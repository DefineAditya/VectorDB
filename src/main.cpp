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

    // set up test
    int query_index = 0; // test just the first query
    int k = 100;         // finding top 100 closest matches

    std::cout << "Running brute-force search for query 0..." << std::endl;
    
    // run search function
    std::vector<int> my_results = flat_search(query_data[query_index].vector, base_data, k);

    // print the top 5 results to see if they match
    std::cout << "\n--- Top 5 Matches ---" << std::endl;
    for (int i = 0; i < 5; ++i) {
        std::cout << "My Database found ID: " << my_results[i] 
                  << " | The Answer Key says: " << ground_truth[query_index].vector[i] << std::endl;
    }

    // calculate Recall@100
    int correct_matches = 0;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            // if our result exists in top 100, it counts as yes
            if (my_results[i] == ground_truth[query_index].vector[j]) {
                correct_matches++;
                break;
            }
        }
    }
    
    float recall = (correct_matches / (float)k) * 100.0f;
    std::cout << "\nFinal Grade (Recall@100): " << recall << "%" << std::endl;

    return 0;
}