/**
 * @file singly-linked-list.cpp
 * @brief Tests for a singly linked list.
 * @author Justin Thoreson
 */

#include <gtest/gtest.h>
#include <singly-linked-list.h>

/**
 * @brief Test fixture for a linked list of integers.
 */
class SinglyLinkedListInt : public testing::Test {
protected:
    using SizeT = SinglyLinkedList<int>::ListSizeT;
    SinglyLinkedList<int> *list = nullptr;
    SinglyLinkedListInt() : list(new SinglyLinkedList<int>) {}
    ~SinglyLinkedListInt() { delete list; };
};

////////////////////
// Is Empty
////////////////////

TEST_F(SinglyLinkedListInt, IsEmptyExpectTrueWhenListIsEmpty) {
	ASSERT_TRUE(list->isEmpty());
}

TEST_F(SinglyLinkedListInt, IsEmptyExpectFalseWhenListHasOneElement) {
	ASSERT_NO_THROW(list->insertFront(0));
	ASSERT_FALSE(list->isEmpty());
}

////////////////////
// Get Size
////////////////////

TEST_F(SinglyLinkedListInt, GetSizeExpectZeroWhenListIsEmpty) {
	ASSERT_EQ(list->getSize(), static_cast<SizeT>(0));
}

TEST_F(SinglyLinkedListInt, GetSizeExpectOneWhenListHasOneElement) {
	ASSERT_NO_THROW(list->insertEnd(0));
	ASSERT_EQ(list->getSize(), static_cast<SizeT>(1));
}

////////////////////
// Insert Front
////////////////////

TEST_F(SinglyLinkedListInt, InsertFrontExpectToInsertWhenListIsEmpty) {
	ASSERT_TRUE(list->isEmpty());
	ASSERT_NO_THROW(list->insertFront(0));
	ASSERT_FALSE(list->isEmpty());
	ASSERT_EQ(list->getSize(), static_cast<SizeT>(1));
	ASSERT_EQ(list->removeEnd(), 0);
}

TEST_F(SinglyLinkedListInt, InsertFrontExpectSizeToIncreaseByOneEachInvocation) {
	ASSERT_EQ(list->getSize(), static_cast<SizeT>(0));
	for (int i = 1; i <= 10; i++) {
		ASSERT_NO_THROW(list->insertFront(i));
		ASSERT_EQ(list->getSize(), static_cast<SizeT>(i));
	}
}

TEST_F(SinglyLinkedListInt, InsertFrontExpectLengthErrorWhenMaxSizeHasBeenReached) {
    for (int i = 1; i <= 100; i++)
        ASSERT_NO_THROW(list->insertFront(i));
    ASSERT_THROW(list->insertFront(0), std::length_error);
}

////////////////////
// Insert End
////////////////////

TEST_F(SinglyLinkedListInt, InsertEndExpectToInsertWhenListIsEmpty) {
	ASSERT_TRUE(list->isEmpty());
	ASSERT_NO_THROW(list->insertEnd(0));
	ASSERT_FALSE(list->isEmpty());
	ASSERT_EQ(list->getSize(), static_cast<SizeT>(1));
	ASSERT_EQ(list->removeFront(), 0);
}

TEST_F(SinglyLinkedListInt, InsertEndExpectSizeToIncreaseByOneEachInvocation) {
	ASSERT_EQ(list->getSize(), static_cast<SizeT>(0));
	for (int i = 1; i <= 10; i++) {
		ASSERT_NO_THROW(list->insertEnd(i));
		ASSERT_EQ(list->getSize(), static_cast<SizeT>(i));
	}
}

TEST_F(SinglyLinkedListInt, InsertEndExpectLengthErrorWhenMaxSizeHasBeenReached) {
    for (int i = 1; i <= 100; i++)
        ASSERT_NO_THROW(list->insertEnd(i));
    ASSERT_THROW(list->insertEnd(0), std::length_error);
}

////////////////////
// Insert At
////////////////////

TEST_F(SinglyLinkedListInt, InsertAtExpectToInsertWhenListIsEmpty) {
	ASSERT_TRUE(list->isEmpty());
	ASSERT_NO_THROW(list->insertAt(0, 0));
	ASSERT_FALSE(list->isEmpty());
	ASSERT_EQ(list->getSize(), static_cast<SizeT>(1));
	ASSERT_EQ(list->removeAt(0), 0);
}

TEST_F(SinglyLinkedListInt, InsertAtExpectToInsertToFrontWhenIndexIsZero) {
	for (int i = 1; i <= 5; i++)
		ASSERT_NO_THROW(list->insertEnd(i));
	ASSERT_NO_THROW(list->insertAt(0, 0));
	ASSERT_EQ(list->removeFront(), 0);
}

TEST_F(SinglyLinkedListInt, InsertAtExpectToInsertToMiddleWhenIndexIsHalfOfSize) {
	for (int i = 1; i <= 10; i++)
		ASSERT_NO_THROW(list->insertFront(i));
	ASSERT_NO_THROW(list->insertAt(list->getSize() / 2, 0));
	ASSERT_EQ(list->removeAt(list->getSize() / 2), 0);
}

TEST_F(SinglyLinkedListInt, InsertAtExpectToInsertToEndWhenIndexIsSize) {
	for (int i = 1; i <= 5; i++)
		ASSERT_NO_THROW(list->insertFront(i));
	ASSERT_NO_THROW(list->insertAt(list->getSize(), 0));
	ASSERT_EQ(list->removeEnd(), 0);
}

TEST_F(SinglyLinkedListInt, InsertAtExpectToInsertAtFrontIndefinitelyWhenIndexIsZero) {
	for (int i = 50; i >= 1; i--)
		ASSERT_NO_THROW(list->insertAt(0, i));
	for (int i = 1; i <= 50; i++)
		ASSERT_EQ(list->removeFront(), i);
}

TEST_F(SinglyLinkedListInt, InsertAtExpectToInsertAtEndIndefinitelyWhenIndexIsSize) {
	for (int i = 1; i <= 50; i++)
		ASSERT_NO_THROW(list->insertAt(list->getSize(), i));
	for (int i = 1; i <= 50; i++)
		ASSERT_EQ(list->removeFront(), i);
}

TEST_F(SinglyLinkedListInt, InsertAtExpectOutOfRangeWhenIndexIsGreaterThanSize) {
	for (int i = 1; i <= 5; i++)
		ASSERT_NO_THROW(list->insertFront(i));
	ASSERT_THROW(list->insertAt(list->getSize() + 1, 0), std::out_of_range);
}

TEST_F(SinglyLinkedListInt, InsertAtExpectSizeToIncreaseByOneEachInvocation) {
	ASSERT_EQ(list->getSize(), static_cast<SizeT>(0));
	for (int i = 1; i <= 10; i++) {
		ASSERT_NO_THROW(list->insertAt(0, i));
		ASSERT_EQ(list->getSize(), static_cast<SizeT>(i));
	}
}

TEST_F(SinglyLinkedListInt, InsertAtExpectLengthErrorWhenMaxSizeHasBeenReached) {
    for (int i = 1; i <= 100; i++)
        ASSERT_NO_THROW(list->insertAt(0, i));
    ASSERT_THROW(list->insertAt(100, 0), std::length_error);
}

////////////////////
// Remove Front
////////////////////

TEST_F(SinglyLinkedListInt, RemoveFrontExpectOutOfRangeWhenListIsEmpty) {
	ASSERT_THROW(list->removeFront(), std::out_of_range);
}

TEST_F(SinglyLinkedListInt, RemoveFrontExpectZeroWhenZeroIsOnlyElementInList) {
	ASSERT_NO_THROW(list->insertFront(0));
	ASSERT_EQ(list->removeFront(), 0);
}

TEST_F(SinglyLinkedListInt, RemoveFrontExpectInverseSequenceOfElementsInsertedToFront) {
	for (int i = 1; i <= 10; i++)
		ASSERT_NO_THROW(list->insertFront(i));
	for (int i = 10; i >= 1; i--)
		ASSERT_EQ(list->removeFront(), i);
}

TEST_F(SinglyLinkedListInt, RemoveFrontExpectSameSequenceOfElementsInsertedToEnd) {
	for (int i = 1; i <= 10; i++)
		ASSERT_NO_THROW(list->insertEnd(i));
	for (int i = 1; i <= 10; i++)
		ASSERT_EQ(list->removeFront(), i);
}

TEST_F(SinglyLinkedListInt, RemoveFrontExpectSizeToDecreaseByOneEachInvocation) {
	for (int i = 1; i <= 10; i++)
		ASSERT_NO_THROW(list->insertEnd(i));
	for (SizeT i = 10; i >= 1; i--) {
		ASSERT_EQ(list->getSize(), i);
		ASSERT_NO_THROW(list->removeFront());
	}
	ASSERT_EQ(list->getSize(), static_cast<SizeT>(0));
}

////////////////////
// Remove End
////////////////////

TEST_F(SinglyLinkedListInt, RemoveEndExpectOutOfRangeWhenListIsEmpty) {
	ASSERT_THROW(list->removeEnd(), std::out_of_range);
}

TEST_F(SinglyLinkedListInt, RemoveEndExpectZeroWhenZeroIsOnlyElementInList) {
	ASSERT_NO_THROW(list->insertFront(0));
	ASSERT_EQ(list->removeEnd(), 0);
}

TEST_F(SinglyLinkedListInt, RemoveEndExpectInverseSequenceOfElementsInsertedToEnd) {
	for (int i = 1; i <= 10; i++)
		ASSERT_NO_THROW(list->insertEnd(i));
	for (int i = 10; i >= 1; i--)
		ASSERT_EQ(list->removeEnd(), i);
}

TEST_F(SinglyLinkedListInt, RemoveEndExpectSameSequenceOfElementsInsertedToFront) {
	for (int i = 1; i <= 10; i++)
		ASSERT_NO_THROW(list->insertFront(i));
	for (int i = 1; i <= 10; i++)
		ASSERT_EQ(list->removeEnd(), i);	
}

TEST_F(SinglyLinkedListInt, RemoveEndExpectSizeToDecreaseByOneEachInvocation) {
	for (int i = 1; i <= 10; i++)
		ASSERT_NO_THROW(list->insertEnd(i));
	for (SizeT i = 10; i >= 1; i--) {
		ASSERT_EQ(list->getSize(), i);
		ASSERT_NO_THROW(list->removeEnd());
	}
	ASSERT_EQ(list->getSize(), static_cast<SizeT>(0));
}

////////////////////
// Remove At
////////////////////

TEST_F(SinglyLinkedListInt, RemoveAtExpectOutOfRangeWhenListIsEmpty) {
	ASSERT_THROW(list->removeAt(0), std::out_of_range);
}

TEST_F(SinglyLinkedListInt, RemoveAtExpectOutOfRangeWhenIndexIsEqualToSize) {
	for (int i = 1; i <= 5; i++)
		ASSERT_NO_THROW(list->insertEnd(i));
	ASSERT_THROW(list->removeAt(list->getSize()), std::out_of_range);
}

TEST_F(SinglyLinkedListInt, RemoveAtExpectFirstElementWhenIndexIsZero) {
	for (int i = 1; i <= 5; i++)
		ASSERT_NO_THROW(list->insertEnd(i));
	ASSERT_EQ(list->removeAt(0), 1);
}

TEST_F(SinglyLinkedListInt, RemoveAtExpectLastElementWhenIndexIsEqualToSizeMinusOne) {
	for (int i = 1; i <= 5; i++)
		ASSERT_NO_THROW(list->insertEnd(i));
	ASSERT_EQ(list->removeAt(list->getSize() - 1), 5);
}

TEST_F(SinglyLinkedListInt, RemoveAtExpectMiddleElementWhenIndexIsHalfOfSize) {
	for (int i = 1; i <= 5; i++)
		ASSERT_NO_THROW(list->insertEnd(i));
	ASSERT_EQ(list->removeAt(list->getSize() / 2), 3);
}

TEST_F(SinglyLinkedListInt, RemoveAtExpectSizeToDecreaseByOneEachInvocation) {
	for (int i = 1; i <= 10; i++)
		ASSERT_NO_THROW(list->insertEnd(i));
	for (SizeT i = 10; i >= 1; i--) {
		ASSERT_EQ(list->getSize(), i);
		ASSERT_NO_THROW(list->removeAt(0));
	}
	ASSERT_EQ(list->getSize(), static_cast<SizeT>(0));
}

////////////////////
// Clear
////////////////////

TEST_F(SinglyLinkedListInt, ClearExpectToStillBeEmptyAfterClearingAnEmptyList) {
	ASSERT_TRUE(list->isEmpty());
	list->clear();
	ASSERT_TRUE(list->isEmpty());
}

TEST_F(SinglyLinkedListInt, ClearExpectSizeToStillBeZeroAfterClearingAnEmptyList) {
	ASSERT_EQ(list->getSize(), static_cast<SizeT>(0));
	list->clear();
	ASSERT_EQ(list->getSize(), static_cast<SizeT>(0));
}

TEST_F(SinglyLinkedListInt, ClearExpectToBeEmptyAfterClearingNonEmptyList) {
	ASSERT_TRUE(list->isEmpty());
	for (int i = 1; i <= 10; i++)
		ASSERT_NO_THROW(list->insertEnd(i));
	ASSERT_FALSE(list->isEmpty());
	list->clear();
	ASSERT_TRUE(list->isEmpty());
}

TEST_F(SinglyLinkedListInt, ClearExpectSizeToBeZeroAfterClearingNonEmptyList) {
	ASSERT_EQ(list->getSize(), static_cast<SizeT>(0));
	for (int i = 1; i <= 10; i++)
		ASSERT_NO_THROW(list->insertEnd(i));
	ASSERT_EQ(list->getSize(), static_cast<SizeT>(10));
	list->clear();
	ASSERT_EQ(list->getSize(), static_cast<SizeT>(0));
}
