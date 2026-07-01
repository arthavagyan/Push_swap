# 📈 Push_Swap — The Art of Sorting with Two Stacks

<p align="center">
  <img src="https://img.shields.io/badge/Score-125%2F100-success?style=for-the-badge&logo=42" alt="Score 125/100" />
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge" alt="Language C" />
  <img src="https://img.shields.io/badge/Status-Completed-brightgreen?style=for-the-badge" alt="Status Completed" />
</p>

---

## 📖 Description

**Push_swap** is a highly efficient C program that sorts data on a stack, using a limited set of instructions, with the lowest possible number of actions. 

You start with two stacks: **Stack A** (full of random numbers) and **Stack B** (empty). The goal is to sort everything into Stack A in ascending order using specific operations like swaps, pushes, and rotations.

---

## 🛠️ Installation & Usage

### ⚙️ Compilation
To build the project, run:
```bash
make
```

### 🖥️ Running the Program
You can use different flags to choose a specific sorting algorithm:

```bash
# Basic sorting (using the default adaptive strategy)
./push_swap 3 1 4 1 5 9 2 6

# Force a specific algorithm
./push_swap --simple 3 1 4       # Selection Sort
./push_swap --medium 3 1 4 1 5   # Chunk Sort
./push_swap --complex 8 2 4 9 1  # Radix Sort

# Check if the result is correct (if you have a checker)
./push_swap 3 2 1 | ./checker 3 2 1
```

---

## 🔄 Allowed Operations

| Op | Description |
| :--- | :--- |
| `sa` / `sb` | **Swap** the first two elements of stack A or B. |
| `ss` | Swap both stacks at the same time. |
| `pa` / `pb` | **Push** the top element from one stack to another. |
| `ra` / `rb` | **Rotate** stack (first element becomes last). |
| `rr` | Rotate both stacks at the same time. |
| `rra` / `rrb` | **Reverse Rotate** (last element becomes first). |
| `rrr` | Reverse rotate both stacks at the same time. |

---

## 🧠 Sorting Algorithms

My partner (**tyeghiaz**) and I (**artavagy**) implemented several strategies to handle different input sizes:

### 🟢 Selection Sort — O(n²) (`--simple`)

Finds the smallest number and moves it to the top. It is very simple and perfect for small sets (3–10 numbers).

### 🟡 Chunk Sort — O(n√n) (`--medium`)

Splits the numbers into "chunks" (groups). By pushing groups of similar values to Stack B first, we reduce the total number of moves. Best for 10–100 numbers.

### 🔴 Radix Sort — O(n log n) (`--complex`)

A bitwise sorting algorithm. It sorts numbers by looking at their binary digits. This is the most consistent and fast method for very large sets (100–500+ numbers).

### ⚡ Adaptive Strategy (`--adaptive`)
The program automatically calculates the **disorder** (how messy the list is) and picks the best algorithm:

| Disorder Level | Selected Algorithm |
| :--- | :--- |
| **Low** (< 0.2) | Selection Sort |
| **Medium** (0.21 - 0.5) | Chunk Sort |
| **High** (> 0.5) | Radix Sort |

---

## 👨‍💻 Authors

This project was a collaboration between:
- **artavagy**
- **tyeghiaz**

Created as part of the 42 Yerevan curriculum.

<div align="center">

  [![GitHub Profile](https://img.shields.io/badge/GitHub-artavagy-181717?style=for-the-badge&logo=github)](https://github.com/arthavagyan)
  [![GitHub Profile](https://img.shields.io/badge/GitHub-tyeghiaz-181717?style=for-the-badge&logo=github)](https://github.com/tatevyeghiazaryan05)

</div>
