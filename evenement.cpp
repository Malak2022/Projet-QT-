
#include "evenement.h"
#include<QtDebug>
#include<QObject>


evenement::evenement()
{
numero=0;
type="";
id_personnel=0;
numero_salle=0;
numero_participants=0;
tarif=0;

}
evenement::evenement(QString type,int id_personnel,int numero,int numero_salle,int numero_participants,float tarif,QDate a,QTime b)
{
 this->numero=numero;
 this->type=type;
 this->id_personnel=id_personnel;
 this->numero_salle=numero_salle;
 this->numero_participants=numero_participants;
 this->tarif=tarif;
 this->date=a;
 this->duree=b;
}
void evenement ::setnumero(int n) {numero=n;}
void evenement ::settype(QString n) {type=n;}
void evenement ::setdate(QDate n) {date=n;}
void evenement ::setid_personnel(int n) {id_personnel=n;}
void evenement ::setnumero_salle(int n) {numero_salle=n;}
void evenement ::setduree(QTime n) {duree=n;}
void evenement ::setnumero_participants(int n) {numero_participants=n;}
void evenement ::settarif(float n) {tarif=n;}

int evenement::get_numero(){return numero;}
QString evenement::get_type(){return type;}
QDate evenement::get_date(){return date;}
int evenement::get_id_personnel(){return id_personnel;}
int evenement::get_numero_salle(){return numero_salle;}
QTime evenement::get_duree(){return duree ;}
int evenement::get_numero_participants(){return numero_participants;}
float evenement::get_tarif(){return tarif ;}

bool evenement::ajouter(){

    QSqlQuery query;

    QString num= QString::number(numero);
    QString  id=QString ::number(id_personnel);
    QString  num2=QString ::number(numero_participants);
    QString  num3=QString ::number(numero_salle);
    QString  tariff=QString ::number(tarif);

    query.prepare("INSERT INTO evenement (NUMERO, TYPE, DATE_EVENEMENT, DUREE, TARIF, NUMERO_PARTICIPANTS, NUMERO_SALLE, ID_PERSONNEL)"
                  "VALUES( :numero, :type, :date_evenement, :duree, :tarif, :numero_participants,  :numero_salle,  :id_personnel )");

    query.bindValue(":numero",num);
    query.bindValue(":type",type);
    query.bindValue(":date_evenement",date);
    query.bindValue(":duree",duree);
    query.bindValue(":tarif",tariff);
    query.bindValue(":numero_participants",num2);
    query.bindValue(":numero_salle",num3);
    query.bindValue(":id_personnel",id);

    return query.exec();
}
bool evenement::supprimer(int numero )
{ QSqlQuery query;
 QString num= QString::number(numero);
 query.prepare("Delete from evenement where NUMERO= :numero");
 query.bindValue(":numero",num);
 return query.exec();
}
QSqlQueryModel * evenement:: afficher()
{
 QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("select * from EVENEMENT");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numéro"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("Durée"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("Tarif"));
 model->setHeaderData(5,Qt::Horizontal,QObject::tr("Numero_participants"));
 model->setHeaderData(6,Qt::Horizontal,QObject::tr("Numéro_salle"));
 model->setHeaderData(7,Qt::Horizontal,QObject::tr("Id_personnel"));
 return model;
}
bool evenement::modifier(int numero,QString type, QDate date, QTime duree,float tarif,int numero_participants,int numero_salle,int id_personnel)
{

        QSqlQuery query;

        QString num= QString::number(numero);
        QString  id=QString ::number(id_personnel);
        QString  num2=QString ::number(numero_participants);
        QString  num3=QString ::number(numero_salle);
       QString  tariff=QString ::number(tarif);

       query.prepare("UPDATE  EVENEMENT set NUMERO= :numero , TYPE= :type, DATE_EVENEMENT= :date_evenement, DUREE= :duree, TARIF= :tarif, NUMERO_PARTICIPANTS= :numero_participants, NUMERO_SALLE= :numero_salle, ID_PERSONNEL= :id_personnel where NUMERO= :numero" );

        query.bindValue(":numero",num);
        query.bindValue(":type",type);
        query.bindValue(":date_evenement",date);
        query.bindValue(":duree",duree);
        query.bindValue(":tarif",tariff);
        query.bindValue(":numero_participants",num2);
        query.bindValue(":numero_salle",num3);
        query.bindValue(":id_personnel",id);
        return query.exec();
    }
QSqlQueryModel* evenement ::recherche_type(QString type)
{

QSqlQuery query;
 query.prepare("SELECT * FROM EVENEMENT where TYPE = :type");
 query.bindValue(":type",type);
 query.exec();
 QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery(query);
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numéro"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("Durée"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("Tarif"));
 model->setHeaderData(5,Qt::Horizontal,QObject::tr("Numero_participants"));
 model->setHeaderData(6,Qt::Horizontal,QObject::tr("Numéro_salle"));
model->setHeaderData(7,Qt::Horizontal,QObject::tr("Id_personnel"));

return  model;

}


QSqlQueryModel* evenement ::recherche_tarif(float tarif)
{

QSqlQuery query;
QString tariff= QString::number(tarif);
 query.prepare("SELECT * FROM EVENEMENT where TARIF = :tarif");
 query.bindValue(":tarif",tariff);
query.exec();
 QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery(query);
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numéro"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("Durée"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("Tarif"));
 model->setHeaderData(5,Qt::Horizontal,QObject::tr("Numero_participants"));
 model->setHeaderData(6,Qt::Horizontal,QObject::tr("Numéro_salle"));
model->setHeaderData(7,Qt::Horizontal,QObject::tr("Id_personnel"));

return  model;

}
QSqlQueryModel* evenement ::recherche_numerosalle(int numero_salle)
{

QSqlQuery query;
QString nums= QString::number(numero_salle);
 query.prepare("SELECT * FROM EVENEMENT where NUMERO_SALLE = :numero_salle");
 query.bindValue(":numero_salle",nums);
query.exec();
 QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery(query);
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numéro"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("Durée"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("Tarif"));
 model->setHeaderData(5,Qt::Horizontal,QObject::tr("Numero_participants"));
 model->setHeaderData(6,Qt::Horizontal,QObject::tr("Numéro_salle"));
model->setHeaderData(7,Qt::Horizontal,QObject::tr("Id_personnel"));
return  model;

}
QSqlQueryModel*  evenement ::recherche_date(QDate date)
 {

    QSqlQuery query;


     query.prepare("SELECT * FROM  EVENEMENT where DATE_EVENEMENT= :date_evenement");
     query.bindValue(":date_evenement",date);
     query.exec();
     QSqlQueryModel *model= new QSqlQueryModel;
model->setQuery(query);
model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numéro"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("Durée"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("Tarif"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("Numero_participants"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("Numéro_salle"));
model->setHeaderData(7,Qt::Horizontal,QObject::tr("Id_personnel"));

    return model;

 }
QSqlQueryModel* evenement ::trie_date()
{


  QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("SELECT * FROM EVENEMENT ORDER BY DATE_EVENEMENT" );
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numéro"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("Durée"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("Tarif"));
 model->setHeaderData(5,Qt::Horizontal,QObject::tr("Numero_participants"));
 model->setHeaderData(6,Qt::Horizontal,QObject::tr("Numéro_salle"));
model->setHeaderData(7,Qt::Horizontal,QObject::tr("Id_personnel"));
  return  model;

}

QSqlQueryModel* evenement ::trie_nbparticipants()
{


  QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("SELECT * FROM EVENEMENT ORDER BY NUMERO_PARTICIPANTS " );
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numéro"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("Durée"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("Tarif"));
 model->setHeaderData(5,Qt::Horizontal,QObject::tr("Numero_participants"));
 model->setHeaderData(6,Qt::Horizontal,QObject::tr("Numéro_salle"));
model->setHeaderData(7,Qt::Horizontal,QObject::tr("Id_personnel"));
  return  model;

}

QSqlQueryModel* evenement ::trie_tarif()
{


  QSqlQueryModel *model=new QSqlQueryModel();
 model->setQuery("SELECT * FROM EVENEMENT ORDER BY  TARIF " );
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numéro"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("Type"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("Date"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("Durée"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("Tarif"));
 model->setHeaderData(5,Qt::Horizontal,QObject::tr("Numero_participants"));
 model->setHeaderData(6,Qt::Horizontal,QObject::tr("Numéro_salle"));
model->setHeaderData(7,Qt::Horizontal,QObject::tr("Id_personnel"));
  return  model;

}
