/**
 * @file bubble-sort.tpp
 * @brief Bubble sort algorithm.
 * @author Justin Thoreson
 */

#include <bubble-sort.hpp>

namespace dsa {

template<typename T>
void bubbleSort(T array[], const std::size_t& size) noexcept {
	for (std::size_t i = 0; i < size - 1; i++) {
		for (std::size_t j = 0; j < size - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				T temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

} // dsa
