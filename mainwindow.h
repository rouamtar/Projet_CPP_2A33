#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include  "audience.h"
#include<QtCharts>
#include<QChartView>
#include<QBarSet>
#include<QBarSeries>
#include "historique.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    
    void on_pb_ajouter_clicked();
    
    void on_pb_supprimer_clicked();



    void on_pb_rechercher_clicked();

    void on_pb_modifier_clicked();

    void on_le_tri_na_textChanged(const QString &arg1);

    void on_pb_PDF_clicked();

    void on_pb_imprimer_clicked();

    void on_pushButton_6_clicked();

    void on_pb_email_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    Audience A1;
      historique H;
};

#endif // MAINWINDOW_H
