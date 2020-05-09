#ifndef CHARTWINDOW_H
#define CHARTWINDOW_H

#include <QMainWindow>
#include <QtCharts/QValueAxis>
#include <QtCharts/QXYLegendMarker>
#include <QtCharts/QChartGlobal>
#include <QtCharts/QLegendMarker>
#include <QtCharts/QLineSeries>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QFormLayout>

#include "chart.hpp"
#include "chartview.hpp"

typedef QPair<int, int> VarPair;
typedef QList<VarPair> VarList;
typedef QList<QLineSeries*> LineList;
typedef QList<QChartView*> ChartViewList;

namespace Ui {
class ChartWindow;
}

class ChartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChartWindow(QWidget *parent = nullptr);
    ~ChartWindow();
    bool addChart(int x_var, int y_var, QString x_name, QString y_name );
    int addPoint(int chart_num, QVector<double> var_x, QVector<double> var_y);
    int addPoint(int chart_num, double x, double y);
    bool setRangeX(int chart_num, double min, double max);
    bool setRangeY(int chart_num, double min, double max);
    bool setRangeFit(int chart_num);
    VarList                             var_list;
private:
    QChart *createLineChart();

signals:
    void    figureClosed(ChartWindow *figure);
private slots:
    void    closeEvent (QCloseEvent *event);
private:
    Ui::ChartWindow *ui;
    int num_chart;
    LineList                            m_line;
    ChartViewList                m_chartview;
    QGridLayout                 *baseLayout = nullptr;
};

#endif // CHARTWINDOW_H
