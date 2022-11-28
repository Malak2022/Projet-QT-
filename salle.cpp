 #include "salle.h"

salle::salle()
{

}
salle::salle(int a ,int b, QString c,int d ,int  e,QString f)
{
    NUMERO_SALLE=a;
    CAPACITE=b;
    ADRESSE=c;
    COUT=d;
    DISPONIBILITE=e;
    VIDEO=f;

}


bool salle::ajouter(){
    QSqlQuery query;
    QString res = QString::number(NUMERO_SALLE);

    query.prepare("insert into SALLES(NUMERO_SALLE,CAPACITE,ADRESSE,COUT,DISPONIBILITE,VIDEO)""values(:NUMERO_SALLE,:CAPACITE,:ADRESSE,:COUT,:DISPONIBILITE,:VIDEO)");

    query.bindValue(":NUMERO_SALLE",NUMERO_SALLE);
    query.bindValue(":CAPACITE",CAPACITE);
    query.bindValue(":ADRESSE",ADRESSE);
    query.bindValue(":COUT",COUT);
    query.bindValue(":DISPONIBILITE",DISPONIBILITE);
    query.bindValue(":VIDEO",VIDEO);

    return query.exec();

}



QSqlQueryModel * salle::afficher(){

      QSqlQueryModel * model=new QSqlQueryModel();

       model->setQuery("select * from SALLES ");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUMERO_SALLE"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("CAPACITE"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADRESSE"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("COUT"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("DISPONIBILITE"));
       model->setHeaderData(5,Qt::Horizontal,QObject::tr("VIDEO"));

       return  model;

}
QSqlQueryModel * salle::afficher1(){

      QSqlQueryModel * model=new QSqlQueryModel();

       model->setQuery("select * from SALLES order by CAPACITE desc");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUMERO_SALLE"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("CAPACITE"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADRESSE"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("COUT"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("DISPONIBILITE"));

       return  model;

}
QSqlQueryModel * salle::afficher2(){

      QSqlQueryModel * model=new QSqlQueryModel();

       model->setQuery("select * from SALLES order by COUT desc");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUMERO_SALLE"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("CAPACITE"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADRESSE"));
       model->setHeaderData(3,Qt::Horizontal,QObject::tr("COUT"));
       model->setHeaderData(4,Qt::Horizontal,QObject::tr("DISPONIBILITE"));

       return  model;

}





bool salle::supprimer(int NUMERO){
QSqlQuery query;
QString res=QString::number(NUMERO);

query.prepare("delete from SALLES where NUMERO_SALLE= :NUMERO_SALLE");
query.bindValue(":NUMERO_SALLE",res);

return query.exec();
}






QSqlQueryModel * salle::afficher4(QString a,QString b)
 {
   QSqlQueryModel * model = new QSqlQueryModel();

   model->setQuery("select * from SALLES WHERE "+a+" LIKE '%"+b+"%'");

   model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUMERO_SALLE"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("CAPACITE"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADRESSE"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("COUT"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("DISPONIBILITE"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("VIDEO"));
    return model;
 }

QSqlQueryModel * salle::afficher5(QString a)
 {  QSqlQueryModel * model = new QSqlQueryModel();


    model->setQuery("select * from SALLES order by "+a+" desc");

   model->setHeaderData(0,Qt::Horizontal,QObject::tr("NUMERO_SALLE"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("CAPACITE"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("ADRESSE"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("COUT"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("DISPONIBILITE"));
    return model;
 }

QSqlQueryModel * salle::setid()
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     model->setQuery("select DISTINCT NUMERO_SALLE from SALLES ");
     model->setHeaderData(0,Qt::Horizontal,"NUMERO_SALLE");

     return model;
 }

bool salle::modifier()
 {
     QSqlQuery query;
     query.prepare("UPDATE SALLES SET  CAPACITE=:CAPACITE , ADRESSE=:ADRESSE , COUT=:COUT , DISPONIBILITE=:DISPONIBILITE, VIDEO=:VIDEO where NUMERO_SALLE=:NUMERO_SALLE ");

     query.bindValue(":NUMERO_SALLE", NUMERO_SALLE);
     query.bindValue(":CAPACITE", CAPACITE);
     query.bindValue(":ADRESSE", ADRESSE);
     query.bindValue(":COUT",COUT);
     query.bindValue(":DISPONIBILITE",DISPONIBILITE);
     query.bindValue(":VIDEO",VIDEO);
     return    query.exec();

 }
