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

#include "debug.hpp"
#include "robotcontroll.hpp"
#include "chart.hpp"
#include "chartview.hpp"


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


private:
    /* Serial */
    void    serial_init();
    void    serial_setDefault();
    void    serial_openPort();
    void    serial_closePort();
    void    logs_write(QString message, QColor c);
    /* Charts */
    void    chart_init();
    void    chart_addSeries();
    void    chart_removeSeries();
    void    chart_connectMarkers();
    void    chart_addData();
    /* UI */
    void    ui_initComboBox();
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
    // connect robot signal
    void    serial_logCommand(QByteArray command);
    void    serial_logRespond(QByteArray respond);
    void    serial_displayPosition(QByteArray respond);
    void    chart_start(QByteArray respond);
    void    chart_addPoint(QByteArray respond);
    void    chart_end(QByteArray respond);
    // connect chart signal
    void    chart_handleMarkerClicked();
    // Button clicked
    void    on_pushButton_Connect_clicked();
    /* Camera */

    /* Variable Declare */




    void on_pushButton_Delete_Plot_clicked();

private:
    Ui::MainWindow    *m_ui                       = nullptr;
    RobotControll        *m_robot               = nullptr;
    QLabel                       *m_status               = nullptr;
    QTimer                      *timer_serial_comboBox  = nullptr;

    QList<QLineSeries *> m_series;
    Chart                          *m_chart                        = nullptr;
    QTimer                      *m_timer                       = nullptr;
    int                                 tick;
};

#endif // MAINWINDOW_H
