#include "../include/FlatSearch.h"
#include <queue>
#include <algorithm>
#include <stdexcept>

// --- PART 1: Distance Calculation ---
float squared_l2_distance(const std::vector<float>& a, const std::vector<float>& b) {
    if (a.size() != b.size()) {
        throw std::invalid_argument("Vectors must be the exact same size to compare.");
    }
    float dist = 0.0f;
    for (size_t i = 0; i < a.size(); ++i) {
        float diff = a[i] - b[i];
        dist += diff * diff; 
    }
    return dist;
}

// --- PART 2: Search ---
std::vector<int> flat_search(const std::vector<float>& query, 
                             const std::vector<VectorRecord<float>>& base_dataset, 
                             int k) {
    
    // A queue that holds pairs of (Distance, ID)
    std::priority_queue<std::pair<float, int>> pq;

    for (const auto& base_vec : base_dataset) {
        float dist = squared_l2_distance(query, base_vec.vector);

        if (pq.size() < k) {
            pq.push({dist, base_vec.id});
        } else if (dist < pq.top().first) {
            pq.pop();
            pq.push({dist, base_vec.id});
        }
    }

    // Extract the final IDs from the queue
    std::vector<int> results;
    while (!pq.empty()) {
        results.push_back(pq.top().second);
        pq.pop();
    }

    // The queue gives us the worst match first, so we reverse it to get best-first
    std::reverse(results.begin(), results.end());
    
    return results;
}