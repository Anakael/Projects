#ifndef STATUS_H
#define STATUS_H

#include "hotel.h"

#include <QDialog>
#include <QDialogButtonBox>
#include <QSqlQueryModel>
#include <fstream>

namespace Ui {
class Status;
}

class Status : public QDialog
{
    Q_OBJECT

public:
    explicit Status(QWidget *parent = 0);
    ~Status();
    QDialogButtonBox* getButtonBox();
private:
    Ui::Status *ui;
};

#endif // STATUS_H
