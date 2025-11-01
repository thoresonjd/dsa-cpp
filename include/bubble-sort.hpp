/**
 * @file bubble-sort.hpp
 * @brief Bubble sort algorithm.
 * @author Justin Thoreson
 */

#pragma once
#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

/**
 * @brief Sorts an array via the bubble sort algorithm.
 * @param[in,out] array An array to sort.
 * @param[in] size The number of elements in the array.
 */
template<typename T>
void bubbleSort(T array[], const std::size_t& size);

#include <bubble-sort.tpp>
#endif // BUBBLE_SORT_HPP
