#ifndef CONSUMER_H
#define CONSUMER_H

#include <QDate>
#include <QSqlQuery>
#include <QVariant>
class Consumer
{
public:
    Consumer(QString FullName,QString SerialNumber,int NumberRoom);
    Consumer();
    void exportSQL();
private:
    const QString _FullName;
    const QString _SerialNumber;
    const int _NumberRoom = 0;
};
#endif // CONSUMER_H
