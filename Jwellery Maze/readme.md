# Jewellery Problem

## Problem Description

You are given a maze with one entrance and one exit. Jewels are placed in some passages of the maze. Your goal is to collect the maximum number of jewels without traversing the same passage more than once.

-   **Entrance**: Located at the upper-most left passage of the maze.
-   **Exit**: Located at the lower-most right passage of the maze.
-   **0**: Represents a passage.
-   **1**: Represents a wall.
-   **2**: Represents a location of a jewel.
-   **3**: Represents the path taken by the solution.

## Input

-   The first line contains `T`, the number of test cases (1 ≤ T ≤ 10).
-   For each test case:
    -   The first line contains the size of the maze, `N` (1 ≤ N ≤ 10).
    -   The next `N` lines contain the maze description:
        -   `0` indicates a passage.
        -   `1` indicates a wall.
        -   `2` indicates a jewel.

## Output

For each test case:

1. Print the maze with the path taken marked as `3`.
2. Print the greatest number of jewels collected.

### Example

#### Input

```
2
5
0 0 0 2 0
2 1 0 1 2
0 0 2 2 0
0 1 0 1 2
2 0 0 0 0
6
0 1 2 1 0 0
0 1 0 0 0 1
0 1 2 1 2 1
0 2 0 1 0 2
0 1 0 1 0 1
2 0 2 1 0 0
```

#### Output

```
Case #1
3 0 0 2 0
3 1 0 1 2
3 0 2 2 0
3 1 0 1 2
2 0 0 0 0
6

Case #2
3 1 2 1 0 0
3 1 0 0 0 1
3 1 2 1 2 1
3 2 0 1 0 2
3 1 0 1 0 1
3 3 2 1 0 0
4
```
