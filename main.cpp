#include <iostream>
#include "graphe.h"

int main()
{
    std::string id;
    graphe g{"graphe_1.txt"};
    g.afficher();
    std::cout << "Quel identifiant voulez-vous choisir ?" << std::endl;
    std::cin>>id;
    g.afficherBFS(id);
    g.afficherDFS(id);
    int ncc=g.rechercher_afficherToutesCC();
    return 0;
}
