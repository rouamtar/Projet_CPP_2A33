#include "audience.h"
#include<QDate>
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include <QFileDialog>
#include<QSoundEffect>
#include <QIcon>

Audience::Audience()
{ salle=0;duree=0;
}

Audience::Audience( int salle ,int  duree, QDate dateAU )
{
    //this->Num_aud=Num_aud;
    this->salle=salle ;
    this->duree=duree;
    this->dateAU=dateAU;
}
//int Audience::getnum_aud() {return Num_aud;}
int Audience::getduree() {return duree;}
int Audience::getsalle() {return salle;}
QDate Audience::getdateAU() {return dateAU;}
//void Audience:: setnum_aud(int Num_aud){this->Num_aud=Num_aud;}
void Audience::setsalle(int salle){this ->salle=salle;}
void Audience::setduree(int duree){this->duree= duree;}
void Audience::setdateAU(QDate dateAU){this->dateAU= dateAU;}
bool Audience::ajouter()
{

   // QString Num_aud_string=QString::number(Num_aud);
    QString salle_string=QString::number(salle);
    QString duree_string=QString::number(duree);
    QSqlQuery query;
         query.prepare("INSERT INTO audiences(Num_aud,salle,duree,date_a) VALUES (num_aud.nextval, :salle, :duree, :date_a)");
         //query.bindValue(":Num_aud",Num_aud);
         query.bindValue(":salle",salle);
         query.bindValue(":duree",duree);
         query.bindValue(":date_a",dateAU);

       return  query.exec();

}

bool Audience::supprimer(int  Num_aud)
{
    QSqlQuery query;
        query.prepare(" delete from Audiences where num_aud=:num_aud");
         query.bindValue(":num_aud", Num_aud);
        return query.exec();
}


QSqlQueryModel*Audience::afficher()

{
    QSqlQueryModel*model=new  QSqlQueryModel();


    model->setQuery("SELECT *  FROM AUDIENCES ");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("Num"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr ("salle"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr ("duree"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr ("DATE"));



 return model;
}

QSqlQueryModel *Audience::rechercher(QString salle)

{

QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * From Audiences  where salle  like '"+salle+"%' ORDER BY date_a");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
model->setHeaderData(3, Qt::Horizontal,QObject:: tr("date"));
model->setHeaderData(1, Qt::Horizontal,QObject:: tr("salle"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("duree"));
return model;
}


QSqlQueryModel * Audience ::TrieA(int)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select Num_aud,salle,duree,date_a From Audiences ORDER BY date_a ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Num"));
    model->setHeaderData(3, Qt::Horizontal,QObject:: tr("date"));
    model->setHeaderData(1, Qt::Horizontal,QObject:: tr("salle"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("duree"));

    return model;
}

bool modifier(int,int,int,QDate);
bool Audience::modifier(int num ,int salle,int duree,QDate date)
 {
       QSqlQuery query;
       QString num_str=QString::number(num);

    query.prepare("UPDATE Audiences SET salle= :salle,duree= :duree,date_a =:datee where num_aud  like '"+num_str+"%'");
    query.bindValue(":salle",salle);
    query.bindValue(":duree",duree);
    query.bindValue(":datee",date);


    return query.exec();
 }



void Audience::notifcation()
{
    int n=0;
    QSqlQuery requete("select date_a from Audiences where date_a  like (sysdate+2);");
 while(requete.next())
     {
     n++;
      }
 if(n!=0)

 {
 QSystemTrayIcon *trayIcon = new QSystemTrayIcon;
             trayIcon->setIcon(QIcon(":/new/prefix2/notif.png"));
             trayIcon->show();
             trayIcon->showMessage("Attention" ,"Vous avez une audience dans deux jours",QSystemTrayIcon::Information,15000);
             if(trayIcon)
             {
                QSoundEffect * sound_effect = new QSoundEffect;
                   sound_effect->setSource(QUrl("qrc:/new/prefix1/sound.wav"));
                // sound_effect->setLoopCount(QSoundEffect::Infinite);
                   sound_effect->setVolume(0.9);
                   sound_effect->play();
                //  QEventLoop loop;
                //  loop.exec();
              }

  }
}


