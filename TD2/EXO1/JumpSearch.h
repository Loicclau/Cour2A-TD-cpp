#pragma once

#include "SearchingAlgorithm.h"

class JumpSearch : public SearchingAlgorithm {
public:
    int search(const std::vector<int>& vector, int element) override;
};