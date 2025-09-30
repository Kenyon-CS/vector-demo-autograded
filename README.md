# Vector Demo (Autograded via GitHub Classroom)

This tiny assignment is meant to get you comfortable with **GitHub Classroom**, **Makefiles**, and **autograded tests** before the midterm.

## Problem (very simple)
Implement two small functions in `src/vector_tasks.cpp`:

1. `int sum_at_even_indices(const std::vector<int>& v);`  
   Return the sum of elements at indices 0, 2, 4, ...

2. `std::vector<int> doubled(const std::vector<int>& v);`  
   Return a new vector where each element is doubled (e.g., `[1, -3, 4] -> [2, -6, 8]`).

### Rules
- Use the C++17 STL `std::vector`.  
- Do **not** use external libraries.  
- Keep it simple: a normal `for` loop or range-based loop is fine.

## Build & Run (locally)
```bash
make               # builds tests and demo
./build/test_vector
./build/demo "1 2 3 -4"
```

Or:
```bash
make run-tests
make run-demo ARGS="1 2 3 -4"
```

### Optional: Sanitizers (local)
```bash
make asan
./build/test_vector
```

## What to edit
Open `src/vector_tasks.cpp` and complete the `// TODO` sections. The stub compiles but **fails tests** until you implement it correctly.

## Grading flow
- Push your changes — GitHub Actions runs the tests automatically.  
- ✅ Green check = tests passed; ❌ Red X = something failed (click the CI log).

## Hints
- For `sum_at_even_indices`, iterate `i += 2`. Empty vectors are fine (sum is 0).  
- For `doubled`, create a result vector, reserve the right size, and push back `2 * x` for each element.

Good luck!# vector-demo-autograded
