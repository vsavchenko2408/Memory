# Smart Pointers

A lightweight, header-only implementation of C++ smart pointers built from scratch without using the standard library's memory management utilities.

## Overview

This project implements three smart pointer types that mirror the behavior of their `std::` counterparts:

- `Unique_ptr<T>` — exclusive ownership, non-copyable
- `Shared_ptr<T>` — shared ownership via reference counting
- `Weak_ptr<T>` — non-owning observer, breaks circular references

Built as a learning project to deeply understand memory management, move semantics, and RAII in modern C++.

## Project Structure

```
include/
  memory.h        # includes all three smart pointer headers
  unique_ptr.h
  shared_ptr.h
  weak_ptr.h
src/
  main.cpp
```

## Requirements

- C++11 or later
- Any standard C++ compiler (GCC, Clang, MSVC)

## Usage

Include the main header:

```cpp
#include "memory.h"
```

### Unique_ptr

Exclusive ownership — only one pointer can own the object at a time.

```cpp
Unique_ptr<int> ptr(new int(42));
Unique_ptr<int> ptr2(42);         // allocates internally

*ptr = 100;
int* raw = ptr.get();

// Move ownership
Unique_ptr<int> ptr3 = std::move(ptr);
// ptr is now nullptr
```

### Shared_ptr

Shared ownership — multiple pointers can refer to the same object. The object is destroyed when the last `Shared_ptr` goes out of scope.

```cpp
Shared_ptr<int> a(new int(42));
Shared_ptr<int> b = a;     // both point to the same object

*a = 100;
std::cout << *b;           // 100

// Object is deleted only when both a and b are destroyed
```

### Weak_ptr

Non-owning reference to a `Shared_ptr`-managed object. Does not affect the reference count. Use `lock()` to safely access the object.

```cpp
Shared_ptr<int> sp(32);
Weak_ptr<int> wp(sp);

if (!wp.expired()) {
    auto locked = wp.lock();  // returns a Shared_ptr
    std::cout << *locked;     // 32
}

// After sp is destroyed:
// wp.expired() == true
// wp.lock().get() == nullptr
```

### Breaking Circular References

The primary use case for `Weak_ptr`:

```cpp
struct Node {
    int value;
    Shared_ptr<Node> next;
    Weak_ptr<Node> prev;   // Shared_ptr here would cause a memory leak
};
```

## Implementation Details

- `Unique_ptr` — disables copy, implements move semantics
- `Shared_ptr` — maintains a shared reference count (`_shared`) and weak count (`_weak`) allocated on the heap
- `Weak_ptr` — accesses the same control block as `Shared_ptr` via a `friend` declaration; increments only the weak count
- Control block (`_shared`, `_weak`) is deleted only when both counts reach zero
- Object (`_data`) is deleted when `_shared` reaches zero, regardless of remaining weak references

## Readme was created Cloude