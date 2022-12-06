#include "fournisseur.h"
#include "ui_fournisseur.h"

fournisseur::fournisseur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fournisseur)
{
    ui->setupUi(this);
}

fournisseur::~fournisseur()
{
    delete ui;
}
