#include "BinarySearch.h"
// ici on cherche dans le vecteur triée le millieu soit plus petit ou plus grand
// on ilimine lautre partie du vecteur
int BinarySearch::search(const std::vector<int>& vector, int element)
{
    numberComparaisons = 0;     // Réinitialise le compteur 

    int left = 0;
    int right = vector.size() - 1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;

        // Une comparaison est effectuée
        numberComparaisons++;

        if (vector[middle] == element)
        { return middle; }

        if (vector[middle] < element)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    // Élément non trouvé
    return -1;
}