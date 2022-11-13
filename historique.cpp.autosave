#include "historique.h"

historique::historique()
{

}
historique::historique (QString b)
 {

    operation=b;

 }

void historique::Ajouter()
{
    QSqlQuery query;



    query.prepare("insert into HISTORIQUE(ID_H,NUM_AUD,DATE_H,OPERATION) values(ID_H.nextval,:NUM_AUD ,sysdate, :operation)");
   query.bindValue(":operation",operation);



 query.exec();
}
QSqlQueryModel * historique::Afficher( )
{
  QSqlQueryModel * model= new QSqlQueryModel();

       model->setQuery("select DATE_H, TYPE_OPERATION from HISTORIQUE ;");
       model->setHeaderData(0, Qt::Horizontal,QObject:: tr("date "));
       model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Operation"));

 return model;
}
