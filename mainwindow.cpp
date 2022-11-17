#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personnel.h"
#include <QMessageBox>
#include <QSqlQuery>
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
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QTextDocument>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
  ui->le_idp->setValidator( new QIntValidator(0,9999999, this));
  ui->le_age->setValidator( new QIntValidator(0,100,this));
  ui->le_tel->setValidator( new QIntValidator(0,99999999,this));
  ui->le_salaire->setValidator(new QIntValidator(0,9999999,this));
  ui->le_role->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
  ui->le_nom->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
  ui->le_prenom->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
  ui->le_grade->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
  ui->le_genre->setValidator( new QRegExpValidator(QRegExp("[h,f]*")));
  ui->tab_personnel->setModel(P.afficher());
  ui->comboBox_3->setModel(P.afficher());
  son=new QSound(":/C/Users/user/Downloads/Sonido-del-Click-del-Mouse-Mouse-Click-Sound-Effect.wav");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    son->play();
    int ID_PERSONNEL=ui->le_idp->text().toInt();
    QString NOM=ui->le_nom->text();
    QString PRENOM=ui->le_prenom->text();
    int AGE=ui->le_age->text().toInt();
    QString GRADE=ui->le_grade->text();
    QString ROLE=ui->le_role->text();
    int SALAIRE=ui->le_salaire->text().toInt();
   int GENRE=ui->le_genre->currentText().toInt();
    int TELEPHONE=ui->le_tel->text().toInt();
    int PASSWORD=ui->le_password->text().toInt();
    int NOMBRE_RES=ui->le_nbrres->text().toInt();
    PERSONNEL P(ID_PERSONNEL,NOM,PRENOM,AGE,GRADE,ROLE,SALAIRE,GENRE,TELEPHONE,PASSWORD,NOMBRE_RES);
    bool test=P.ajouter();
    if(test)
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter"),
                    QObject::tr("Ajout avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
          ui->tab_personnel->setModel(P.afficher());
            ui->comboBox_3->setModel(P.afficher());

}
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("Pas d'ajout.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
}

void MainWindow::on_pb_supprimer_clicked()
{
    son->play();
  PERSONNEL P1;P1.setID_PERSONNEL(ui->le_idp_sup->text().toInt());
  bool test=P1.supprimer(P1.getID_PERSONNEL());
  QMessageBox msgBox;
  if(test)
     {
       msgBox.setText("Suppression avec succes.");
    ui->tab_personnel->setModel(P.afficher());
      ui->comboBox_3->setModel(P.afficher());
  }
  else
      msgBox.setText("Echec de suppression.");
      msgBox.exec();
}

void MainWindow::on_pb_modifier_clicked()
{
    son->play();
    int ID_PERSONNEL=ui->le_idp->text().toInt();
    QString NOM=ui->le_nom->text();
    QString PRENOM=ui->le_prenom->text();
    int AGE=ui->le_age->text().toInt();
    QString GRADE=ui->le_grade->text();
    QString ROLE=ui->le_role->text();
    int SALAIRE=ui->le_salaire->text().toInt();
    int GENRE=ui->le_genre->currentText().toInt();
    int TELEPHONE=ui->le_tel->text().toInt();
    int PASSWORD=ui->le_password->text().toInt();
    int NOMBRE_RES=ui->le_nbrres->text().toInt();
    PERSONNEL P(ID_PERSONNEL,NOM,PRENOM,AGE,GRADE,ROLE,SALAIRE,GENRE,TELEPHONE,PASSWORD,NOMBRE_RES);
    bool test=P.modifier(ID_PERSONNEL);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Modifier"),
                    QObject::tr("Modification  avec succés.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
          ui->tab_personnel->setModel(P.afficher());
            ui->comboBox_3->setModel(P.afficher());
   }
    else

        QMessageBox::critical(nullptr, QObject::tr("Modifier"),
                    QObject::tr("Pas de modification.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}




void MainWindow::on_pb_trier_clicked()
{
    son->play();
    PERSONNEL p;
    ui->tab_personnel->setModel(p.Trier(ui->comboBox_tri->currentText()));
}




void MainWindow::on_pb_chercher_clicked()
{
    son->play();
    PERSONNEL p;
    QString search=ui->line_recherche->text();
    ui->tab_personnel->setModel(p.Rechercher(search));
}


void MainWindow::on_pushButton_clicked()
{
    son->play();
    QString strStream;
                   QTextStream out(&strStream);
                   const int rowCount = ui->tab_personnel->model()->rowCount();
                   const int columnCount =ui->tab_personnel->model()->columnCount();

                   out <<  "<html>\n"
                           "<head>\n"
                           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                           <<  QString("<title>%1</title>\n").arg("PERSONNELS")
                           <<  "</head>\n"
                           "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                               "<h1>Liste des employes </h1>"

                               "<table border=1 cellspacing=0 cellpadding=2>\n";

                   // headers
                       out << "<thead><tr bgcolor=#f0f0f0>";
                       for (int column = 0; column < columnCount; column++)
                           if (!ui->tab_personnel->isColumnHidden(column))
                               out << QString("<th>%1</th>").arg(ui->tab_personnel->model()->headerData(column, Qt::Horizontal).toString());
                       out << "</tr></thead>\n";
                       // data table
                          for (int row = 0; row < rowCount; row++) {
                              out << "<tr>";
                              for (int column = 0; column < columnCount; column++) {
                                  if (!ui->tab_personnel->isColumnHidden(column)) {
                                      QString data = ui->tab_personnel->model()->data(ui->tab_personnel->model()->index(row, column)).toString().simplified();
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


          // QTextDocument *document;
             //  document->setHtml(strStream);
         //  document->setHtml(html);
           QPrinter printer(QPrinter::PrinterResolution);
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setOutputFileName("mypdffile.pdf");
           QString link ="file:///C:/Users/user/OneDrive/Documents/interfacepersonnel/mypdffile.pdf";
           document->print(&printer);

   }


void MainWindow::on_pushButton_2_clicked()
{
    son->play();
    s = new stat_combo();
   s->setWindowTitle("statistique ComboBox");
  s->choix_pie();
  s->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    s = new stat_combo();
  s->setWindowTitle("statistique ComboBox");
  s->choix_bar();
  s->show();

}




void MainWindow::on_comboBox_3_currentIndexChanged(const QString &arg1)
{
    int ID_PERSONNEL=ui->comboBox_3->currentText().toInt();
    QString id= QString::number(ID_PERSONNEL);
    QSqlQuery query;
        query.prepare("select * from  PERSONNEL  where ID_PERSONNEL='"+id+"'");

        query.bindValue(":ID_PERSONNEL",ui->comboBox_3->currentText().toInt());

        if(query.exec())
       while(query.next())
       {
        {


        ui->le_idp->setText(query.value(0).toString()) ;
        ui->le_nom->setText(query.value(1).toString()) ;
        ui->le_prenom->setText(query.value(2).toString()) ;
        ui->le_age->setText(query.value(3).toString()) ;
        ui->le_grade->setText(query.value(4).toString()) ;
        ui->le_role->setText(query.value(5).toString()) ;
        ui->le_salaire->setText(query.value(6).toString()) ;
        //ui->le_genre->setCurrentText(query.value(7).toString()) ;
        ui->le_tel->setText(query.value(8).toString()) ;
        ui->le_password->setText(query.value(9).toString()) ;
        ui->le_nbrres->setText(query.value(10).toString());
}
}
}

void MainWindow::on_pb_emd_clicked()
{
    PERSONNEL p;
    QString n=p.EDM();
    QMessageBox msgBox;
    QString str;
    str=QString("le personnel du mois est: %1 ").arg(n);
    msgBox.setText(str);
    msgBox.exec();

}

