# Binary Search Tree

A binary search tree (BST) is a type of binary tree data structure where the value of each node is:
- Greater than all the values in the node's immediate left subtree
- Less than all the values in the node's immediate right subtree

## Algorithms

### Binary Search

As the name suggests, values within a BST can be easily searched for via binary search. A binary search algorithm works by eliminating have of its search space at each iteration by utilizing the ordered nature of the data structure it applies to.

### Traversal

There are different ways to traverse through a BST (or any binary tree in general). Some traversal methods are in-order traversal, pre-order traversal, and post-order traversal.

## Example

Consider the following BST

```
                 7 
              __/ \__
           __/       \__
         _/             \_
        3                11
      _/ \_            _/  \_
     /     \          /      \
    1       5        9       13
   / \     / \      / \     /  \
  /   \   /   \    /   \   /    \
 0     2 4     6  8    10 12    14
```

where the top node (7) is the root node and the bottom row contains only leaf nodes (left and right children are nullptr).

This BST can be created by inserting the following values in order from left to right

`[7, 3, 1, 5, 0, 2, 4, 6, 11, 9, 13, 8, 11, 12, 14]`

### Binary Search

If we wanted to search for the number 9, we would first hit 7. Given that the nodes in a BST are essentially ordered, we can easily chose where to search next. The number 9 is greater than 7, so we do not need to search the left subtree of 7. Therefore, if 9 exists, it will be present within the right subtree of 7. We move to 11, and since 9 is less than that, we know that 9 must be in 11's left subtree, so don't have to search the right subtree. We move into 11's left subtree and find 9. From here, we can stop searching. Had we chose a value that didn't exist in the tree, such as 15, the algorithm would terminate when reaching 14's right child (nullptr).

### Traversal

When running each of the traversal algorithms, we get the following results

| Algorithm  | Sequence                                           |
|------------|----------------------------------------------------|
| in-order   | `0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14` |
| pre-order  | `7, 3, 1, 0, 2, 5, 4, 6, 11, 9, 8, 10, 13, 12, 14` |
| post-order | `0, 2, 1, 4, 6, 5, 3, 8, 10, 9, 12, 14, 13, 11, 7` |

## Code

| File           | Location                                                 |
|----------------|----------------------------------------------------------|
| Header         | [binary-search-tree.h](../include/binary-search-tree.h)  |
| Implementation | [binary-search-tree.tpp](../src/binary-search-tree.tpp)  |
| Test           | [binary-search-tree.cpp](../test/binary-search-tree.cpp) |
