#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>

#include "salle.h"
#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QProgressBar>
#include <QSlider>
#include "stat_combo.h"
#include "ui_stat_combo.h"
#include "arduino.h"
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
    void on_pushButton_ajouter_clicked();

    void on_pushButton_supp_clicked();
    void update_label();






    void on_pushButton_clicked();



    void on_comboBox_3_activated(int index);

    void on_Update_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButtonplay_clicked();

    void on_pushButtonStop_clicked();

    void on_pushButtonPause_clicked();

    void on_pushButton_4_clicked();

    void on_lineEditsearch_textChanged(const QString &arg1);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_tableView_pressed(const QModelIndex &index);

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
    salle Etmp;
    QMediaPlayer* player;
    QVideoWidget* vw;
    QProgressBar* bar;
    QSlider* slider;
    stat_combo *s;
    arduino A;
     QByteArray data;
      QByteArray data1;


};
#endif // MAINWINDOW_H
