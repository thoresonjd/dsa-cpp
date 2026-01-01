/**
 * @file circular-queue.hpp
 * @brief A cricular queue, a.k.a., ring buffer.
 * @author Justin Thoreson
 */

#pragma once
#ifndef CIRCULAR_QUEUE_HPP
#define CIRCULAR_QUEUE_HPP

namespace dsa {

/**
 * @brief A generic circular queue class.
 * @tparam QueueT The type of data to store in the circular queue.
 */
template<typename QueueT>
class CircularQueue {
public:

	/**
     * @brief Variable type to track the size.
     */
	using QueueSizeT = int;

	/**
	 * @brief The minimum allowed capacity of the circular queue.
	 */
	static constexpr QueueSizeT MIN_CAPACITY = 1;

	/**
     * @brief The maximum allowed capacity of the circular queue.
     */
	static constexpr QueueSizeT MAX_CAPACITY = 100;

private:

	/**
	 * @brief Points to the underlying array of data in the circular queue.
	 */
	QueueT* data = nullptr;

	/**
	 * @brief The index of the front of the circular queue. 
	 */
	QueueSizeT front = 0;
	
	/**
	 * @brief The index of the end of the circular queue.
	 */
	QueueSizeT end = 0;
	
	/**
	 * @brief The capacity of the circular queue.
	 */
	QueueSizeT capacity = 0;
	
	/**
	 * @brief The number of elements in the circular queue.
	 */
	QueueSizeT size = 0;

public:

	/**
	 * @brief Constructs a new CircularQueue object.
	 * @param capacity The capacity of the circular queue.
	 * @throw std::invalid_argument The provided capacity is greater than the maximum allowed capacity.
	 */
	explicit CircularQueue(const QueueSizeT& capacity);
	
	/**
	 * @brief Destroys the CircularQueue object.
	 */
	~CircularQueue();

	CircularQueue(const CircularQueue& other) = delete;
	CircularQueue(CircularQueue&& other) = delete;
	CircularQueue& operator=(const CircularQueue& other) = delete;
	CircularQueue& operator=(CircularQueue&& other) = delete;

	/**
	 * @brief Places data into the end of the circular queue.
	 * @param value The data to enqueue.
	 * @throw std::length_error The capacity has been reached.
	 */
	void enqueue(const QueueT& value);
	
	/**
	 * @brief Removes data from the front of the circular queue.
	 * @throw std::out_of_range The circular queue is empty.
	 */
	void dequeue();

	/**
	 * @brief Gets the data at the front of the circular queue.
	 * @return QueueT The data at the front of the circular queue.
	 * @throw std::out_of_range The circular queue is empty.
	 */
	QueueT peek() const;

	/**
	 * @brief Gets the size of the circular queue.
	 * @return QueueSizeT The number of elements in the circular queue.
	 */
    QueueSizeT getSize() const noexcept;

	/**
	 * @brief Determines if the circular queue is empty.
	 * @return true
	 * @return false
	 */
	bool isEmpty() const noexcept;
	
	/**
	 * @brief Determines if the circular queue is full.
	 * @return true
	 * @return false
	 */
	bool isFull() const noexcept;
};

} // dsa

#include <circular-queue.tpp>
#endif // CIRCULAR_QUEUE_HPP
