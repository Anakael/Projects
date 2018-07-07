#include "hotelsroom.h"

OtelsRoom::OtelsRoom(int ID,int Cacity,QDate DateEnd, int Consumer): _ID(ID),_Capacity(Cacity), _DateEnd(DateEnd), _Consumer(Consumer)
{
}
OtelsRoom::OtelsRoom()
{
}
void OtelsRoom::exportSql()
{
    QSqlQuery SqlQuery;
    SqlQuery.exec("UPDATE Rooms SET DateEnd=" + _DateEnd.toString("dd.MM") + ", Consumer=" + QString::number(_Consumer) + " WHERE ID=" + QString::number(_ID));
}
