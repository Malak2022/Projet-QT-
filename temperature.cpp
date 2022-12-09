#include "temperature.h"
#include "arduino.h"
TEMPERATURE::TEMPERATURE()
{

}
bool TEMPERATURE::tempajout(){



    QSqlQuery query;
       // QString res = QString::number(TEMP);
    arduino A ;
    temp= A.read_from_arduino();
        query.prepare("insert into TEMPERATURE(KEY,TEMP) VALUES  ( 1,  temp)");

        query.bindValue(":TEMP",temp);
 query.bindValue(":KEY",1);

        return query.exec();
}
