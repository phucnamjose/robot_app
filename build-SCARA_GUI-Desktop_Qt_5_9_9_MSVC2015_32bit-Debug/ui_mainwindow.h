/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget_Operation;
    QWidget *tab1_Control;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_Serial;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_Comport;
    QLabel *label_Comport;
    QComboBox *comboBox_Comport;
    QHBoxLayout *horizontalLayout_Baudrate;
    QLabel *label_Baudrate;
    QComboBox *comboBox_Baudrate;
    QPushButton *pushButton_Connect;
    QLabel *label_connectStatus;
    QGroupBox *groupBox_Information;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_Joint_var;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_X_3;
    QTextEdit *textEdit_Theta1;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_Y_3;
    QTextEdit *textEdit_Theta2;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_Z_5;
    QTextEdit *textEdit_D3;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_Z_3;
    QTextEdit *textEdit_Theta4;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_XYZ_target_2;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_X_2;
    QTextEdit *textEdit_X;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_Y_2;
    QTextEdit *textEdit_Y;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_Z_2;
    QTextEdit *textEdit_Z;
    QVBoxLayout *verticalLayout_22;
    QLabel *label_Roll_2;
    QTextEdit *textEdit_Roll;
    QRadioButton *radioButton_Degree;
    QRadioButton *radioButton_Radian;
    QGroupBox *groupBox_Logs;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit_Logs;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButton_LogsClear;
    QSpacerItem *horizontalSpacer_7;
    QGroupBox *groupBox_Command;
    QGroupBox *groupBox_Input;
    QGroupBox *groupBox_Output;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Output;
    QCheckBox *checkBox_Output;
    QGroupBox *groupBox_Rotate;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_Rotate;
    QLabel *label_Rotate;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_Target_Joint;
    QTextEdit *textEdit_Target_Joint;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_Target_Angle;
    QTextEdit *textEdit_Target_Angle;
    QGroupBox *groupBox_Circle;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_Center;
    QLabel *label_CENTER;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_Center_X;
    QTextEdit *textEdit_Center_X;
    QVBoxLayout *verticalLayout_20;
    QLabel *label_Center_Y;
    QTextEdit *textEdit_Center_Y;
    QVBoxLayout *verticalLayout_21;
    QLabel *label_Center_Z;
    QTextEdit *textEdit_Center_Z;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *radioButton_Dir_counter;
    QRadioButton *radioButton_Dir_noncounter;
    QGroupBox *groupBox_Move;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_Target;
    QLabel *label_Target;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_Target_X;
    QTextEdit *textEdit_Target_X;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_Target_Y;
    QTextEdit *textEdit_Target_Y;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_Target_Z;
    QTextEdit *textEdit_Target_Z;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_Roll;
    QTextEdit *textEdit_Target_Roll;
    QGroupBox *groupBox_Trajectory;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_23;
    QRadioButton *radioButton_LSPB;
    QRadioButton *radioButton_Scurve;
    QGroupBox *groupBox_Coordinate;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_Coordinate;
    QRadioButton *radioButton_Absolute;
    QRadioButton *radioButton_Relative;
    QGroupBox *groupBox_Circle_2;
    QWidget *layoutWidget_9;
    QHBoxLayout *horizontalLayout_Center_4;
    QVBoxLayout *verticalLayout_32;
    QLabel *label_Velocity;
    QTextEdit *textEdit_Velocity_Limit;
    QVBoxLayout *verticalLayout_33;
    QLabel *label_Accelerate;
    QTextEdit *textEdit_Accelerate_Limit;
    QVBoxLayout *verticalLayout_35;
    QLabel *label_Total_Time;
    QTextEdit *textEdit_Time_Total;
    QVBoxLayout *verticalLayout_34;
    QRadioButton *radioButton_QVA;
    QRadioButton *radioButton_QVT;
    QPushButton *pushButton_Change_Limit;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_command;
    QRadioButton *radioButton_Stop;
    QRadioButton *radioButton_Scan;
    QRadioButton *radioButton_MoveHome;
    QRadioButton *radioButton_MoveLine;
    QRadioButton *radioButton_MoveCircle;
    QRadioButton *radioButton_MoveJoint;
    QRadioButton *radioButton_Rotate;
    QRadioButton *radioButton_Output;
    QRadioButton *radioButton_ReadStatus;
    QRadioButton *radioButton_ReadPosition;
    QRadioButton *radioButton_Setting;
    QPushButton *pushButton_Request;
    QProgressBar *progressBar_Running;
    QWidget *tab2_Plot;
    QWidget *layoutWidget6;
    QVBoxLayout *verticalLayout_Plot;
    QHBoxLayout *horizontalLayout_Chart1;
    QLabel *label_Chart1;
    QComboBox *comboBox_Chart1_x;
    QComboBox *comboBox_Chart1_y;
    QHBoxLayout *horizontalLayout_Chart2;
    QLabel *label_Chart2;
    QComboBox *comboBox_Chart2_x;
    QComboBox *comboBox_Chart2_y;
    QHBoxLayout *horizontalLayout_Chart3;
    QLabel *label_Chart3;
    QComboBox *comboBox_Chart3_x;
    QComboBox *comboBox_Chart3_y;
    QHBoxLayout *horizontalLayout_Chart4;
    QLabel *label_Chart4;
    QComboBox *comboBox_Chart4_x;
    QComboBox *comboBox_Chart4_y;
    QPushButton *pushButton_Plot;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_Delete_Data;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1027, 731);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        tabWidget_Operation = new QTabWidget(centralWidget);
        tabWidget_Operation->setObjectName(QStringLiteral("tabWidget_Operation"));
        tab1_Control = new QWidget();
        tab1_Control->setObjectName(QStringLiteral("tab1_Control"));
        gridLayout_5 = new QGridLayout(tab1_Control);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        groupBox_Serial = new QGroupBox(tab1_Control);
        groupBox_Serial->setObjectName(QStringLiteral("groupBox_Serial"));
        groupBox_Serial->setMaximumSize(QSize(150, 150));
        verticalLayout_3 = new QVBoxLayout(groupBox_Serial);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_Comport = new QHBoxLayout();
        horizontalLayout_Comport->setSpacing(6);
        horizontalLayout_Comport->setObjectName(QStringLiteral("horizontalLayout_Comport"));
        label_Comport = new QLabel(groupBox_Serial);
        label_Comport->setObjectName(QStringLiteral("label_Comport"));
        label_Comport->setAlignment(Qt::AlignCenter);

        horizontalLayout_Comport->addWidget(label_Comport);

        comboBox_Comport = new QComboBox(groupBox_Serial);
        comboBox_Comport->setObjectName(QStringLiteral("comboBox_Comport"));

        horizontalLayout_Comport->addWidget(comboBox_Comport);


        verticalLayout_3->addLayout(horizontalLayout_Comport);

        horizontalLayout_Baudrate = new QHBoxLayout();
        horizontalLayout_Baudrate->setSpacing(6);
        horizontalLayout_Baudrate->setObjectName(QStringLiteral("horizontalLayout_Baudrate"));
        label_Baudrate = new QLabel(groupBox_Serial);
        label_Baudrate->setObjectName(QStringLiteral("label_Baudrate"));
        label_Baudrate->setAlignment(Qt::AlignCenter);

        horizontalLayout_Baudrate->addWidget(label_Baudrate);

        comboBox_Baudrate = new QComboBox(groupBox_Serial);
        comboBox_Baudrate->setObjectName(QStringLiteral("comboBox_Baudrate"));
        comboBox_Baudrate->setEnabled(true);

        horizontalLayout_Baudrate->addWidget(comboBox_Baudrate);


        verticalLayout_3->addLayout(horizontalLayout_Baudrate);

        pushButton_Connect = new QPushButton(groupBox_Serial);
        pushButton_Connect->setObjectName(QStringLiteral("pushButton_Connect"));
        pushButton_Connect->setEnabled(true);

        verticalLayout_3->addWidget(pushButton_Connect);

        label_connectStatus = new QLabel(groupBox_Serial);
        label_connectStatus->setObjectName(QStringLiteral("label_connectStatus"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_connectStatus->setFont(font);

        verticalLayout_3->addWidget(label_connectStatus);


        gridLayout_5->addWidget(groupBox_Serial, 0, 0, 1, 1);

        groupBox_Information = new QGroupBox(tab1_Control);
        groupBox_Information->setObjectName(QStringLiteral("groupBox_Information"));
        groupBox_Information->setEnabled(true);
        layoutWidget_3 = new QWidget(groupBox_Information);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(20, 80, 308, 61));
        horizontalLayout_Joint_var = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_Joint_var->setSpacing(6);
        horizontalLayout_Joint_var->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_Joint_var->setObjectName(QStringLiteral("horizontalLayout_Joint_var"));
        horizontalLayout_Joint_var->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_Joint_var->setContentsMargins(0, 0, 0, 0);
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        label_X_3 = new QLabel(layoutWidget_3);
        label_X_3->setObjectName(QStringLiteral("label_X_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_X_3->sizePolicy().hasHeightForWidth());
        label_X_3->setSizePolicy(sizePolicy);
        label_X_3->setMaximumSize(QSize(70, 20));

        verticalLayout_13->addWidget(label_X_3);

        textEdit_Theta1 = new QTextEdit(layoutWidget_3);
        textEdit_Theta1->setObjectName(QStringLiteral("textEdit_Theta1"));
        sizePolicy.setHeightForWidth(textEdit_Theta1->sizePolicy().hasHeightForWidth());
        textEdit_Theta1->setSizePolicy(sizePolicy);
        textEdit_Theta1->setMaximumSize(QSize(70, 32));

        verticalLayout_13->addWidget(textEdit_Theta1);


        horizontalLayout_Joint_var->addLayout(verticalLayout_13);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        label_Y_3 = new QLabel(layoutWidget_3);
        label_Y_3->setObjectName(QStringLiteral("label_Y_3"));
        sizePolicy.setHeightForWidth(label_Y_3->sizePolicy().hasHeightForWidth());
        label_Y_3->setSizePolicy(sizePolicy);
        label_Y_3->setMaximumSize(QSize(70, 20));

        verticalLayout_14->addWidget(label_Y_3);

        textEdit_Theta2 = new QTextEdit(layoutWidget_3);
        textEdit_Theta2->setObjectName(QStringLiteral("textEdit_Theta2"));
        sizePolicy.setHeightForWidth(textEdit_Theta2->sizePolicy().hasHeightForWidth());
        textEdit_Theta2->setSizePolicy(sizePolicy);
        textEdit_Theta2->setMaximumSize(QSize(70, 32));

        verticalLayout_14->addWidget(textEdit_Theta2);


        horizontalLayout_Joint_var->addLayout(verticalLayout_14);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        label_Z_5 = new QLabel(layoutWidget_3);
        label_Z_5->setObjectName(QStringLiteral("label_Z_5"));
        sizePolicy.setHeightForWidth(label_Z_5->sizePolicy().hasHeightForWidth());
        label_Z_5->setSizePolicy(sizePolicy);
        label_Z_5->setMaximumSize(QSize(70, 20));

        verticalLayout_17->addWidget(label_Z_5);

        textEdit_D3 = new QTextEdit(layoutWidget_3);
        textEdit_D3->setObjectName(QStringLiteral("textEdit_D3"));
        sizePolicy.setHeightForWidth(textEdit_D3->sizePolicy().hasHeightForWidth());
        textEdit_D3->setSizePolicy(sizePolicy);
        textEdit_D3->setMaximumSize(QSize(70, 32));

        verticalLayout_17->addWidget(textEdit_D3);


        horizontalLayout_Joint_var->addLayout(verticalLayout_17);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        label_Z_3 = new QLabel(layoutWidget_3);
        label_Z_3->setObjectName(QStringLiteral("label_Z_3"));
        sizePolicy.setHeightForWidth(label_Z_3->sizePolicy().hasHeightForWidth());
        label_Z_3->setSizePolicy(sizePolicy);
        label_Z_3->setMaximumSize(QSize(70, 20));

        verticalLayout_15->addWidget(label_Z_3);

        textEdit_Theta4 = new QTextEdit(layoutWidget_3);
        textEdit_Theta4->setObjectName(QStringLiteral("textEdit_Theta4"));
        sizePolicy.setHeightForWidth(textEdit_Theta4->sizePolicy().hasHeightForWidth());
        textEdit_Theta4->setSizePolicy(sizePolicy);
        textEdit_Theta4->setMaximumSize(QSize(70, 32));

        verticalLayout_15->addWidget(textEdit_Theta4);


        horizontalLayout_Joint_var->addLayout(verticalLayout_15);

        layoutWidget_2 = new QWidget(groupBox_Information);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 20, 308, 55));
        horizontalLayout_XYZ_target_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_XYZ_target_2->setSpacing(6);
        horizontalLayout_XYZ_target_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_XYZ_target_2->setObjectName(QStringLiteral("horizontalLayout_XYZ_target_2"));
        horizontalLayout_XYZ_target_2->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_XYZ_target_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label_X_2 = new QLabel(layoutWidget_2);
        label_X_2->setObjectName(QStringLiteral("label_X_2"));
        sizePolicy.setHeightForWidth(label_X_2->sizePolicy().hasHeightForWidth());
        label_X_2->setSizePolicy(sizePolicy);
        label_X_2->setMaximumSize(QSize(70, 20));

        verticalLayout_10->addWidget(label_X_2);

        textEdit_X = new QTextEdit(layoutWidget_2);
        textEdit_X->setObjectName(QStringLiteral("textEdit_X"));
        sizePolicy.setHeightForWidth(textEdit_X->sizePolicy().hasHeightForWidth());
        textEdit_X->setSizePolicy(sizePolicy);
        textEdit_X->setMaximumSize(QSize(70, 32));

        verticalLayout_10->addWidget(textEdit_X);


        horizontalLayout_XYZ_target_2->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        label_Y_2 = new QLabel(layoutWidget_2);
        label_Y_2->setObjectName(QStringLiteral("label_Y_2"));
        sizePolicy.setHeightForWidth(label_Y_2->sizePolicy().hasHeightForWidth());
        label_Y_2->setSizePolicy(sizePolicy);
        label_Y_2->setMaximumSize(QSize(70, 20));

        verticalLayout_11->addWidget(label_Y_2);

        textEdit_Y = new QTextEdit(layoutWidget_2);
        textEdit_Y->setObjectName(QStringLiteral("textEdit_Y"));
        sizePolicy.setHeightForWidth(textEdit_Y->sizePolicy().hasHeightForWidth());
        textEdit_Y->setSizePolicy(sizePolicy);
        textEdit_Y->setMaximumSize(QSize(70, 32));

        verticalLayout_11->addWidget(textEdit_Y);


        horizontalLayout_XYZ_target_2->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        label_Z_2 = new QLabel(layoutWidget_2);
        label_Z_2->setObjectName(QStringLiteral("label_Z_2"));
        sizePolicy.setHeightForWidth(label_Z_2->sizePolicy().hasHeightForWidth());
        label_Z_2->setSizePolicy(sizePolicy);
        label_Z_2->setMaximumSize(QSize(70, 20));

        verticalLayout_12->addWidget(label_Z_2);

        textEdit_Z = new QTextEdit(layoutWidget_2);
        textEdit_Z->setObjectName(QStringLiteral("textEdit_Z"));
        sizePolicy.setHeightForWidth(textEdit_Z->sizePolicy().hasHeightForWidth());
        textEdit_Z->setSizePolicy(sizePolicy);
        textEdit_Z->setMaximumSize(QSize(70, 32));

        verticalLayout_12->addWidget(textEdit_Z);


        horizontalLayout_XYZ_target_2->addLayout(verticalLayout_12);

        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setSpacing(6);
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        label_Roll_2 = new QLabel(layoutWidget_2);
        label_Roll_2->setObjectName(QStringLiteral("label_Roll_2"));
        sizePolicy.setHeightForWidth(label_Roll_2->sizePolicy().hasHeightForWidth());
        label_Roll_2->setSizePolicy(sizePolicy);
        label_Roll_2->setMaximumSize(QSize(70, 20));

        verticalLayout_22->addWidget(label_Roll_2);

        textEdit_Roll = new QTextEdit(layoutWidget_2);
        textEdit_Roll->setObjectName(QStringLiteral("textEdit_Roll"));
        sizePolicy.setHeightForWidth(textEdit_Roll->sizePolicy().hasHeightForWidth());
        textEdit_Roll->setSizePolicy(sizePolicy);
        textEdit_Roll->setMaximumSize(QSize(70, 32));

        verticalLayout_22->addWidget(textEdit_Roll);


        horizontalLayout_XYZ_target_2->addLayout(verticalLayout_22);

        radioButton_Degree = new QRadioButton(groupBox_Information);
        radioButton_Degree->setObjectName(QStringLiteral("radioButton_Degree"));
        radioButton_Degree->setGeometry(QRect(340, 50, 41, 17));
        radioButton_Degree->setChecked(true);
        radioButton_Radian = new QRadioButton(groupBox_Information);
        radioButton_Radian->setObjectName(QStringLiteral("radioButton_Radian"));
        radioButton_Radian->setGeometry(QRect(340, 20, 41, 17));
        radioButton_Radian->setChecked(false);

        gridLayout_5->addWidget(groupBox_Information, 0, 1, 1, 1);

        groupBox_Logs = new QGroupBox(tab1_Control);
        groupBox_Logs->setObjectName(QStringLiteral("groupBox_Logs"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_Logs->sizePolicy().hasHeightForWidth());
        groupBox_Logs->setSizePolicy(sizePolicy1);
        groupBox_Logs->setMaximumSize(QSize(390, 620));
        verticalLayout = new QVBoxLayout(groupBox_Logs);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        scrollArea = new QScrollArea(groupBox_Logs);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setMaximumSize(QSize(370, 600));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 368, 554));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        textEdit_Logs = new QTextEdit(scrollAreaWidgetContents);
        textEdit_Logs->setObjectName(QStringLiteral("textEdit_Logs"));
        sizePolicy1.setHeightForWidth(textEdit_Logs->sizePolicy().hasHeightForWidth());
        textEdit_Logs->setSizePolicy(sizePolicy1);
        textEdit_Logs->setMaximumSize(QSize(350, 600));
        QFont font1;
        font1.setPointSize(10);
        textEdit_Logs->setFont(font1);

        verticalLayout_2->addWidget(textEdit_Logs);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        pushButton_LogsClear = new QPushButton(groupBox_Logs);
        pushButton_LogsClear->setObjectName(QStringLiteral("pushButton_LogsClear"));

        horizontalLayout->addWidget(pushButton_LogsClear);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_5->addWidget(groupBox_Logs, 0, 2, 2, 1);

        groupBox_Command = new QGroupBox(tab1_Control);
        groupBox_Command->setObjectName(QStringLiteral("groupBox_Command"));
        groupBox_Input = new QGroupBox(groupBox_Command);
        groupBox_Input->setObjectName(QStringLiteral("groupBox_Input"));
        groupBox_Input->setGeometry(QRect(130, 20, 441, 391));
        groupBox_Output = new QGroupBox(groupBox_Input);
        groupBox_Output->setObjectName(QStringLiteral("groupBox_Output"));
        groupBox_Output->setGeometry(QRect(250, 170, 151, 71));
        layoutWidget = new QWidget(groupBox_Output);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 148, 54));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_Output = new QLabel(layoutWidget);
        label_Output->setObjectName(QStringLiteral("label_Output"));
        sizePolicy.setHeightForWidth(label_Output->sizePolicy().hasHeightForWidth());
        label_Output->setSizePolicy(sizePolicy);
        label_Output->setMinimumSize(QSize(70, 52));
        label_Output->setMaximumSize(QSize(70, 52));
        label_Output->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_Output);

        checkBox_Output = new QCheckBox(layoutWidget);
        checkBox_Output->setObjectName(QStringLiteral("checkBox_Output"));
        checkBox_Output->setMinimumSize(QSize(70, 52));
        checkBox_Output->setMaximumSize(QSize(70, 52));

        horizontalLayout_2->addWidget(checkBox_Output);

        groupBox_Rotate = new QGroupBox(groupBox_Input);
        groupBox_Rotate->setObjectName(QStringLiteral("groupBox_Rotate"));
        groupBox_Rotate->setGeometry(QRect(10, 170, 231, 71));
        layoutWidget1 = new QWidget(groupBox_Rotate);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 10, 231, 55));
        horizontalLayout_Rotate = new QHBoxLayout(layoutWidget1);
        horizontalLayout_Rotate->setSpacing(6);
        horizontalLayout_Rotate->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_Rotate->setObjectName(QStringLiteral("horizontalLayout_Rotate"));
        horizontalLayout_Rotate->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_Rotate->setContentsMargins(0, 0, 0, 0);
        label_Rotate = new QLabel(layoutWidget1);
        label_Rotate->setObjectName(QStringLiteral("label_Rotate"));
        sizePolicy.setHeightForWidth(label_Rotate->sizePolicy().hasHeightForWidth());
        label_Rotate->setSizePolicy(sizePolicy);
        label_Rotate->setMinimumSize(QSize(70, 52));
        label_Rotate->setMaximumSize(QSize(70, 52));
        label_Rotate->setAlignment(Qt::AlignCenter);

        horizontalLayout_Rotate->addWidget(label_Rotate);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_Target_Joint = new QLabel(layoutWidget1);
        label_Target_Joint->setObjectName(QStringLiteral("label_Target_Joint"));
        sizePolicy.setHeightForWidth(label_Target_Joint->sizePolicy().hasHeightForWidth());
        label_Target_Joint->setSizePolicy(sizePolicy);
        label_Target_Joint->setMaximumSize(QSize(70, 20));

        verticalLayout_8->addWidget(label_Target_Joint);

        textEdit_Target_Joint = new QTextEdit(layoutWidget1);
        textEdit_Target_Joint->setObjectName(QStringLiteral("textEdit_Target_Joint"));
        sizePolicy.setHeightForWidth(textEdit_Target_Joint->sizePolicy().hasHeightForWidth());
        textEdit_Target_Joint->setSizePolicy(sizePolicy);
        textEdit_Target_Joint->setMaximumSize(QSize(70, 32));

        verticalLayout_8->addWidget(textEdit_Target_Joint);


        horizontalLayout_Rotate->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_Target_Angle = new QLabel(layoutWidget1);
        label_Target_Angle->setObjectName(QStringLiteral("label_Target_Angle"));
        sizePolicy.setHeightForWidth(label_Target_Angle->sizePolicy().hasHeightForWidth());
        label_Target_Angle->setSizePolicy(sizePolicy);
        label_Target_Angle->setMaximumSize(QSize(70, 20));

        verticalLayout_9->addWidget(label_Target_Angle);

        textEdit_Target_Angle = new QTextEdit(layoutWidget1);
        textEdit_Target_Angle->setObjectName(QStringLiteral("textEdit_Target_Angle"));
        sizePolicy.setHeightForWidth(textEdit_Target_Angle->sizePolicy().hasHeightForWidth());
        textEdit_Target_Angle->setSizePolicy(sizePolicy);
        textEdit_Target_Angle->setMaximumSize(QSize(70, 32));

        verticalLayout_9->addWidget(textEdit_Target_Angle);


        horizontalLayout_Rotate->addLayout(verticalLayout_9);

        groupBox_Circle = new QGroupBox(groupBox_Input);
        groupBox_Circle->setObjectName(QStringLiteral("groupBox_Circle"));
        groupBox_Circle->setGeometry(QRect(10, 100, 391, 71));
        layoutWidget_5 = new QWidget(groupBox_Circle);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(0, 10, 366, 55));
        horizontalLayout_Center = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_Center->setSpacing(6);
        horizontalLayout_Center->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_Center->setObjectName(QStringLiteral("horizontalLayout_Center"));
        horizontalLayout_Center->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_Center->setContentsMargins(0, 0, 0, 0);
        label_CENTER = new QLabel(layoutWidget_5);
        label_CENTER->setObjectName(QStringLiteral("label_CENTER"));
        sizePolicy.setHeightForWidth(label_CENTER->sizePolicy().hasHeightForWidth());
        label_CENTER->setSizePolicy(sizePolicy);
        label_CENTER->setMinimumSize(QSize(70, 52));
        label_CENTER->setMaximumSize(QSize(70, 52));
        label_CENTER->setAlignment(Qt::AlignCenter);

        horizontalLayout_Center->addWidget(label_CENTER);

        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setSpacing(6);
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        label_Center_X = new QLabel(layoutWidget_5);
        label_Center_X->setObjectName(QStringLiteral("label_Center_X"));
        sizePolicy.setHeightForWidth(label_Center_X->sizePolicy().hasHeightForWidth());
        label_Center_X->setSizePolicy(sizePolicy);
        label_Center_X->setMaximumSize(QSize(70, 20));

        verticalLayout_19->addWidget(label_Center_X);

        textEdit_Center_X = new QTextEdit(layoutWidget_5);
        textEdit_Center_X->setObjectName(QStringLiteral("textEdit_Center_X"));
        sizePolicy.setHeightForWidth(textEdit_Center_X->sizePolicy().hasHeightForWidth());
        textEdit_Center_X->setSizePolicy(sizePolicy);
        textEdit_Center_X->setMaximumSize(QSize(70, 32));

        verticalLayout_19->addWidget(textEdit_Center_X);


        horizontalLayout_Center->addLayout(verticalLayout_19);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setSpacing(6);
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        label_Center_Y = new QLabel(layoutWidget_5);
        label_Center_Y->setObjectName(QStringLiteral("label_Center_Y"));
        sizePolicy.setHeightForWidth(label_Center_Y->sizePolicy().hasHeightForWidth());
        label_Center_Y->setSizePolicy(sizePolicy);
        label_Center_Y->setMaximumSize(QSize(70, 20));

        verticalLayout_20->addWidget(label_Center_Y);

        textEdit_Center_Y = new QTextEdit(layoutWidget_5);
        textEdit_Center_Y->setObjectName(QStringLiteral("textEdit_Center_Y"));
        sizePolicy.setHeightForWidth(textEdit_Center_Y->sizePolicy().hasHeightForWidth());
        textEdit_Center_Y->setSizePolicy(sizePolicy);
        textEdit_Center_Y->setMaximumSize(QSize(70, 32));

        verticalLayout_20->addWidget(textEdit_Center_Y);


        horizontalLayout_Center->addLayout(verticalLayout_20);

        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setSpacing(6);
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        label_Center_Z = new QLabel(layoutWidget_5);
        label_Center_Z->setObjectName(QStringLiteral("label_Center_Z"));
        sizePolicy.setHeightForWidth(label_Center_Z->sizePolicy().hasHeightForWidth());
        label_Center_Z->setSizePolicy(sizePolicy);
        label_Center_Z->setMaximumSize(QSize(70, 20));

        verticalLayout_21->addWidget(label_Center_Z);

        textEdit_Center_Z = new QTextEdit(layoutWidget_5);
        textEdit_Center_Z->setObjectName(QStringLiteral("textEdit_Center_Z"));
        sizePolicy.setHeightForWidth(textEdit_Center_Z->sizePolicy().hasHeightForWidth());
        textEdit_Center_Z->setSizePolicy(sizePolicy);
        textEdit_Center_Z->setMaximumSize(QSize(70, 32));

        verticalLayout_21->addWidget(textEdit_Center_Z);


        horizontalLayout_Center->addLayout(verticalLayout_21);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        radioButton_Dir_counter = new QRadioButton(layoutWidget_5);
        radioButton_Dir_counter->setObjectName(QStringLiteral("radioButton_Dir_counter"));
        radioButton_Dir_counter->setChecked(true);

        verticalLayout_4->addWidget(radioButton_Dir_counter);

        radioButton_Dir_noncounter = new QRadioButton(layoutWidget_5);
        radioButton_Dir_noncounter->setObjectName(QStringLiteral("radioButton_Dir_noncounter"));

        verticalLayout_4->addWidget(radioButton_Dir_noncounter);


        horizontalLayout_Center->addLayout(verticalLayout_4);

        groupBox_Move = new QGroupBox(groupBox_Input);
        groupBox_Move->setObjectName(QStringLiteral("groupBox_Move"));
        groupBox_Move->setGeometry(QRect(10, 20, 391, 80));
        layoutWidget2 = new QWidget(groupBox_Move);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 10, 384, 61));
        horizontalLayout_Target = new QHBoxLayout(layoutWidget2);
        horizontalLayout_Target->setSpacing(6);
        horizontalLayout_Target->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_Target->setObjectName(QStringLiteral("horizontalLayout_Target"));
        horizontalLayout_Target->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_Target->setContentsMargins(0, 0, 0, 0);
        label_Target = new QLabel(layoutWidget2);
        label_Target->setObjectName(QStringLiteral("label_Target"));
        sizePolicy.setHeightForWidth(label_Target->sizePolicy().hasHeightForWidth());
        label_Target->setSizePolicy(sizePolicy);
        label_Target->setMinimumSize(QSize(70, 52));
        label_Target->setMaximumSize(QSize(70, 52));
        label_Target->setAlignment(Qt::AlignCenter);

        horizontalLayout_Target->addWidget(label_Target);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_Target_X = new QLabel(layoutWidget2);
        label_Target_X->setObjectName(QStringLiteral("label_Target_X"));
        sizePolicy.setHeightForWidth(label_Target_X->sizePolicy().hasHeightForWidth());
        label_Target_X->setSizePolicy(sizePolicy);
        label_Target_X->setMaximumSize(QSize(70, 20));

        verticalLayout_5->addWidget(label_Target_X);

        textEdit_Target_X = new QTextEdit(layoutWidget2);
        textEdit_Target_X->setObjectName(QStringLiteral("textEdit_Target_X"));
        sizePolicy.setHeightForWidth(textEdit_Target_X->sizePolicy().hasHeightForWidth());
        textEdit_Target_X->setSizePolicy(sizePolicy);
        textEdit_Target_X->setMaximumSize(QSize(70, 32));

        verticalLayout_5->addWidget(textEdit_Target_X);


        horizontalLayout_Target->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_Target_Y = new QLabel(layoutWidget2);
        label_Target_Y->setObjectName(QStringLiteral("label_Target_Y"));
        sizePolicy.setHeightForWidth(label_Target_Y->sizePolicy().hasHeightForWidth());
        label_Target_Y->setSizePolicy(sizePolicy);
        label_Target_Y->setMaximumSize(QSize(70, 20));

        verticalLayout_6->addWidget(label_Target_Y);

        textEdit_Target_Y = new QTextEdit(layoutWidget2);
        textEdit_Target_Y->setObjectName(QStringLiteral("textEdit_Target_Y"));
        sizePolicy.setHeightForWidth(textEdit_Target_Y->sizePolicy().hasHeightForWidth());
        textEdit_Target_Y->setSizePolicy(sizePolicy);
        textEdit_Target_Y->setMaximumSize(QSize(70, 32));

        verticalLayout_6->addWidget(textEdit_Target_Y);


        horizontalLayout_Target->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_Target_Z = new QLabel(layoutWidget2);
        label_Target_Z->setObjectName(QStringLiteral("label_Target_Z"));
        sizePolicy.setHeightForWidth(label_Target_Z->sizePolicy().hasHeightForWidth());
        label_Target_Z->setSizePolicy(sizePolicy);
        label_Target_Z->setMaximumSize(QSize(70, 20));

        verticalLayout_7->addWidget(label_Target_Z);

        textEdit_Target_Z = new QTextEdit(layoutWidget2);
        textEdit_Target_Z->setObjectName(QStringLiteral("textEdit_Target_Z"));
        sizePolicy.setHeightForWidth(textEdit_Target_Z->sizePolicy().hasHeightForWidth());
        textEdit_Target_Z->setSizePolicy(sizePolicy);
        textEdit_Target_Z->setMaximumSize(QSize(70, 32));

        verticalLayout_7->addWidget(textEdit_Target_Z);


        horizontalLayout_Target->addLayout(verticalLayout_7);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        label_Roll = new QLabel(layoutWidget2);
        label_Roll->setObjectName(QStringLiteral("label_Roll"));
        sizePolicy.setHeightForWidth(label_Roll->sizePolicy().hasHeightForWidth());
        label_Roll->setSizePolicy(sizePolicy);
        label_Roll->setMaximumSize(QSize(70, 20));

        verticalLayout_18->addWidget(label_Roll);

        textEdit_Target_Roll = new QTextEdit(layoutWidget2);
        textEdit_Target_Roll->setObjectName(QStringLiteral("textEdit_Target_Roll"));
        sizePolicy.setHeightForWidth(textEdit_Target_Roll->sizePolicy().hasHeightForWidth());
        textEdit_Target_Roll->setSizePolicy(sizePolicy);
        textEdit_Target_Roll->setMaximumSize(QSize(70, 32));

        verticalLayout_18->addWidget(textEdit_Target_Roll);


        horizontalLayout_Target->addLayout(verticalLayout_18);

        groupBox_Trajectory = new QGroupBox(groupBox_Input);
        groupBox_Trajectory->setObjectName(QStringLiteral("groupBox_Trajectory"));
        groupBox_Trajectory->setGeometry(QRect(110, 240, 91, 71));
        layoutWidget3 = new QWidget(groupBox_Trajectory);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(0, 20, 84, 42));
        verticalLayout_23 = new QVBoxLayout(layoutWidget3);
        verticalLayout_23->setSpacing(6);
        verticalLayout_23->setContentsMargins(11, 11, 11, 11);
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        verticalLayout_23->setContentsMargins(0, 0, 0, 0);
        radioButton_LSPB = new QRadioButton(layoutWidget3);
        radioButton_LSPB->setObjectName(QStringLiteral("radioButton_LSPB"));
        radioButton_LSPB->setChecked(true);

        verticalLayout_23->addWidget(radioButton_LSPB);

        radioButton_Scurve = new QRadioButton(layoutWidget3);
        radioButton_Scurve->setObjectName(QStringLiteral("radioButton_Scurve"));

        verticalLayout_23->addWidget(radioButton_Scurve);

        groupBox_Coordinate = new QGroupBox(groupBox_Input);
        groupBox_Coordinate->setObjectName(QStringLiteral("groupBox_Coordinate"));
        groupBox_Coordinate->setGeometry(QRect(10, 240, 91, 71));
        layoutWidget4 = new QWidget(groupBox_Coordinate);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(0, 20, 84, 42));
        verticalLayout_Coordinate = new QVBoxLayout(layoutWidget4);
        verticalLayout_Coordinate->setSpacing(6);
        verticalLayout_Coordinate->setContentsMargins(11, 11, 11, 11);
        verticalLayout_Coordinate->setObjectName(QStringLiteral("verticalLayout_Coordinate"));
        verticalLayout_Coordinate->setContentsMargins(0, 0, 0, 0);
        radioButton_Absolute = new QRadioButton(layoutWidget4);
        radioButton_Absolute->setObjectName(QStringLiteral("radioButton_Absolute"));
        radioButton_Absolute->setChecked(true);

        verticalLayout_Coordinate->addWidget(radioButton_Absolute);

        radioButton_Relative = new QRadioButton(layoutWidget4);
        radioButton_Relative->setObjectName(QStringLiteral("radioButton_Relative"));

        verticalLayout_Coordinate->addWidget(radioButton_Relative);

        groupBox_Circle_2 = new QGroupBox(groupBox_Input);
        groupBox_Circle_2->setObjectName(QStringLiteral("groupBox_Circle_2"));
        groupBox_Circle_2->setGeometry(QRect(10, 310, 371, 71));
        layoutWidget_9 = new QWidget(groupBox_Circle_2);
        layoutWidget_9->setObjectName(QStringLiteral("layoutWidget_9"));
        layoutWidget_9->setGeometry(QRect(0, 10, 363, 55));
        horizontalLayout_Center_4 = new QHBoxLayout(layoutWidget_9);
        horizontalLayout_Center_4->setSpacing(6);
        horizontalLayout_Center_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_Center_4->setObjectName(QStringLiteral("horizontalLayout_Center_4"));
        horizontalLayout_Center_4->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_Center_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_32 = new QVBoxLayout();
        verticalLayout_32->setSpacing(6);
        verticalLayout_32->setObjectName(QStringLiteral("verticalLayout_32"));
        label_Velocity = new QLabel(layoutWidget_9);
        label_Velocity->setObjectName(QStringLiteral("label_Velocity"));
        sizePolicy.setHeightForWidth(label_Velocity->sizePolicy().hasHeightForWidth());
        label_Velocity->setSizePolicy(sizePolicy);
        label_Velocity->setMaximumSize(QSize(70, 20));

        verticalLayout_32->addWidget(label_Velocity);

        textEdit_Velocity_Limit = new QTextEdit(layoutWidget_9);
        textEdit_Velocity_Limit->setObjectName(QStringLiteral("textEdit_Velocity_Limit"));
        sizePolicy.setHeightForWidth(textEdit_Velocity_Limit->sizePolicy().hasHeightForWidth());
        textEdit_Velocity_Limit->setSizePolicy(sizePolicy);
        textEdit_Velocity_Limit->setMaximumSize(QSize(70, 32));

        verticalLayout_32->addWidget(textEdit_Velocity_Limit);


        horizontalLayout_Center_4->addLayout(verticalLayout_32);

        verticalLayout_33 = new QVBoxLayout();
        verticalLayout_33->setSpacing(6);
        verticalLayout_33->setObjectName(QStringLiteral("verticalLayout_33"));
        label_Accelerate = new QLabel(layoutWidget_9);
        label_Accelerate->setObjectName(QStringLiteral("label_Accelerate"));
        sizePolicy.setHeightForWidth(label_Accelerate->sizePolicy().hasHeightForWidth());
        label_Accelerate->setSizePolicy(sizePolicy);
        label_Accelerate->setMaximumSize(QSize(70, 20));

        verticalLayout_33->addWidget(label_Accelerate);

        textEdit_Accelerate_Limit = new QTextEdit(layoutWidget_9);
        textEdit_Accelerate_Limit->setObjectName(QStringLiteral("textEdit_Accelerate_Limit"));
        sizePolicy.setHeightForWidth(textEdit_Accelerate_Limit->sizePolicy().hasHeightForWidth());
        textEdit_Accelerate_Limit->setSizePolicy(sizePolicy);
        textEdit_Accelerate_Limit->setMaximumSize(QSize(70, 32));

        verticalLayout_33->addWidget(textEdit_Accelerate_Limit);


        horizontalLayout_Center_4->addLayout(verticalLayout_33);

        verticalLayout_35 = new QVBoxLayout();
        verticalLayout_35->setSpacing(6);
        verticalLayout_35->setObjectName(QStringLiteral("verticalLayout_35"));
        label_Total_Time = new QLabel(layoutWidget_9);
        label_Total_Time->setObjectName(QStringLiteral("label_Total_Time"));
        sizePolicy.setHeightForWidth(label_Total_Time->sizePolicy().hasHeightForWidth());
        label_Total_Time->setSizePolicy(sizePolicy);
        label_Total_Time->setMaximumSize(QSize(70, 20));

        verticalLayout_35->addWidget(label_Total_Time);

        textEdit_Time_Total = new QTextEdit(layoutWidget_9);
        textEdit_Time_Total->setObjectName(QStringLiteral("textEdit_Time_Total"));
        sizePolicy.setHeightForWidth(textEdit_Time_Total->sizePolicy().hasHeightForWidth());
        textEdit_Time_Total->setSizePolicy(sizePolicy);
        textEdit_Time_Total->setMaximumSize(QSize(70, 32));

        verticalLayout_35->addWidget(textEdit_Time_Total);


        horizontalLayout_Center_4->addLayout(verticalLayout_35);

        verticalLayout_34 = new QVBoxLayout();
        verticalLayout_34->setSpacing(6);
        verticalLayout_34->setObjectName(QStringLiteral("verticalLayout_34"));
        radioButton_QVA = new QRadioButton(layoutWidget_9);
        radioButton_QVA->setObjectName(QStringLiteral("radioButton_QVA"));
        radioButton_QVA->setChecked(true);

        verticalLayout_34->addWidget(radioButton_QVA);

        radioButton_QVT = new QRadioButton(layoutWidget_9);
        radioButton_QVT->setObjectName(QStringLiteral("radioButton_QVT"));

        verticalLayout_34->addWidget(radioButton_QVT);


        horizontalLayout_Center_4->addLayout(verticalLayout_34);

        pushButton_Change_Limit = new QPushButton(layoutWidget_9);
        pushButton_Change_Limit->setObjectName(QStringLiteral("pushButton_Change_Limit"));

        horizontalLayout_Center_4->addWidget(pushButton_Change_Limit);

        layoutWidget5 = new QWidget(groupBox_Command);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 30, 111, 321));
        verticalLayout_command = new QVBoxLayout(layoutWidget5);
        verticalLayout_command->setSpacing(6);
        verticalLayout_command->setContentsMargins(11, 11, 11, 11);
        verticalLayout_command->setObjectName(QStringLiteral("verticalLayout_command"));
        verticalLayout_command->setContentsMargins(0, 0, 0, 0);
        radioButton_Stop = new QRadioButton(layoutWidget5);
        radioButton_Stop->setObjectName(QStringLiteral("radioButton_Stop"));
        radioButton_Stop->setChecked(true);

        verticalLayout_command->addWidget(radioButton_Stop);

        radioButton_Scan = new QRadioButton(layoutWidget5);
        radioButton_Scan->setObjectName(QStringLiteral("radioButton_Scan"));

        verticalLayout_command->addWidget(radioButton_Scan);

        radioButton_MoveHome = new QRadioButton(layoutWidget5);
        radioButton_MoveHome->setObjectName(QStringLiteral("radioButton_MoveHome"));

        verticalLayout_command->addWidget(radioButton_MoveHome);

        radioButton_MoveLine = new QRadioButton(layoutWidget5);
        radioButton_MoveLine->setObjectName(QStringLiteral("radioButton_MoveLine"));

        verticalLayout_command->addWidget(radioButton_MoveLine);

        radioButton_MoveCircle = new QRadioButton(layoutWidget5);
        radioButton_MoveCircle->setObjectName(QStringLiteral("radioButton_MoveCircle"));

        verticalLayout_command->addWidget(radioButton_MoveCircle);

        radioButton_MoveJoint = new QRadioButton(layoutWidget5);
        radioButton_MoveJoint->setObjectName(QStringLiteral("radioButton_MoveJoint"));

        verticalLayout_command->addWidget(radioButton_MoveJoint);

        radioButton_Rotate = new QRadioButton(layoutWidget5);
        radioButton_Rotate->setObjectName(QStringLiteral("radioButton_Rotate"));

        verticalLayout_command->addWidget(radioButton_Rotate);

        radioButton_Output = new QRadioButton(layoutWidget5);
        radioButton_Output->setObjectName(QStringLiteral("radioButton_Output"));

        verticalLayout_command->addWidget(radioButton_Output);

        radioButton_ReadStatus = new QRadioButton(layoutWidget5);
        radioButton_ReadStatus->setObjectName(QStringLiteral("radioButton_ReadStatus"));

        verticalLayout_command->addWidget(radioButton_ReadStatus);

        radioButton_ReadPosition = new QRadioButton(layoutWidget5);
        radioButton_ReadPosition->setObjectName(QStringLiteral("radioButton_ReadPosition"));

        verticalLayout_command->addWidget(radioButton_ReadPosition);

        radioButton_Setting = new QRadioButton(layoutWidget5);
        radioButton_Setting->setObjectName(QStringLiteral("radioButton_Setting"));

        verticalLayout_command->addWidget(radioButton_Setting);

        pushButton_Request = new QPushButton(layoutWidget5);
        pushButton_Request->setObjectName(QStringLiteral("pushButton_Request"));

        verticalLayout_command->addWidget(pushButton_Request);

        progressBar_Running = new QProgressBar(groupBox_Command);
        progressBar_Running->setObjectName(QStringLiteral("progressBar_Running"));
        progressBar_Running->setEnabled(true);
        progressBar_Running->setGeometry(QRect(10, 450, 561, 23));
        progressBar_Running->setMaximum(1000);
        progressBar_Running->setValue(0);
        progressBar_Running->setTextVisible(false);

        gridLayout_5->addWidget(groupBox_Command, 1, 0, 1, 2);

        tabWidget_Operation->addTab(tab1_Control, QString());
        tab2_Plot = new QWidget();
        tab2_Plot->setObjectName(QStringLiteral("tab2_Plot"));
        layoutWidget6 = new QWidget(tab2_Plot);
        layoutWidget6->setObjectName(QStringLiteral("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(20, 10, 361, 371));
        verticalLayout_Plot = new QVBoxLayout(layoutWidget6);
        verticalLayout_Plot->setSpacing(6);
        verticalLayout_Plot->setContentsMargins(11, 11, 11, 11);
        verticalLayout_Plot->setObjectName(QStringLiteral("verticalLayout_Plot"));
        verticalLayout_Plot->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_Chart1 = new QHBoxLayout();
        horizontalLayout_Chart1->setSpacing(6);
        horizontalLayout_Chart1->setObjectName(QStringLiteral("horizontalLayout_Chart1"));
        label_Chart1 = new QLabel(layoutWidget6);
        label_Chart1->setObjectName(QStringLiteral("label_Chart1"));

        horizontalLayout_Chart1->addWidget(label_Chart1);

        comboBox_Chart1_x = new QComboBox(layoutWidget6);
        comboBox_Chart1_x->setObjectName(QStringLiteral("comboBox_Chart1_x"));

        horizontalLayout_Chart1->addWidget(comboBox_Chart1_x);

        comboBox_Chart1_y = new QComboBox(layoutWidget6);
        comboBox_Chart1_y->setObjectName(QStringLiteral("comboBox_Chart1_y"));

        horizontalLayout_Chart1->addWidget(comboBox_Chart1_y);


        verticalLayout_Plot->addLayout(horizontalLayout_Chart1);

        horizontalLayout_Chart2 = new QHBoxLayout();
        horizontalLayout_Chart2->setSpacing(6);
        horizontalLayout_Chart2->setObjectName(QStringLiteral("horizontalLayout_Chart2"));
        label_Chart2 = new QLabel(layoutWidget6);
        label_Chart2->setObjectName(QStringLiteral("label_Chart2"));

        horizontalLayout_Chart2->addWidget(label_Chart2);

        comboBox_Chart2_x = new QComboBox(layoutWidget6);
        comboBox_Chart2_x->setObjectName(QStringLiteral("comboBox_Chart2_x"));

        horizontalLayout_Chart2->addWidget(comboBox_Chart2_x);

        comboBox_Chart2_y = new QComboBox(layoutWidget6);
        comboBox_Chart2_y->setObjectName(QStringLiteral("comboBox_Chart2_y"));

        horizontalLayout_Chart2->addWidget(comboBox_Chart2_y);


        verticalLayout_Plot->addLayout(horizontalLayout_Chart2);

        horizontalLayout_Chart3 = new QHBoxLayout();
        horizontalLayout_Chart3->setSpacing(6);
        horizontalLayout_Chart3->setObjectName(QStringLiteral("horizontalLayout_Chart3"));
        label_Chart3 = new QLabel(layoutWidget6);
        label_Chart3->setObjectName(QStringLiteral("label_Chart3"));

        horizontalLayout_Chart3->addWidget(label_Chart3);

        comboBox_Chart3_x = new QComboBox(layoutWidget6);
        comboBox_Chart3_x->setObjectName(QStringLiteral("comboBox_Chart3_x"));

        horizontalLayout_Chart3->addWidget(comboBox_Chart3_x);

        comboBox_Chart3_y = new QComboBox(layoutWidget6);
        comboBox_Chart3_y->setObjectName(QStringLiteral("comboBox_Chart3_y"));

        horizontalLayout_Chart3->addWidget(comboBox_Chart3_y);


        verticalLayout_Plot->addLayout(horizontalLayout_Chart3);

        horizontalLayout_Chart4 = new QHBoxLayout();
        horizontalLayout_Chart4->setSpacing(6);
        horizontalLayout_Chart4->setObjectName(QStringLiteral("horizontalLayout_Chart4"));
        label_Chart4 = new QLabel(layoutWidget6);
        label_Chart4->setObjectName(QStringLiteral("label_Chart4"));

        horizontalLayout_Chart4->addWidget(label_Chart4);

        comboBox_Chart4_x = new QComboBox(layoutWidget6);
        comboBox_Chart4_x->setObjectName(QStringLiteral("comboBox_Chart4_x"));

        horizontalLayout_Chart4->addWidget(comboBox_Chart4_x);

        comboBox_Chart4_y = new QComboBox(layoutWidget6);
        comboBox_Chart4_y->setObjectName(QStringLiteral("comboBox_Chart4_y"));

        horizontalLayout_Chart4->addWidget(comboBox_Chart4_y);


        verticalLayout_Plot->addLayout(horizontalLayout_Chart4);

        pushButton_Plot = new QPushButton(layoutWidget6);
        pushButton_Plot->setObjectName(QStringLiteral("pushButton_Plot"));

        verticalLayout_Plot->addWidget(pushButton_Plot);

        verticalSpacer = new QSpacerItem(20, 100, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_Plot->addItem(verticalSpacer);

        pushButton_Delete_Data = new QPushButton(layoutWidget6);
        pushButton_Delete_Data->setObjectName(QStringLiteral("pushButton_Delete_Data"));

        verticalLayout_Plot->addWidget(pushButton_Delete_Data);

        tabWidget_Operation->addTab(tab2_Plot, QString());

        gridLayout_2->addWidget(tabWidget_Operation, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        tabWidget_Operation->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Robot Interface", Q_NULLPTR));
        groupBox_Serial->setTitle(QApplication::translate("MainWindow", "Serial", Q_NULLPTR));
        label_Comport->setText(QApplication::translate("MainWindow", "COM:", Q_NULLPTR));
        label_Baudrate->setText(QApplication::translate("MainWindow", "Baudrate:", Q_NULLPTR));
        pushButton_Connect->setText(QApplication::translate("MainWindow", "CONNECT", Q_NULLPTR));
        label_connectStatus->setText(QApplication::translate("MainWindow", "Disconnected", Q_NULLPTR));
        groupBox_Information->setTitle(QApplication::translate("MainWindow", "Information", Q_NULLPTR));
        label_X_3->setText(QApplication::translate("MainWindow", "Theta1", Q_NULLPTR));
        label_Y_3->setText(QApplication::translate("MainWindow", "Theta2", Q_NULLPTR));
        label_Z_5->setText(QApplication::translate("MainWindow", "D3", Q_NULLPTR));
        label_Z_3->setText(QApplication::translate("MainWindow", "Theta4", Q_NULLPTR));
        label_X_2->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        label_Y_2->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        label_Z_2->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        label_Roll_2->setText(QApplication::translate("MainWindow", "ROLL", Q_NULLPTR));
        radioButton_Degree->setText(QApplication::translate("MainWindow", "Deg", Q_NULLPTR));
        radioButton_Radian->setText(QApplication::translate("MainWindow", "Rad", Q_NULLPTR));
        groupBox_Logs->setTitle(QApplication::translate("MainWindow", "History Logs", Q_NULLPTR));
        pushButton_LogsClear->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        groupBox_Command->setTitle(QApplication::translate("MainWindow", "Command", Q_NULLPTR));
        groupBox_Input->setTitle(QApplication::translate("MainWindow", "Input Parameters", Q_NULLPTR));
        groupBox_Output->setTitle(QApplication::translate("MainWindow", "Output", Q_NULLPTR));
        label_Output->setText(QApplication::translate("MainWindow", "OUTPUT", Q_NULLPTR));
        checkBox_Output->setText(QApplication::translate("MainWindow", "ON/OFF", Q_NULLPTR));
        groupBox_Rotate->setTitle(QApplication::translate("MainWindow", "Rotate", Q_NULLPTR));
        label_Rotate->setText(QApplication::translate("MainWindow", "ROTATE", Q_NULLPTR));
        label_Target_Joint->setText(QApplication::translate("MainWindow", "Joint(0,1,2,3)", Q_NULLPTR));
        label_Target_Angle->setText(QApplication::translate("MainWindow", "Angle(deg,mm)", Q_NULLPTR));
        groupBox_Circle->setTitle(QApplication::translate("MainWindow", "Move Circle", Q_NULLPTR));
        label_CENTER->setText(QApplication::translate("MainWindow", "CENTER", Q_NULLPTR));
        label_Center_X->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        label_Center_Y->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        label_Center_Z->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        radioButton_Dir_counter->setText(QApplication::translate("MainWindow", "DIR +", Q_NULLPTR));
        radioButton_Dir_noncounter->setText(QApplication::translate("MainWindow", "DIR -", Q_NULLPTR));
        groupBox_Move->setTitle(QApplication::translate("MainWindow", "Move", Q_NULLPTR));
        label_Target->setText(QApplication::translate("MainWindow", "TARGET", Q_NULLPTR));
        label_Target_X->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        label_Target_Y->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        label_Target_Z->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        label_Roll->setText(QApplication::translate("MainWindow", "ROLL", Q_NULLPTR));
        groupBox_Trajectory->setTitle(QApplication::translate("MainWindow", "Trajectory", Q_NULLPTR));
        radioButton_LSPB->setText(QApplication::translate("MainWindow", "LSPB", Q_NULLPTR));
        radioButton_Scurve->setText(QApplication::translate("MainWindow", "S-CURVE", Q_NULLPTR));
        groupBox_Coordinate->setTitle(QApplication::translate("MainWindow", "Coordinate", Q_NULLPTR));
        radioButton_Absolute->setText(QApplication::translate("MainWindow", "ABSOLUTE", Q_NULLPTR));
        radioButton_Relative->setText(QApplication::translate("MainWindow", "RELATIVE", Q_NULLPTR));
        groupBox_Circle_2->setTitle(QApplication::translate("MainWindow", "Limit", Q_NULLPTR));
        label_Velocity->setText(QApplication::translate("MainWindow", "Velocity", Q_NULLPTR));
        label_Accelerate->setText(QApplication::translate("MainWindow", "Accelarate", Q_NULLPTR));
        label_Total_Time->setText(QApplication::translate("MainWindow", "Total Time", Q_NULLPTR));
        radioButton_QVA->setText(QApplication::translate("MainWindow", "QVA", Q_NULLPTR));
        radioButton_QVT->setText(QApplication::translate("MainWindow", "QVT", Q_NULLPTR));
        pushButton_Change_Limit->setText(QApplication::translate("MainWindow", "Change", Q_NULLPTR));
        radioButton_Stop->setText(QApplication::translate("MainWindow", "STOP", Q_NULLPTR));
        radioButton_Scan->setText(QApplication::translate("MainWindow", "SCAN LIMIT", Q_NULLPTR));
        radioButton_MoveHome->setText(QApplication::translate("MainWindow", "MOVE HOME", Q_NULLPTR));
        radioButton_MoveLine->setText(QApplication::translate("MainWindow", "MOVE LINE", Q_NULLPTR));
        radioButton_MoveCircle->setText(QApplication::translate("MainWindow", "MOVE CIRCLE", Q_NULLPTR));
        radioButton_MoveJoint->setText(QApplication::translate("MainWindow", "MOVE JOINT", Q_NULLPTR));
        radioButton_Rotate->setText(QApplication::translate("MainWindow", "ROTATE", Q_NULLPTR));
        radioButton_Output->setText(QApplication::translate("MainWindow", "OUTPUT", Q_NULLPTR));
        radioButton_ReadStatus->setText(QApplication::translate("MainWindow", "READ STATUS", Q_NULLPTR));
        radioButton_ReadPosition->setText(QApplication::translate("MainWindow", "READ POSITION", Q_NULLPTR));
        radioButton_Setting->setText(QApplication::translate("MainWindow", "SETTING", Q_NULLPTR));
        pushButton_Request->setText(QApplication::translate("MainWindow", "REQUEST", Q_NULLPTR));
        tabWidget_Operation->setTabText(tabWidget_Operation->indexOf(tab1_Control), QApplication::translate("MainWindow", "Robot Control", Q_NULLPTR));
        label_Chart1->setText(QApplication::translate("MainWindow", "Chart 1", Q_NULLPTR));
        label_Chart2->setText(QApplication::translate("MainWindow", "Chart 2", Q_NULLPTR));
        label_Chart3->setText(QApplication::translate("MainWindow", "Chart 3", Q_NULLPTR));
        label_Chart4->setText(QApplication::translate("MainWindow", "Chart 4", Q_NULLPTR));
        pushButton_Plot->setText(QApplication::translate("MainWindow", "Plot", Q_NULLPTR));
        pushButton_Delete_Data->setText(QApplication::translate("MainWindow", "Delete Data", Q_NULLPTR));
        tabWidget_Operation->setTabText(tabWidget_Operation->indexOf(tab2_Plot), QApplication::translate("MainWindow", "Plot", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
