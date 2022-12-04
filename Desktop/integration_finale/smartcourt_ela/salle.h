#ifndef SALLE_H
#define SALLE_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class salle
{
    int Numsalle, etage, capaciter;
    QString  type,etat;


public:
    salle() {}
    salle(int,int,int,QString,QString);
    int getNumSalle(){return Numsalle;}
    int getetage(){return etage;}
    int getcapaciter(){return capaciter;}
    QString gettype(){return type;}
    QString getetat(){return etat;}
    void setNumSalle(int Numsalle){this->Numsalle=Numsalle;}
    void setetage(int etage){this->etage=etage;}
    void setcapaciter(int capaciter){this->capaciter=capaciter;}
    void settype(QString t){type=t;}
    void setetat(QString e){etat=e;}
    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel* recherche_Numsalle(int Numsalle);
    bool supprimer(int);
    bool modifier_salle(int Numsalle,int etage,int capaciter, QString type ,QString etat);


};

#endif // SALLE_H
