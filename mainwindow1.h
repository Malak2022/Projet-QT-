#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow1; }
QT_END_NAMESPACE

class MainWindow1 : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow1(QWidget *parent = nullptr);
    ~MainWindow1();

private:
    Ui::MainWindow1 *ui;
};
#endif // MAINWINDOW_H
