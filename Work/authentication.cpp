#include "authentication.h"
#include "ui_authentication.h"

#include <QDebug>

Authentication::Authentication(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Authentication)
{
    ui->setupUi(this);
    connect(this,
            &QDialog::accepted,
            this,
            &Authentication::authAndInitDBConnecdtion);
}

Authentication::~Authentication()
{
    delete ui;
}
void Authentication::authAndInitDBConnecdtion()
{
    Admin::DataBase = QSqlDatabase::addDatabase("QMYSQL");
    QFile fileHostName("hostname.txt");
    if (!fileHostName.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&fileHostName);
    QString hostname = in.readLine();
    Admin::DataBase.setHostName(hostname);
    Admin::DataBase.setDatabaseName("main_data_base");
    Admin::DataBase.setUserName(ui->loginLineEdit->text());
    Admin::DataBase.setPassword(ui->passwordLineEdit->text());
    if(Admin::DataBase.open())
    {
        MySqlQueries::getAllPrice(Admin::PriceDeliveryForTheArea, Admin::PriceDeliveryForTheTypeDelivery,
                                  Admin::PriceForTheTypeMaterial,Admin::Discounts);
        Admin::IsAdmin = ui->loginLineEdit->text() == "root";
        emit successAuth();
    }
}
