#ifndef PERSO_H
#define PERSO_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>




class perso
{
    int CIN,num;
    QString  adr,poste,nomprenom;


public:
    perso();
    perso(int,int,QString,QString,QString);
    QString get_nomprenom(){return nomprenom;}
    int get_CIN(){return CIN;}
    int get_num(){return num;}
    QString get_adr (){return adr;}
    QString get_poste (){return poste;}

    void set_nomprenom(QString nomprenom){this->nomprenom=nomprenom;}
    void set_CIN(int CIN){this->CIN=CIN;}
    void set_num(int num){this->num=num;}
    void set_adr(QString adr){this->adr=adr;}
    void set_poste(QString poste){this->poste=poste;}



    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel* recherche_CIN(int Numsalle);
    bool supprimer(int);
    bool modifier (int CIN , int num , QString nomprenom , QString adr, QString poste);


};








#endif // PERSO_H
