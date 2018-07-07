#ifndef SETTINGOTEL_H
#define SETTINGOTEL_H

#include "hotel.h"

#include <QDialog>
#include <QDialogButtonBox>
#include <QFile>

namespace Ui {
class SettingOtel;
}

class SettingOtel : public QDialog
{
    Q_OBJECT
public:
    explicit SettingOtel(QWidget *parent = 0);
    ~SettingOtel();
    QDialogButtonBox* getButtonBox();
private:
    Ui::SettingOtel *ui;
private slots:
    void onAcceptClicked();
};

#endif // SETTINGOTEL_H
