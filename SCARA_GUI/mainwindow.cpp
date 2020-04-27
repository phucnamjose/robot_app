#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#define COMBOBOX_NUM    (2)
#define RADIOBUTTON_NUM (15)
#define CHECKBOX_NUM    (2)


const char* comboBox_Name[COMBOBOX_NUM] = {"comboBox_Comport",
                                                                                                             "comboBox_Baudrate",};

const char* radioButton_Name[RADIOBUTTON_NUM] = {"radioButtion_Stop",
                                                                                                                     "radioButtion_Scan",
                                                                                                                     "radioButton_MoveHome",
                                                                                                                     "radioButton_MoveLine",
                                                                                                                     "radioButton_MoveCircle",
                                                                                                                     "radioButton_MoveJoint",
                                                                                                                     "radioButton_Rotate",
                                                                                                                     "radioButton_Output",
                                                                                                                     "radioButton_ReadStatus",
                                                                                                                     "radioButton_ReadPosition",
                                                                                                                     "radioButton_Setting",
                                                                                                                     "radioButton_Absolute",
                                                                                                                     "radioButton_Relative",
                                                                                                                     "radioButton_LSPB",
                                                                                                                     "radioButton_Scurve"};

const char* checkBox_Name[CHECKBOX_NUM] = {"checkBox_Output",
                                                                                                        "checkBox_Scan"};


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),
    m_ui(new Ui::MainWindow),
    m_robot(new RobotControll(this)),
    m_status(new QLabel)
{
    m_ui->setupUi(this);
    m_ui->statusBar->addWidget(m_status);
    serial_init();
}

MainWindow::~MainWindow()
{
    delete m_ui;
    delete m_robot;
    delete m_status;
}

    /*-- ROBOT DECLARE --*/
void MainWindow::serial_init() {
    m_ui->comboBox_Baudrate->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    m_ui->comboBox_Baudrate->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    m_ui->comboBox_Baudrate->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    m_ui->comboBox_Baudrate->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    serial_updatePortName();
    serial_updateSetting();
    m_status->setText(tr("No Robot Device"));
    for(int i = 0; i < COMBOBOX_NUM; i++) {
        connect(this->findChild<QComboBox*>(comboBox_Name[i]), &QComboBox::currentTextChanged,
                this, &MainWindow::serial_updateSetting, Qt::QueuedConnection);
    }
    connect(m_ui->pushButton_LogsClear, &QPushButton::clicked, this, &MainWindow::logs_clear);
    connect(m_ui->pushButton_Change_Limit, &QPushButton::clicked, this, &MainWindow::manual_changeLimit);
    connect(m_ui->pushButton_Request, &QPushButton::clicked, this, &MainWindow::manual_checkPara_setCommand);
    connect(m_robot, &RobotControll::commandSend, this, &MainWindow::serial_logCommand);
    connect(m_robot, &RobotControll::respondArrived, this, &MainWindow::serial_logRespond);

    timer_serial_comboBox = new QTimer(this);
    connect(timer_serial_comboBox, &QTimer::timeout, this, &MainWindow::serial_updatePortName);
    timer_serial_comboBox->start(1000);
}

void MainWindow::serial_openPort() {
    if(m_robot->open(QIODevice::ReadWrite)) {
        timer_serial_comboBox->stop();
        m_ui->comboBox_Baudrate->setEnabled(false);
        m_ui->comboBox_Comport->setEnabled(false);
        m_ui->pushButton_Connect->setText(tr("DISCONNECT"));
        m_ui->label_connectStatus->setText(tr("Connected"));
        m_status->setText(tr("Connected to %1 : %2")
                          .arg(m_ui->comboBox_Comport->currentText())
                          .arg(m_ui->comboBox_Baudrate->currentText()));
    } else {
        QMessageBox::critical(this, tr("Error"), m_robot->errorString());
        m_status->setText(tr("Open error"));
    }
}

void MainWindow::serial_closePort() {
    if(m_robot->isOpen()) {
        m_robot->close();
        m_ui->comboBox_Baudrate->setEnabled(true);
        m_ui->comboBox_Comport->setEnabled(true);
        m_ui->pushButton_Connect->setText("CONNECT");
        m_ui->label_connectStatus->setText(tr("Disconnected"));
        timer_serial_comboBox->start(1000);
        m_status->setText(tr("No Robot Device"));
    } else {
        QMessageBox::critical(this, tr("Error"), m_robot->errorString());
        m_status->setText(tr("No Robot Device"));
    }
}

void MainWindow::serial_updatePortName() {
    const auto port_info = QSerialPortInfo::availablePorts();
    int count_port = port_info.count();
    int count_item = m_ui->comboBox_Comport->count();

    if(count_port < count_item) {
        for(int i = count_port; i < count_item; i++) {
            m_ui->comboBox_Comport->removeItem(i);
        }
        count_item = count_port;
    } else if(count_port > count_item) {
        for(int i = count_item; i < count_port; i++) {
            m_ui->comboBox_Comport->addItem(port_info.at(i).portName());
        }
    }
    for(int i = 0 ; i < count_item; i ++) {
        if(port_info.at(i).portName() != m_ui->comboBox_Comport->itemText(i)) {
            m_ui->comboBox_Comport->removeItem(i);
            m_ui->comboBox_Comport->addItem(port_info.at(i).portName());
        }
    }
}

void MainWindow::serial_updateSetting() {
    m_robot->setPortName(m_ui->comboBox_Comport->currentText());
    m_robot->setBaudRate(static_cast<QSerialPort::BaudRate>
                          (m_ui->comboBox_Baudrate->itemData(m_ui->comboBox_Baudrate->currentIndex()).toInt()));
    m_robot->setDataBits(QSerialPort::Data8);
    m_robot->setParity(QSerialPort::NoParity);
    m_robot->setStopBits(QSerialPort::OneStop);
    m_robot->setFlowControl(QSerialPort::NoFlowControl);
    //qDebug() << m_robot->portName() << m_robot->baudRate();
}

void MainWindow::serial_handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), m_robot->errorString());
        serial_closePort();
    }
}

void MainWindow::manual_changeLimit() {
    bool isDouble1, isDouble2, isDouble3;
    double  factor_v, factor_a, time;
    factor_v       = m_ui->textEdit_Velocity_Limit->toPlainText().toDouble(&isDouble1);
    // Velocity
    if (isDouble1) {
        if ( (factor_v <= 0.0) || (factor_v > 1.0)) {
            QMessageBox::critical(this, tr("Error"), tr("Factor velocity must be in range : 0 -  1"));
            return;
        }
    } else {
        QMessageBox::critical(this, tr("Error"), tr("Velocity parameter must is double"));
        return;
    }
    // Mode Init
    if (m_ui->radioButton_QVA->isChecked()) {
        factor_a = m_ui->textEdit_Accelerate_Limit->toPlainText().toDouble(&isDouble2);
        if(isDouble2) {
            // Accelerate
            if ( (factor_a > 0.0) && (factor_a <= 1.0)) {
                m_robot->robotSetModeInite(RobotControll::MODE_INIT_QVA);
                m_robot->robotSetVelocity(factor_v);
                m_robot->robotSetAccelerate(factor_a);
                // Logs
                logs_write(tr("Changed: Mode QTA veloc %1, accel %2").arg(factor_v).arg(factor_a),
                                        QColor(0,140,0));
            } else {
                QMessageBox::critical(this, tr("Error"), tr("Factor accelerate must be in range : 0 -  1"));
                return;
            }
        } else {
            QMessageBox::critical(this, tr("Error"), tr("Accelarate parameter must is double"));
            return;
        }

    } else {
        time = m_ui->textEdit_Time_Total->toPlainText().toDouble(&isDouble3);
        if (isDouble3) {
            // Time
            if ( (time > 0.0) && (time < 20)) {
                m_robot->robotSetModeInite(RobotControll::MODE_INIT_QVT);
                m_robot->robotSetVelocity(factor_v);
                m_robot->robotSetTimeTotal(time);
                // Logs
                logs_write(tr("Changed: Mode QVT veloc %1, total time %2s").arg(factor_v).arg(time),
                                        QColor(0,140,0));
            } else {
                QMessageBox::critical(this, tr("Error"), tr("Time over range"));
                return;
            }
        } else {
            QMessageBox::critical(this, tr("Error"), tr("Time parameter must is double"));
            return;
        }
    }
}

void MainWindow::manual_checkPara_setCommand() {
    // Check
    if (!(m_robot->isOpen()))  {
        QMessageBox::critical(this, tr("Error"), tr("Comport is not connected"));
        return;
    }
    // STOP
    if (m_ui->radioButton_Stop->isChecked()) {
            if( m_robot->robotStop() ) {
                return;
            }
     // SCAN
     } else  if (m_ui->radioButton_Scan->isChecked()) {
            if( m_robot->robotScanLimit() ) {
                return;
            }
     // HOME
    } else if (m_ui->radioButton_MoveHome->isChecked()) {
            if( m_robot->robotMoveHome() ) {
                return;
            }
     // MOVL
    } else if(m_ui->radioButton_MoveLine->isChecked()) {
        bool isDouble1, isDouble2, isDouble3, isDouble4;
        double x, y, z, roll;
        x = m_ui->textEdit_Target_X->toPlainText().toDouble(&isDouble1);
        y = m_ui->textEdit_Target_Y->toPlainText().toDouble(&isDouble2);
        z = m_ui->textEdit_Target_Z->toPlainText().toDouble(&isDouble3);
        roll =  m_ui->textEdit_Target_Roll->toPlainText().toDouble(&isDouble4);
        if(isDouble1 && isDouble2 && isDouble3 && isDouble4) {
            if( m_robot->robotMoveLine(x, y, z, roll)== false ) {
                return;
            }
        } else {
            QMessageBox::critical(this, tr("Error"), tr("All parameter must is double"));
            return;
        }
    //MOVC
    } else if(m_ui->radioButton_MoveCircle->isChecked()) {
        bool isDouble1, isDouble2, isDouble3, isDouble4, isDouble5, isDouble6, isDouble7;
        double x, y, z, roll, center_x, center_y, center_z;
        int dir;
        x       = m_ui->textEdit_Target_X->toPlainText().toDouble(&isDouble1);
        y       = m_ui->textEdit_Target_Y->toPlainText().toDouble(&isDouble2);
        z       = m_ui->textEdit_Target_Z->toPlainText().toDouble(&isDouble3);
        roll   =  m_ui->textEdit_Target_Roll->toPlainText().toDouble(&isDouble4);
        center_x = m_ui->textEdit_Center_X->toPlainText().toDouble(&isDouble5);
        center_y = m_ui->textEdit_Center_Y->toPlainText().toDouble(&isDouble6);
        center_z = m_ui->textEdit_Center_Z->toPlainText().toDouble(&isDouble7);
        if (m_ui->radioButton_Dir_counter->isChecked()) {
            dir =    1;
        } else {
            dir =    -1;
        }
        if (isDouble1 && isDouble2 && isDouble3 && isDouble4
                && isDouble5 && isDouble6 && isDouble7) {
            if ( m_robot->robotMoveCircle(x, y, z, roll, center_x, center_y, center_z, dir)== false ) {
                return;
            }
        } else {
            QMessageBox::critical(this, tr("Error"), tr("All parameter must is double"));
            return;
        }
    // MOVJ
    } else if (m_ui->radioButton_MoveJoint->isChecked()) {
        bool isDouble1, isDouble2, isDouble3, isDouble4 ;
        double x, y, z, roll;
        x       = m_ui->textEdit_Target_X->toPlainText().toDouble(&isDouble1);
        y       = m_ui->textEdit_Target_Y->toPlainText().toDouble(&isDouble2);
        z       = m_ui->textEdit_Target_Z->toPlainText().toDouble(&isDouble3);
        roll   = m_ui->textEdit_Target_Roll->toPlainText().toDouble(&isDouble4);

        if (isDouble1 && isDouble2 && isDouble3 && isDouble4) {
            if ( m_robot->robotMoveJoint(x, y, z, roll)== false ) {
                return;
            }
        } else {
            QMessageBox::critical(this, tr("Error"), tr("All parameter must is double"));
            return;
        }
    // ROTA
    } else if (m_ui->radioButton_Rotate->isChecked()) {
        bool isDouble, isInt;
        double angle;
        int joint;
        joint   = m_ui->textEdit_Target_Joint->toPlainText().toInt(&isInt);
        angle = m_ui->textEdit_Target_Angle->toPlainText().toDouble(&isDouble);
        if(isDouble && isInt) {
            if(joint != 2) {
                // Degree --> Radian
                angle = angle*PI/180;
            }
            if ( m_robot->robotRotateSingleJoint(joint, angle)== false ) {
                return;
            }
        } else {
            QMessageBox::critical(this, tr("Error"), tr("Joint must is int 0 - 3,Angle must is double"));
            return;
        }
    // OUTP
    } else if(m_ui->radioButton_Output->isChecked()) {
        int output = 0;
        if (m_ui->checkBox_Output->isChecked()) { output = 1;}
        if ( m_robot->robotOutput(output)== false ) {
                return;
            }
    // READ
    } else if(m_ui->radioButton_ReadStatus->isChecked()) {
        if ( m_robot->robotReadStatus() == false ) {
            return;
        }
    // POSI
    } else if(m_ui->radioButton_ReadPosition->isChecked()) {
        if ( m_robot->robotReadPosition() == false ) {
            return;
        }
    // SETT
    } else if(m_ui->radioButton_Setting->isChecked()) {
        RobotControll::robotCoordinate_t coor;
        RobotControll::robotTrajectory_t  trajec;
        if (m_ui->radioButton_Absolute->isChecked()) {
            coor = RobotControll::COORDINATES_ABS;
        } else {
            coor = RobotControll::COORDINATES_REL;
        }

        if (m_ui->radioButton_LSPB->isChecked()) {
            trajec = RobotControll::TRAJECTORY_LSPB;
        } else {
           trajec = RobotControll::TRAJECTORY_SCURVE;
        }

        if ( m_robot->robotSetting(coor, trajec) == false ) {
            return;
        }
    }
}

void MainWindow::serial_logCommand(QByteArray command) {
    logs_write(tr(command), QColor(0,0,140));
}

void  MainWindow::serial_logRespond(QByteArray respond) {
     logs_write(tr(respond), QColor(230,0,0));
}

void MainWindow::logs_write(QString message, QColor c) {
    if( message.isEmpty() || message.isNull() ) {
        M_DEBUG("log write error");
        return;
    }
    m_ui->textEdit_Logs->setTextColor(c);
    m_ui->textEdit_Logs->insertPlainText(message);
    m_ui->textEdit_Logs->insertPlainText("\n");
    m_ui->textEdit_Logs->ensureCursorVisible();
}
void MainWindow::logs_clear() {
    m_ui->textEdit_Logs->clear();
}

void MainWindow::on_pushButton_Connect_clicked()
{
    if(m_ui->pushButton_Connect->text() == "CONNECT") {
        serial_openPort();
    } else {
        serial_closePort();
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Confirmation",
                                                                    "Close window. Sure?\n",
                                                                    QMessageBox::No | QMessageBox::Yes);
        if (resBtn != QMessageBox::Yes) {
            event->ignore();
        } else {
            event->accept();
        }
}

