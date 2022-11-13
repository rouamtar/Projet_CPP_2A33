#include "login.h"
#include "ui_login.h"
#include<QMessageBox>
#include<QTimer>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    QPixmap logo("C:/Users/dell/Downloads/logo2.png");
    int w_logo = ui->label_logo->width();
    int h_logo = ui->label_logo->height();
    ui->label_logo->setPixmap(logo.scaled(w_logo,h_logo,Qt::KeepAspectRatio)); //logo smart court
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_connexion_clicked()
{
   QString username = ui->lineEdit_username->text();
   QString password = ui->lineEdit_password->text();

   if(username == "salle" && password == "admin"){
       ui->label_connexion->setText("connected");
       //QMessageBox::information(this, "login", "connected");
       hide();
       mainwindow = new MainWindow(this);
       mainwindow->show();
   }
   else{

        ui->label_connexion->setStyleSheet("color: #ff0000;");
        ui->label_connexion->setText("User Name or Password is not correct");
        QTimer::singleShot(2000,this,[this] () { ui->label_connexion->setText(""); });
   }
}
