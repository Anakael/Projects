#include "mysqlqueries.h"

void MySqlQueries::changeStatus(int ID,int status, QDate date)
{
    QSqlQuery query;
    QString str("UPDATE Applications SET Applications.Status = "
               + QString::number(status + 1)
               + ", Last_Update_Date = '"
               + date.toString("yyyy-MM-dd")
               + "' WHERE Applications.ID = "
               + QString::number(ID));
    query.exec(str);
}
int MySqlQueries::getCountRequestByID(int IDConsumer)
{
    QSqlQuery query;
    query.exec("SELECT COUNT(*) FROM Applications WHERE Applications.ID_Consumers = "
               + QString::number(IDConsumer));
    query.next();
    return query.value(0).toInt();
}
void MySqlQueries::changeRequestSql(Request& request)
{

    Admin::DataBase.transaction();
    QSqlQuery query;
    query.exec("SET NAMES cp1251");
    QString queryString("UPDATE Consumers SET Consumers.Name = '" + request.consumer.name +
               "', Consumers.Phone_Number = '" + request.consumer.number +
               "', Consumers.Area = " + QString::number(request.consumer.area + 1) +
               ", Consumers.Address = '" + request.consumer.address +
               "', Consumers.Additional_Discount = " + QString::number(request.consumer.additionalDiscount) +
               " WHERE Consumers.ID = " + QString::number(request.consumer.ID));
    query.exec(queryString);
    queryString = "UPDATE Applications SET Applications.TypeDelivery = " + QString::number(request.typeDelivery + 1) +
                  ", Applications.Price_For_Work = " + QString::number(request.priceForWork) +
                  ", Applications.Price_For_Delivery = " + QString::number(request.priceForDelivery) +
                  ", Applications.Price_Summary =  " + QString::number(request.priceSummary) +
                  " WHERE Applications.ID = " + QString::number(request.ID);
    query.exec(queryString);
    for(auto &it: request.materials)
    {
        queryString = "UPDATE Materials SET Materials.Material = " + QString::number(it->composition + 1) +
                      ", Materials.Size = " + QString::number(it->size) +
                      " WHERE Materials.ID_Application = " + QString::number(request.ID);
        query.exec(queryString);
    }
    Admin::DataBase.commit();
}
void MySqlQueries::addNewRequestSql(Request& request)
{
    Admin::DataBase.transaction();
    QSqlQuery query;
    if(request.consumer.ID == 0)
    {
        query.exec("SET NAMES cp1251");
        query.prepare("INSERT INTO Consumers (Consumers.Name, Consumers.Phone_Number, Consumers.Area,"
                      " Consumers.Address, Consumers.Additional_Discount) VALUES (?,?,?,?,?)");
        query.addBindValue(request.consumer.name);
        query.addBindValue(request.consumer.number);
        query.addBindValue(request.consumer.area + 1);
        query.addBindValue(request.consumer.address);
        query.addBindValue(request.consumer.additionalDiscount);
        query.exec();
        query.exec("SELECT last_insert_id()");
        query.next();
        request.consumer.ID = query.value(0).toInt();
    }
    query.prepare("INSERT INTO Applications (Applications.TypeDelivery, Applications.Price_For_Work,"
                  "Applications.Price_For_Delivery, Applications.Price_Summary, Applications.ID_Consumers,"
                  "Applications.Order_Date, Applications.Last_Update_Date) VALUES (?,?,?,?,?,?,?)" );
    query.addBindValue(request.typeDelivery + 1);
    query.addBindValue(request.priceForWork);
    query.addBindValue(request.priceForDelivery);
    query.addBindValue(request.priceSummary);
    query.addBindValue(request.consumer.ID);
    query.addBindValue(request.orderDate.toString("yyyy-MM-dd"));
    query.addBindValue(request.lastUpdateDate.toString("yyyy-MM-dd"));
    query.exec();
    query.exec("SELECT last_insert_id()");
    query.next();
    request.ID = query.value(0).toInt();
    for(auto &it: request.materials)
    {
        query.prepare("INSERT INTO Materials (Materials.Material, Materials.Size, Materials.ID_Application) VALUES (?,?,?)");
        query.addBindValue(it->composition + 1);
        query.addBindValue(it->size);
        query.addBindValue(request.ID);
        query.exec();
    }
    Admin::DataBase.commit();
}
int MySqlQueries::getIDConsumer(QString number)
{
    QSqlQuery SqlQuery;
    SqlQuery.exec("SELECT Consumers.ID FROM Consumers WHERE Consumers.Phone_Number = " + number);
    if(SqlQuery.size() != 0)
    {
        SqlQuery.next();
        return SqlQuery.value(0).toInt();
    }
    else
    {
        return 0;
    }
}
void MySqlQueries::getDataFromDB(QTableView& table)
{
    QSqlQuery query;
    QSqlQueryModel* model = new QSqlQueryModel(table.parentWidget());
    query.exec("SET NAMES cp1251");
    query.exec("SELECT Applications.ID, Consumers.Name AS 'Имя', Consumers.Phone_Number AS 'Номер', "
               "DATE_FORMAT(Applications.Last_Update_Date, '%d.%m.%Y') AS 'Дата изменения'"
               " FROM Consumers JOIN Applications ON (Consumers.ID = Applications.ID_Consumers)"
               "ORDER BY 'Дата изменения'");
    model->setQuery(query);
    table.setModel(model);
}
Request MySqlQueries::getRequest(int IDRequest)
{
    QSqlQuery query;
    query.exec("SET NAMES cp1251");
    query.exec("SELECT Materials.Material+0, Materials.Size "
               "FROM `Materials` WHERE Materials.ID_Application = "
               + QString::number(IDRequest));
    QVector<Material*> materials;
    while(query.next())
    {
        materials.push_back(new Material(static_cast<Material::Composition>(query.value(0).toInt() - 1),
                            query.value(1).toInt()));
    }
    int IDConsumer;
    query.exec("SELECT Applications.ID_Consumers "
               "FROM Applications WHERE Applications.ID = "
                + QString::number(IDRequest));
    query.next();
    IDConsumer = query.value(0).toInt();
    query.exec("SELECT Consumers.Name, Consumers.Phone_Number, "
               "Consumers.Address, Consumers.Area+0, Consumers.Additional_Discount "
               "FROM Consumers WHERE Consumers.ID = "
               + QString::number(IDConsumer));
    query.next();
    Consumer consumer(IDConsumer,
                      query.value(0).toString(),
                      query.value(1).toString(),
                      query.value(2).toString(),
                      static_cast<Consumer::Area>(query.value(3).toInt() - 1),
                      query.value(4).toBool());
    query.exec("SELECT Applications.TypeDelivery+0, Applications.Price_For_Work, "
               "Applications.Price_For_Delivery, Applications.Price_Summary, "
               "Applications.Order_Date, Applications.Last_Update_Date, Applications.Status+0 "
               "FROM Applications WHERE Applications.ID = "
                + QString::number(IDRequest));
    query.next();
    return Request(consumer,
                   materials,
                   static_cast<Request::TypeDelivery>(query.value(0).toInt() - 1),
                   query.value(1).toInt(),
                   query.value(2).toInt(),
                   query.value(3).toInt(),
                   query.value(4).toDate(),
                   query.value(5).toDate(),
                   static_cast<Request::Status>(query.value(6).toInt() - 1),
                   IDRequest);
}
void MySqlQueries::deleteRequest(int IDRequest)
{
    Admin::DataBase.transaction();
    QSqlQuery query;
    QString str(("DELETE FROM Applications WHERE Applications.ID = " + QString::number(IDRequest)));
    query.exec(str);
    Admin::DataBase.commit();
}
void MySqlQueries::getAllPrice(int areaDelivery[3], int typeDelivery[4], int materialPrice[3], int discounts[3])
{
    QSqlQuery query;
    query.exec("SELECT Config_AreaDelivery_Price.Price FROM Config_AreaDelivery_Price");
    for (int i = 0; i < 3;i++)
    {
        query.next();
        areaDelivery[i] = query.value(0).toInt();
    }
    query.exec("SELECT Config_TypeDelivery_Price.Price FROM Config_TypeDelivery_Price");
    for (int i = 0; i < 4;i++)
    {
        query.next();
        typeDelivery[i] = query.value(0).toInt();
    }
    query.exec("SELECT Config_Material_Price.Price FROM Config_Material_Price");
    for (int i = 0; i < 3;i++)
    {
        query.next();
        materialPrice[i] = query.value(0).toInt();
    }
    query.exec("SELECT Config_Discount.Value FROM Config_Discount");
    query.next();
    discounts[0] = query.value(0).toInt();
    query.next();
    discounts[2] = query.value(0).toInt();
    query.next();
    discounts[1] = query.value(0).toInt();
}
void MySqlQueries::searchDataFromDB(QTableView& table,const QString& searchString)
{
    QSqlQuery query;
    QSqlQueryModel* model = new QSqlQueryModel(table.parentWidget());
    QString dateString = searchString;
    if(searchString.contains('.'))
    {
        QStringList dateList = searchString.split('.', QString::SkipEmptyParts);
        if(dateList.count() == 1)
        {
            dateString = dateList[0];
        }
        else
            if(dateList.count() == 2)
            {
                dateList[1] += dateList[1].count() == 1? "%" : "";
                dateString = dateList[1] + '-' + dateList[0];
            }
            else
                if(dateList.count() == 3)
                {
                    dateList[2] += dateList[2].count() < 4? "%" : "";
                    dateString = dateList[2] + '-' + dateList[1] + '-' + dateList[0];
                }
    }
    query.exec("SET NAMES cp1251");
    QString queryString = "SELECT Applications.ID, Consumers.Name AS 'Имя', Consumers.Phone_Number AS 'Номер', "
            "DATE_FORMAT(Applications.Last_Update_Date, '%d.%m.%Y') AS 'Дата изменения', "
            "DATE_FORMAT(Applications.Order_Date, '%d.%m.%Y') AS 'Дата поступления' "
            "FROM Consumers JOIN Applications ON (Consumers.ID = Applications.ID_Consumers) "
            "WHERE Consumers.Name LIKE '%" + searchString + "%\' OR Consumers.Phone_Number LIKE '%" + searchString + "%' "
            "OR Applications.Last_Update_Date LIKE '%" + dateString + "%' OR Applications.Order_Date LIKE '%" + dateString + "%' "
            "ORDER BY 'Дата изменения'";
    query.exec(queryString);
    model->setQuery(query);
    table.setModel(model);
}
