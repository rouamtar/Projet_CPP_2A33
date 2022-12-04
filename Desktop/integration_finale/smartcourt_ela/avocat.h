#ifndef AVOCAT_H
#define AVOCAT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class AVOCAT
{
    QString nom ,prenom,classe;
    int id;
public:
    AVOCAT(){}
    AVOCAT(int,QString,QString,QString);
    QString getnom(){return  nom;}
    QString getprenom(){return  prenom;}
     QString getclasse(){return  classe;}
      int getID(){return  id;}
      void setnom(QString n){nom=n;}
      void setprenom(QString p){prenom=p;}
      void setclasse(QString c){classe=c;}
      void setID(int id){this ->id=id;}
      bool ajouter();
      bool modifier(int);
      QSqlQueryModel * afficher() ;
      bool supprimer (int);
      QSqlQueryModel* rechercher(QString arg1);
      QSqlQueryModel* trier(QString);
      void notification_ajoutavocat();
      void notification_suppavocat();
      void notification_modifavocat();

};


#endif // AVOCAT_H
