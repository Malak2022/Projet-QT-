#include "ajouter.h"
#include "ui_ajouter.h"
#include "fournisseur.h"
#include <QApplication>
#include <QMessageBox>
#include <QFileDialog>
ajouter::ajouter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouter)
{
    ui->setupUi(this);

}

ajouter::~ajouter()
{
    delete ui;
}

void ajouter::on_pushButton_clicked()
{
    ;/*IF ID = " " {

        QMessageBox::information(nullptr, QObject::tr("id invalide"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
   */

FOURNISSEUR FR(ui->lineEdit->text().toInt(),ui->lineEdit_2->text(),ui->lineEdit_3->text(),ui->lineEdit_4->text().toInt(),ui->lineEdit_5->text(),ui->lineEdit_6->text(),ui->lineEdit_7->text(),ui->TYPE->currentText(),ui->image->text());
  FR.ajouter();
  close();
}

void ajouter::on_pushButton_2_clicked()
{
    close();
}


void ajouter::on_pushButton_3_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("choose"),"",tr(""));

        if(QString::compare(filename,QString())!=0)
        {QImage image;
            bool valid=image.load(filename);
            if(valid){

                ui->image->setText(filename);
                image=image.scaledToWidth(ui->img_name->width(),Qt::SmoothTransformation);
                ui->img_name->setPixmap(QPixmap::fromImage(image));

            }
            else
            {
                QMessageBox::information(this, tr("ERROR"), QString(tr("Not Valid!")));
}}}
