/**
 * @file queue.cpp
 * @brief Tests for a queue.
 * @author Justin Thoreson
 */

#include <gtest/gtest.h>
#include <queue.h>

/**
 * @brief Test fixture for a queue of characters.
 */
class QueueChar : public testing::Test {
protected:
    using SizeT = Queue<char>::QueueSizeT;
    Queue<char>* queue = nullptr;
    QueueChar(): queue(new Queue<char>) {}
	~QueueChar() { delete queue; }
};

////////////////////
// Is Empty
////////////////////

TEST_F(QueueChar, IsEmptyExpectTrueWhenQueueIsEmpty) {
    ASSERT_TRUE(queue->isEmpty());
}

TEST_F(QueueChar, IsEmptyExpectFalseWhenQueueHasOneElement) {
    ASSERT_NO_THROW(queue->enqueue('a'));
    ASSERT_FALSE(queue->isEmpty());
}

////////////////////
// Get Size
////////////////////

TEST_F(QueueChar, GetSizeExpectZeroWhenQueueIsEmpty) {
	ASSERT_EQ(queue->getSize(), static_cast<SizeT>(0));
}

TEST_F(QueueChar, GetSizeExpectOneWhenQueueHasOneElement) {
	ASSERT_NO_THROW(queue->enqueue('a'));
	ASSERT_EQ(queue->getSize(), static_cast<SizeT>(1));
}

////////////////////
// Enqueue
////////////////////

TEST_F(QueueChar, EnqueueExpectToEnqueueWhenListIsEmpty) {
    ASSERT_TRUE(queue->isEmpty());
    ASSERT_NO_THROW(queue->enqueue('a'));
    ASSERT_EQ(queue->getSize(), static_cast<SizeT>(1));
    ASSERT_FALSE(queue->isEmpty());
    ASSERT_EQ(queue->peek(), 'a');
}

TEST_F(QueueChar, EnqueueExpectSizeToIncreaseByOneEachInvocation) {
    ASSERT_EQ(queue->getSize(), static_cast<SizeT>(0));
    for (int i = 1; i <= 10; i++) {
        ASSERT_NO_THROW(queue->enqueue(static_cast<char>(i)));
        ASSERT_EQ(queue->getSize(), static_cast<SizeT>(i));
    }
}

TEST_F(QueueChar, EnqueueExpectLengthErrorWhenMaxSizeHasBeenReached) {
    for (int i = 1; i <= 100; i++)
        ASSERT_NO_THROW(queue->enqueue(static_cast<char>(i)));
    ASSERT_THROW(queue->enqueue(static_cast<char>(0)), std::length_error);
}

////////////////////
// Dequeue
////////////////////

TEST_F(QueueChar, DequeueExpectOutOfRangeWhenQueueIsEmpty) {
    ASSERT_THROW(queue->dequeue(), std::out_of_range);
}

TEST_F(QueueChar, DequeueExpectSizeToDecreaseByOneEachInvocation) {
    for (int i = 1; i <= 10; i++)
        ASSERT_NO_THROW(queue->enqueue(static_cast<char>(i)));
    for (SizeT i = 10; i >= 1; i--) {
        ASSERT_EQ(queue->getSize(), i);
        ASSERT_NO_THROW(queue->dequeue());
    }
    ASSERT_EQ(queue->getSize(), static_cast<SizeT>(0));
}

////////////////////
// Peek
////////////////////

TEST_F(QueueChar, PeekExpectOutOfRangeIfQueueIsEmpty) {
    ASSERT_THROW(queue->peek(), std::out_of_range);
}

TEST_F(QueueChar, PeekExpectZeroWhenZeroIsOnlyElementInQueue) {
    ASSERT_NO_THROW(queue->enqueue('a'));
    ASSERT_EQ(queue->peek(), 'a');
}

TEST_F(QueueChar, PeekExpectFirstValueEnqueuedIfNeverDequeued) {
    for (int i = 1; i <= 10; i++) {
        ASSERT_NO_THROW(queue->enqueue(static_cast<char>(i)));
        ASSERT_EQ(queue->peek(), static_cast<char>(1));
    }
}

TEST_F(QueueChar, PeekExpectSameSequenceOfElementsEnqueued) {
    for (int i = 1; i <= 10; i++)
        ASSERT_NO_THROW(queue->enqueue(static_cast<char>(i)));
    for (int i = 1; i <= 10; i++) {
        ASSERT_EQ(queue->peek(), static_cast<char>(i));
        ASSERT_NO_THROW(queue->dequeue());
    }
}

////////////////////
// Clear
////////////////////

TEST_F(QueueChar, ClearExpectToStillBeEmptyAfterClearingAnEmptyQueue) {
    ASSERT_TRUE(queue->isEmpty());
    queue->clear();
    ASSERT_TRUE(queue->isEmpty());
}

TEST_F(QueueChar, ClearExpectSizeToStillBeZeroAfterClearingAnEmptyQueue) {
    ASSERT_EQ(queue->getSize(), static_cast<SizeT>(0));
    queue->clear();
    ASSERT_EQ(queue->getSize(), static_cast<SizeT>(0));
}

TEST_F(QueueChar, ClearExpectToBeEmptyAfterClearingNonEmptyQueue) {
    ASSERT_TRUE(queue->isEmpty());
	for (int i = 1; i <= 10; i++)
		ASSERT_NO_THROW(queue->enqueue(static_cast<char>(i)));
	ASSERT_FALSE(queue->isEmpty());
	queue->clear();
	ASSERT_TRUE(queue->isEmpty());
}

TEST_F(QueueChar, ClearExpectSizeToBeZeroAfterClearingNonEmptyQueue) {
    ASSERT_EQ(queue->getSize(), static_cast<SizeT>(0));
    for (int i = 1; i <= 10; i++)
        ASSERT_NO_THROW(queue->enqueue(static_cast<char>(i)));
    ASSERT_EQ(queue->getSize(), static_cast<SizeT>(10));
	queue->clear();
    ASSERT_EQ(queue->getSize(), static_cast<SizeT>(0));
}

