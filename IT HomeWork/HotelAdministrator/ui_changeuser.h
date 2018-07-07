/********************************************************************************
** Form generated from reading UI file 'changeuser.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEUSER_H
#define UI_CHANGEUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChangeUser
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *ChangePushButton;
    QDateEdit *dateEdit;
    QLabel *deltaPriceLabel;
    QLabel *numberLabel;
    QPushButton *deletePushButton;
    QSpinBox *numberSpinBox;

    void setupUi(QDialog *ChangeUser)
    {
        if (ChangeUser->objectName().isEmpty())
            ChangeUser->setObjectName(QStringLiteral("ChangeUser"));
        ChangeUser->resize(400, 300);
        buttonBox = new QDialogButtonBox(ChangeUser);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        gridLayoutWidget = new QWidget(ChangeUser);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(60, 0, 283, 241));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        ChangePushButton = new QPushButton(gridLayoutWidget);
        ChangePushButton->setObjectName(QStringLiteral("ChangePushButton"));

        gridLayout->addWidget(ChangePushButton, 1, 3, 1, 3);

        dateEdit = new QDateEdit(gridLayoutWidget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setEnabled(true);

        gridLayout->addWidget(dateEdit, 2, 3, 1, 3);

        deltaPriceLabel = new QLabel(gridLayoutWidget);
        deltaPriceLabel->setObjectName(QStringLiteral("deltaPriceLabel"));

        gridLayout->addWidget(deltaPriceLabel, 2, 0, 1, 3);

        numberLabel = new QLabel(gridLayoutWidget);
        numberLabel->setObjectName(QStringLiteral("numberLabel"));

        gridLayout->addWidget(numberLabel, 0, 0, 1, 3);

        deletePushButton = new QPushButton(gridLayoutWidget);
        deletePushButton->setObjectName(QStringLiteral("deletePushButton"));

        gridLayout->addWidget(deletePushButton, 1, 0, 1, 3);

        numberSpinBox = new QSpinBox(gridLayoutWidget);
        numberSpinBox->setObjectName(QStringLiteral("numberSpinBox"));
        numberSpinBox->setMinimum(1);

        gridLayout->addWidget(numberSpinBox, 0, 3, 1, 3);


        retranslateUi(ChangeUser);
        QObject::connect(buttonBox, SIGNAL(accepted()), ChangeUser, SLOT(accept()));

        QMetaObject::connectSlotsByName(ChangeUser);
    } // setupUi

    void retranslateUi(QDialog *ChangeUser)
    {
        ChangeUser->setWindowTitle(QApplication::translate("ChangeUser", "Dialog", nullptr));
        ChangePushButton->setText(QApplication::translate("ChangeUser", "Change End date", nullptr));
        dateEdit->setDisplayFormat(QApplication::translate("ChangeUser", "dd.MM", nullptr));
        deltaPriceLabel->setText(QApplication::translate("ChangeUser", "Delta price:", nullptr));
        numberLabel->setText(QApplication::translate("ChangeUser", "Number room", nullptr));
        deletePushButton->setText(QApplication::translate("ChangeUser", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChangeUser: public Ui_ChangeUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEUSER_H
