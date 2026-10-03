#pragma once

#include "SearchingAlgorithm.h"

class LinearSearch : public SearchingAlgorithm { //la class LinearSearch
public:
    int search(const std::vector<int>& vector, int element) override;
};