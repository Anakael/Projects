/********************************************************************************
** Form generated from reading UI file 'addnewuser.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDNEWUSER_H
#define UI_ADDNEWUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddNewUser
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *serialNumberEdit;
    QLabel *typeLabel;
    QLabel *nameLabel;
    QLabel *endLabel;
    QDateEdit *endDateEdit;
    QLabel *label;
    QComboBox *typeBox;
    QLineEdit *nameEdit;
    QLabel *resultPriceLabel;

    void setupUi(QDialog *AddNewUser)
    {
        if (AddNewUser->objectName().isEmpty())
            AddNewUser->setObjectName(QStringLiteral("AddNewUser"));
        AddNewUser->resize(400, 300);
        AddNewUser->setInputMethodHints(Qt::ImhLatinOnly);
        buttonBox = new QDialogButtonBox(AddNewUser);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setEnabled(true);
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        gridLayoutWidget = new QWidget(AddNewUser);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(62, 10, 281, 221));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        serialNumberEdit = new QLineEdit(gridLayoutWidget);
        serialNumberEdit->setObjectName(QStringLiteral("serialNumberEdit"));

        gridLayout->addWidget(serialNumberEdit, 1, 1, 1, 1);

        typeLabel = new QLabel(gridLayoutWidget);
        typeLabel->setObjectName(QStringLiteral("typeLabel"));

        gridLayout->addWidget(typeLabel, 2, 0, 1, 1);

        nameLabel = new QLabel(gridLayoutWidget);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));

        gridLayout->addWidget(nameLabel, 0, 0, 1, 1);

        endLabel = new QLabel(gridLayoutWidget);
        endLabel->setObjectName(QStringLiteral("endLabel"));

        gridLayout->addWidget(endLabel, 4, 0, 1, 1);

        endDateEdit = new QDateEdit(gridLayoutWidget);
        endDateEdit->setObjectName(QStringLiteral("endDateEdit"));

        gridLayout->addWidget(endDateEdit, 4, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        typeBox = new QComboBox(gridLayoutWidget);
        typeBox->addItem(QString());
        typeBox->addItem(QString());
        typeBox->setObjectName(QStringLiteral("typeBox"));

        gridLayout->addWidget(typeBox, 2, 1, 1, 1);

        nameEdit = new QLineEdit(gridLayoutWidget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));
        nameEdit->setInputMethodHints(Qt::ImhNone);

        gridLayout->addWidget(nameEdit, 0, 1, 1, 1);

        resultPriceLabel = new QLabel(gridLayoutWidget);
        resultPriceLabel->setObjectName(QStringLiteral("resultPriceLabel"));

        gridLayout->addWidget(resultPriceLabel, 6, 0, 1, 2);

        QWidget::setTabOrder(nameEdit, serialNumberEdit);
        QWidget::setTabOrder(serialNumberEdit, typeBox);
        QWidget::setTabOrder(typeBox, endDateEdit);

        retranslateUi(AddNewUser);
        QObject::connect(buttonBox, SIGNAL(rejected()), AddNewUser, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddNewUser);
    } // setupUi

    void retranslateUi(QDialog *AddNewUser)
    {
        AddNewUser->setWindowTitle(QApplication::translate("AddNewUser", "Dialog", nullptr));
        typeLabel->setText(QApplication::translate("AddNewUser", "Choose type", nullptr));
        nameLabel->setText(QApplication::translate("AddNewUser", "Name", nullptr));
        endLabel->setText(QApplication::translate("AddNewUser", "End date", nullptr));
        endDateEdit->setDisplayFormat(QApplication::translate("AddNewUser", "dd.MM", nullptr));
        label->setText(QApplication::translate("AddNewUser", "Serial Number", nullptr));
        typeBox->setItemText(0, QApplication::translate("AddNewUser", "Single room", nullptr));
        typeBox->setItemText(1, QApplication::translate("AddNewUser", "Double room", nullptr));

        nameEdit->setText(QString());
        resultPriceLabel->setText(QApplication::translate("AddNewUser", "Result price:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddNewUser: public Ui_AddNewUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDNEWUSER_H
