#include <gtest/gtest.h>
#include <linked-list.h>

/**
 * @brief Test fixture for a linked list of integers.
 */
class LinkedListInt : public testing::Test {
protected:
	LinkedList<int>* list = nullptr;

	LinkedListInt() {
		list = new LinkedList<int>;
	}

	~LinkedListInt() {
		delete list;
	}
};

////////////////////
// Is Empty
////////////////////

TEST_F(LinkedListInt, IsEmptyExpectTrueWhenListIsEmpty) {
	ASSERT_TRUE(list->isEmpty());
}

TEST_F(LinkedListInt, IsEmptyExpectFalseWhenListHasOneElement) {
	list->insertFront(0);
	ASSERT_FALSE(list->isEmpty());
}

////////////////////
// Get Size
////////////////////

TEST_F(LinkedListInt, GetSizeExpectZeroWhenListIsEmpty) {
	ASSERT_EQ(list->getSize(), static_cast<std::size_t>(0));
}

TEST_F(LinkedListInt, GetSizeExpectOneWhenListHasOneElement) {
	list->insertEnd(0);
	ASSERT_EQ(list->getSize(), static_cast<std::size_t>(1));
}

////////////////////
// Insert Front
////////////////////

TEST_F(LinkedListInt, InsertFrontExpectToInsertWhenListIsEmpty) {
	ASSERT_TRUE(list->isEmpty());
	list->insertFront(0);
	ASSERT_FALSE(list->isEmpty());
	ASSERT_EQ(list->getSize(), static_cast<std::size_t>(1));
	ASSERT_EQ(list->removeEnd(), 0);
}

TEST_F(LinkedListInt, InsertFrontExpectSizeToIncreaseByOneEachInvocation) {
	ASSERT_EQ(list->getSize(), static_cast<std::size_t>(0));
	for (int i = 1; i <= 10; i++) {
		list->insertFront(i);
		ASSERT_EQ(list->getSize(), static_cast<std::size_t>(i));
	}
}

////////////////////
// Insert End
////////////////////

TEST_F(LinkedListInt, InsertEndExpectToInsertWhenListIsEmpty) {
	ASSERT_TRUE(list->isEmpty());
	list->insertEnd(0);
	ASSERT_FALSE(list->isEmpty());
	ASSERT_EQ(list->getSize(), static_cast<std::size_t>(1));
	ASSERT_EQ(list->removeFront(), 0);
}

TEST_F(LinkedListInt, InsertEndExpectSizeToIncreaseByOneEachInvocation) {
	ASSERT_EQ(list->getSize(), static_cast<std::size_t>(0));
	for (int i = 1; i <= 10; i++) {
		list->insertEnd(i);
		ASSERT_EQ(list->getSize(), static_cast<std::size_t>(i));
	}
}

////////////////////
// Insert At
////////////////////

TEST_F(LinkedListInt, InsertAtExpectToInsertWhenListIsEmpty) {
	ASSERT_TRUE(list->isEmpty());
	ASSERT_NO_THROW(list->insertAt(0, 0));
	ASSERT_FALSE(list->isEmpty());
	ASSERT_EQ(list->getSize(), static_cast<std::size_t>(1));
	ASSERT_EQ(list->removeAt(0), 0);
}

TEST_F(LinkedListInt, InsertAtExpectToInsertToFrontWhenIndexIsZero) {
	for (int i = 1; i <= 5; i++)
		list->insertEnd(i);
	ASSERT_NO_THROW(list->insertAt(0, 0));
	ASSERT_EQ(list->removeFront(), 0);
}

TEST_F(LinkedListInt, InsertAtExpectToInsertToMiddleWhenIndexIsHalfOfSize) {
	for (int i = 1; i <= 10; i++)
		list->insertFront(i);
	ASSERT_NO_THROW(list->insertAt(list->getSize() / 2, 0));
	ASSERT_EQ(list->removeAt(list->getSize() / 2), 0);
}

TEST_F(LinkedListInt, InsertAtExpectToInsertToEndWhenIndexIsSize) {
	for (int i = 1; i <= 5; i++)
		list->insertFront(i);
	ASSERT_NO_THROW(list->insertAt(list->getSize(), 0));
	ASSERT_EQ(list->removeEnd(), 0);
}

TEST_F(LinkedListInt, InsertAtExpectToInsertAtFrontIndefinitelyWhenIndexIsZero) {
	for (int i = 100; i >= 1; i--)
		ASSERT_NO_THROW(list->insertAt(0, i));
	for (int i = 1; i <= 100; i++)
		ASSERT_EQ(list->removeFront(), i);
}

TEST_F(LinkedListInt, InsertAtExpectToInsertAtEndIndefinitelyWhenIndexIsSize) {
	for (int i = 1; i <= 100; i++)
		ASSERT_NO_THROW(list->insertAt(list->getSize(), i));
	for (int i = 1; i <= 100; i++)
		ASSERT_EQ(list->removeFront(), i);
}

TEST_F(LinkedListInt, InsertAtExpectOutOfRangeWhenIndexIsGreaterThanSize) {
	for (int i = 1; i <= 5; i++)
		list->insertFront(i);
	ASSERT_THROW(list->insertAt(list->getSize() + 1, 0), std::out_of_range);
}

TEST_F(LinkedListInt, InsertAtExpectSizeToIncreaseByOneEachInvocation) {
	ASSERT_EQ(list->getSize(), static_cast<std::size_t>(0));
	for (int i = 1; i <= 10; i++) {
		ASSERT_NO_THROW(list->insertAt(0, i));
		ASSERT_EQ(list->getSize(), static_cast<std::size_t>(i));
	}
}

////////////////////
// Remove Front
////////////////////

TEST_F(LinkedListInt, RemoveFrontExpectOutOfRangeWhenListIsEmpty) {
	ASSERT_THROW(list->removeFront(), std::out_of_range);
}

TEST_F(LinkedListInt, RemoveFrontExpectZeroWhenZeroIsOnlyElementInList) {
	list->insertFront(0);
	ASSERT_EQ(list->removeFront(), 0);
}

TEST_F(LinkedListInt, RemoveFrontExpectInverseSequenceOfElementsInsertedToFront) {
	for (int i = 1; i <= 10; i++)
		list->insertFront(i);
	for (int i = 10; i >= 1; i--)
		ASSERT_EQ(list->removeFront(), i);
}

TEST_F(LinkedListInt, RemoveFrontExpectSameSequenceOfElementsInsertedToEnd) {
	for (int i = 1; i <= 10; i++)
		list->insertEnd(i);
	for (int i = 1; i <= 10; i++)
		ASSERT_EQ(list->removeFront(), i);
}

TEST_F(LinkedListInt, RemoveFrontExpectSizeToDecreaseByOneEachInvocation) {
	for (int i = 1; i <= 10; i++)
		list->insertEnd(i);
	for (std::size_t i = 10; i >= 1; i--) {
		ASSERT_EQ(list->getSize(), i);
		ASSERT_NO_THROW(list->removeFront());
	}
	ASSERT_EQ(list->getSize(), static_cast<std::size_t>(0));
}

////////////////////
// Remove End
////////////////////

TEST_F(LinkedListInt, RemoveEndExpectOutOfRangeWhenListIsEmpty) {
	ASSERT_THROW(list->removeEnd(), std::out_of_range);
}

TEST_F(LinkedListInt, RemoveEndExpectZeroWhenZeroIsOnlyElementInList) {
	list->insertFront(0);
	ASSERT_EQ(list->removeEnd(), 0);
}

TEST_F(LinkedListInt, RemoveEndExpectInverseSequenceOfElementsInsertedToEnd) {
	for (int i = 1; i <= 10; i++)
		list->insertEnd(i);
	for (int i = 10; i >= 1; i--)
		ASSERT_EQ(list->removeEnd(), i);
}

TEST_F(LinkedListInt, RemoveEndExpectSameSequenceOfElementsInsertedToFront) {
	for (int i = 1; i <= 10; i++)
		list->insertFront(i);
	for (int i = 1; i <= 10; i++)
		ASSERT_EQ(list->removeEnd(), i);	
}

TEST_F(LinkedListInt, RemoveEndExpectSizeToDecreaseByOneEachInvocation) {
	for (int i = 1; i <= 10; i++)
		list->insertEnd(i);
	for (std::size_t i = 10; i >= 1; i--) {
		ASSERT_EQ(list->getSize(), i);
		ASSERT_NO_THROW(list->removeEnd());
	}
	ASSERT_EQ(list->getSize(), static_cast<std::size_t>(0));
}

////////////////////
// Remove At
////////////////////

TEST_F(LinkedListInt, RemoveAtExpectOutOfRangeWhenListIsEmpty) {
	ASSERT_THROW(list->removeAt(0), std::out_of_range);
}

TEST_F(LinkedListInt, RemoveAtExpectOutOfRangeWhenIndexIsEqualToSize) {
	for (int i = 1; i <= 5; i++)
		list->insertEnd(i);
	ASSERT_THROW(list->removeAt(list->getSize()), std::out_of_range);
}

TEST_F(LinkedListInt, RemoveAtExpectFirstElementWhenIndexIsZero) {
	for (int i = 1; i <= 5; i++)
		list->insertEnd(i);
	ASSERT_EQ(list->removeAt(0), 1);
}

TEST_F(LinkedListInt, RemoveAtExpectLastElementWhenIndexIsEqualToSizeMinusOne) {
	for (int i = 1; i <= 5; i++)
		list->insertEnd(i);
	ASSERT_EQ(list->removeAt(list->getSize() - 1), 5);
}

TEST_F(LinkedListInt, RemoveAtExpectMiddleElementWhenIndexIsHalfOfSize) {
	for (int i = 1; i <= 5; i++)
		list->insertEnd(i);
	ASSERT_EQ(list->removeAt(list->getSize() / 2), 3);
}

TEST_F(LinkedListInt, RemoveAtExpectSizeToDecreaseByOneEachInvocation) {
	for (int i = 1; i <= 10; i++)
		list->insertEnd(i);
	for (std::size_t i = 10; i >= 1; i--) {
		ASSERT_EQ(list->getSize(), i);
		ASSERT_NO_THROW(list->removeAt(0));
	}
	ASSERT_EQ(list->getSize(), static_cast<std::size_t>(0));
}

////////////////////
// Clear
////////////////////

TEST_F(LinkedListInt, ClearExpectListToBeEmptyAfterClearing) {
	ASSERT_TRUE(list->isEmpty());
	for (int i = 1; i <= 10; i++)
		list->insertEnd(i);
	ASSERT_FALSE(list->isEmpty());
	list->clear();
	ASSERT_TRUE(list->isEmpty());
}

TEST_F(LinkedListInt, ClearExpectSizeZeroAfterClearing) {
	ASSERT_EQ(list->getSize(), static_cast<std::size_t>(0));
	for (int i = 1; i <= 10; i++)
		list->insertEnd(i);
	ASSERT_EQ(list->getSize(), static_cast<std::size_t>(10));
	list->clear();
	ASSERT_EQ(list->getSize(), static_cast<std::size_t>(0));
}
