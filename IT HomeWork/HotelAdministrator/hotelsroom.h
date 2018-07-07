#ifndef OTELSROOM_H
#define OTELSROOM_H

#include <QApplication>
#include "consumer.h"

enum TypeRoom{SingleRoom,DoubleRoom};
class OtelsRoom
{
public:
    OtelsRoom();
    OtelsRoom(int ID,int Capacity,QDate DateEnd,int Consumer);
    int _ID;
    int _Capacity;
    QDate _DateEnd;
    int _Consumer;
    void exportSql();
};

#endif // OTELSROOM_H
