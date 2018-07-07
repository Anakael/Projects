#include "changeuser.h"
#include "ui_changeuser.h"

ChangeUser::ChangeUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeUser)
{
    ui->setupUi(this);
    ui->numberSpinBox->setMaximum(Otel::SingleRoomCount + Otel::DoubleRoomCount);
    ui->dateEdit->setMinimumDate(QDate::currentDate());
    connectAll();
    IsInited = false;
}

ChangeUser::~ChangeUser()
{
    delete ui;
}
QDialogButtonBox* ChangeUser::getButtonBox()
{
    return ui->buttonBox;
}
QPushButton* ChangeUser::getDeleteButton()
{
    return ui->deletePushButton;
}
QPushButton* ChangeUser::getChangeDateButton()
{
    return ui->ChangePushButton;
}
void ChangeUser::connectAll()
{
    connect(ui->deletePushButton,
            &QPushButton::clicked,
            this,
            &ChangeUser::deleteConsumer);
    connect(ui->ChangePushButton,
            &QPushButton::clicked,
            this,
            &ChangeUser::changeEndDateRoom);
    connect(ui->dateEdit,
            &QDateEdit::dateChanged,
            this,
            &ChangeUser::changeDateEdit);

}
void ChangeUser::deleteConsumer()
{
    if(!IsInited) getData();
    QSqlQuery SqlQuery;
    SqlQuery.exec("DELETE FROM Consumers WHERE ID=" + ID);
    SqlQuery.exec("UPDATE Rooms SET DateEnd=NULL, Consumer=NULL WHERE ID=" + ID);
    if (Capacity == 1)
        Otel::FreedSingleID->push_back(ID.toInt());
    else
        Otel::FreedDoubleID->push_back(ID.toInt());
}
void ChangeUser::changeEndDateRoom()
{
    if(!IsInited) getData();
    QSqlQuery SqlQuery;
    SqlQuery.exec("UPDATE Rooms SET DateEnd=" + ui->dateEdit->date().toString("dd.MM") + " WHERE ID=" + ID);

}
void ChangeUser::changeDateEdit()
{
    if(!IsInited) getData();
    int Delta = Capacity == 1? Otel::SingleRoomPrice : Otel::DoubleRoomPrice;
    Delta *= EndDate.daysTo(ui->dateEdit->date());
    ui->deltaPriceLabel->setText("Delta price: " + QString::number(Delta));
}
void ChangeUser::getData()
{
    QSqlQuery SqlQuery;
    ID = QString::number(ui->numberSpinBox->value());
    SqlQuery.exec("SELECT Capacity, DateEnd FROM Rooms WHERE ID=" + ID);
    SqlQuery.first();
    Capacity = SqlQuery.value(0).toInt();
    EndDate = QDate::fromString(SqlQuery.value(1).toString(),"dd.MM");
    EndDate = EndDate.addYears(QDate::currentDate().year() - 1900);
    IsInited = true;
}
