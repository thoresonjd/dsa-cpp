#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstddef>

/**
 * @brief A generic linked list class.
 * @tparam ListT The type of data to store in the linked list.
 */
template<typename ListT>
class LinkedList {
private:

	/**
	 * @brief A generic linked list node structure.
	 * @tparam NodeT The type of data to store in the node.
	 */
	template<typename NodeT>
	struct ListNode {

		/**
		 * @brief The data contained by the list node.
		 */
		NodeT value;

		/**
		 * @brief Points to the next list node.
		 */
		ListNode* next;
	};

	/**
	 * @brief Points to the first node in the linked list.
	 */
	ListNode<ListT>* head;

	/**
	 * @brief The number of nodes in the linked list.
	 */
	std::size_t size;


public:

	/**
	 * @brief Construct a new Linked List object.
	 */
	LinkedList();
	
	/**
	 * @brief Destroy the Linked List object.
	 */
	~LinkedList();

	LinkedList(const LinkedList& other) = delete;
	LinkedList(LinkedList&& other) = delete;
	LinkedList& operator=(const LinkedList& other) = delete;
	LinkedList& operator=(LinkedList& other) = delete;

	/**
	 * @brief Inserts data to the front of the linked list.
	 * @param value The data to insert.
	 */
	void insertFront(const ListT value) noexcept;

	/**
	 * @brief Inserts data to the end of the linked list.
	 * @param value The data to insert.
	 */
	void insertEnd(const ListT value) noexcept;

	/**
	 * @brief Inserts data into the linked list at a given index. 
	 * @param index The index in which to insert data to.
	 * @param value The data to insert.
	 * @throw std::out_of_range The index is invalid.
	 */
	void insertAt(const std::size_t& index, const ListT value);

	/**
	 * @brief Removes the first node of the linked list.
	 * @return ListT The data removed from the front of the linked list.
	 * @throw std::out_of_range The linked list is empty.
	 */
	ListT removeFront();

	/**
	 * @brief Removes the last node of the linked list.
	 * @return ListT The data removed from the end of the linked list.
	 * @throw std::out_of_range The linked list is empty.
	 */
	ListT removeEnd();

	/**
	 * @brief Removes data from a given index in the linked list.
	 * @param index The index in which to remove data from.
	 * @return ListT The data removed from the given index of the linked list.
	 * @throw std::out_of_range The index is invalid.
	 */
	ListT removeAt(const std::size_t& index);

	/**
	 * @brief Removes all data from the linked list.
	 */
	void clear() noexcept;

	/**
	 * @brief Gets the size of the linked list.
	 * @return std::size_t The number of nodes in the list.
	 */
	std::size_t getSize() const noexcept;	

	/**
	 * @brief Determines if the linked list is empty.
	 * @return true 
	 * @return false 
	 */
	bool isEmpty() const noexcept;
};

#include <linked-list.tpp>
#endif
