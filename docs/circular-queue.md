# Circular Queue

A circular queue, also known as a ring buffer, is a queue of fixed size where the underlying data storage operates via circular/modulo arithmetic.

## Operations

A circular queue supports the same operations as a typical queue:
- `enqueue` - Places a data element into the back of the queue
- `dequeue` - Removes the data element at the front of the queue
- `peek` - Retrieves the data element at the front of the queue

The implementation here also supports two additional operations:
- `isEmpty` - Checks if the circular queue is empty
- `isFull` - Checks if the capacity of the circular queue has been reached

## Example

In this example, the underlying structure is an array. The front (`f`) and rear (`r`) indices are tracked such that whenever an element is enqueued or dequeued from the circular queue, modulo arithmetic can resolve where to enqueue to or dequeue from. Meaning, once the end of the array itself is surpassed by either `f` or `r`, that index will need to wrap around to the front. Similarly, if the start of the array is surpassed, the index will need to wrap around to the end. Hence, the cirular nature of the queue.

```
Operation | Visual
----------+-----------------------------------------
          |  f/r
          |   |
          |   v
          | +---+---+---+---+---+
          | |   |   |   |   |   |
          | +---+---+---+---+---+
          | 
          |  f/r
          |   |
          |   v
          | +---+---+---+---+---+
Enqueue 1 | | 1 |   |   |   |   |
          | +---+---+---+---+---+
          |
          |   f   r
          |   |   |
          |   v   v
          | +---+---+---+---+---+
Enqueue 2 | | 1 | 2 |   |   |   |
          | +---+---+---+---+---+
          |
          |   f       r
          |   |       |
          |   v       v
          | +---+---+---+---+---+
Enqueue 3 | | 1 | 2 | 3 |   |   |
          | +---+---+---+---+---+
          |
          |   f           r
          |   |           |
          |   v           v
          | +---+---+---+---+---+
Enqueue 4 | | 1 | 2 | 3 | 4 |   |
          | +---+---+---+---+---+
          |
          |   f               r
          |   |               |
          |   v               v
          | +---+---+---+---+---+
Enqueue 5 | | 1 | 2 | 3 | 4 | 5 |
          | +---+---+---+---+---+
          |
          |       f           r
          |       |           |
          |       v           v
          | +---+---+---+---+---+
  Dequeue | |   | 2 | 3 | 4 | 5 |
          | +---+---+---+---+---+
          |
          |           f       r
          |           |       |
          |           v       v
          | +---+---+---+---+---+
  Dequeue | |   |   | 3 | 4 | 5 |
          | +---+---+---+---+---+
          |
          |               f   r
          |               |   |
          |               v   v
          | +---+---+---+---+---+
  Dequeue | |   |   |   | 4 | 5 |
          | +---+---+---+---+---+
          |
          |   r           f
          |   |           |
          |   v           v
          | +---+---+---+---+---+
Enqueue 6 | | 6 |   |   | 4 | 5 |
          | +---+---+---+---+---+
          |
          |       r       f
          |       |       |
          |       v       v
          | +---+---+---+---+---+
Enqueue 7 | | 6 | 7 |   | 4 | 5 |
          | +---+---+---+---+---+
          |
          |       r           f
          |       |           |
          |       v           v
          | +---+---+---+---+---+
  Dequeue | | 6 | 7 |   |   | 5 |
          | +---+---+---+---+---+
          |
          |   f   r       
          |   |   |
          |   v   v  
          | +---+---+---+---+---+
  Dequeue | | 6 | 7 |   |   |   |
          | +---+---+---+---+---+
          |
          |       f   r
          |       |   |
          |       v   v
          | +---+---+---+---+---+
  Dequeue | |   | 7 | 8 |   |   |
          | +---+---+---+---+---+
          |
          |       f       r
          |       |       |
          |       v       v
          | +---+---+---+---+---+
Enqueue 9 | |   | 7 | 8 | 9 |   |
          | +---+---+---+---+---+
          |
          |       f           r
          |       |           |
          |       v           v
          | +---+---+---+---+---+
Enqueue 0 | |   | 7 | 8 | 9 | 0 |
          | +---+---+---+---+---+
          
          |   r   f
          |   |   |
          |   v   v
          | +---+---+---+---+---+
Enqueue 1 | | 1 | 7 | 8 | 9 | 0 |
          | +---+---+---+---+---+
```

## Code

| File           | Location                                            |
|----------------|-----------------------------------------------------|
| Header         | [circular-queue.hpp](../include/circular-queue.hpp) |
| Implementation | [circular-queue.tpp](../src/circular-queue.tpp)     |
| Test           | [circular-queue.cpp](../test/circular-queue.cpp)    |
