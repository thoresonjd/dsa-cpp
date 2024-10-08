# Stack

A stack is a linear data structure where the data inserted and removed from the stack follows last in, first out (LIFO) ordering. A common real-world example is a stack of plates: the *last* plate added to the top of the stack is the *first* plate removed from the top of the stack.

## Operations

The primary operations of a stack are:
- `push` - Places a data element onto the top of the stack
- `pop` - Removes the data element on the top of the stack
- `peek` - Retrieves the data element on the top of the stack

## Example

```
Operations:

    push 1  push 2  push 3   pop     pop     pop

 top     top     top     top     top     top     top
  |       |       |       |       |       |       |
  V       V       V       V       V       V       V
 null   +---+   +---+   +---+   +---+   +---+    null
        | 1 |   | 2 |   | 3 |   | 2 |   | 1 | 
        +---+   +---+   +---+   +---+   +---+
          |       |       |       |       |
          V       V       V       V       V
         null   +---+   +---+   +---+    null
                | 1 |   | 2 |   | 1 |
                +---+   +---+   +---+
                  |       |       |
                  V       V       V
                 null   +---+    null
                        | 1 |  
                        +---+  
                          |
                          V
                         null  
```

## Code

| File           | Location                                   |
|----------------|--------------------------------------------|
| Header         | [stack.h](../include/stack.h)  |
| Implementation | [stack.tpp](../src/stack.tpp)  |
| Test           | [stack.cpp](../test/stack.cpp) |