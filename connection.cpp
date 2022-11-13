#include "connection.h"

Connection::Connection()
{}

bool Connection::createconnect(){


   db= QSqlDatabase::addDatabase("QODBC");
   db.setDatabaseName("Source_Projet2A");
   db.setUserName("Ahmedk");//inserer nom de l'utilisateur
   db.setPassword("esprit01");//inserer mot de passe de cet utilisateur
   if (db.open())
      return true;
      return false;}




void Connection::closeConnection(){db.close();}
