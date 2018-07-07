#include "team.h"
QString Team::title = "";
QString Team::cityCreated = "";
ushort Team::yearCreated = 0;
QList<Player> Team::players;
bool Team::isInited = false;
const QStringList Team::listPos = { "Защитник", "Форвард", "Центровой" };
const QStringList Team::listState = { "Здоров", "Травмирован" };
const QStringList Team::listStatus = { "Игрок основы", "Игрок запаса" };

void Team::initTeam(QString _title, QString _cityCreated, ushort _yearCreated, QList<Player>&& _players)
{
    title = _title;
    cityCreated = _cityCreated;
    yearCreated = _yearCreated;
    players = _players;
    isInited = true;
}
void Team::flushToStream(QTextStream& stream)
{
    stream << title << "\n";
    stream << cityCreated << "\n";
    stream << yearCreated << "\n";
    stream << players.size() << "\n";
    for (int i = 0; i < players.size(); ++i)
    {
        stream << players[i].getName()
               << "\n"
               << players[i].getAge()
               << " " << static_cast<int>(players[i].getPosition())
               << " " << static_cast<int>(players[i].getStatus())
               << " " << static_cast<int>(players[i].getState())
               << "\n";
    }
}
void Team::loadFromStream(QTextStream& stream)
{
    int size;
    title = stream.readLine();
    cityCreated = stream.readLine();
    yearCreated = stream.readLine().toUShort();
    size = stream.readLine().toInt();
    players.clear();
    for (int i = 0; i < size; ++i)
    {
        QString name;
        ushort age;
        ushort position;
        ushort status;
        ushort state;
        name = stream.readLine();
        QStringList tmp = stream.readLine().split(" ");
        age = tmp[0].toUShort();
        position = tmp[1].toUShort();
        status = tmp[2].toUShort();
        state = tmp[3].toUShort();
        players.push_back(Player(name, age, static_cast<Position>(position), static_cast<HealthState>(state), static_cast<Status>(status)));
    }
}
