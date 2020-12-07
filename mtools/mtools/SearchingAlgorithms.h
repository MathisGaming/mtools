#pragma once

#include <vector>

namespace mtools {
    
    template <class T>
    static bool binary_search(const std::vector<T>& v, size_t min, size_t max, const T& x) {
        if (max < min) { return false; }
        size_t mid = min + ((max-min) / 2);
        if (v[mid] == x) { return true; }
        return (x < v[mid] ? binary_search(v, min, mid - 1, x) : binary_search(v, mid + 1, max, x));
    }

    template <class T>
    static bool binary_search_iterative(const std::vector<T>& v, size_t min, size_t max, const T& x) {
        size_t mid = 0;
        while (max >= min) {
            mid = min + ((max - min) / 2);
            if (v[mid] == x) { return true; }
            if (x < v[mid]) {
                max = mid - 1;
            }
            else {
                min = mid + 1;
            }
        }
        return false;
    }
}