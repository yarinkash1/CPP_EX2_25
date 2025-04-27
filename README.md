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

- Operator overloads: `+`, `-`, `*`, `%`, `/`, `^`, `++`, `--`, `~`, `[]`, `==`, `!=`, `>`, `<`, `<=`, `>=`, `!`, `<<`, `+=`, `-=`, `*=`, `%=` and `/=`.
*note: some operators can have more than one purpose(different function signature).
- Scalar and matrix operations
- Rule of 3 implemented: destructor, copy constructor, and assignment operator
- Unit tests using doctest framework

## Operator Overloads Explanation

This project overloads a variety of operators to provide natural syntax for matrix operations:

#### Arithmetic Operations
- `+`, `-`, `*`, `/`: Matrix addition, subtraction, multiplication, and division by a scalar or another matrix (when applicable).
- `%`: Modulus operation on each element (element-wise).
- `^`: Matrix exponentiation (raising a matrix to an integer power).
- `+=`, `-=`, `*=`, `/=`, `%=`: In-place arithmetic operations(`/=` and `%=` have both matrix and scalar versions).

#### Unary Operations
- `++`, `--`: Element-wise increment and decrement (prefix and postfix versions).
- `~`: Transpose of the matrix.
- `!`: Calculate the determinant of a matrix.

#### Comparison Operators
- `==`, `!=`: Compare matrices for equality or inequality (with floating point tolerance - see notes below).
- `>`, `<`, `>=`, `<=`: Compare matrices based on their elements total sum.

#### Other Operators
- `[]`: Access elements by index.
- `<<`: Stream output to easily print matrices.

## Notes
- Tolerance for float equality is set to `1e-6`.

## Author

Yarin Keshet 
yarinkash1@gmail.com



