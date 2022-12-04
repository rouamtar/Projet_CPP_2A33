#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
#include "perso.h"

perso::perso(){
 CIN=0;
 num=0;
 nomprenom="";
 adr="";
 poste="";

}
perso::perso(int CIN,int num,QString nomprenom,QString adr,QString poste)
{
    this->CIN=CIN;
    this->num=num;
    this->nomprenom=nomprenom;
    this->adr=adr;
    this->poste=poste;

}

bool perso::ajouter(){
    QSqlQuery query;
    QString CIN_string=QString::number(CIN);
    QString num_string=QString::number(num);

    query.prepare("INSERT INTO perso (nomprenom,CIN,num,adr,poste)"
                   "VALUES (:nomprenom, :CIN, :num, :adr,:poste)");
          query.bindValue(":nomprenom", nomprenom);
          query.bindValue(":CIN", CIN_string);
          query.bindValue(":num", num_string);
          query.bindValue(":adr", adr);
          query.bindValue(":poste", poste);

          return query.exec();}


bool perso::supprimer(int CIN){
    QSqlQuery query;
    QString res=QString::number(CIN);
    query.prepare("Delete from PERSO where CIN= :CIN");
    query.bindValue(":CIN",res);
    return query.exec();}


QSqlQueryModel* perso::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from perso");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nomprenom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("num"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adr"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("poste"));
    return model;}



QSqlQueryModel* perso::recherche_CIN(int CIN){
           QSqlQuery query;
           query.prepare(QString("SELECT * FROM perso WHERE CIN=:CIN"));
           query.bindValue(":CIN",CIN);
           query.exec();
             QSqlQueryModel* model=new QSqlQueryModel();
                model->setQuery(query);
                model->setHeaderData(0, Qt::Horizontal, QObject::tr("nomprenom"));
                model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
                model->setHeaderData(2, Qt::Horizontal, QObject::tr("num"));
                model->setHeaderData(3, Qt::Horizontal, QObject::tr("adr"));
                model->setHeaderData(4, Qt::Horizontal, QObject::tr("poste"));
                return model;}



bool perso::modifier(int CIN , int num , QString nomprenom , QString adr, QString poste){
    QSqlQuery query;
    query.prepare("UPDATE perso SET nomprenom=:newnomprenom,CIN=:newCIN,num=:newnum,adr=:newadr,poste=:newposte WHERE CIN=:newCIN");
    query.bindValue(":newnomprenom",nomprenom);
    query.bindValue(":newCIN",CIN);
    query.bindValue(":newnum",num);
    query.bindValue(":newadr",adr);
    query.bindValue(":newposte",poste);
   //if(query.exec()){return true;}
       // else {return false;}
    return query.exec();}
