#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"evenement.h"
#include <QMainWindow>

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


private:
    Ui::MainWindow *ui;
    evenement e;

};
#endif // MAINWINDOW_H
