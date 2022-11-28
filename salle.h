#ifndef SALLE_H
#define SALLE_H
#include <string>
#include "connection.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>

class salle
{
private:
    int NUMERO_SALLE;
    int CAPACITE;
    QString ADRESSE;
    int COUT;
    int DISPONIBILITE;
    QString VIDEO;




public:
    salle();
    salle(int ,int, QString,int,int,QString);

    int getnum(){return NUMERO_SALLE;}
    int getcapacite(){return CAPACITE;}
    QString getadresse(){return ADRESSE;}
    int getcout(){return COUT;}
    int getdisponibilite(){return DISPONIBILITE;}

    void setnom(int n){NUMERO_SALLE=n;}
    void setcapacite(int c){CAPACITE=c;}
    void setadresse(QString a){ADRESSE=a;}
    void setcout(int co){COUT=co;}
    void setdispo(int di){DISPONIBILITE=di;}


    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficher1();
    QSqlQueryModel * afficher2();
    QSqlQueryModel * afficher4(QString a,QString b);
    QSqlQueryModel * afficher5(QString a);
    bool supprimer(int);


    QSqlQueryModel * setid();
    bool modifier();
};

#endif // SALLE_H
