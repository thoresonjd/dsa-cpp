/**
 * @file binary-search-tree.hpp
 * @brief A binary search tree (BST).
 * @author Justin Thoreson
 */

#pragma once
#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <string>
#include <sstream>

/**
 * @brief A generic binary search tree (BST) class.
 * @tparam TreeT The type of data to store in the BST
 */
template<typename TreeT>
class BinarySearchTree {
public:

	/**
	 * @brief Variable type to track size.
	 */
	using TreeSizeT = int;

private:

	/**
	 * @brief A generic binary tree node structure.
	 * @tparam NodeT The type of data to store in the node.
	 */
	template<typename NodeT>
	struct TreeNode {

		/**
		 * @brief The data contained by the tree node.
		 */
		NodeT value;

		/**
		 * @brief Points to the left child node.
		 */
		TreeNode* left = nullptr;

		/** 
		 * @brief Points to the right child node.
		 */
		TreeNode* right = nullptr;

		/**
		 * @brief Initializes a new tree node.
		 * @param value The value to store in the tree node.
		 */
		explicit TreeNode(const NodeT& value);

		/**
		 * @brief Initializes a new tree node.
		 * @param value The value to store in the tree node.
		 * @param left The address of the left child node.
		 * @param right The address of the right child node.
		 */
		TreeNode(const NodeT& value, const TreeNode<NodeT>* left, const TreeNode<NodeT>* right);
	};

	/**
	 * @brief The maximum number of nodes allowed in the BST.
	 */
	static constexpr TreeSizeT MAX_SIZE = 100;

	/**
	 * @brief The number of nodes in the BST.
	 */
	TreeSizeT size = 0;

	/**
	 * @prief Points to the root node of the BST.
	 */
	TreeNode<TreeT>* root = nullptr;

	/**
	 * @brief Helper that inserts a value into the BST if it does not exist.
	 * @param node The node to insert the new value under.
	 * @param value The value to insert.
	 * @return TreeNode<TreeT>* Address of the given node, or the newly created node.
     * @throw std::length_error The maximum size has been reached.
	 */
	[[nodiscard]] TreeNode<TreeT>* insert(TreeNode<TreeT>* node, const TreeT& value);

	/**
	 * @brief Helper that removes a value from the BST if it exists, resulting in rearranging the nodes in the tree.
	 * @param node The node to check under for removal.
	 * @param value The value to remove.
	 * @return TreeNode<TreeT>* Address of a node.
	 */
	[[nodiscard]] TreeNode<TreeT>* remove(TreeNode<TreeT>* node, const TreeT& value) noexcept;

	/**
	 * @brief Finds the immediate in-order successor of a node within BST.
	 * @param node The node to find the successor of.
	 * @return TreeNode<TreeT>* Address of the successor of the node.
	 */
	TreeNode<TreeT>* getInorderSuccessor(const TreeNode<TreeT>* node) const noexcept;

	/**
	 * @brief Helper to empty the BST.
	 * @node A node to delete under.
	 */
	void clear(TreeNode<TreeT>* node) noexcept;
	
	/**
	 * @brief Conducts a binary search of a BST for a give value.
	 * @param node A BST node.
	 * @param value The value to search for.
	 * @return true
	 * @return false
	 */
	static bool binarySearch(const TreeNode<TreeT>* node, const TreeT& value) noexcept;

	/**
	 * @brief Checks if a stringstrem object has nothing to read from it.
	 * @param out A stringstream object.
	 * @return true
	 * @return false
	 */
	static bool isStreamEmpty(const std::stringstream& out) noexcept;

	/**
	 * @brief Inserts a value into a stringstream object.
	 * @param out A stringstream object.
	 * @param value The value to insert.	 
	 */
	static void writeValueToStream(std::stringstream& out, const TreeT& value) noexcept;

	/**
	 * @brief Helper that creates a string representation of an in-order traversal through a BST.
	 * @param out A stringstream object.
	 * @param node The currently accessed node in the traversal. 
     */	 
	static void toStringInorder(std::stringstream& out, const TreeNode<TreeT>* node) noexcept;
	
    /**
	 * @brief Helper that creates a string representation of an pre-order traversal through a BST.
	 * @param out A stringstream object.
	 * @param node The currently accessed node in the traversal. 
     */	 
	static void toStringPreorder(std::stringstream& out, const TreeNode<TreeT>* node) noexcept;
	
    /**
	 * @brief Helper that creates a string representation of an post-order traversal through a BST.
	 * @param out A stringstream object.
	 * @param node The currently accessed node in the traversal. 
     */	 
	static void toStringPostorder(std::stringstream& out, const TreeNode<TreeT>* node) noexcept;

public:

	/**
	 * @brief Constructs a new BinarySearchTree object.
	 */
	BinarySearchTree() = default;

	/**
	 * @brief Destroys the BinarySearchTree object.
	 */
	~BinarySearchTree();
	
	BinarySearchTree(const BinarySearchTree& other) = delete;
	BinarySearchTree(BinarySearchTree&& other) = delete;
	BinarySearchTree& operator=(const BinarySearchTree& other) = delete;
	BinarySearchTree& operator=(BinarySearchTree&& other) = delete;
	
	/**
	 * @brief Inserts a value into the BST if it does not exist.
	 * @param value The value to insert.
	 */
	void insert(const TreeT& value);
	
	/**
	 * @brief Removes a value from the BST if it exists.
	 * @param value The value to remove.
	 */
	void remove(const TreeT& value) noexcept;

	/**
	 * @brief Empties the BST.
	 */
	void clear() noexcept;

	/**
	 * @brief Checks if the BST is empty.
	 * @return true
	 * @return false 
	 */
	bool isEmpty() const noexcept;

	/**
	 * @brief Checks if a value is present within the BST.
	 * @param The value to check for within the BST
	 * @return true
	 * @return false	 
	 */
	bool isPresent(const TreeT& value) const noexcept;

	/**
	 * @brief Retrieves the size of the BST.
	 * @return ListSizeT The number of nodes in the BST.
	 */
	TreeSizeT getSize() const noexcept;

	/**
	 * @brief Creates the string representation of an in-order traversal through the BST.
	 * @return std::string The string representation of the BST in-order.
	 */	
	std::string toStringInorder() const noexcept;
	
	/**
	 * @brief Creates the string representation of an pre-order traversal through the BST.
	 * @return std::string The string representation of the BST pre-order.
	 */	
	std::string toStringPreorder() const noexcept;
	
	/**
	 * @brief Creates the string representation of an post-order traversal through the BST.
	 * @return std::string The string representation of the BST post-order.
	 */	
	std::string toStringPostorder() const noexcept;
};

#include <binary-search-tree.tpp>
#endif // BINARY_SEARCH_TREE_HPP
