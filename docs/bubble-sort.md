# Bubble Sort

Bubble Sort is a sorting algorithm that iterates through each element of the input, comparing adjacent elements and swapping if in the incorrect order, repeatedly until the input is sorted.

Bubble Sort is considered conceptually to be one of the simplest sorting algorithms, though it is inefficient compared to other sorting techniques. Assuming a sorted input list in non-descending, the algorithm works by shifting the largest values toward the end of the list one at a time. Hence, the largest value is the first to be moved to the last index, then the second largest is moved to the second to last index, and so forth. Given an input size of *n*, the worst case complexity is O(n^2) operations (comparisons/swaps).

## Example

The current element (`c`) is compared to the next index (`c + 1`).

```
  c
  |
  V
+---+---+---+---+---+
| 4 | 2 | 3 | 1 | 0 |
+---+---+---+---+---+

      c
      |
      V
+---+---+---+---+---+
| 2 | 4 | 3 | 1 | 0 |
+---+---+---+---+---+

          c
          |
          V
+---+---+---+---+---+
| 2 | 3 | 4 | 1 | 0 |
+---+---+---+---+---+

              c
              |
              V
+---+---+---+---+---+
| 2 | 3 | 1 | 4 | 0 |
+---+---+---+---+---+

                  c
                  |
                  V
+---+---+---+---+---+
| 2 | 3 | 1 | 0 | 4 |
+---+---+---+---+---+

  c
  |
  V
+---+---+---+---+---+
| 2 | 3 | 1 | 0 | 4 |
+---+---+---+---+---+

      c
      |
      V
+---+---+---+---+---+
| 2 | 3 | 1 | 0 | 4 |
+---+---+---+---+---+

          c
          |
          V
+---+---+---+---+---+
| 2 | 1 | 3 | 0 | 4 |
+---+---+---+---+---+

              c
              |
              V
+---+---+---+---+---+
| 2 | 1 | 0 | 3 | 4 |
+---+---+---+---+---+

  c
  |
  V
+---+---+---+---+---+
| 2 | 1 | 0 | 3 | 4 |
+---+---+---+---+---+

      c
      |
      V
+---+---+---+---+---+
| 1 | 2 | 0 | 3 | 4 |
+---+---+---+---+---+

          c
          |
          V
+---+---+---+---+---+
| 1 | 0 | 2 | 3 | 4 |
+---+---+---+---+---+

  c
  |
  V
+---+---+---+---+---+
| 1 | 0 | 2 | 3 | 4 |
+---+---+---+---+---+

      c
      |
      V
+---+---+---+---+---+
| 0 | 1 | 2 | 3 | 4 |
+---+---+---+---+---+
```

## Code

| File           | Location                                      |
|----------------|-----------------------------------------------|
| Header         | [bubble-sort.hpp](../include/bubble-sort.hpp) |
| Implementation | [bubble-sort.tpp](../src/bubble-sort.tpp)     |
| Test           | [bubble-sort.cpp](../test/bubble-sort.cpp)    |

