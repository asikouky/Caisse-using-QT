#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->AjouterArticle_pushButton, SIGNAL(clicked(bool)),
    this, SLOT(AjouterArticleUI()));

    QObject::connect(&caisse_, SIGNAL(ajouterArticleCaisseFin(Article*)),
    this, SLOT(ajouterArticleListeVue(Article*)));

    QObject::connect(ui->RetirerArticle_pushButton, SIGNAL(clicked()),
                     this, SLOT(retirerArticleUI()));

    QObject::connect(&caisse_, SIGNAL(retirerArticleCaisseFin(Article*)),
                     this, SLOT(retirerArticleListeVue(Article*)));

    QObject::connect(ui->ReinitialiserCommande_pushButton, SIGNAL(clicked()),
                     this, SLOT(reinitialiserCommande()));

    // Par défaut, le bouton RetirerArticle est désactivé
    ui->RetirerArticle_pushButton->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AjouterArticleUI(){

    try {

        if(ui->NomArticle_lineEdit->text().isEmpty() || ui->PrixArticle_lineEdit->text().isEmpty()){
            throw std::invalid_argument("Veuillez remplir le nom et le prix de l'article avant de l'ajouter!");
        }
        else {
            Article* a = new Article();

            a->description = ui->NomArticle_lineEdit->text().toStdString();
            a->prix = ui->PrixArticle_lineEdit->text().toDouble();
            a->taxable = ui->ArticleTaxable_checkBox->isChecked();

            caisse_.ajouterArticleCaisse(a);

            ui->NomArticle_lineEdit->clear();
            ui->PrixArticle_lineEdit->clear();
            ui->ArticleTaxable_checkBox->setChecked(false);
        }
    }
    catch (std::invalid_argument& e) {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText(e.what());
        msgBox.exec();
    }
}

void MainWindow::ajouterArticleListeVue(Article* a){ //??
    QString Qnom = QString::fromStdString(a->description) + "\t";
    QString Qprix = QString::number(a->prix,'f',2) + "\t";
    QString Qtaxable;
    if (a->taxable)
        Qtaxable = "taxable";
    else
        Qtaxable = "Non-taxable";

    QString Qarticle = Qnom + Qprix + Qtaxable;

    QListWidgetItem* item = new QListWidgetItem(Qarticle, ui->ArticlesAjoutes_listWidget);
    item->setData(Qt::UserRole, QVariant::fromValue<Article*>(a));

    // Si le bouton RetirerArticle est désactivé, l'activer.
    if (!ui->RetirerArticle_pushButton->isEnabled()){
        ui->RetirerArticle_pushButton->setEnabled(true);
    }

    // Mettre à jour les totaux
    mettreAJourTotaux();

}

void MainWindow::retirerArticleUI(){
    vector<Article*> toDelete;
    for(QListWidgetItem* item : ui->ArticlesAjoutes_listWidget->selectedItems()) {
        toDelete.push_back(item->data(Qt::UserRole).value<Article*>());
    }

    for(Article* a : toDelete){
        caisse_.retirerArticleCaisse(a);
    }
}

void MainWindow::retirerArticleListeVue(Article* a){
    for (int i = 0; i < ui->ArticlesAjoutes_listWidget->count(); i++){
        QListWidgetItem *item = ui->ArticlesAjoutes_listWidget->item(i);
        Article* art = item->data(Qt::UserRole).value<Article*>();
        if(art == a) {
            delete item;
            break;
        }
    }
    delete a;    // OU: liste locale d'articles ???

    // Si la liste d'articles est vide, désactiver le bouton RetirerArticle
    if (ui->ArticlesAjoutes_listWidget->count() == 0) {
        ui->RetirerArticle_pushButton->setEnabled(false);
    }

    // Mettre à jour les totaux
    mettreAJourTotaux();

}


void MainWindow::reinitialiserCommande(){
    vector<Article*> toDelete;
    for (int i = 0; i < ui->ArticlesAjoutes_listWidget->count(); i++) {
        QListWidgetItem *item = ui->ArticlesAjoutes_listWidget->item(i);
        toDelete.push_back(item->data(Qt::UserRole).value<Article*>());
    }
    for (Article* a : toDelete) {
        caisse_.retirerArticleCaisse(a);
    }

    // Désactiver le bouton RetirerArticle
    ui->RetirerArticle_pushButton->setEnabled(false);

    // Mettre à jour les totaux
    mettreAJourTotaux();

}

void MainWindow::mettreAJourTotaux(){
    double totalAvantTaxes = caisse_.getTotalAvantTaxes();
    double taxes = caisse_.calculerTaxes();

    // Mettre à jour le total avant taxes
    QString QSousTotal = QString::number(totalAvantTaxes,'f',2);
    ui->TotalAvantTaxes_label->setText(QSousTotal);

    // Mettre à jour les taxes
    QString QTaxes = QString::number(taxes,'f',2);
    ui->TotalDesTaxes_label->setText(QTaxes);

    // Mettre à jour le total après taxes
    QString QTotal = QString::number(totalAvantTaxes + taxes,'f',2);
    ui->TotalAPayer_label->setText(QTotal);
}
