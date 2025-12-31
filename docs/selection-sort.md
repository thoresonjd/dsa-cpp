# Selection Sort

Selection Sort is a sorting algorithm that works by creating a sorted sublist at the beginning of the list by iteratively swapping the first element in the unsorted sublist at the end of the list with the minimum element in the unsorted sublist.

Selection Sort is considered conceptually to be one of the simplest sorting algorithms, though it is inefficient compared to other sorting techniques. Given an input size of *n*, the worst case complexity is O(n^2) comparisons and O(n) swaps.

## Example

The first unsorted element (`i`) is compared with the succeeding unsorted elements (each one denoted by `j`). The minimum element (`m`) is swapped with `i` when all elements seen by `j` are exhausted.
```
 i,m
  |
  V 
+---+---+---+---+---+
| 4 | 2 | 3 | 1 | 0 |
+---+---+---+---+---+

  i  j,m
  |   |
  V   V
+---+---+---+---+---+
| 4 | 2 | 3 | 1 | 0 |
+---+---+---+---+---+

  i   m   j
  |   |   |
  V   V   V
+---+---+---+---+---+
| 4 | 2 | 3 | 1 | 0 |
+---+---+---+---+---+

  i          j,m
  |           |
  V           V
+---+---+---+---+---+
| 4 | 2 | 3 | 1 | 0 |
+---+---+---+---+---+

  i              j,m
  |               |
  V               V
+---+---+---+---+---+
| 4 | 2 | 3 | 1 | 0 |
+---+---+---+---+---+

     i,m
      |
      V
+---+---+---+---+---+
| 0 | 2 | 3 | 1 | 4 |
+---+---+---+---+---+

     i,m  j
      |   |
      V   V
+---+---+---+---+---+
| 0 | 2 | 3 | 1 | 4 |
+---+---+---+---+---+

      i      j,m
      |       |
      V       V
+---+---+---+---+---+
| 0 | 2 | 3 | 1 | 4 |
+---+---+---+---+---+

      i       m   j
      |       |   |
      V       V   V
+---+---+---+---+---+
| 0 | 2 | 3 | 1 | 4 |
+---+---+---+---+---+

         i,m
          | 
          V 
+---+---+---+---+---+
| 0 | 1 | 3 | 2 | 4 |
+---+---+---+---+---+

          i  j,m
          |   |
          V   V
+---+---+---+---+---+
| 0 | 1 | 3 | 2 | 4 |
+---+---+---+---+---+

          i   m   j
          |   |   |
          V   V   V
+---+---+---+---+---+
| 0 | 1 | 3 | 2 | 4 |
+---+---+---+---+---+

             i,m
              |
              V
+---+---+---+---+---+
| 0 | 1 | 2 | 3 | 4 |
+---+---+---+---+---+

             i,m  j
              |   |
              V   V
+---+---+---+---+---+
| 0 | 1 | 2 | 3 | 4 |
+---+---+---+---+---+



		Done
+---+---+---+---+---+
| 0 | 1 | 2 | 3 | 4 |
+---+---+---+---+---+
```

## Code 

| File           | Location                                            |
|----------------|-----------------------------------------------------|
| Header         | [selection-sort.hpp](../include/selection-sort.hpp) |
| Implementation | [selection-sort.tpp](../src/selection-sort.tpp)     |
| Test           | [selection-sort.cpp](../test/selection-sort.cpp)    |

