# Camels Transportation Problem

## Problem Description

A man has some camels, and he needs to move all of them to the opposite end of a desert. Each camel has a specific cost associated with traveling from one end to the other.

-   The man can take **two camels at a time** to the opposite end, and the cost of the trip will be the **maximum cost** of the two camels.
-   After reaching the opposite end, the man **returns with one camel**, and the cost of returning is the cost of that particular camel.
-   The goal is to find the **minimum total cost** to move all the camels to the opposite end.

### Example

#### Input

```
2                // Number of test cases
4                // Number of camels in the first test case
1 2 8 9          // Costs of camels in the first test case
6                // Number of camels in the second test case
14 45 73 86 95 98 // Costs of camels in the second test case
```

#### Output

```
16
434
```
