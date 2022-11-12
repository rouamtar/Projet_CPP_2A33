#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"aff.juridique.h"
#include <QMessageBox>
#include<QIntValidator>
#include <QSqlQuery>
////
#include <QtCharts>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0, 9999999, this));
    ui->tab_affjuridique->setModel(A.afficher());
    ui->tableView_archive_dossier->setModel(A.afficher_archive()); // ajouté // affichage table view archive
    ui->stackedWidget->setCurrentIndex(0); // ajouté // stacked widget first window
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
    QString type=ui->comboBox_type->currentText();
    QString date=ui->le_date->text();
    QString emprete=ui->lemprete->text();
    QString etat=ui->comboBox_etat->currentText();
    QString dec=ui->le_dec->text();

    Affjuridique A (idavocat, numdossier, nomaccuse, prenomaccuse, date, emprete, type,etat,dec,0); // 0 par défaut pour l'archive

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

void MainWindow::on_le_recherche_textChanged(const QString &arg1)
{

ui->tab_affjuridique->setModel(A.recherche(arg1));

}

void MainWindow::on_pushButton_triernom_clicked()
{
  ui->tab_affjuridique->setModel(A.trierparnom());
}

///////////////////////////////////////////// statistique
QVector<double> MainWindow::statistiques()
{
    QSqlQuery q;
    QVector<double> stat(5);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;

    q.prepare("SELECT type FROM affjuridique WHERE type='Divorce'");
    q.exec();
    while (q.next())
    {
        stat[0]++;

    }
    q.prepare("SELECT type FROM affjuridique WHERE type='Rape'");
    q.exec();
    while (q.next())
    {
        stat[1]++;

    }
    q.prepare("SELECT type FROM affjuridique WHERE type='Murder'");
    q.exec();
    while (q.next())
    {
        stat[2]++;

    }
    q.prepare("SELECT type FROM affjuridique WHERE type='Theft'");
    q.exec();
    while (q.next())
    {
        stat[3]++;

    }

    return stat;
}

void MainWindow::makePlot()
{
    // prepare data:
    QVector<double> x3(5), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
      y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->customplot->xAxis, ui->customplot->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, MainWindow::statistiques());//////////////////////////////////////////fonction statistiques
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->customplot->replot();

    // move bars above graphs and grid below bars:
    ui->customplot->addLayer("abovemain", ui->customplot->layer("main"), QCustomPlot::limAbove);
    ui->customplot->addLayer("belowmain", ui->customplot->layer("main"), QCustomPlot::limBelow);
    ui->customplot->xAxis->grid()->setLayer("belowmain");
    ui->customplot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4; //<<5<<6<<7;//////
    QVector<QString> labels;
    labels<<"Divorce"<<"Rape"<<"Murder"<<"Theft";////////////////////////////////////////
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->customplot->xAxis->setTicker(textTicker);
    ui->customplot->xAxis->setSubTicks(false);
    ui->customplot->xAxis->setTickLength(0,4);
    ui->customplot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customplot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customplot->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->customplot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customplot->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customplot->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customplot->xAxis->setTickLabelColor(Qt::white);
    ui->customplot->yAxis->setTickLabelColor(Qt::white);
    ui->customplot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customplot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customplot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customplot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customplot->xAxis->grid()->setSubGridVisible(true);
    ui->customplot->yAxis->grid()->setSubGridVisible(true);
    ui->customplot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customplot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customplot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customplot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(00, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->customplot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));//
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->customplot->axisRect()->setBackground(axisRectGradient);

    ui->customplot->rescaleAxes();
    ui->customplot->xAxis->setRange(0, 7);
    ui->customplot->yAxis->setRange(0, 10);


}

///////////////////////////////////////////////////////// fin stat

void MainWindow::on_pushButton_connexion_clicked() // athentification
{
    QMessageBox msgBox;
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    if(username == "admin" && password == "admin"){
        msgBox.setText("Connecté avec succes.");
        msgBox.exec();
        ui->stackedWidget->setCurrentIndex(1);

    }
    else {
        {
            msgBox.setText("Mot de passe ou username erroné");
            msgBox.exec();
        }
    }
}

void MainWindow::on_pushButton_archiver_roua_clicked() // bouton archiver
{
     QMessageBox msgBox;
    int numdoss_archive=ui->tab_affjuridique->model()->data(ui->tab_affjuridique->model()->index(ui->tab_affjuridique->currentIndex().row(),0)).toInt();
    QString etat = ui->tab_affjuridique->model()->data(ui->tab_affjuridique->model()->index(ui->tab_affjuridique->currentIndex().row(),1)).toString();
       if ( etat != "Fini")
       {
           msgBox.setText("Ce dossier est en cours, il ne peut pas être archivé ");

       }
       else
       {
            bool test = A.update_archive(numdoss_archive) ;
                if (test)
                {
                    msgBox.setText(" dossier archivé avec succes ");
                    ui->tab_affjuridique->setModel(A.afficher());
                    ui->tableView_archive_dossier->setModel(A.afficher_archive());
                }
                else
                    {
                        msgBox.setText(" echec de l'archivage ");
                    }
                }
       msgBox.exec();
}



void MainWindow::on_pushButton_desarchiver_clicked() // bouton desarchiver
{
    QMessageBox msgBox;
   int numdoss_desarchive=ui->tableView_archive_dossier->model()->data(ui->tableView_archive_dossier->model()->index(ui->tableView_archive_dossier->currentIndex().row(),0)).toInt();
           bool test = A.update_desarchive(numdoss_desarchive) ;
               if (test)
               {
                   msgBox.setText(" dossier desarchivé avec succes ");
                   ui->tab_affjuridique->setModel(A.afficher());
                   ui->tableView_archive_dossier->setModel(A.afficher_archive());
               }
               else
                   {
                       msgBox.setText(" echec de desarchivage ");
                   }

      msgBox.exec();
}

void MainWindow::on_stat_roua_clicked() // bouton stat
{
    ui->customplot->clearPlottables();
    MainWindow::makePlot();
    MainWindow::makePlot();
}


void MainWindow::on_PDF_roua_clicked() // bouton pdf
{
    QSqlQuery query;
    int id;

    id=ui->tab_affjuridique->model()->data(ui->tab_affjuridique->model()->index(ui->tab_affjuridique->currentIndex().row(),0)).toInt();
    QString res=QString::number(id);



    QPdfWriter pdf("C:/Users/roua mtar/Desktop/rouafinal/affaire.pdf");
        QPainter painter(&pdf);
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(2000,1200,"DOSSIER NUMERO: "+res);

        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 50));
        painter.drawRect(2000,3000,5000,9000);
        painter.setFont(QFont("Arial", 10));
        painter.drawText(2500,3300,"NUM DOSSEIR: ");
        painter.drawText(2500,3800,"ETAT DOSSIER: ");
        painter.drawText(2500,4300,"TYPE: ");
        painter.drawText(2500,4800,"DECISION: ");
        painter.drawText(2500,5300,"NOM ACCUSE: ");
        painter.drawText(2500,5800,"PRENOM ACCUSE: ");
        painter.drawText(2500,6300,"DATE NAISSANCE: ");
        painter.drawText(2500,6800,"EMPREINTE: ");
        painter.drawText(2500,7300,"ID AVOCAT: ");
        painter.drawText(2500,7800,"ARCHIVE: ");

        query.prepare("select * from AFFJURIDIQUE WHERE NUMDOSSIER=:id");
        query.bindValue(":id",res);
        query.exec();
        while (query.next())
        {
            painter.drawText(4500,3300,query.value(0).toString());
            painter.drawText(4500,3800,query.value(1).toString());
            painter.drawText(4500,4300,query.value(2).toString());
            painter.drawText(4500,4800,query.value(3).toString());
            painter.drawText(4500,5300,query.value(4).toString());
            painter.drawText(4500,5800,query.value(5).toString());
            painter.drawText(4500,6300,query.value(6).toString());
            painter.drawText(4500,6800,query.value(7).toString());
            painter.drawText(4500,7300,query.value(8).toString());
            painter.drawText(4500,7800,query.value(9).toString());

        }

        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/roua mtar/Desktop/rouafinal/affaire.pdf"));
            painter.end();
        }
        if (reponse == QMessageBox::No)
        {
            painter.end();
        }
}

