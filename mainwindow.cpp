#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evenement.h"
#include "dialog.h"
#include<QPixmap>
#include <QDateEdit>
#include <QTimeEdit>
#include <QMessageBox>
#include<QIntValidator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
      ui->tabevent->setModel(e.afficher());
     ui->lineEdit_numero->setValidator(new QIntValidator(0,999999,this));
     ui->lineEdit_tarif_2->setValidator(new QIntValidator(0,999999,this));
     ui->lineEdit_num_part->setValidator(new QIntValidator(0,999999,this));
     ui->lineEdit_salle->setValidator(new QIntValidator(0,999999,this));
     ui->lineEdit_id_pers->setValidator(new QIntValidator(0,999999,this));
     ui->lineEdit_type->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
      QPixmap pix("C:/Users/Nawres/Desktop/logo.png");
      ui->label_pic->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
      //ui->tabevent>setColumnWidth(4,100);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{

   int numero=ui->lineEdit_numero->text().toInt();
   int id_personnel=ui->lineEdit_id_pers->text().toInt();
   QString type=ui->lineEdit_type->text();
   QDate  date=ui->dateEdit_date->date();

  int numero_salle=ui->lineEdit_salle->text().toInt();
   QTime duree=ui->timeEdit_duree->time();
   int numero_participants=ui->lineEdit_num_part->text().toInt();
  float tarif=ui->lineEdit_tarif_2->text().toFloat();
   evenement e(type,id_personnel,numero,numero_salle,numero_participants,tarif,date,duree);
   bool test=e.ajouter();

   if (test)
     {  QMessageBox::information(nullptr, QObject::tr("OK"),
                   QObject::tr("Ajout effectué\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tabevent->setModel(e.afficher());

   }
   else if     (type.isEmpty())
      { QMessageBox::information(nullptr, QObject::tr(" Not OK"),
                                                         QObject::tr("Veuillez remplir le champ vide\n"
                                                                     "Click Cancel to exit."), QMessageBox::Cancel);


   }
    else   QMessageBox::information(nullptr, QObject::tr(" Not OK"),
                          QObject::tr("Ajout non effectué\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);


}
void MainWindow::on_pushButton_suppression_clicked()
{
    {
        int numero =ui->lineEdit_numero->text().toInt();
        bool test=e.supprimer(numero);
        if(test)
        {
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("Suppression effectuée\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
              ui->tabevent->setModel(e.afficher());
              }
        else
            QMessageBox::information(nullptr,QObject::tr(" Not OK"),
                                QObject::tr("Suppression non effectuée\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
              }

}

void MainWindow::on_pushButton_clicked()

    {

       int numero=ui->lineEdit_numero->text().toInt();
       int id_personnel=ui->lineEdit_id_pers->text().toInt();
       QString type=ui->lineEdit_type->text();
       QDate  date=ui->dateEdit_date->date();

      int numero_salle=ui->lineEdit_salle->text().toInt();
       QTime duree=ui->timeEdit_duree->time();
       int numero_participants=ui->lineEdit_num_part->text().toInt();
      float tarif=ui->lineEdit_tarif_2->text().toFloat();
       evenement e(type,id_personnel,numero,numero_salle,numero_participants,tarif,date,duree);
      bool test=e.modifier(numero,type,date,duree ,tarif,numero_participants,numero_salle,id_personnel);
      if (test)
         {  QMessageBox::information(nullptr, QObject::tr("OK"),
                       QObject::tr("modification effectué\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tabevent->setModel(e.afficher());
       }
      else
           QMessageBox::information(nullptr, QObject::tr(" Not OK"),
                              QObject::tr("modification non effectué\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


}





