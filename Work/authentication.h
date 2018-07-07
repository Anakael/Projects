#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include "admin.h"
#include "mysqlqueries.h"

#include <QDialog>
#include <QFile>
#include <QTextStream>

namespace Ui {
class Authentication;
}

class Authentication : public QDialog
{
    Q_OBJECT

public:
    explicit Authentication(QWidget *parent = 0);
    ~Authentication();
    void authAndInitDBConnecdtion();
signals:
    void successAuth();
private:
    Ui::Authentication *ui;
};

#endif // AUTHENTICATION_H
