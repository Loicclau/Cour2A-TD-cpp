#pragma once

#include <vector>
#include <iostream>


class SearchingAlgorithm {
    
protected:
    int numberComparaisons;
    //Nbr total de comparaisons effectuées par toutes les instances
    static int totalComparaisons;
    //Nbr total de recherches effectuées par toutes les instances
    static int totalSearch;
    //Nbr moyen de comparaisons effectuées pour une recherche
    static double averageComparaison;

public:
    SearchingAlgorithm(); //constructeur

    // Recherche un élément dans le vecteur
    // Retourne l'indice de l'élément s'il est trouvé, sinon -1
    virtual int search(const std::vector<int>& vector, int element) = 0;

    // Affiche les résultats d'une recherche
    void displaySearchResults(std::ostream& os, int results, int target);
};