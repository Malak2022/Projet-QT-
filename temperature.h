#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include <string>
#include "connection.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>

class TEMPERATURE
{private:
    QString TEMP;
public:
    TEMPERATURE();
    TEMPERATURE(QByteArray);
    bool tempajout();
};

#endif // TEMPERATURE_H
