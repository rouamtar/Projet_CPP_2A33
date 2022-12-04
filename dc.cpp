#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
#include "dc.h"


dc::dc(){
 code_bancaire=0;
 etat_sante="";
 ID=0;
 CIN=0;

}
dc::dc(int code_bancaire,QString etat_sante,int ID,int CIN)
{
    this->code_bancaire=code_bancaire;
    this->etat_sante=etat_sante;
    this->ID=ID;
    this->CIN=CIN;

}


QSqlQueryModel* dc::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from dc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code_bancaire"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat_sante"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
    return model;}
