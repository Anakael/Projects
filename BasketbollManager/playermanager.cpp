#include "playermanager.h"
#include "ui_playermanager.h"

PlayerManager::PlayerManager(bool isOpenExist, QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::PlayerManager)
{
    ui->setupUi(this);
    init();
    connectAll();
    if (isOpenExist)
    {
        loadData();
        model = new PlayersModel(std::move(Team::players), this);
        isFirstSave = false;
    }
    else
        model = new PlayersModel(QList<Player>(), this);
    sortModel = new QSortFilterProxyModel;
    sortModel->setSourceModel(model);
    tableView->setModel(sortModel);
}

PlayerManager::~PlayerManager()
{
    delete ui;
}
void PlayerManager::init()
{
    try
    {
        menuBar = new QMenuBar;
        QMenu* pmnu = new QMenu("Файл");
        saveAction = new QAction("Сохранить как...");
        saveAction->setShortcut(QKeySequence::Open);
        printAction = new QAction("Печать");
        printAction->setShortcut(QKeySequence::Print);
        pmnu->addAction(saveAction);
        pmnu->addAction(printAction);
        menuBar->addMenu(pmnu);
        pmnu = new QMenu("Помощь");
        helpAction = new QAction("Справка");
        pmnu->addAction(helpAction);
        menuBar->addMenu(pmnu);
        vbl = new QVBoxLayout;
        vbl->addWidget(menuBar);
        fl = new QFormLayout;
        lineEditTitle = new QLineEdit;
        lineEditCity = new QLineEdit;
        lineEditYear = new QLineEdit;
        fl->addRow("Название:", lineEditTitle);
        fl->addRow("Город:", lineEditCity);
        fl->addRow("Год основания:", lineEditYear);
        vbl->addLayout(fl);
        tableView = new QTableView;
        vbl->addWidget(tableView);
        addButton = new QPushButton("Добавить игрока");
        deleteButton = new QPushButton("Удалить игрока");
        hblForTablesButtons = new QHBoxLayout;
        hblForTablesButtons->addWidget(addButton);
        hblForTablesButtons->addWidget(deleteButton);
        buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal);
        hblForTablesButtons->addWidget(buttonBox);
        vbl->addLayout(hblForTablesButtons);
        setLayout(vbl);
        QRegExp stringRegExp("[A-ZА-Я][a-zA-Zа-яА-Я -]{1,32}");
        QRegExp numRegExp("[1-2][0-9]{1,3}");
        lineEditTitle->setValidator(new QRegExpValidator(stringRegExp, this));
        lineEditCity->setValidator(new QRegExpValidator(stringRegExp, this));
        lineEditYear->setValidator(new QRegExpValidator(numRegExp, this));
        tableView->setSortingEnabled(true);
        tableView->verticalHeader()->hide();
        tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ComboBoxDelegate* d = new ComboBoxDelegate;
        tableView->setItemDelegate(d);
    }
    catch (std::bad_alloc& ba)
    {
        qDebug() << ba.what();
        exit(1);
    }
}
QDialogButtonBox* PlayerManager::getButtonBox()
{
    return buttonBox;
}
void PlayerManager::connectAll()
{
    connect(addButton, &QPushButton::clicked, this, &PlayerManager::onAddButtonClick);
    connect(deleteButton, &QPushButton::clicked, this, &PlayerManager::onDeleteButtonClick);
    connect(buttonBox, &QDialogButtonBox::accepted, this, &PlayerManager::onAcceptButtonClick);
    connect(saveAction, &QAction::triggered, this, &PlayerManager::saveTo);
    connect(printAction, &QAction::triggered, this, &PlayerManager::print);
    connect(helpAction, &QAction::triggered, this, [&]() {
        QString helpText = "";
        QMessageBox::information(this, "Справка", helpText, QMessageBox::Ok, 0);
    });
}
void PlayerManager::print()
{
    if (!isValid())
        return;
    QPrinter printer;
    QPrintDialog dialog(&printer, this);
    dialog.setWindowTitle(tr("Print Document"));
    if (dialog.exec() == QDialog::Accepted)
    {
        QTextDocument doc;
        QString st("");
        st.append("<h1> Название: </h1><span>" + lineEditTitle->text() + "</span>");
        st.append("<h2> Город: </h2><span>" + lineEditCity->text() + "</span>");
        st.append("<h2>  Год основания: </h2><span>" + lineEditYear->text() + "</span>");
        st.append("<h3>  Список игроков: </h3>");
        st.append("<table border=\"1\">");
        st.append("<tr>");
        st.append("<th>ФИО</th>");
        st.append("<th>Возраст</th>");
        st.append("<th>Позиция</th>");
        st.append("<th>Статус</th>");
        st.append("<th>Состояние здоровья</th>");
        st.append("</tr>");
        for (auto& it : model->getPlayers())
        {
            st.append("<tr>");
            st.append("<td border-collapse=\"collapse\" border=\"1\">" + it.getName() + "</td>"
                + "<td border-collapse=\"collapse\" border=\"1\">" + QString().setNum(it.getAge()) + "</td>"
                + "<td border-collapse=\"collapse\" border=\"1\">" + Team::listPos.at(static_cast<int>(it.getPosition())) + "</td>"
                + "<td border-collapse=\"collapse\" border=\"1\">" + Team::listStatus.at(static_cast<int>(it.getStatus())) + "</td>"
                + "<td border-collapse=\"collapse\" border=\"1\">" + Team::listState.at(static_cast<int>(it.getState())) + "</td>");
            st.append("</tr>");
        }
        st.append("</table>");
        doc.setHtml(st);
        doc.print(&printer);
    }
}
void PlayerManager::onAcceptButtonClick()
{
    if (saveTo())
        emit sucAdd();
}
void PlayerManager::onAddButtonClick()
{
    model->insertRow(model->rowCount());
}
void PlayerManager::onDeleteButtonClick()
{
    model->removeRow(tableView->currentIndex().row());
}
bool PlayerManager::saveTo()
{
    if (!isValid())
        return false;
    QFile file;
    path = QFileDialog::getSaveFileName(this, "Сохранить файл", "", "Текстовый файл (*.txt)");
    if (path == "")
        return false;
    file.setFileName(path);
    try
    {
        file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);
    }
    catch (std::exception& e)
    {
        qDebug() << e.what();
        return false;
    }

    QTextStream out(&file);
    Team::initTeam(lineEditTitle->text(), lineEditCity->text(), lineEditYear->text().toUShort(), model->getPlayers());
    Team::flushToStream(out);
    file.close();
    return true;
}
void PlayerManager::restoreStyleSheet(QObject* object)
{
    if (QString(object->metaObject()->className()) == "QLineEdit")
        static_cast<QLineEdit*>(object)->setStyleSheet(
            "QLineEdit { }");
    else if (QString(object->metaObject()->className()) == "QTableView")
        static_cast<QTableView*>(object)->setStyleSheet(
            "QTableView { }");
}
bool PlayerManager::isValid()
{
    bool valid = true;
    if (lineEditTitle->text() == "")
    {
        valid = false;
        lineEditTitle->setStyleSheet(
            "QLineEdit { border: 1px solid red;}");
        connect(lineEditTitle, &QLineEdit::textChanged, this, [=]() {
            restoreStyleSheet(lineEditTitle);
        });
    }
    if (lineEditCity->text() == "")
    {
        valid = false;
        lineEditCity->setStyleSheet(
            "QLineEdit { border: 1px solid red;}");
        connect(lineEditCity, &QLineEdit::textChanged, this, [=]() {
            restoreStyleSheet(lineEditCity);
        });
    }
    if (lineEditYear->text().length() < 4)
    {
        valid = false;
        lineEditYear->setStyleSheet(
            "QLineEdit { border: 1px solid red;}");
        connect(lineEditYear, &QLineEdit::textChanged, this, [=]() {
            restoreStyleSheet(lineEditYear);
        });
    }
    if (model->rowCount() == 0)
    {
        valid = false;
        tableView->setStyleSheet(
            "QTableView { border: 1px solid red;}");
        connect(addButton, &QPushButton::clicked, this, [this]() {
            restoreStyleSheet(tableView);
        });
    }
    if (!model->isValidCountPrimary())
    {
        valid = false;
        QMessageBox msgBox;
        msgBox.setText("Количество игроков в основе должно быть 5.");
        msgBox.exec();
    }
    if (!model->isValidPlayerNames())
        valid = false;
    return valid;
}
void PlayerManager::loadData()
{
    QFile file;
    if (isFirstSave)
    {
        path = QFileDialog::getOpenFileName(this, "Открыть файл", "", "Текстовый файл (*.txt)");
    }
    if (path == "")
    {
        return;
    }

    file.setFileName(path);
    try
    {
        file.open(QIODevice::ReadOnly | QIODevice::Text);
    }
    catch (std::exception& e)
    {
        qDebug() << e.what();
        return;
    }

    QTextStream in(&file);
    Team::loadFromStream(in);
    lineEditTitle->setText(Team::title);
    lineEditCity->setText(Team::cityCreated);
    lineEditYear->setText(QString().setNum(Team::yearCreated));
}
