#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QtSql>
#include <QList>
#include "item.h"
#include "constants.h"
#include <QSqlDatabase>

class DatabaseManager
{
private:
    DatabaseManager();
    ~DatabaseManager();

    QSqlDatabase myDB;

public:
    static DatabaseManager& instance();
    bool isOpen() const;

    DatabaseManager(const DatabaseManager&) = delete; //delete copy constructor.
    void operator =(const DatabaseManager&) = delete; //delete = operator.

    // inventory functions for database
    // items
    bool AddItem(const Item& newItem);
    bool RemoveItem(const Item& item);
    bool ItemExists(const Item& item) const;

    // members
    bool MemberExists(QString& id);
    bool AddMember(QString name, QString id, QString memType, QString expDate);
    bool deleteMember(QString);
};
#endif // DATABASEMANAGER_H
