#include "supp.h"
#include "ui_supp.h"
#include "fournisseur.h"

supp::supp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::supp)
{
    ui->setupUi(this);
}

supp::~supp()
{
    delete ui;
}

void supp::pushButton_3()
{
  /*  FOURNISSEUR fr;
     fr.supprimer(ui->supp_2->toPlainText().toInt());
    close();*/
}

void supp::on_pushButton_clicked()
{FOURNISSEUR fr;
    fr.supprimer(ui->supp_2->text().toInt());
   close();

}

void supp::on_pushButton_2_clicked()
{
    close();
}
