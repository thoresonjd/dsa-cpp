# Linked List

A linked list is a data structure that holds data in a linear fashion. Data elements are chained together via nodes to form a sequence. An individual node encapsulates a single data element as well as at least one pointer or reference to another node in the list.

## Singly Linked List

The most basic form of the linked list is the singly linked list, where each node contains a single data element and a single pointer/reference to the next node in the list. The last node in the list points to null.

### Example

```
      +---+---+  +---+---+  +---+---+
head->| 0 | --+->| 1 | --+->| 2 | --+->null
      +---+---+  +---+---+  +---+---+
```

### Code

| File           | Location                                                 |
|----------------|----------------------------------------------------------|
| Header         | [singly-linked-list.h](../include/singly-linked-list.h)  |
| Implementation | [singly-linked-list.tpp](../src/singly-linked-list.tpp)  |
| Test           | [singly-linked-list.cpp](../test/singly-linked-list.cpp) |

## Other Linked Lists

Other forms of the linked list include the doubly linked list and the circular linked list. Additional forms exist as well.

