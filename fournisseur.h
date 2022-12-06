#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H


#include <QDialog>
#include"mainwindow.h"
#include <QMainWindow>
#include"personnel.h"
#include <QDialog>

namespace Ui {
class fournisseur;
}

class fournisseur : public QDialog
{
    Q_OBJECT

public:
    fournisseur(QWidget *parent = nullptr);
    ~fournisseur();

    private slots:

private:
    Ui::fournisseur *ui;
    MainWindow *main;
    QSqlDatabase db;

};



#endif // FOURNISSEUR_H
