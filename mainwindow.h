#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "perso.h"
#include "salle.h"
#include"dc.h"
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QBarSet>
#include <QBarSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
/////////////////////////////////////////////
#include "aff.juridique.h"
#include <QVector>
#include "arduino.h"


QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pb_supprimer_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_rechercher_clicked();

    void on_pb_affichier_clicked();

    void on_pb_tri_clicked();

    void on_pb_pdf_clicked();

    void on_pb_imp_clicked();

    void on_pb_modif_clicked();

    void on_pb_email_clicked();

    void on_pushButton_afficher_ela_clicked();

    ////////////////////////////////// roua

    void on_pbAjouter_clicked();

    void on_pb_supprimer_roua_clicked();

    void on_le_recherche_textChanged(const QString &arg1);

    void on_pushButton_triernom_clicked();
    void update_label();


    QVector<double> statistiques();
    void makePlot();


    void on_pushButton_connexion_clicked();

    void on_pushButton_archiver_roua_clicked();


    void on_pushButton_desarchiver_clicked();

    void on_stat_roua_clicked();

    void on_PDF_roua_clicked();

    void on_pushButton_mailing_clicked();

    ////////////////////////////////////////////
    ///
    void on_pb_ajouter_ahmed_clicked();

    void on_pb_modifier_ahmed_clicked();

    void on_pb_supprimer_ahmed_clicked();

    void on_pb_afficher_ahmed_clicked();

    void on_pb_pdf_ahmed_clicked();

    void on_pb_imprimer_ahmed_clicked();

    void on_pushButton_salle_46_pressed();

    void on_pushButton_salle_46_released();

    void on_pushButton_tri_ahmed_clicked();

    void on_pushButton_recherche_ahmed_clicked();

    void update_label_ahmed();


    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    QByteArray data;
    arduino a;
    perso p;
    perso p1;
    dc d;
    Affjuridique A;
    salle Etmp;


};

#endif // MAINWINDOW_H

