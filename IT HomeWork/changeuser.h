#ifndef CHANGEUSER_H
#define CHANGEUSER_H

#include "hotel.h"

#include <QDialog>
#include <QDialogButtonBox>
#include <QSqlQuery>

namespace Ui {
class ChangeUser;
}

class ChangeUser : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeUser(QWidget *parent = 0);
    ~ChangeUser();
    QDialogButtonBox* getButtonBox();
    QPushButton* getDeleteButton();
    QPushButton* getChangeDateButton();
private:
    Ui::ChangeUser *ui;
    void connectAll();
    QString ID;
    int Capacity;
    QDate EndDate;
    bool IsInited;
    void getData();
private slots:
    void deleteConsumer();
    void changeEndDateRoom();
    void changeDateEdit();
};

#endif // CHANGEUSER_H
