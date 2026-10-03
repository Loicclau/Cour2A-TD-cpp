#include "LinearSearch.h"

int LinearSearch::search(const std::vector<int>& vector, int element)
{
    //ca Réinitialise le compteur
    numberComparaisons = 0;

    for (int i = 0; i < vector.size(); i++) //recher dans tout le vecteur
    { numberComparaisons++;

        if (vector[i] == element)
        {
            return i;
        }
    }
    // Élément non trouvé
    return -1;
}