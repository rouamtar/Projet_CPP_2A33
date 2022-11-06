#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"aff.juridique.h"
#include <QMessageBox>
#include<QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0, 9999999, this));
    ui->tab_affjuridique->setModel(A.afficher());
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pbAjouter_clicked()
{
    int idavocat=ui->le_id->text().toInt();
    QString nomaccuse=ui->le_nom->text();
    QString prenomaccuse=ui->le_prenom->text();
    int numdossier=ui->le_num->text().toInt();
    QString type=ui->le_type->text();
    QString date=ui->le_date->text();
    QString emprete=ui->lemprete->text();

    Affjuridique A (idavocat, numdossier, nomaccuse, prenomaccuse, date, emprete, type);



   bool test=A.ajouter();
   QMessageBox msgBox;
   if(test)
      { msgBox.setText("Ajout avec succes.");
       ui->tab_affjuridique->setModel(A.afficher());
   }
   else
       msgBox.setText("Echec d'ajout");
   msgBox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
    Affjuridique A1; A1.setidavocat(ui->le_id_supp->text().toInt());
    bool test=A1.supprimer(A1.getidavocat());
    QMessageBox msgBox;
    if(test)
       { msgBox.setText("Suppression avec succes.");
    ui->tab_affjuridique->setModel(A.afficher());
    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();
 }







