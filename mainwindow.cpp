#include "ui_mainwindow.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QMessageBox>
#include "perso.h"
#include "dc.h"
#include <QIntValidator>
#include <QPixmap>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTimer>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QPdfWriter>
#include <QTextStream>
#include <QtPrintSupport/QPrintDialog>
//////////////////////////////////////////////// roua
#include <QDesktopServices>
#include <QUrl>
#include"aff.juridique.h"
#include <QtCharts>
#include <QPainter>
////////////////////////////////////////////////////////

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //arduino
        int ret=a.connect_arduino();
        switch(ret){
        case(0):qDebug() <<"arduino is available and connected to:"<<a.getarduino_port_name();
            break;
        case(1):qDebug() <<"arduino is available but not connected to:"<<a.getarduino_port_name();
            break;
        case(-1):qDebug() <<"arduino is not available";
        }
        QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

    //combobox_tri

        QStringList list=(QStringList()<<" "<<"CIN");
        ui->comboBox_tri->addItems(list);


        ////////////////////////////////////////////  roua
        ui->le_id->setValidator(new QIntValidator(0, 9999999, this));
        ui->tab_affjuridique->setModel(A.afficher());
        ui->tableView_archive_dossier->setModel(A.afficher_archive()); // ajouté // affichage table view archive
        ui->stackedWidget->setCurrentIndex(0); // ajouté // stacked widget first window

       /////////////////////////////////////////////////////
       ///
       ///
       ///
        QSqlQuery q1,q2,q3,q4;
        qreal adm=0,aud=0,wc=0,buv=0;
        q1.prepare("select *from salle where type='administration'"); q1.exec();
        q2.prepare("select *from salle where type='audience'"); q2.exec();
        q3.prepare("select *from salle where type='wc'"); q3.exec();
        q4.prepare("select *from salle where type='buvette'"); q4.exec();
        while(q1.next()){adm++;}
        while(q2.next()){aud++;}
        while(q3.next()){wc++;}
        while(q4.next()){buv++;}
        QBarSet *set0 = new QBarSet("Administration");
               QBarSet *set1 = new QBarSet("Audience");
               QBarSet *set2 = new QBarSet("WC");
               QBarSet *set3 = new QBarSet("Buvette");
               *set0 << adm;
               *set1 << aud;
               *set2 << wc;
               *set3 << buv;
        QBarSeries *series = new QBarSeries();
               series->append(set0);
               series->append(set1);
               series->append(set2);
               series->append(set3);
        QChart *chart = new QChart();
               chart->addSeries(series);
               chart->createDefaultAxes();
               chart->axes(Qt::Horizontal).first()->hide();
        QBarCategoryAxis();
        QPalette pal = qApp->palette();
               pal.setColor(QPalette::Window, QRgb(0xffffff));
               pal.setColor(QPalette::WindowText, QRgb(0x404044));
               // Apply palette changes to the application
               qApp->setPalette(pal);
        QChartView *chartView ;
               chartView = new QChartView(chart,ui->horizontalFrame_stat_ahmed);
               chartView->setRenderHint(QPainter::Antialiasing);
               chartView->setMinimumSize(400,400);
               chartView->chart()->setAnimationOptions(QChart::AllAnimations);
               chartView->chart()->legend()->setAlignment(Qt::AlignRight);
               chartView->show();

               ui->table_salle_ahmed->setModel(Etmp.afficher());
}



MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pb_ajouter_clicked()
{
  QString nomprenom=ui->L_nomprenom->text();
  QString adr=ui->L_adr->text();
  QString poste=ui->L_poste->text();
  int num=ui->L_num->text().toInt();
  int CIN=ui->L_CIN->text().toInt();
  perso p (CIN,num,nomprenom,adr,poste);
  QMessageBox msgBox;
  bool test=p.ajouter();
  if (test)
  { msgBox.setText ("Ajout avec succes.");
  ui->tableView->setModel (p.afficher());
  }
  else
  msgBox.setText ("Echec d'ajout");
  msgBox.exec();

}

void MainWindow::on_pb_supprimer_clicked()
{
    int CIN=ui->L_CIN_supp->text().toInt();

            bool test=p1.supprimer(CIN);

            if (test){

               ui->tableView->setModel(p1.afficher());

               ui->label_supp->setStyleSheet("color: #00c800;");

               ui->label_supp->setText("done!");

               QTimer::singleShot(2000,this,[this] () { ui->label_supp->setText(""); });

                                    //QMessageBox::information(nullptr,QObject::tr("ok"),

                                    //QObject::tr("suppression effectué\n"

                                    /*"Click Cancel to exit."),QMessageBox::Cancel);*/}

            else{

                ui->label_supp->setText("personnel n'existe pas!");

                QTimer::singleShot(2000,this,[this] () { ui->label_supp->setText(""); });

                                    /*QMessageBox::critical(nullptr,QObject::tr("NOT OK"),

                                    QObject::tr("suppression non effectué.\n"

                                    "Click Cancel to exit."),QMessageBox::Cancel);*/}}








void MainWindow::on_pb_rechercher_clicked()
{
    perso p;

        p.set_CIN(ui->lineEdit_recherche->text().toInt());

        ui->tableView->setModel(p.recherche_CIN(p.get_CIN()));

        ui->label_test_recherche->setStyleSheet("color: #00c800;");

        ui->label_test_recherche->setText("done!");

        QTimer::singleShot(2000,this,[this] () { ui->label_test_recherche->setText(""); });}



void MainWindow::on_pb_affichier_clicked()
{
    ui->tableView->setModel(p.afficher());


    QSqlQuery q1,q2,q3,q4;
       qreal adm=0,juge=0,avocat=0,cons=0;

       q1.prepare("select *from perso where poste='administrateurs'");
       q1.exec();

       q2.prepare("select *from perso where poste='juges'");
       q2.exec();

       q3.prepare("select *from perso where poste='avocats'");
       q3.exec();

       q4.prepare("select *from perso where poste='conseillers'");
       q4.exec();

       while(q1.next()){adm++;}
       while(q2.next()){juge++;}
       while(q3.next()){avocat++;}
       while(q4.next()){cons++;}

       QBarSet *set0 = new QBarSet("administrateurs");
              QBarSet *set1 = new QBarSet("juges");
              QBarSet *set2 = new QBarSet("avocats");
              QBarSet *set3 = new QBarSet("conseillers");

              *set0 << adm;
              *set1 << juge;
              *set2 << avocat;
              *set3 << cons;
       QBarSeries *series = new QBarSeries();
       series->append(set0);
       series->append(set1);
       series->append(set2);
       series->append(set3);

       QChart *chart = new QChart();
       chart->addSeries(series);
              chart->createDefaultAxes();
                  chart->axes(Qt::Horizontal).first()->hide();
                  QBarCategoryAxis();
        QPalette pal = qApp->palette();
        pal.setColor(QPalette::Window, QRgb(0xffffff));
              pal.setColor(QPalette::WindowText, QRgb(0x404044));

              // Apply palette changes to the application
              qApp->setPalette(pal);

   QChartView *chartView = new QChartView(chart);
      // Used to display the chart
      chartView = new QChartView(chart,ui->horizontalFrame);
      chartView->setRenderHint(QPainter::Antialiasing);
      chartView->setMinimumSize(400,400);
      chartView->chart()->setAnimationOptions(QChart::AllAnimations);
      chartView->chart()->legend()->setAlignment(Qt::AlignRight);

      chartView->show();

      ////
      QStringList list=(QStringList()<<" "<<"Numsalle"<<"Etage"<<"Capacité"<<"Type");
      ui->comboBox_tri_ahmed->addItems(list);











    ui->label_ajout->setStyleSheet("color: #00c800;");

    ui->label_ajout->setText("done!");

    QTimer::singleShot(2000,this,[this] () { ui->label_ajout->setText(""); });}


void MainWindow::on_pb_tri_clicked()
{
    perso p;

        QSqlQuery query;

        QSqlQueryModel* model= new QSqlQueryModel();



        if (ui->comboBox_tri->currentText()=="CIN"){

                  query.prepare(QString("SELECT CIN FROM perso"));

                  query.exec();

                  model->setQuery(query);

                  model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));

                  ui->tableView->setModel(model);

                  ui->label_test_recherche->setStyleSheet("color: #00c800;");

                  ui->label_test_recherche->setText("done!");

                  QTimer::singleShot(2000,this,[this] () { ui->label_test_recherche->setText(""); });}
}



void MainWindow::on_pb_pdf_clicked()
{
    QString strStream;

                    QTextStream out(&strStream);



                    const int rowCount = ui->tableView->model()->rowCount();

                    const int columnCount = ui->tableView->model()->columnCount();



                    out <<  "<html>\n"

                        "<head>\n"

                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"

                        <<  QString("<title>%1</title>\n").arg("strTitle")

                        <<  "</head>\n"

                        "<body bgcolor=#ffffff link=#5000A0>\n"



                       //     "<align='right'> " << datefich << "</align>"

                        "<center> <H1>Liste des salles</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";



                    // headers

                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";

                    for (int column = 0; column < columnCount; column++)

                        if (!ui->tableView->isColumnHidden(column))

                            out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());

                    out << "</tr></thead>\n";



                    // data table

                    for (int row = 0; row < rowCount; row++) {

                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";

                        for (int column = 0; column < columnCount; column++) {

                            if (!ui->tableView->isColumnHidden(column)) {

                                QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();

                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));

                            }

                        }

                        out << "</tr>\n";

                    }

                    out <<  "</table> </center>\n"

                        "</body>\n"

                        "</html>\n";



              QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");

                if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }



               QPrinter printer (QPrinter::PrinterResolution);

                printer.setOutputFormat(QPrinter::PdfFormat);

               printer.setPaperSize(QPrinter::A4);

              printer.setOutputFileName(fileName);



               QTextDocument doc;

                doc.setHtml(strStream);

                doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number

                doc.print(&printer);

   }


void MainWindow::on_pb_imp_clicked()

    {

        QPrinter printer;



        printer.setPrinterName("desiered printer name");



      QPrintDialog dialog(&printer,this);



        if(dialog.exec()== QDialog::Rejected)



            return;

    }


void MainWindow::on_pb_modif_clicked()
{
    int CIN=ui->L_CIN->text().toInt();
    QString nomprenom=ui->L_nomprenom->text();
    int num=ui->L_num->text().toInt();
    QString adr=ui->L_adr->text();
    QString poste=ui->L_poste->text();

    bool test=p1.modifier(CIN,num,nomprenom,adr,poste);
            if(test)
            {
                 ui->tableView->setModel(p1.afficher());
                 ui->label_ajout->setStyleSheet("color: #00c800;");
                 ui->label_ajout->setText("done!");
                 QTimer::singleShot(2000,this,[this] () { ui->label_ajout->setText(""); });}

            else

            {
                ui->label_ajout->setStyleSheet("color: #ff0000;");
                ui->label_ajout->setText("Echec");
                QTimer::singleShot(2000,this,[this] () { ui->label_ajout->setText(""); });


            }

}


void MainWindow::on_pb_email_clicked()
{
    QString link="https://mail.google.com/mail/u/0/#inbox?compose=new";
       QDesktopServices::openUrl(link);
}

void MainWindow::on_pushButton_afficher_ela_clicked()
{
      ui->tableView_dc->setModel(d.afficher());
}


/////////////////////////////////// roua

void MainWindow::update_label()
{
data=a.read_from_arduino();
if (data == "1"){
    int row =ui->tab_affjuridique->selectionModel()->currentIndex().row();
             int code=ui->tab_affjuridique->model()->index(row,0).data().toInt();

             A.classer(code,"classé");
              ui->tab_affjuridique->setModel(A.afficher());
}

else if (data == "2"){

    int row =ui->tab_affjuridique->selectionModel()->currentIndex().row();
             int code=ui->tab_affjuridique->model()->index(row,0).data().toInt();

             A.classer(code,"non classé");
     ui->tab_affjuridique->setModel(A.afficher());
}





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

void MainWindow::on_pb_supprimer_roua_clicked()
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
        ui->stackedWidget->setCurrentIndex(2);

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



    QPdfWriter pdf("C:/Users/roua mtar/Desktop/rouafinal/affaire.pdf");   // a changer selon le pc
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
            QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/roua mtar/Desktop/rouafinal/affaire.pdf")); // a changer selon le pc
            painter.end();
        }
        if (reponse == QMessageBox::No)
        {
            painter.end();
        }
}


void MainWindow::on_pushButton_mailing_clicked()
{
    QString link="https://mail.google.com/mail/u/0/#inbox?compose=new";
    QDesktopServices::openUrl(link);

}


//////////////////////////////////////////////
///ahmed
//statistique


//pdp user:

/*QPixmap pdp("C:/Users/dell/Downloads/ahmed.jpg");
int w_pdp = ui->label_pdp->width();
int h_pdp = ui->label_pdp->height();
ui->label_pdp->setPixmap(pdp.scaled(w_pdp,h_pdp,Qt::KeepAspectRatio));

//logo smart court:
QPixmap logo("C:/Users/dell/Downloads/logo2.png");
int w_logo = ui->label_logo->width();
int h_logo = ui->label_logo->height();
ui->label_logo->setPixmap(logo.scaled(w_logo,h_logo,Qt::KeepAspectRatio));
*/
//combobox_tri






/*










void MainWindow::on_pushButton_deconnexion_clicked(){close();}









void MainWindow::on_pushButton_perso_clicked(){
ui->label_acc->setStyleSheet("color: #ff0000;");
ui->label_acc->setText("page inaccessible");
QTimer::singleShot(2000,this,[this] () { ui->label_acc->setText(""); });}




void MainWindow::on_pushButton_aud_clicked(){
ui->label_acc->setStyleSheet("color: #ff0000;");
ui->label_acc->setText("page inaccessible");
QTimer::singleShot(2000,this,[this] () { ui->label_acc->setText(""); });}



void MainWindow::on_pushButton_avocat_clicked(){
ui->label_acc->setStyleSheet("color: #ff0000;");
ui->label_acc->setText("page inaccessible");
QTimer::singleShot(2000,this,[this] () { ui->label_acc->setText(""); });}




void MainWindow::on_pushButton_parametres_clicked(){
ui->label_acc->setStyleSheet("color: #ff0000;");
ui->label_acc->setText("page inaccessible");
QTimer::singleShot(2000,this,[this] () { ui->label_acc->setText(""); });}


void MainWindow::update_label(){
data=A.read_from_arduino();
qDebug()<<data;
if (data=="1")
    ui->pushButton_salle_46->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 230, 0), stop:1 rgba(0, 230, 0));");
else  ui->pushButton_salle_46->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(229, 0, 0), stop:1 rgba(229, 0, 0));");
}
*/




void MainWindow::on_pb_ajouter_ahmed_clicked()
{
int Numsalle=ui->l_Numsalle_ahmed->text().toInt();
int etage=ui->l_etage_ahmed->text().toInt();
int capaciter=ui->l_capaciter_ahmed->text().toInt();
QString type=ui->l_type_ahmed->text();
QString etat=ui->l_etat_ahmed->text();
salle S(Numsalle,etage,capaciter,type,etat);
bool test=S.ajouter();
if (test){
    ui->table_salle_ahmed->setModel(Etmp.afficher());

  //ll affichage taa les salles:
    QString state=ui->l_etat_ahmed->text();
    int salle=ui->l_Numsalle_ahmed->text().toInt();
    //salle 1
    if(salle == 1){
        if(state == "pleine"){ui->salle1_pleine->show(); ui->salle1_vide->hide();}
        else {ui->salle1_vide->show(); ui->salle1_pleine->hide();}}
    //salle 2
    if(salle == 2){
        if(state == "pleine"){ui->salle2_pleine->show(); ui->salle2_vide->hide();}
        else {ui->salle2_vide->show(); ui->salle2_pleine->hide();}}
    //salle 3
    if(salle == 3){
        if(state == "pleine"){ui->salle3_pleine->show(); ui->salle3_vide->hide();}
        else {ui->salle3_vide->show(); ui->salle3_pleine->hide();}}
    //salle 4
    if(salle == 4){
        if(state == "pleine"){ui->salle2_pleine->show(); ui->salle4_vide->hide();}
        else {ui->salle4_vide->show(); ui->salle4_pleine->hide();}}
    //salle 5
    if(salle == 5){
        if(state == "pleine"){ui->salle5_pleine->show(); ui->salle5_vide->hide();}
        else {ui->salle5_vide->show(); ui->salle5_pleine->hide();}}


    // ui->label_salle1->setText(state);
    ui->label_testajout_ahmed->setStyleSheet("color: #00c800;");
    ui->label_testajout_ahmed->setText("done!");
    QTimer::singleShot(2000,this,[this] () { ui->label_testajout_ahmed->setText(""); });}
else{
      ui->label_testajout_ahmed->setStyleSheet("color: #ff0000;");
      ui->label_testajout_ahmed->setText("Salle existe déja!");
      QTimer::singleShot(2000,this,[this] () { ui->label_testajout_ahmed->setText(""); });}
}


void MainWindow::on_pb_modifier_ahmed_clicked()
{
int Numsalle=ui->l_Numsalle_ahmed->text().toInt();
int etage=ui->l_etage_ahmed->text().toInt();
int capaciter=ui->l_capaciter_ahmed->text().toInt();
QString type=ui->l_type_ahmed->text();
QString etat=ui->l_etat_ahmed->text();
bool test=Etmp.modifier_salle(Numsalle,etage,capaciter,type, etat);
        if(test){
             ui->table_salle_ahmed->setModel(Etmp.afficher());
             //ll affichage taa les salles:
             QString state=ui->l_etat_ahmed->text();
             int salle=ui->l_Numsalle_ahmed->text().toInt();
             //salle 1
             if(salle == 1){
                if(state == "pleine"){ui->salle1_pleine->show(); ui->salle1_vide->hide();}
                else {ui->salle1_vide->show(); ui->salle1_pleine->hide();}}
             //salle 2
             if(salle == 2){
                if(state == "pleine"){ui->salle2_pleine->show(); ui->salle2_vide->hide();}
                else {ui->salle2_vide->show(); ui->salle2_pleine->hide();}}
             //salle 3
             if(salle == 3){
                if(state == "pleine"){ui->salle3_pleine->show(); ui->salle3_vide->hide();}
                else {ui->salle3_vide->show(); ui->salle3_pleine->hide();}}
             //salle 4
             if(salle == 4){
                if(state == "pleine"){ui->salle2_pleine->show(); ui->salle4_vide->hide();}
                else {ui->salle4_vide->show(); ui->salle4_pleine->hide();}}
             //salle 5
             if(salle == 5){
                if(state == "pleine"){ui->salle5_pleine->show(); ui->salle5_vide->hide();}
                else {ui->salle5_vide->show(); ui->salle5_pleine->hide();}}
             ui->label_testajout_ahmed->setStyleSheet("color: #00c800;");
             ui->label_testajout_ahmed->setText("done!");
             QTimer::singleShot(2000,this,[this] () { ui->label_testajout_ahmed->setText(""); });}
        else{
            ui->label_testajout_ahmed->setStyleSheet("color: #ff0000;");
            ui->label_testajout_ahmed->setText("Echec");
            QTimer::singleShot(2000,this,[this] () { ui->label_testajout_ahmed->setText(""); });}
}


void MainWindow::on_pb_supprimer_ahmed_clicked()
{
int Numsalle=ui->l_Numsalle_ahmed->text().toInt();
bool test=Etmp.supprimer(Numsalle);
if (test){
   ui->table_salle_ahmed->setModel(Etmp.afficher());
     //ll affichage taa les salles:
     QString state=ui->l_etat_ahmed->text();
     int salle=ui->l_Numsalle_ahmed->text().toInt();
     //salle 1
     if(salle == 1){ui->salle1_vide->hide(); ui->salle1_pleine->hide();}
     //salle 2
     if(salle == 2){ui->salle2_vide->hide(); ui->salle2_pleine->hide();}
     //salle 3
     if(salle == 3){ui->salle3_vide->hide(); ui->salle3_pleine->hide();}
     //salle 4
     if(salle == 4){ui->salle4_vide->hide(); ui->salle4_pleine->hide();}
     //salle 5
     if(salle == 5){ui->salle5_vide->hide(); ui->salle5_pleine->hide();}
 ui->label_testajout_ahmed->setStyleSheet("color: #00c800;");
 ui->label_testajout_ahmed->setText("done!");
 QTimer::singleShot(2000,this,[this] () { ui->label_testajout_ahmed->setText(""); });}
else{
    ui->label_testajout_ahmed->setText("Salle n'existe pas!");
    QTimer::singleShot(2000,this,[this] () { ui->label_testajout_ahmed->setText(""); });}
}


void MainWindow::on_pb_afficher_ahmed_clicked()
{
ui->table_salle_ahmed->setModel(Etmp.afficher());
ui->label_testajout_ahmed->setStyleSheet("color: #00c800;");
ui->label_testajout_ahmed->setText("done!");
QTimer::singleShot(2000,this,[this] () { ui->label_testajout_ahmed->setText(""); });
}


void MainWindow::on_pb_pdf_ahmed_clicked()
{
QString strStream;
QTextStream out(&strStream);
    const int rowCount = ui->table_salle_ahmed->model()->rowCount();
    const int columnCount = ui->table_salle_ahmed->model()->columnCount();
             out <<  "<html>\n"
                     "<head>\n"
                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                 <<  QString("<title>%1</title>\n").arg("strTitle")
                 <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"
                     //"<align='right'> " << datefich << "</align>"
                     "<center> <H1>Liste des salles</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";
                     // headers
             out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
             for (int column = 0; column < columnCount; column++)
             if (!ui->table_salle_ahmed->isColumnHidden(column))
             out << QString("<th>%1</th>").arg(ui->table_salle_ahmed->model()->headerData(column, Qt::Horizontal).toString());
             out << "</tr></thead>\n";
                    // data table
             for (int row = 0; row < rowCount; row++) {
             out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
             for (int column = 0; column < columnCount; column++) {
             if (!ui->table_salle_ahmed->isColumnHidden(column)) {
QString data = ui->table_salle_ahmed->model()->data(ui->table_salle_ahmed->model()->index(row, column)).toString().simplified();
             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));}}
             out << "</tr>\n";}
             out << "</table> </center>\n"
                    "</body>\n"
                    "</html>\n";
QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
            if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
QPrinter printer (QPrinter::PrinterResolution);
         printer.setOutputFormat(QPrinter::PdfFormat);
         printer.setPaperSize(QPrinter::A4);
         printer.setOutputFileName(fileName);
QTextDocument doc;
         doc.setHtml(strStream);
         doc.setPageSize(printer.pageRect().size());
         doc.print(&printer);
}


void MainWindow::on_pb_imprimer_ahmed_clicked()
{
QPrinter printer;
printer.setPrinterName("desiered printer name");
QPrintDialog dialog(&printer,this);
if(dialog.exec()== QDialog::Rejected)
    return;
}


void MainWindow::on_pushButton_salle_46_pressed()
{
ui->pushButton_salle_46->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 230, 0), stop:1 rgba(0, 230, 0));");
}


void MainWindow::on_pushButton_salle_46_released()
{
ui->pushButton_salle_46->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(229, 0, 0), stop:1 rgba(229, 0, 0));");
}


void MainWindow::on_pushButton_tri_ahmed_clicked()
{
salle s;
QSqlQuery query;
QSqlQueryModel* model= new QSqlQueryModel();
if (ui->comboBox_tri_ahmed->currentText()=="Numsalle"){
          query.prepare(QString("SELECT Numsalle FROM salle"));
          query.exec();
          model->setQuery(query);
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numsalle"));
          ui->table_salle_ahmed->setModel(model);
          ui->label_testrecherche_ahmed->setStyleSheet("color: #00c800;");
          ui->label_testrecherche_ahmed->setText("done!");
          QTimer::singleShot(2000,this,[this] () { ui->label_testrecherche_ahmed->setText(""); });}
else if (ui->comboBox_tri_ahmed->currentText()=="Etage"){
          query.prepare(QString("SELECT etage FROM salle"));
          query.exec();
          model->setQuery(query);
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("etage"));
          ui->table_salle_ahmed->setModel(model);
          ui->label_testrecherche_ahmed->setStyleSheet("color: #00c800;");
          ui->label_testrecherche_ahmed->setText("done!");
          QTimer::singleShot(2000,this,[this] () { ui->label_testrecherche_ahmed->setText(""); });}
else if (ui->comboBox_tri_ahmed->currentText()=="Capacité"){
          query.prepare(QString("SELECT capaciter FROM salle"));
          query.exec();
          model->setQuery(query);
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("capaciter"));
          ui->table_salle_ahmed->setModel(model);
          ui->label_testrecherche_ahmed->setStyleSheet("color: #00c800;");
          ui->label_testrecherche_ahmed->setText("done!");
          QTimer::singleShot(2000,this,[this] () { ui->label_testrecherche_ahmed->setText(""); });}
else if (ui->comboBox_tri_ahmed->currentText()=="Type"){
          query.prepare(QString("SELECT type FROM salle"));
          query.exec();
          model->setQuery(query);
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("type"));
          ui->table_salle_ahmed->setModel(model);
          ui->label_testrecherche_ahmed->setStyleSheet("color: #00c800;");
          ui->label_testrecherche_ahmed->setText("done!");
          QTimer::singleShot(2000,this,[this] () { ui->label_testrecherche_ahmed->setText(""); });}
else {ui->table_salle_ahmed->setModel(Etmp.afficher());
    ui->label_testrecherche_ahmed->setStyleSheet("color: #00c800;");
    ui->label_testrecherche_ahmed->setText("done!");
    QTimer::singleShot(2000,this,[this] () { ui->label_testrecherche_ahmed->setText(""); });}
}


void MainWindow::on_pushButton_recherche_ahmed_clicked()
{
salle s;
s.setNumSalle(ui->lineEdit_recherche_ahmed->text().toInt());
ui->table_salle_ahmed->setModel(s.recherche_Numsalle(s.getNumSalle()));
ui->label_testrecherche_ahmed->setStyleSheet("color: #00c800;");
ui->label_testrecherche_ahmed->setText("done!");
QTimer::singleShot(2000,this,[this] () { ui->label_testrecherche_ahmed->setText(""); });
}

void MainWindow::update_label_ahmed(){
data=a.read_from_arduino();
qDebug()<<data;
if (data=="1")
    ui->pushButton_salle_46->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 230, 0), stop:1 rgba(0, 230, 0));");
else  ui->pushButton_salle_46->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(229, 0, 0), stop:1 rgba(229, 0, 0));");
}





void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

