/**
 * @file stack.h
 * @brief A stack.
 * @author Justin Thoreson
 */

#pragma once
#ifndef STACK_H
#define STACK_H

/**
 * @brief A generic stack class.
 * @tparam StackT The type of data to store in the stack.
 */
template<typename StackT>
class Stack {
public:

    /**
     * @brief Variable type to track the size.
     */
    using StackSizeT = int;

private:

    /**
     * @brief A generic stack node structure.
     * @tparam NodeT The type of data to store in the node.
     */
    template<typename NodeT>
    struct StackNode {

        /**
         * @brief The data contained by the stack node.
         */
        NodeT value;

        /**
         * @brief Points to the next stack node.
         */
        StackNode* next = nullptr;
    };

    /**
     * @brief The maximum number of nodes allowed in the stack.
     */
    static constexpr StackSizeT MAX_SIZE = 100;

    /**
     * @brief The number of nodes in the stack.
     */
    StackSizeT size = 0;

    /**
     * @brief Points to the node at the top of the stack.
     */
    StackNode<StackT>* top = nullptr;

public:

    /**
     * @brief Constructs a new Stack object.
     */
    Stack() = default;

    /**
     * @brief Destroys the Stack object.
     */
    ~Stack();

    Stack(const Stack& other) = delete;
    Stack(Stack&& other) = delete;
    Stack& operator=(const Stack& other) = delete;
    Stack& operator=(Stack&& other) = delete;

    /**
     * @brief Places data onto the top of the stack.
     * @param value The data to push.
     * @throw std::length_error The maximum size has been reached.
     */
    void push(const StackT value);

    /**
     * @brief Removes data from the top of the stack.
     * @throw std::out_of_range The stack is empty.
     */
    void pop();

    /**
     * @brief Removes all data from the stack.
     */
    void clear() noexcept;

    /**
     * @brief Gets the data at the top of the stack.
     * @return StackT The data at the top of the stack.
     * @throw std::out_of_range The Stack is empty.
     */
    StackT peek() const;

    /**
     * @brief Gets the size of the stack.
     * @return StackSizeT The number of nodes in the stack.
     */
    StackSizeT getSize() const noexcept;

    /**
     * @brief Determines if the stack is empty.
     * @return true
     * @return false
     */
    bool isEmpty() const noexcept;
};

#include <stack.tpp>
#endif // STACK_H
