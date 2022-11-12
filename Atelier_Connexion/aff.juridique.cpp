#include "aff.juridique.h"
#include <QSqlQuery >
#include <QtDebug>
#include <QObject>
using namespace std;

Affjuridique::Affjuridique()
    {
        idavocat=0; nomaccuse=""; prenomaccuse="";numdossier=0; datenaissance=""; emprete=""; type="";
    }

Affjuridique::Affjuridique( int idavocat,int numdossier,QString nomaccuse,QString prenomaccuse,QString datenaissance,QString emprete,QString type,QString etat , QString dec ,int archive)
    {
        this->idavocat=idavocat;
        this->nomaccuse=nomaccuse;
        this->prenomaccuse=prenomaccuse;
        this->numdossier=numdossier;
        this->datenaissance=datenaissance;
        this ->emprete=emprete;
        this->type=type;
        this->etat_dossier = etat ; // ajouté
        this ->decision_dossier = dec ; // ajouté
        this ->archive = archive ; // ajouté
    }

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
    {
        //bool test=false;
        QString id_string= QString::number(idavocat);
        QSqlQuery query;
        query.prepare("INSERT INTO affjuridique(idavocat, nomaccuse, prenomaccuse,numdossier,datenaissance,emprete,type,etatdossier,decisiondossier,archive) "
                        "VALUES (:idavocat, :nomaccuse, :prenomaccuse, :numdossier, :datenaissance,:emprete, :type ,:etat,:decision,:archive)");
        query.bindValue(":idavocat", idavocat);
        query.bindValue(":nomaccuse", nomaccuse);
        query.bindValue( ":prenomaccuse",prenomaccuse);
        query.bindValue(":numdossier",numdossier);
        query.bindValue(":type",type);
        query.bindValue( ":emprete",emprete);
        query.bindValue( ":datenaissance",datenaissance);
        query.bindValue( ":etat",etat_dossier);
        query.bindValue( ":decision",decision_dossier);
        query.bindValue( ":archive",archive);
        return  query.exec();
    }

bool Affjuridique::supprimer(int numDoss)
    {
         QSqlQuery query;
         query.prepare(" Delete from affjuridique where numdossier=:num") ;
         query.bindValue(":num", numDoss);
         return  query.exec();
    }


QSqlQueryModel* Affjuridique::afficher()
    {
          QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM affjuridique where archive = 0");
          model->setHeaderData(0, Qt::Horizontal, QObject ::tr("Numero Dossier"));
          model->setHeaderData(1, Qt::Horizontal, QObject:: tr("Etat Dossier"));
          model->setHeaderData(2, Qt::Horizontal, QObject:: tr("Type Dossier"));
          model->setHeaderData(3, Qt::Horizontal, QObject:: tr("Decision"));
          model->setHeaderData(4, Qt::Horizontal, QObject:: tr("Nom Accusé"));
          model->setHeaderData(5, Qt::Horizontal, QObject:: tr("Prenom Accusé"));
          model->setHeaderData(6, Qt::Horizontal, QObject:: tr("Date de naissance"));
          model->setHeaderData(7, Qt::Horizontal, QObject:: tr("Empreinte"));
          model->setHeaderData(8, Qt::Horizontal, QObject:: tr("ID Avocat"));

          return model;
      }

QSqlQueryModel* Affjuridique::recherche(QString a)
    {
        QSqlQueryModel* model=new QSqlQueryModel();

        model->setQuery("SELECT * FROM affjuridique WHERE  ((numdossier LIKE '%"+a+"%' OR prenomaccuse LIKE '%"+a+"%' OR nomaccuse LIKE '%"+a+"%' OR idavocat LIKE '%"+a+"%') AND archive=0 )");

        model->setHeaderData(0, Qt::Horizontal, QObject ::tr("Numero Dossier"));
        model->setHeaderData(1, Qt::Horizontal, QObject:: tr("Etat Dossier"));
        model->setHeaderData(2, Qt::Horizontal, QObject:: tr("Type Dossier"));
        model->setHeaderData(3, Qt::Horizontal, QObject:: tr("Decision"));
        model->setHeaderData(4, Qt::Horizontal, QObject:: tr("Nom Accusé"));
        model->setHeaderData(5, Qt::Horizontal, QObject:: tr("Prenom Accusé"));
        model->setHeaderData(6, Qt::Horizontal, QObject:: tr("Date de naissance"));
        model->setHeaderData(7, Qt::Horizontal, QObject:: tr("Empreinte"));
        model->setHeaderData(8, Qt::Horizontal, QObject:: tr("ID Avocat"));

        return model;
    }

QSqlQueryModel* Affjuridique::trierparnom()
    {
            QSqlQueryModel* model=new QSqlQueryModel();

            model->setQuery("SELECT* FROM affjuridique WHERE archive = 0 ORDER BY nomaccuse ASC ");

            model->setHeaderData(0, Qt::Horizontal, QObject ::tr("Numero Dossier"));
            model->setHeaderData(1, Qt::Horizontal, QObject:: tr("Etat Dossier"));
            model->setHeaderData(2, Qt::Horizontal, QObject:: tr("Type Dossier"));
            model->setHeaderData(3, Qt::Horizontal, QObject:: tr("Decision"));
            model->setHeaderData(4, Qt::Horizontal, QObject:: tr("Nom Accusé"));
            model->setHeaderData(5, Qt::Horizontal, QObject:: tr("Prenom Accusé"));
            model->setHeaderData(6, Qt::Horizontal, QObject:: tr("Date de naissance"));
            model->setHeaderData(7, Qt::Horizontal, QObject:: tr("Empreinte"));
            model->setHeaderData(8, Qt::Horizontal, QObject:: tr("ID Avocat"));

          return model;
      }

bool Affjuridique::update_archive(int numDoss) // ajouté
    {
        QSqlQuery query;
        query.prepare("UPDATE affjuridique SET archive=:archive WHERE numdossier=:num") ;
        query.bindValue(":archive", 1);
        query.bindValue(":num", numDoss);

        return  query.exec();
    }

bool Affjuridique::update_desarchive(int numDoss) // ajouté
    {
        QSqlQuery query;
        query.prepare("UPDATE affjuridique SET archive=:archive WHERE numdossier=:num") ;
        query.bindValue(":archive", 0);
        query.bindValue(":num", numDoss);

        return  query.exec();
    }

QSqlQueryModel* Affjuridique::afficher_archive() //ajouté
    {
           QSqlQueryModel* model=new QSqlQueryModel();

           model->setQuery("SELECT* FROM affjuridique where archive = 1");
           model->setHeaderData(0, Qt::Horizontal, QObject ::tr("Numero Dossier"));
           model->setHeaderData(1, Qt::Horizontal, QObject:: tr("Etat Dossier"));
           model->setHeaderData(2, Qt::Horizontal, QObject:: tr("Type Dossier"));
           model->setHeaderData(3, Qt::Horizontal, QObject:: tr("Decision"));
           model->setHeaderData(4, Qt::Horizontal, QObject:: tr("Nom Accusé"));
           model->setHeaderData(5, Qt::Horizontal, QObject:: tr("Prenom Accusé"));
           model->setHeaderData(6, Qt::Horizontal, QObject:: tr("Date de naissance"));
           model->setHeaderData(7, Qt::Horizontal, QObject:: tr("Empreinte"));
           model->setHeaderData(8, Qt::Horizontal, QObject:: tr("ID Avocat"));

           return model;
       }

