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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
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
    QTabWidget *tabWidget_Operation;
    QWidget *tab1_Control;
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
    QGroupBox *groupBox_Robot_Status;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_XYZ_current;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_X_2;
    QTextEdit *textEdit_X_current;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_Y_2;
    QTextEdit *textEdit_Y_current;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_Z_2;
    QTextEdit *textEdit_Z_current;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_Joint_var;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_X_3;
    QTextEdit *textEdit_X_Theta1;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_Y_3;
    QTextEdit *textEdit_Theta2;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_Z_5;
    QTextEdit *textEdit_Z_D3;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_Z_3;
    QTextEdit *textEdit_Theta4;
    QGroupBox *groupBox_Command;
    QGroupBox *groupBox_Input_Parameters;
    QCheckBox *checkBox_Output;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_XYZ_target;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_X;
    QTextEdit *textEdit_X_target;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_Y;
    QTextEdit *textEdit_Y_target;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_Z;
    QTextEdit *textEdit_Z_target;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_Rotate;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_Joint;
    QTextEdit *textEdit_Joint_target;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_Algle;
    QTextEdit *textEdit_Angle_target;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_command;
    QRadioButton *radioButton_MoveHome;
    QRadioButton *radioButton_MoveLine;
    QRadioButton *radioButton_MoveCircle;
    QRadioButton *radioButton_MoveJoint;
    QRadioButton *radioButton_Rotate;
    QRadioButton *radioButton_Output;
    QRadioButton *radioButton_ReadStatus;
    QRadioButton *radioButton_MoveHome_2;
    QPushButton *pushButton_Request;
    QWidget *tab2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1027, 755);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget_Operation = new QTabWidget(centralWidget);
        tabWidget_Operation->setObjectName(QStringLiteral("tabWidget_Operation"));
        tabWidget_Operation->setGeometry(QRect(10, 20, 1011, 701));
        tab1_Control = new QWidget();
        tab1_Control->setObjectName(QStringLiteral("tab1_Control"));
        groupBox_Serial = new QGroupBox(tab1_Control);
        groupBox_Serial->setObjectName(QStringLiteral("groupBox_Serial"));
        groupBox_Serial->setGeometry(QRect(20, 0, 181, 131));
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

        groupBox_Logs = new QGroupBox(tab1_Control);
        groupBox_Logs->setObjectName(QStringLiteral("groupBox_Logs"));
        groupBox_Logs->setGeometry(QRect(569, 0, 431, 611));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_Logs->sizePolicy().hasHeightForWidth());
        groupBox_Logs->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(groupBox_Logs);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        scrollArea = new QScrollArea(groupBox_Logs);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 409, 545));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        textEdit_Logs = new QTextEdit(scrollAreaWidgetContents);
        textEdit_Logs->setObjectName(QStringLiteral("textEdit_Logs"));
        sizePolicy.setHeightForWidth(textEdit_Logs->sizePolicy().hasHeightForWidth());
        textEdit_Logs->setSizePolicy(sizePolicy);
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

        groupBox_Robot_Status = new QGroupBox(tab1_Control);
        groupBox_Robot_Status->setObjectName(QStringLiteral("groupBox_Robot_Status"));
        groupBox_Robot_Status->setGeometry(QRect(10, 500, 541, 161));
        layoutWidget_2 = new QWidget(groupBox_Robot_Status);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 20, 231, 55));
        horizontalLayout_XYZ_current = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_XYZ_current->setSpacing(6);
        horizontalLayout_XYZ_current->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_XYZ_current->setObjectName(QStringLiteral("horizontalLayout_XYZ_current"));
        horizontalLayout_XYZ_current->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_XYZ_current->setContentsMargins(0, 0, 0, 0);
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label_X_2 = new QLabel(layoutWidget_2);
        label_X_2->setObjectName(QStringLiteral("label_X_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_X_2->sizePolicy().hasHeightForWidth());
        label_X_2->setSizePolicy(sizePolicy1);
        label_X_2->setMaximumSize(QSize(70, 20));

        verticalLayout_10->addWidget(label_X_2);

        textEdit_X_current = new QTextEdit(layoutWidget_2);
        textEdit_X_current->setObjectName(QStringLiteral("textEdit_X_current"));
        sizePolicy1.setHeightForWidth(textEdit_X_current->sizePolicy().hasHeightForWidth());
        textEdit_X_current->setSizePolicy(sizePolicy1);
        textEdit_X_current->setMaximumSize(QSize(70, 32));

        verticalLayout_10->addWidget(textEdit_X_current);


        horizontalLayout_XYZ_current->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        label_Y_2 = new QLabel(layoutWidget_2);
        label_Y_2->setObjectName(QStringLiteral("label_Y_2"));
        sizePolicy1.setHeightForWidth(label_Y_2->sizePolicy().hasHeightForWidth());
        label_Y_2->setSizePolicy(sizePolicy1);
        label_Y_2->setMaximumSize(QSize(70, 20));

        verticalLayout_11->addWidget(label_Y_2);

        textEdit_Y_current = new QTextEdit(layoutWidget_2);
        textEdit_Y_current->setObjectName(QStringLiteral("textEdit_Y_current"));
        sizePolicy1.setHeightForWidth(textEdit_Y_current->sizePolicy().hasHeightForWidth());
        textEdit_Y_current->setSizePolicy(sizePolicy1);
        textEdit_Y_current->setMaximumSize(QSize(70, 32));

        verticalLayout_11->addWidget(textEdit_Y_current);


        horizontalLayout_XYZ_current->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        label_Z_2 = new QLabel(layoutWidget_2);
        label_Z_2->setObjectName(QStringLiteral("label_Z_2"));
        sizePolicy1.setHeightForWidth(label_Z_2->sizePolicy().hasHeightForWidth());
        label_Z_2->setSizePolicy(sizePolicy1);
        label_Z_2->setMaximumSize(QSize(70, 20));

        verticalLayout_12->addWidget(label_Z_2);

        textEdit_Z_current = new QTextEdit(layoutWidget_2);
        textEdit_Z_current->setObjectName(QStringLiteral("textEdit_Z_current"));
        sizePolicy1.setHeightForWidth(textEdit_Z_current->sizePolicy().hasHeightForWidth());
        textEdit_Z_current->setSizePolicy(sizePolicy1);
        textEdit_Z_current->setMaximumSize(QSize(70, 32));

        verticalLayout_12->addWidget(textEdit_Z_current);


        horizontalLayout_XYZ_current->addLayout(verticalLayout_12);

        layoutWidget_3 = new QWidget(groupBox_Robot_Status);
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
        sizePolicy1.setHeightForWidth(label_X_3->sizePolicy().hasHeightForWidth());
        label_X_3->setSizePolicy(sizePolicy1);
        label_X_3->setMaximumSize(QSize(70, 20));

        verticalLayout_13->addWidget(label_X_3);

        textEdit_X_Theta1 = new QTextEdit(layoutWidget_3);
        textEdit_X_Theta1->setObjectName(QStringLiteral("textEdit_X_Theta1"));
        sizePolicy1.setHeightForWidth(textEdit_X_Theta1->sizePolicy().hasHeightForWidth());
        textEdit_X_Theta1->setSizePolicy(sizePolicy1);
        textEdit_X_Theta1->setMaximumSize(QSize(70, 32));

        verticalLayout_13->addWidget(textEdit_X_Theta1);


        horizontalLayout_Joint_var->addLayout(verticalLayout_13);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        label_Y_3 = new QLabel(layoutWidget_3);
        label_Y_3->setObjectName(QStringLiteral("label_Y_3"));
        sizePolicy1.setHeightForWidth(label_Y_3->sizePolicy().hasHeightForWidth());
        label_Y_3->setSizePolicy(sizePolicy1);
        label_Y_3->setMaximumSize(QSize(70, 20));

        verticalLayout_14->addWidget(label_Y_3);

        textEdit_Theta2 = new QTextEdit(layoutWidget_3);
        textEdit_Theta2->setObjectName(QStringLiteral("textEdit_Theta2"));
        sizePolicy1.setHeightForWidth(textEdit_Theta2->sizePolicy().hasHeightForWidth());
        textEdit_Theta2->setSizePolicy(sizePolicy1);
        textEdit_Theta2->setMaximumSize(QSize(70, 32));

        verticalLayout_14->addWidget(textEdit_Theta2);


        horizontalLayout_Joint_var->addLayout(verticalLayout_14);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        label_Z_5 = new QLabel(layoutWidget_3);
        label_Z_5->setObjectName(QStringLiteral("label_Z_5"));
        sizePolicy1.setHeightForWidth(label_Z_5->sizePolicy().hasHeightForWidth());
        label_Z_5->setSizePolicy(sizePolicy1);
        label_Z_5->setMaximumSize(QSize(70, 20));

        verticalLayout_17->addWidget(label_Z_5);

        textEdit_Z_D3 = new QTextEdit(layoutWidget_3);
        textEdit_Z_D3->setObjectName(QStringLiteral("textEdit_Z_D3"));
        sizePolicy1.setHeightForWidth(textEdit_Z_D3->sizePolicy().hasHeightForWidth());
        textEdit_Z_D3->setSizePolicy(sizePolicy1);
        textEdit_Z_D3->setMaximumSize(QSize(70, 32));

        verticalLayout_17->addWidget(textEdit_Z_D3);


        horizontalLayout_Joint_var->addLayout(verticalLayout_17);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        label_Z_3 = new QLabel(layoutWidget_3);
        label_Z_3->setObjectName(QStringLiteral("label_Z_3"));
        sizePolicy1.setHeightForWidth(label_Z_3->sizePolicy().hasHeightForWidth());
        label_Z_3->setSizePolicy(sizePolicy1);
        label_Z_3->setMaximumSize(QSize(70, 20));

        verticalLayout_15->addWidget(label_Z_3);

        textEdit_Theta4 = new QTextEdit(layoutWidget_3);
        textEdit_Theta4->setObjectName(QStringLiteral("textEdit_Theta4"));
        sizePolicy1.setHeightForWidth(textEdit_Theta4->sizePolicy().hasHeightForWidth());
        textEdit_Theta4->setSizePolicy(sizePolicy1);
        textEdit_Theta4->setMaximumSize(QSize(70, 32));

        verticalLayout_15->addWidget(textEdit_Theta4);


        horizontalLayout_Joint_var->addLayout(verticalLayout_15);

        groupBox_Command = new QGroupBox(tab1_Control);
        groupBox_Command->setObjectName(QStringLiteral("groupBox_Command"));
        groupBox_Command->setGeometry(QRect(20, 140, 541, 351));
        groupBox_Input_Parameters = new QGroupBox(groupBox_Command);
        groupBox_Input_Parameters->setObjectName(QStringLiteral("groupBox_Input_Parameters"));
        groupBox_Input_Parameters->setGeometry(QRect(130, 19, 391, 311));
        checkBox_Output = new QCheckBox(groupBox_Input_Parameters);
        checkBox_Output->setObjectName(QStringLiteral("checkBox_Output"));
        checkBox_Output->setGeometry(QRect(10, 170, 101, 21));
        layoutWidget = new QWidget(groupBox_Input_Parameters);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 231, 55));
        horizontalLayout_XYZ_target = new QHBoxLayout(layoutWidget);
        horizontalLayout_XYZ_target->setSpacing(6);
        horizontalLayout_XYZ_target->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_XYZ_target->setObjectName(QStringLiteral("horizontalLayout_XYZ_target"));
        horizontalLayout_XYZ_target->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_XYZ_target->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_X = new QLabel(layoutWidget);
        label_X->setObjectName(QStringLiteral("label_X"));
        sizePolicy1.setHeightForWidth(label_X->sizePolicy().hasHeightForWidth());
        label_X->setSizePolicy(sizePolicy1);
        label_X->setMaximumSize(QSize(70, 20));

        verticalLayout_5->addWidget(label_X);

        textEdit_X_target = new QTextEdit(layoutWidget);
        textEdit_X_target->setObjectName(QStringLiteral("textEdit_X_target"));
        sizePolicy1.setHeightForWidth(textEdit_X_target->sizePolicy().hasHeightForWidth());
        textEdit_X_target->setSizePolicy(sizePolicy1);
        textEdit_X_target->setMaximumSize(QSize(70, 32));

        verticalLayout_5->addWidget(textEdit_X_target);


        horizontalLayout_XYZ_target->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_Y = new QLabel(layoutWidget);
        label_Y->setObjectName(QStringLiteral("label_Y"));
        sizePolicy1.setHeightForWidth(label_Y->sizePolicy().hasHeightForWidth());
        label_Y->setSizePolicy(sizePolicy1);
        label_Y->setMaximumSize(QSize(70, 20));

        verticalLayout_6->addWidget(label_Y);

        textEdit_Y_target = new QTextEdit(layoutWidget);
        textEdit_Y_target->setObjectName(QStringLiteral("textEdit_Y_target"));
        sizePolicy1.setHeightForWidth(textEdit_Y_target->sizePolicy().hasHeightForWidth());
        textEdit_Y_target->setSizePolicy(sizePolicy1);
        textEdit_Y_target->setMaximumSize(QSize(70, 32));

        verticalLayout_6->addWidget(textEdit_Y_target);


        horizontalLayout_XYZ_target->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_Z = new QLabel(layoutWidget);
        label_Z->setObjectName(QStringLiteral("label_Z"));
        sizePolicy1.setHeightForWidth(label_Z->sizePolicy().hasHeightForWidth());
        label_Z->setSizePolicy(sizePolicy1);
        label_Z->setMaximumSize(QSize(70, 20));

        verticalLayout_7->addWidget(label_Z);

        textEdit_Z_target = new QTextEdit(layoutWidget);
        textEdit_Z_target->setObjectName(QStringLiteral("textEdit_Z_target"));
        sizePolicy1.setHeightForWidth(textEdit_Z_target->sizePolicy().hasHeightForWidth());
        textEdit_Z_target->setSizePolicy(sizePolicy1);
        textEdit_Z_target->setMaximumSize(QSize(70, 32));

        verticalLayout_7->addWidget(textEdit_Z_target);


        horizontalLayout_XYZ_target->addLayout(verticalLayout_7);

        layoutWidget1 = new QWidget(groupBox_Input_Parameters);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 110, 152, 55));
        horizontalLayout_Rotate = new QHBoxLayout(layoutWidget1);
        horizontalLayout_Rotate->setSpacing(6);
        horizontalLayout_Rotate->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_Rotate->setObjectName(QStringLiteral("horizontalLayout_Rotate"));
        horizontalLayout_Rotate->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_Rotate->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_Joint = new QLabel(layoutWidget1);
        label_Joint->setObjectName(QStringLiteral("label_Joint"));
        sizePolicy1.setHeightForWidth(label_Joint->sizePolicy().hasHeightForWidth());
        label_Joint->setSizePolicy(sizePolicy1);
        label_Joint->setMaximumSize(QSize(70, 20));

        verticalLayout_8->addWidget(label_Joint);

        textEdit_Joint_target = new QTextEdit(layoutWidget1);
        textEdit_Joint_target->setObjectName(QStringLiteral("textEdit_Joint_target"));
        sizePolicy1.setHeightForWidth(textEdit_Joint_target->sizePolicy().hasHeightForWidth());
        textEdit_Joint_target->setSizePolicy(sizePolicy1);
        textEdit_Joint_target->setMaximumSize(QSize(70, 32));

        verticalLayout_8->addWidget(textEdit_Joint_target);


        horizontalLayout_Rotate->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_Algle = new QLabel(layoutWidget1);
        label_Algle->setObjectName(QStringLiteral("label_Algle"));
        sizePolicy1.setHeightForWidth(label_Algle->sizePolicy().hasHeightForWidth());
        label_Algle->setSizePolicy(sizePolicy1);
        label_Algle->setMaximumSize(QSize(70, 20));

        verticalLayout_9->addWidget(label_Algle);

        textEdit_Angle_target = new QTextEdit(layoutWidget1);
        textEdit_Angle_target->setObjectName(QStringLiteral("textEdit_Angle_target"));
        sizePolicy1.setHeightForWidth(textEdit_Angle_target->sizePolicy().hasHeightForWidth());
        textEdit_Angle_target->setSizePolicy(sizePolicy1);
        textEdit_Angle_target->setMaximumSize(QSize(70, 32));

        verticalLayout_9->addWidget(textEdit_Angle_target);


        horizontalLayout_Rotate->addLayout(verticalLayout_9);

        layoutWidget2 = new QWidget(groupBox_Command);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 20, 121, 311));
        verticalLayout_command = new QVBoxLayout(layoutWidget2);
        verticalLayout_command->setSpacing(6);
        verticalLayout_command->setContentsMargins(11, 11, 11, 11);
        verticalLayout_command->setObjectName(QStringLiteral("verticalLayout_command"));
        verticalLayout_command->setContentsMargins(0, 0, 0, 0);
        radioButton_MoveHome = new QRadioButton(layoutWidget2);
        radioButton_MoveHome->setObjectName(QStringLiteral("radioButton_MoveHome"));

        verticalLayout_command->addWidget(radioButton_MoveHome);

        radioButton_MoveLine = new QRadioButton(layoutWidget2);
        radioButton_MoveLine->setObjectName(QStringLiteral("radioButton_MoveLine"));

        verticalLayout_command->addWidget(radioButton_MoveLine);

        radioButton_MoveCircle = new QRadioButton(layoutWidget2);
        radioButton_MoveCircle->setObjectName(QStringLiteral("radioButton_MoveCircle"));

        verticalLayout_command->addWidget(radioButton_MoveCircle);

        radioButton_MoveJoint = new QRadioButton(layoutWidget2);
        radioButton_MoveJoint->setObjectName(QStringLiteral("radioButton_MoveJoint"));

        verticalLayout_command->addWidget(radioButton_MoveJoint);

        radioButton_Rotate = new QRadioButton(layoutWidget2);
        radioButton_Rotate->setObjectName(QStringLiteral("radioButton_Rotate"));

        verticalLayout_command->addWidget(radioButton_Rotate);

        radioButton_Output = new QRadioButton(layoutWidget2);
        radioButton_Output->setObjectName(QStringLiteral("radioButton_Output"));

        verticalLayout_command->addWidget(radioButton_Output);

        radioButton_ReadStatus = new QRadioButton(layoutWidget2);
        radioButton_ReadStatus->setObjectName(QStringLiteral("radioButton_ReadStatus"));

        verticalLayout_command->addWidget(radioButton_ReadStatus);

        radioButton_MoveHome_2 = new QRadioButton(layoutWidget2);
        radioButton_MoveHome_2->setObjectName(QStringLiteral("radioButton_MoveHome_2"));

        verticalLayout_command->addWidget(radioButton_MoveHome_2);

        pushButton_Request = new QPushButton(layoutWidget2);
        pushButton_Request->setObjectName(QStringLiteral("pushButton_Request"));

        verticalLayout_command->addWidget(pushButton_Request);

        tabWidget_Operation->addTab(tab1_Control, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QStringLiteral("tab2"));
        tabWidget_Operation->addTab(tab2, QString());
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QFont font2;
        font2.setFamily(QStringLiteral("SansSerif"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        statusBar->setFont(font2);
        MainWindow->setStatusBar(statusBar);

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
        pushButton_Connect->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        label_connectStatus->setText(QApplication::translate("MainWindow", "Disconnected", Q_NULLPTR));
        groupBox_Logs->setTitle(QApplication::translate("MainWindow", "Logs", Q_NULLPTR));
        pushButton_LogsClear->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        groupBox_Robot_Status->setTitle(QApplication::translate("MainWindow", "Robot Status", Q_NULLPTR));
        label_X_2->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        label_Y_2->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        label_Z_2->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        label_X_3->setText(QApplication::translate("MainWindow", "Theta1", Q_NULLPTR));
        label_Y_3->setText(QApplication::translate("MainWindow", "Theta2", Q_NULLPTR));
        label_Z_5->setText(QApplication::translate("MainWindow", "D3", Q_NULLPTR));
        label_Z_3->setText(QApplication::translate("MainWindow", "Theta4", Q_NULLPTR));
        groupBox_Command->setTitle(QApplication::translate("MainWindow", "Command", Q_NULLPTR));
        groupBox_Input_Parameters->setTitle(QApplication::translate("MainWindow", "Input Parameters", Q_NULLPTR));
        checkBox_Output->setText(QApplication::translate("MainWindow", "ON/OFF Output", Q_NULLPTR));
        label_X->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        label_Y->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        label_Z->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        label_Joint->setText(QApplication::translate("MainWindow", "Joint(0,1,2,3)", Q_NULLPTR));
        label_Algle->setText(QApplication::translate("MainWindow", "Angle(deg)", Q_NULLPTR));
        radioButton_MoveHome->setText(QApplication::translate("MainWindow", "Move Home", Q_NULLPTR));
        radioButton_MoveLine->setText(QApplication::translate("MainWindow", "Move Line", Q_NULLPTR));
        radioButton_MoveCircle->setText(QApplication::translate("MainWindow", "Move Circle", Q_NULLPTR));
        radioButton_MoveJoint->setText(QApplication::translate("MainWindow", "Move Joint", Q_NULLPTR));
        radioButton_Rotate->setText(QApplication::translate("MainWindow", "Rotate Single Joint", Q_NULLPTR));
        radioButton_Output->setText(QApplication::translate("MainWindow", "Output", Q_NULLPTR));
        radioButton_ReadStatus->setText(QApplication::translate("MainWindow", "Read  Status", Q_NULLPTR));
        radioButton_MoveHome_2->setText(QApplication::translate("MainWindow", "Setting", Q_NULLPTR));
        pushButton_Request->setText(QApplication::translate("MainWindow", "Request", Q_NULLPTR));
        tabWidget_Operation->setTabText(tabWidget_Operation->indexOf(tab1_Control), QApplication::translate("MainWindow", "Robot Control", Q_NULLPTR));
        tabWidget_Operation->setTabText(tabWidget_Operation->indexOf(tab2), QApplication::translate("MainWindow", "Reserve", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
