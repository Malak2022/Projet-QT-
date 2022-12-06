#include "salle.h"
#include "ui_salle.h"

salle::salle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::salle)
{
    ui->setupUi(this);
}

salle::~salle()
{
    delete ui;
}
