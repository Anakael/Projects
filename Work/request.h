#ifndef REQUEST_H
#define REQUEST_H

#include "material.h"
#include "consumer.h"

#include <QDate>

class Request
{
public:
    int ID;
    Consumer consumer;
    QVector<Material*> materials;
    enum TypeDelivery { SelfDrive_IndependentExport,
              DeliverytotheWorkshop_IndependentExport,
              SelfDelivery_DeliverytotheHouse,
              DeliveryintheShop_DeliverytotheHouse} typeDelivery;
    int priceForWork;
    int priceForDelivery;
    int priceSummary;
    QDate orderDate;
    QDate lastUpdateDate;
    enum Status { WaitingforDeliverytotheShop, DeliveryToTheShop, InWork, WaitingfordeliverytoCustomer} status;
    Request(Consumer& _consumer,
            QVector<Material*>& _materials,
            TypeDelivery _typedel,
            int _priceForWork,
            int _priceForDelivery,
            int _priceSummary,
            QDate _orderDate = QDate::currentDate(),
            QDate _lastUpdateDate = QDate::currentDate(),
            Status _status = static_cast<Status>(0),
            int ID = 0);
    Request(const Request&);
    Request();
};

#endif // REQUEST_H
