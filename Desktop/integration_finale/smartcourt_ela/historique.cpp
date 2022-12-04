#include "historique.h"

historique::historique()
{

}
historique::historique (QString b,int a)
 {
    id=a;
    operation=b;

 }

void historique::Ajouter()
{
    QSqlQuery query;


     QString num_str=QString::number(id);
    query.prepare("insert into HISTORIQUE(ID_H,NUM_AUD,DATE_H,OPERATION) values(ID_H.nextval,:NUM_AUD ,sysdate, :operation)");
   query.bindValue(":operation",operation);
   query.bindValue(":NUM_AUD",num_str);



 query.exec();
}
QSqlQueryModel * historique::Afficher( )
{
  QSqlQueryModel * model= new QSqlQueryModel();

       model->setQuery("select DATE_H,NUM_AUD,OPERATION from HISTORIQUE ;");
       model->setHeaderData(0, Qt::Horizontal,QObject:: tr("date "));
       model->setHeaderData(2, Qt::Horizontal,QObject:: tr("Operation"));
       model->setHeaderData(1, Qt::Horizontal,QObject:: tr("Id"));

 return model;
}
