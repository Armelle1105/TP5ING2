#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

#include <iostream>
#include <vector>

class Sommet {
private:
    int m_numero;
    std::vector<const Sommet*> m_successeurs;
public:
    Sommet(int num);
    int getNumero() const;
    void addSuccesseur(const Sommet* succ);
    const std::vector<const Sommet*>& getSuccesseurs() const;
    void afficher() const;
};


#endif //TP2_TG_SOMMET_H
