#include "playersmodel.h"

PlayersModel::PlayersModel(QList<Player>&& _players, QObject* parent)
    : QAbstractTableModel(parent)
{
    players = _players;
}
int PlayersModel::columnCount(const QModelIndex& parent) const
{
    return 5;
}
int PlayersModel::rowCount(const QModelIndex& parent) const
{
    return players.size();
}
bool PlayersModel::insertRow(int row, const QModelIndex& parent)
{
    if (players.size() > 12)
        return false;
    beginInsertRows(parent, row, row);
    players.push_back(Player());
    endInsertRows();
    return true;
}
bool PlayersModel::removeRow(int row, const QModelIndex& parent)
{
    if (row == -1)
        return false;
    beginRemoveRows(parent, row, row);
    players.removeAt(row);
    endRemoveRows();
    return true;
}
QVariant PlayersModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (role == Qt::DisplayRole)
    {
        switch (index.column())
        {
        case 0:
            return players[index.row()].getName();
        case 1:
            return players[index.row()].getAge();
        case 2:
            return Team::listPos.at(static_cast<int>(players[index.row()].getPosition()));
        case 3:
            return Team::listStatus.at(static_cast<int>(players[index.row()].getStatus()));
        case 4:
            return Team::listState.at(static_cast<int>(players[index.row()].getState()));
        }
    }
    if (role == Qt::BackgroundRole)
    {
        switch (index.column())
        {
        case 0:
            if (players[index.row()].getName() == "")
            {
                QColor redCol("#D50000");
                return redCol;
            }
            break;
        }
    }
    return QVariant();
}
bool PlayersModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (role == Qt::EditRole)
    {
        switch (index.column())
        {
        case 0:
            players[index.row()].setName(value.toString());
            return true;
        case 1:
            players[index.row()].setAge(static_cast<ushort>(value.toInt()));
            return true;
        case 2:
            players[index.row()].setPosition(static_cast<Position>(value.toInt()));
            return true;
        case 3:
            players[index.row()].setStatus(static_cast<Status>(value.toInt()));
            return true;
        case 4:
            players[index.row()].setState(static_cast<HealthState>(value.toInt()));
            return true;
        }
    }
    return false;
}
QVariant PlayersModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
            case 0:
                return QString("ФИО");
            case 1:
                return QString("Возраст");
            case 2:
                return QString("Позиция");
            case 3:
                return QString("Статус");
            case 4:
                return QString("Состояние здоровья");
            }
        }
    }
    return QVariant();
}
bool PlayersModel::isValidCountPrimary() const
{
    ushort countPrimary = 0;
    for (auto& it : players)
    {
        if (it.getStatus() == Status::Primary)
            ++countPrimary;
    }
    return countPrimary == MAXPrimary;
}
bool PlayersModel::isValidPlayerNames() const
{
    for (auto& it : players)
    {
        if (it.getName() == "")
            return false;
    }
    return true;
}
QList<Player> PlayersModel::getPlayers() const
{
    return players;
}
Qt::ItemFlags PlayersModel::flags(const QModelIndex& index) const
{
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}
ComboBoxDelegate::ComboBoxDelegate(QObject* parent)
    : QStyledItemDelegate(parent)
{
}
QWidget* ComboBoxDelegate::createEditor(QWidget* parent,
    const QStyleOptionViewItem& /* option */,
    const QModelIndex& index) const
{
    switch (index.column())
    {
    case 2:
    {
        QComboBox* editor = new QComboBox(parent);
        editor->addItems(Team::listPos);
        return editor;
    }
    case 3:
    {
        QComboBox* editor = new QComboBox(parent);
        editor->addItems(Team::listStatus);
        return editor;
    }
    case 4:
    {
        QComboBox* editor = new QComboBox(parent);
        editor->addItems(Team::listState);
        return editor;
    }
    }
    QLineEdit* l = new QLineEdit(parent);
    QRegExp regExp;
    if (index.column() == 0)
    {
        regExp = QRegExp("[A-ZА-Я][a-zA-Zа-яА-Я ]{1,32}");
    }
    else if (index.column() == 1)
    {
        regExp = QRegExp("[1-9][0-9]");
    }
    l->setValidator(new QRegExpValidator(regExp));
    return l;
}
void ComboBoxDelegate::setEditorData(QWidget* editor,
    const QModelIndex& index) const
{

    if (index.column() >= 2 && index.column() <= 4)
    {
        int value = index.model()->data(index, Qt::EditRole).toInt();
        QComboBox* comboBox = static_cast<QComboBox*>(editor);
        comboBox->setCurrentIndex(value);
    }
}
void ComboBoxDelegate::setModelData(QWidget* editor, QAbstractItemModel* model,
    const QModelIndex& index) const
{
    if (index.column() >= 2 && index.column() <= 4)
    {
        QComboBox* comboBox = static_cast<QComboBox*>(editor);
        int value = comboBox->currentIndex();
        model->setData(index, value, Qt::EditRole);
    }
    else
    {
        QLineEdit* lineEdit = static_cast<QLineEdit*>(editor);
        model->setData(index, lineEdit->text());
    }
}
void ComboBoxDelegate::updateEditorGeometry(QWidget* editor,
    const QStyleOptionViewItem& option, const QModelIndex& /* index */) const
{
    editor->setGeometry(option.rect);
}
