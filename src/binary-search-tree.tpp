/**
 * @file binary-search-tree.tpp
 * @brief A binary search tree (BST).
 * @author Justin Thoreson
 */

#include <binary-search-tree.hpp>

template<typename TreeT>
template<typename NodeT>
BinarySearchTree<TreeT>::TreeNode<NodeT>::TreeNode(const NodeT& value) noexcept
	: value(value), left(nullptr), right(nullptr) {}

template<typename TreeT>
template<typename NodeT>
BinarySearchTree<TreeT>::TreeNode<NodeT>::TreeNode(
	const NodeT& value,
	const TreeNode<NodeT>* left,
	const TreeNode<NodeT>* right) noexcept
	: value(value), left(left), right(right) {}

template<typename TreeT>
BinarySearchTree<TreeT>::~BinarySearchTree() {
	clear();
}

template<typename TreeT>
[[nodiscard]]
BinarySearchTree<TreeT>::TreeNode<TreeT>* BinarySearchTree<TreeT>::insert(TreeNode<TreeT>* node, const TreeT& value) {
	if (!node) {
		size++;
		return new TreeNode<TreeT>(value);
	}
	if (value < node->value)
		node->left = insert(node->left, value);
	else if (value > node->value)
		node->right = insert(node->right, value);
	return node;
}

template<typename TreeT>
void BinarySearchTree<TreeT>::insert(const TreeT& value) {
	if (size == MAX_SIZE)
		throw std::length_error("Maximum size has been reached");
	root = insert(root, value);
}

template<typename TreeT>
BinarySearchTree<TreeT>::TreeNode<TreeT>* BinarySearchTree<TreeT>::getInorderSuccessor(const TreeNode<TreeT>* node) const noexcept {
	TreeNode<TreeT>* successor = node->right;
	while (successor && successor->left)
		successor = successor->left;
	return successor;
}

template<typename TreeT>
[[nodiscard]]
BinarySearchTree<TreeT>::TreeNode<TreeT>* BinarySearchTree<TreeT>::remove(TreeNode<TreeT>* node, const TreeT& value) noexcept {
	if (!node)
		return nullptr;
	if (value < node->value) {
		node->left = remove(node->left, value);
	} else if (value > node->value) {
		node->right = remove(node->right, value);
	} else if (node->value == value) {
		size--;
		if (!node->left) {
			TreeNode<TreeT>* right = node->right;
			delete node;
			return right;
		} 
		if (!node->right) {
			TreeNode<TreeT>* left = node->left;
			delete node;
			return left;
		}
		TreeNode<TreeT>* successor = getInorderSuccessor(node);
		node->value = successor->value;
		node->right = remove(node->right, successor->value);
	}
	return node;
}

template<typename TreeT>
void BinarySearchTree<TreeT>::remove(const TreeT& value) noexcept {
	root = remove(root, value);
}

template<typename TreeT>
void BinarySearchTree<TreeT>::clear(TreeNode<TreeT>* node) noexcept {
	if (!node)
		return;
	clear(node->left);
	clear(node->right);
	delete node;
    node = nullptr;
    size--;
}

template<typename TreeT>
void BinarySearchTree<TreeT>::clear() noexcept {
	clear(root);
}

template<typename TreeT>
bool BinarySearchTree<TreeT>::isEmpty() const noexcept {
	return !root;
}

template<typename TreeT>
bool BinarySearchTree<TreeT>::binarySearch(const TreeNode<TreeT>* node, const TreeT& value) noexcept {
	if (!node)
		return false;
	if (value == node->value)
		return true;
	if (value < node->value)
		return binarySearch(node->left, value);
	return binarySearch(node->right, value);
}

template<typename TreeT>
bool BinarySearchTree<TreeT>::isPresent(const TreeT& value) const noexcept {
	return binarySearch(root, value);
}

template<typename TreeT>
BinarySearchTree<TreeT>::TreeSizeT BinarySearchTree<TreeT>::getSize() const noexcept {
	return size;
}

template<typename TreeT>
bool BinarySearchTree<TreeT>::isStreamEmpty(const std::stringstream& out) noexcept {
	return out.rdbuf()->in_avail() == 0;
}

template<typename TreeT>
void BinarySearchTree<TreeT>::writeValueToStream(std::stringstream& out, const TreeT& value) noexcept {
	if (!isStreamEmpty(out))
		out << ' ';
	out << value;
}

template<typename TreeT>
void BinarySearchTree<TreeT>::toStringInorder(std::stringstream& out, const TreeNode<TreeT>* node) noexcept {
	if (!node)
		return;
	toStringInorder(out, node->left);
	writeValueToStream(out, node->value);
	toStringInorder(out, node->right);
}

template<typename TreeT>
std::string BinarySearchTree<TreeT>::toStringInorder() const noexcept {
	std::stringstream ss;
	toStringInorder(ss, root);
	return ss.str();
}

template<typename TreeT>
void BinarySearchTree<TreeT>::toStringPreorder(std::stringstream& out, const TreeNode<TreeT>* node) noexcept {
	if (!node)
		return;
	writeValueToStream(out, node->value);
	toStringPreorder(out, node->left);
	toStringPreorder(out, node->right);
}	

template<typename TreeT>
std::string BinarySearchTree<TreeT>::toStringPreorder() const noexcept {
	std::stringstream ss;
	toStringPreorder(ss, root);
	return ss.str();
}

template<typename TreeT>
void BinarySearchTree<TreeT>::toStringPostorder(std::stringstream& out, const TreeNode<TreeT>* node) noexcept {
	if (!node)
		return;
	toStringPostorder(out, node->left);
	toStringPostorder(out, node->right);
	writeValueToStream(out, node->value);
}

template<typename TreeT>
std::string BinarySearchTree<TreeT>::toStringPostorder() const noexcept {
	std::stringstream ss;
	toStringPostorder(ss, root);
	return ss.str();
}

