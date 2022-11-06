#include "aff.juridique.h"

#include <QSqlQuery >
#include <QtDebug>
#include <QObject>
using namespace std;

Affjuridique::Affjuridique()
{
idavocat=0; nomaccuse=""; prenomaccuse="";numdossier=0; datenaissance=""; emprete=""; type="";

}

Affjuridique::Affjuridique( int idavocat,int numdossier,QString nomaccuse,QString prenomaccuse,QString datenaissance,QString emprete,QString type)
{this->idavocat=idavocat; this->nomaccuse=nomaccuse;this->prenomaccuse=prenomaccuse;this->numdossier=numdossier;this->datenaissance=datenaissance;this ->emprete=emprete;this->type=type;}

int Affjuridique::getidavocat() {return idavocat;}
QString Affjuridique::getnomaccuse() {return nomaccuse;}
QString Affjuridique::getprenomaccuse() {return prenomaccuse;}
int Affjuridique::getnumdossier() {return numdossier;}
QString Affjuridique::getdatenaissance() {return datenaissance ;}
QString Affjuridique::getemprete() {return emprete;}
QString Affjuridique::gettype() {return type;}
void Affjuridique ::setidavocat(int idavocat) {this->idavocat=idavocat;}
void Affjuridique ::setnomaccuse(QString nomaccuse){this->nomaccuse=nomaccuse;}
void Affjuridique ::setprenomaccuse(QString prenomaccuse){this->prenomaccuse=prenomaccuse;}



void Affjuridique :: setnumdossier(int numdossier){this->numdossier=numdossier;}
void Affjuridique :: settype(QString type){this->type=type;}
void Affjuridique :: setdatenaissance(QString datenaissance){this->datenaissance=datenaissance;}
void Affjuridique ::setemprete(QString emprete){this->emprete=emprete;}
bool Affjuridique ::ajouter()
{//bool test=false;




    QString id_string= QString::number(idavocat);
     QSqlQuery query;
          query.prepare("INSERT INTO affjuridique(idavocat, nomaccuse, prenomaccuse,numdossier,datenaissance,emprete,type) "
                        "VALUES (:idavocat, :nomaccuse, :prenomaccuse, :numdossier, :datenaissance,:emprete, :type)");
          query.bindValue(":idavocat", idavocat);
          query.bindValue(":nomaccuse", nomaccuse);
          query.bindValue( ":prenomaccuse",prenomaccuse);
           query.bindValue(":numdossier",numdossier);
           query.bindValue(":type",type);
            query.bindValue( ":emprete",emprete);
              query.bindValue( ":datenaissance",datenaissance);

        return  query.exec();


}
bool Affjuridique::supprimer(int idavocat)
{
    QSqlQuery query;
         query.prepare(" Delete from affjuridique where idavocat=:idavocat") ;

         query.bindValue(0, idavocat);

       return  query.exec();

}
QSqlQueryModel* Affjuridique::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM affjuridique");
          model->setHeaderData(0, Qt::Horizontal, QObject ::tr("idavocat"));
          model->setHeaderData(1, Qt::Horizontal, QObject:: tr("nomaccuse"));
          model->setHeaderData(2, Qt::Horizontal, QObject:: tr("prenomaccuse"));
          model->setHeaderData(3, Qt::Horizontal, QObject:: tr("numdossuer"));
          model->setHeaderData(4, Qt::Horizontal, QObject:: tr("emprete"));
          model->setHeaderData(5, Qt::Horizontal, QObject:: tr("date"));
          model->setHeaderData(6, Qt::Horizontal, QObject:: tr("type"));




    return model;
}
