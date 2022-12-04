#ifndef DC_H
#define DC_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>




class dc
{
    int CIN,ID,code_bancaire;
    QString  etat_sante;


public:
    dc();
    dc(int,QString,int,int);
    QString get_etat_sante(){return etat_sante;}
    int get_CIN(){return CIN;}
    int get_ID(){return ID;}
    int get_code_bancaire(){return code_bancaire;}



    void set_etat_sante(QString etat_sante){this->etat_sante=etat_sante;}
    void set_CIN(int CIN){this->CIN=CIN;}
    void set_ID(int ID){this->ID=ID;}
    void set_code_bancaire (int code_bancaire){this->code_bancaire=code_bancaire;}


    QSqlQueryModel* afficher();



};
#endif // DC_H
