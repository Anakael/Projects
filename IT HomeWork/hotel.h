#ifndef OTEL_H
#define OTEL_H

#include <consumer.h>
#include <hotelsroom.h>
#include <addnewuser.h>

#include <QSqlDatabase>
#include <QSqlQuery>

class Otel
{
public:
    static QVector<int>* FreedSingleID;
    static QVector<int>* FreedDoubleID;
    static int SingleRoomCount;
    static int DoubleRoomCount;
    static int SingleRoomPrice;
    static int DoubleRoomPrice;
    static void init(int SingleRoomCount,int DoubleRoomCount,int SingleRoomPrice,int DoubleRoomPrice);
    static void addNewConsumer(QString FullName,QString SerialNumber,int Capacity,QDate EndDate);
    static QSqlDatabase db;
    static const QString NameDB;
};

#endif // OTEL_H
