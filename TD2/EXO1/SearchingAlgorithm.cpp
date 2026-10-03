#include "SearchingAlgorithm.h"

int SearchingAlgorithm::totalComparaisons = 0;
int SearchingAlgorithm::totalSearch = 0;
double SearchingAlgorithm::averageComparaison = 0.0;

SearchingAlgorithm::SearchingAlgorithm()
{
    numberComparaisons = 0;
}


void SearchingAlgorithm::displaySearchResults(std::ostream& os, int result, int target)
{
    // Ajt le nombre de comparaisons ici au total
    totalComparaisons += numberComparaisons;
    totalSearch++; //+1

    // Calcule moyenne des comparaisons
    averageComparaison = (double)totalComparaisons / totalSearch;

    os << "On recherche le nombre :  " << target << std::endl;

    if (result != -1){ os << "Element trouve a l'indice : " << result << std::endl; }
    else{ os << "Element non trouve." << std::endl; }

    os << "Nombre de comparaisons : "
       << numberComparaisons << std::endl;

    os << "Nombre total de comparaisons : "
       << totalComparaisons << std::endl;

    os << "Nombre total de recherches : "
       << totalSearch << std::endl;

    os << "Moyenne des comparaisons : "
       << averageComparaison << std::endl;
}