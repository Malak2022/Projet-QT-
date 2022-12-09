#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseur.h"
#include <QApplication>
#include <QMessageBox>
#include "dialog.h"
#include "supp.h"
#include "modif.h"
#include "stat.h"
#include <QDialog>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QTextDocument>
#include <QPainter>
#include <QPrinter>
#include <QMessageBox>
#include "ajouter.h"
#include <QPrinter>
#include "inserer.h"
#include "calc.h"
#include "arduino.h"
#include "temperature.h"
using namespace std;
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ajouter  ajout;
       ajout.setModal(true);
       ajout.exec();

}

void MainWindow::on_pushButton_4_clicked()
{
    Dialog ajout;
       ajout.setModal(true);
       ajout.exec();
}

void MainWindow::on_pushButton_5_clicked()
{
    supp ajout;
       ajout.setModal(true);
       ajout.exec();
}

void MainWindow::on_pushButton_3_clicked()
{
    modif ajout;
       ajout.setModal(true);
       ajout.exec();
}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    int ret=A.connect_arduino(); // lancer la connexion à arduino
        switch(ret){
        case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
            break;
        case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
           break;
        case(-1):qDebug() << "arduino is not available";
        }
         QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
         //le slot update_label suite à la reception du signal readyRead (reception des données).
       //TEMPERATURE TMP ;
        // nTMP.tempajout();
        ui->setupUi(this);

}







void MainWindow::on_pushButton_10_clicked()
{
    close();
}

void MainWindow::on_pushButton_7_clicked()
{

       s = new STAT();

            s->setWindowTitle("statistique");
            s->DOMAINE_pie();

            s->show();


}

void MainWindow::on_pushButton_9_clicked()
{s = new STAT();

    s->setWindowTitle("statistique");
    s->DOMAINE_bar();
    s->show();
}



void MainWindow::on_pushButton_8_clicked()
{

     c = new Calc();
        c->show();


}




void MainWindow::update_label(){

    A.data=A.serial->readAll();
            A.s = QString:: fromStdString (A.data.toStdString());
           qDebug() << A.s;
   ui->label_3->setText(A.s);
   //  if(A.read_from_arduino()>="22"){
               // QMessageBox::information(nullptr, QObject::tr("ON"),QObject::tr("Temperature supérieur à 20 °\n" "Allumer le climatiseur."), A.write_to_arduino("1"));
               // A.write_to_arduino("1");
       //    }
       //  else  if(A.read_from_arduino()<"22"){
             //   QMessageBox::information(nullptr, QObject::tr("OFF"),QObject::tr("Temperature inférieure à 20 °\n" "desactivez le climatiseur."), A.write_to_arduino("0"));
               // A.write_to_arduino("0");
        //   }

}


void MainWindow::on_pushButton_11_clicked()
{
    A.write_to_arduino("1");

}

void MainWindow::on_pushButton_12_clicked()
{
    A.write_to_arduino("0");
}
