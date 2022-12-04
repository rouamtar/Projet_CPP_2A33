#include "connection.h"



Connection::Connection()
{}

bool Connection::createconnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test-bd");
    db.setUserName("system");
    db.setPassword("aziiz1");

    if (db.open())
        return true;
    return false;
}
void Connection::closeconnection(){db.close();}
