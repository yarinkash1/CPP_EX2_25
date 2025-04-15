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

        // Helper functios:
        bool areOutOfBounds(int i, int j);
        // Helper function to print the matrix:
        void printMatrix() const;
    };
}