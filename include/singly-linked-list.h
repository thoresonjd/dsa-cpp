/**
 * @file singly-linked-list.h
 * @brief A singly linked list.
 * @author Justin Thoreson
 */

#pragma once
#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

/**
 * @brief A generic singly linked list class.
 * @tparam ListT The type of data to store in the linked list.
 */
template<typename ListT>
class SinglyLinkedList {
public:
    
    /**
     * @brief Variable type to track the size.
     */
    using ListSizeT = int;

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
		ListNode* next = nullptr;
	};

    /**
     * @brief The maximum number of nodes allowed in the linked list.
     */
    static constexpr ListSizeT MAX_SIZE = 100;

    /**
	 * @brief The number of nodes in the linked list.
	 */
	ListSizeT size = 0;

    /**
	 * @brief Points to the first node in the linked list.
	 */
	ListNode<ListT>* head = nullptr;

public:

	/**
	 * @brief Constructs a new SinglyLinkedList object.
	 */
	SinglyLinkedList() = default;
	
	/**
	 * @brief Destroys the SinglyLinkedList object.
	 */
	~SinglyLinkedList();

	SinglyLinkedList(const SinglyLinkedList& other) = delete;
	SinglyLinkedList(SinglyLinkedList&& other) = delete;
	SinglyLinkedList& operator=(const SinglyLinkedList& other) = delete;
	SinglyLinkedList& operator=(SinglyLinkedList&& other) = delete;

	/**
	 * @brief Inserts data to the front of the linked list.
	 * @param value The data to insert.
     * @throw std::length_error The maximum size has been reached.
	 */
	void insertFront(const ListT value);

	/**
	 * @brief Inserts data to the end of the linked list.
	 * @param value The data to insert.
     * @throw std::length_error The maximum size has been reached.
	 */
	void insertEnd(const ListT value);

	/**
	 * @brief Inserts data into the linked list at a given index. 
	 * @param index The index in which to insert data to.
	 * @param value The data to insert.
     * @throw std::length_error The maximum size has been reached.
	 * @throw std::out_of_range The index is invalid.
	 */
	void insertAt(const ListSizeT& index, const ListT value);

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
	ListT removeAt(const ListSizeT& index);

	/**
	 * @brief Removes all data from the linked list.
	 */
	void clear() noexcept;

	/**
	 * @brief Gets the size of the linked list.
	 * @return ListSizeT The number of nodes in the list.
	 */
	ListSizeT getSize() const noexcept;	

	/**
	 * @brief Determines if the linked list is empty.
	 * @return true 
	 * @return false 
	 */
	bool isEmpty() const noexcept;
};

#include <singly-linked-list.tpp>
#endif // SINGLY_LINKED_LIST_H
