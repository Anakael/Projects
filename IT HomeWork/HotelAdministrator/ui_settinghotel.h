/********************************************************************************
** Form generated from reading UI file 'settinghotel.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGHOTEL_H
#define UI_SETTINGHOTEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingOtel
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QSpinBox *singleRoomCount;
    QSpinBox *singleRoomPrice;
    QLabel *label_4;
    QSpinBox *dobleRoomPrice;
    QLabel *label_3;
    QSpinBox *doubleRoomCount;
    QLabel *label_2;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SettingOtel)
    {
        if (SettingOtel->objectName().isEmpty())
            SettingOtel->setObjectName(QStringLiteral("SettingOtel"));
        SettingOtel->resize(400, 300);
        verticalLayoutWidget = new QWidget(SettingOtel);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(60, 30, 281, 111));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        singleRoomCount = new QSpinBox(verticalLayoutWidget);
        singleRoomCount->setObjectName(QStringLiteral("singleRoomCount"));
        singleRoomCount->setMaximum(200);
        singleRoomCount->setValue(100);

        gridLayout->addWidget(singleRoomCount, 1, 1, 1, 1);

        singleRoomPrice = new QSpinBox(verticalLayoutWidget);
        singleRoomPrice->setObjectName(QStringLiteral("singleRoomPrice"));
        singleRoomPrice->setMaximum(2000);
        singleRoomPrice->setSingleStep(100);
        singleRoomPrice->setValue(1000);

        gridLayout->addWidget(singleRoomPrice, 1, 3, 1, 1);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 3, 1, 1);

        dobleRoomPrice = new QSpinBox(verticalLayoutWidget);
        dobleRoomPrice->setObjectName(QStringLiteral("dobleRoomPrice"));
        dobleRoomPrice->setMaximum(4000);
        dobleRoomPrice->setSingleStep(100);
        dobleRoomPrice->setValue(2000);

        gridLayout->addWidget(dobleRoomPrice, 2, 3, 1, 1);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        doubleRoomCount = new QSpinBox(verticalLayoutWidget);
        doubleRoomCount->setObjectName(QStringLiteral("doubleRoomCount"));
        doubleRoomCount->setMaximum(100);
        doubleRoomCount->setValue(50);

        gridLayout->addWidget(doubleRoomCount, 2, 1, 1, 1);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(SettingOtel);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 34));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget->raise();
        buttonBox->raise();

        retranslateUi(SettingOtel);

        QMetaObject::connectSlotsByName(SettingOtel);
    } // setupUi

    void retranslateUi(QDialog *SettingOtel)
    {
        SettingOtel->setWindowTitle(QApplication::translate("SettingOtel", "Dialog", nullptr));
        label_4->setText(QApplication::translate("SettingOtel", "Price", nullptr));
        label_3->setText(QApplication::translate("SettingOtel", "Count", nullptr));
        label_2->setText(QApplication::translate("SettingOtel", "Double room", nullptr));
        label->setText(QApplication::translate("SettingOtel", "Single room", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingOtel: public Ui_SettingOtel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGHOTEL_H
