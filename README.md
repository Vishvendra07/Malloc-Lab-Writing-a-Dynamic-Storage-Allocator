# Malloc Lab: Writing a Dynamic Storage Allocator

## Introduction

This project involves implementing a **dynamic memory allocator** in C, providing functionalities similar to the standard `malloc`, `free`, and `realloc` functions. The goal is to develop a space-efficient and performant memory management system that adheres to the specified rules and passes rigorous testing.

The implementation includes:
- `malloc`: Allocates memory blocks.
- `free`: Frees previously allocated blocks.
- `realloc`: Adjusts the size of an allocated block.
- `mm_checkheap`: A heap consistency checker for debugging.

You will implement these functions in **`mm.c`**.

---

## Features

### Dynamic Allocator Functions

1. **`mm_init`**: Initializes the heap before any memory operations.
2. **`malloc`**: Allocates memory blocks aligned to 16 bytes.
3. **`free`**: Frees memory previously allocated by `malloc` or `realloc`.
4. **`realloc`**: Resizes allocated memory, preserving existing data.
5. **`mm_checkheap`**: Validates heap consistency and helps identify bugs.

### Heap Consistency Checker

The `mm_checkheap` function ensures the integrity of the memory heap by verifying:
- All free blocks are marked as free.
- Contiguous free blocks are coalesced.
- Free blocks are listed in the free list.
- No allocated blocks overlap.
- Pointers in heap blocks are valid.

---

## Project Structure

### Core Files

- **`mm.c`**: Main implementation file (modifiable).
- **`memlib.c`**: Memory system simulator for dynamic memory allocation.
- **`mdriver.c`**: Test harness for evaluating the implementation.

### Supporting Files

- **`Makefile`**: Build and test commands.
- **`traces`**: Contains trace files for testing the allocator.
- **`throughputs.txt`**: Tracks throughput results.

---

## Implementation Guidelines

1. **Alignment**:
   - Ensure all memory blocks are 16-byte aligned.

2. **Free List Management**:
   - Efficiently manage free blocks to minimize fragmentation.
   - Implement block coalescing where possible.

3. **Heap Checker**:
   - Validate heap integrity after every operation using `mm_checkheap`.

4. **Helper Functions**:
   - Use static helper functions to manage pointer arithmetic and bit manipulation.

5. **Restrictions**:
   - No direct use of system memory functions like `sbrk` or `malloc`.
   - No macros; use static functions for inline optimizations.

---

## Building and Testing

### Build Commands

- **Build the Project**:
  ```bash
  make
  ```

- **Build in Debug Mode**:
  ```bash
  make debug
  ```

### Running Tests

- **Run All Tests**:
  ```bash
  make test
  ```

- **Run a Specific Trace File**:
  ```bash
  ./mdriver -f traces/<tracefile.rep>
  ```

- **Display Options**:
  ```bash
  ./mdriver -h
  ```

### Debugging

Use **GDB** to debug crashes:
```bash
gdb mdriver
```

To check memory integrity:
```bash
valgrind --leak-check=full ./mdriver -f traces/<tracefile.rep>
```

---

## Evaluation Criteria

1. **Functionality**:
   - Correctness of `malloc`, `free`, and `realloc`.
   - Passes all trace files during testing.

2. **Performance**:
   - Space Utilization (60%): Ratio of allocated memory to heap size.
   - Throughput (40%): Operations completed per second.

3. **Heap Checker**:
   - Validates heap integrity.
   - Assists in debugging memory issues.

4. **Code Quality**:
   - Clear comments and modular design.
   - Adherence to the design specifications.

---

## Debugging Tips

1. **Draw Memory Layouts**:
   - Visualize heap structure to debug issues.

2. **Encapsulate Pointer Operations**:
   - Use static functions for clarity and reuse.

3. **Use Small Trace Files**:
   - Start with `-short.rep` files for initial debugging.

4. **Utilize Debugging Tools**:
   - **GDB** for runtime analysis.
   - **Valgrind** for memory checks.

---

## Resources

- [Linux sbrk Documentation](https://man7.org/linux/man-pages/man2/sbrk.2.html)
- [Valgrind Documentation](https://valgrind.org/)
- [Dynamic Memory Allocation Examples](https://csapp.cs.cmu.edu/)

---

## Author
Implemented by **Vishvendra Reddy Bhoomidi** as part of the Malloc Lab course by Timothy Zhu.
