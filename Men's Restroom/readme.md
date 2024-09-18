# Men's Restroom Problem

## Problem Description

In a restroom with a certain number of stalls, visitors prefer to maximize their distance from already occupied stalls. The strategy is to occupy the middle of the longest sequence of unoccupied stalls.

Given the number of stalls, simulate the process of visitors entering the restroom and occupying stalls according to the described strategy.

## Input

-   The input consists of a single integer representing the number of stalls.

### Example

#### Input

```
10
```

#### Output

```
_ _ _ _ _ X _ _ _ _
_ _ _ _ X _ _ X _ _
_ X _ _ X _ _ X _ _
_ X _ _ X _ _ X X _
_ X _ _ X X _ X X _
_ X X _ X X _ X X _
_ X X _ X X _ X X X
_ X X _ X X X X X X
_ X X X X X X X X X
X X X X X X X X X X
```

## Output Format

-   Each line represents the stalls' status after each visitor occupies a stall.
-   Use `_` for unoccupied stalls and `X` for occupied stalls.
