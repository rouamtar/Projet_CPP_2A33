#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "aff.juridique.h"

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


private:
    Ui::MainWindow *ui;
    Affjuridique A;
};

#endif // MAINWINDOW_H
