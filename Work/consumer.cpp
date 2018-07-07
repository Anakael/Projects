#include "consumer.h"
Consumer::Consumer(){}
Consumer::Consumer(int _id,QString _name,QString _number, QString _address, Area _area, bool _additionalDiscount):
    ID(_id),
    name(_name),
    number(_number),
    address(_address),
    area(_area),
    additionalDiscount(_additionalDiscount)
{}
