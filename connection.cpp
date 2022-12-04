#include "connection.h"



Connection::Connection()
{}

bool Connection::createconnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test");
    db.setUserName("roua");
    db.setPassword("esprit22");

    if (db.open())
        return true;
    return false;
}
void Connection::closeconnection(){db.close();}
