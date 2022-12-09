#include "dialog.h"
#include "ui_dialog.h"
#include "fournisseur.h"
#include <QTextStream>
#include <QTextDocument>
#include <QPainter>
#include <QPrinter>
#include <QFileDialog>
#include <QMessageBox>
#include "connection.h"
#include "arduino.h"
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    FOURNISSEUR FR;
    ui->tableView->setModel(FR.afficher());}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::pushButton_7()
{
    close();
}

void Dialog::on_pushButton_clicked()
{
    QString strStream;
                QTextStream out(&strStream);
                const int rowCount = ui->tableView->model()->rowCount();
                const int columnCount =ui->tableView->model()->columnCount();


                out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("eleve")
                        <<  "</head>\n"
                        "<body bgcolor=#FFC0CB link=#5000A0>\n"
                            "<h1>Liste des fournisseurs</h1>"

                            "<table border=1 cellspacing=0 cellpadding=2>\n";

                // headers
                    out << "<thead><tr bgcolor=#FFC0CB>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->tableView->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
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
        printer.setOutputFileName("C:/Users/assil/Desktop/listefournissseur.pdf");
        document->print(&printer);

}

void Dialog::on_pushButton_2_clicked()
{
    close();
}

void Dialog::on_pushButton_3_clicked()
{

     FOURNISSEUR fr;
      ui->tableView->setModel(fr.afficher1(ui->comboBox->currentText(),ui->lineEdit->text()));

}

void Dialog::on_pushButton_4_clicked()
{
    FOURNISSEUR fr;
     ui->tableView->setModel(fr.afficher2(ui->comboBox_2->currentText()));

}

void Dialog::on_pushButton_5_clicked()
{

    FOURNISSEUR fr;
     ui->tableView->setModel(fr.afficher3(ui->comboBox_2->currentText()));
}

void Dialog::on_tableView_pressed(const QModelIndex &index)
{
    index.data();
     QString filename = index.data().toString();
     if(QString::compare(filename,QString())!=0)
     {QImage image;
         bool valid=image.load(filename);
         if(valid){


             image=image.scaledToWidth(ui->img_name->width(),Qt::SmoothTransformation);
             ui->img_name->setPixmap(QPixmap::fromImage(image));

         }
         else
         {
             QMessageBox::information(this, tr("ERROR"), QString(tr("Not Valid!")));
}}}

