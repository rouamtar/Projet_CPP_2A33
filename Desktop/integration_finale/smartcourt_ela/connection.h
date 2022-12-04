#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "perso.h"

class Connection
{
    QSqlDatabase db ;
public:
    Connection();
    bool createconnection();
    void closeconnection();
};

#endif // CONNECTION_H
