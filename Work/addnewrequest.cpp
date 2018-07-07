#include "addnewrequest.h"
#include "ui_addnewrequest.h"
#include <QDebug>
#include <cmath>

AddNewRequest::AddNewRequest(QWidget* parent, bool _isNotNew, int _IDRequest)
  : QDialog(parent)
  , isNotNew(_isNotNew)
  , IDRequest(_IDRequest)
  , ui(new Ui::AddNewRequest)
{
    ui->setupUi(this);
    init();
    connectAll();
}
AddNewRequest::~AddNewRequest()
{
    while (Materials.size()) {
	delete Materials[0];
	Materials[0] = nullptr;
	Materials.remove(0);
    }
    delete ui;
}
void
AddNewRequest::init()
{
    QRegExp ExpForName(
      "[A-ZА-ЯЁ][a-zа-яё]{1,32}([ -][A-ZА-ЯЁ][a-zа-яё]{1,32})*");
    ui->nameEdit->setValidator(new QRegExpValidator(ExpForName, this));
    QRegExp ExpForNumber("^[+7][0-9]{11}");
    ui->numberEdit->setValidator(new QRegExpValidator(ExpForNumber, this));
    ItemLayout = new QVBoxLayout(this);
    ui->itemsScrollAreaWidgetContents->setLayout(ItemLayout);
    ui->standartDiscountLabel->setText(QString::number(Admin::Discounts[0]));
    changeDeliveryPrice();
    // ui->driverDepartureDateEdit->setMinimumDate(QDate::currentDate());
    if (isNotNew) {
	Request request = MySqlQueries::getRequest(IDRequest);
	IDConsumer = request.consumer.ID;
	ui->nameEdit->setText(request.consumer.name);
	ui->numberEdit->setText(request.consumer.number);
	ui->countLabel->setText(QString::number(
	  MySqlQueries::getCountRequestByID(request.consumer.ID)));
	ui->areaComboBox->setCurrentIndex(request.consumer.area);
	ui->addressLineEdit->setText(request.consumer.address);
	ui->typeDeliveryComboBox->setCurrentIndex(request.typeDelivery);
	ui->workPriceLabel->setText(QString::number(request.priceForWork));
	ui->deliveryPriceLabel->setText(
	  QString::number(request.priceForDelivery));
	ui->summaryPriceLabel->setText(QString::number(request.priceSummary));
	for (auto& it : request.materials)
	    addNewItems(true, it);
    }
}
void
AddNewRequest::addNewItems(bool isNotNew, Material* CurrentMaterial)
{
    Materials.push_back(CurrentMaterial);
    QFormLayout* fl = new QFormLayout(ItemLayout->widget());
    QComboBox* cbt = new QComboBox(fl->widget());
    cbt->addItems(Admin::CompositionList);
    if (isNotNew) {
	cbt->setCurrentIndex(CurrentMaterial->composition);
    } else {
	cbt->setCurrentIndex(0);
	CurrentMaterial->composition =
	  static_cast<Material::Composition>(cbt->currentIndex());
    }
    connect(
      cbt,
      static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
      this,
      [=](int index) mutable {
	  CurrentMaterial->composition =
	    static_cast<Material::Composition>(index);
	  changeWorkPrice();
      });
    fl->addRow("Состав", cbt);
    QHBoxLayout* hl = new QHBoxLayout(fl->widget());
    QComboBox* cbs = new QComboBox(hl->widget());
    cbs->addItems(Admin::TypeSizeList);
    connect(
      cbs,
      static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
      this,
      [=]() mutable {
	  AddNewRequest::changeTypeSize(hl, CurrentMaterial, isNotNew);
	  changeWorkPrice();
      });
    cbs->setCurrentIndex(0);
    if (Materials.size() >= 3) {
	ui->for3ItemsDiscountLabel->setText(
	  QString::number(Admin::Discounts[1]));
	changeSummaryDiscount();
    }
    hl->addWidget(cbs);
    QLineEdit* leL = new QLineEdit(hl->widget());
    QLineEdit* leW = new QLineEdit(hl->widget());
    lineEdits.push_back(leL);
    lineEdits.push_back(leW);
    QRegExp ExpForSize("[1-9][0-9]*");
    leL->setValidator(new QRegExpValidator(ExpForSize, this));
    leW->setValidator(new QRegExpValidator(ExpForSize, this));
    connect(leL, &QLineEdit::textEdited, this, [=]() mutable {
	if (leL->text() != "" && leW->text() != "") {
	    double size = leL->text().toInt() * leW->text().toInt();
	    size = ceil(size / 10000);
	    CurrentMaterial->size = int(size);
	    changeWorkPrice();
	}
    });
    connect(leW, &QLineEdit::textEdited, this, [=]() mutable {
	if (leL->text() != "" && leW->text() != "") {
	    double size = leL->text().toInt() * leW->text().toInt();
	    size = ceil(size / 10000);
	    CurrentMaterial->size = int(size);
	    changeWorkPrice();
	}
    });
    hl->addWidget(leL);
    hl->addWidget(leW);
    fl->addRow("Размер", hl);
    if (isNotNew)
	cbs->setCurrentIndex(1);
    QPushButton* delb = new QPushButton("Удалить", fl->widget());
    connect(delb, &QPushButton::clicked, this, [=]() mutable {
	clearLayout(fl, true);
	Materials.removeOne(CurrentMaterial);
	delete CurrentMaterial;
	if (Materials.size() < 3) {
	    ui->for3ItemsDiscountLabel->setText("0");
	    changeSummaryDiscount();
	}
	changeWorkPrice();
    });
    fl->addWidget(delb);
    ItemLayout->addLayout(fl);
}
void
AddNewRequest::changeTypeSize(QHBoxLayout* hl,
			      Material* CurrentMaterial,
			      bool isNotNew)
{
    QComboBox* cb = static_cast<QComboBox*>(hl->itemAt(0)->widget());
    QRegExp ExpForSize("[1-9][0-9]*");
    if (!cb->currentIndex()) {
	QLineEdit* leL = static_cast<QLineEdit*>(hl->itemAt(1)->widget());
	QLineEdit* leW = new QLineEdit(hl->widget());
	lineEdits.push_back(leL);
	lineEdits.push_back(leW);
	leL->setValidator(new QRegExpValidator(ExpForSize, this));
	leW->setValidator(new QRegExpValidator(ExpForSize, this));
	connect(leW, &QLineEdit::textEdited, this, [=]() mutable {
	    if (leW->text() != "" && leL->text() != "") {
		double size = leL->text().toInt() * leW->text().toInt();
		size = ceil(size / 10000);
		CurrentMaterial->size = int(size);
		changeWorkPrice();
	    }
	});
	hl->addWidget(leW);
    } else {
	auto item = hl->takeAt(2);
	lineEdits.removeOne(static_cast<QLineEdit*>(item->widget()));
	delete item->widget();
	delete item;
	QLineEdit* leS = static_cast<QLineEdit*>(hl->itemAt(1)->widget());
	lineEdits.push_back(leS);
	leS->setValidator(new QRegExpValidator(ExpForSize, this));
	disconnect(leS, 0, 0, 0);
	connect(leS, &QLineEdit::textEdited, this, [=]() mutable {
	    if (leS->text() != "") {
		CurrentMaterial->size = leS->text().toInt();
		changeWorkPrice();
	    }
	});
	if (isNotNew)
	    leS->setText(QString::number(CurrentMaterial->size));
    }
}
void
AddNewRequest::changeWorkPrice()
{
    int WorkPrice = 0;
    for (auto& it : Materials) {
	WorkPrice += it->size * Admin::PriceForTheTypeMaterial[it->composition];
    }
    WorkPrice -=
      ceil(WorkPrice * ui->summaryDiscountLabel->text().toInt() / 100);
    ui->workPriceLabel->setText(QString::number(WorkPrice));
    emit changedWorkPrice();
    changeSummaryPrice();
}
void
AddNewRequest::connectAll()
{
    connect(ui->numberEdit,
	    &QLineEdit::editingFinished,
	    this,
	    &AddNewRequest::changeCountLabel);
    connect(ui->areaComboBox,
	    &QComboBox::currentTextChanged,
	    this,
	    &AddNewRequest::changeDeliveryPrice);
    connect(ui->typeDeliveryComboBox,
	    &QComboBox::currentTextChanged,
	    this,
	    &AddNewRequest::changeDeliveryPrice);
    connect(ui->invalidDiscountCheckBox,
	    &QCheckBox::clicked,
	    this,
	    &AddNewRequest::changeSummaryDiscount);
    connect(ui->addItemPushButton, &QPushButton::clicked, this, [=]() {
	this->addNewItems();
    });
    connect(ui->buttonBox,
	    &QDialogButtonBox::accepted,
	    this,
	    &AddNewRequest::makeRequst);
}
void
AddNewRequest::changeSummaryDiscount()
{
    int SummaryDiscount = ui->standartDiscountLabel->text().toInt() +
			  ui->for3ItemsDiscountLabel->text().toInt();
    if (ui->invalidDiscountCheckBox->isChecked())
	SummaryDiscount += Admin::Discounts[2];
    ui->summaryDiscountLabel->setText(QString::number(SummaryDiscount));
    changeWorkPrice();
    changeDeliveryPrice();
}
void
AddNewRequest::changeSummaryPrice()
{
    int WorkPrice = ui->workPriceLabel->text().toInt();
    int DeliveryPrice = ui->deliveryPriceLabel->text().toInt();
    int SummaryPrice = WorkPrice + DeliveryPrice;
    ui->summaryPriceLabel->setText(QString::number(SummaryPrice));
}
void
AddNewRequest::changeCountLabel()
{
    if (!isNotNew) {
	IDConsumer = MySqlQueries::getIDConsumer(ui->numberEdit->text());
	ui->countLabel->setText(
	  QString::number(MySqlQueries::getCountRequestByID(IDConsumer)));
    }
}
void
AddNewRequest::changeDeliveryPrice()
{
    /*if(ui->typeDeliveryComboBox->currentIndex() == 1 ||
    ui->typeDeliveryComboBox->currentIndex() == 3)
	ui->driverDepartureDateEdit->setEnabled(true);
    else
	ui->driverDepartureDateEdit->setEnabled(false);*/
    int IndexForAreaDelivery = ui->areaComboBox->currentIndex();
    int IndexForTypeDelivery = ui->typeDeliveryComboBox->currentIndex();
    int DeliveryPrice =
      Admin::PriceDeliveryForTheArea[IndexForAreaDelivery] +
      Admin::PriceDeliveryForTheTypeDelivery[IndexForTypeDelivery];
    DeliveryPrice -=
      ceil(DeliveryPrice * ui->summaryDiscountLabel->text().toInt() / 100);
    ui->deliveryPriceLabel->setText(QString::number(DeliveryPrice));
    changeSummaryPrice();
}

void
AddNewRequest::clearLayout(QLayout* layout)
{
    while (layout->count() > 0) {
	auto item = layout->takeAt(0);
	if (item->layout()) {
	    clearLayout(item->layout());
	} else {
	    delete item->widget();
	    delete item;
	}
    }
    delete layout;
}
void
AddNewRequest::clearLayout(QLayout* layout, bool isNeedFindLineEdits)
{
    while (layout->count() > 0) {
	auto item = layout->takeAt(0);
	if (item->layout()) {
	    clearLayout(item->layout(), true);
	} else {
	    if (isNeedFindLineEdits)
		if (QString(item->widget()->metaObject()->className()) ==
		    "QLineEdit")
		    lineEdits.removeOne(
		      static_cast<QLineEdit*>(item->widget()));
	    delete item->widget();
	    delete item;
	}
    }
    delete layout;
}
void
AddNewRequest::restoreStyleSheet(QObject* object)
{
    if (QString(object->metaObject()->className()) == "QLineEdit")
	static_cast<QLineEdit*>(object)->setStyleSheet(
	  "QLineEdit { border-color: #76797C;}");
    else
	static_cast<QLabel*>(object)->setStyleSheet(
	  "QLabel { border-color: #76797C;}");
}

void
AddNewRequest::makeRequst()
{
    bool success = true;
    if (ui->nameEdit->text() == "") {
	ui->nameEdit->setStyleSheet(
	  "QLineEdit { border-color: rgb(150, 0, 0);}");
	connect(ui->nameEdit, &QLineEdit::textChanged, this, [=]() {
	    this->restoreStyleSheet(ui->nameEdit);
	});
	success = false;
    }
    if (ui->numberEdit->text().size() != 12) {
	ui->numberEdit->setStyleSheet(
	  "QLineEdit { border-color: rgb(150, 0, 0);}");
	connect(ui->numberEdit, &QLineEdit::textChanged, this, [=]() {
	    this->restoreStyleSheet(ui->numberEdit);
	});
	success = false;
    }
    if (ui->addressLineEdit->text() == "") {
	ui->addressLineEdit->setStyleSheet(
	  "QLineEdit { border-color: rgb(150, 0, 0);}");
	connect(ui->addressLineEdit, &QLineEdit::textChanged, this, [=]() {
	    this->restoreStyleSheet(ui->addressLineEdit);
	});
	success = false;
    }
    if (!lineEdits.size()) {
	ui->workPriceLabel->setStyleSheet(
	  "QLabel { background-color: rgb(150, 0, 0);}");
	connect(this, &AddNewRequest::changedWorkPrice, this, [=]() {
	    this->restoreStyleSheet(ui->workPriceLabel);
	});
	success = false;
    } else
	for (auto& it : lineEdits) {
	    if (it->text() == "") {
		it->setStyleSheet("QLineEdit { border-color: rgb(150, 0, 0);}");
		connect(it, &QLineEdit::textChanged, this, [=]() {
		    this->restoreStyleSheet(it);
		});
		success = false;
	    }
	}
    if (success) {
	Consumer consumer(
	  IDConsumer,
	  ui->nameEdit->text(),
	  ui->numberEdit->text(),
	  ui->addressLineEdit->text(),
	  static_cast<Consumer::Area>(ui->areaComboBox->currentIndex()),
	  ui->invalidDiscountCheckBox->isChecked());
	Request request(consumer,
			Materials,
			static_cast<Request::TypeDelivery>(
			  ui->typeDeliveryComboBox->currentIndex()),
			ui->workPriceLabel->text().toInt(),
			ui->deliveryPriceLabel->text().toInt(),
			ui->summaryPriceLabel->text().toInt());
	if (isNotNew) {
	    request.ID = IDRequest;
	    MySqlQueries::changeRequestSql(request);
	} else {
	    qDebug() << request.consumer.name;
	    MySqlQueries::addNewRequestSql(request);
	}
	emit successAdded();
    }
}
