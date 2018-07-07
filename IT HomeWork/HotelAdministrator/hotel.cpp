#include "hotel.h"

int Otel::SingleRoomCount = 0;
int Otel::DoubleRoomCount = 0;
int Otel::SingleRoomPrice = 0;
int Otel::DoubleRoomPrice = 0;
QSqlDatabase Otel::db;
QVector<int>* Otel::FreedSingleID;
QVector<int>* Otel::FreedDoubleID;
const QString Otel::NameDB = "HotelDB.sql";
void Otel::init(int SingleRoomCount,int DoubleRoomCount,int SingleRoomPrice,int DoubleRoomPrice)
{
    Otel::SingleRoomCount = SingleRoomCount;
    Otel::DoubleRoomCount = DoubleRoomCount;
    Otel::SingleRoomPrice = SingleRoomPrice;
    Otel::DoubleRoomPrice = DoubleRoomPrice;
    FreedSingleID = new QVector<int>(SingleRoomCount);
    int inc = 1;
    for (auto it = FreedSingleID->begin(); it != FreedSingleID->end(); ++it)
    {
        *it = inc++;
    }
    inc = SingleRoomCount + 1;
    FreedDoubleID = new QVector<int>(DoubleRoomCount);
    for (auto it = FreedDoubleID->begin(); it != FreedDoubleID->end(); ++it)
    {
        *it = inc++;
    }
}
void Otel::addNewConsumer(QString FullName, QString SerialNumber,int Capacity,QDate EndDate)
{
    int CurrentID;
    if(Capacity == 1)
    {
        CurrentID = FreedSingleID->front();
        FreedSingleID->pop_front();
    }
    else
    {
        CurrentID = FreedDoubleID->front();
        FreedDoubleID->pop_front();
    }

    Consumer* CurConsumer = new Consumer(FullName,SerialNumber,CurrentID);
    CurConsumer->exportSQL();
    QSqlQuery query;    
    query.exec("SELECT ID FROM Rooms WHERE ID=last_insert_rowid()");
    query.next();
    OtelsRoom* Room = new OtelsRoom(CurrentID,Capacity,EndDate,query.value(0).toInt());
    Room->exportSql();
    delete CurConsumer;
    delete Room;
}

