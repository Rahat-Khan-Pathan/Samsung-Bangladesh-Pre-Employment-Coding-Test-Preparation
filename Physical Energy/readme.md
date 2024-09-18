# Physical Energy Problem

## Problem Description

You have a certain amount of energy and need to travel a specific distance. You can choose from five different speeds to travel, each with its own energy cost and time taken per kilometer.

Your goal is to minimize the total time required to cover the distance, ensuring that you do not exceed the available energy.

### Given

1. An initial amount of energy `H`.
2. A total distance `D` to travel.
3. Five speeds, each with associated:
    - **Cost of traveling 1 km** (energy required per km).
    - **Time taken to travel 1 km** (time required per km).

### Input

-   An integer `H` representing the initial amount of energy.
-   An integer `D` representing the total distance to be traveled.
-   A list of five integers representing the energy cost to travel 1 km for each speed.
-   A list of five integers representing the time taken to travel 1 km for each speed.

### Example

#### Input

```
3000
10
4 5 2 3 6
200 210 230 235 215
```
