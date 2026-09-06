#include <iostream>
#include <vector>

#include "../include/VectorRecord.h"
#include "../include/VectorStoreIO.h"
#include "../include/FlatSearch.h" 

int main() {
    std::cout << "Loading dataset... Please wait." << std::endl;

    // load SIFT files
    // make sure these files are in folder 'data'
    auto base_data = VectorStoreIO::load_data<float>("data/siftsmall_base.fvecs");
    auto query_data = VectorStoreIO::load_data<float>("data/siftsmall_query.fvecs");
    auto ground_truth = VectorStoreIO::load_data<int>("data/siftsmall_groundtruth.ivecs");

    std::cout << "Loaded " << base_data.size() << " base vectors." << std::endl;
    std::cout << "Loaded " << query_data.size() << " query vectors." << std::endl;

    

    return 0;
}