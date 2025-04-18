// yarinkash1@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"
#include <iostream>

using namespace mat_ns;

TEST_CASE("Basic SquareMat functionality")
{
    SquareMat mat(3); // Create a 3x3 matrix

    CHECK(mat.getSize() == 3); // Test size is correct

    // Set a value and get it
    mat.setValue(1, 2, 42);
    CHECK(mat.getValue(1, 2) == 42);

    // Make sure all other values are still 0
    CHECK(mat.getValue(0, 0) == 0);
    CHECK(mat.getValue(0, 1) == 0);
    CHECK(mat.getValue(0, 2) == 0);
    CHECK(mat.getValue(1, 0) == 0);
    CHECK(mat.getValue(1, 1) == 0);
    CHECK(mat.getValue(2, 0) == 0);
    CHECK(mat.getValue(2, 1) == 0);
    CHECK(mat.getValue(2, 2) == 0);
}

// Check the copy constructor:
TEST_CASE("Copy constructor")
{
    SquareMat mat1(3);
    mat1.setValue(1, 2, 3);

    SquareMat mat2(mat1); // Use the copy constructor

    CHECK(mat2.getSize() == 3);      // Test size is correct
    CHECK(mat2.getValue(1, 2) == 3); // Check copied value

    // Make sure all other values are still 0
    CHECK(mat2.getValue(0, 0) == 0);
    CHECK(mat2.getValue(0, 1) == 0);
    CHECK(mat2.getValue(0, 2) == 0);
    CHECK(mat2.getValue(1, 0) == 0);
    CHECK(mat2.getValue(1, 1) == 0);
    CHECK(mat2.getValue(2, 0) == 0);
    CHECK(mat2.getValue(2, 1) == 0);
    CHECK(mat2.getValue(2, 2) == 0);
}
// Check the assignment operator:
TEST_CASE("Assignment operator")
{
    SquareMat mat1(3);
    mat1.setValue(1, 2, 88);

    SquareMat mat2(3);
    mat2 = mat1; // Use the assignment operator

    CHECK(mat2.getSize() == 3);       // Test size is correct
    CHECK(mat2.getValue(1, 2) == 88); // Check copied value

    // Make sure all other values are still 0
    CHECK(mat2.getValue(0, 0) == 0);
    CHECK(mat2.getValue(0, 1) == 0);
    CHECK(mat2.getValue(0, 2) == 0);
    CHECK(mat2.getValue(1, 0) == 0);
    CHECK(mat2.getValue(1, 1) == 0);
    CHECK(mat2.getValue(2, 0) == 0);
    CHECK(mat2.getValue(2, 1) == 0);
    CHECK(mat2.getValue(2, 2) == 0);
}

// Operator overloads:

// Check the addition operator:
TEST_CASE("Addition operator")
{
    SquareMat mat1(3);
    mat1.setValue(0, 0, 1);
    mat1.setValue(1, 1, 2);
    mat1.setValue(2, 2, 3);

    SquareMat mat2(3);
    mat2.setValue(0, 0, 4);
    mat2.setValue(1, 1, 5);
    mat2.setValue(2, 2, 6);

    SquareMat result = mat1 + mat2;

    CHECK(result.getSize() == 3); // Test size is correct
    CHECK(result.getValue(0, 0) == 5);
    CHECK(result.getValue(1, 1) == 7);
    CHECK(result.getValue(2, 2) == 9);

    // Make sure all other values are still 0
    CHECK(result.getValue(0, 1) == 0);
    CHECK(result.getValue(0, 2) == 0);
    CHECK(result.getValue(1, 0) == 0);
    CHECK(result.getValue(1, 2) == 0);
    CHECK(result.getValue(2, 0) == 0);
    CHECK(result.getValue(2, 1) == 0);
}

// Check the subtraction operator: