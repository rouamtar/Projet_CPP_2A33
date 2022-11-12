#ifndef AFFJURIDIQUE_H
#define AFFJURIDIQUE_H
#include <QString>
#include <QSqlQueryModel>

class Affjuridique
{
public:
    Affjuridique();
    Affjuridique(int,int,QString,QString,QString,QString,QString,QString,QString,int); // constructeur modifié
    int getnumdossier();
    int getidavocat();
    QString gettype();
    QString getnomaccuse();
    QString getprenomaccuse();
    QString getdatenaissance();
    QString getemprete();
    void setidavocat(int);
    void setnomaccuse(QString);
    void setprenomaccuse(QString);
    void setnumdossier(int);
    void settype(QString);
    void setdatenaissance(QString);
    void setemprete(QString);
    bool ajouter();
   QSqlQueryModel* afficher(); // affichage modifié
   bool supprimer(int); // modifié
   QSqlQueryModel* recherche(QString A); // modifié
   QSqlQueryModel* trierparnom(); // modifié
   bool update_archive(int numDoss); // ajouté
    QSqlQueryModel*afficher_archive(); // ajouté
    bool update_desarchive(int numDoss); // ajouté

 private:
    int numdossier;
    QString type,etat_dossier,decision_dossier; // etat et decision ajouté
    QString prenomaccuse,nomaccuse,emprete,datenaissance;
    int idavocat;
    int archive ; // ajouté
};

#endif // ETUDIANT_
