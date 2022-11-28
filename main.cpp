#include "mainwindow.h"
#include "salle.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QApplication>
#include <arduino.h>
//QSqlDatabase db= QSqlDatabase::addDatabase("QODBC");



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    bool test=c.createconnection();
    MainWindow w;
   // arduino ar;

    if(test)
    {
        w.show();
    //    ar.show();
        QMessageBox::critical(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    return a.exec();
}
