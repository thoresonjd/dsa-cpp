/**
 * @file insertion-sort.tpp
 * @brief Insertion sort algorithm.
 * @author Justin Thoreson
 */

#include <insertion-sort.hpp>

template<typename T>
void insertionSort(T array[], const std::size_t& size) noexcept {
	for (std::size_t i = 1; i < size; i++) {
		T key = array[i];
		std::size_t j = i;
		while (j > 0 && array[j - 1] > key) {
			array[j] = array[j - 1];
			j--;
		}
		array[j] = key;
	}	
}

