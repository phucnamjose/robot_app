#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QCloseEvent>
#include <QMessageBox>
#include <QSerialPortInfo>
#include <QTimer>
#include <QSlider>
#include<QtCharts>
#include<QChartView>
#include<QLineSeries>
#include <QtCore/QtMath>
#include <QtCharts/QValueAxis>
#include <QtCharts/QXYLegendMarker>
#include <QtCharts/QLegendMarker>
#include <QVector>

#include "debug.hpp"
#include "robotcontroll.hpp"
#include "chart.hpp"
#include "chartview.hpp"
#include "chartwindow.hpp"


#define  ARRAY_DATA_SIZE        (6000)

using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    /*------------------ Function Define----------------- */
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    /* Plot */
    void    plot_init();
    void    plot_initComboBox();
    /* Compute */

    /* Serial */
    void    serial_init();
    void    serial_initComboBox();
    void    serial_setDefault();
    void    serial_openPort();
    void    serial_closePort();
    void    logs_write(QString message, QColor c);
    void    serial_Connect_Clicked();
    /* UI */

private slots:
    // Plot
    void    plot_figureClosed(ChartWindow *figure);
    void    plot_Plot_Clicked();
    //Compute
    void    compute_init();
    void    compute_newData();
    void    compute_Delete_Data_Clicked();   // connect delete Data button
    // Serial
    void    serial_updatePortName();    // connect timeout timer check
    void    serial_updateSetting();    // connect current text change
    void    serial_handleError(QSerialPort::SerialPortError error);    // connect error handle
    void    serial_logCommand(QByteArray command);    // connect robot signal
    void    serial_logRespond(QByteArray respond);
    void    serial_displayPosition();
    void    serial_Change_Limit_Clicked();    // connect change limit button
    void    serial_Request_Clicked();    // connect request button
    void    serial_workStart(QByteArray respond);
    void    serial_workRunning();
    void    serial_workEnd(QByteArray respond);
    // UI
    void    ui_init();
    void    logs_Clear_Clicked();    // connect clear log button
    void    closeEvent (QCloseEvent *event);


    /* --------------Variable Define--------------- */
private:
    // Plot
    QList<QComboBox *> m_x_axis;
    QList<QComboBox *> m_y_axis;
    double pre_time_total;
    double pre_lenght;
    int   num_chartwindow;
    QList<ChartWindow *> m_figure;
    // Compute
    int  num_sample;
    QList<QVector<double>*> vec_list;
    QVector<double> vec_time;
    QVector<double> vec_pos[9];
    QVector<double> vec_vel[9];
    QVector<double> vec_acc[9];
    double time_pre;
    double pos_pre[9];
    double vel_pre[9];
    double acc_pre[9];
    // Serial
    RobotControll        *m_robot               = nullptr;
    QTimer                      *timer_update      = nullptr;
    // UI
    Ui::MainWindow    *m_ui                       = nullptr; 
    QLabel                       *m_status               = nullptr;
};

#endif // MAINWINDOW_H
