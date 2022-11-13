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




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//ui->le_num_aud->setValidator( new QIntValidator(0,9999999, this));
ui->le_duree->setValidator( new QIntValidator(0,9999999, this));
ui->le_salle->setValidator(new QIntValidator(0,9999999, this));
ui->tab_des_audiences->setModel(A1.afficher());
ui->tv_tri->setModel(A1.afficher());
ui-> tv_histo->setModel(H.Afficher());

//logo smart court:
    QPixmap logo("C:/Users/21652/Downloads/logo2.png");
    int w_logo = ui->label_logo->width();
    int h_logo = ui->label_logo->height();
    ui->label_logo->setPixmap(logo.scaled(w_logo,h_logo,Qt::KeepAspectRatio));

    //statistique
        QBarSet *set0 = new QBarSet("num des Audience  par mois");


        *set0 <<80<<74<<68<<100<<59<<90<<77<<100<<70;


        QBarSeries *series = new QBarSeries();
        series->append(set0);


        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("statistiques");
        chart->setAnimationOptions(QChart::SeriesAnimations);

        QStringList categories;
        categories <<"janvier"<<"fevrier"<<"mars"<<"avril"<<"mai"<<"juin"<<"juillet"<<"aout"<<"septempre";
        QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();
        chart->setAxisX(axis, series);

        QChartView *chartview = new QChartView(chart);
        chartview->setParent(ui->horizontalFrame_stat);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
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
        historique H(operation);
        H.Ajouter();
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



void MainWindow::on_pb_supprimer_clicked()
{ Audience A1;
  historique H;
int id=ui->le_num_aud_supp->text().toInt();
bool test=A1.supprimer(id);
QMessageBox msgBox;
if (test)
{msgBox.setText( "supprimer avec succes.");
ui->tab_des_audiences->setModel(A1.afficher());
QString operation="Suppression";
historique H(operation);
H.Ajouter();
 ui->tv_histo->setModel(H.Afficher());


}
else
msgBox.setText("echec de supprimer");
msgBox.exec();
}






void MainWindow::on_pb_rechercher_clicked()
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
                      historique H(operation);
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

void MainWindow::on_pushButton_6_clicked()
{
    close();
}





void MainWindow::on_pb_email_clicked()
{

    QString link="https://mail.google.com/mail/u/0/#i"
                 "5ox?compose=new";
        QDesktopServices::openUrl(link);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->label_acc->setStyleSheet("color: #ff0000;");
       ui->label_acc->setText("page inaccessible");
       QTimer::singleShot(2000,this,[this] () { ui->label_acc->setText(""); });
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->label_acc->setStyleSheet("color: #ff0000;");
       ui->label_acc->setText("page inaccessible");
       QTimer::singleShot(2000,this,[this] () { ui->label_acc->setText(""); });
}

void MainWindow::on_pushButton_clicked()
{
    ui->label_acc->setStyleSheet("color: #ff0000;");
       ui->label_acc->setText("page inaccessible");
       QTimer::singleShot(2000,this,[this] () { ui->label_acc->setText(""); });
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->label_acc->setStyleSheet("color: #ff0000;");
       ui->label_acc->setText("page inaccessible");
       QTimer::singleShot(2000,this,[this] () { ui->label_acc->setText(""); });
}
