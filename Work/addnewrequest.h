#ifndef ADDNEWREQUEST_H
#define ADDNEWREQUEST_H

#include "admin.h"
#include "request.h"
#include "mysqlqueries.h"

#include <QDialog>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QCheckBox>

namespace Ui {
class AddNewRequest;
}

class AddNewRequest : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewRequest(QWidget *parent = 0,bool _isNotNew = false, int _IDRequest = 0);
    ~AddNewRequest();
    static void clearLayout(QLayout *layout);
private:
    int IDConsumer;
    bool isNotNew;
    int IDRequest;
    Ui::AddNewRequest *ui;
    void init();
    void connectAll();
    QVBoxLayout* ItemLayout;
    QVector<Material*> Materials;
    QVector<QLineEdit*> lineEdits;
    void clearLayout(QLayout *layout,bool);
signals:
    void successAdded();
    void changedWorkPrice();
private slots:
    void changeCountLabel();
    void changeTypeSize(QHBoxLayout*, Material*,bool = false);
    void changeDeliveryPrice();
    void changeWorkPrice();
    void changeSummaryPrice();
    void changeSummaryDiscount();
    void addNewItems(bool isNew = false,Material* material = new Material);
    void makeRequst();
    void restoreStyleSheet(QObject*);
};

#endif // ADDNEWREQUEST_H
