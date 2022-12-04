#include "salle.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>






salle::salle(int Numsalle,int etage,int capaciter,QString type ,QString etat){
    this->Numsalle=Numsalle;
    this->etage=etage;
    this->capaciter=capaciter;
    this->type=type;
    this->etat=etat;}



bool salle::ajouter(){
    QSqlQuery query;
    QString Numsalle_string=QString::number(Numsalle);
    QString etage_string=QString::number(etage);
    QString capaciter_string=QString::number(capaciter);
    query.prepare("INSERT INTO salle (Numsalle,etage,capaciter,type,etat)"
                   "VALUES (:Numsalle, :etage, :capaciter, :type , :etat)");
          query.bindValue(":Numsalle", Numsalle_string);
          query.bindValue(":etage", etage_string);
          query.bindValue(":capaciter", capaciter_string);
          query.bindValue(":type", type);
          query.bindValue(":etat", etat);
          return query.exec();}



bool salle::supprimer(int Numsalle){
    QSqlQuery query;
    QString res=QString::number(Numsalle);
    query.prepare("Delete from salle where Numsalle= :Numsalle");
    query.bindValue(":Numsalle",res);
    return query.exec();}




QSqlQueryModel* salle::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select * from salle");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numsalle"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("etage"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("capaciter"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("etat"));
    return model;}



QSqlQueryModel* salle::recherche_Numsalle(int Numsalle){
           QSqlQuery query;
           query.prepare(QString("SELECT * FROM salle WHERE Numsalle=:Numsalle"));
           query.bindValue(":Numsalle",Numsalle);
           query.exec();
             QSqlQueryModel* model=new QSqlQueryModel();
                model->setQuery(query);
                model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numsalle"));
                model->setHeaderData(1, Qt::Horizontal, QObject::tr("etage"));
                model->setHeaderData(2, Qt::Horizontal, QObject::tr("capaciter"));
                model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
                model->setHeaderData(4, Qt::Horizontal, QObject::tr("etat"));
                return model;}

bool salle::modifier_salle(int Numsalle,int etage,int capaciter,QString type,QString etat)
{
    QSqlQuery query;
    query.prepare("UPDATE salle SET NUMSALLE=:newNumsalle,ETAGE=:newetage,CAPACITER=:newcapaciter,TYPE=:newtype ,ETAT=:newetat WHERE NUMSALLE=:newNumsalle");

    query.bindValue(":newNumsalle",Numsalle);
    query.bindValue(":newetage",etage);
    query.bindValue(":newcapaciter",capaciter);
    query.bindValue(":newtype",type);
    query.bindValue(":newetat",etat);
   //if(query.exec()){return true;}
       // else {return false;}

    return query.exec();

}






