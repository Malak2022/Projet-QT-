#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H


#include <QDialog>
#include"mainwindow.h"
#include <QMainWindow>
#include"personnel.h"
#include <QDialog>

namespace Ui {
class equipement;
}

class equipement : public QDialog
{
    Q_OBJECT

public:
    equipement(QWidget *parent = nullptr);
    ~equipement();

    private slots:

private:
    Ui::equipement *ui;
    MainWindow *main;
    QSqlDatabase db;

};


#endif // EQUIPEMENT_H
