#include "Graphe.h"
#include <fstream>
#include <algorithm>
#include <queue>
#include <limits>
#include <string>


Graphe::Graphe(std::string const cheminFichierGraphe) {
    std::ifstream ifs{cheminFichierGraphe};
    if(!ifs) {
        throw std::runtime_error("Impossible d'ouvrir " + cheminFichierGraphe);
    }
    ifs >> m_estOriente;
    if(ifs.fail()) {
        throw std::runtime_error("Probl�me de lecture de l'orientation du graphe.");
    }
    int taille;
    ifs >> taille;
    if(ifs.fail()) {
        throw std::runtime_error("Probl�me de lecture de la taille du graphe.");
    }

for(int i=0; i<ordre; ++i) {
m_sommets.push_back(new Sommet(i));
}
int num1, num2, poids;
for(int i=0; i<taille; ++i) {
ifs >> num1 >> num2 >> poids;
if(ifs.fail()) {
throw std::runtime_error("Problème de lecture d'un.e arc/arête.");
}
m_sommets[num1]->addSuccesseur(m_sommets[num2], poids);
if(!m_estOriente && num1 < num2 < poids) {
m_sommets[num2]->addSuccesseur(m_sommets[num1, poids]);
}
}
}



Graphe::~Graphe() {
    for(auto addrSommet : m_sommets) {
        delete addrSommet;
    }
}


void Graphe::afficherSommet() const {
    int i = 0;
    for (auto sommet: m_sommets) {
        std::cout << i << " ";
        sommet->afficher();
        std::cout << std::endl;
        i++;
    }
}


void Graphe::afficherInfo() const {
    std::cout<< "Liste des sommets : " << std::endl;
    for (auto sommet: m_sommets){
        sommet->afficher();
        std::cout << std::endl;

    }
    std::cout<< " " << std::endl;
    std::cout << "Liste des aretes : " << std::endl;
    for (auto s: m_sommets){
        s->afficher_arrete();
    }
}



std::vector<Arete*> Graphe::Kruskal() {
    //std::cout << "DEBUT DE KRUSKAL" << std::endl << std::endl;
    std::vector<Arete*> aretesTriees = m_aretes;
    std::vector<int> numCC;
    int nb_aretes = 0;
    int poidsTotal = 0;

    //Classer les arêtes par ordre croissant
    std::sort(aretesTriees.begin(), aretesTriees.end(), [](const Arete* a1, const Arete* a2) { return a1->getPoids() < a2->getPoids();});

    /*std::cout << "Poids par ordre croissant : ";
    for(auto it = aretesTriees.begin();it!=aretesTriees.end();++it) {
        std::cout << (*it)->getPoids() << " ";
    }
    std::cout << std::endl;*/

    //std::cout << "NumCC initialisés : ";
    for (unsigned int i=0;i<m_sommets.size();i++)
    {
        numCC.push_back(i);
        //std::cout << numCC[i] << " " << std::endl;
    }
    //std::cout << std::endl;
    std::vector<Arete*> aretesKruskal;
    int i,j,a=0;
    while (nb_aretes < aretesTriees.size()) {
        i = aretesTriees[nb_aretes]->get1();
        j = aretesTriees[nb_aretes]->get2();

        if (numCC[i] != numCC[j]) {
            if (numCC[j] > numCC[i]){

                for (unsigned int k=0; k < aretesTriees.size();k++){

                    if (numCC[k]==numCC[j])
                    {
                        if(k!=j){
                            numCC[k]= numCC[i];
                        }
                    }

                }
                numCC[j] = numCC[i];
            }
            if(numCC[j] < numCC[i]){
                for (unsigned int k=0; k < aretesTriees.size();k++){
                    if (numCC[k]==numCC[i])
                    {
                        if(k!=i){
                            numCC[k]= numCC[j];
                        }
                    }

                }
                numCC[i] = numCC[j];
            }

            //std::cout<<numCC[i]<<"    "<<numCC[j]<<std::endl;
            int poids=aretesTriees[nb_aretes]->getDistance();
            int extremite1=aretesTriees[nb_aretes]->get1();
            int extremite2=aretesTriees[nb_aretes]->get2();
            aretesKruskal.push_back(new Arete(poids,m_sommets[extremite1],m_sommets[extremite2]));

            //std::cout << extremite1 <<"---"<<poids<<"---"<<extremite2<< std::endl;
            poidsTotal = poidsTotal + poids;
            a++;
        }
        nb_aretes++;
    }
    //std::cout << "Poids total : " << poidsTotal << std::endl;
    //std::cout << std::endl << "FIN DE KRUSKAL" << std::endl;
    return aretesKruskal;
}




