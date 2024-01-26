#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "Caisse.h"
#include <iostream>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void mettreAJourTotaux();

public slots:
    void AjouterArticleUI();
    void ajouterArticleListeVue(Article* a);

    void retirerArticleUI();
    void retirerArticleListeVue(Article* a);
    void reinitialiserCommande();

private:
    Ui::MainWindow *ui;
    Caisse caisse_;
};
#endif // MAINWINDOW_H
