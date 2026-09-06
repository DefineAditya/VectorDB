#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include "VectorRecord.h"
class VectorStoreIO {
public:
    template <typename T>
    static std::vector<VectorRecord<T>> load_data(const std::string& file_path) {
        std::vector<VectorRecord<T>> dataset;

        // open the file in binary
        std::ifstream file(file_path, std::ios::binary);

        // check for error in opening file
        if (!file.is_open()) {
            throw std::runtime_error("Error: Could not open the file at " + file_path);
        }

        
    }
};