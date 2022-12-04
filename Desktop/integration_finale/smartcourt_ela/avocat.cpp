#include "avocat.h"
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include<QSystemTrayIcon>
AVOCAT::AVOCAT(int id ,QString nom ,QString prenom,QString classe)

{
   this -> id=id;
   this -> nom =nom ;
   this -> prenom =prenom ;
    this -> classe =classe ;

}
bool AVOCAT::ajouter ()
{
QSqlQuery query;
QString res =QString::number(id);
query.prepare("insert into AVOCAT (nom,prenom,classe) values (:nom,:prenom,:classe)");
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":classe",classe);
return query.exec();
}

bool AVOCAT::modifier(int id)
{
    QSqlQuery query;
    query.prepare("update AVOCAT set nom = ?, prenom = ?, classe = ? where id = ?");
    query.addBindValue(nom);
    query.addBindValue(prenom);
    query.addBindValue(classe);
    query.addBindValue(id);

    return query.exec();
}
bool AVOCAT::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("Delete from AVOCAT where ID= :id");
    query.bindValue(":id",res);
    return query.exec();
}

  QSqlQueryModel * AVOCAT :: afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from avocat");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("classe"));
    return model;
}
  QSqlQueryModel * AVOCAT::rechercher(QString arg1){
      QSqlQueryModel *model=new QSqlQueryModel();
      QSqlQuery   query;
      query.prepare("SELECT * FROM AVOCAT WHERE id  LIKE'%"+arg1+"%' or nom  LIKE'%"+arg1+"%' or prenom LIKE'%"+arg1+"%' or classe LIKE'%"+arg1+"%' ");
       query.exec();
      model->setQuery(query);

      model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("classe"));

     return model;
  }
      QSqlQueryModel *AVOCAT:: trier(QString input){
      QSqlQueryModel *model=new QSqlQueryModel();
      model->setQuery("select * from AVOCAT  order by "+input);
      model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
      model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
      model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("classe"));

      return  model;
  }
      void AVOCAT::notification_ajoutavocat()
      {

          QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
          notifyIcon->show();
          notifyIcon->showMessage("Gestion des avocats ","Nouvau avocat ajoute ",QSystemTrayIcon::Information,15000);
      }


      void AVOCAT::notification_suppavocat()
      {

          QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
          notifyIcon->show();
          notifyIcon->showMessage("Gestion des avocats ","avocat supprime ",QSystemTrayIcon::Information,15000);
      }

      void AVOCAT::notification_modifavocat()
      {

          QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
          notifyIcon->show();
          notifyIcon->showMessage("Gestion des avocats ","avocat modifie ",QSystemTrayIcon::Information,15000);
      }
