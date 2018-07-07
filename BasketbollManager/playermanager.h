#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H

#include "playersmodel.h"
#include <QDialog>
#include <QDialogButtonBox>
#include <QFileDialog>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QMenuBar>
#include <QMessageBox>
#include <QPushButton>
#include <QSortFilterProxyModel>
#include <QTableView>
#include <QTextDocument>
#include <QVBoxLayout>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>

namespace Ui
{
class PlayerManager;
}

class PlayerManager : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerManager(bool isOpenExist = false, QWidget* parent = 0);
    QDialogButtonBox* getButtonBox();
    ~PlayerManager();

private:
    QPushButton* addButton;
    QPushButton* deleteButton;
    Ui::PlayerManager* ui;
    QVBoxLayout* vbl;
    QHBoxLayout* hblForTablesButtons;
    QFormLayout* fl;
    QLineEdit* lineEditTitle;
    QLineEdit* lineEditCity;
    QLineEdit* lineEditYear;
    QTableView* tableView;
    QDialogButtonBox* buttonBox;
    QMenuBar* menuBar;
    QSortFilterProxyModel* sortModel;
    PlayersModel* model;
    QAction* saveAction;
    QAction* printAction;
    QAction* helpAction;
    QString path;
    void init();
    void connectAll();
    void restoreStyleSheet(QObject* object);
    bool isValid();
    bool isFirstSave = true;
    void loadData();
signals:
    void sucAdd();
private slots:
    void onAddButtonClick();
    void onAcceptButtonClick();
    void onDeleteButtonClick();
    bool saveTo();
    void print();
};

#endif // PLAYERMANAGER_H
