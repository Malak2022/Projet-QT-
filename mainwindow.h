#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stat.h"
#include "calc.h"
#include "arduino.h"
#include <iostream>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();




void on_pushButton_8_clicked();

//void on_pushButton_11_clicked(bool checked);
void update_label();

void on_pushButton_11_clicked();

void on_pushButton_12_clicked();

private:
    Ui::MainWindow *ui;
    STAT *s;
    Calc *c;
    arduino A;
        QByteArray data;
};

#endif // MAINWINDOW_H
