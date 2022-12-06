#ifndef EVENEMENT_H
#define EVENEMENT_H
#include<QString>
#include <QDateEdit>
#include <QTimeEdit>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QTableView>
#include<QFile>
#include<QFileDialog>
#include<QCoreApplication>
class evenement
{
private:
    QString type;
    int numero,numero_salle,numero_participants,id_personnel;
    QDate date;
    QTime duree;
    float tarif;
public:
    evenement();
     evenement(QString,int,int,int,int,float,QDate,QTime);
    void setnumero(int n);
    void settype(QString n);
    void setdate(QDate n);
    void setid_personnel(int n);
    void setnumero_salle(int n);
    void setduree(QTime n);
    void setnumero_participants(int n);
    void settarif(float n);


    int get_numero();
    QString get_type();
    QDate get_date();
    int  get_id_personnel();
    int get_numero_salle();
    QTime get_duree();
    int get_numero_participants();
    float get_tarif();
bool ajouter();
QSqlQueryModel * afficher();
QSqlQueryModel* recherche_type(QString);
QSqlQueryModel* recherche_tarif(float );
QSqlQueryModel* recherche_numerosalle(int);
QSqlQueryModel* recherche_date(QDate);
QSqlQueryModel* trie_date();
QSqlQueryModel* trie_tarif();
QSqlQueryModel* trie_nbparticipants();
QSqlQueryModel* get_numero_s();
QSqlQueryModel* get_idperso();

 bool supprimer(int);
 bool modifier(int,QString,QDate,QTime,float,int,int,int);
 void exporter(QTableView *table);
};

#endif // EVENEMENT_H
