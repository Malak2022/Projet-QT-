
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evenement.h"
#include "dialog.h"
#include<QPixmap>
#include <QDateEdit>
#include <QTimeEdit>
#include <QMessageBox>
#include<QIntValidator>
#include<QTextDocument>

#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QApplication>
#include<QCalendarWidget>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
     ui(new Ui::MainWindow)
{
     ui->setupUi(this);
      ui->tabevent->setModel(e.afficher());
      ui->comboBox_2->setModel(e.afficher());
      ui->comboBox_3->setModel(e.afficher());
     ui->lineEdit_numero->setValidator(new QIntValidator(0,999999,this));
     ui->lineEdit_tarif_2->setValidator(new QIntValidator(0,999999,this));
     ui->lineEdit_num_part->setValidator(new QIntValidator(0,999999,this));
     ui->numero_s->setModel(e.get_numero_s());
     ui->idperso->setModel(e.get_idperso());
     ui->lineEdit_type->setValidator(new QRegExpValidator(QRegExp("[A-Z,a-z]*")));
      QPixmap pix("C:/Users/Nawres/Desktop/logo.png");
      QPixmap pixxx("C:/Users/Nawres/Desktop/caa.png");
      ui->label_pic->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
      ui->label_picc->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
      ui->label_piccl->setPixmap(pixxx.scaled(100,100,Qt::KeepAspectRatio));
      //ui->tabevent>setColumnWidth(4,100);
      ui->label_gif->setMask((new QPixmap("C:/Users/Nawres/Desktop/promo3.gif"))->mask());

        QMovie *movie = new QMovie ("C:/Users/Nawres/Desktop/promo3.gif");
        ui->label_gif->setMovie(movie);
        movie->start();
        ui->label_gif->show();

}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{

    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("C:/Users/Nawres/Downloads/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();

   int numero=ui->lineEdit_numero->text().toInt();
   int id_personnel=ui->idperso->currentText().toInt();
   QString type=ui->lineEdit_type->text();
   QDate  date=ui->dateEdit_date->date();

  int numero_salle=ui->numero_s->currentText().toInt();
   QTime duree=ui->timeEdit_duree->time();
   int numero_participants=ui->lineEdit_num_part->text().toInt();
  float tarif=ui->lineEdit_tarif_2->text().toFloat();
   evenement e(type,id_personnel,numero,numero_salle,numero_participants,tarif,date,duree);
   bool test=e.ajouter();

   if (test)

     {
       QMediaPlayer *player = new QMediaPlayer;
                      player->setMedia(QUrl::fromLocalFile("C:/Users/Nawres/Desktop/ajouter.mp3"));
                      player->setVolume(45);
                      player->play();
       QMessageBox::information(nullptr, QObject::tr("OK"),
                   QObject::tr("Ajout effectué\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

           ui->tabevent->setModel(e.afficher());
           ui->comboBox_2->setModel(e.afficher());
          ui->comboBox_3->setModel(e.afficher());

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

        QMediaPlayer *music=new QMediaPlayer();
        music->setMedia(QUrl("C:/Users/Nawres/Downloads/mixkit-fast-double-click-on-mouse-275.wav"));
        music->setVolume(50);
        music->play();
        int numero =ui->lineEdit_numero->text().toInt();
        bool test=e.supprimer(numero);
        if(test)
        {
            QMediaPlayer *player = new QMediaPlayer;
                           player->setMedia(QUrl::fromLocalFile("C:/Users/Nawres/Desktop/suppression.mp3"));
                           player->setVolume(45);
                           player->play();
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("Suppression effectuée\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
              ui->tabevent->setModel(e.afficher());
              ui->comboBox_2->setModel(e.afficher());
              ui->comboBox_3->setModel(e.afficher());

              }
        else
            QMessageBox::information(nullptr,QObject::tr(" Not OK"),
                                QObject::tr("Suppression non effectuée\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
              }

}

void MainWindow::on_pushButton_clicked()

    {
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("C:/Users/Nawres/Downloads/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
       int numero=ui->lineEdit_numero->text().toInt();
       int id_personnel=ui->idperso->currentText().toInt();
       QString type=ui->lineEdit_type->text();
       QDate  date=ui->dateEdit_date->date();

      int numero_salle=ui->numero_s->currentText().toInt();
       QTime duree=ui->timeEdit_duree->time();
       int numero_participants=ui->lineEdit_num_part->text().toInt();
      float tarif=ui->lineEdit_tarif_2->text().toFloat();
       evenement e(type,id_personnel,numero,numero_salle,numero_participants,tarif,date,duree);
      bool test=e.modifier(numero,type,date,duree ,tarif,numero_participants,numero_salle,id_personnel);
      if (test)
         {
          QMediaPlayer *player = new QMediaPlayer;
                         player->setMedia(QUrl::fromLocalFile("C:/Users/Nawres/Desktop/modification.mp3"));
                         player->setVolume(45);
                         player->play();
          QMessageBox::information(nullptr, QObject::tr("OK"),
                       QObject::tr("modification effectué\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tabevent->setModel(e.afficher());
           ui->comboBox_2->setModel(e.afficher());
           ui->comboBox_3->setModel(e.afficher());

       }
      else
           QMessageBox::information(nullptr, QObject::tr(" Not OK"),
                              QObject::tr("modification non effectué\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


}






void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{

    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("C:/Users/Nawres/Downloads/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    int numero =ui->comboBox_2->currentText().toInt();
         QString num= QString::number(numero);
                QSqlQuery query;
                query.prepare("select * from evenement where NUMERO='"+num+"'");

                if(query.exec()){

                    while(query.next())
                    {

                   ui->lineEdit_numero->setText(query.value(0).toString());
                   ui->lineEdit_type->setText(query.value(1).toString());

                   ui->lineEdit_tarif_2->setText(query.value(4).toString());
                    ui->lineEdit_num_part->setText(query.value(5).toString());
                    ui->numero_s->setCurrentText(query.value(6).toString());
                    ui->idperso->setCurrentText(query.value(7).toString());





    }}
                else
                    QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
    }


void MainWindow::on_comboBox_3_currentIndexChanged(const QString &arg1)
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("C:/Users/Nawres/Downloads/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    int numero =ui->comboBox_3->currentText().toInt();
         QString num= QString::number(numero);
                QSqlQuery query;
                query.prepare("select * from evenement where NUMERO='"+num+"'");

                if(query.exec()){

                    while(query.next())
                    {

                   ui->lineEdit_numero->setText(query.value(0).toString());
                   ui->lineEdit_type->setText(query.value(1).toString());
                   ui->lineEdit_tarif_2->setText(query.value(4).toString());
                    ui->lineEdit_num_part->setText(query.value(5).toString());
                    ui->numero_s->setCurrentText(query.value(6).toString());
                    ui->idperso->setCurrentText(query.value(7).toString());





    }}
                else
                    QMessageBox::critical(nullptr, QObject::tr(" echoué"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_3_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("C:/Users/Nawres/Downloads/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
       QString typee=ui->lineEdit_recherche->text();
       float tariff=ui->lineEdit_recherche->text().toFloat();
      int numerosalle=ui->lineEdit_recherche->text().toInt();
    if (ui->comboBox_recherche->currentText()=="type")
      ui->tabevent->setModel(e.recherche_type(typee));
  else if (ui->comboBox_recherche->currentText()=="tarif")
      ui->tabevent->setModel(e.recherche_tarif(tariff));
     else if (ui->comboBox_recherche->currentText()=="numero_salle")
      ui->tabevent->setModel(e.recherche_numerosalle(numerosalle));
}

void MainWindow::on_pushButton_4_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("C:/Users/Nawres/Downloads/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
if (ui->comboBox_5->currentText()=="date")
  ui->tabevent->setModel(e.trie_date());
else if (ui->comboBox_5->currentText()=="tarif")
  ui->tabevent->setModel(e.trie_tarif());
else if (ui->comboBox_5->currentText()=="numero participants")
  ui->tabevent->setModel(e.trie_nbparticipants());
}


void MainWindow::on_pushButton_5_clicked()
{


    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("C:/Users/Nawres/Downloads/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
                     QString strStream;
                    QTextStream out(&strStream);
                    const int rowCount = ui->tabevent->model()->rowCount();
                    const int columnCount =ui->tabevent->model()->columnCount();


                    out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("evenement")
                            <<  "</head>\n"
                            "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                                "<h1>Liste des Evenements</h1>"

                                "<table border=1.5 cellspacing=0 cellpadding=2>\n";

                    // headers
                        out << "<thead><tr bgcolor=#FFCCD4>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->tabevent->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->tabevent->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";
                        // data table
                           for (int row = 0; row < rowCount; row++) {
                               out << "<tr>";
                               for (int column = 0; column < columnCount; column++) {
                                   if (!ui->tabevent->isColumnHidden(column)) {
                                       QString data = ui->tabevent->model()->data(ui->tabevent->model()->index(row, column)).toString().simplified();
                                       out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                   }
                               }
                               out << "</tr>\n";
                           }
                           out <<  "</table>\n"
                               "</body>\n"
                               "</html>\n";



            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);



            QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName("liste_evenements.pdf");
            document->print(&printer);

    }

void MainWindow::on_pushButton_stat_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("C:/Users/Nawres/Downloads/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    QSqlQueryModel * model= new QSqlQueryModel();

                            model->setQuery("select * from EVENEMENT where TARIF <500 ");
                            float e=model->rowCount();
                             model->setQuery("select * from EVENEMENT where TARIF between 500 and 1000  ");
                             float ee=model->rowCount();
                             model->setQuery("select * from EVENEMENT where  TARIF between 1000 and 2000 ");
                             float eee=model->rowCount();
                             model->setQuery("select * from EVENEMENT where  TARIF > 2000 ");
                             float eeee=model->rowCount();
                             float total=e+ee+eee+eeee;
                             QString a=QString("Moins de 500 dinars "+QString::number((e*100)/total,'f',2)+"%" );
                             QString b=QString("Entre 500 et 1000 dinars "+QString::number((ee*100)/total,'f',2)+"%" );
                             QString c=QString("Entre 1000 et 2000 dinars "+QString::number((eee*100)/total,'f',2)+"%" );
                             QString d=QString("Plus de 2000 dinars "+QString::number((eeee*100)/total,'f',2)+"%" );
                            QPieSeries *series = new QPieSeries();
                            series->append(a,e);
                             series->append(b,ee);
                             series->append(c,eee);
                             series->append(d,eeee);
                     if (e!=0)
                     {QPieSlice *slice = series->slices().at(0);
                      slice->setLabelVisible();
                      slice->setPen(QPen());}
                     if ( ee!=0)
                     {
                           //add label to rest of slices
                              QPieSlice *slice1 = series->slices().at(1);

                              slice1->setLabelVisible();
                     }
                     if(eee!=0)
                     {

                              QPieSlice *slice2 = series->slices().at(2);

                              slice2->setLabelVisible();
                     }
                     if(eeee!=0)
                     {

                              QPieSlice *slice2 = series->slices().at(3);

                              slice2->setLabelVisible();
                     }
                             // Create the chart widget
                             QChart *chart = new QChart();
                             // Add data to chart with title and hide legend
                             chart->addSeries(series);
                             chart->setTitle("Statistiques selon tarifs : "+ QString::number(total));
                             chart->legend()->hide();
                             // Used to display the chart
                             QChartView *chartView = new QChartView(chart);
                             chartView->setRenderHint(QPainter::Antialiasing);
                             chartView->resize(1000,500);

                            chartView->show();

}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{

    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("C:/Users/Nawres/Downloads/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
       ui->dateEdit_date = new QDateEdit;
                           ui->dateEdit_date->setDisplayFormat("dd/MM/yyyy");
                           ui->dateEdit_date->setDate(date);

                       QString Date(ui->dateEdit_date->text());
                      //QString date=ui->currentdate->toString();
                       QSqlQueryModel* model=e.recherche_date(date);
                       if (model != nullptr)
                       {
                          ui->tcalendrier->setModel(model);
                       }

    }


void MainWindow::on_reduction_clicked()
{

    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("C:/Users/Nawres/Downloads/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
   int numero =ui->comboBox_2->currentText().toInt();
   int id_personnel=ui->idperso->currentText().toInt();
   QString type=ui->lineEdit_type->text();
   QDate  date=ui->dateEdit_date->date();
  int numero_salle=ui->numero_s->currentText().toInt();
   QTime duree=ui->timeEdit_duree->time();
   int numero_participants=ui->lineEdit_num_part->text().toInt();
   float tarif=ui->lineEdit_tarif_2->text().toFloat();
   int reduction;

   if (numero_participants>50 && numero_participants<100)
      reduction=20;
   if (numero_participants>=100 && numero_participants<150)
      reduction=30;
   if (numero_participants>=150)
      reduction=50;

    tarif=tarif*(100-reduction)/100;
    evenement e(type,id_personnel,numero,numero_salle,numero_participants,tarif,date,duree);
    bool test=e.modifier(numero,type,date,duree ,tarif,numero_participants,numero_salle,id_personnel);

       if(test)
       {
           QMediaPlayer *player = new QMediaPlayer;
                          player->setMedia(QUrl::fromLocalFile("C:/Users/Nawres/Desktop/reduction.mp3"));
                          player->setVolume(45);
                          player->play();
           QMessageBox::information(nullptr, QObject::tr("OK"),
                                  QObject::tr("Reduction effectuée\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tabevent->setModel(e.afficher());
        ui->comboBox_2->setModel(e.afficher());
        ui->comboBox_3->setModel(e.afficher());
       }
       else
           QMessageBox::information(nullptr, QObject::tr(" Not OK"),
                              QObject::tr("Reduction non effectuée\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_6_clicked()
{
    QMediaPlayer *music=new QMediaPlayer();
    music->setMedia(QUrl("C:/Users/Nawres/Downloads/mixkit-fast-double-click-on-mouse-275.wav"));
    music->setVolume(5);
    music->play();
    e.exporter(ui->tabevent);
}

