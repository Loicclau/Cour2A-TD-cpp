#include "JumpSearch.h"
#include <cmath>
#include <algorithm>

int JumpSearch::search(const std::vector<int>& vector, int element)
{
    // Réinitialise le compteur
    numberComparaisons = 0;

    int n = vector.size();  //n=taille du vecteur
    if (n == 0)
    { return -1; } //si pas de vecteur

    // Taille du saut
    int step = std::sqrt(n); //saut optimal
    int prev = 0;

    // Recherche du bloc
    while (prev < n)
    {
        numberComparaisons++;
        if (vector[std::min(step, n) - 1] >= element)
        {
            break;
        }
        prev = step;
        step += std::sqrt(n);

        if (prev >= n)
        {return -1;}
    }

    // Recherche linéaire dans le bloc
    while (prev < std::min(step, n))
    {
        numberComparaisons++;

        if (vector[prev] == element)
        {
            return prev;
        }

        if (vector[prev] > element)
        {
            return -1;
        }
        prev++;
    }
    return -1;
}