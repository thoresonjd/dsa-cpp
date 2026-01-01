/**
 * @file selection-sort.tpp
 * @brief Selection sort algorithm.
 * @author Justin Thoreson
 */

#include <selection-sort.hpp>

template<typename T>
void selectionSort(T array[], const std::size_t& size) noexcept {
	for (std::size_t i = 0; i < size - 1; i++) {
		std::size_t min = i;
		for (std::size_t j = i + 1; j < size; j++) {
			if (array[j] < array[min])
				min = j;
		}
		if (i != min) {
			T temp = array[i];
			array[i] = array[min];
			array[min] = temp;
		}
	}
}

