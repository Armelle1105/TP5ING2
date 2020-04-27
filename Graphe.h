#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include "Sommet.h"
#include "Arete.h"

class Graphe {
private:
    bool m_estOriente;
    std::vector<Arete*> m_aretes;
    std::vector<Sommet*> m_sommets;
public:
    explicit Graphe(std::string const cheminFichierGraphe);
    ~Graphe() = default;
    void afficherInfo() const;
    void afficherSommet() const;
    std::vector<Arete*> Kruskal();

    void dessiner();
};



#endif // GRAPHE_H_INCLUDED

