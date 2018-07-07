#ifndef MYSQLQUERIES_H
#define MYSQLQUERIES_H

#include "admin.h"
#include "request.h"

#include <QSqlQuery>
#include <QVariant>
#include <QSqlQueryModel>
#include <QTableView>

class MySqlQueries
{
public:
    static void addNewRequestSql(Request&);
    static void changeRequestSql(Request&);
    static int getIDConsumer(QString);
    static int getCountRequestByID(int);
    static void getDataFromDB(QTableView&);
    static void searchDataFromDB(QTableView&,const QString&);
    static Request getRequest(int);
    static void changeStatus(int ID, int status, QDate date);
    static void deleteRequest(int);
    static void getAllPrice(int areaDelivery[3], int typeDelivery[4], int materialPrice[3], int discounts[3]);
};

#endif // MYSQLQUERIES_H
