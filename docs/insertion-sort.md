# Insertion Sort

Insertion Sort is a sorting algorithm that iterates through each element of the input, treating each one as a key. From each key, Insertion Sort walks backwards through all elements greater than the key and moves them forward by one. The backwards walk stops when an element is reached that is less than or equal to the key. The next element is chosen as the key and the process repeats.

Insertion Sort is considered conceptually to be one of the simplest sorting algorithms, though it is inefficient compared to other sorting techniques. Given an input size of *n*, the worst case complexity is O(n^2) operations (comparisons/swaps).

## Example

The key (starting at index 1, denoted by `k`) is used to compare the preceeding elements (denoted by `c`, the current preceeding element).
```
  c   k 
  |   |
  V   V
+---+---+---+---+---+
| 4 | 2 | 3 | 1 | 0 |
+---+---+---+---+---+

      c   k 
      |   |
      V   V
+---+---+---+---+---+
| 2 | 4 | 3 | 1 | 0 |
+---+---+---+---+---+

  c       k 
  |       |
  V       V
+---+---+---+---+---+
| 2 | 4 | 4 | 1 | 0 |
+---+---+---+---+---+

          c   k 
          |   |
          V   V
+---+---+---+---+---+
| 2 | 3 | 4 | 1 | 0 |
+---+---+---+---+---+

      c       k 
      |       |
      V       V
+---+---+---+---+---+
| 2 | 3 | 4 | 4 | 0 |
+---+---+---+---+---+

  c           k 
  |           |
  V           V
+---+---+---+---+---+
| 2 | 3 | 3 | 4 | 0 |
+---+---+---+---+---+

              c   k 
              |   |
              V   V
+---+---+---+---+---+
| 1 | 2 | 3 | 4 | 0 |
+---+---+---+---+---+

          c       k 
          |       |
          V       V
+---+---+---+---+---+
| 1 | 2 | 3 | 4 | 4 |
+---+---+---+---+---+

      c           k 
      |           |
      V           V
+---+---+---+---+---+
| 1 | 2 | 3 | 3 | 4 |
+---+---+---+---+---+

  c               k 
  |               |
  V               V
+---+---+---+---+---+
| 1 | 2 | 2 | 3 | 4 |
+---+---+---+---+---+



        Done
+---+---+---+---+---+
| 0 | 1 | 2 | 3 | 4 |
+---+---+---+---+---+
```

## Code

| File           | Location                                            |
|----------------|-----------------------------------------------------|
| Header         | [insertion-sort.hpp](../include/insertion-sort.hpp) |
| Implementation | [insertion-sort.tpp](../src/insertion-sort.tpp)     |
| Test           | [insertion-sort.cpp](../test/insertion-sort.cpp)    |

