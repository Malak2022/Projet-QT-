#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "connection.h"
#include "webaxwidget.h"
#include <QPainter>
#include <QPrinter>
#include "salle.h"
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QTextDocument>
#include <temperature.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{//ui->setupUi(this);
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
    ui->setupUi(this);

    player = new QMediaPlayer(this);
    vw = new QVideoWidget(this);
    player->setVideoOutput(vw);

    vw->setGeometry(100,100,900,900);
    ui->tabWidget->addTab(vw,"VIDEO");
    slider = new QSlider(this);
    bar = new QProgressBar(this);

    slider->setOrientation(Qt::Horizontal);

    ui->statusbar->addPermanentWidget(slider);
    ui->statusbar->addPermanentWidget(bar);

    connect(player,&QMediaPlayer::durationChanged,slider,&QSlider::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,slider,&QSlider::setValue);
    connect(slider,&QSlider::sliderMoved,player,&QMediaPlayer::setPosition);

    connect(player,&QMediaPlayer::durationChanged,bar,&QProgressBar::setMaximum);
    connect(player,&QMediaPlayer::positionChanged,bar,&QProgressBar::setValue);

    ui->tableView->setModel(Etmp.afficher());
    ui->comboBox_3->setModel(Etmp.setid());

    QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                       QCoreApplication::organizationName(), QCoreApplication::applicationName());

   // ui->WebBrowser1->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/place/ESPRIT/@36.9016729,10.1713215,15z");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajouter_clicked()
{
    int numsalle=ui->lineEdit_num->text().toInt();
    int capacite=ui->lineEdit_cap->text().toInt();
    QString adresse=ui->lineEdit_ad->text();
    int cout=ui->lineEdit_c->text().toInt();
    int disponibilite1=ui->comboBox_2->currentText().toInt();
    QString video1=ui->video->text();


    salle s(numsalle,capacite,adresse,cout,disponibilite1,video1);


    bool test=s.ajouter();

    if(test){
    ui->tableView->setModel(Etmp.afficher());
        QMessageBox::information(nullptr, QObject::tr("cancel"),QObject::tr("Ajout effectué\n" "click cancel to exit."), QMessageBox::Cancel);

    }

        else QMessageBox::critical(nullptr ,QObject::tr("cancel"),QObject::tr("ajout non effectué. \n" " click cancel to exit") );
}

void MainWindow::on_pushButton_supp_clicked()
{
    int NUMERO=ui->lineEdit_13->text().toInt();
        bool test=Etmp.supprimer(NUMERO);

        if(test){
    ui->tableView->setModel(Etmp.afficher());
            QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("suppression effectué\n" "click cancel to exit."), QMessageBox::Cancel);

        }

            else QMessageBox::critical(nullptr ,QObject::tr("not ok"),QObject::tr("suppression non effectué. \n" " click cancel to exit") );
}









void MainWindow::on_pushButton_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);
                    const int rowCount = ui->tableView->model()->rowCount();
                    const int columnCount =ui->tableView->model()->columnCount();


                    out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("SALLES")
                            <<  "</head>\n"
                            "<body bgcolor=#FFC0CB link=#FFC0CB>\n"
                                "<h1>Liste des Salles</h1>"


                                "<table border=1 cellspacing=9 cellpadding=9>\n";

                    // headers
                        out << "<thead><tr bgcolor=#FFC0CB>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->tableView->isColumnHidden(column))
                                out << QString("<th style='color:#FFFFFF'>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";
                        // data table
                           for (int row = 0; row < rowCount; row++) {
                               out << "<tr>";
                               for (int column = 0; column < columnCount; column++) {
                                   if (!ui->tableView->isColumnHidden(column)) {
                                       QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                       out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                   }
                               }
                               out << "</tr>\n";
                           }
                           out <<  "</table>\n";


                               "</body>\n"
                               "</html>\n";



          QTextDocument *document = new QTextDocument();
          document->setHtml(strStream);


           // QTextDocument *document;
              //  document->setHtml(strStream);
          //  document->setHtml(html);
            QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName("listesalle.pdf");
            document->print(&printer);

            QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("exportation effectué\n" "click cancel to exit."), QMessageBox::Cancel);

}






void MainWindow::on_comboBox_3_activated(int index)
{   QSqlQuery query;

    query.prepare("select * from  SALLES  where NUMERO_SALLE=:NUMERO_SALLE");

    query.bindValue(":NUMERO_SALLE",ui->comboBox_3->currentText().toInt());

    if(query.exec())
        while(query.next())

{


    ui->lineEdit_cap_2->setText(query.value(1).toString()) ;
    ui->lineEdit_ad_2->setText(query.value(2).toString()) ;
    ui->lineEdit_c_2->setText(query.value(3).toString()) ;
    ui->lineEdit_dis_2->setText(query.value(4).toString()) ;
    //ui->comboBox_5->setModel(query.value(4).toString());
    ui->video_2->setText(query.value(5).toString());
}
}

void MainWindow::on_Update_clicked()
{
    salle s(ui->comboBox_3->currentText().toInt(),ui->lineEdit_cap_2->text().toInt(),ui->lineEdit_ad_2->text(),ui->lineEdit_c_2->text().toInt(),ui->comboBox_5->currentText().toInt(),ui->video_2->text());
    s.modifier();
    ui->tableView->setModel(Etmp.afficher());
}

void MainWindow::on_pushButton_2_clicked()
{
    salle Etmp;
     ui->tableView->setModel(Etmp.afficher5(ui->comboBox_4->currentText()));
}

void MainWindow::on_pushButton_3_clicked()
{   QString filename = QFileDialog::getOpenFileName(this,"Open a File","","Video File (*.*)");
    on_pushButtonStop_clicked();

    player->setMedia(QUrl::fromLocalFile(filename));

    on_pushButtonplay_clicked();

}

void MainWindow::on_pushButtonplay_clicked()
{   player->play();
    ui->statusbar->showMessage("Playing");

}

void MainWindow::on_pushButtonStop_clicked()
{    player->pause();
     ui->statusbar->showMessage("Paused...");

}

void MainWindow::on_pushButtonPause_clicked()
{
    player->stop();
    ui->statusbar->showMessage("Stopped");
}

void MainWindow::on_pushButton_4_clicked()
{
    s=new stat_combo();

  s->setWindowTitle("statistique ComboBox");
  s->choix_pie();
  s->show();

}

void MainWindow::on_lineEditsearch_textChanged(const QString &arg1)
{ salle Etmp;
    ui->tableView->setModel(Etmp.afficher4(ui->comboBox->currentText(),ui->lineEditsearch->text()));

}

void MainWindow::on_pushButton_5_clicked()
{QString filename = QFileDialog::getOpenFileName(this,"Open a File","","Video File (*.*)");
ui->video->setText(filename);
}



void MainWindow::on_pushButton_6_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open a File","","Video File (*.*)");
    ui->video_2->setText(filename);
}

void MainWindow::on_tableView_pressed(const QModelIndex &index)
{   // index.data();player->setMedia(QUrl::fromLocalFile(filename));
ui->WebBrowser1->dynamicCall("Navigate(const QString&)", index.data().toString());

         player->setMedia(QUrl::fromLocalFile(index.data().toString()));
         ui->statusbar->showMessage("Playing");
         player->play();
                 //index.data().toString()
}


//arduino starts from here



void MainWindow::update_label()
{//bool ok=true;
  //  data=A.read_from_arduino();
 /*   int numsalle=ui->lineEdit_num->text().toInt();
    int capacite=ui->lineEdit_cap->text().toInt();
    QString adresse=ui->lineEdit_ad->text();
    int cout=ui->lineEdit_c->text().toInt();
    int disponibilite1=ui->comboBox_2->currentText().toInt();
    QString video1=ui->video->text();*/

//TEMPERATURE t(data);

//TEMPERATURE t(data);

  //t.tempajout();
   // query.prepare("select * from  SALLES  where NUMERO_SALLE=:NUMERO_SALLE");

    //query.bindValue(":NUMERO_SALLE",ui->comboBox_3->currentText().toInt());

data=A.read_from_arduino();
    cout<<data.toStdString();
  //  atoi(data);
    ui->label_20->setText(data+"\n");
    data1=("select * from T4EMPERATURE");
    A.write_to_arduino(data);

      //  if(A.read_from_arduino()>="22"){
            // QMessageBox::information(nullptr, QObject::tr("ON"),QObject::tr("Temperature supérieur à 20 °\n" "Allumer le climatiseur."), A.write_to_arduino("1"));
            // A.write_to_arduino("1");
    //    }
    //  else  if(A.read_from_arduino()<"22"){
          //   QMessageBox::information(nullptr, QObject::tr("OFF"),QObject::tr("Temperature inférieure à 20 °\n" "desactivez le climatiseur."), A.write_to_arduino("0"));
            // A.write_to_arduino("0");
     //   }


    //if(data!=""){
     //   TEMPERATURE t(data);
     //  t.tempajout();

    }



   /* if(data=="A")
        //cout<<(int)data.toStdString().;
        ui->label_20->setText(data);
    else if(data=="B")
        //cout<<(int)data.toStdString().;
        ui->label_20->setText("18 C°");
    else if(data=="C")
        //cout<<(int)data.toStdString().;
        ui->label_20->setText("19 C°");
    else if(data=="C")
        //cout<<(int)data.toStdString().;
        ui->label_20->setText("20 C°");
    else if(data=="D")
        //cout<<(int)data.toStdString().;
        ui->label_20->setText("20 C°");
    else if(data=="E")
        //cout<<(int)data.toStdString().;
        ui->label_20->setText("21 C°");
    else if(data=="F")
        //cout<<(int)data.toStdString().;
        ui->label_20->setText("21 C°");
    else if(data=="G")
        //cout<<(int)data.toStdString().;
        ui->label_20->setText("22 C°");
    else if(data=="H")
        //cout<<(int)data.toStdString().;
        ui->label_20->setText("22 C°");
    else if(data=="I")
        //cout<<(int)data.toStdString().;
        ui->label_20->setText("23 C°");
        // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

   // else if (data=="0")

     //   ui->label_3->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON*/


void MainWindow::on_pushButton_7_clicked()
{
     A.write_to_arduino("1"); //envoyer 1 à arduino
}

void MainWindow::on_pushButton_8_clicked()
{
     A.write_to_arduino("0"); //envoyer 1 à arduino
}
