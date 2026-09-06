#pragma once

#include <vector>
#include "Metadata.h"

template <typename T>
struct VectorRecord {
    int id;
    std::vector<T> vector;
    Metadata metadata;

    // A helpful mini-function to quickly check the size of the vector
    size_t dimension() const {
        return vector.size();
    }
};