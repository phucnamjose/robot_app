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
#include <QtGamepad/QGamepadManager>

#include "debug.hpp"
#include "robotcontroll.hpp"
#include "chartwindow.hpp"
#include "joysticks.hpp"


#define  ARRAY_DATA_SIZE        (6000)

//QT_BEGIN_NAMESPACE
//class QGamepad;
//QT_END_NAMESPACE


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

    /* UI */
    void    ui_init();
    void    logsWrite(QString message, QColor c);
    bool   joystick_init();
    void    joystick_event(bool pressed, Joysticks::joysticksFunction_t func);

private slots:
    // Plot
    void    plot_figureClosed(ChartWindow *figure);
    void    plot_timerFigure_handle();

    //Compute
    void    compute_init();
    void    compute_newData(double x,double y, double z, double roll,
                            double var0, double var1, double var2, double var3,
                            double lenght, double time_run, double time_total);

    // Serial
    void    serial_updatePortName();    // connect timeout timer check
    void    serial_updateSetting();    // connect current text change
    void    serial_logCommand(QByteArray command);    // connect robot signal
    void    serial_logRespond(QByteArray respond);
    void    serial_displayPosition();
    void    serial_workStart();
    void    serial_workRunning(double x,double y, double z, double roll,
                               double var0, double var1, double var2, double var3,
                               double lenght, double time_run, double time_total);
    void    serial_workEnd(double x,double y, double z, double roll,
                                double var0, double var1, double var2, double var3,
                                double lenght, double time_run, double time_total);

    // UI
    void    on_pushButton_startUpCommand();
    void    on_pushButton_Connect_Clicked();
    void    on_pushButton_Logs_Clear_Clicked();    // connect clear log button
    void    on_pushButton_Stop_clicked();  // connect stop button
    void    on_pushButton_Change_Limit_Clicked();    // connect change limit button
    void    on_pushButton_Request_Clicked();    // connect request button
    void    on_pushButton_Output_Clicked();    // connect output button
    void    on_pushButton_Delete_Data_Clicked();   // connect delete data button
    void    on_pushButton_Plot_Clicked();  // connect plot button
    void    on_checkBox_Collect_Data_toggled(bool checked);
    void    closeEvent (QCloseEvent *event);
    void    keyboardPressHandle();
    void    keyboardReleaseHandle();
    void    keyboardTimerHandle();
    /* --------------Variable Define--------------- */
private:
    // Plot
    QList<QComboBox *> m_x_axis;
    QList<QComboBox *> m_y_axis;
    double pre_time_total;
    double pre_lenght;
    int   num_chartwindow;
    QList<ChartWindow *> m_figure;
    int  num_sample_plot;
    QTimer                       *timer_update_figure      = nullptr;

    // Compute
    bool collect_data = false;
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
     QTimer                       *timer_update_display      = nullptr;

    // Serial
     QString                     comportName;
    RobotControll        *m_robot                = nullptr;
    QTimer                      *timer_update_comport      = nullptr;
    bool                            is_cartesian             = true;
    int                                 joysticks_speed    = 1;

    // UI
    Ui::MainWindow    *m_ui                        = nullptr;
    QLabel                       *m_status               = nullptr;
    QTimer                      *timer_keyboard = nullptr;
    Joysticks                  *joystick                   = nullptr;
    bool                            joysticks_identify = false;
    RobotControll::robotKeyBoard_t      key_robot;
};

#endif // MAINWINDOW_H
