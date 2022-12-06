#ifndef PERSONNEL_H
#define PERSONNEL_H
#include <QString>
#include <QSqlQueryModel>
class PERSONNEL
{
public:
    PERSONNEL();
    PERSONNEL(int,QString,QString,int,QString,QString,int,int,int,int,int);
    int getID_PERSONNEL();
    int getAGE();
    int getsSALAIRE();
    int getTELEPHONE();
    int getPASSWORD();
    int getNOMBRE_RES();
    QString getNOM();
    QString getPRENOM();
    QString getGRADE();
    int getGENRE();
    QString getROLE();
    void setID_PERSONNEL(int);
    void setAGE(int);
    void setSALAIRE(int);
    void setTELEPHONE(int);
    void setPASSWORD(int);
    void setNOM(QString);
    void setPRENOM(QString);
    void setGRADE(QString);
    void setGENRE(int);
    void setROLE(QString);
    void setNOMBRE_RES(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int);
    QString EDM();
    QSqlQueryModel* Trier(QString);
    QSqlQueryModel* Rechercher(QString);
     QSqlQueryModel* setid();
     int login(QString,QString);
private:
    int ID_PERSONNEL,AGE,SALAIRE,TELEPHONE,PASSWORD,GENRE,NOMBRE_RES;
    QString NOM,PRENOM,GRADE,ROLE;
};

#endif // PERSONNEL_H
