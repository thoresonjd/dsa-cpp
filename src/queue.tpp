/**
 * @file queue.tpp
 * @brief A queue.
 * @author Justin Thoreson
 */

#include <queue.h>
#include <stdexcept>

template<typename QueueT>
Queue<QueueT>::~Queue() {
	clear();
}

template<typename QueueT>
void Queue<QueueT>::enqueue(const QueueT value) {
	if (size == MAX_SIZE)
		throw std::length_error("Maximum size has been reached");
	QueueNode<QueueT>* node = new QueueNode<QueueT>;
	node->value = value;
	node->next = nullptr;
    if (!isEmpty())
	    rear->next = node;
	rear = node;
	if (isEmpty())
		front = node;
	size++;
}

template<typename QueueT>
void Queue<QueueT>::dequeue() {
	if (isEmpty())
		throw std::out_of_range("Queue is empty");
	QueueNode<QueueT>* next = front->next;
	delete front;
	front = next;
	if (isEmpty())
		rear = nullptr;
	size--;
}

template<typename QueueT>
void Queue<QueueT>::clear() noexcept {
	rear = nullptr;
	while (!isEmpty()) {
		QueueNode<QueueT>* next = front->next;
		delete front;
		front = next;
	}
	size = 0;
	
}

template<typename QueueT>
QueueT Queue<QueueT>::peek() const {
	if (isEmpty())
		throw std::out_of_range("Queue is empty");
	return front->value;
}

template<typename QueueT>
Queue<QueueT>::QueueSizeT Queue<QueueT>::getSize() const noexcept {
	return size;
}

template<typename QueueT>
bool Queue<QueueT>::isEmpty() const noexcept {
	return !front;
}

