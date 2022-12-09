#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H



#include <QObject>
#include <QWidget>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class FOURNISSEUR
{
public:
    FOURNISSEUR();
    FOURNISSEUR(int ID_FOURNISSEUR,QString NOM,QString PRENOM  ,int TELEPHONE,QString ADRESSE_MAIL ,QString PAYS,QString VILLE,QString DOMAINE,QString IMAGE);
    bool ajouter();
    bool supprimer(int);
    bool modifier(int ID_FOURNISSEUR,QString NOM,QString PRENOM  ,int TELEPHONE,QString ADRESSE_MAIL ,QString PAYS,QString VILLE,QString DOMAINE);
  QSqlQueryModel   *afficher();
  QSqlQueryModel *afficher1(QString a,QString b);
  QSqlQueryModel * afficher2(QString a);
   QSqlQueryModel * afficher3(QString a);
private:
    QString    NOM,   PRENOM ,      ADRESSE_MAIL  ,     PAYS, VILLE ,   DOMAINE ,IMAGE  ;
int ID_FOURNISSEUR;
int TELEPHONE;

};


#endif // FOURNISSEUR_H
