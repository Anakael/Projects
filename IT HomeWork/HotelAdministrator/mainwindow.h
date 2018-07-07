#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "addnewuser.h"
#include "changeuser.h"
#include "status.h"

#include <QMainWindow>
#include <QDialogButtonBox>

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
    SettingOtel* so;
    AddNewUser* anu;
    ChangeUser* cu;
    Status* s;
    void connectAll();
    void initDB();
private slots:
    void returnControl();
    void callSetting();
    void callAddNewUser();
    void callChange();
    void CallStatus();
};

#endif // MAINWINDOW_H
