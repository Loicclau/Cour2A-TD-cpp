#include <iostream>
#include <vector>

#include "LinearSearch.h"
#include "JumpSearch.h"
#include "BinarySearch.h"

int main()
{
    // Vecteur trié pour les algos
    std::vector<int> vector = {
        1, 3, 5, 7, 9, 12, 15, 18, 21, 25,
        30, 35, 40, 45, 50, 55, 60, 65, 70, 75
    };

    int target = 45; // le nombre a chercher

    // les 3 algorithmes
    LinearSearch linearSearch;
    JumpSearch jumpSearch;
    BinarySearch binarySearch;
    // Linear Search
    int result = linearSearch.search(vector, target);
    std::cout << "\nLINEAR SEARCH" << std::endl;
    linearSearch.displaySearchResults(std::cout, result, target);

    // Jump Search
    result = jumpSearch.search(vector, target);
    std::cout << "\nJUMP SEARCH" << std::endl;
    jumpSearch.displaySearchResults(std::cout, result, target);

    // Binary Search
    result = binarySearch.search(vector, target);
    std::cout << "\nBINARY SEARCH" << std::endl;
    binarySearch.displaySearchResults(std::cout, result, target);

    return 0;
}