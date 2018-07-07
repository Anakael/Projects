#include "status.h"
#include "ui_status.h"

#include <QStringListModel>
#include <QSqlDatabase>

Status::Status(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Status)
{
    ui->setupUi(this);
    ui->singleRoomCountLabel->setText("Single room count: " + QString::number(Otel::FreedSingleID->size()));
    ui->doubleRoomCountLabel->setText("Double room count: " + QString::number(Otel::FreedDoubleID->size()));
    std::fstream fs("LastCheck.dat",std::ios_base::binary| std::ios_base::in);
    bool NeedCheck = true;
    QDate LastCheck;
    fs.read((char*)&LastCheck,sizeof(LastCheck));
    if(fs)
        NeedCheck = LastCheck.daysTo(QDate::currentDate()) >= 1;
    if(NeedCheck)
    {
        fs.open("LastCheck.dat",std::ios_base::binary | std::ios_base::out | std::ios_base::trunc);
        QSqlQueryModel* Model = new QSqlQueryModel(this);
        QSqlQuery SqlQury;
        SqlQury.exec("SELECT ID FROM Rooms WHERE DateEnd <=" + QDate::currentDate().toString("dd.MM"));
        Model->setQuery(SqlQury);
        ui->listView->setModel(Model);
        LastCheck = QDate::currentDate();
        fs.write((char*)&LastCheck,sizeof(LastCheck));
    }
    fs.close();
}

Status::~Status()
{
    delete ui;
}
QDialogButtonBox* Status::getButtonBox()
{
    return ui->buttonBox;
}
