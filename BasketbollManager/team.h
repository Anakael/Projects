#ifndef TEAM_H
#define TEAM_H
#include <QDebug>
#include <QList>
#include <QString>

enum class Position
{
    Guard,
    Forward,
    Center
};
enum class Status
{
    Primary,
    Bench
};
enum class HealthState
{
    Healthy,
    Injured
};
class Player
{
private:
    QString name;
    ushort age;
    Position position;
    HealthState state;
    Status status;

public:
    Player()
        : name("")
        , age(20)
        , position(Position::Forward)
        , state(HealthState::Healthy)
        , status(Status::Bench)
    {}

    Player(QString _name, ushort _age, Position _pos, HealthState _state, Status _status)
        : name(_name)
        , age(_age)
        , position(_pos)
        , state(_state)
        , status(_status)
    {}
    QString getName() const { return name; }
    ushort getAge() const { return age; }
    Position getPosition() const { return position; }
    HealthState getState() const { return state; }
    Status getStatus() const { return status; }
    void setName(QString sr) { name = sr; }
    void setAge(ushort _age) { age = _age; }
    void setPosition(Position _pos) { position = _pos; }
    void setStatus(Status _status) { status = _status; }
    void setState(HealthState _state) { state = _state; }
};
class Team
{
public:
    Team() = delete;
    static QString title;
    static QString cityCreated;
    static ushort yearCreated;
    static QList<Player> players;
    static void initTeam(QString _title, QString _cityCreated, ushort _yearCreated, QList<Player>&& _players);
    static const QStringList listPos;
    static const QStringList listState;
    static const QStringList listStatus;
    static bool isInited;
    static void flushToStream(QTextStream& strem);
    static void loadFromStream(QTextStream& strem);
};

class Parent
{
protected:
public:
    virtual void lol() const = 0;
    virtual ~Parent() {}
};
class Derived : public Parent
{
    void lol() const override
    {
    }
};

#endif // TEAM_H
