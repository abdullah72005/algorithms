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
    Initialize rlD = 0   // Sum of right-to-left diagonal'
    rlD =  calcRightSide(A, n-1,0)
    lrD =  calcLeftSide(A , n-1)
    Return absolute value of (lrD - rlD)

Function calcRightSide(matrix A,integer n,integer m):
    Initialize rlD = 0
    IF n == 0 Do
        Return A[n][m]
    calcRightSide(A, n-1, m+1)


Function calcLeftSide(matrix A,integer n):
    Initialize lrD = 0
    IF n == 0 Do
        Return A[n][n]
    calcLeftSide(A, n-1)
    Return A[n][n] + lrD;
```

---

## 2. Algorithm Analysis

Both functions compute the absolute difference between:
- The **left-to-right diagonal** lrD
- The **right-to-left diagonal** rlD

### `calcDD1`
- Combines both diagonal computations in a **single loop** using index `i`.
- More concise and efficient.

### `calcDD2`
- Separates the diagonals:
  - Each one goes recursively over itself until n reaches 0
  - the calcRightSide calculates the right-left diagonal 
  - it uses m to point to its horizontal and n to point to its vertical
  - the calcLeftSide calculates the left-right diagonal 
  - it uses n to point both vertical and horizontal location
- Functionally correct but less elegant.

---

## 3. Time Complexity Analysis and Comparison

Let `n` be the size of the matrix (rows = columns).

### Time Complexity
- `calcDD1`: O(n) — One loop
- `calcDD2`: O(n) — Two loops of O(n) each

### Space Complexity
- `calcDD1` use constant auxiliary space: **O(1)**
- `calcDD2` use two recursive function of O(n) each:  **O(n)**

### Comparison Table
| Metric              | `calcDD1`         | `calcDD2`              |
|---------------------|-------------------|------------------------|
| Time Complexity     | O(n)              | O(n)                   |
| Space Complexity    | O(1)              | O(n)                   |
| Code Readability    | Simple & clean    | Slightly verbose       |
| Efficiency          | Single loop       | goes recursivley twice |


