# Frog Jump Problem

## Problem Description

Given a 2D matrix where:

-   `1` represents the places where the frog can jump.
-   `0` represents empty spaces.

The frog can:

-   Move horizontally without any cost (only on `1`s).
-   Move vertically with a cost equal to the number of jumps taken.

Given a source and destination within the matrix, the frog needs to reach the destination while minimizing the total vertical jump cost.

## Input

-   The matrix size and its elements.
-   The source and destination coordinates.

### Example

#### Input

```
5
0 1 1 0 1
1 0 0 1 0
1 0 0 0 1
0 1 0 1 1
1 0 1 1 1
4 2 1 3
```

#### Output

```
2
```
