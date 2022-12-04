#include "connection.h"



Connection::Connection()
{}

bool Connection::createconnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("system");
    db.setPassword("211JFT8245");

    if (db.open())
        return true;
    return false;
}
void Connection::closeconnection(){db.close();}
