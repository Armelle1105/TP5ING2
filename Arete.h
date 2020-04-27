


#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED

#include <iostream>
#include <vector>

class Arete {
private:
    int m_numero;
    std::vector<const Arete*> m_successeurs;
public:
    Arete(int num);
    int getNumero() const;
    void addSuccesseur(const Arete* succ);
    const std::vector<const Arete*>& getSuccesseurs() const;
    void afficher() const;
};


#endif
f