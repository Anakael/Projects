#include "admin.h"
int Admin::PriceDeliveryForTheArea[3] = {0,0,0};
int Admin::PriceDeliveryForTheTypeDelivery[4] = {4,5,6,7};
int Admin::PriceForTheTypeMaterial[3] = {100,300,200};
int Admin::Discounts[3] = {10,30,5};
QSqlDatabase Admin::DataBase;
bool Admin::IsAdmin;
const QStringList Admin::CompositionList {"Синтетика","Шерсть","Синтетика + Шерсть"};
const QStringList Admin::TypeSizeList {"Д/Ш","М^2"};
const QStringList Admin::AreaList {"Московский","Кировский", "Красносельский"};

