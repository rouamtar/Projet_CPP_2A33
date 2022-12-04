#include "connection.h"



Connection::Connection()
{}

bool Connection::createconnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("data_base");
    db.setUserName("ash");
    db.setPassword("ash");

    if (db.open())
        return true;
    return false;
}
void Connection::closeconnection(){db.close();}
