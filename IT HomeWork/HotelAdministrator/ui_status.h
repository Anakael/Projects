/********************************************************************************
** Form generated from reading UI file 'status.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATUS_H
#define UI_STATUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Status
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *singleRoomCountLabel;
    QLabel *doubleRoomCountLabel;
    QLabel *label;
    QListView *listView;

    void setupUi(QDialog *Status)
    {
        if (Status->objectName().isEmpty())
            Status->setObjectName(QStringLiteral("Status"));
        Status->resize(400, 300);
        buttonBox = new QDialogButtonBox(Status);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(Status);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(60, 0, 281, 241));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        singleRoomCountLabel = new QLabel(verticalLayoutWidget);
        singleRoomCountLabel->setObjectName(QStringLiteral("singleRoomCountLabel"));

        verticalLayout->addWidget(singleRoomCountLabel);

        doubleRoomCountLabel = new QLabel(verticalLayoutWidget);
        doubleRoomCountLabel->setObjectName(QStringLiteral("doubleRoomCountLabel"));

        verticalLayout->addWidget(doubleRoomCountLabel);

        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        listView = new QListView(verticalLayoutWidget);
        listView->setObjectName(QStringLiteral("listView"));

        verticalLayout->addWidget(listView);


        retranslateUi(Status);
        QObject::connect(buttonBox, SIGNAL(accepted()), Status, SLOT(accept()));

        QMetaObject::connectSlotsByName(Status);
    } // setupUi

    void retranslateUi(QDialog *Status)
    {
        Status->setWindowTitle(QApplication::translate("Status", "Dialog", nullptr));
        singleRoomCountLabel->setText(QApplication::translate("Status", "Single Room Count:", nullptr));
        doubleRoomCountLabel->setText(QApplication::translate("Status", "Double Room Count:", nullptr));
        label->setText(QApplication::translate("Status", "You need delete next consumers:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Status: public Ui_Status {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATUS_H
