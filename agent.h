#ifndef AGENT_H
#define AGENT_H

#include"evenement.h"
#include"mainwindow.h"
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
#include<QPropertyAnimation>
#include<arduino.h>

//#include<parking.h>

QT_BEGIN_NAMESPACE
namespace Ui { class agent; }
QT_END_NAMESPACE

class agent : public QDialog
{
    Q_OBJECT

public:
  agent(QWidget *parent = nullptr);
    ~agent();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_suppression_clicked();
    void on_comboBox_2_currentIndexChanged(const QString &arg1);


  void on_pushButton_recherche_clicked();
   void on_pushButton_tri_clicked();


    void on_pushButton_5_clicked();
    void on_comboBox_suppression_currentIndexChanged(const QString &arg1);
    void on_pushButton_stat_clicked();

    void on_reduction_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_modifier_clicked();
    void on_calendarWidget_2_clicked(const QDate &date);

private:
    Ui::agent *ui;

    QSqlDatabase db;
    evenement e;
    QByteArray data; // variable contenant les données reçues
     arduino A ;   // objet temporaire
     };
#endif // AGENT_H
