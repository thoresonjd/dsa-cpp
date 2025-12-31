/**
 * @file insertion-sort.cpp
 * @brief Tests for insertion sort.
 * @author Justin Thoreson
 */

#include <gtest/gtest.h>
#include <insertion-sort.hpp>

TEST(InsertionSort, SortNonDescendingSortedArray) {
	std::size_t arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::size_t size = sizeof(arr) / sizeof(arr[0]);
	insertionSort(arr, size);
	for (std::size_t i = 0; i < size; i++)
		ASSERT_EQ(arr[i], i);
}

TEST(InsertionSort, SortNonAscendingSortedArray) {
	int arr[] = {
		9, 9, 8, 8, 7, 7, 6, 6, 5, 5,
		4, 4, 3, 3, 2, 2, 1, 1, 0, 0
	};
	int expected[] = {
		0, 0, 1, 1, 2, 2, 3, 3, 4, 4,
		5, 5, 6, 6, 7, 7, 8, 8, 9, 9
	};
	const std::size_t size = sizeof(arr) / sizeof(arr[0]);
	insertionSort(arr, size);
	for (std::size_t i = 0; i < size; i++)
		ASSERT_EQ(arr[i], expected[i]);
}

TEST(InsertionSort, SortUnsortedArray) {
	std::size_t arr[] = { 9, 0, 7, 6, 3, 5, 4, 1, 8, 2 };
	const std::size_t size = sizeof(arr) / sizeof(arr[0]);
	insertionSort(arr, size);
	for (std::size_t i = 0; i < size; i++)
		ASSERT_EQ(arr[i], i);
}

