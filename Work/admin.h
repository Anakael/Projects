#ifndef ADMINCONFIGURATION_H
#define ADMINCONFIGURATION_H

#include <QSqlDatabase>
#include <QStringList>

class Admin
{
public:
    static int PriceDeliveryForTheArea[3];
    static int PriceDeliveryForTheTypeDelivery[4];
    static int PriceForTheTypeMaterial[3];
    static int Discounts[3];
    static QSqlDatabase DataBase;
    static bool IsAdmin;
    static const QStringList CompositionList;
    static const QStringList TypeSizeList;
    static const QStringList AreaList;
};

#endif // ADMINCONFIGURATION_H
