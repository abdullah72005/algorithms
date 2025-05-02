# Diagonal Difference - Documentation

## Problem Statement
Given a square matrix, calculate the absolute difference between the sums of its two diagonals.

### Example Input
```
11 2 4
4 5 6
10 8 -12
```

### Output
```
15
```

## 1. Pseudocode of Algorithms

### Function: `calcDD1`
```java
Function calcDD1(matrix A, integer n):
    Initialize lrD = 0   // Sum of left-to-right diagonal
    Initialize rlD = 0   // Sum of right-to-left diagonal

    For i from 0 to n-1:
        lrD = lrD + A[i][i]
        rlD = rlD + A[i][n - 1 - i]

    Return absolute value of (lrD - rlD)
```

### Function: `calcDD2`
```java
Function calcDD2(matrix A, integer n):
    Initialize lrD = 0   // Sum of left-to-right diagonal
    Initialize rlD = 0   // Sum of right-to-left diagonal

    For i from 0 to n-1:
        lrD = lrD + A[i][i]

    Set r = 0, c = n - 1
    While r < n and c >= 0:
        rlD = rlD + A[r][c]
        r = r + 1
        c = c - 1

    Return absolute value of (lrD - rlD)
```

---

## 2. Algorithm Analysis

Both functions compute the absolute difference between:
- The **left-to-right diagonal** (A[i][i])
- The **right-to-left diagonal** (A[i][n - i - 1])

### `calcDD1`
- Combines both diagonal computations in a **single loop** using index `i`.
- More concise and efficient.

### `calcDD2`
- Separates the diagonals:
  - First loop for the left-to-right diagonal.
  - Second loop using two pointers (`r` and `c`) for the right-to-left.
- Functionally correct but less elegant.

---

## 3. Time Complexity Analysis and Comparison

Let `n` be the size of the matrix (rows = columns).

### Time Complexity
- `calcDD1`: O(n) — One loop
- `calcDD2`: O(n) — Two loops of O(n) each

### Space Complexity
- Both use constant auxiliary space: **O(1)**

### Comparison Table
| Metric              | `calcDD1`         | `calcDD2`              |
|---------------------|-------------------|------------------------|
| Time Complexity     | O(n)              | O(n)                   |
| Space Complexity    | O(1)              | O(1)                   |
| Code Readability    | Simple & clean  | Slightly verbose     |
| Efficiency          | Single loop     | Redundant second loop |


