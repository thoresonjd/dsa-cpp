/**
 * @file stack.tpp
 * @brief A stack.
 * @author Justin Thoreson
 */

#include <stack.h>
#include <stdexcept>

template<typename StackT>
Stack<StackT>::~Stack() {
    clear();
}

template<typename StackT>
void Stack<StackT>::push(const StackT value) {
    if (size == MAX_SIZE)
        throw std::length_error("Maximum size has been reached");
    StackNode<StackT>* node = new StackNode<StackT>;
    node->value = value;
    node->next = top;
    top = node;
    size++;
}

template<typename StackT>
void Stack<StackT>::pop() {
    if (isEmpty())
        throw std::out_of_range("Stack is empty");
    StackNode<StackT>* next = top->next;
    delete top;
    top = next;
    size--;
}

template<typename StackT>
void Stack<StackT>::clear() noexcept {
    while (!isEmpty()) {
        StackNode<StackT>* next = top->next;
        delete top;
        top = next;
    }
    size = 0;
}

template<typename StackT>
StackT Stack<StackT>::peek() const {
    if (isEmpty())
		throw std::out_of_range("Stack is empty");
	return top->value;
}

template<typename StackT>
Stack<StackT>::StackSizeT Stack<StackT>::getSize() const noexcept {
    return size;
}

template<typename StackT>
bool Stack<StackT>::isEmpty() const noexcept {
    return !top;
}
