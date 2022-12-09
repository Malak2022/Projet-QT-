#include "modif.h"
#include "ui_modif.h"
#include "fournisseur.h"
modif::modif(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modif)
{
    ui->setupUi(this);
}

modif::~modif()
{
    delete ui;

}


void modif::on_pushButton_2_clicked()
{
    FOURNISSEUR fr;
      fr.supprimer(ui->lineEdit_18->text().toInt());
      FOURNISSEUR FR(ui->lineEdit_10->text().toInt(),ui->lineEdit_11->text(),ui->lineEdit_12->text(),ui->lineEdit_13->text().toInt(),ui->lineEdit_14->text(),ui->lineEdit_15->text(),ui->lineEdit_16->text(),ui->TYPE->currentText(),ui->lineEdit->text());


      FR.ajouter();



      close();
}

void modif::on_pushButton_3_clicked()
{
    close();

}
