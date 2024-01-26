#include "Caisse.h"

Caisse::Caisse(QObject *parent)
    : QObject{parent}
{

}

void Caisse::ajouterArticleCaisse(Article* a){
    articles_.push_back(a);
    calculerTotalAvantTaxes(a, true);
    emit ajouterArticleCaisseFin(a);
}

void Caisse::retirerArticleCaisse(Article* a){
    auto it = find(articles_.begin(), articles_.end(), a);
    if(it != articles_.end()){
        Article* art = *it;
        articles_.erase(it);
        calculerTotalAvantTaxes(art, false);

        emit retirerArticleCaisseFin(art);
    }
}


void Caisse::calculerTotalAvantTaxes(Article* a, bool ajouter){
    if (ajouter)
        totalAvantTaxes_ += a->prix;
    else
        totalAvantTaxes_ -= a->prix;
}

double Caisse::calculerTaxes(){
    double somme = 0;
    for_each(articles_.begin(), articles_.end(),
             [&](auto& elem) {if (elem->taxable) return somme += elem->prix*0.14975;});

    return somme;
}



