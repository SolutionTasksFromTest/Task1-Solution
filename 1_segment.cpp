#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

int64_t find_min_transversal(const std::vector<std::pair<int64_t, int64_t>>& segments) {
    if (segments.empty()) {
        return 0;
    }

    std::vector<std::pair<int64_t, int64_t>> min_transversal;
    min_transversal.push_back(segments[0]);

    for(auto const &seg: segments) {
        if (seg.first > min_transversal.back().second) {
            min_transversal.push_back(seg);
        }
    }

    return min_transversal.size();
}

int main() {
    size_t number_of_segments = 0;
    std::cin >> number_of_segments;

    std::vector<std::pair<int64_t, int64_t>> segments(number_of_segments);
    for (auto &seg : segments) {
        std::cin >> seg.first >> seg.second;
    }

    std::sort(segments.begin(), segments.end(), [](const auto &a, const auto &b) {
        return a.second < b.second;
    });

    size_t min_transversal_size = find_min_transversal(segments);
    std::cout << min_transversal_size << std::endl;

    return 0;
}