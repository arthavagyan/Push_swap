*This project has been created as part of the 42 curriculum by artavagy, tyeghiaz*

# push_swap

---
## Instructions

### Requirements
- `cc` compiler with `-Wall -Wextra -Werror` support

### Compilation

```bash
make
```
---

### Usage

```bash
# Basic sorting
./push_swap 3 1 4 1 5 9 2 6

# With flags
./push_swap --simple 3 1 4 
./push_swap --medium 3 1 4 1 5 9 2 6 
./push_swap --complex 3 1 4 1 5 9 2 6 5 3
./push_swap --adaptive 3 1 4 1 5 9   

# Printing Operetions
./push_swap --bench 3 1 4 1 5 9 2 6

# Running Checker
./push_swap 3 2 1 | ./checker 3 2 1
```

### Allowed Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of stack A |
| `sb` | Swap the first two elements of stack B |
| `ss` | Perform `sa` and `sb` simultaneously |
| `pa` | Push the first element from stack B to stack A |
| `pb` | Push the first element from stack A to stack B |
| `ra` | Rotate stack A (first element becomes last) |
| `rb` | Rotate stack B |
| `rr` | Rotate both stacks |
| `rra` | Reverse rotate stack A |
| `rrb` | Reverse rotate stack B |
| `rrr` | Reverse rotate both stacks |

---
## Algorithms

### Selection Sort — O(n²) (`--simple`)
*Implemented by tyeghiaz*

A basic comparison-based sorting approach. For every position in stack a, the smallest remaining element is located and rotated to the top before being placed. Easy to understand and implement, though its quadratic growth in operations makes it poorly suited for larger inputs.
Best suited for: inputs of roughly 3–10 elements where clarity matters more than speed.

---

### Chunk Sort — O(n√n) (`--medium`)
*Implemented by artavagy*

Splits the input range into chunks of approximately √n in size. Elements are pushed to stack b by chunk order, then pulled back into stack a. By grouping values that are close together, this approach cuts down on the number of rotations compared to a pure insertion sort.
Best suited for: medium-sized inputs (~10–100 elements) where a reasonable trade-off between complexity and performance is acceptable.

---

### Radix Sort — O(n log n) (`--complex`)
*Implemented by tyeghiaz*

Processes integers one bit at a time, starting from the least significant bit and working upward. Each pass distributes elements across stack a and stack b based on the current bit, then recombines them. Since integers are normalized to indices ahead of time, negative numbers are handled without any special cases.
Best suited for: large inputs (100–500+ elements) where keeping the total operation count low is essential. Radix sort fits push_swap particularly well — it maps naturally to pb/pa operations and yields a consistent, predictable number of moves.

---

### Adaptive Strategy (`--adaptive`, default)
*Dispatcher implemented as part of project architecture*

Rather than forcing a single algorithm, the program measures the **disorder** of the input (based on the number of inversions) and selects the most appropriate strategy automatically:

|         Disorder       | Selected algorithm |
|------------------------|--------------------|
|         < 0.2          |    Selection sort  |
| 0.21 <= disorder < 0.5 |      Chunk sort    |
|          >= 0.5        |      Radix sort    |

This ensures optimal performance across all input sizes without requiring the user to manually choose a flag.

## Description

Push_swap is a C program that sorts integers using two stacks (a and b) with minimal operations.  
Stack `a` initially contains a random sequence of positive and/or negative numbers with no duplicates, while stack `b` is empty.  
The program outputs a sequence of operations to sort stack `a` in ascending order using only the allowed Push_swap operations.


---

## Project Goal

Sort a stack of integers in ascending order using two stacks while minimizing the number of Push_swap operations.
Apply different sorting strategies depending on input size and level of disorder:

- --simple — Explicitly runs the Selection Sort O(n²) algorithm.
- --medium — Explicitly runs the Chunk Sort O(n√n) algorithm.
- --complex — Explicitly runs the Radix Sort O(n log n) algorithm.
- --adaptive — Automatically selects a strategy based on how disordered the input is. This is the default behavior.


Produce a valid sequence of Push_swap operations (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr) that sorts the stack as efficiently as possible.

---

## Resources

### Algorithm References

- 42 push_swap subject PDF
- Push_swap — Sorting with Two Stacks — A conceptual walkthrough of the problem and common approaches.
- 42 Push_swap Docs — Official-style breakdown of the rules and available operations.
- Chunk Sort for Push_swap — Detailed explanation of the chunk-based sorting strategy.
- Radix Sort — GeeksforGeeks — Reference for the bitwise radix sort algorithm.
- Selection Sort — GeeksforGeeks — Reference for the selection sort algorithm.
