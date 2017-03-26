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
		int iPivot =  static_cast<int>(floor((right - left) / 2));
		int pivot = v[right];
		
		int l = left - 1;
		if (l < 0) l = 0;
		
		int r = right + 1;
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

	static void quick_sort(std::vector<int>& v, int left, int right) {
		if (left < right) {
			int p = quick_sort_partition(v, left, right);			
			quick_sort(v, left, p - 1);
			quick_sort(v, p + 1, right);
		}
	}

}