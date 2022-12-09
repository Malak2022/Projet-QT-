#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
class TEMPERATURE
{private:
    QString temp;
public:
    TEMPERATURE();
    bool tempajout();
};

#endif // TEMPERATURE_H
