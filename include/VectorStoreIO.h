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

        int32_t dimension;
        int current_id = 0;

        // find dim using 4 bytes
        while (file.read(reinterpret_cast<char*>(&dimension), sizeof(dimension))) {
            
            // create new record
            VectorRecord<T> record;
            record.id = current_id;
            
            // create space in the vector
            record.vector.resize(dimension);

            // read the numbers into the vector
            size_t bytes_to_read = dimension * sizeof(T);
            file.read(reinterpret_cast<char*>(record.vector.data()), bytes_to_read);

            // add the record to master list
            dataset.push_back(record);
            
            // increment
            current_id++; 
        }

        file.close();
        return dataset;
    }
};