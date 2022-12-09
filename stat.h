#ifndef STAT_H
#define STAT_H

#include <QDialog>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QDialog>
#include <QtCharts/QChartView>
#include <QMainWindow>

QT_CHARTS_USE_NAMESPACE

namespace Ui
{
class STAT;
}

class STAT: public QDialog
{
    Q_OBJECT

public:
    explicit STAT(QWidget *parent = nullptr);
    ~STAT();

    QChartView *chartView ;
    void DOMAINE_bar();
    void DOMAINE_pie();

private:
    Ui::STAT *ui;
};

#endif // STAT_COMBO_H
