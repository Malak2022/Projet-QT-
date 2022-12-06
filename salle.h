#ifndef SALLE_H
#define SALLE_H


#include <QDialog>
#include"mainwindow.h"
#include <QMainWindow>
#include"personnel.h"
#include <QDialog>

namespace Ui {
class salle;
}

class salle : public QDialog
{
    Q_OBJECT

public:
    salle(QWidget *parent = nullptr);
    ~salle();

    private slots:

private:
    Ui::salle *ui;
    MainWindow *main;
    QSqlDatabase db;

};





#endif // SALLE_H
