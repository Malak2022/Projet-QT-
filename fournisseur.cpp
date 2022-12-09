#include "fournisseur.h"

FOURNISSEUR::FOURNISSEUR()
{
  ID_FOURNISSEUR=1;
NOM="";
PRENOM = ""  ;
 TELEPHONE=1;
ADRESSE_MAIL = ""  ;
 PAYS = ""  ;
 VILLE = ""  ;
 DOMAINE = "";
 IMAGE = "";

}

bool FOURNISSEUR::ajouter()
{

    QSqlQuery query;

    query.prepare("INSERT INTO FOURINISSEURS (ID_FOURNISSEUR,NOM,PRENOM,TELEPHONE,ADRESSE_MAIL,PAYS,VILLE,DOMAINE,IMAGE ) "
                        "VALUES (:ID_FOURNISSEUR,:NOM,:PRENOM,:TELEPHONE,:ADRESSE_MAIL,:PAYS,:VILLE,:DOMAINE,:IMAGE )");


    query.bindValue(":ID_FOURNISSEUR",ID_FOURNISSEUR);
    query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM", PRENOM);
    query.bindValue(":TELEPHONE", TELEPHONE);
    query.bindValue(":ADRESSE_MAIL", ADRESSE_MAIL);
    query.bindValue(":PAYS",PAYS);
    query.bindValue(":VILLE", VILLE);
    query.bindValue(":DOMAINE", DOMAINE);
     query.bindValue(":IMAGE",IMAGE);
    return query.exec();

}





 FOURNISSEUR::FOURNISSEUR(int ID_FOURNISSEUR,QString NOM,QString PRENOM  ,int TELEPHONE,QString ADRESSE_MAIL ,QString PAYS,QString VILLE,QString DOMAINE,QString IMAGE )
{


  this->ID_FOURNISSEUR=ID_FOURNISSEUR;
  this->NOM=NOM;
  this->PRENOM =PRENOM  ;
   this->TELEPHONE  =TELEPHONE  ;
   this->ADRESSE_MAIL = ADRESSE_MAIL  ;
 this->PAYS =PAYS;
 this->VILLE =VILLE;
  this->DOMAINE =DOMAINE;
this->IMAGE =IMAGE;





}





 bool  FOURNISSEUR::supprimer(int idd)
 {

 QSqlQuery query;

 query.prepare("Delete from  FOURINISSEURS where ID_FOURNISSEUR = :id");
 query.bindValue(":id", idd);
 return query.exec();
 }





 QSqlQueryModel * FOURNISSEUR::afficher()
 {
   QSqlQueryModel * model = new QSqlQueryModel();
   model->setQuery("select * from FOURINISSEURS");
   model->setHeaderData(0,Qt::Horizontal,"ID_FOURNISSEUR");
   model->setHeaderData(1,Qt::Horizontal,"NOM");
   model->setHeaderData(2,Qt::Horizontal,"PRENOM");
   model->setHeaderData(3,Qt::Horizontal,"TELEPHONE");
    model->setHeaderData(4,Qt::Horizontal,"ADRESSE_MAIL");
     model->setHeaderData(5,Qt::Horizontal,"PAYS");
       model->setHeaderData(6,Qt::Horizontal,"VILLE");
         model->setHeaderData(7,Qt::Horizontal,"DOMAINE");
    return model;
 }
  QSqlQueryModel * FOURNISSEUR::afficher1(QString a,QString b)
  {
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from FOURINISSEURS  WHERE "+a+" LIKE '%"+b+"%'");
    model->setHeaderData(0,Qt::Horizontal,"ID_FOURNISSEUR");
    model->setHeaderData(1,Qt::Horizontal,"NOM");
    model->setHeaderData(2,Qt::Horizontal,"PRENOM");
    model->setHeaderData(3,Qt::Horizontal,"TELEPHONE");
     model->setHeaderData(4,Qt::Horizontal,"ADRESSE_MAIL");
      model->setHeaderData(5,Qt::Horizontal,"PAYS");
        model->setHeaderData(6,Qt::Horizontal,"VILLE");
          model->setHeaderData(7,Qt::Horizontal,"DOMAINE");
     return model;
  }
 QSqlQueryModel * FOURNISSEUR::afficher2(QString a)
  {
    QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from FOURINISSEURS order by "+a+" desc");
    model->setHeaderData(0,Qt::Horizontal,"ID_FOURNISSEUR");
    model->setHeaderData(1,Qt::Horizontal,"NOM");
    model->setHeaderData(2,Qt::Horizontal,"PRENOM");
    model->setHeaderData(3,Qt::Horizontal,"TELEPHONE");
     model->setHeaderData(4,Qt::Horizontal,"ADRESSE_MAIL");
      model->setHeaderData(5,Qt::Horizontal,"PAYS");
        model->setHeaderData(6,Qt::Horizontal,"VILLE");
          model->setHeaderData(7,Qt::Horizontal,"DOMAINE");
     return model;
}
 QSqlQueryModel * FOURNISSEUR::afficher3(QString a)
  {
    QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("select * from FOURINISSEURS order by "+a+" asc");
    model->setHeaderData(0,Qt::Horizontal,"ID_FOURNISSEUR");
    model->setHeaderData(1,Qt::Horizontal,"NOM");
    model->setHeaderData(2,Qt::Horizontal,"PRENOM");
    model->setHeaderData(3,Qt::Horizontal,"TELEPHONE");
     model->setHeaderData(4,Qt::Horizontal,"ADRESSE_MAIL");
      model->setHeaderData(5,Qt::Horizontal,"PAYS");
        model->setHeaderData(6,Qt::Horizontal,"VILLE");
          model->setHeaderData(7,Qt::Horizontal,"DOMAINE");
     return model;
}

