#include "consumer.h"
Consumer::Consumer(QString FullName, QString SerialNumber,int NumberRoom): _FullName(FullName),_SerialNumber(SerialNumber), _NumberRoom(NumberRoom)
{

}
Consumer::Consumer(){}
void Consumer::exportSQL()
{
    QSqlQuery SqlQuery;
    SqlQuery.prepare("INSERT INTO Consumers (Name,SerialNumber,NumberRoom) VALUES(?,?,?);");
    SqlQuery.addBindValue(_FullName);
    SqlQuery.addBindValue(_SerialNumber);
    SqlQuery.addBindValue(_NumberRoom);
    SqlQuery.exec();
}


