# Queue

A queue is a linear data structure where the data inserted and removed from the queue follows first in, first out (FIFO) ordering. A common real-world example is a ticket booth line at the cinema: the *first* person to enter the line is the `first` person to receive their ticket.

## Operations

The primary operations of a queue are:
- `enqueue` - Places a data element into the back of the queue
- `dequeue` - Removes the data element at the front of the queue
- `peek` - Retrieves the data element at the front of the queue

## Example

```
Operation | Visual
----------+-----------------------------------------
          |          rear
          |           |
          |           V
          | front -> null
          |
          |           rear
Enqueue 1 |            |
          |            V  
          |          +---+
          | front -> | 1 | -> null
          |          +---+
          |
          |                    rear
Enqueue 2 |                     |
          |                     V 
          |          +---+    +---+
          | front -> | 1 | -> | 2 | -> null
          |          +---+    +---+
          |
          |                             rear
Enqueue 3 |                              |
          |                              V   
          |          +---+    +---+    +---+
          | front -> | 1 | -> | 2 | -> | 3 | -> null
          |          +---+    +---+    +---+
          |  
          |                    rear
  Dequeue |                     |
          |                     V 
          |          +---+    +---+
          | front -> | 1 | -> | 2 | -> null
          |          +---+    +---+

          |           rear
  Dequeue |            |
          |            V  
          |          +---+
          | front -> | 1 | -> null
          |          +---+
          |
          |          rear
  Dequeue |           |
          |           V
          | front -> null
```

## Code

| File           | Location                       |
|----------------|--------------------------------|
| Header         | [queue.h](../include/queue.h)  |
| Implementation | [queue.tpp](../src/queue.tpp)  |
| Test           | [queue.cpp](../test/queue.cpp) |