#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "C:\Users\dell\Desktop\kol chay\esprit\smart-court1\salle.h"
#include <QMainWindow>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QBarSet>
#include <QBarSeries>




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
    //void on_pushButton_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_ajouter_clicked();

    //void on_tabWidget_currentChanged(int index);

    //void on_table_salle_activated(const QModelIndex &index);

    //void on_comboBox_salle_activated(int index);

    //void on_comboBox_salle_currentIndexChanged(int index);

    //void on_comboBox_salle_currentIndexChanged(const QString &arg1);

    //void on_pb_modifier_clicked();

    void on_pushButton_recherche_clicked();

    void on_pb_imprimer_clicked();

    //void on_pb_pdf_clicked();

    void on_pushButton_deconnexion_clicked();


    void on_pb_afficher_clicked();


    void on_pushButton_tri_clicked();

    void on_pb_pdf_clicked();

    //void on_pb_imprimer_clicked();

    void on_pb_modifier_clicked();


    void on_pushButton_salle_46_pressed();

    void on_pushButton_salle_46_released();

    void on_pushButton_perso_clicked();

    void on_pushButton_aud_clicked();

    void on_pushButton_avocat_clicked();

    void on_pushButton_parametres_clicked();

private:
    Ui::MainWindow *ui;
   salle Etmp;
};

#endif // MAINWINDOW_H
