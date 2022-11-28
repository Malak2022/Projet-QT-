#include "temperature.h"
#include "arduino.h"
TEMPERATURE::TEMPERATURE()
{   TEMP="0";

}
TEMPERATURE::TEMPERATURE(QByteArray a)
{   TEMP=a;

}


bool TEMPERATURE::tempajout(){
    QSqlQuery query;
   // QString res = QString::number(TEMP);
     //data=A.read_from_arduino();
    arduino A;
    TEMP=A.read_from_arduino();
    query.prepare("insert into TEMPERATURE TEMP=:TEMP");

    //query.bindValue(":TEMP",TEMP);


    return query.exec();
}
