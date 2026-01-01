/**
 * @file binary-search-tree.cpp
 * @brief Tests for a binary search tree.
 * @author Justin Thoreson
 */

#include <gtest/gtest.h>
#include <binary-search-tree.hpp>

using dsa::BinarySearchTree;

class BstInt : public testing::Test {
protected:
	using SizeT = BinarySearchTree<int>::TreeSizeT;
	BinarySearchTree<int>* bst = nullptr;
	BstInt() : bst(new BinarySearchTree<int>) {}
	~BstInt() { delete bst; }
};


////////////////////
// Is Empty
////////////////////

TEST_F(BstInt, IsEmptyExpectTrueWhenBstIsEmpty) {
	ASSERT_TRUE(bst->isEmpty());
}

TEST_F(BstInt, IsEmptyExpectFalseWhenBstHasOneElement) {
	ASSERT_NO_THROW(bst->insert(0));
	ASSERT_FALSE(bst->isEmpty());
}

////////////////////
// Get Size
////////////////////

TEST_F(BstInt, GetSizeExpectZeroWhenBstIsEmpty) {
	ASSERT_EQ(bst->getSize(), static_cast<SizeT>(0));
}

TEST_F(BstInt, GetSizeExpectOneWhenBstHasOneElement) {
	ASSERT_NO_THROW(bst->insert(0));
	ASSERT_EQ(bst->getSize(), static_cast<SizeT>(1));
}

////////////////////
// Insert
////////////////////

TEST_F(BstInt, InsertExpectToInsertWhenBstIsEmpty) {
	ASSERT_TRUE(bst->isEmpty());
	ASSERT_NO_THROW(bst->insert(0));
	ASSERT_EQ(bst->getSize(), static_cast<SizeT>(1));
	ASSERT_FALSE(bst->isEmpty());	
}

TEST_F(BstInt, InsertExpectSizeToIncreaseByOneEachInvocation) {
	ASSERT_EQ(bst->getSize(), static_cast<SizeT>(0));
	for (int i = 1; i <= 10; i++) {
		ASSERT_NO_THROW(bst->insert(i));
		ASSERT_EQ(bst->getSize(), static_cast<SizeT>(i));
	}
}

TEST_F(BstInt, InsertExpectLengthErrorWhenMaxSizeHasBeenReached) {
	for (int i = 1; i <= 100; i++)
		ASSERT_NO_THROW(bst->insert(i));
	ASSERT_THROW(bst->insert(0), std::length_error);
}

TEST_F(BstInt, InsertExpectNotToInsertWhenValueAlreadyExistsInBst) {
	ASSERT_EQ(bst->getSize(), static_cast<SizeT>(0));
	for (int i = 1; i <= 10; i++) {
		ASSERT_NO_THROW(bst->insert(i));
		ASSERT_EQ(bst->getSize(), static_cast<SizeT>(i));
	}
	for (int i = 1; i <= 10; i++) {
		ASSERT_NO_THROW(bst->insert(i));
		ASSERT_EQ(bst->getSize(), static_cast<SizeT>(10));
	}
	for (int i = 11; i <= 20; i++) {
		ASSERT_NO_THROW(bst->insert(i));
		ASSERT_EQ(bst->getSize(), static_cast<SizeT>(i));
	}
}

////////////////////
// Remove
////////////////////

TEST_F(BstInt, RemoveExpectNotToRemoveValueThatIsNotPresent) {
	ASSERT_EQ(bst->getSize(), static_cast<SizeT>(0));	
	bst->remove(0);
	ASSERT_EQ(bst->getSize(), static_cast<SizeT>(0));	
}

TEST_F(BstInt, RemoveExpectSizeToDecreaseByOneEachInvocation) {
	for (int i = 1; i <= 10; i++)
		ASSERT_NO_THROW(bst->insert(i));
	for (int i = 10; i >= 1; i--) {
		ASSERT_EQ(bst->getSize(), static_cast<SizeT>(i));
		ASSERT_NO_THROW(bst->remove(i));
	}
	ASSERT_EQ(bst->getSize(), static_cast<SizeT>(0));
}

////////////////////
// Traversals 
////////////////////

/*
Example:

            _7_ 
          _/   \_
        _/       \_
       /           \
      3            11
     / \          /  \
    /   \        /    \
   1     5      9     13
  / \   / \    / \   /  \
 0   2 4   6  8  10 12  14

*/

// In Order
// -----------------

TEST_F(BstInt, ToStringInOrderExpectEmptyStringWhenBstIsEmpty) {
	ASSERT_EQ(bst->toStringInorder(), "");
}

TEST_F(BstInt, ToStringInOrderExpectInOrderSequenceWhenPopulated) {
	int values[] = {7, 3, 1, 5, 0, 2, 4, 6, 11, 9, 13, 8, 10, 12, 14};
	for (const int& value : values)
		ASSERT_NO_THROW(bst->insert(value));
	ASSERT_EQ(bst->toStringInorder(), "0 1 2 3 4 5 6 7 8 9 10 11 12 13 14");
}

// Pre Order
// -----------------

TEST_F(BstInt, ToStringPreOrderExpectEmptyStringWhenBstIsEmpty) {
	ASSERT_EQ(bst->toStringPreorder(), "");
}

TEST_F(BstInt, ToStringPreOrderExpectPreOrderSequenceWhenPopulated) {
	int values[] = {7, 3, 1, 5, 0, 2, 4, 6, 11, 9, 13, 8, 10, 12, 14};
	for (const int& value : values)
		ASSERT_NO_THROW(bst->insert(value));
	ASSERT_EQ(bst->toStringPreorder(), "7 3 1 0 2 5 4 6 11 9 8 10 13 12 14");
}

// Post Order
// -----------------

TEST_F(BstInt, ToStringPostOrderExpectEmptyStringWhenBstIsEmpty) {
	ASSERT_EQ(bst->toStringPostorder(), "");
}

TEST_F(BstInt, ToStringPostOrderExpectPostOrderSequenceWhenPopulated) {
    int values[] = {7, 3, 1, 5, 0, 2, 4, 6, 11, 9, 13, 8, 10, 12, 14};
	for (const int& value : values)
		ASSERT_NO_THROW(bst->insert(value));
	ASSERT_EQ(bst->toStringPostorder(), "0 2 1 4 6 5 3 8 10 9 12 14 13 11 7");
}

