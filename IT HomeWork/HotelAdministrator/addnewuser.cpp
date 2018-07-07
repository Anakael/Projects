#include "addnewuser.h"
#include "ui_addnewuser.h"
#include <QDateEdit>
#include <qregexp.h>

AddNewUser::AddNewUser(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::AddNewUser)
{
    ui->setupUi(this);
    init();
    connectAll();
}

AddNewUser::~AddNewUser()
{
    delete ui;
}
QDialogButtonBox* AddNewUser::getButtonBox()
{
    return ui->buttonBox;
}
void AddNewUser::onAcceptClicked()
{
    int Capacity = ui->typeBox->currentIndex() ? 2 : 1;
    if (
        (ui->nameEdit->text() != "" && ui->serialNumberEdit->text() != "")
        && ((Capacity == 1 && !Otel::FreedSingleID->empty()) || (Capacity == 2 && !Otel::FreedDoubleID->empty())))
    {
        Otel::addNewConsumer(ui->nameEdit->text(), ui->serialNumberEdit->text(), Capacity, ui->endDateEdit->date());
        emit sucAdd();
    }
}
void AddNewUser::init()
{
    QRegExp exp("[A-ZА-Я][a-zA-Zа-яА-Я]{1,32}");
    ui->nameEdit->setValidator(new QRegExpValidator(exp, this));
    ui->endDateEdit->setMinimumDate(QDate::currentDate().addDays(1));
    onPriceChanged();
}
void AddNewUser::onPriceChanged()
{
    int Price = ui->typeBox->currentIndex() == 0 ? Otel::SingleRoomPrice : Otel::DoubleRoomPrice;
    Price *= QDate::currentDate().daysTo(ui->endDateEdit->date());
    ui->resultPriceLabel->setText("Result price: " + QString::number(Price));
}
void AddNewUser::connectAll()
{
    connect(ui->endDateEdit,
        &QDateEdit::dateChanged,
        this,
        &AddNewUser::changed);
    connect(ui->typeBox,
        &QComboBox::currentTextChanged,
        this,
        &AddNewUser::changed);
    connect(this,
        &AddNewUser::changed,
        this,
        &AddNewUser::onPriceChanged);
    connect(ui->buttonBox,
        &QDialogButtonBox::accepted,
        this,
        &AddNewUser::onAcceptClicked);
}
