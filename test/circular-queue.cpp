/**
 * @file circular-queue.cpp
 * @brief Tests for a circular queue.
 * @author Justin Thoreson
 */

#include <gtest/gtest.h>
#include <circular-queue.hpp>

using dsa::CircularQueue;

/**
 * @brief Test fixture for a circular queue of integers.
 */
class CircularQueueInt : public testing::Test {
protected:
	using SizeT = CircularQueue<int>::QueueSizeT;
	static constexpr SizeT MIN_CAPACITY = CircularQueue<int>::MIN_CAPACITY;
	static constexpr SizeT MAX_CAPACITY = CircularQueue<int>::MAX_CAPACITY;
	CircularQueue<int>* circularQueue = nullptr;
	CircularQueueInt() = default;
	~CircularQueueInt() { if (circularQueue) delete circularQueue; }
};

/**
 * @brief Test fixture for a circular queue of floats.
 */
class CircularQueueFloat : public testing::Test {
protected:
	using SizeT = CircularQueue<float>::QueueSizeT;
	static constexpr SizeT CAPACITY = 10;
	CircularQueue<float>* circularQueue = nullptr;
	CircularQueueFloat(): circularQueue(new CircularQueue<float>(CAPACITY)) {}
	~CircularQueueFloat() { delete circularQueue; }
};

////////////////////
// Constructor
////////////////////

TEST_F(CircularQueueInt, ConstructorExpectInvalidArgumentGivenCapacityOfZero) {
	ASSERT_THROW(circularQueue = new CircularQueue<int>(MIN_CAPACITY - 1), std::invalid_argument);
}

TEST_F(CircularQueueInt, ConstructorExpectInvalidArgumentGivenTooLargeCapacity) {
	for (SizeT capacity = MIN_CAPACITY; capacity <= MAX_CAPACITY; capacity++) {
		ASSERT_NO_THROW(circularQueue = new CircularQueue<int>(capacity));
		ASSERT_NO_THROW(delete circularQueue);
		circularQueue = nullptr;
	}
	ASSERT_THROW(circularQueue = new CircularQueue<int>(MAX_CAPACITY + 1), std::invalid_argument);
}

////////////////////
// Is Empty
////////////////////

TEST_F(CircularQueueFloat, IsEmptyExpectTrueWhenQueueIsEmpty) {
	ASSERT_TRUE(circularQueue->isEmpty());
}

TEST_F(CircularQueueFloat, IsEmptyExpectFalseWhenQueueHasOneElement) {
	ASSERT_NO_THROW(circularQueue->enqueue(1.0f));
	ASSERT_FALSE(circularQueue->isEmpty());	
}

////////////////////
// Is Full
////////////////////

TEST_F(CircularQueueFloat, IsFullExpectFalseWhenEmpty) {
	ASSERT_FALSE(circularQueue->isFull());
}

TEST_F(CircularQueueFloat, IsFullExpectTrueWhenCapacityReached) {
	for (SizeT i = 0; i < CAPACITY; i++) {
		ASSERT_FALSE(circularQueue->isFull());
		ASSERT_NO_THROW(circularQueue->enqueue(1.0f));
	}
	ASSERT_TRUE(circularQueue->isFull());
}	

TEST_F(CircularQueueFloat, IsFullExpectFalseAfterDequeueFromFullCapacity) {
	for (SizeT i = 0; i < CAPACITY; i++) {
		ASSERT_FALSE(circularQueue->isFull());
		ASSERT_NO_THROW(circularQueue->enqueue(1.0f));
	}
	ASSERT_TRUE(circularQueue->isFull());
	ASSERT_NO_THROW(circularQueue->dequeue());
	ASSERT_FALSE(circularQueue->isFull());
}

////////////////////
// Get Size
////////////////////

TEST_F(CircularQueueFloat, GetSizeExpectSizeToIncrementEachEnqueue) {
	for (SizeT i = 0; i < CAPACITY; i++) {
		ASSERT_EQ(circularQueue->getSize(), i);
		ASSERT_NO_THROW(circularQueue->enqueue(1.0f));
	}
	ASSERT_EQ(circularQueue->getSize(), CAPACITY);
}

TEST_F(CircularQueueFloat, GetSizeExpectSizeToDecrementEachDequeue) {
	for (SizeT i = 0; i < CAPACITY; i++)
		ASSERT_NO_THROW(circularQueue->enqueue(1.0f));	
	for (SizeT i = CAPACITY; i > 0; i--) {
		ASSERT_EQ(circularQueue->getSize(), i);
		ASSERT_NO_THROW(circularQueue->dequeue());
	}
	ASSERT_EQ(circularQueue->getSize(), 0);
}

////////////////////
// Peek
////////////////////

TEST_F(CircularQueueFloat, PeekExpectOutOfRangeWhenQueueIsEmpty) {
	ASSERT_THROW(circularQueue->peek(), std::out_of_range);
}

TEST_F(CircularQueueFloat, PeekExpectFrontToAlwaysBeFirstEnqueuedWhenNoDequeues) {
	for (SizeT i = 0; i < CAPACITY; i++) {
		ASSERT_NO_THROW(circularQueue->enqueue(static_cast<float>(i)));
		ASSERT_FLOAT_EQ(circularQueue->peek(), 0.0f);	
	}
}

TEST_F(CircularQueueFloat, PeekExpectFrontToShiftToSuccessiveEnqueueAfterDequeue) {
	for (SizeT i = 0; i < CAPACITY; i++)
		ASSERT_NO_THROW(circularQueue->enqueue(static_cast<float>(i)));
	for (SizeT i = 0; i < CAPACITY; i++) {
		ASSERT_FLOAT_EQ(circularQueue->peek(), static_cast<float>(i));
		ASSERT_NO_THROW(circularQueue->dequeue());
	}
}

////////////////////
// Enqueue
////////////////////

TEST_F(CircularQueueFloat, EnqueueExpectLengthErrorWhenCapacityExceeded) {
	for (SizeT i = 0; i < CAPACITY; i++)
		ASSERT_NO_THROW(circularQueue->enqueue(1.0f));
	ASSERT_THROW(circularQueue->enqueue(1.0f), std::length_error);
}

////////////////////
// Dequeue
////////////////////

TEST_F(CircularQueueFloat, DequeueExpectOutOfRangeWhenQueueIsEmpty) {
	ASSERT_THROW(circularQueue->dequeue(), std::out_of_range);
}
