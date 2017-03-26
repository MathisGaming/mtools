#pragma once

#include <vector>
#include <iostream>

namespace mtools {

	// Sorting Algorithms

	static void buble_sort(std::vector<int>& v) {
		for (unsigned int i = 0; i < v.size();++i) {
			for (unsigned int j = 0; j < v.size()-1; ++j) {
				if (v[j] > v[j+1]) {
					int tmp = v[j+1];
					v[j+1] = v[j];
					v[j] = tmp;
				}
			}
		}
	}

	static void merge_sort(std::vector<int>& v) {

	}

	static int quick_sort_partition(std::vector<int>& v, int left, int right) {

	}

	static void quick_sort(std::vector<int>& v, int left, int right) {

	}

}