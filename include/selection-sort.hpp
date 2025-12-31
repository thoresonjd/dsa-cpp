/**
 * @file selection-sort.hpp
 * @brief Selection sort algorithm.
 * @author Justin Thoreson
 */

#pragma once
#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

/**
 * @brief Sorts an array via the selection sort algorithm.
 * @param[in,out] array An array to sort.
 * @param[in] size The number of elements in the array.
 */
template<typename T>
void selectionSort(T array[], const std::size_t& size);

#include <selection-sort.tpp>
#endif // SELECTION_SORT_HPP
