// FlatSearch.h

#pragma once

#include <vector>
#include "VectorRecord.h" 

// Flat Search function that performs a brute-force search for the k nearest neighbors of a query vector in a base dataset.
std::vector<int> flat_search(const std::vector<float>& query, 
                             const std::vector<VectorRecord<float>>& base_dataset, 
                             int k);