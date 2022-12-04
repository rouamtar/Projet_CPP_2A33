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
#include<qrcode.hpp>

#include <QtPrintSupport/QPrintDialog>
//////////////////////////////////////////////// roua
#include <QDesktopServices>
#include <QUrl>
#include"aff.juridique.h"
#include <QtCharts>
#include <QPainter>
//////////////////////////////////////////////////////// yassmine
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "audience.h"
#include<QMessageBox>
#include<QIntValidator>
#include<QDateTime>
#include<QDate>
#include<QTextEdit>
#include<QTextDocument>
#include<QPdfWriter>
#include<QtPrintSupport/QPrintDialog>
#include"historique.h"
#include<QFileDialog>
#include<QtPrintSupport/QPrinter>
#include<QTextStream>
#include<QTimer>
#include <QObject>
#include <QPixmap>
//////////////////////////////////////////////////////



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_2->setModel(ptmp.afficher());
        ui->stackedWidget_2->setCurrentIndex(1);

        ui->cb_tri->addItem("ID");
        ui->cb_tri->addItem("NOM");
        ui->cb_tri->addItem("PRENOM");
        ui->cb_tri->addItem("CLASSE");

        ui->cb_up_classe->addItem("CLASSE 1");
        ui->cb_up_classe->addItem("CLASSE 2");
        ui->cb_up_classe->addItem("CLASSE 3");
        ui->cb_up_classe->addItem("CLASSE 4");

        ui->cb_add_classe->addItem("CLASSE 1");
        ui->cb_add_classe->addItem("CLASSE 2");
        ui->cb_add_classe->addItem("CLASSE 3");
        ui->cb_add_classe->addItem("CLASSE 4");

        QPieSeries *series = new QPieSeries();

            series->append("CLASSE1",8);
            series->append("CLASSE2",10);
            series->append("CLASSE3",5);
            series->append("CLASSE4",4);

            QPieSlice *slice = series->slices().at(0);
            slice->setExploded(true);
            slice->setLabelVisible(true);

    ui->label_3->setPixmap(QPixmap("C:/Users/Firas/Desktop/integration roua/integ/3 parts integ/smartcourt_ela/test.png"));
    login = 0 ;
    ui->stackedWidget->setCurrentIndex(5);
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

       ///////////////////////////////////////////////////// ahmed

//       QSqlQuery q1,q2,q3,q4;
//        qreal adm=0,aud=0,wc=0,buv=0;
//        q1.prepare("select *from salle where type='administration'"); q1.exec();
//        q2.prepare("select *from salle where type='audience'"); q2.exec();
//        q3.prepare("select *from salle where type='wc'"); q3.exec();
//        q4.prepare("select *from salle where type='buvette'"); q4.exec();
//        while(q1.next()){adm++;}
//        while(q2.next()){aud++;}
//        while(q3.next()){wc++;}
//        while(q4.next()){buv++;}
//        QBarSet *set0 = new QBarSet("Administration");
//               QBarSet *set1 = new QBarSet("Audience");
//               QBarSet *set2 = new QBarSet("WC");
//               QBarSet *set3 = new QBarSet("Buvette");
//               *set0 << adm;
//               *set1 << aud;
//               *set2 << wc;
//               *set3 << buv;
////        QBarSeries *series = new QBarSeries();
////               series->append(set0);
////               series->append(set1);
////               series->append(set2);
////               series->append(set3);
//        QChart *chart = new QChart();
//               chart->addSeries(series);
//               chart->createDefaultAxes();
//               chart->axes(Qt::Horizontal).first()->hide();
//        QBarCategoryAxis();
//        QPalette pal = qApp->palette();
//               pal.setColor(QPalette::Window, QRgb(0xffffff));
//               pal.setColor(QPalette::WindowText, QRgb(0x404044));
//               // Apply palette changes to the application
//               qApp->setPalette(pal);
//        QChartView *chartView ;
//               chartView = new QChartView(chart,ui->horizontalFrame_stat_ahmed);
//               chartView->setRenderHint(QPainter::Antialiasing);
//               chartView->setMinimumSize(400,400);
//               chartView->chart()->setAnimationOptions(QChart::AllAnimations);
//               chartView->chart()->legend()->setAlignment(Qt::AlignRight);
//               chartView->show();

//               ui->table_salle_ahmed->setModel(Etmp.afficher());


//    ////////////////////////////////////////////////////////////////////////////////////

//               //ui->le_num_aud->setValidator( new QIntValidator(0,9999999, this));
//             /*  ui->le_duree->setValidator( new QIntValidator(0,9999999, this));
//               ui->le_salle->setValidator(new QIntValidator(0,9999999, this));
//               ui->tab_des_audiences->setModel(A1.afficher());
//               ui->tv_tri->setModel(A1.afficher());
//               ui-> tv_histo->setModel(H.Afficher());*/

//               //logo smart court:
//                  /* QPixmap logo("C:/Users/21652/Downloads/logo2.png");
//                   int w_logo = ui->label_logo->width();
//                   int h_logo = ui->label_logo->height();
//                   ui->label_logo->setPixmap(logo.scaled(w_logo,h_logo,Qt::KeepAspectRatio));*/

//                   //statistique

//                   QSqlQuery q1y,q2y,q3y,q4y;
//                      qreal s1=0,s2=0,s3=0,s4=0;

//                      q1y.prepare("select *from AUDIENCES where salle=1");
//                      q1y.exec();

//                      q2y.prepare("select *from AUDIENCES where salle=2");
//                      q2y.exec();

//                      q3y.prepare("select *from AUDIENCES where salle=3");
//                      q3y.exec();

//                      q4y.prepare("select *from AUDIENCES where salle=4");
//                      q4y.exec();

//                      while(q1y.next()){s1++;}
//                      while(q2y.next()){s2++;}
//                      while(q3y.next()){s3++;}
//                      while(q4y.next()){s4++;}

//                             QBarSet *set0y = new QBarSet("salle1");
//                             QBarSet *set1y = new QBarSet("salle2");
//                             QBarSet *set2y = new QBarSet("salle3");
//                             QBarSet *set3y = new QBarSet("salle4");

//                             *set0y << s1;
//                             *set1y << s2;
//                             *set2y << s3;
//                             *set3y << s4;
//                      QBarSeries *seriesy = new QBarSeries();
//                      seriesy->append(set0y);
//                      seriesy->append(set1y);
//                      seriesy->append(set2y);
//                      seriesy->append(set3y);

//                      QChart *charty = new QChart();
//                      charty->addSeries(seriesy);
//                             charty->createDefaultAxes();
//                                 charty->axes(Qt::Horizontal).first()->hide();
//                                 QBarCategoryAxis();
//                       QPalette paly = qApp->palette();
//                       paly.setColor(QPalette::Window, QRgb(0xffffff));
//                             paly.setColor(QPalette::WindowText, QRgb(0x404044));

//                             // Apply palette changes to the application
//                             qApp->setPalette(paly);

//                  QChartView *chartViewy = new QChartView(charty);
//                     // Used to display the chart
//                     chartViewy = new QChartView(charty,ui->horizontalFrame_stat);
//                     chartViewy->setRenderHint(QPainter::Antialiasing);
//                     chartViewy->setMinimumSize(400,400);
//                     chartViewy->chart()->setAnimationOptions(QChart::AllAnimations);
//                     chartViewy->chart()->legend()->setAlignment(Qt::AlignRight);

//                     chartViewy->show();

//                       /*QBarSet *set0 = new QBarSet("num des Audience  par mois");


//                       *set0 <<80<<74<<68<<100<<59<<90<<77<<100<<70;


//                       QBarSeries *series = new QBarSeries();
//                       series->append(set0);


//                       QChart *chart = new QChart();
//                       chart->addSeries(series);
//                       chart->setTitle("statistiques");
//                       chart->setAnimationOptions(QChart::SeriesAnimations);

//                       QStringList categories;
//                       categories <<"janvier"<<"fevrier"<<"mars"<<"avril"<<"mai"<<"juin"<<"juillet"<<"aout"<<"septempre";
//                       QBarCategoryAxis *axis = new QBarCategoryAxis();
//                       axis->append(categories);
//                       chart->createDefaultAxes();
//                       chart->setAxisX(axis, series);

//                       QChartView *chartview = new QChartView(chart);
//                       chartview->setParent(ui->horizontalFrame_stat);}*/
////////////////////////////////////////////////////////////////////////////////////////////////////////
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
    if(username == "personnel" && password == "admin"){
        msgBox.setText("Connecté avec succes.");
        msgBox.exec();
        ui->stackedWidget->setCurrentIndex(1);
        login = 1 ;

    }
    else if(username == "affaire" && password == "admin"){
        msgBox.setText("Connecté avec succes.");
        msgBox.exec();
        ui->stackedWidget->setCurrentIndex(2);
        login = 2 ;

    }
    else if(username == "salle" && password == "admin"){
        msgBox.setText("Connecté avec succes.");
        msgBox.exec();
        ui->stackedWidget->setCurrentIndex(3);
        login = 3 ;

    }
    else if(username == "audience" && password == "admin"){
        msgBox.setText("Connecté avec succes.");
        msgBox.exec();
        ui->stackedWidget->setCurrentIndex(4);
        login = 4;

    }
    else if(username == "avocat" && password == "admin"){
        msgBox.setText("Connecté avec succes.");
        msgBox.exec();
        ui->stackedWidget->setCurrentIndex(5);
        login = 5;

    }
    else {
        {
            msgBox.setText("Mot de passe ou username erroné");
            msgBox.exec();
        }
    }
    ui->lineEdit_password->clear();
    ui->lineEdit_username->clear();
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


//////////////////////////////////////////////////////////////////////// yassmine


void MainWindow::update()
{
    data=a.read_from_arduino();
    if(data=="1")
    {
        bool tester=A1.valider(data);

        if(tester)
        {
            a.write_to_arduino("1");
        }else
        {
             a.write_to_arduino("0");
        }
    }
}

void MainWindow::on_pb_modifier_clicked()
{

       int id=ui->le_rech->text().toInt();
       int salle=ui->salle_m->text().toInt();
       int duree=ui->duree_m->text().toInt();
       QDate date= ui->date_m->date();
      bool test= A1.modifier(id,salle,duree,date);
       QMessageBox msg;
      if(test)
      { ui->tab_des_audiences->setModel(A1.afficher());

          ui->tv_tri->setModel(A1.afficher());
                      msg.setText("modifie avec succés");
                       QString operation="Modifier";
                      historique H(operation,id);
                      H.Ajouter();
                       ui->tv_histo->setModel(H.Afficher());
                      }
                      else
                      {
                      msg.setText("Echec au niveau de la modif ");
                      }
                      msg.exec();

                  ui->le_rech->clear();
                  ui->salle_m->clear();
                  ui->date_m->clear();
                  ui->duree_m->clear();
}



void MainWindow::on_le_tri_na_textChanged(const QString &arg1)
{
       ui->tv_tri->setModel( A1.rechercher(arg1));
}

void MainWindow::on_pb_PDF_clicked()
{
    QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = ui->tab_des_audiences->model()->rowCount();
                     const int columnCount = ui->tab_des_audiences->model()->columnCount();

                     out <<  "<html>\n"
                         "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg("strTitle")
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"

                        //     "<align='right'> " << datefich << "</align>"
                         "<center> <H1>Liste des audiences </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                     // headers
                     out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tab_des_audiences->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tab_des_audiences->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tab_des_audiences->isColumnHidden(column)) {
                                 QString data = ui->tab_des_audiences->model()->data(ui->tab_des_audiences->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pb_imprimer_clicked()
{
    QPrinter printer;

        printer.setPrinterName("desiered printer name");

      QPrintDialog dialog(&printer,this);

        if(dialog.exec()== QDialog::Rejected)

            return;

}

void MainWindow::on_pb_ajouter_yassmine_clicked()
{
    QMessageBox msgBox;

    int salle=ui->le_salle->text().toInt();
    int duree=ui->le_duree->text().toInt();
    QDate datime=ui->dateTimeEdit->date();
   Audience A(salle,duree,datime) ;
   bool test=A.ajouter();

   if (test)
    { msgBox.setText( "ajout  avec succes.");

       QString operation="Ajout";

        ui-> tv_histo->setModel(H.Afficher());

           ui->tab_des_audiences->setModel(A1.afficher());
           ui->tv_tri->setModel(A1.afficher());
           ui->le_salle->clear();
           ui->dateTimeEdit->clear();
           ui->le_duree->clear();
      }
    else

     msgBox.setText("echec d'ajout");
     msgBox.exec();
}

void MainWindow::on_pb_supprimer_yassmine_clicked()
{
    Audience A1;
      historique H;
    int id=ui->le_num_aud_supp->text().toInt();
    bool test=A1.supprimer(id);
    QMessageBox msgBox;
    if (test)
    {msgBox.setText( "supprimer avec succes.");
    ui->tab_des_audiences->setModel(A1.afficher());
    QString operation="Suppression";
    historique H(operation,id);
    H.Ajouter();
     ui->tv_histo->setModel(H.Afficher());


    }
    else
    msgBox.setText("echec de supprimer");
    msgBox.exec();
}


void MainWindow::on_pb_rechercher_yassmine_clicked()
{
    QSqlQuery query;
    query.prepare("select salle, duree ,date_a from Audiences where num_aud=?;");
    query.addBindValue(ui->le_rech->text());
    if(query.exec())
       {
        while(query.next())
         {
                     ui->salle_m->setText(query.value(0).toString());
                     ui->duree_m->setText(query.value(1).toString());
                     ui->date_m->setDate(query.value(2).toDate());

            }
        }
}

void MainWindow::on_pb_email_yassmine_clicked()
{
    QString link="https://mail.google.com/mail/u/0/#i"
                 "5ox?compose=new";
        QDesktopServices::openUrl(link);
}

void MainWindow::on_pushButton_rechercher_yassmine_clicked()
{
    Audience A1;
            A1.setsalle(ui->lineEdit_rechercher->text().toInt());
            ui->tab_des_audiences->setModel(A1.rechercher_salle(A1.getsalle()));
            ui->label_re->setStyleSheet("color: #00c800;");
            ui->label_re->setText("done!");
            QTimer::singleShot(2000,this,[this] () { ui->label_re->setText(""); });
}
//////////////////////////////////////////////////////////////////////////////////////////////

void MainWindow::on_pushButton_2_clicked()
{
    if (login == 1)
    ui->stackedWidget->setCurrentIndex(1);
    else {
        ui->label_acc->setStyleSheet("color: #ff0000;");
        ui->label_acc->setText("page inaccessible");
        QTimer::singleShot(2000,this,[this] () { ui->label_acc->setText(""); });
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if (login == 4)
    ui->stackedWidget->setCurrentIndex(4);
    else {
        ui->label_acc->setStyleSheet("color: #ff0000;");
        ui->label_acc->setText("page inaccessible");
        QTimer::singleShot(2000,this,[this] () { ui->label_acc->setText(""); });
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    if (login == 2)
    ui->stackedWidget->setCurrentIndex(2);
    else {
        ui->label_acc->setStyleSheet("color: #ff0000;");
        ui->label_acc->setText("page inaccessible");
        QTimer::singleShot(2000,this,[this] () { ui->label_acc->setText(""); });
    }
}
void MainWindow::on_pushButton_6_clicked()
{
    if (login == 3)
    ui->stackedWidget->setCurrentIndex(3);
    else {
        ui->label_acc->setStyleSheet("color: #ff0000;");
        ui->label_acc->setText("page inaccessible");
        QTimer::singleShot(2000,this,[this] () { ui->label_acc->setText(""); });
    }
}

void MainWindow::on_pushButton_8_clicked()
{
    if (login != 0)
    {
        ui->label_acc->setStyleSheet("color: #ff0000;");
        ui->label_acc->setText("vous êtes deja connecté ! ");
        QTimer::singleShot(2000,this,[this] () { ui->label_acc->setText(""); });
    }
}

void MainWindow::on_pushButton_deconnexion_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
     login = 0 ;
}

void MainWindow::on_QR_clicked()
{
    // NOTE: At this point you will use the API to get the encoding and format you want, instead of my hardcoded stuff:

          int tabprod=ui->tableView_2->currentIndex().row();
          QVariant numcc=ui->tableView_2->model()->data(ui->tableView_2->model()->index(tabprod,0));
          QString id= numcc.toString();
          QSqlQuery qry;
          qry.prepare("select * from AVOCAT where id=:id");
          qry.bindValue(":id",id);
          qry.exec();
         // QDate date_signification;
          QString nom,prenom,classe;
          while(qry.next()){
              nom=qry.value(1).toString();
              prenom=qry.value(2).toString();
              classe=qry.value(3).toString();
             // cin==qry.value(4).toString();
          }
         // numcs=QString::number(numc);
          id="id: "+nom+" nom: "+prenom+" prenom: "+classe+"classe: ";
          qrcodegen::QrCode  qr = qrcodegen::QrCode::encodeText(id.toUtf8().constData(), qrcodegen::QrCode::Ecc::HIGH);


          QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
          // NOTE: For performance reasons my implementation only draws the foreground parts in supplied color.
          // It expects background to be prepared already (in white or whatever is preferred).
          for (int y = 0; y < qr.getSize(); y++) {
              for (int x = 0; x < qr.getSize(); x++) {
                  int color = qr.getModule(x, y);  // 0 for white, 1 for black

                  // You need to modify this part
                  if(color==0)
                      im.setPixel(x, y,qRgb(254, 254, 254));
                  else
                      im.setPixel(x, y,qRgb(0, 0, 0));
              }
          }
          im=im.scaled(200,200);
          ui->qrcodecommande_2->setPixmap(QPixmap::fromImage(im));

}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_pushButton_10_clicked()
{
    QString strStream;
                QTextStream out(&strStream);

                const int rowCount = ui->tableView_2->model()->rowCount();
                const int columnCount = ui->tableView_2->model()->columnCount();

                out <<  "<html>\n"
                    "<head>\n"
                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                    <<  QString("<title>%1</title>\n").arg("strTitle")
                    <<  "</head>\n"
                    "<body bgcolor=#ffffff link=#5000A0>\n"

                    //     "<align='right'> " << datefich << "</align>"
                    "<center> <H1>Liste Des Reclamation </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                // headers
                out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                for (int column = 0; column < columnCount; column++)
                    if (!ui->tableView_2->isColumnHidden(column))
                        out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
                out << "</tr></thead>\n";

                // data table
                for (int row = 0; row < rowCount; row++)
                {
                    out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
                    for (int column = 0; column < columnCount; column++)
                    {
                        if (!ui->tableView_2->isColumnHidden(column))
                        {
                            QString data = ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                        }
                    }
                    out << "</tr>\n";
                }
                out <<  "</table> </center>\n"
                    "</body>\n"
                    "</html>\n";

                QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");
                if (QFileInfo(fileName).suffix().isEmpty())
                {
                    fileName.append(".pdf");
                }

                QPrinter p (QPrinter::PrinterResolution);
                p.setOutputFormat(QPrinter::PdfFormat);
                p.setPaperSize(QPrinter::A4);
                p.setOutputFileName(fileName);

                QTextDocument doc;
                doc.setHtml(strStream);
                doc.setPageSize(p.pageRect().size()); // This is necessary if you want to hide the page number
                doc.print(&p);
}

void MainWindow::on_tableView_2_doubleClicked(const QModelIndex &index)
{
    int id = ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(), 0)).toInt();
        QString prenom = ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(), 1)).toString();
        QString nom = ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(), 2)).toString();
        QString classe = ui->tableView_2->model()->data(ui->tableView_2->model()->index(index.row(), 3)).toString();

        ptmp.setID(id);
        ptmp.setnom(nom);
        ptmp.setprenom(prenom);
        ptmp.setclasse(classe);

        ui->lineEdit_8->setText(nom);
        ui->lineEdit_7->setText(prenom);
        ui->cb_up_classe->setCurrentText(classe);

        ui->stackedWidget_2->setCurrentIndex(3);
}

void MainWindow::on_lineEdit_9_textChanged(const QString &arg1)
{
    ui->tableView_2->setModel(ptmp.rechercher(arg1));

}

void MainWindow::on_cb_tri_currentTextChanged(const QString &arg1)
{
    ui->tableView_2->setModel(ptmp.trier(arg1));

}

void MainWindow::on_pushButton_16_clicked()
{
    QString nom=ui->lineEdit_8->text();
         QString prenom=ui->lineEdit_7->text();
          QString classe=ui->cb_up_classe->currentText();

          ptmp.setnom(nom);
          ptmp.setprenom(prenom);
          ptmp.setclasse(classe);
         bool test=ptmp.modifier(ptmp.getID());
         if (test)
         {
             ui->tableView_2->setModel(ptmp.afficher());
             QMessageBox::information(nullptr,QObject::tr("ok"),
                                      QObject::tr("modif effectué\n"
                                                  "Click Cancel to exit."),QMessageBox::Cancel);
             ptmp.notification_modifavocat();

             ui->stackedWidget_2->setCurrentIndex(1);

         }
         else QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                               QObject::tr("modif non effectué.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_14_clicked()
{
    bool test=ptmp.supprimer(ptmp.getID());
        if (test)
        {
            ui->tableView_2->setModel(ptmp.afficher());
            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression effectué\n"
                                                 "Click Cancel to exit."),QMessageBox::Cancel);
            ui->stackedWidget_2->setCurrentIndex(1);


        }else QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                              QObject::tr("suppression non effectué.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);

}

void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);

}

void MainWindow::on_pushButton_clicked()
{
    int id=ui->lineEdit->text().toInt();
        QString nom=ui->lineEdit_2->text();
         QString prenom=ui->lineEdit_3->text();
          QString classe=ui->cb_add_classe->currentText();
         AVOCAT A(id,nom,prenom,classe);
         bool test=A.ajouter();
         if (test)
         {
             ui->tableView_2->setModel(ptmp.afficher());
             QMessageBox::information(nullptr,QObject::tr("ok"),
                                      QObject::tr("ajout effectué\n"
                                                  "Click Cancel to exit."),QMessageBox::Cancel);
             ptmp.notification_ajoutavocat();
             ui->stackedWidget_2->setCurrentIndex(1);

         }
         else QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                               QObject::tr("Ajout non effectué.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_11_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("SELECT classe FROM AVOCAT WHERE  classe='CLASSE 1' ");
            float countC=model->rowCount();
            model->setQuery("SELECT classe FROM AVOCAT WHERE  classe='CLASSE 2' ");
            float countEC=model->rowCount();
            model->setQuery("SELECT classe FROM AVOCAT WHERE  classe='CLASSE 3' ");
            float countEG=model->rowCount();
            model->setQuery("SELECT classe FROM AVOCAT WHERE  classe='CLASSE 4' ");
            float countET=model->rowCount();


            float total=countC+countEC+countEG+countET;

                    QPieSeries *series = new QPieSeries();
                    series->append("CLASSE 1",countC);
                    series->append("CLASSE 2",countEC);
                    series->append("CLASSE 3",countEG);
                    series->append("CLASSE 4",countET);



                    if (countC!=0)
                    {QPieSlice *slice = series->slices().at(0);
                        slice->setLabel("CLASSE 1 "+QString("%1%").arg(100*slice->percentage(),3,'f',1));
                        slice->setPen(QPen(Qt::blue));
                        slice->setBrush(QColor(Qt::yellow));}

                    if ( countEC!=0)
                    {
                        QPieSlice *slice1 = series->slices().at(1);
                        slice1->setLabel("CLASSE 2 "+QString("%1%").arg(100*slice1->percentage(),3,'f',1));
                        slice1->setPen(QPen(Qt::blue));
                        slice1->setBrush(QColor(Qt::cyan));
                    }
                    if (countEG!=0)
                    {QPieSlice *slice = series->slices().at(2);
                        slice->setLabel("CLASSE 3 "+QString("%1%").arg(100*slice->percentage(),3,'f',1));
                        slice->setPen(QPen(Qt::blue));
                        slice->setBrush(QColor(Qt::green));}
                    if (countET!=0)
                    {QPieSlice *slice = series->slices().at(3);
                        slice->setLabel("CLASSE 4 "+QString("%1%").arg(100*slice->percentage(),3,'f',1));
                        slice->setPen(QPen(Qt::blue));
                        slice->setBrush(QColor(Qt::red));}


                    QChart *chart = new QChart();
                    chart->addSeries(series);
                    chart->setTitle(" Avocats: "+ QString::number(total));

                    QChartView *chartView = new QChartView(chart);
                    chartView->setRenderHint(QPainter::Antialiasing);
                    chartView->resize(1000,500);

                    chartView->show();

    }


void MainWindow::on_pushButton_12_clicked()
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
                "<center> <H1>Liste Des Reclamation </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

            // headers
            out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
            for (int column = 0; column < columnCount; column++)
                if (!ui->tableView->isColumnHidden(column))
                    out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
            out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++)
            {
                out << "<tr> <td bkcolor=0>" << row + 1 << "</td>";
                for (int column = 0; column < columnCount; column++)
                {
                    if (!ui->tableView->isColumnHidden(column))
                    {
                        QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                        out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }
            out <<  "</table> </center>\n"
                "</body>\n"
                "</html>\n";

            QString fileName = QFileDialog::getSaveFileName((QWidget * )0, "Sauvegarder en PDF", QString(), "*.pdf");
            if (QFileInfo(fileName).suffix().isEmpty())
            {
                fileName.append(".pdf");
            }

            QPrinter p (QPrinter::PrinterResolution);
            p.setOutputFormat(QPrinter::PdfFormat);
            p.setPaperSize(QPrinter::A4);
            p.setOutputFileName(fileName);

            QTextDocument doc;
            doc.setHtml(strStream);
            doc.setPageSize(p.pageRect().size()); // This is necessary if you want to hide the page number
            doc.print(&p);

}
