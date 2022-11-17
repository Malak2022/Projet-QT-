#include "personnel.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QString>
PERSONNEL::PERSONNEL()
{
ID_PERSONNEL=0;SALAIRE=0;TELEPHONE=0;AGE=0;NOM=" ";PRENOM=" ";GRADE=" ";GENRE=0,PASSWORD=0; NOMBRE_RES=0;
}
PERSONNEL::PERSONNEL(int ID_PERSONNEL,QString NOM,QString PRENOM,int AGE,QString GRADE,QString ROLE,int SALAIRE,int GENRE,int TELEPHONE,int PASSWORD,int NOMBRE_RES)
{this->ID_PERSONNEL=ID_PERSONNEL;this->SALAIRE=SALAIRE;this->AGE=AGE;this->TELEPHONE=TELEPHONE;this->NOM=NOM;this->PRENOM=PRENOM;this->GRADE=GRADE;this->GENRE=GENRE;this->ROLE=ROLE;this->NOMBRE_RES=NOMBRE_RES;this->PASSWORD=PASSWORD;}
int PERSONNEL:: getID_PERSONNEL(){return ID_PERSONNEL;}
int PERSONNEL::getAGE(){return AGE;}
int PERSONNEL::getsSALAIRE(){return SALAIRE;}
int PERSONNEL::getTELEPHONE(){return TELEPHONE;}
int PERSONNEL::getPASSWORD(){return PASSWORD;}
int PERSONNEL::getNOMBRE_RES(){return NOMBRE_RES;}
QString PERSONNEL::getNOM(){return NOM;}
QString PERSONNEL::getPRENOM(){return PRENOM;}
QString PERSONNEL::getGRADE(){return GRADE;}
int PERSONNEL::getGENRE(){return GENRE;}
QString PERSONNEL::getROLE(){return ROLE;}
void PERSONNEL::setID_PERSONNEL(int ID_PERSONNEL){this->ID_PERSONNEL=ID_PERSONNEL;}
void PERSONNEL::setAGE(int AGE){this->AGE=AGE;}
void PERSONNEL::setSALAIRE(int SALAIRE){this->SALAIRE=SALAIRE;}
void PERSONNEL::setTELEPHONE(int TELEPHONE){this->TELEPHONE=TELEPHONE;}
void PERSONNEL::setPASSWORD(int PASSWORD){this->PASSWORD=PASSWORD;}
void PERSONNEL::setNOM(QString NOM){this->NOM=NOM;}
void PERSONNEL::setPRENOM(QString PRENOM){this->PRENOM=PRENOM;}
void PERSONNEL::setGRADE(QString GRADE){this->GRADE=GRADE;}
void PERSONNEL::setGENRE(int GENRE){this->GENRE=GENRE;}
void PERSONNEL::setNOMBRE_RES(int NOMBRE_RES){this->NOMBRE_RES=NOMBRE_RES;}
void PERSONNEL::setROLE(QString ROLE){this->ROLE=ROLE;}
bool PERSONNEL::ajouter()
{ //bool test=false;
    QSqlQuery query;
    QString ID_PERSONNEL_string=QString::number(ID_PERSONNEL);
    QString AGE_string=QString::number(AGE);
    QString SALAIRE_string=QString::number(SALAIRE);
     QString TELEPHONE_string=QString::number(TELEPHONE);
      QString PASSWORD_string=QString::number(PASSWORD);
       QString NOMBRE_RES_string=QString::number(NOMBRE_RES);
         query.prepare("INSERT INTO personnel (ID_PERSONNEL,NOM,PRENOM,AGE,GRADE,ROLE,SALAIRE,GENRE,TELEPHONE,PASSWORD,NOMBRE_RES) "
                       "VALUES (:ID_PERSONNEL, :NOM, :PRENOM, :AGE, :GRADE, :ROLE, :SALAIRE, :GENRE, :TELEPHONE,  :PASSWORD,  :NOMBRE_RES)");
         query.bindValue(":ID_PERSONNEL",ID_PERSONNEL_string);
         query.bindValue(":NOM",NOM);
         query.bindValue(":PRENOM",PRENOM);
         query.bindValue(":AGE",AGE_string);
         query.bindValue(":GRADE",GRADE);
         query.bindValue(":ROLE",ROLE);
         query.bindValue(":SALAIRE",SALAIRE_string);
         query.bindValue(":GENRE",GENRE);
         query.bindValue(":TELEPHONE",TELEPHONE_string);
          query.bindValue(":PASSWORD",PASSWORD_string);
          query.bindValue(":NOMBRE_RES",NOMBRE_RES_string);
    return   query.exec();
}
QSqlQueryModel* PERSONNEL::afficher()
{
   QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT * FROM personnel");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("Age"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("Grade"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("Role"));
   model->setHeaderData(6, Qt::Horizontal, QObject::tr("Salaire"));
   model->setHeaderData(7, Qt::Horizontal, QObject::tr("Genre"));
   model->setHeaderData(8, Qt::Horizontal, QObject::tr("Telephone"));
   model->setHeaderData(9, Qt::Horizontal, QObject::tr("Password"));
   model->setHeaderData(10, Qt::Horizontal, QObject::tr("Nombre_res"));
  return model;

}
bool PERSONNEL::supprimer(int ID_PERSONNEL)
{
    QSqlQuery query;
    query.prepare("Delete from personnel where ID_PERSONNEL=:ID_PERSONNEL");
    query.bindValue(0,ID_PERSONNEL);
   return   query.exec();
}
bool PERSONNEL::modifier(int ID_PERSONNEL)
{
    QSqlQuery query;
    query.prepare("UPDATE PERSONNEL SET NOM=:NOM,PRENOM=:PRENOM,AGE=:AGE,GRADE=:GRADE,ROLE=:ROLE,SALAIRE=:SALAIRE,GENRE=:GENRE,TELEPHONE=:TELEPHONE,PASSWORD=:PASSWORD,NOMBRE_RES:=NOMBRE_RES where ID_PERSONNEL=:ID_PERSONNEL");
    query.bindValue(":ID_PERSONNEL",ID_PERSONNEL);
    query.bindValue(":NOM",NOM);
    query.bindValue(":PRENOM",PRENOM);
    query.bindValue(":AGE",AGE);
    query.bindValue(":GRADE",GRADE);
    query.bindValue(":ROLE",ROLE);
    query.bindValue(":SALAIRE",SALAIRE);
    query.bindValue(":GENRE",GENRE);
    query.bindValue(":TELEPHONE",TELEPHONE);
    query.bindValue(":PASSWORD",PASSWORD);
    query.bindValue(":NOMBRE_RES",NOMBRE_RES);
    return    query.exec();

}
QSqlQueryModel* PERSONNEL::Trier(QString x)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    qDebug()<<x<<endl;

    if (x=="Identifiant")
            model->setQuery("select*  from PERSONNEL order by ID_PERSONNEL");
    else if (x=="Salaire")
        model->setQuery("select*  from PERSONNEL order by SALAIRE");
    else if (x=="Age")
        model->setQuery("select*  from PERSONNEL order by AGE");
    else if (x=="Default")
            model->setQuery("select * from PERSONNEL");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Age "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Grade"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Role"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Salaire"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Genre"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Password"));
    model->setHeaderData(10, Qt::Horizontal, QObject::tr("Nombre_res"));
        return model;
}
QSqlQueryModel*PERSONNEL::Rechercher(QString a)
{
    QSqlQueryModel * query=new QSqlQueryModel();
        query->setQuery("select * from PERSONNEL where (ID_PERSONNEL like '%"+a+"%' or PRENOM like '%"+a+"%' or AGE like '%"+a+"%' or ROLE like '%"+a+"%' or SALAIRE like '%"+a+"%' or TELEPHONE like '%"+a+"%'or PASSWORD like '%"+a+"%'or NOM like '%"+a+"%' or Genre like '%"+a+"%' or  GRADE like '%"+a+"%' ) ");

        query->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
        query->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
        query->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
        query->setHeaderData(3, Qt::Horizontal, QObject::tr("Age"));
        query->setHeaderData(4, Qt::Horizontal, QObject::tr("Grade"));
        query->setHeaderData(5, Qt::Horizontal, QObject::tr("Role"));
        query->setHeaderData(6, Qt::Horizontal, QObject::tr("Salaire"));
        query->setHeaderData(7, Qt::Horizontal, QObject::tr("Genre"));
        query->setHeaderData(8, Qt::Horizontal, QObject::tr("Telephone"));
        query->setHeaderData(9, Qt::Horizontal, QObject::tr("Password"));
        query->setHeaderData(10, Qt::Horizontal, QObject::tr("Nombre_res"));
        return    query;

}
QSqlQueryModel * PERSONNEL::setid()
 {

     QSqlQueryModel * model = new QSqlQueryModel();
     model->setQuery("select DISTINCT ID_PERSONNEL from PERSONNEL ");
     model->setHeaderData(0,Qt::Horizontal,"ID_PERSONNEL");

     return model;

 }
QString PERSONNEL::EDM()
{ QString n;
    QString nom;
            QSqlQuery qry("select MAX(NOMBRE_RES) from PERSONNEL ");
            while (qry.next())
            {n=qry.value(0).toString();}

            QSqlQuery qry1("select PRENOM from PERSONNEL where NOMBRE_RES ="+n);
            while (qry1.next())
            {nom=qry1.value(0).toString();}

            return nom;

}


