

#include "Arete.h"

Arete::Arete(int num) : m_numero{num} {}


void Arete::addSuccesseur(const Arete* succ) {
    m_successeurs.push_back(succ);
}

const std::vector<const Arete*>& Arete::getSuccesseurs() const {
    return m_successeurs;
}

int Arete::getNumero() const {
    return m_numero;
}

void Arete::afficher() const {
    std::cout << "   Sommet " << m_numero << " : ";
    for(auto addrSommet : m_successeurs) {
        std::cout << addrSommet->getNumero() << " ";
    }
}