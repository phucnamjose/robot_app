#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#define COMBOBOX_SERIAL_NUM                     (2)
#define RADIOBUTTON_NUM                               (15)
#define CHECKBOX_NUM                                         (2)
#define COMBOBOX_PLOT_NUM                         (4)
#define COMBOBOX_VAR_NUM                            (29)

const char* comboBoxSerial_Name[COMBOBOX_SERIAL_NUM] = {"comboBox_Comport",
                                                                                                                                        "comboBox_Baudrate"};

const char* checkBox_Name[CHECKBOX_NUM] = {"checkBox_Output",
                                                                                                       "checkBox_Scan"};

const char* comboBoxPlot_X_Name[COMBOBOX_PLOT_NUM] = { "comboBox_Chart1_x",
                                                                                                                                        "comboBox_Chart2_x",
                                                                                                                                        "comboBox_Chart3_x",
                                                                                                                                        "comboBox_Chart4_x"};

const char* comboBoxPlot_Y_Name[COMBOBOX_PLOT_NUM] = { "comboBox_Chart1_y",
                                                                                                                                       "comboBox_Chart2_y",
                                                                                                                                       "comboBox_Chart3_y",
                                                                                                                                       "comboBox_Chart4_y"};

const char* comboBoxPlot_Var[COMBOBOX_VAR_NUM] = {  "None",
                                                                                                                                  "Time (second)",
                                                                                                                                  "Pos Var 0 (deg)",
                                                                                                                                  "Pos Var 1 (deg)",
                                                                                                                                  "Pos Var 2 (mm)",
                                                                                                                                  "Pos Var 3 (deg)",
                                                                                                                                  "Pos X (mm)",
                                                                                                                                  "Pos Y (mm)",
                                                                                                                                   "Pos Z (mm)",
                                                                                                                                   "Pos Roll (deg)",
                                                                                                                                   "Pos 3D (mm)",
                                                                                                                                   "Vel Var 0 (deg/s)",
                                                                                                                                   "Vel Var 1 (deg/s)",
                                                                                                                                    "Vel Var 2 (mm/s)",
                                                                                                                                    "Vel Var 3 (deg/s)",
                                                                                                                                    "Vel X (mm/s)",
                                                                                                                                    "Vel Y (mm/s)",
                                                                                                                                    "Vel Z (mm/s)",
                                                                                                                                    "Vel Roll (deg/s)",
                                                                                                                                    "Vel 3D (mm/s)",
                                                                                                                                    "Acc Var 0 (deg/s2)",
                                                                                                                                    "Acc Var 1 (deg/s2)",
                                                                                                                                    "Acc Var 2 (mm/s2)",
                                                                                                                                    "Acc Var 3 (deg/s2)",
                                                                                                                                    "Acc X (mm/s2)",
                                                                                                                                    "Acc Y (mm/s2)",
                                                                                                                                    "Acc Z (mm/s2)",
                                                                                                                                    "Acc Roll (deg/s2)",
                                                                                                                                    "Acc 3D (mm/s2)"};


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),
    m_ui(new Ui::MainWindow),
    m_robot(new RobotControll(this))
{
    m_ui->setupUi(this);
    plot_init();
    serial_init();
    ui_init();
    compute_init();
    qDebug() << "Program START \n";
}

MainWindow::~MainWindow()
{
    for(ChartWindow *figure : m_figure) {
        delete figure;
    }
    delete m_ui;
    delete m_robot;
    delete timer_update;
}

    /*-------------------------- DECLARE -----------------------------*/

/*---- Ploting -----*/
void MainWindow::plot_init() {
    num_chartwindow = 1;
    plot_initComboBox();
     // SIGNAL & SLOT
    connect(m_ui->pushButton_Plot, &QPushButton::clicked, this, &MainWindow::plot_Plot_Clicked);
}

void MainWindow::plot_initComboBox() {
    // X Axis
    for (int i = 0; i < COMBOBOX_PLOT_NUM; ++i) {
        QComboBox* comboBox;
        comboBox = this->findChild<QComboBox*>(comboBoxPlot_X_Name[i]);
        if(comboBox != nullptr) {
             comboBox->addItem(comboBoxPlot_Var[0], QVariant(-1));// None
             comboBox->addItem(comboBoxPlot_Var[1], QVariant(0));// Time
             comboBox->addItem(comboBoxPlot_Var[7], QVariant(6));// Y
             m_x_axis.append(comboBox);
        }
    }
    // Y Axis
    for (int i = 0; i < COMBOBOX_PLOT_NUM; ++i) {
        QComboBox* comboBox;
        comboBox = this->findChild<QComboBox*>(comboBoxPlot_Y_Name[i]);
        if(comboBox != nullptr) {
            for (int j = 0; j < COMBOBOX_VAR_NUM; ++j) {
                comboBox->addItem(comboBoxPlot_Var[j], QVariant(j - 1));
            }
            m_y_axis.append(comboBox);
        }
    }
    if (m_x_axis.count() != m_y_axis.count()) {
        QMessageBox::critical(this, tr("Error"), tr("Number ComboBox  is not equal"));
    }
}

void MainWindow::plot_Plot_Clicked()
{
    // create figure
    ChartWindow *figure = new ChartWindow(this);
    figure->setWindowTitle(QString(tr("Figure ")) + QString::number(num_chartwindow));
    num_chartwindow++;
    // set figure
    for (int i = 0; i < m_x_axis.count(); ++i) {
        QComboBox *comboBox_X = m_x_axis.at(i);
        QComboBox *comboBox_Y = m_y_axis.at(i);
        if (comboBox_X->currentText() != QString("None") && comboBox_Y->currentText() != QString("None")) {
                QString x_name, y_name;
                int x_var, y_var;
                x_name = comboBox_X->currentText();
                y_name = comboBox_Y->currentText();
                x_var = comboBox_X->currentData().toInt();
                y_var = comboBox_Y->currentData().toInt();
                figure->addChart(x_var, y_var, x_name, y_name);
                // add points
                figure->addPoint(i, *vec_list.at(x_var), *vec_list.at(y_var));
                figure->setRangeFit(i);
        }
    }
    figure->show();
    m_figure.append(figure);
    // signals & slot
    connect(figure, &ChartWindow::figureClosed, this, &MainWindow::plot_figureClosed);
}

void MainWindow::plot_figureClosed(ChartWindow *figure) {
    m_figure.removeOne(figure);
}

/*---- Computing Data -----*/
void MainWindow::compute_init() {
    num_sample = 0;
    pre_time_total = 0;
    pre_lenght = 0;
    time_pre = -0.01;
    // Init size
    vec_time.resize(6000);
    vec_time.clear();
    for (int i = 0; i < 9; ++i) {
        vec_pos[i].resize(6000);
        vec_pos[i].clear();
    }
    for (int i = 0; i < 9; ++i) {
        vec_vel[i].resize(6000);
        vec_vel[i].clear();
    }
    for (int i = 0; i < 9; ++i) {
        vec_acc[i].resize(6000);
        vec_acc[i].clear();
    }
    // Add to list
    vec_list.clear();
    vec_list.append(&vec_time);
    for (int i = 0; i < 9; ++i) {
        vec_list.append(&vec_pos[i]);
    }
    for (int i = 0; i < 9; ++i) {
        vec_list.append(&vec_vel[i]);
    }
    for (int i = 0; i < 9; ++i) {
        vec_list.append(&vec_acc [i]);
    }
    // Signal & Slot
    connect(m_ui->pushButton_Delete_Data, &QPushButton::clicked,
                        this, &MainWindow::compute_Delete_Data_Clicked);
}

void MainWindow::compute_newData() {
    double time, total_time, pos[9], vel[9], acc[9];
    total_time = m_robot->getTotalTime();
    time = m_robot->getTimeRun();
    pos[0]  = m_robot->getVar0();
    pos[1]  = m_robot->getVar1();
    pos[2]  = m_robot->getVar2();
    pos[3]  = m_robot->getVar3();
    pos[4]  = m_robot->getX();
    pos[5]  = m_robot->getY();
    pos[6]  = m_robot->getZ();
    pos[7]  = m_robot->getRoll();
    pos[8] = m_robot->getLenght() + pre_lenght;
    if( 0 == num_sample) {
        for (int i = 0; i < 9; ++i) {
            vel[i] = 0;
            acc[i] = 0;
        }
    } else {
        for (int i = 0; i < 9; ++i) {
            if ( time - time_pre > 0) {
                vel[i]  = (pos[i] - pos_pre[i])/(time  - time_pre);
                acc[i] = (vel[i] - vel_pre[i])/ (time - time_pre);
            } else {
                vel[i] = vel_pre[i];
                acc[i] = acc_pre[i];
            }
        }
    }
    // Save value;
    vec_time.append(time +  pre_time_total);
    for (int i = 0; i < 9; ++i) {
        vec_pos[i].append(pos[i]);
        vec_vel[i].append(vel[i]);
        vec_acc[i].append(acc[i]);
    }
    // Plot new point
    for( ChartWindow *figure : m_figure) {
        for( int  i = 0;  i < figure->var_list.count(); ++i) {
            double x_value = (*vec_list.at(figure->var_list.at(i).first)).last();
            double y_value = (*vec_list.at(figure->var_list.at(i).second)).last();
            figure->addPoint(i, x_value, y_value);
        }
    }
    // Update previos value
    time_pre = time;
    for (int i = 0; i < 9; ++i) {
        pos_pre[i] = pos[i];
        vel_pre[i] = vel[i];
        acc_pre[i] = acc[i];
    }
    num_sample++;
    m_ui->progressBar_Running->setValue(ceil(time/total_time*1000));
}

void MainWindow::compute_Delete_Data_Clicked() {
    for (int i = 0; i < 28; ++i) {
        (*(vec_list.at(i))).clear();
    }
    pre_time_total = 0;
    pre_lenght = 0;
    QMessageBox::information(this, tr("Inform"), tr("Data vector is deleted"));
}

/*---- Serial -----*/
void MainWindow::serial_init() {
    serial_updatePortName();
    serial_updateSetting();
    serial_initComboBox();
    // signals & slot
    connect(m_ui->pushButton_Change_Limit, &QPushButton::clicked,
                        this, &MainWindow::serial_Change_Limit_Clicked);
    connect(m_ui->pushButton_Request, &QPushButton::clicked,
                        this, &MainWindow::serial_Request_Clicked);
    connect(m_ui->pushButton_Connect, &QPushButton::clicked,
                        this, &MainWindow::serial_Connect_Clicked);
    connect(m_ui->pushButton_Startup, &QPushButton::clicked,
                        this, &MainWindow::serial_startUpCommand);

    connect(m_robot, &RobotControll::commandSend, this, &MainWindow::serial_logCommand);
    connect(m_robot, &RobotControll::respondArrived, this, &MainWindow::serial_logRespond);
    connect(m_robot, &RobotControll::respondPosition, this, &MainWindow::serial_logRespond);
    connect(m_robot, &RobotControll::respondPosition, this, &MainWindow::serial_displayPosition);
    connect(m_robot, &RobotControll::commandWorkStart, this, &MainWindow::serial_workStart);
    connect(m_robot, &RobotControll::commandWorkRunning, this, &MainWindow::serial_workRunning);
    connect(m_robot, &RobotControll::commandWorkDone, this, &MainWindow::serial_workEnd);
    // create timer to update what comboBox PortName change
    timer_update = new QTimer(this);
    connect(timer_update, &QTimer::timeout, this, &MainWindow::serial_updatePortName);
    timer_update->start(1000);
}

void MainWindow::serial_initComboBox() {
    // Update Comport, Baudrate
    for(int i = 0; i < COMBOBOX_SERIAL_NUM; ++i) {
        connect(this->findChild<QComboBox*>(comboBoxSerial_Name[i]), &QComboBox::currentTextChanged,
                this, &MainWindow::serial_updateSetting, Qt::QueuedConnection);
    }
    m_ui->comboBox_Baudrate->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    m_ui->comboBox_Baudrate->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    m_ui->comboBox_Baudrate->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    m_ui->comboBox_Baudrate->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
}

void MainWindow::serial_openPort() {
    if(m_robot->open(QIODevice::ReadWrite)) {
        m_ui->comboBox_Baudrate->setEnabled(false);
        m_ui->comboBox_Comport->setEnabled(false);
        m_ui->pushButton_Connect->setText(tr("DISCONNECT"));
        m_ui->label_connectStatus->setText(tr("Connected"));
        timer_update->stop();
    } else {
        QMessageBox::critical(this, tr("Error"), m_robot->errorString());
    }
}

void MainWindow::serial_closePort() {
    if(m_robot->isOpen()) {
        m_robot->close();
        m_ui->comboBox_Baudrate->setEnabled(true);
        m_ui->comboBox_Comport->setEnabled(true);
        m_ui->pushButton_Connect->setText("CONNECT");
        m_ui->label_connectStatus->setText(tr("Disconnected"));
        timer_update->start(1000);
    } else {
        QMessageBox::critical(this, tr("Error"), m_robot->errorString());
    }
}

void MainWindow::serial_updatePortName() {
    const auto port_info = QSerialPortInfo::availablePorts();
    QComboBox *box = m_ui->comboBox_Comport;
    // Add
    for (QSerialPortInfo info : port_info) {
        int count = 0;
        for (int i = 0; i < box->count() ; ++i) {
            if (info.portName() != box->itemText(i)) count++;
        }
        if (count == box->count()) box->addItem(info.portName());//if the name is not exist in comboBox, add it.
     }
    // Remove
    for (int i = 0; i < box->count() ; ++i) {
        int count = 0;
        for (QSerialPortInfo info : port_info) {
             if (info.portName() != box->itemText(i)) count++;
        }
        if (count == port_info.count()) box->removeItem(i);//if the name is not exist in portName list, remove it.
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

void MainWindow::serial_logCommand(QByteArray command) {
    logs_write(tr(command), QColor(0,0,140));
}

void MainWindow::serial_logRespond(QByteArray respond) {
     logs_write(tr(respond), QColor(230,0,0));
}

void MainWindow::serial_displayPosition() {
    double var0, var1, var3, roll;
    if (m_ui->radioButton_Degree->isChecked()) {
        var0 = m_robot->getVar0();
        var1 = m_robot->getVar1();
        var3 = m_robot->getVar3();
        roll   = m_robot->getRoll();
    } else {
        var0 = m_robot->getVar0()*M_PI/180.0;
        var1 = m_robot->getVar1()*M_PI/180.0;
        var3 = m_robot->getVar3()*M_PI/180.0;
        roll   = m_robot->getRoll()*M_PI/180.0;
    }
    if (m_robot->isScan()) {
        m_ui->textEdit_Theta1->setText(QString::number(var0));
        m_ui->textEdit_Theta2->setText(QString::number(var1));
        m_ui->textEdit_D3->setText(QString::number(m_robot->getVar2()));
        m_ui->textEdit_Theta4->setText(QString::number(var3));
        m_ui->textEdit_X->setText(QString::number(m_robot->getX()));
        m_ui->textEdit_Y->setText(QString::number(m_robot->getY()));
        m_ui->textEdit_Z->setText(QString::number(m_robot->getZ()));
        m_ui->textEdit_Roll->setText(QString::number(roll));
    }
}

void MainWindow::serial_Connect_Clicked()
{
    if(m_ui->pushButton_Connect->text() == "CONNECT") {
        serial_openPort();
    } else {
        serial_closePort();
    }
}

void MainWindow::serial_Change_Limit_Clicked() {
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
                m_robot->setModeInite(RobotControll::MODE_INIT_QVA);
                m_robot->setVelocity(factor_v);
                m_robot->setAccelerate(factor_a);
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
                m_robot->setModeInite(RobotControll::MODE_INIT_QVT);
                m_robot->setVelocity(factor_v);
                m_robot->setTimeTotalLimit(time);
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

void MainWindow::serial_Request_Clicked() {
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

void MainWindow::serial_workStart(QByteArray respond) {
    time_pre = -0.01;
    num_sample = 0;
    serial_displayPosition();
    logs_write(respond, QColor(220, 80, 115));
    // Set X range
    for( ChartWindow *figure : m_figure) {
        for( int  i = 0;  i < figure->var_list.count(); ++i) {
            if (figure->var_list.at(i).first == 0)
            {
                figure->setRangeX(i, 0, ceil(m_robot->getTotalTime()) + pre_time_total);
            } else if (figure->var_list.at(i).first == 6) {
                figure->setRangeX(i, -360, 360);
                figure->setRangeY(i, 0 , 360);
            }
        }
    }
}

void MainWindow::serial_workRunning() {
    compute_newData();
    serial_displayPosition();
}

void MainWindow::serial_workEnd(QByteArray respond) {
    compute_newData();
    serial_displayPosition();
    logs_write(respond, QColor(220, 80, 115));
    num_sample = 0;
    time_pre = -0.01;
    m_ui->progressBar_Running->setValue(0);
    // Fit all chart
    for( ChartWindow *figure : m_figure) {
        for( int  i = 0;  i < figure->var_list.count(); ++i) {
                figure->setRangeFit(i);
        }
    }
    pre_time_total  = vec_time.last();
    pre_lenght = vec_pos[8].last();
}

void MainWindow::serial_startUpCommand() {
    m_robot->robotReadStatus();
    m_robot->robotReadPosition();
}

/*----UI -----*/
void MainWindow:: ui_init() {
    connect(m_ui->pushButton_LogsClear, &QPushButton::clicked,
                        this, &MainWindow::logs_Clear_Clicked);
}

void MainWindow::logs_write(QString message, QColor c) {
    if( message.isEmpty() || message.isNull() ) {
        M_DEBUG("log write error");
        return;
    }
    m_ui->textEdit_Logs->setTextColor(c);
    m_ui->textEdit_Logs->insertPlainText(message);
    m_ui->textEdit_Logs->insertPlainText("\n");
    m_ui->textEdit_Logs->ensureCursorVisible(); // Scroll to bottom automaticly
}

void MainWindow::logs_Clear_Clicked() {
    m_ui->textEdit_Logs->clear();
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

