#include "request.h"
Request::Request(){}
Request::Request(const Request& request){}
Request::Request(Consumer& _consumer,
                 QVector<Material*>& _materials,
                 TypeDelivery _typedel,
                 int _priceForWork,
                 int _priceForDelivery,
                 int _priceSummary,
                 QDate _orderDate,
                 QDate _lastUpdateDate,
                 Status _status,
                 int _ID):
    consumer(_consumer),
    materials(_materials),
    typeDelivery(_typedel),
    priceForWork(_priceForWork),
    priceForDelivery(_priceForDelivery),
    priceSummary(_priceSummary),
    orderDate(_orderDate),
    lastUpdateDate(_lastUpdateDate),
    status(_status),
    ID(_ID)
{}
