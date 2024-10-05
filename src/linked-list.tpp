#include <linked-list.h>
#include <stdexcept>

template<typename ListT>
LinkedList<ListT>::LinkedList(): head(nullptr), size(0) {}

template<typename ListT>
LinkedList<ListT>::~LinkedList() {
	clear();
}

template<typename ListT>
void LinkedList<ListT>::insertFront(const ListT value) noexcept {
	ListNode<ListT>* node = new ListNode<ListT>;
	node->value = value;
	node->next = head;
	head = node;
	size++;
}

template<typename ListT>
void LinkedList<ListT>::insertEnd(const ListT value) noexcept {
	ListNode<ListT>* node = new ListNode<ListT>;
	node->value = value;
	node->next = nullptr;
	if (isEmpty()) {
		head = node;
		size++;
		return;
	}
	ListNode<ListT>* current = head;
	while (current->next)
		current = current->next;
	current->next = node;
	size++;
}

template<typename ListT>
void LinkedList<ListT>::insertAt(const std::size_t& index, const ListT value) {
	if (index > size)
		throw std::out_of_range("Index out of range");
	if (index == 0) {
		insertFront(value);
		return;
	} 
	if (index == size) {
		insertEnd(value);
		return;	
	}
	ListNode<ListT>* current = head;
	for (std::size_t i = 0; i < index - 1; i++)
		current = current->next;
	ListNode<ListT>* node = new ListNode<ListT>;
	node->value = value;
	node->next = nullptr;
	ListNode<ListT>* next = current->next;
	current->next = node;
	node->next = next;
	size++;
}

template<typename ListT>
ListT LinkedList<ListT>::removeFront() {
	if (isEmpty())
		throw std::out_of_range("List is empty");
	ListNode<ListT>* next = head->next;
	ListT value = head->value;
	delete head;
	head = next;
	size--;
	return value;
}

template<typename ListT>
ListT LinkedList<ListT>::removeEnd() {
	if (isEmpty())
		throw std::out_of_range("List is empty");
	ListT value;
	if (!head->next) {
		value = head->value;
		delete head;
		head = nullptr;
		size--;
		return value;	
	}
	ListNode<ListT>* current = head;
	while (current->next->next)
		current = current->next;
	ListNode<ListT>* next = current->next;
	value = next->value;
	delete next;
	current->next = nullptr;
	size--;
	return value;
}

template<typename ListT>
ListT LinkedList<ListT>::removeAt(const std::size_t& index) {
	if (index >= size)
		throw std::out_of_range("Index out of range");
	if (index == 0)
		return removeFront();	
	if (index == size - 1)
		return removeEnd();
	ListNode<ListT>* current = head;
	for (std::size_t i = 0; i < index - 1; i++)
		current = current->next;
	ListNode<ListT>* next = current->next;
	ListT value = next->value;
	current->next = next->next;
	next->next = nullptr;
	delete next;
	size--;
	return value;
}

template<typename ListT>
std::size_t LinkedList<ListT>::getSize() const noexcept {
	return size;
}

template<typename ListT>
bool LinkedList<ListT>::isEmpty() const noexcept {
	return !head;
}

template<typename ListT>
void LinkedList<ListT>::clear() noexcept {
	while (head) {
		ListNode<ListT>* next = head->next;
		head->next = nullptr;
		delete head;
		head = next;		
	}
	size = 0;
}
