#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#define COMBOBOX_SERIAL_NUM                     (2)
#define RADIOBUTTON_NUM                               (15)
#define CHECKBOX_NUM                                         (2)
#define COMBOBOX_PLOT_NUM                         (4)
#define COMBOBOX_VAR_NUM                            (29)
#define BUTTON_KEYBOARD_NUM                      (17)

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

const char* pushButton_KeyBoard[BUTTON_KEYBOARD_NUM] = {  "pushButton_X_inc",
                                                                                                                                         "pushButton_X_dec",
                                                                                                                                         "pushButton_Y_inc",
                                                                                                                                         "pushButton_Y_dec",
                                                                                                                                         "pushButton_Z_inc",
                                                                                                                                         "pushButton_Z_dec",
                                                                                                                                         "pushButton_Roll_inc",
                                                                                                                                         "pushButton_Roll_dec",
                                                                                                                                         "pushButton_Var0_inc",
                                                                                                                                         "pushButton_Var0_dec",
                                                                                                                                         "pushButton_Var1_inc",
                                                                                                                                         "pushButton_Var1_dec",
                                                                                                                                         "pushButton_Var2_inc",
                                                                                                                                         "pushButton_Var2_dec",
                                                                                                                                         "pushButton_Var3_inc",
                                                                                                                                         "pushButton_Var3_dec"};


MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),
    m_ui(new Ui::MainWindow),
    m_robot(new RobotControll(this))
{
    m_ui->setupUi(this);
    plot_init();
    serial_init();
    ui_init();
    compute_init();
    joystick_init();
    qDebug() << "Program START \n";
    qDebug() << "main thread is:" << QThread::currentThreadId();
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

    /*-------------------------- DECLARE -----------------------------*/

/*---- Ploting -----*/
void MainWindow::plot_init() {
    num_chartwindow = 1;
    plot_initComboBox();
     // SIGNAL & SLOT
    connect(m_ui->pushButton_Plot, &QPushButton::clicked, this, &MainWindow::on_pushButton_Plot_Clicked);

    timer_update_figure = new QTimer(this);
    connect(timer_update_figure, &QTimer::timeout, this, &MainWindow:: plot_timerFigure_handle);
    timer_update_figure->start(200);
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

void MainWindow::plot_figureClosed(ChartWindow *figure) {
    m_figure.removeOne(figure);
}

void  MainWindow::plot_timerFigure_handle() {
    // Plot new point
    if(num_sample_plot < vec_time.size() && vec_time.size() > 0) {
        for( ChartWindow *figure : m_figure) {
            for( int  i = 0;  i < figure->var_list.count(); ++i) {
                figure->addPoint(i, vec_list.at(figure->var_list.at(i).first)->mid(num_sample_plot),
                                vec_list.at(figure->var_list.at(i).second)->mid(num_sample_plot) );
            }
        }
        num_sample_plot = vec_time.size();
    }
}

/*---- Computing Data -----*/
void MainWindow::compute_init() {
    num_sample = 0;
    pre_time_total = 0;
    pre_lenght = 0;
    time_pre = -0.01;
    collect_data = false;
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


    connect(m_ui->pushButton_Delete_Data, &QPushButton::clicked,
                        this, &MainWindow::on_pushButton_Delete_Data_Clicked);
}

void MainWindow::compute_newData(double x,double y, double z, double roll,
                                 double var0, double var1, double var2, double var3,
                                 double lenght, double time_run, double time_total) {
    double time, total_time, pos[9], vel[9], acc[9];
    total_time = time_total;
    time = time_run;
    pos[0]  = var0;
    pos[1]   = var1;
    pos[2]  = var2;
    pos[3]  = var3;
    pos[4]  = x;
    pos[5]  = y;
    pos[6]  = z;
    pos[7]  = roll;
    pos[8] = lenght + pre_lenght;
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
    if(collect_data) {
         vec_time.append(time +  pre_time_total);
        for (int i = 0; i < 9; ++i) {
            vec_pos[i].append(pos[i]);
            vec_vel[i].append(vel[i]);
            vec_acc[i].append(acc[i]);
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
}

/*---- Serial -----*/
void MainWindow::serial_init() {
    serial_updatePortName();
    serial_updateSetting();
    serial_initComboBox();
    // signals & slot
    connect(m_ui->pushButton_Change_Limit, &QPushButton::clicked,
                        this, &MainWindow::on_pushButton_Change_Limit_Clicked);
    connect(m_ui->pushButton_Request, &QPushButton::clicked,
                        this, &MainWindow::on_pushButton_Request_Clicked);
    connect(m_ui->pushButton_Connect, &QPushButton::clicked,
                        this, &MainWindow::on_pushButton_Connect_Clicked);
    connect(m_ui->pushButton_Startup, &QPushButton::clicked,
                        this, &MainWindow::on_pushButton_startUpCommand);
    connect(m_ui->pushButton_Output, &QPushButton::clicked,
                        this, &MainWindow::on_pushButton_Output_Clicked);


    connect(m_robot, &RobotControll::commandSend, this, &MainWindow::serial_logCommand, Qt::QueuedConnection);
    connect(m_robot, &RobotControll::respondArrived, this, &MainWindow::serial_logRespond, Qt::QueuedConnection);
    connect(m_robot, &RobotControll::respondPosition, this, &MainWindow::serial_logRespond, Qt::QueuedConnection);
    connect(m_robot, &RobotControll::commandAccept, this, &MainWindow::serial_logRespond, Qt::QueuedConnection);
    connect(m_robot, &RobotControll::commandDeny, this, &MainWindow::serial_logRespond, Qt::QueuedConnection);
    connect(m_robot, &RobotControll::commandWorkStart, this, &MainWindow::serial_workStart, Qt::QueuedConnection);
    connect(m_robot, &RobotControll::commandWorkRunning, this, &MainWindow::serial_workRunning, Qt::QueuedConnection);
    connect(m_robot, &RobotControll::commandWorkDone, this, &MainWindow::serial_workEnd, Qt::QueuedConnection);
    connect(m_robot, &RobotControll::updatePosition, this, &MainWindow::serial_displayPosition, Qt::QueuedConnection);
    // create timer to update what comboBox PortName change
    timer_update_comport = new QTimer(this);
    connect(timer_update_comport, &QTimer::timeout, this, &MainWindow::serial_updatePortName);
    timer_update_comport->start(1000);
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
    if(!m_robot->isOpen()) {
        if (m_robot->openComPort(comportName)) {
            m_ui->comboBox_Baudrate->setEnabled(false);
            m_ui->comboBox_Comport->setEnabled(false);
            m_ui->pushButton_Connect->setText(tr("DISCONNECT"));
            m_ui->label_connectStatus->setText(tr("Connected"));
            timer_update_comport->stop();
        } else {
            QMessageBox::critical(this, tr("Error"), "Open comport FAIL");
        }
    } else {
       QMessageBox::critical(this, tr("Error"), "comport isn't closed");
    }
}

void MainWindow::serial_closePort() {
    if(m_robot->isOpen()) {
        if (m_robot->closeComPort()) {
            m_ui->comboBox_Baudrate->setEnabled(true);
            m_ui->comboBox_Comport->setEnabled(true);
            m_ui->pushButton_Connect->setText("CONNECT");
            m_ui->label_connectStatus->setText(tr("Disconnected"));
            timer_update_comport->start(1000);
        } else {
            QMessageBox::critical(this, tr("Error"), "Close comport FAIL");
        }
    } else {
        QMessageBox::critical(this, tr("Error"), "comport isn't opened");
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
    comportName = m_ui->comboBox_Comport->currentText();
}


void MainWindow::serial_logCommand(QByteArray command) {
     qDebug() << "logCommand thread is:" << QThread::currentThreadId();
    logsWrite(tr(command), QColor(0,0,140));
}

void MainWindow::serial_logRespond(QByteArray respond) {
     qDebug() << "logRespond thread is:" << QThread::currentThreadId();
     logsWrite(tr(respond), QColor(230,0,0));
}

void MainWindow::serial_displayPosition(double x,double y, double z, double roll,
                                        double var0, double var1, double var2, double var3,
                                        double lenght, double time_run, double time_total) {
        // Get data
        qDebug() << "display thread is:" << QThread::currentThreadId()<< "Time"<< QTime::currentTime().toString();
        // Display in slider
        m_ui->horizontalSlider_var0->setValue(round((var0 - (-85))/(85 - (- 85))*1000));
        m_ui->horizontalSlider_var1->setValue(round((var1 - (-135))/(135 - (- 135))*1000));
        m_ui->horizontalSlider_var2->setValue(round(var2/100*1000));
        m_ui->horizontalSlider_var3->setValue(round((var3 - (-170))/(170 - (- 170))*1000));
        // Display in Text edit
        if (!m_ui->radioButton_Degree->isChecked()) {
            var0 = var0*M_PI/180.0;
            var1 = var1*M_PI/180.0;
            var3 = var2*M_PI/180.0;
            roll   = var3*M_PI/180.0;
        }
        m_ui->textEdit_Theta1->setText(QString::number(var0));
        m_ui->textEdit_Theta2->setText(QString::number(var1));
        m_ui->textEdit_D3->setText(QString::number(var2));
        m_ui->textEdit_Theta4->setText(QString::number(var3));
        m_ui->textEdit_X->setText(QString::number(x));
        m_ui->textEdit_Y->setText(QString::number(y));
        m_ui->textEdit_Z->setText(QString::number(z));
        m_ui->textEdit_Roll->setText(QString::number(roll));
         // Display in Progress Bar
        m_ui->progressBar_Running->setValue(ceil(time_run/time_total*1000));
}

void MainWindow::serial_workStart() {
    time_pre = -0.01;
    num_sample = 0;
    if (vec_time.size() > 0) {
        pre_time_total  = vec_time.last();
        pre_lenght = vec_pos[8].last();
    }
    m_ui->progressBar_Running->setValue(0);
   // logsWrite(respond, QColor(220, 80, 115));
}

void MainWindow::serial_workRunning(double x,double y, double z, double roll,
                                    double var0, double var1, double var2, double var3,
                                    double lenght, double time_run, double time_total) {
    compute_newData(x, y, z, roll, var0, var1, var2, var3, lenght, time_run, time_total);
}

void MainWindow::serial_workEnd(double x,double y, double z, double roll,
                                double var0, double var1, double var2, double var3,
                                double lenght, double time_run, double time_total) {
    compute_newData(x, y, z, roll, var0, var1, var2, var3, lenght, time_run, time_total);
   // logsWrite(respond, QColor(220, 80, 115));
    num_sample = 0;
    time_pre = -0.01;
    m_ui->progressBar_Running->setValue(0);
//    // Fit all chart
//    for( ChartWindow *figure : m_figure) {
//        for( int  i = 0;  i < figure->var_list.count(); ++i) {
//                figure->setRangeFit(i);
//        }
//    }
    if (vec_time.size() > 0) {
        pre_time_total  = vec_time.last();
        pre_lenght = vec_pos[8].last();
    }
}

/*----UI -----*/
void MainWindow:: ui_init() {
    timer_keyboard = new QTimer(this);
    connect(m_ui->pushButton_LogsClear, &QPushButton::clicked,
                        this, &MainWindow::on_pushButton_Logs_Clear_Clicked);

    connect(timer_keyboard, &QTimer::timeout, this, &MainWindow::keyboardTimerHandle);

    connect(m_ui->pushButton_X_inc, &QPushButton::pressed,
                        this, &MainWindow::keyboardPressHandle);
    connect(m_ui->pushButton_X_dec, &QPushButton::pressed,
                        this, &MainWindow::keyboardPressHandle);
    connect(m_ui->pushButton_Y_inc, &QPushButton::pressed,
                        this, &MainWindow::keyboardPressHandle);
    connect(m_ui->pushButton_Y_dec, &QPushButton::pressed,
                        this, &MainWindow::keyboardPressHandle);
    connect(m_ui->pushButton_Z_inc, &QPushButton::pressed,
                        this, &MainWindow::keyboardPressHandle);
    connect(m_ui->pushButton_Z_dec, &QPushButton::pressed,
                        this, &MainWindow::keyboardPressHandle);
    connect(m_ui->pushButton_Roll_inc, &QPushButton::pressed,
                        this, &MainWindow::keyboardPressHandle);
    connect(m_ui->pushButton_Roll_dec, &QPushButton::pressed,
                        this, &MainWindow::keyboardPressHandle);
    connect(m_ui->pushButton_Var0_inc, &QPushButton::pressed,
                        this, &MainWindow::keyboardPressHandle);
    connect(m_ui->pushButton_Var0_dec, &QPushButton::pressed,
                        this, &MainWindow::keyboardPressHandle);
    connect(m_ui->pushButton_Var1_inc, &QPushButton::pressed,
                        this, &MainWindow::keyboardPressHandle);
    connect(m_ui->pushButton_Var1_dec, &QPushButton::pressed,
                        this, &MainWindow::keyboardPressHandle);
    connect(m_ui->pushButton_Var2_inc, &QPushButton::pressed,
                        this, &MainWindow::keyboardPressHandle);
    connect(m_ui->pushButton_Var2_dec, &QPushButton::pressed,
                        this, &MainWindow::keyboardPressHandle);
    connect(m_ui->pushButton_Var3_inc, &QPushButton::pressed,
                        this, &MainWindow::keyboardPressHandle);
    connect(m_ui->pushButton_Var3_dec, &QPushButton::pressed,
                        this, &MainWindow::keyboardPressHandle);

    connect(m_ui->pushButton_X_inc, &QPushButton::released,
                        this, &MainWindow::keyboardReleaseHandle);
    connect(m_ui->pushButton_X_dec, &QPushButton::released,
                        this, &MainWindow::keyboardReleaseHandle);
    connect(m_ui->pushButton_Y_inc, &QPushButton::released,
                        this, &MainWindow::keyboardReleaseHandle);
    connect(m_ui->pushButton_Y_dec, &QPushButton::released,
                        this, &MainWindow::keyboardReleaseHandle);
    connect(m_ui->pushButton_Z_inc, &QPushButton::released,
                        this, &MainWindow::keyboardReleaseHandle);
    connect(m_ui->pushButton_Z_dec, &QPushButton::released,
                        this, &MainWindow::keyboardReleaseHandle);
    connect(m_ui->pushButton_Roll_inc, &QPushButton::released,
                        this, &MainWindow::keyboardReleaseHandle);
    connect(m_ui->pushButton_Roll_dec, &QPushButton::released,
                        this, &MainWindow::keyboardReleaseHandle);
    connect(m_ui->pushButton_Var0_inc, &QPushButton::released,
                        this, &MainWindow::keyboardReleaseHandle);
    connect(m_ui->pushButton_Var0_dec, &QPushButton::released,
                        this, &MainWindow::keyboardReleaseHandle);
    connect(m_ui->pushButton_Var1_inc, &QPushButton::released,
                        this, &MainWindow::keyboardReleaseHandle);
    connect(m_ui->pushButton_Var1_dec, &QPushButton::released,
                        this, &MainWindow::keyboardReleaseHandle);
    connect(m_ui->pushButton_Var2_inc, &QPushButton::released,
                        this, &MainWindow::keyboardReleaseHandle);
    connect(m_ui->pushButton_Var2_dec, &QPushButton::released,
                        this, &MainWindow::keyboardReleaseHandle);
    connect(m_ui->pushButton_Var3_inc, &QPushButton::released,
                        this, &MainWindow::keyboardReleaseHandle);
    connect(m_ui->pushButton_Var3_dec, &QPushButton::released,
                        this, &MainWindow::keyboardReleaseHandle);
}

void MainWindow::logsWrite(QString message, QColor c) {
    if( message.isEmpty() || message.isNull() ) {
        M_DEBUG("log write error");
        return;
    }
    m_ui->textEdit_Logs->setTextColor(c);
    m_ui->textEdit_Logs->insertPlainText(message);
    m_ui->textEdit_Logs->insertPlainText("\n");
    m_ui->textEdit_Logs->ensureCursorVisible(); // Scroll to bottom automaticly
}

void MainWindow::on_pushButton_Logs_Clear_Clicked() {
    m_ui->textEdit_Logs->clear();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "Confirmation",
                                                                    "Close window. Sure?\n",
                                                                    QMessageBox::No | QMessageBox::Yes);
        if (resBtn != QMessageBox::Yes) {
            event->ignore();
        } else {
            event->accept();
        }
}

void MainWindow::on_pushButton_startUpCommand() {
    // Check
    if (!m_robot->isOpen())  {
        QMessageBox::critical(this, tr("Error"), tr("Comport is not connected"));
        return;
    }
    m_robot->robotResetId();
    m_robot->robotReadStatus();
    m_robot->robotReadPosition();
    m_robot->setVelocity(0.5);
    m_robot->setAccelerate(0.5);
  }

void MainWindow::on_pushButton_Stop_clicked()
{
    // Check
    if (!m_robot->isOpen())  {
        QMessageBox::critical(this, tr("Error"), tr("Comport is not connected"));
        return;
    }
    m_robot->robotStop();
}

void MainWindow::on_pushButton_Plot_Clicked() {
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
                num_sample_plot = vec_time.size();
        }
    }
    figure->show();
    m_figure.append(figure);
    // signals & slot
    connect(figure, &ChartWindow::figureClosed, this, &MainWindow::plot_figureClosed);
}

void MainWindow::on_pushButton_Request_Clicked() {
    // Check
    if (!m_robot->isOpen())  {
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
            if( m_robot->robotMoveLine(x, y, z, roll)) {
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
            if ( m_robot->robotMoveCircle(x, y, z, roll, center_x, center_y, center_z, dir) ) {
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
            if ( m_robot->robotMoveJoint(x, y, z, roll)) {
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
            if ( m_robot->robotRotateSingleJoint(joint, angle) ) {
                return;
            }
        } else {
            QMessageBox::critical(this, tr("Error"), tr("Joint must is int 0 - 3,Angle must is double"));
            return;
        }
    // OUTP
    } else if(m_ui->radioButton_Output->isChecked()) {
        bool output = false;
        if (m_ui->checkBox_Output->isChecked()) { output = true;}
        if ( m_robot->robotOutput(output)) {
                return;
            }
    // READ
    } else if(m_ui->radioButton_ReadStatus->isChecked()) {
        if ( m_robot->robotReadStatus()) {
            return;
        }
    // POSI
    } else if(m_ui->radioButton_ReadPosition->isChecked()) {
        if ( m_robot->robotReadPosition()) {
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

        if ( m_robot->robotSetting(coor, trajec) ) {
            return;
        }
    } else if(m_ui->radioButton_Method->isChecked()) {
        RobotControll::robotMethod_t method;
        if(m_ui->radioButton_Auto->isChecked()) {
            method = RobotControll:: METHOD_AUTO;
        } else if (m_ui->radioButton_SemiAuto->isChecked()) {
            method = RobotControll:: METHOD_SEMI_AUTO;
        } else if (m_ui->radioButton_Manual->isChecked()) {
            method = RobotControll:: METHOD_MANUAL;
        }
        m_robot->robotMethodChange(method);
    }
}

void MainWindow::on_pushButton_Output_Clicked() {
    // Check
    if (true)  {
        QMessageBox::critical(this, tr("Error"), tr("Comport is not connected"));
        return;
    }
    m_robot->robotOutputToggle();
}

void MainWindow::on_pushButton_Change_Limit_Clicked() {
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
                logsWrite(tr("Changed: Mode QTA veloc %1, accel %2").arg(factor_v).arg(factor_a),
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
                logsWrite(tr("Changed: Mode QVT veloc %1, total time %2s").arg(factor_v).arg(time),
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

void MainWindow::on_pushButton_Connect_Clicked() {
    if(m_ui->pushButton_Connect->text() == "CONNECT") {
        serial_openPort();
    } else {
        serial_closePort();
    }
}

void MainWindow::on_pushButton_Delete_Data_Clicked() {
    for (int i = 0; i < 28; ++i) {
        (*(vec_list.at(i))).clear();
    }
    pre_time_total = 0;
    pre_lenght = 0;
    num_sample_plot = 0;
    QMessageBox::information(this, tr("Inform"), tr("Data vector is deleted"));
}

void MainWindow::on_checkBox_Collect_Data_toggled(bool checked)
{
    collect_data = checked;
}

void MainWindow::keyboardPressHandle() {
    QPushButton *button =  (QPushButton *)sender();
    for(int i = 0; i < BUTTON_KEYBOARD_NUM; i++) {
        if (pushButton_KeyBoard[i] ==  button->objectName()) {
            key_robot =static_cast<RobotControll::robotKeyBoard_t>(i);
            break;
        }
    }
    timer_keyboard->start(m_robot->keyboard_time_period);
}

void MainWindow::keyboardReleaseHandle() {
    timer_keyboard->stop();
}

void MainWindow::keyboardTimerHandle() {
    m_robot->robotKeyBoard(key_robot);
}

bool MainWindow:: joystick_init() {
    QGamepadManager *ptrManager = QGamepadManager::instance();

    /******************************
     * Workaround code so gamepads are detected
     *****************************/
    QWindow *wnd = new QWindow();
    wnd->show();
    delete wnd;
    qApp->processEvents();
    /********************************
     * End workaround code
     ********************************/
    QList<int> lstDevices = ptrManager->connectedGamepads();
    if(!lstDevices.isEmpty()) {
            joystick = new Joysticks(lstDevices[0], this);
            connect(joystick, &Joysticks::buttonUpChanged,       this,
                              [this](bool value) {this->joystick_event(value, Joysticks::FUNC_X_V0_DEC);});
            connect(joystick, &Joysticks::buttonDownChanged, this,
                              [this](bool value) {this->joystick_event(value, Joysticks::FUNC_X_V0_INC);});
            connect(joystick, &Joysticks::buttonLeftChanged,     this,
                              [this](bool value) {this->joystick_event(value, Joysticks::FUNC_Y_V1_DEC);});
            connect(joystick, &Joysticks::buttonRightChanged,  this,
                              [this](bool value) {this->joystick_event(value, Joysticks::FUNC_Y_V1_INC);});
            connect(joystick, &Joysticks::buttonYChanged,          this,
                            [this](bool value) {this->joystick_event(value, Joysticks::FUNC_Z_V2_INC);});
            connect(joystick, &Joysticks::buttonAChanged,          this,
                            [this](bool value) {this->joystick_event(value, Joysticks::FUNC_Z_V2_DEC);});
            connect(joystick, &Joysticks::buttonXChanged,          this,
                            [this](bool value) {this->joystick_event(value, Joysticks::FUNC_ROLL_V3_DEC);});
            connect(joystick, &Joysticks::buttonBChanged,          this,
                            [this](bool value) {this->joystick_event(value, Joysticks::FUNC_ROLL_V3_INC);});
            connect(joystick, &Joysticks::buttonL1Changed,         this,
                            [this](bool value) {this->joystick_event(value, Joysticks::FUNC_OUTPUT);});
            connect(joystick, &Joysticks::buttonL2Changed,        this,
                            [this](bool value) {this->joystick_event(value, Joysticks::FUNC_INC_SPEED);});
            connect(joystick, &Joysticks::buttonR1Changed,        this,
                            [this](bool value) {this->joystick_event(value, Joysticks::FUNC_CHANGE_SPACE);});
            connect(joystick, &Joysticks::buttonR2Changed,        this,
                            [this](bool value) {this->joystick_event(value, Joysticks::FUNC_DEC_SPEED);});
    return true;
    }
    return false;
}

void  MainWindow::joystick_event(bool pressed, Joysticks::joysticksFunction_t func) {
    if (pressed) {
        switch (func) {
        case Joysticks::FUNC_X_V0_INC:
            if(is_cartesian) {
                key_robot = RobotControll::KEY_X_INC;
            } else {
                key_robot = RobotControll::KEY_VAR0_INC;
            }
            timer_keyboard->start(m_robot->keyboard_time_period);
            break;
        case Joysticks::FUNC_X_V0_DEC:
            if(is_cartesian) {
                key_robot = RobotControll::KEY_X_DEC;
            } else {
                 key_robot = RobotControll::KEY_VAR0_DEC;
            }
            timer_keyboard->start(m_robot->keyboard_time_period);
            break;
        case Joysticks::FUNC_Y_V1_INC:
            if(is_cartesian) {
                 key_robot = RobotControll::KEY_Y_INC;
            } else {
                 key_robot = RobotControll::KEY_VAR1_INC;
            }
            timer_keyboard->start(m_robot->keyboard_time_period);
            break;
        case Joysticks::FUNC_Y_V1_DEC:
            if(is_cartesian) {
                 key_robot = RobotControll::KEY_Y_DEC;
            } else {
                 key_robot = RobotControll::KEY_VAR1_DEC;
            }
            timer_keyboard->start(m_robot->keyboard_time_period);
            break;
        case Joysticks::FUNC_Z_V2_INC:
            if(is_cartesian) {
                 key_robot = RobotControll::KEY_Z_INC;
            } else {
                 key_robot = RobotControll::KEY_VAR2_INC;
            }
            timer_keyboard->start(m_robot->keyboard_time_period);
            break;
        case Joysticks::FUNC_Z_V2_DEC:
            if(is_cartesian) {
                key_robot = RobotControll::KEY_Z_DEC;
            } else {
                 key_robot = RobotControll::KEY_VAR2_DEC;
            }
            timer_keyboard->start(m_robot->keyboard_time_period);
            break;
        case Joysticks::FUNC_ROLL_V3_INC:
            if(is_cartesian) {
                 key_robot = RobotControll::KEY_ROLL_INC;
            } else {
                 key_robot = RobotControll::KEY_VAR3_INC;
            }
            timer_keyboard->start(m_robot->keyboard_time_period);
            break;
        case Joysticks::FUNC_ROLL_V3_DEC:
            if(is_cartesian) {
                 key_robot = RobotControll::KEY_ROLL_DEC;
            } else {
                 key_robot = RobotControll::KEY_VAR3_DEC;
            }
            timer_keyboard->start(m_robot->keyboard_time_period);
            break;
        case Joysticks::FUNC_OUTPUT:
            m_robot->robotOutputToggle();
            break;
        case Joysticks::FUNC_CHANGE_SPACE:
            is_cartesian = !is_cartesian;
            if(is_cartesian) {
                m_ui->label_Space->setText("SPACE: WORK");
            } else {
                m_ui->label_Space->setText("SPACE: JOINT");
            }
            break;
        case Joysticks::FUNC_INC_SPEED:
            m_robot->robotKeySpeedInc();
            break;
        case Joysticks::FUNC_DEC_SPEED:
            m_robot->robotKeySpeedDec();
            break;
        default:
            break;
        }
    } else {
        switch (func) {
        case Joysticks::FUNC_X_V0_INC:
        case Joysticks::FUNC_X_V0_DEC:
        case Joysticks::FUNC_Y_V1_INC:
        case Joysticks::FUNC_Y_V1_DEC:
        case Joysticks::FUNC_Z_V2_INC:
        case Joysticks::FUNC_Z_V2_DEC:
        case Joysticks::FUNC_ROLL_V3_INC:
        case Joysticks::FUNC_ROLL_V3_DEC:
            timer_keyboard->stop();
            break;
        default:
            break;
        }
    }
}
