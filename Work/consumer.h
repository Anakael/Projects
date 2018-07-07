#ifndef CONSUMER_H
#define CONSUMER_H

#include <QString>

class Consumer
{
public:
    int ID;
    QString name;
    QString number;
    QString address;
    enum Area { Moskovskiy, Kirovskiy, Krasnoselskiy} area;
    bool additionalDiscount;
    Consumer();
    Consumer(int _id,QString _name,QString _number, QString _address, Area _area, bool _additionalDiscount);
};

#endif // CONSUMER_H
