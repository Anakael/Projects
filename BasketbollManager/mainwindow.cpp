#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    returnControl();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::connectAll()
{
    connect(ui->createTeamButton,
        &QPushButton::clicked,
        this,
        [&]() { MainWindow::callPlayerManager(); });
    connect(ui->loadTeamButton,
        &QPushButton::clicked,
        this,
        [&]() { MainWindow::callPlayerManager(true); });
}
void MainWindow::returnControl()
{
    ui->setupUi(this);
    connectAll();
    setMinimumSize(QSize(415, 420));
    setMaximumSize(QSize(415, 420));
    adjustSize();
}
void MainWindow::callPlayerManager(bool isOpenExist)
{
    pm = new PlayerManager(isOpenExist);
    setCentralWidget(pm);
    setMinimumSize(QSize(810, 650));
    setMaximumSize(QSize(810, 650));
    connect(pm->getButtonBox(), &QDialogButtonBox::rejected, this, &MainWindow::returnControl);
    connect(pm, &PlayerManager::sucAdd, this, &MainWindow::returnControl);
}
