#include "chartwindow.hpp"
#include "ui_chartwindow.h"
#include <QDebug>

ChartWindow::ChartWindow(QWidget *parent) :
    QMainWindow(parent),
    num_chart(0),
    ui(new Ui::ChartWindow)
{
    ui->setupUi(this);
    baseLayout = new QGridLayout();
    ui->centralwidget->setLayout(baseLayout);

}

ChartWindow::~ChartWindow()
{
     //Restore
    // ChartView include : chart, series that added to chart
    for(QChartView *chartview : m_chartview) {
        delete chartview;
    }
    delete baseLayout;
    delete ui;
}

bool ChartWindow::addChart(int x_var, int y_var, QString x_name, QString y_name ) {
    QChart *chart = new QChart();
    QLineSeries *series = new QLineSeries(chart);
    series->clear();
    chart->addSeries(series);
    chart->legend()->hide();
    m_line.append(series);

    QValueAxis *axisX = new QValueAxis;
     axisX->setLabelFormat("%0.4f");
     axisX->setTitleText(x_name);
     axisX->setRange(-1,1);

     QValueAxis *axisY = new QValueAxis;
     axisY->setLabelFormat("%0.4f");
     axisY->setTitleText(y_name);
     axisY->setRange(-1,1);

     if ( x_var == 0) {
        axisX->setTickCount(11);
     } else if (x_var == 6) {
        axisX->setTickCount(5);
        axisY->setTickCount(5);
     }

     // Add X axis
     chart->addAxis(axisX, Qt::AlignBottom);
     if(!series->attachAxis(axisX)) {
         qDebug() << "Error attach Axis X \n";
     }
     // Add Y axis
     chart->addAxis(axisY, Qt::AlignLeft);
     if(!series->attachAxis(axisY)) {
         qDebug() << "Error attach Axis Y \n";
     }

    QChartView *chartView;
    chartView = new QChartView(chart);
    baseLayout->addWidget(chartView, num_chart , 0);
    m_chartview.append(chartView);
    var_list.append(qMakePair(x_var, y_var));
    chartView->setRenderHint(QPainter::Antialiasing);
    num_chart++;

    //chartView->chart()->setTheme(QChart::ChartThemeBlueCerulean);

    return true;
}

int ChartWindow::addPoint(int chart_num, QVector<double> var_x, QVector<double> var_y) {
    if( 0 <= chart_num  && chart_num < m_chartview.size()) {
        if(var_x.size() == var_y.size()) {
            int i;
            for(i = 0; i < var_x.size(); ++i) {
                m_line.at(chart_num)->append(var_x[i], var_y[i]);
            }
            return i;
        } else {
            qDebug() << "Error 2 vector is not equal lenght \n";
            return 0;
        }
    } else {
        qDebug() << "Error Chartnum \n";
        return 0;
    }
}

int ChartWindow::addPoint(int chart_num, double x, double y) {
    if( 0 <= chart_num  && chart_num < m_line.size()) {
        m_line.at(chart_num)->append(x, y);
        return 1;
    } else {
        qDebug() << "Error Chartnum \n";
        return 0;
    }
}

bool ChartWindow::setRangeX(int chart_num, double min, double max) {
    if( 0 <= chart_num  && chart_num < m_chartview.size()) {
        m_chartview.at(chart_num)->chart()->axisX()->setRange(min , max);
        return true;
    } else {
        return false;
    }
}

bool ChartWindow::setRangeY(int chart_num, double min, double max) {
    if( 0 <= chart_num  && chart_num < m_chartview.size()) {
        m_chartview.at(chart_num)->chart()->axisY()->setRange(min , max);
        return true;
    } else {
        return false;
    }
}

bool ChartWindow::setRangeFit(int chart_num) {
    if( 0 <= chart_num  && chart_num < m_chartview.size()) {
        double x_min, y_min, x_max, y_max;
        QLineSeries *series = m_line.at(chart_num);
        // Check series is Empty
        if (series->count() > 0) {
            x_min = series->at(0).x();
            y_min = series->at(0).y();
            x_max = series->at(0).x();
            y_max = series->at(0).y();
            // Find Max Min
            for (int i = 1; i < series->count(); ++i) {
                if( x_min > series->at(i).x()) {
                    x_min = series->at(i).x();
                }
                if( y_min > series->at(i).y()) {
                    y_min = series->at(i).y();
                }
                if( x_max < series->at(i).x()) {
                    x_max = series->at(i).x();
                }
                if( y_max < series->at(i).y()) {
                    y_max = series->at(i).y();
                }
            }   
            // Ajust
            double range_x = x_max - x_min;
            double range_y = y_max - y_min;
            double x_center = (x_min + x_max) / 2;
            double y_center = (y_min + y_max) / 2;
            range_x *= 1.1;// add 10%
            range_y *= 1.1;
            if (range_x < 0.0000001) {
                x_max = x_max + 0.05;
                x_min = x_min - 0.05;
                range_x = 0.1;
            } else {
                x_min = x_center - range_x/2;
                x_max = x_center + range_x/2;
            }
            if (range_y < 0.0000001) {
                y_max = y_max + 0.05;
                y_min = y_min - 0.05;
                range_y = 0.1;
            } else {
                y_max = y_center + range_y/2;
                y_min = y_center - range_y/2;
            }
            // If chart XY
            if (var_list.at(chart_num).first == 6) {
                if (range_x > range_y) {
                    y_min = y_center  - range_x / 2;
                    y_max = y_center + range_x / 2;
                } else {
                    x_min = x_center - range_y / 2;
                    x_max = x_center + range_y / 2;
                }
           }
           setRangeX(chart_num, x_min, x_max);
           setRangeY(chart_num, y_min, y_max);
        }
        return true;
    } else {
        return false;
    }
}

void ChartWindow::closeEvent(QCloseEvent *event)
{
    event->accept();
    // Deny Plot
    emit figureClosed(this);
    delete this;
}
