#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QSound>
#include <QMainWindow>
#include "personnel.h"
#include "stat_combo.h"
#include "arduino.h"
#include "Parking.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_trier_clicked();

    void on_pb_chercher_clicked();

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_comboBox_3_activated(const QString &arg1);
    void on_comboBox_3_currentIndexChanged(const QString &arg1);
    void on_pb_emd_clicked();
    void on_pushButton_4_clicked();
    void update_label();

private:
    Ui::MainWindow *ui;
    PERSONNEL P;
    stat_combo *s;
    QSound *son;
   QString data;
    arduino A;
    parking p;
};
#endif // MAINWINDOW_H
