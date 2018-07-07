#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "addnewrequest.h"
#include "authentication.h"
#include "admin.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    void connectAll();
    AddNewRequest* anr;
    Authentication* auth;
    QVBoxLayout* vlayout;
    void initDB();
    bool isNotInit = 1;
private slots:
    void callAddNewRequest(bool isNotNew = false,int IDRequest = 0);
    void callAuthentication();
    void returnControl();
    void displayDataForRequest(const QModelIndex&);
    void searchRequest(const QString&);
};

#endif // MAINWINDOW_H
