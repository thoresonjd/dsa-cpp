#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstddef>

template<typename ListT>
class LinkedList {
private:
	template<typename NodeT>
	struct ListNode {
		NodeT value;
		ListNode* next;
	};

	ListNode<ListT>* head;
	std::size_t size;

	void clear() noexcept;

public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList& other) = delete;
	LinkedList(LinkedList&& other) = delete;
	LinkedList& operator=(const LinkedList& other) = delete;
	LinkedList& operator=(LinkedList& other) = delete;
	void insertFront(const ListT value) noexcept;
	void insertEnd(const ListT value) noexcept;
	void insertAt(const std::size_t& index, const ListT value);
	ListT removeFront();
	ListT removeEnd();
	ListT removeAt(const std::size_t& index);
	std::size_t getSize() const noexcept;	
	bool isEmpty() const noexcept;
};

#include <linked-list.tpp>
#endif

