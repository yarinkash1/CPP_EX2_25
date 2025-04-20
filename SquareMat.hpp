#pragma once
#include <iostream>
#include <cmath>
#define TOLERANCE 1e-6  // Define the tolerance value
using namespace std;

namespace mat_ns
{
    class SquareMat
    {
    private:
        int n;
        double **data;

    public:
        SquareMat(int dimension); // Constructor

        // Rule of 3:

        ~SquareMat();                                    // Destructor
        SquareMat(const SquareMat &other_sm);            // Copy constructor (deep copy)
        SquareMat &operator=(const SquareMat &other_sm); // Copy Assignment operator (deep copy)

        // Getters and setters:

        int getSize() const;
        void setValue(int i, int j, double value);
        void setValue(int i, int j, int value); // Function overload to accept int, and implicitly convert to double
        double getValue(int i, int j);

        // Helper functions:

        bool areOutOfBounds(int i, int j);        // Helper function to determine if the input indexes are out of bounds
        void printMatrix(ostream &os) const;      // Helper function to print the matrix
        static SquareMat identity(int dimension); // Helper function to create identity matrix
        double matrixSum() const;                    // Helper function to calculate the sum of all elements in the matrix
        static bool isEqual(double a, double b); // Helper function to check for double equality
        static double myAbs(double value);       // Helper function to calculate absolute value

        // Operator overloads:
        SquareMat operator+(const SquareMat &other_sm) const;             // Addition operator
        SquareMat operator-(const SquareMat &other_sm) const;             // Subtraction operator
        SquareMat operator-() const;                                      // Unary minus operator (negation)
        SquareMat operator*(const SquareMat &other_sm) const;             // Multiplication operator
        SquareMat operator*(double scalar) const;                            // Member function to multiply by a scalar (matrix * scalar)
        SquareMat operator%(const SquareMat &other_sm) const;             // Element-wise multiplication operator
        SquareMat operator%(double scalar) const;                            // Modulo operator with scalar: applies modulo to each element in the matrix (element % scalar)
        SquareMat operator/(double scalar) const;                            // Division operator with scalar: applies division to each element in the matrix (element / scalar)
        SquareMat operator^(double scalar) const;                            // Unary power operator: multiply the matrix by itself 'scalar' times
        SquareMat &operator++();                                          // Pre-increment operator: increment each element in the matrix by 1
        SquareMat operator++(int);                                        // Post-increment operator: increment each element in the matrix by 1
        SquareMat &operator--();                                          // Pre-decrement operator: decrement each element in the matrix by 1
        SquareMat operator--(int);                                        // Post-decrement operator: decrement each element in the matrix by 1
        SquareMat operator~() const;                                      // Transpose operator: transpose the matrix
        double* operator[](int i);                                           // For write access (non-const)
        const double* operator[](int i) const;                               // For read-only access (const objects)
        bool operator==(const SquareMat &other_sm) const;                 // Equality operator: checks if two matrices are equal
        bool operator!=(const SquareMat &other_sm) const;                 // Inequality operator: checks if two matrices are not equal
        bool operator>(const SquareMat &other_sm) const;                  // Greater than operator: checks if the sum of elements in this matrix is greater than the other matrix
        bool operator<(const SquareMat &other_sm) const;                  // Less than operator: checks if the sum of elements in this matrix is less than the other matrix
        bool operator>=(const SquareMat &other_sm) const;                 // Greater than or equal to operator: checks if the sum of elements in this matrix is greater than or equal to the other matrix
        bool operator<=(const SquareMat &other_sm) const;                 // Less than or equal to operator: checks if the sum of elements in this matrix is less than or equal to the other matrix
        double operator!() const;                                            // calculate the determinant of the matrix
        friend ostream &operator<<(ostream &os, const SquareMat &matrix); // Output operator: prints the matrix to the console
        SquareMat &operator+=(const SquareMat &other_sm);                 // Adds another matrix to this matrix
        SquareMat &operator-=(const SquareMat &other_sm);                 // Subtracts another matrix from this matrix
        SquareMat &operator*=(const SquareMat &other);                    // Multiplies this matrix by another matrix
        SquareMat &operator/=(const SquareMat &other);                    // Divides this matrix by another matrix
        SquareMat &operator%=(const SquareMat &other);                    // Applies element-wise modulo operation between this matrix and another matrix
    };
    SquareMat operator*(double scalar, const SquareMat &matrix); // Non-member function to multiply by a scalar (scalar * matrix)
}