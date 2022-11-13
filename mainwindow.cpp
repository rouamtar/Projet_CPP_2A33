#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "login.h"
#include "C:\Users\dell\Desktop\kol chay\esprit\smart-court1\salle.h"
#include<QMessageBox>
#include<QIntValidator>
#include<QPixmap>
#include <QSqlQuery>
#include<QTimer>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QPdfWriter>
#include <QTextStream>
#include <QtPrintSupport/QPrintDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);

    //statistique
    QBarSet *set0 = new QBarSet("capacité des salles");


    *set0 <<50<<56<<68<<50<<88<<100;


    QBarSeries *series = new QBarSeries();
    series->append(set0);


    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("statistiques");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories;
    categories <<"salle N°1"<<"salle N°2"<<"salle N°3"<<"salle N°4"<<"salle N°5"<<"salle N°6";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);

    QChartView *chartview = new QChartView(chart);
    chartview->setParent(ui->horizontalFrame_stat);

    //pdp user:
    ui->table_salle->setModel(Etmp.afficher());
    QPixmap pdp("C:/Users/dell/Downloads/ahmed.jpg");
    int w_pdp = ui->label_pdp->width();
    int h_pdp = ui->label_pdp->height();
    ui->label_pdp->setPixmap(pdp.scaled(w_pdp,h_pdp,Qt::KeepAspectRatio));

  //logo smart court:
    QPixmap logo("C:/Users/dell/Downloads/logo2.png");
    int w_logo = ui->label_logo->width();
    int h_logo = ui->label_logo->height();
    ui->label_logo->setPixmap(logo.scaled(w_logo,h_logo,Qt::KeepAspectRatio));

    //combobox_tri
    QStringList list=(QStringList()<<" "<<"Numsalle"<<"Etage"<<"Capacité"<<"Type");
    ui->comboBox_tri->addItems(list);

  /*//map:
    QPixmap map("C:/Users/dell/Downloads/map smart court.png");
    int w_map = ui->label_map->width();
    int h_map = ui->label_map->height();
    ui->label_map->setPixmap(map.scaled(w_map,h_map,Qt::KeepAspectRatio));*/}



MainWindow::~MainWindow(){delete ui;}



void MainWindow::on_pb_ajouter_clicked(){

    int Numsalle=ui->l_Numsalle->text().toInt();
    int etage=ui->l_etage->text().toInt();
    int capaciter=ui->l_capaciter->text().toInt();
    QString type=ui->l_type->text();
    salle S(Numsalle,etage,capaciter,type);
    bool test=S.ajouter();
    if (test){
        ui->table_salle->setModel(Etmp.afficher());
        ui->label_testajout->setStyleSheet("color: #00c800;");
        ui->label_testajout->setText("done!");
        QTimer::singleShot(2000,this,[this] () { ui->label_testajout->setText(""); });}
    else{
          ui->label_testajout->setStyleSheet("color: #ff0000;");
          ui->label_testajout->setText("Salle existe déja!");
          QTimer::singleShot(2000,this,[this] () { ui->label_testajout->setText(""); });
                               //QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                               //QObject::tr("Ajout non effectué.\n"
                               /*"Click Cancel to exit."), QMessageBox::Cancel);*/}}



void MainWindow::on_pb_supprimer_clicked(){

        int Numsalle=ui->l_Numsalle->text().toInt();
        bool test=Etmp.supprimer(Numsalle);
        if (test){            
           ui->table_salle->setModel(Etmp.afficher());
           ui->label_testajout->setStyleSheet("color: #00c800;");
           ui->label_testajout->setText("done!");
           QTimer::singleShot(2000,this,[this] () { ui->label_testajout->setText(""); });
                                //QMessageBox::information(nullptr,QObject::tr("ok"),
                                //QObject::tr("suppression effectué\n"
                                /*"Click Cancel to exit."),QMessageBox::Cancel);*/}
        else{
            ui->label_testajout->setText("Salle n'existe pas!");
            QTimer::singleShot(2000,this,[this] () { ui->label_testajout->setText(""); });
                                /*QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                QObject::tr("suppression non effectué.\n"
                                "Click Cancel to exit."),QMessageBox::Cancel);*/}}



void MainWindow::on_pushButton_recherche_clicked(){

    salle s;
    s.setNumSalle(ui->lineEdit_recherche->text().toInt());
    ui->table_salle->setModel(s.recherche_Numsalle(s.getNumSalle()));
    ui->label_testrecherche->setStyleSheet("color: #00c800;");
    ui->label_testrecherche->setText("done!");
    QTimer::singleShot(2000,this,[this] () { ui->label_testrecherche->setText(""); });}



void MainWindow::on_pushButton_deconnexion_clicked(){close();}



void MainWindow::on_pb_afficher_clicked(){

  ui->table_salle->setModel(Etmp.afficher());
  ui->label_testajout->setStyleSheet("color: #00c800;");
  ui->label_testajout->setText("done!");
  QTimer::singleShot(2000,this,[this] () { ui->label_testajout->setText(""); });}




void MainWindow::on_pushButton_tri_clicked(){

    salle s;
    QSqlQuery query;
    QSqlQueryModel* model= new QSqlQueryModel();

    if (ui->comboBox_tri->currentText()=="Numsalle"){
              query.prepare(QString("SELECT Numsalle FROM salle"));
              query.exec();
              model->setQuery(query);
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numsalle"));
              ui->table_salle->setModel(model);
              ui->label_testrecherche->setStyleSheet("color: #00c800;");
              ui->label_testrecherche->setText("done!");
              QTimer::singleShot(2000,this,[this] () { ui->label_testrecherche->setText(""); });}

    else if (ui->comboBox_tri->currentText()=="Etage"){
              query.prepare(QString("SELECT etage FROM salle"));
              query.exec();
              model->setQuery(query);
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("etage"));
              ui->table_salle->setModel(model);
              ui->label_testrecherche->setStyleSheet("color: #00c800;");
              ui->label_testrecherche->setText("done!");
              QTimer::singleShot(2000,this,[this] () { ui->label_testrecherche->setText(""); });}

    else if (ui->comboBox_tri->currentText()=="Capacité"){
              query.prepare(QString("SELECT capaciter FROM salle"));
              query.exec();
              model->setQuery(query);
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("capaciter"));
              ui->table_salle->setModel(model);
              ui->label_testrecherche->setStyleSheet("color: #00c800;");
              ui->label_testrecherche->setText("done!");
              QTimer::singleShot(2000,this,[this] () { ui->label_testrecherche->setText(""); });}

    else if (ui->comboBox_tri->currentText()=="Type"){
              query.prepare(QString("SELECT type FROM salle"));
              query.exec();
              model->setQuery(query);
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("type"));
              ui->table_salle->setModel(model);
              ui->label_testrecherche->setStyleSheet("color: #00c800;");
              ui->label_testrecherche->setText("done!");
              QTimer::singleShot(2000,this,[this] () { ui->label_testrecherche->setText(""); });}

    else {ui->table_salle->setModel(Etmp.afficher());
        ui->label_testrecherche->setStyleSheet("color: #00c800;");
        ui->label_testrecherche->setText("done!");
        QTimer::singleShot(2000,this,[this] () { ui->label_testrecherche->setText(""); });}
}

void MainWindow::on_pb_pdf_clicked()
{
    QString strStream;
                 QTextStream out(&strStream);

                 const int rowCount = ui->table_salle->model()->rowCount();
                 const int columnCount = ui->table_salle->model()->columnCount();

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
                     if (!ui->table_salle->isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(ui->table_salle->model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 // data table
                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!ui->table_salle->isColumnHidden(column)) {
                             QString data = ui->table_salle->model()->data(ui->table_salle->model()->index(row, column)).toString().simplified();
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

void MainWindow::on_pb_modifier_clicked()
{

    int Numsalle=ui->l_Numsalle->text().toInt();
    int etage=ui->l_etage->text().toInt();
    int capaciter=ui->l_capaciter->text().toInt();
    QString type=ui->l_type->text();

    bool test=Etmp.modifier_salle(Numsalle,etage,capaciter,type);


            if(test)

            {

                 ui->table_salle->setModel(Etmp.afficher());
                 ui->label_testajout->setStyleSheet("color: #00c800;");
                 ui->label_testajout->setText("done!");
                 QTimer::singleShot(2000,this,[this] () { ui->label_testajout->setText(""); });



           }

            else

            {

                ui->label_testajout->setStyleSheet("color: #ff0000;");
                ui->label_testajout->setText("Echec");
                QTimer::singleShot(2000,this,[this] () { ui->label_testajout->setText(""); });

            }




}



void MainWindow::on_pushButton_salle_46_pressed()
{
    ui->pushButton_salle_46->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 230, 0), stop:1 rgba(0, 230, 0));");
}

void MainWindow::on_pushButton_salle_46_released()
{
     ui->pushButton_salle_46->setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(229, 0, 0), stop:1 rgba(229, 0, 0));");
}

void MainWindow::on_pushButton_perso_clicked()
{
    ui->label_acc->setStyleSheet("color: #ff0000;");
    ui->label_acc->setText("page inaccessible");
    QTimer::singleShot(2000,this,[this] () { ui->label_acc->setText(""); });

}

void MainWindow::on_pushButton_aud_clicked()
{
    ui->label_acc->setStyleSheet("color: #ff0000;");
    ui->label_acc->setText("page inaccessible");
    QTimer::singleShot(2000,this,[this] () { ui->label_acc->setText(""); });

}

void MainWindow::on_pushButton_avocat_clicked()
{
    ui->label_acc->setStyleSheet("color: #ff0000;");
    ui->label_acc->setText("page inaccessible");
    QTimer::singleShot(2000,this,[this] () { ui->label_acc->setText(""); });

}

void MainWindow::on_pushButton_parametres_clicked()
{
    ui->label_acc->setStyleSheet("color: #ff0000;");
    ui->label_acc->setText("page inaccessible");
    QTimer::singleShot(2000,this,[this] () { ui->label_acc->setText(""); });

}
