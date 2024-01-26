/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *NomArticle_lineEdit;
    QLineEdit *PrixArticle_lineEdit;
    QPushButton *AjouterArticle_pushButton;
    QPushButton *RetirerArticle_pushButton;
    QPushButton *ReinitialiserCommande_pushButton;
    QCheckBox *ArticleTaxable_checkBox;
    QListWidget *ArticlesAjoutes_listWidget;
    QLabel *TotalAvantTaxes_label;
    QLabel *TotalDesTaxes_label;
    QLabel *TotalAPayer_label;
    QLabel *DescriptionArticle_label;
    QLabel *PrixArticle_label;
    QLabel *SousTotal_label;
    QLabel *ArticlesAjoutes_label;
    QLabel *Taxes_label;
    QLabel *Total_label;
    QLabel *Error_label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        NomArticle_lineEdit = new QLineEdit(centralwidget);
        NomArticle_lineEdit->setObjectName("NomArticle_lineEdit");
        NomArticle_lineEdit->setGeometry(QRect(340, 60, 131, 31));
        PrixArticle_lineEdit = new QLineEdit(centralwidget);
        PrixArticle_lineEdit->setObjectName("PrixArticle_lineEdit");
        PrixArticle_lineEdit->setGeometry(QRect(600, 60, 121, 31));
        AjouterArticle_pushButton = new QPushButton(centralwidget);
        AjouterArticle_pushButton->setObjectName("AjouterArticle_pushButton");
        AjouterArticle_pushButton->setGeometry(QRect(470, 150, 131, 31));
        RetirerArticle_pushButton = new QPushButton(centralwidget);
        RetirerArticle_pushButton->setObjectName("RetirerArticle_pushButton");
        RetirerArticle_pushButton->setGeometry(QRect(30, 310, 131, 31));
        ReinitialiserCommande_pushButton = new QPushButton(centralwidget);
        ReinitialiserCommande_pushButton->setObjectName("ReinitialiserCommande_pushButton");
        ReinitialiserCommande_pushButton->setGeometry(QRect(630, 500, 141, 41));
        ArticleTaxable_checkBox = new QCheckBox(centralwidget);
        ArticleTaxable_checkBox->setObjectName("ArticleTaxable_checkBox");
        ArticleTaxable_checkBox->setGeometry(QRect(470, 110, 121, 31));
        ArticleTaxable_checkBox->setChecked(false);
        ArticlesAjoutes_listWidget = new QListWidget(centralwidget);
        ArticlesAjoutes_listWidget->setObjectName("ArticlesAjoutes_listWidget");
        ArticlesAjoutes_listWidget->setGeometry(QRect(30, 60, 261, 221));
        TotalAvantTaxes_label = new QLabel(centralwidget);
        TotalAvantTaxes_label->setObjectName("TotalAvantTaxes_label");
        TotalAvantTaxes_label->setGeometry(QRect(80, 420, 101, 31));
        TotalDesTaxes_label = new QLabel(centralwidget);
        TotalDesTaxes_label->setObjectName("TotalDesTaxes_label");
        TotalDesTaxes_label->setGeometry(QRect(330, 420, 101, 31));
        TotalAPayer_label = new QLabel(centralwidget);
        TotalAPayer_label->setObjectName("TotalAPayer_label");
        TotalAPayer_label->setGeometry(QRect(580, 420, 111, 31));
        DescriptionArticle_label = new QLabel(centralwidget);
        DescriptionArticle_label->setObjectName("DescriptionArticle_label");
        DescriptionArticle_label->setGeometry(QRect(340, 20, 101, 31));
        PrixArticle_label = new QLabel(centralwidget);
        PrixArticle_label->setObjectName("PrixArticle_label");
        PrixArticle_label->setGeometry(QRect(600, 20, 71, 31));
        SousTotal_label = new QLabel(centralwidget);
        SousTotal_label->setObjectName("SousTotal_label");
        SousTotal_label->setGeometry(QRect(80, 390, 81, 31));
        QFont font;
        font.setBold(true);
        SousTotal_label->setFont(font);
        ArticlesAjoutes_label = new QLabel(centralwidget);
        ArticlesAjoutes_label->setObjectName("ArticlesAjoutes_label");
        ArticlesAjoutes_label->setGeometry(QRect(30, 20, 131, 31));
        Taxes_label = new QLabel(centralwidget);
        Taxes_label->setObjectName("Taxes_label");
        Taxes_label->setGeometry(QRect(330, 396, 49, 20));
        Taxes_label->setFont(font);
        Total_label = new QLabel(centralwidget);
        Total_label->setObjectName("Total_label");
        Total_label->setGeometry(QRect(580, 396, 49, 20));
        Total_label->setFont(font);
        Error_label = new QLabel(centralwidget);
        Error_label->setObjectName("Error_label");
        Error_label->setGeometry(QRect(346, 210, 371, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Caisse", nullptr));
        NomArticle_lineEdit->setText(QString());
        PrixArticle_lineEdit->setText(QString());
        AjouterArticle_pushButton->setText(QCoreApplication::translate("MainWindow", "Ajouter Article", nullptr));
        RetirerArticle_pushButton->setText(QCoreApplication::translate("MainWindow", "Retirer Article", nullptr));
        ReinitialiserCommande_pushButton->setText(QCoreApplication::translate("MainWindow", "R\303\251initialiser Commande", nullptr));
        ArticleTaxable_checkBox->setText(QCoreApplication::translate("MainWindow", "Article Taxable", nullptr));
        TotalAvantTaxes_label->setText(QCoreApplication::translate("MainWindow", "Total Avant Taxes", nullptr));
        TotalDesTaxes_label->setText(QCoreApplication::translate("MainWindow", "Total des Taxes", nullptr));
        TotalAPayer_label->setText(QCoreApplication::translate("MainWindow", "Total \303\200 Payer", nullptr));
        DescriptionArticle_label->setText(QCoreApplication::translate("MainWindow", "Description Article", nullptr));
        PrixArticle_label->setText(QCoreApplication::translate("MainWindow", "Prix Article", nullptr));
        SousTotal_label->setText(QCoreApplication::translate("MainWindow", "Sous Total", nullptr));
        ArticlesAjoutes_label->setText(QCoreApplication::translate("MainWindow", "Articles Ajoutes", nullptr));
        Taxes_label->setText(QCoreApplication::translate("MainWindow", "Taxes", nullptr));
        Total_label->setText(QCoreApplication::translate("MainWindow", "Total", nullptr));
        Error_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
