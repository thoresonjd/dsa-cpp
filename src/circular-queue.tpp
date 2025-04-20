/**
 * @file circular-queue.tpp
 * @brief A circular queue, a.k.a., ring buffer.
 * @author Justin Thoreson
 */

#include <circular-queue.hpp>
#include <exception>

template <typename QueueT>
CircularQueue<QueueT>::CircularQueue(const QueueSizeT& capacity) {
	if (capacity < MIN_CAPACITY)
		throw std::invalid_argument("Provided capacity less than minimum allowed capacity");
	if (capacity > MAX_CAPACITY)
		throw std::invalid_argument("Provided capacity exceeds maximum allowed capacity");
	this->capacity = capacity;
	data = new QueueT[capacity];
} 

template <typename QueueT>
CircularQueue<QueueT>::~CircularQueue() {
	delete[] data;
}

template <typename QueueT>
void CircularQueue<QueueT>::enqueue(const QueueT& value) {
	if (isFull())
		throw std::length_error("Capacity has been reached");
	if (!isEmpty())
		end = (end + 1) % capacity;
	data[end] = value;
	size++;
}

template <typename QueueT>
void CircularQueue<QueueT>::dequeue() {
    if (isEmpty())
		throw std::out_of_range("Circular queue is empty");
	front = (front + 1) % capacity;
	size--;
}

template <typename QueueT>
QueueT CircularQueue<QueueT>::peek() const {
	if (isEmpty())
		throw std::out_of_range("Circular queue is empty");
	return data[front];
}

template <typename QueueT>
CircularQueue<QueueT>::QueueSizeT CircularQueue<QueueT>::getSize() const noexcept {
	return size;
}

template <typename QueueT>
bool CircularQueue<QueueT>::isEmpty() const noexcept {
	return !size;
}

template <typename QueueT>
bool CircularQueue<QueueT>::isFull() const noexcept {
	return size == capacity;
}
