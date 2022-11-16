#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"evenement.h"
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QMediaPlayer>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_suppression_clicked();

    void on_pushButton_clicked();




    void on_comboBox_2_currentIndexChanged(const QString &arg1);



    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_pushButton_stat_clicked();

    void on_calendarWidget_clicked(const QDate &date);



    void on_reduction_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    evenement e;

};
#endif // MAINWINDOW_H
