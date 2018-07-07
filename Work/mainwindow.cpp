#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	callAuthentication();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::connectAll()
{
    disconnect(ui->requestsTableView,0,0,0);
    connect(ui->addNewRequestButton,
            &QPushButton::clicked,
            this,
            [=]()
    {
        this->callAddNewRequest();
    });
    connect(ui->requestsTableView,
            &QTableView::doubleClicked,
            this,
            &MainWindow::displayDataForRequest);
    connect(ui->searchLineEdit,
            &QLineEdit::textEdited,
            this,
            &MainWindow::searchRequest);
}
void MainWindow::searchRequest(const QString& searchString)
{
    if(searchString != "")
        MySqlQueries::searchDataFromDB(*ui->requestsTableView,searchString);
    else
        MySqlQueries::getDataFromDB(*ui->requestsTableView);
    //ui->requestsTableView->resizeColumnsToContents();
    ui->requestsTableView->horizontalHeader()->setStretchLastSection(true);
    ui->requestsTableView->horizontalHeader()->setVisible(true);
}
void MainWindow::displayDataForRequest(const QModelIndex& index)
{
    disconnect(ui->deleteRequestButton,0,0,0);
    disconnect(ui->changeRequestButton,0,0,0);
    disconnect(ui->okPushButton,0,0,0);
    int IDRequest = ui->requestsTableView->model()->index(index.row(),0).data().toInt();
    Request request = MySqlQueries::getRequest(IDRequest);
    ui->statusComboBox->setCurrentIndex(request.status);
    ui->lastUpdateStatusDateEdit->setDate(request.lastUpdateDate);
    ui->dateOrderLabel->setText(request.orderDate.toString("dd.MM.yyyy"));
    ui->nameLabel->setText(request.consumer.name);
    ui->phoneNumberLabel->setText(request.consumer.number);
    ui->areaLabel->setText(Admin::AreaList[request.consumer.area]);
    ui->addressLabel->setText(request.consumer.address);
    ui->countRequestsLabel->setText(QString::number(MySqlQueries::getCountRequestByID(request.consumer.ID)));
    ui->workPriceLabel->setText(QString::number(request.priceForWork));
    ui->deliveryPriceLabel->setText(QString::number(request.priceForDelivery));
    ui->summaryPriceLabel->setText(QString::number(request.priceSummary));
    if(isNotInit)
    {
        AddNewRequest::clearLayout(vlayout);
        vlayout = new QVBoxLayout(ui->itemsScrollAreaWidgetContents);
    }
    for(auto &it : request.materials)
    {
        QFormLayout* flayout = new QFormLayout;
        QLabel* composition = new QLabel(Admin::CompositionList[it->composition],flayout->widget());
        flayout->addRow("Состав",composition);
        QLabel* size = new QLabel(QString::number(it->size),flayout->widget());
        flayout->addRow("Размер",size);
        vlayout->addLayout(flayout);
    }
    isNotInit = true;
    while (request.materials.size())
    {
        delete request.materials[0];
        request.materials[0] = nullptr;
        request.materials.remove(0);
    }

    connect(ui->okPushButton,
            &QPushButton::clicked,
            this,
            [=]()
    {
        MySqlQueries::changeStatus(IDRequest,
                                   ui->statusComboBox->currentIndex(),
                                   ui->lastUpdateStatusDateEdit->date());
        MySqlQueries::getDataFromDB(*ui->requestsTableView);

    });
    connect(ui->deleteRequestButton,
            &QPushButton::clicked,
            this,
            [=]()
    {
        MySqlQueries::deleteRequest(IDRequest);
        MySqlQueries::getDataFromDB(*ui->requestsTableView);
    });
    connect(ui->changeRequestButton,
            &QPushButton::clicked,
            this,
            [=]()
    {
        MainWindow::callAddNewRequest(true,IDRequest);
    });
}

void MainWindow::callAddNewRequest(bool isNotNew,int IDRequest)
{

    anr = new AddNewRequest(0,isNotNew,IDRequest);
    this->setCentralWidget(anr);
    this->resize(731,551);
    connect(anr,
            &AddNewRequest::successAdded,
            this,
            &MainWindow::returnControl);
    connect(anr,
            &QDialog::rejected,
            this,
            &MainWindow::returnControl);
}
void MainWindow::returnControl()
{
    ui->setupUi(this);
    connectAll();
    vlayout = new QVBoxLayout(ui->itemsScrollAreaWidgetContents);
    MySqlQueries::getDataFromDB(*ui->requestsTableView);
    ui->requestsTableView->resizeColumnsToContents();
    ui->requestsTableView->horizontalHeader()->setStretchLastSection(true);
    ui->requestsTableView->horizontalHeader()->setVisible(true);
}
void MainWindow::callAuthentication()
{
    auth = new Authentication;
    this->setCentralWidget(auth);
    this->resize(290,120);
    connect(auth,
            &Authentication::successAuth,
            this,
            &MainWindow::returnControl);
    connect(auth,
            &QDialog::rejected,
            this,
            &MainWindow::close);
}
