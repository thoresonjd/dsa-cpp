/**
 * @file insertion-sort.hpp
 * @brief Insertion sort algorithm.
 * @author Justin Thoreson
 */

#pragma once
#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

/**
 * @brief Sorts an array via the insertion sort algorithm.
 * @param[in,out] array An array to sort.
 * @param[in] size The number of elements in the array.
 */
template<typename T>
void insertionSort(T array[], const std::size_t& size) noexcept;

#include <insertion-sort.tpp>
#endif // INSERTION_SORT_HPP
