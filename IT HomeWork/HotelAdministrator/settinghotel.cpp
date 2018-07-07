#include "settinghotel.h"
#include "ui_settinghotel.h"


SettingOtel::SettingOtel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingOtel)
{
    ui->setupUi(this);
    connect(ui->buttonBox,
            &QDialogButtonBox::accepted,
            this,
            &SettingOtel::onAcceptClicked
            );
}

SettingOtel::~SettingOtel()
{
    delete ui;
}
QDialogButtonBox* SettingOtel::getButtonBox()
{
    return ui->buttonBox;
}
void SettingOtel::onAcceptClicked()
{
    Otel::init(ui->singleRoomCount->value(),ui->doubleRoomCount->value(),ui->singleRoomPrice->value(),ui->dobleRoomPrice->value());
    QSqlQuery SqlQuery;
    SqlQuery.exec("CREATE TABLE `SettingHotel` (`Capacity`	INTEGER, `Count` INTEGER,`Price` INTEGER)");
    SqlQuery.exec("CREATE TABLE `Rooms` (`ID` INTEGER PRIMARY KEY AUTOINCREMENT, `Capacity` INTEGER,`DateEnd` TEXT, `Consumer` INTEGER)");
    SqlQuery.exec("CREATE TABLE `Consumers` (`ID` INTEGER PRIMARY KEY AUTOINCREMENT,`Name`	TEXT, `SerialNumber` TEXT,`NumberRoom` INTEGER)");
    SqlQuery.prepare("INSERT INTO SettingHotel (`Capacity`, `Count`, `Price`) VALUES (?,?,?)");
    SqlQuery.addBindValue(1);
    SqlQuery.addBindValue(Otel::SingleRoomCount);
    SqlQuery.addBindValue(Otel::SingleRoomPrice);
    SqlQuery.exec();

    SqlQuery.prepare("INSERT INTO SettingHotel(`Capacity`, `Count`, `Price`) VALUES (?,?,?)");
    SqlQuery.addBindValue(2);
    SqlQuery.addBindValue(Otel::DoubleRoomCount);
    SqlQuery.addBindValue(Otel::DoubleRoomPrice);
    SqlQuery.exec();

    Otel::db.transaction();
    QString st = "INSERT INTO Rooms (Capacity) SELECT 1";
    for (int i = 0; i < Otel::SingleRoomCount-1; ++i)
        st+= " UNION ALL SELECT 1 ";
    st+= ";";
    SqlQuery.exec(st);
    st = "INSERT INTO Rooms (Capacity) SELECT 2";
    for (int i = 0; i < Otel::DoubleRoomCount-1; ++i)
        st+= " UNION ALL SELECT 2 ";
    st+= ";";
    SqlQuery.exec(st);
    Otel::db.commit();
}
