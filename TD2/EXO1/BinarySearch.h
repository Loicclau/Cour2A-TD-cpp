#pragma once

#include "SearchingAlgorithm.h"

class BinarySearch : public SearchingAlgorithm {
public:
    int search(const std::vector<int>& vector, int element) override;
};