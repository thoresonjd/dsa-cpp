/**
 * @file stack.cpp
 * @brief Tests for a stack.
 * @author Justin Thoreson
 */

#include <gtest/gtest.h>
#include <stack.h>

/**
 * @brief Test fixture for a stack of floats.
 */
class StackFloat : public testing::Test {
protected:
    using SizeT = Stack<float>::StackSizeT;
    Stack<float>* stack = nullptr;
    StackFloat() : stack(new Stack<float>) {}
    ~StackFloat() { delete stack; }
};

////////////////////
// Is Empty
////////////////////

TEST_F(StackFloat, IsEmptyExpectTrueWhenStackIsEmpty) {
    ASSERT_TRUE(stack->isEmpty());
}

TEST_F(StackFloat, IsEmptyExpectFalseWhenStackHasOneElement) {
    ASSERT_NO_THROW(stack->push(0.0f));
    ASSERT_FALSE(stack->isEmpty());
}

////////////////////
// Get Size
////////////////////

TEST_F(StackFloat, GetSizeExpectZeroWhenStackIsEmpty) {
	ASSERT_EQ(stack->getSize(), static_cast<SizeT>(0));
}

TEST_F(StackFloat, GetSizeExpectOneWhenStackHasOneElement) {
	ASSERT_NO_THROW(stack->push(0.0f));
	ASSERT_EQ(stack->getSize(), static_cast<SizeT>(1));
}

////////////////////
// Push
////////////////////

TEST_F(StackFloat, PushExpectToPushWhenListIsEmpty) {
    ASSERT_TRUE(stack->isEmpty());
    ASSERT_NO_THROW(stack->push(0.0f));
    ASSERT_EQ(stack->getSize(), static_cast<SizeT>(1));
    ASSERT_FALSE(stack->isEmpty());
    ASSERT_FLOAT_EQ(stack->peek(), 0.0f);
}

TEST_F(StackFloat, PushExpectSizeToIncreaseByOneEachInvocation) {
    ASSERT_EQ(stack->getSize(), static_cast<SizeT>(0));
    for (int i = 1; i <= 10; i++) {
        ASSERT_NO_THROW(stack->push(static_cast<float>(i)));
        ASSERT_EQ(stack->getSize(), static_cast<SizeT>(i));
    }
}

TEST_F(StackFloat, PushExpectLengthErrorWhenMaxSizeHasBeenReached) {
    for (int i = 1; i <= 100; i++)
        ASSERT_NO_THROW(stack->push(static_cast<float>(i)));
    ASSERT_THROW(stack->push(0.0f), std::length_error);
}

////////////////////
// Pop
////////////////////

TEST_F(StackFloat, PopExpectOutOfRangeWhenStackIsEmpty) {
    ASSERT_THROW(stack->pop(), std::out_of_range);
}

TEST_F(StackFloat, PopExpectSizeToDecreaseByOneEachInvocation) {
    for (int i = 1; i <= 10; i++)
        ASSERT_NO_THROW(stack->push(static_cast<float>(i)));
    for (SizeT i = 10; i >= 1; i--) {
        ASSERT_EQ(stack->getSize(), i);
        ASSERT_NO_THROW(stack->pop());
    }
    ASSERT_EQ(stack->getSize(), static_cast<SizeT>(0));
}

////////////////////
// Peek
////////////////////

TEST_F(StackFloat, PeekExpectOutOfRangeIfStackIsEmpty) {
    ASSERT_THROW(stack->peek(), std::out_of_range);
}

TEST_F(StackFloat, PeekExpectZeroWhenZeroIsOnlyElementInStack) {
    ASSERT_NO_THROW(stack->push(0.0f));
    ASSERT_FLOAT_EQ(stack->peek(), 0.0f);
}

TEST_F(StackFloat, PeekExpectLastValuePushed) {
    for (int i = 1; i <= 10; i++) {
        ASSERT_NO_THROW(stack->push(static_cast<float>(i)));
        ASSERT_FLOAT_EQ(stack->peek(), static_cast<float>(i));
    }
}

TEST_F(StackFloat, PeekExpectInverseSequenceOfElementsPushed) {
    for (int i = 1; i <= 10; i++)
        ASSERT_NO_THROW(stack->push(static_cast<float>(i)));
    for (int i = 10; i >= 1; i--) {
        ASSERT_FLOAT_EQ(stack->peek(), static_cast<float>(i));
        ASSERT_NO_THROW(stack->pop());
    }
}

////////////////////
// Clear
////////////////////

TEST_F(StackFloat, ClearExpectToStillBeEmptyAfterClearingAnEmptyStack) {
    ASSERT_TRUE(stack->isEmpty());
    stack->clear();
    ASSERT_TRUE(stack->isEmpty());
}

TEST_F(StackFloat, ClearExpectSizeToStillBeZeroAfterClearingAnEmptyStack) {
    ASSERT_EQ(stack->getSize(), static_cast<SizeT>(0));
    stack->clear();
    ASSERT_EQ(stack->getSize(), static_cast<SizeT>(0));
}

TEST_F(StackFloat, ClearExpectToBeEmptyAfterClearingNonEmptyStack) {
    ASSERT_TRUE(stack->isEmpty());
	for (int i = 1; i <= 10; i++)
		ASSERT_NO_THROW(stack->push(static_cast<float>(i)));
	ASSERT_FALSE(stack->isEmpty());
	stack->clear();
	ASSERT_TRUE(stack->isEmpty());
}

TEST_F(StackFloat, ClearExpectSizeToBeZeroAfterClearingNonEmptyStack) {
    ASSERT_EQ(stack->getSize(), static_cast<SizeT>(0));
    for (int i = 1; i <= 10; i++)
        ASSERT_NO_THROW(stack->push(static_cast<float>(i)));
    ASSERT_EQ(stack->getSize(), static_cast<SizeT>(10));
	stack->clear();
    ASSERT_EQ(stack->getSize(), static_cast<SizeT>(0));
}
