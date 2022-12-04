#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class historique
{
private:
    QString operation;
     int id ;



public:
    historique();
    historique(QString,int);
    void Ajouter();
    QSqlQueryModel * Afficher( );



};

#endif // HISTORIQUE_H
