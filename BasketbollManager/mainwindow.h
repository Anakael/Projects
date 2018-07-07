#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "playermanager.h"
#include <QDialog>
#include <QMainWindow>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    PlayerManager* pm;
    void connectAll();
private slots:
    void callPlayerManager(bool isOpenExist = false);
    void returnControl();
};

class Foo
{
private:
    virtual void lol() = 0;
    virtual ~Foo();
};
class Bar : public Foo
{
    void lol() override;
    ~Bar() override;
};
#endif // MAINWINDOW_H
