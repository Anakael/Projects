#ifndef ADDNEWUSER_H
#define ADDNEWUSER_H

#include "hotel.h"
#include "settinghotel.h"

#include <QDialog>
#include <QDialogButtonBox>

namespace Ui {
class AddNewUser;
}

class AddNewUser : public QDialog
{
    Q_OBJECT
public:
    explicit AddNewUser(QWidget *parent = 0);
    ~AddNewUser();
    QDialogButtonBox* getButtonBox();
private:
    Ui::AddNewUser *ui;
    void init();
    void connectAll();
signals:
    void changed();
    void sucAdd();
private slots:
    void onPriceChanged();
    void onAcceptClicked();
};

#endif // ADDNEWUSER_H
