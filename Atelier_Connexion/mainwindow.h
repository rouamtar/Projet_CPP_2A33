#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "aff.juridique.h"
#include <QVector>

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
    void on_pbAjouter_clicked();

    void on_pb_supprimer_clicked();


    void on_le_recherche_textChanged(const QString &arg1);

    void on_pushButton_triernom_clicked();


    QVector<double> statistiques();
    void makePlot();


    void on_pushButton_connexion_clicked();

    void on_pushButton_archiver_roua_clicked();


    void on_pushButton_desarchiver_clicked();

    void on_stat_roua_clicked();

    void on_PDF_roua_clicked();

private:
    Ui::MainWindow *ui;
    Affjuridique A;
};

#endif // MAINWINDOW_H
