#pragma once
#include <iostream>
using namespace std;

namespace mat_ns
{
    class SquareMat
    {
    private:
        int n;
        int **data;

    public:
        SquareMat(int dimension); // Constructor

        // Rule of 3:
        ~SquareMat();                                    // Destructor
        SquareMat(const SquareMat &other_sm);            // Copy constructor (deep copy)
        SquareMat &operator=(const SquareMat &other_sm); // Copy Assignment operator (deep copy)

        // Getters and setters:
        int getSize() const;
        void setValue(int i, int j, int value);
        int getValue(int i, int j);

        // Helper functions:
        bool areOutOfBounds(int i, int j);
        // Helper function to print the matrix:
        void printMatrix() const;

        // Operator overloads:
        SquareMat operator+(const SquareMat &other_sm) const; // Addition operator
        SquareMat operator-(const SquareMat &other_sm) const; // Subtraction operator
        SquareMat operator-() const; // Unary minus operator (negation)
        SquareMat operator*(const SquareMat &other_sm) const; // Multiplication operator
        SquareMat operator*(int scalar) const; // Member function to multiply by a scalar (matrix * scalar)
    };
    SquareMat operator*(int scalar, const SquareMat &matrix); // Non-member function to multiply by a scalar (scalar * matrix)
}