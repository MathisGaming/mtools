#pragma once

#include <vector>
#include <iostream>

namespace mtools {

	// Sorting Algorithms

	template<class T>
	static void buble_sort(std::vector<T>& v) {
		for (size_t i = 0; i < v.size();++i) {
			for (size_t j = 0; j < v.size()-1; ++j) {
				if (v[j] > v[j+1]) {
					int tmp = v[j+1];
					v[j+1] = v[j];
					v[j] = tmp;
				}
			}
		}
	}

	template<typename T>
	static void heap_Sort(std::vector<T>&) {

	}

	template<typename T>
	static void merge_sort(std::vector<T>& v) {

	}

	template<typename T>
	static size_t quick_sort_partition(std::vector<T>& v, size_t left, size_t right) {
		int iPivot =  static_cast<int>(floor((right - left) / 2));
		int pivot = v[right];
		
		size_t l = left - 1;
		if (l < 0) l = 0;
		
		size_t r = right + 1;
		if (r >= v.size()) r = v.size() - 1;
		
		while (1) {
			while (v[l] < pivot) {
				l++;
			}
			while (v[r] > pivot) {
				r--;
			}

			if (l >= r) {
				break;
			}

			int tmp = v[l];
			v[l] = v[r];
			v[r] = tmp;
		}

		return r;
	}

	template<typename T>
	static void quick_sort(std::vector<T>& v, size_t left, size_t right) {
		if (left < right) {
			size_t p = quick_sort_partition(v, left, right);			
			quick_sort(v, left, p - 1);
			quick_sort(v, p + 1, right);
		}
	}

}