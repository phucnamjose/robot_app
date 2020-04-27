#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
#include <QMessageBox>
#include <QSerialPortInfo>
#include <QTimer>
#include <QSlider>


#include "debug.hpp"
#include "robotcontroll.hpp"

#define     PI      (3.14159265f)

using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    /* Function Declare */
    /* Widget */
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void    closeEvent (QCloseEvent *event);

    /* Serial */
private:
    void    serial_init();
    void    serial_setDefault();
    void    serial_openPort();
    void    serial_closePort();
    void    logs_write(QString message, QColor c);

private slots:
    // connect timeout timer check
    void    serial_updatePortName();
    // connect current text change
    void    serial_updateSetting();
    // connect error handle
    void    serial_handleError(QSerialPort::SerialPortError error);
    // connect clear log button
    void    logs_clear();
    // connect change limit button
    void    manual_changeLimit();
    // connect request button
    void    manual_checkPara_setCommand();
    void    serial_logCommand(QByteArray command);
    void    serial_logRespond(QByteArray respond);
    // Button clicked
    void    on_pushButton_Connect_clicked();
    /* Camera */

    /* Variable Declare */




private:
    Ui::MainWindow    *m_ui                       = nullptr;
    RobotControll        *m_robot               = nullptr;
    QLabel                       *m_status               = nullptr;
    QTimer                      *timer_serial_comboBox  = nullptr;
};

#endif // MAINWINDOW_H
