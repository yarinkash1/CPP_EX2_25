# SquareMat - Matrix Operations in C++

This project implements a `SquareMat` class in C++ that provides support for square matrices with a wide range of operator overloads, including arithmetic operations, transpose, comparison, determinant etc...
There are also tests for each operator overload covering all edge cases.

## Build Instructions

To build the project, make sure you have a C++ compiler (e.g. `g++`) and `make` installed.

### Compile the main executable(the demo)

```bash
make all
./main_exe
```

### Run the main program

```bash
./main_exe
```

### Build the tests

```bash
make test
```

### Run the tests

```bash
./test_exe
```

## Project Structure

```
├── main.cpp            # Main executable (demo code)
├── SquareMatTest.cpp   # Unit tests using doctest
├── SquareMat.hpp       # Matrix class header
├── SquareMat.cpp       # Matrix class implementation
├── Makefile            # Build script
└── README.md           # Project documentation (this file)
```

## Features

- Operator overloads: `+`, `-`, `*`, `%`, `/`, `^`, `++`, `--`, `~`, `[]`, `==`, `!=`, `>`, `<`, `<=`, `>=`, `!`, `<<`, `+=`, `-=`, `*=` and `/=`.
*note: some operators can have more than one purpose(different function signature).
- Scalar and matrix operations
- Rule of 3 implemented: destructor, copy constructor, and assignment operator
- Unit tests using doctest framework

## Notes
- Tolerance for float equality is set to `1e-6`.

## Author

Yarin Keshet 
yarinkash1@gmail.com



