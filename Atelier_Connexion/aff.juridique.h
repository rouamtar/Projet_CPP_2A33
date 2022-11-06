#ifndef AFFJURIDIQUE_H
#define AFFJURIDIQUE_H
#include <QString>
#include <QSqlQueryModel>

class Affjuridique
{
public:
    Affjuridique();
    Affjuridique(int,int,QString,QString,QString,QString,QString);
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
   QSqlQueryModel* afficher();
   bool supprimer(int);

 private:
        int idavocat,numdossier;
    QString type,prenomaccuse,nomaccuse,emprete,datenaissance;

};

#endif // ETUDIANT_
