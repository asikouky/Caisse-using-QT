#ifndef CAISSE_H
#define CAISSE_H

#include <QObject>
using namespace std;

struct Article {
    string description;
    double prix;
    bool taxable;

};


class Caisse : public QObject
{
    Q_OBJECT
public:
    explicit Caisse(QObject *parent = nullptr);
    void calculerTotalAvantTaxes(Article* a, bool ajouter);
    double calculerTaxes();

    void ajouterArticleCaisse(Article* a);
    void retirerArticleCaisse(Article* a);

    double getTotalAvantTaxes() {return totalAvantTaxes_;}

signals:
    void ajouterArticleCaisseFin(Article* a);
    void retirerArticleCaisseFin(Article* a);

private:
    vector<Article*> articles_;  // Le conteneur STL approprié?
    double totalAvantTaxes_;

};

#endif // CAISSE_H
