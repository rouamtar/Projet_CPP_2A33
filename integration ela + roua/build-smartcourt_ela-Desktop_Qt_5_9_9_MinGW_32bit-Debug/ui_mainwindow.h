/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QColumnView>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QColumnView *columnView;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLabel *label_2;
    QPushButton *pushButton_8;
    QStackedWidget *stackedWidget;
    QWidget *page_connexion;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_password;
    QPushButton *pushButton_connexion;
    QLabel *label_16;
    QLabel *label_17;
    QWidget *page_personnels;
    QTabWidget *tab_perso;
    QWidget *tab_9;
    QGroupBox *groupBox_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *L_nomprenom;
    QLineEdit *L_CIN;
    QLineEdit *L_num;
    QLineEdit *L_adr;
    QPushButton *pb_ajouter;
    QLineEdit *L_poste;
    QPushButton *pb_modif;
    QPushButton *pb_email;
    QTableView *tableView;
    QPushButton *pb_pdf;
    QPushButton *pb_imp;
    QPushButton *pb_affichier;
    QPushButton *pb_tri;
    QPushButton *pb_rechercher;
    QLineEdit *lineEdit_recherche;
    QComboBox *comboBox_tri;
    QLabel *label_ajout;
    QLabel *label_test_recherche;
    QWidget *tab_3;
    QLabel *label;
    QLineEdit *L_CIN_supp;
    QPushButton *pb_supprimer;
    QLabel *label_supp;
    QWidget *tab_4;
    QTableView *tableView_dc;
    QPushButton *pushButton_afficher_ela;
    QWidget *tab_2;
    QFrame *horizontalFrame;
    QHBoxLayout *horizontalLayout;
    QWidget *page_affaires;
    QTabWidget *tabWidget;
    QWidget *tab_10;
    QGroupBox *groupBox_4;
    QLabel *label_5;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *le_id;
    QLineEdit *le_nom;
    QLineEdit *le_prenom;
    QDateEdit *le_date;
    QLabel *label_20;
    QLineEdit *le_num;
    QLabel *label_21;
    QLabel *label_22;
    QLineEdit *lemprete;
    QLabel *label_23;
    QLineEdit *le_dec;
    QLabel *label_24;
    QLabel *label_25;
    QComboBox *comboBox_type;
    QComboBox *comboBox_etat;
    QPushButton *pbAjouter;
    QWidget *tab_11;
    QTableView *tab_affjuridique;
    QLineEdit *le_recherche;
    QLabel *label_26;
    QPushButton *pushButton_triernom;
    QPushButton *pushButton_archiver_roua;
    QPushButton *PDF_roua;
    QWidget *tab_12;
    QLabel *label_27;
    QLineEdit *le_id_supp;
    QPushButton *pb_supprimer_roua;
    QWidget *tab_13;
    QCustomPlot *customplot;
    QPushButton *stat_roua;
    QPushButton *pushButton_mailing;
    QWidget *tab_14;
    QTableView *tableView_archive_dossier;
    QPushButton *pushButton_desarchiver;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1397, 732);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        columnView = new QColumnView(centralwidget);
        columnView->setObjectName(QStringLiteral("columnView"));
        columnView->setGeometry(QRect(0, 0, 181, 601));
        columnView->setStyleSheet(QStringLiteral("background-color: rgb(45, 62, 99);"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(-10, 290, 191, 28));
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(45, 62, 99), stop:1 rgba(45, 62, 99));\n"
"\n"
"color: rgb(255, 255, 255);\n"
"\n"
"border : none;\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(51, 65, 145), stop:1 rgba(51, 65, 145));\n"
"}"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(0, 320, 171, 28));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(45, 62, 99), stop:1 rgba(45, 62, 99));\n"
"\n"
"color: rgb(255, 255, 255);\n"
"\n"
"border : none;\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(51, 65, 145), stop:1 rgba(51, 65, 145));\n"
"}"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(-10, 350, 181, 28));
        pushButton_4->setFont(font);
        pushButton_4->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(45, 62, 99), stop:1 rgba(45, 62, 99));\n"
"\n"
"color: rgb(255, 255, 255);\n"
"\n"
"border : none;\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(51, 65, 145), stop:1 rgba(51, 65, 145));\n"
"}"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(-10, 410, 191, 31));
        QFont font1;
        font1.setPointSize(6);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_5->setFont(font1);
        pushButton_5->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(45, 62, 99), stop:1 rgba(45, 62, 99));\n"
"\n"
"color: rgb(255, 255, 255);\n"
"\n"
"border : none;\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(51, 65, 145), stop:1 rgba(51, 65, 145));\n"
"}"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 380, 141, 28));
        pushButton_6->setFont(font);
        pushButton_6->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(45, 62, 99), stop:1 rgba(45, 62, 99));\n"
"\n"
"color: rgb(255, 255, 255);\n"
"\n"
"border : none;\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(51, 65, 145), stop:1 rgba(51, 65, 145));\n"
"}"));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(30, 60, 111, 131));
        QIcon icon;
        icon.addFile(QStringLiteral("../../Documents/Uni/ela.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon);
        pushButton_7->setIconSize(QSize(150, 150));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 10, 91, 21));
        QFont font2;
        font2.setFamily(QStringLiteral("Tw Cen MT"));
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(10, 260, 151, 28));
        pushButton_8->setFont(font);
        pushButton_8->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(45, 62, 99), stop:1 rgba(45, 62, 99));\n"
"\n"
"color: rgb(255, 255, 255);\n"
"\n"
"border : none;\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(51, 65, 145), stop:1 rgba(51, 65, 145));\n"
"}"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(190, 10, 1151, 641));
        page_connexion = new QWidget();
        page_connexion->setObjectName(QStringLiteral("page_connexion"));
        groupBox = new QGroupBox(page_connexion);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(360, 110, 331, 311));
        lineEdit_username = new QLineEdit(groupBox);
        lineEdit_username->setObjectName(QStringLiteral("lineEdit_username"));
        lineEdit_username->setGeometry(QRect(121, 104, 137, 22));
        lineEdit_password = new QLineEdit(groupBox);
        lineEdit_password->setObjectName(QStringLiteral("lineEdit_password"));
        lineEdit_password->setGeometry(QRect(121, 155, 137, 22));
        pushButton_connexion = new QPushButton(groupBox);
        pushButton_connexion->setObjectName(QStringLiteral("pushButton_connexion"));
        pushButton_connexion->setGeometry(QRect(121, 206, 93, 28));
        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(30, 100, 56, 16));
        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(30, 160, 81, 16));
        stackedWidget->addWidget(page_connexion);
        page_personnels = new QWidget();
        page_personnels->setObjectName(QStringLiteral("page_personnels"));
        tab_perso = new QTabWidget(page_personnels);
        tab_perso->setObjectName(QStringLiteral("tab_perso"));
        tab_perso->setGeometry(QRect(0, 20, 1111, 571));
        QFont font3;
        font3.setFamily(QStringLiteral("Tw Cen MT Condensed Extra Bold"));
        font3.setPointSize(11);
        font3.setBold(false);
        font3.setWeight(50);
        tab_perso->setFont(font3);
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        groupBox_2 = new QGroupBox(tab_9);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 0, 1101, 601));
        QFont font4;
        font4.setFamily(QStringLiteral("Tw Cen MT Condensed Extra Bold"));
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        groupBox_2->setFont(font4);
        groupBox_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 50, 151, 16));
        QFont font5;
        font5.setFamily(QStringLiteral("Tw Cen MT"));
        font5.setPointSize(12);
        font5.setBold(true);
        font5.setWeight(75);
        label_6->setFont(font5);
        label_6->setStyleSheet(QStringLiteral("color: rgb(0, 0, 127);"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 90, 56, 16));
        label_7->setFont(font5);
        label_7->setStyleSheet(QStringLiteral("color: rgb(0, 0, 127);"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 130, 201, 16));
        label_8->setFont(font5);
        label_8->setStyleSheet(QStringLiteral("color: rgb(0, 0, 127);"));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 170, 91, 16));
        label_9->setFont(font5);
        label_9->setStyleSheet(QStringLiteral("color: rgb(0, 0, 127);"));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 210, 56, 16));
        label_10->setFont(font5);
        label_10->setStyleSheet(QStringLiteral("color: rgb(0, 0, 127);"));
        L_nomprenom = new QLineEdit(groupBox_2);
        L_nomprenom->setObjectName(QStringLiteral("L_nomprenom"));
        L_nomprenom->setGeometry(QRect(220, 50, 113, 22));
        L_CIN = new QLineEdit(groupBox_2);
        L_CIN->setObjectName(QStringLiteral("L_CIN"));
        L_CIN->setGeometry(QRect(220, 90, 113, 22));
        L_num = new QLineEdit(groupBox_2);
        L_num->setObjectName(QStringLiteral("L_num"));
        L_num->setGeometry(QRect(220, 130, 113, 22));
        L_adr = new QLineEdit(groupBox_2);
        L_adr->setObjectName(QStringLiteral("L_adr"));
        L_adr->setGeometry(QRect(220, 170, 113, 22));
        pb_ajouter = new QPushButton(groupBox_2);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(80, 250, 93, 28));
        QFont font6;
        font6.setFamily(QStringLiteral("Tw Cen MT"));
        font6.setPointSize(10);
        font6.setBold(true);
        font6.setWeight(75);
        pb_ajouter->setFont(font6);
        pb_ajouter->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        L_poste = new QLineEdit(groupBox_2);
        L_poste->setObjectName(QStringLiteral("L_poste"));
        L_poste->setGeometry(QRect(220, 210, 113, 22));
        pb_modif = new QPushButton(groupBox_2);
        pb_modif->setObjectName(QStringLiteral("pb_modif"));
        pb_modif->setGeometry(QRect(180, 250, 93, 28));
        pb_modif->setFont(font6);
        pb_modif->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        pb_email = new QPushButton(groupBox_2);
        pb_email->setObjectName(QStringLiteral("pb_email"));
        pb_email->setGeometry(QRect(110, 280, 141, 28));
        QFont font7;
        font7.setFamily(QStringLiteral("Tw Cen MT"));
        font7.setPointSize(10);
        font7.setBold(true);
        font7.setItalic(false);
        font7.setWeight(75);
        pb_email->setFont(font7);
        pb_email->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        tableView = new QTableView(groupBox_2);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(360, 50, 701, 371));
        pb_pdf = new QPushButton(groupBox_2);
        pb_pdf->setObjectName(QStringLiteral("pb_pdf"));
        pb_pdf->setGeometry(QRect(440, 430, 111, 28));
        pb_pdf->setFont(font6);
        pb_pdf->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        pb_imp = new QPushButton(groupBox_2);
        pb_imp->setObjectName(QStringLiteral("pb_imp"));
        pb_imp->setGeometry(QRect(560, 430, 93, 28));
        pb_imp->setFont(font6);
        pb_imp->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        pb_affichier = new QPushButton(groupBox_2);
        pb_affichier->setObjectName(QStringLiteral("pb_affichier"));
        pb_affichier->setGeometry(QRect(960, 430, 93, 28));
        pb_affichier->setFont(font6);
        pb_affichier->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        pb_tri = new QPushButton(groupBox_2);
        pb_tri->setObjectName(QStringLiteral("pb_tri"));
        pb_tri->setGeometry(QRect(910, 20, 93, 28));
        pb_tri->setFont(font6);
        pb_tri->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        pb_rechercher = new QPushButton(groupBox_2);
        pb_rechercher->setObjectName(QStringLiteral("pb_rechercher"));
        pb_rechercher->setGeometry(QRect(490, 20, 93, 28));
        pb_rechercher->setFont(font6);
        pb_rechercher->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        lineEdit_recherche = new QLineEdit(groupBox_2);
        lineEdit_recherche->setObjectName(QStringLiteral("lineEdit_recherche"));
        lineEdit_recherche->setGeometry(QRect(370, 20, 113, 22));
        comboBox_tri = new QComboBox(groupBox_2);
        comboBox_tri->setObjectName(QStringLiteral("comboBox_tri"));
        comboBox_tri->setGeometry(QRect(790, 20, 101, 22));
        label_ajout = new QLabel(groupBox_2);
        label_ajout->setObjectName(QStringLiteral("label_ajout"));
        label_ajout->setGeometry(QRect(130, 330, 101, 31));
        label_test_recherche = new QLabel(groupBox_2);
        label_test_recherche->setObjectName(QStringLiteral("label_test_recherche"));
        label_test_recherche->setGeometry(QRect(660, 30, 56, 16));
        tab_perso->addTab(tab_9, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(130, 50, 56, 16));
        label->setFont(font6);
        label->setStyleSheet(QStringLiteral("color: rgb(0, 0, 127);"));
        L_CIN_supp = new QLineEdit(tab_3);
        L_CIN_supp->setObjectName(QStringLiteral("L_CIN_supp"));
        L_CIN_supp->setGeometry(QRect(180, 50, 113, 22));
        pb_supprimer = new QPushButton(tab_3);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(310, 50, 93, 28));
        pb_supprimer->setFont(font6);
        label_supp = new QLabel(tab_3);
        label_supp->setObjectName(QStringLiteral("label_supp"));
        label_supp->setGeometry(QRect(150, 100, 191, 41));
        tab_perso->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tableView_dc = new QTableView(tab_4);
        tableView_dc->setObjectName(QStringLiteral("tableView_dc"));
        tableView_dc->setGeometry(QRect(260, 10, 611, 381));
        pushButton_afficher_ela = new QPushButton(tab_4);
        pushButton_afficher_ela->setObjectName(QStringLiteral("pushButton_afficher_ela"));
        pushButton_afficher_ela->setGeometry(QRect(530, 420, 93, 28));
        pushButton_afficher_ela->setFont(font6);
        tab_perso->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        horizontalFrame = new QFrame(tab_2);
        horizontalFrame->setObjectName(QStringLiteral("horizontalFrame"));
        horizontalFrame->setGeometry(QRect(10, 10, 1121, 551));
        horizontalLayout = new QHBoxLayout(horizontalFrame);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tab_perso->addTab(tab_2, QString());
        stackedWidget->addWidget(page_personnels);
        page_affaires = new QWidget();
        page_affaires->setObjectName(QStringLiteral("page_affaires"));
        tabWidget = new QTabWidget(page_affaires);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 20, 1111, 601));
        tab_10 = new QWidget();
        tab_10->setObjectName(QStringLiteral("tab_10"));
        groupBox_4 = new QGroupBox(tab_10);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(140, 50, 431, 441));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(61, 360, 54, 16));
        label_18 = new QLabel(groupBox_4);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(61, 198, 71, 16));
        label_19 = new QLabel(groupBox_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(61, 239, 88, 16));
        le_id = new QLineEdit(groupBox_4);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(211, 353, 137, 22));
        le_nom = new QLineEdit(groupBox_4);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(211, 193, 137, 22));
        le_prenom = new QLineEdit(groupBox_4);
        le_prenom->setObjectName(QStringLiteral("le_prenom"));
        le_prenom->setGeometry(QRect(211, 233, 137, 22));
        le_date = new QDateEdit(groupBox_4);
        le_date->setObjectName(QStringLiteral("le_date"));
        le_date->setGeometry(QRect(211, 273, 82, 22));
        label_20 = new QLabel(groupBox_4);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(61, 279, 87, 16));
        le_num = new QLineEdit(groupBox_4);
        le_num->setObjectName(QStringLiteral("le_num"));
        le_num->setGeometry(QRect(211, 33, 137, 22));
        label_21 = new QLabel(groupBox_4);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(61, 36, 73, 16));
        label_22 = new QLabel(groupBox_4);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(61, 117, 29, 16));
        lemprete = new QLineEdit(groupBox_4);
        lemprete->setObjectName(QStringLiteral("lemprete"));
        lemprete->setGeometry(QRect(211, 313, 137, 22));
        label_23 = new QLabel(groupBox_4);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(61, 320, 71, 16));
        le_dec = new QLineEdit(groupBox_4);
        le_dec->setObjectName(QStringLiteral("le_dec"));
        le_dec->setGeometry(QRect(211, 153, 137, 22));
        label_24 = new QLabel(groupBox_4);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(61, 77, 69, 16));
        label_25 = new QLabel(groupBox_4);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(61, 158, 48, 16));
        comboBox_type = new QComboBox(groupBox_4);
        comboBox_type->setObjectName(QStringLiteral("comboBox_type"));
        comboBox_type->setGeometry(QRect(210, 110, 121, 22));
        comboBox_etat = new QComboBox(groupBox_4);
        comboBox_etat->setObjectName(QStringLiteral("comboBox_etat"));
        comboBox_etat->setGeometry(QRect(210, 70, 121, 22));
        pbAjouter = new QPushButton(tab_10);
        pbAjouter->setObjectName(QStringLiteral("pbAjouter"));
        pbAjouter->setGeometry(QRect(310, 510, 75, 23));
        tabWidget->addTab(tab_10, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName(QStringLiteral("tab_11"));
        tab_affjuridique = new QTableView(tab_11);
        tab_affjuridique->setObjectName(QStringLiteral("tab_affjuridique"));
        tab_affjuridique->setGeometry(QRect(30, 110, 1011, 371));
        le_recherche = new QLineEdit(tab_11);
        le_recherche->setObjectName(QStringLiteral("le_recherche"));
        le_recherche->setGeometry(QRect(180, 80, 113, 20));
        label_26 = new QLabel(tab_11);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(100, 80, 81, 20));
        pushButton_triernom = new QPushButton(tab_11);
        pushButton_triernom->setObjectName(QStringLiteral("pushButton_triernom"));
        pushButton_triernom->setGeometry(QRect(870, 80, 161, 23));
        pushButton_archiver_roua = new QPushButton(tab_11);
        pushButton_archiver_roua->setObjectName(QStringLiteral("pushButton_archiver_roua"));
        pushButton_archiver_roua->setGeometry(QRect(930, 490, 93, 28));
        PDF_roua = new QPushButton(tab_11);
        PDF_roua->setObjectName(QStringLiteral("PDF_roua"));
        PDF_roua->setGeometry(QRect(742, 80, 91, 29));
        tabWidget->addTab(tab_11, QString());
        tab_12 = new QWidget();
        tab_12->setObjectName(QStringLiteral("tab_12"));
        label_27 = new QLabel(tab_12);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(30, 25, 181, 31));
        le_id_supp = new QLineEdit(tab_12);
        le_id_supp->setObjectName(QStringLiteral("le_id_supp"));
        le_id_supp->setGeometry(QRect(260, 30, 113, 20));
        pb_supprimer_roua = new QPushButton(tab_12);
        pb_supprimer_roua->setObjectName(QStringLiteral("pb_supprimer_roua"));
        pb_supprimer_roua->setGeometry(QRect(160, 120, 75, 23));
        tabWidget->addTab(tab_12, QString());
        tab_13 = new QWidget();
        tab_13->setObjectName(QStringLiteral("tab_13"));
        customplot = new QCustomPlot(tab_13);
        customplot->setObjectName(QStringLiteral("customplot"));
        customplot->setGeometry(QRect(160, 100, 601, 341));
        stat_roua = new QPushButton(tab_13);
        stat_roua->setObjectName(QStringLiteral("stat_roua"));
        stat_roua->setGeometry(QRect(870, 60, 121, 29));
        pushButton_mailing = new QPushButton(tab_13);
        pushButton_mailing->setObjectName(QStringLiteral("pushButton_mailing"));
        pushButton_mailing->setGeometry(QRect(750, 60, 75, 23));
        tabWidget->addTab(tab_13, QString());
        tab_14 = new QWidget();
        tab_14->setObjectName(QStringLiteral("tab_14"));
        tableView_archive_dossier = new QTableView(tab_14);
        tableView_archive_dossier->setObjectName(QStringLiteral("tableView_archive_dossier"));
        tableView_archive_dossier->setGeometry(QRect(30, 80, 971, 381));
        pushButton_desarchiver = new QPushButton(tab_14);
        pushButton_desarchiver->setObjectName(QStringLiteral("pushButton_desarchiver"));
        pushButton_desarchiver->setGeometry(QRect(900, 470, 93, 28));
        tabWidget->addTab(tab_14, QString());
        stackedWidget->addWidget(page_affaires);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1397, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);
        tab_perso->setCurrentIndex(2);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Gestion des personnels", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Gestion des audiences", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Gestion des avocats", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "Gestion des affaires juridiques", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "Gestion des salles", Q_NULLPTR));
        pushButton_7->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "Bienvenue", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "Se connecter", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Connexion", Q_NULLPTR));
        pushButton_connexion->setText(QApplication::translate("MainWindow", "Connexion", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "Gestion", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "Mot de passe", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Gestion des personnels", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Nom et pr\303\251nom :", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "CIN :", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Num\303\251ro de t\303\251l\303\251phone :", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Adresse :", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Poste :", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        pb_modif->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        pb_email->setText(QApplication::translate("MainWindow", "Envoyer un E-mail", Q_NULLPTR));
        pb_pdf->setText(QApplication::translate("MainWindow", "Exporter PDF", Q_NULLPTR));
        pb_imp->setText(QApplication::translate("MainWindow", "Imprimer", Q_NULLPTR));
        pb_affichier->setText(QApplication::translate("MainWindow", "Afficher", Q_NULLPTR));
        pb_tri->setText(QApplication::translate("MainWindow", "Trier", Q_NULLPTR));
        pb_rechercher->setText(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        label_ajout->setText(QString());
        label_test_recherche->setText(QString());
        tab_perso->setTabText(tab_perso->indexOf(tab_9), QApplication::translate("MainWindow", "Ajouter un personnel", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "CIN :", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label_supp->setText(QString());
        tab_perso->setTabText(tab_perso->indexOf(tab_3), QApplication::translate("MainWindow", "Supprimer un personnel", Q_NULLPTR));
        pushButton_afficher_ela->setText(QApplication::translate("MainWindow", "Afficher ", Q_NULLPTR));
        tab_perso->setTabText(tab_perso->indexOf(tab_4), QApplication::translate("MainWindow", "Donn\303\251es Critiques", Q_NULLPTR));
        tab_perso->setTabText(tab_perso->indexOf(tab_2), QApplication::translate("MainWindow", "Statistiques", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Ajout", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Id avocat", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "Nom Accus\303\251", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "Prenom Accus\303\251", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "Date naissance", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "Num Dossier", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "Type", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "Empreinte", Q_NULLPTR));
        label_24->setText(QApplication::translate("MainWindow", "Etat Dossier", Q_NULLPTR));
        label_25->setText(QApplication::translate("MainWindow", "Decision", Q_NULLPTR));
        comboBox_type->clear();
        comboBox_type->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Divorce", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Murder", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Theft", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Rape", Q_NULLPTR)
        );
        comboBox_etat->clear();
        comboBox_etat->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "En cours", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Fini", Q_NULLPTR)
        );
        pbAjouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_10), QApplication::translate("MainWindow", "Ajouter une affaire", Q_NULLPTR));
        label_26->setText(QApplication::translate("MainWindow", "Recherche", Q_NULLPTR));
        pushButton_triernom->setText(QApplication::translate("MainWindow", "Trier par nom", Q_NULLPTR));
        pushButton_archiver_roua->setText(QApplication::translate("MainWindow", "Archiver", Q_NULLPTR));
        PDF_roua->setText(QApplication::translate("MainWindow", "Generer PDF", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_11), QApplication::translate("MainWindow", "Afficher une affaire", Q_NULLPTR));
        label_27->setText(QApplication::translate("MainWindow", "Numero dossier \303\240 supprimer", Q_NULLPTR));
        pb_supprimer_roua->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_12), QApplication::translate("MainWindow", "supprimer une affaire", Q_NULLPTR));
        stat_roua->setText(QApplication::translate("MainWindow", "statistiques_type", Q_NULLPTR));
        pushButton_mailing->setText(QApplication::translate("MainWindow", "mail", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_13), QApplication::translate("MainWindow", "Statistique", Q_NULLPTR));
        pushButton_desarchiver->setText(QApplication::translate("MainWindow", "D\303\251sarchiver", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_14), QApplication::translate("MainWindow", "Archive", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
