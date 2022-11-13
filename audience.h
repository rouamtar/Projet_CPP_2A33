#ifndef AUDIENCE_H
#define AUDIENCE_H
#include<QDateTime>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QDate>
#include <QTime>
#include <QStringList>
#include <QSystemTrayIcon>
//#include<QSoundEffect>
#include <QIcon>

class Audience
{
private:
  int salle,duree;
   QDate dateAU;
public:
    Audience();
    Audience(int,int,QDate );


    int getsalle();
    int getduree();
    QDate getdateAU();
    void setsalle(int);
    void setduree(int);
    void setdateAU(QDate);
    bool ajouter();
    QSqlQueryModel*afficher();
    QSqlQueryModel * rechercher(QString);
   QSqlQueryModel * TrieA(int);
   void notifcation();
    bool modifier(int,int,int,QDate);
    bool supprimer(int);


};

#endif // AUDIENCE_H
