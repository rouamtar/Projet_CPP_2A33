#include "mainwindow.h"
#include "login.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"


int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnect();
    login l;
    MainWindow w;
         if(test){
            l.show();}
         else
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
            QObject::tr("connection failed.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
        return a.exec();}
