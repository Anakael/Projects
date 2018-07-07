#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectAll();
    initDB();
}

MainWindow::~MainWindow()
{
    Otel::db.close();
    QSqlDatabase::removeDatabase(Otel::NameDB);
    delete ui;
}
void MainWindow::initDB()
{
    bool IsExist = true;
    if (!QFile::exists(Otel::NameDB))
        IsExist = false;
    Otel::db = QSqlDatabase::addDatabase("QSQLITE");
    Otel::db.setDatabaseName(Otel::NameDB);
    Otel::db.open();

    if (!IsExist)
        callSetting();
    else
    {
        QSqlQuery SqlQuery;
        SqlQuery.exec("SELECT Count, Price FROM SettingHotel");
        SqlQuery.next();
        Otel::SingleRoomCount = SqlQuery.value(0).toInt();
        Otel::SingleRoomPrice = SqlQuery.value(1).toInt();
        SqlQuery.next();
        Otel::DoubleRoomCount = SqlQuery.value(0).toInt();
        Otel::DoubleRoomPrice = SqlQuery.value(1).toInt();

        SqlQuery.exec("SELECT ID FROM Rooms WHERE DateEnd IS NULL AND Capacity IS 1");
        Otel::FreedSingleID = new QVector<int>;
        while (SqlQuery.next())
        {
            Otel::FreedSingleID->push_back(SqlQuery.value(0).toInt());
        }
        SqlQuery.exec("SELECT ID FROM Rooms WHERE DateEnd IS NULL AND Capacity IS 2");
        Otel::FreedDoubleID = new QVector<int>;
        while (SqlQuery.next())
        {
            Otel::FreedDoubleID->push_back(SqlQuery.value(0).toInt());
        }
    }
}

void MainWindow::returnControl()
{
    ui->setupUi(this);
    connectAll();
}
void MainWindow::callSetting()
{
    so = new SettingOtel;
    this->setCentralWidget(so);
    connect(so->getButtonBox(),
        &QDialogButtonBox::accepted,
        this,
        &MainWindow::returnControl);
    connect(so->getButtonBox(),
        &QDialogButtonBox::rejected,
        this,
        &MainWindow::returnControl);
}
void MainWindow::callChange()
{
    cu = new ChangeUser;
    this->setCentralWidget(cu);
    connect(cu->getButtonBox(),
        &QDialogButtonBox::accepted,
        this,
        &MainWindow::returnControl);
    connect(cu->getDeleteButton(),
        &QPushButton::clicked,
        this,
        &MainWindow::returnControl);
    connect(cu->getChangeDateButton(),
        &QPushButton::clicked,
        this,
        &MainWindow::returnControl);
}
void MainWindow::callAddNewUser()
{
    anu = new AddNewUser;
    this->setCentralWidget(anu);
    connect(anu,
        &AddNewUser::sucAdd,
        this,
        &MainWindow::returnControl);
    connect(anu->getButtonBox(),
        &QDialogButtonBox::rejected,
        this,
        &MainWindow::returnControl);
}
void MainWindow::CallStatus()
{
    s = new Status;
    this->setCentralWidget(s);
    connect(s->getButtonBox(),
        &QDialogButtonBox::accepted,
        this,
        &MainWindow::returnControl);
}

void MainWindow::connectAll()
{
    connect(ui->addNewConsumerButton,
        &QPushButton::clicked,
        this,
        &MainWindow::callAddNewUser);
    connect(ui->changeConsumerButton,
        &QPushButton::clicked,
        this,
        &MainWindow::callChange);
    connect(ui->viewStatusButton,
        &QPushButton::clicked,
        this,
        &MainWindow::CallStatus);
}
