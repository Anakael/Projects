#ifndef PLAYERSMODEL_H
#define PLAYERSMODEL_H
#include "team.h"
#include <QAbstractTableModel>
#include <QComboBox>
#include <QDebug>
#include <QLineEdit>
#include <QRegExpValidator>
#include <QStyledItemDelegate>
#include <QVariant>
class ComboBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    ComboBoxDelegate(QObject* parent = 0);

    QWidget* createEditor(QWidget* parent, const QStyleOptionViewItem& option,
        const QModelIndex& index) const override;

    void setEditorData(QWidget* editor, const QModelIndex& index) const override;
    void setModelData(QWidget* editor, QAbstractItemModel* model,
        const QModelIndex& index) const override;

    void updateEditorGeometry(QWidget* editor,
        const QStyleOptionViewItem& option, const QModelIndex& index) const override;
};

class PlayersModel : public QAbstractTableModel
{
    Q_OBJECT
private:
    QList<Player> players;
    const ushort MAXPrimary = 5;

public:
    PlayersModel(QList<Player>&& _players, QObject* parent = 0);
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    bool insertRow(int row, const QModelIndex& parent = QModelIndex());
    bool removeRow(int row, const QModelIndex& parent = QModelIndex());
    bool isValidCountPrimary() const;
    bool isValidPlayerNames() const;
    QList<Player> getPlayers() const;
    ~PlayersModel()
    {
        qDebug() << "Model destroed" << players.size();
    }
};

#endif // PLAYERSMODEL_H
