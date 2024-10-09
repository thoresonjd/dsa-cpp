/**
 * @file queue.h
 * @brief A queue.
 * @author Justin Thoreson
 */

#pragma once
#ifndef QUEUE_H
#define QUEUE_H

/**
 * @brief A generic queue class.
 * @tparam QueueT The type of data to store in the queue.
 */
template<typename QueueT>
class Queue {
public:

    /**
     * @brief Variable type to track the size.
     */
	using QueueSizeT = int;

private:
	
    /**
     * @brief A generic queue node structure.
     * @tparam NodeT The type of data to store in the node.
     */
	template<typename NodeT>
	struct QueueNode {

        /**
         * @brief The data contained by the queue node.
         */
		NodeT value;

        /**
         * @brief Points to the next queue node.
         */
		QueueNode* next = nullptr;
	};

    /**
     * @brief The maximum number of nodes allowed in the queue.
     */
	static constexpr QueueSizeT MAX_SIZE = 100;

    /**
     * @brief The number of nodes in the queue.
     */
	QueueSizeT size = 0;
	
    /**
     * @brief Points to the node at the front of the queue.
     */
    QueueNode<QueueT>* front = nullptr;
	
    /**
     * @brief Points to the node at the back of the queue.
     */
    QueueNode<QueueT>* rear = nullptr;

public:
	
    /**
     * @brief Constructs a new Queue object.
     */
	Queue() = default;

    /**
     * @brief Destroys the Queue object.
     */
	~Queue();

	Queue(const Queue& other) = delete;
	Queue(Queue&& other) = delete;
	Queue& operator=(const Queue& other) = delete;
	Queue& operator=(Queue&& other) = delete;

    /**
     * @brief Places data into the back of the queue.
     * @param value The data to enqueue.
     * @throw std::length_error The maximum size has been reached.
     */
	void enqueue(const QueueT value);

    /**
     * @brief Removes data from the front of the queue.
     * @throw std::out_of_range The queue is empty.
     */
	void dequeue();

    /**
     * @brief Removes all data from the queue.
     */
	void clear() noexcept;

    /**
     * @brief Gets the data at the front of the queue.
     * @return QueueT The data at the front of the queue.
     * @throw std::out_of_range The queue is empty.
     */
	QueueT peek() const;

    /**
     * @brief Gets the size of the queue.
     * @return QueueSizeT The number of nodes in the queue.
     */
	QueueSizeT getSize() const noexcept;

    /**
     * @brief Determines if the queue is empty.
     * @return true
     * @return false
     */
	bool isEmpty() const noexcept;

};

#include <queue.tpp>
#endif // QUEUE_H
