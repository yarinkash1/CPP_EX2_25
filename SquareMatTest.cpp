// yarinkash1@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"
#include <iostream>

using namespace mat_ns;

TEST_CASE("Basic SquareMat functionality")
{
    // Check matrix creation with 0 dimension or less throws string:
    CHECK_THROWS(SquareMat(0));
    CHECK_THROWS(SquareMat(-1));

    // Check matrix creation with positive dimension of type double converts to int:
    SquareMat mat_with_type_double_dimension1(3.5);
    SquareMat mat_with_type_double_dimension2(5.76543);
    CHECK(mat_with_type_double_dimension1.getSize() == 3);
    CHECK(mat_with_type_double_dimension2.getSize() == 5);

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

    // Check out of bounds access throws string:
    CHECK_THROWS(mat.getValue(3, 3));
    CHECK_THROWS(mat.getValue(-1, -1));
    CHECK_THROWS(mat.setValue(3, 3, 5.6));
    CHECK_THROWS(mat.setValue(-1, -1, 5.6));
    CHECK_THROWS(mat.setValue(0, 3.77777, 5.6444));

    // Test the write access operator(non-const):
    mat[0][0] = 1;
    mat[1][1] = 2;
    mat[2][2] = 3;
    CHECK(mat.getValue(0, 0) == 1);
    CHECK(mat.getValue(1, 1) == 2);
    CHECK(mat.getValue(2, 2) == 3);
    // Test the read-only access operator(const):
    const SquareMat const_mat = mat;
    CHECK(const_mat[0][0] == 1);
    CHECK(const_mat[1][1] == 2);
    CHECK(const_mat[2][2] == 3);
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
    mat1.setValue(1, 1, -2);
    mat1.setValue(2, 2, 3.1);

    SquareMat mat2(3);
    mat2.setValue(0, 0, 4);
    mat2.setValue(1, 1, 5);
    mat2.setValue(2, 2, 6.1);

    SquareMat result = mat1 + mat2;

    CHECK(result.getValue(0, 0) == 5);
    CHECK(result.getValue(1, 1) == 3);
    CHECK(result.getValue(2, 2) == 9.2); 

    // Make sure all other values are still 0
    CHECK(result.getValue(0, 1) == 0);
    CHECK(result.getValue(0, 2) == 0);
    CHECK(result.getValue(1, 0) == 0);
    CHECK(result.getValue(1, 2) == 0);
    CHECK(result.getValue(2, 0) == 0);
    CHECK(result.getValue(2, 1) == 0);
}

// Check the subtraction operator:
TEST_CASE("Subtraction operator")
{
    SquareMat mat1(3);
    mat1.setValue(0, 0, -5);
    mat1.setValue(1, 1, 6.555);
    mat1.setValue(2, 2, 7);

    SquareMat mat2(3);
    mat2.setValue(0, 0, -2);
    mat2.setValue(1, 1, 3);
    mat2.setValue(2, 2, 4);

    SquareMat result = mat1 - mat2;

    CHECK(result.getValue(0, 0) == -3);
    CHECK(SquareMat::isEqual(result.getValue(1, 1), 3.555));
    CHECK(result.getValue(2, 2) == 3);

    // Make sure all other values are still 0
    CHECK(result.getValue(0, 1) == 0);
    CHECK(result.getValue(0, 2) == 0);
    CHECK(result.getValue(1, 0) == 0);
    CHECK(result.getValue(1, 2) == 0);
    CHECK(result.getValue(2, 0) == 0);
    CHECK(result.getValue(2, 1) == 0);
}

// Check the negation operator:
TEST_CASE("Negation operator")
{
    SquareMat mat(3);
    mat.setValue(0, 0, 1);
    mat.setValue(1, 1, -2);
    mat.setValue(2, 2, 3);

    SquareMat result = -mat;

    CHECK(result.getValue(0, 0) == -1);
    CHECK(result.getValue(1, 1) == 2);
    CHECK(result.getValue(2, 2) == -3);

    // Make sure all other values are still 0
    CHECK(result.getValue(0, 1) == 0);
    CHECK(result.getValue(0, 2) == 0);
    CHECK(result.getValue(1, 0) == 0);
    CHECK(result.getValue(1, 2) == 0);
    CHECK(result.getValue(2, 0) == 0);
    CHECK(result.getValue(2, 1) == 0);
}

// Check the multiplication operator:
TEST_CASE("Multiplication operator")
{
    SquareMat mat1(3);
    mat1.setValue(0, 0, 1);
    mat1.setValue(0, 1, 2);
    mat1.setValue(0, 2, 3);
    mat1.setValue(1, 0, 4);
    mat1.setValue(1, 1, 5);
    mat1.setValue(1, 2, 6);
    mat1.setValue(2, 0, 7);
    mat1.setValue(2, 1, 8);
    mat1.setValue(2, 2, 9);

    SquareMat mat2(3);
    mat2.setValue(0, 0, 1);
    mat2.setValue(0, 1, 2);
    mat2.setValue(0, 2, 3);
    mat2.setValue(1, 0, 4);
    mat2.setValue(1, 1, 5);
    mat2.setValue(1, 2, 6);
    mat2.setValue(2, 0, 7);
    mat2.setValue(2, 1, 8);
    mat2.setValue(2, 2, 9);

    SquareMat result = mat1 * mat2;
    CHECK(result.getValue(0, 0) == 30);
    CHECK(result.getValue(0, 1) == 36);
    CHECK(result.getValue(0, 2) == 42);
    CHECK(result.getValue(1, 0) == 66);
    CHECK(result.getValue(1, 1) == 81);
    CHECK(result.getValue(1, 2) == 96);
    CHECK(result.getValue(2, 0) == 102);
    CHECK(result.getValue(2, 1) == 126);
    CHECK(result.getValue(2, 2) == 150);
}

// Check the multiplication operator with scalar:
TEST_CASE("Multiplication operator with scalar")
{
    SquareMat mat(3);
    mat.setValue(0, 0, 1);
    mat.setValue(1, 1, -2);
    mat.setValue(2, 2, 3.5);

    SquareMat result = mat * 2.0;

    CHECK(result.getValue(0, 0) == 2);
    CHECK(result.getValue(1, 1) == -4);
    CHECK(result.getValue(2, 2) == 7);

    // Make sure all other values are still 0
    CHECK(result.getValue(0, 1) == 0);
    CHECK(result.getValue(0, 2) == 0);
    CHECK(result.getValue(1, 0) == 0);
    CHECK(result.getValue(1, 2) == 0);
    CHECK(result.getValue(2, 0) == 0);
    CHECK(result.getValue(2, 1) == 0);
}

// Check the non-member function to multiply by a scalar (scalar * matrix)
TEST_CASE("Non-member function to multiply by a scalar")
{
    SquareMat mat(3);
    mat.setValue(0, 0, 1);
    mat.setValue(1, 1, -2);
    mat.setValue(2, 2, 3.5);

    SquareMat result = 2.5 * mat;

    CHECK(result.getValue(0, 0) == 2.5);
    CHECK(result.getValue(1, 1) == -5);
    CHECK(result.getValue(2, 2) == 8.75);

    // Make sure all other values are still 0
    CHECK(result.getValue(0, 1) == 0);
    CHECK(result.getValue(0, 2) == 0);
    CHECK(result.getValue(1, 0) == 0);
    CHECK(result.getValue(1, 2) == 0);
    CHECK(result.getValue(2, 0) == 0);
    CHECK(result.getValue(2, 1) == 0);
}

// Check the element-wise multiplication operator:
TEST_CASE("Element-wise multiplication operator")
{
    SquareMat mat1(3);
    mat1.setValue(0, 0, 1);
    mat1.setValue(1, 1, -2);
    mat1.setValue(2, 2, 3.65);

    SquareMat mat2(3);
    mat2.setValue(0, 0, 4);
    mat2.setValue(1, 1, -5);
    mat2.setValue(2, 2, -6.54);

    SquareMat result = mat1 % mat2;

    CHECK(result.getValue(0, 0) == 4);
    CHECK(result.getValue(1, 1) == 10);
    CHECK(result.getValue(2, 2) == -23.871);

    // Make sure all other values are still 0
    CHECK(result.getValue(0, 1) == 0);
    CHECK(result.getValue(0, 2) == 0);
    CHECK(result.getValue(1, 0) == 0);
    CHECK(result.getValue(1, 2) == 0);
    CHECK(result.getValue(2, 0) == 0);
    CHECK(result.getValue(2, 1) == 0);
}

// Check the modulo operator with scalar:
TEST_CASE("Modulo operator with scalar")
{
    SquareMat mat(3);
    mat.setValue(0, 0, 1);
    mat.setValue(1, 1, -2);
    mat.setValue(2, 2, 3.00);

    SquareMat result = mat % 2;

    CHECK(result.getSize() == 3); // Test size is correct
    CHECK(result.getValue(0, 0) == 1);
    CHECK(result.getValue(1, 1) == 0);
    CHECK(result.getValue(2, 2) == 1);

    // Make sure all other values are still 0
    CHECK(result.getValue(0, 1) == 0);
    CHECK(result.getValue(0, 2) == 0);
    CHECK(result.getValue(1, 0) == 0);
    CHECK(result.getValue(1, 2) == 0);
    CHECK(result.getValue(2, 0) == 0);
    CHECK(result.getValue(2, 1) == 0);
}

// Check the division operator with scalar:
TEST_CASE("Division operator with scalar")
{
    SquareMat mat(3);
    mat.setValue(0, 0, 2);
    mat.setValue(1, 1, -4);
    mat.setValue(2, 2, 6.000);

    SquareMat result = mat / 2;

    CHECK(result.getSize() == 3); // Test size is correct
    CHECK(result.getValue(0, 0) == 1);
    CHECK(result.getValue(1, 1) == -2);
    CHECK(result.getValue(2, 2) == 3);

    // Make sure all other values are still 0
    CHECK(result.getValue(0, 1) == 0);
    CHECK(result.getValue(0, 2) == 0);
    CHECK(result.getValue(1, 0) == 0);
    CHECK(result.getValue(1, 2) == 0);
    CHECK(result.getValue(2, 0) == 0);
    CHECK(result.getValue(2, 1) == 0);
}

// Check the unary power operator:
TEST_CASE("Unary power operator")
{
    SquareMat mat(3);
    mat.setValue(0, 0, 1);
    mat.setValue(0, 1, 2);
    mat.setValue(0, 2, 3);
    mat.setValue(1, 0, 4);
    mat.setValue(1, 1, 5);
    mat.setValue(1, 2, 6);
    mat.setValue(2, 0, 7);
    mat.setValue(2, 1, 8);
    mat.setValue(2, 2, 9);

    CHECK_THROWS(mat ^ -3); // Ensure the power operator throws for negative exponents

    // Check the power operator with a zero exponent:
    // (The result should be the identity matrix of the same size)
    SquareMat identity_matrix = mat ^ 0;
    CHECK(identity_matrix.getSize() == 3); // Test size is correct
    CHECK(identity_matrix.getValue(0, 0) == 1);
    CHECK(identity_matrix.getValue(1, 1) == 1);
    CHECK(identity_matrix.getValue(2, 2) == 1);
    // Make sure all other values are still 0
    CHECK(identity_matrix.getValue(0, 1) == 0);
    CHECK(identity_matrix.getValue(0, 2) == 0);
    CHECK(identity_matrix.getValue(1, 0) == 0);
    CHECK(identity_matrix.getValue(1, 2) == 0);
    CHECK(identity_matrix.getValue(2, 0) == 0);
    CHECK(identity_matrix.getValue(2, 1) == 0);

    // Check the power operator with a positive exponent(3):

    SquareMat mat2(3);
    mat2.setValue(0, 0, 1);
    mat2.setValue(0, 1, 2);
    mat2.setValue(0, 2, 3);
    mat2.setValue(1, 0, 4);
    mat2.setValue(1, 1, 5);
    mat2.setValue(1, 2, 6);
    mat2.setValue(2, 0, 7);
    mat2.setValue(2, 1, 8);
    mat2.setValue(2, 2, 9);

    SquareMat result = mat2 ^ 3;

    CHECK(result.getSize() == 3); // Test size is correct
    CHECK(result.getValue(0, 0) == 468);
    CHECK(result.getValue(0, 1) == 576);
    CHECK(result.getValue(0, 2) == 684);
    CHECK(result.getValue(1, 0) == 1062);
    CHECK(result.getValue(1, 1) == 1305);
    CHECK(result.getValue(1, 2) == 1548);
    CHECK(result.getValue(2, 0) == 1656);
    CHECK(result.getValue(2, 1) == 2034);
    CHECK(result.getValue(2, 2) == 2412);
}

// Check the pre-increment operator:
TEST_CASE("Pre-increment operator")
{
    SquareMat mat(3);
    mat.setValue(0, 0, 1);
    mat.setValue(0, 1, 2);
    mat.setValue(0, 2, 3);
    mat.setValue(1, 0, 4);
    mat.setValue(1, 1, 5);
    mat.setValue(1, 2, 6);
    mat.setValue(2, 0, 7);
    mat.setValue(2, 1, 8);
    mat.setValue(2, 2, 9);

    SquareMat result = ++mat;

    CHECK(result.getValue(0, 0) == 2);
    CHECK(result.getValue(0, 1) == 3);
    CHECK(result.getValue(0, 2) == 4);
    CHECK(result.getValue(1, 0) == 5);
    CHECK(result.getValue(1, 1) == 6);
    CHECK(result.getValue(1, 2) == 7);
    CHECK(result.getValue(2, 0) == 8);
    CHECK(result.getValue(2, 1) == 9);
    CHECK(result.getValue(2, 2) == 10);
}

// Check the post-increment operator:
TEST_CASE("Post-increment operator")
{
    SquareMat mat(3);
    mat.setValue(0, 0, 1);
    mat.setValue(0, 1, 2);
    mat.setValue(0, 2, 3);
    mat.setValue(1, 0, 4);
    mat.setValue(1, 1, 5);
    mat.setValue(1, 2, 6);
    mat.setValue(2, 0, 7);
    mat.setValue(2, 1, 8);
    mat.setValue(2, 2, 9);

    SquareMat result = mat++;

    CHECK(result.getValue(0, 0) == 1);
    CHECK(result.getValue(0, 1) == 2);
    CHECK(result.getValue(0, 2) == 3);
    CHECK(result.getValue(1, 0) == 4);
    CHECK(result.getValue(1, 1) == 5);
    CHECK(result.getValue(1, 2) == 6);
    CHECK(result.getValue(2, 0) == 7);
    CHECK(result.getValue(2, 1) == 8);
    CHECK(result.getValue(2, 2) == 9);

    // Check the original matrix has been incremented:
    CHECK(mat.getSize() == 3); // Test size is correct
    CHECK(mat.getValue(0, 0) == 2);
    CHECK(mat.getValue(0, 1) == 3);
    CHECK(mat.getValue(0, 2) == 4);
    CHECK(mat.getValue(1, 0) == 5);
    CHECK(mat.getValue(1, 1) == 6);
    CHECK(mat.getValue(1, 2) == 7);
    CHECK(mat.getValue(2, 0) == 8);
    CHECK(mat.getValue(2, 1) == 9);
    CHECK(mat.getValue(2, 2) == 10);
}

// Check the pre-decrement operator:
TEST_CASE("Pre-decrement operator")
{
    SquareMat mat(3);
    mat.setValue(0, 0, 1);
    mat.setValue(0, 1, 2);
    mat.setValue(0, 2, 3);
    mat.setValue(1, 0, 4);
    mat.setValue(1, 1, 5);
    mat.setValue(1, 2, 6);
    mat.setValue(2, 0, 7);
    mat.setValue(2, 1, 8);
    mat.setValue(2, 2, 9);

    SquareMat result = --mat;

    CHECK(result.getValue(0, 0) == 0);
    CHECK(result.getValue(0, 1) == 1);
    CHECK(result.getValue(0, 2) == 2);
    CHECK(result.getValue(1, 0) == 3);
    CHECK(result.getValue(1, 1) == 4);
    CHECK(result.getValue(1, 2) == 5);
    CHECK(result.getValue(2, 0) == 6);
    CHECK(result.getValue(2, 1) == 7);
    CHECK(result.getValue(2, 2) == 8);
}

// Check the post-decrement operator:
TEST_CASE("Post-decrement operator")
{
    SquareMat mat(3);
    mat.setValue(0, 0, 1);
    mat.setValue(0, 1, 2);
    mat.setValue(0, 2, 3);
    mat.setValue(1, 0, 4);
    mat.setValue(1, 1, 5);
    mat.setValue(1, 2, 6);
    mat.setValue(2, 0, 7);
    mat.setValue(2, 1, 8);
    mat.setValue(2, 2, 9);

    SquareMat result = mat--;

    CHECK(result.getValue(0, 0) == 1);
    CHECK(result.getValue(0, 1) == 2);
    CHECK(result.getValue(0, 2) == 3);
    CHECK(result.getValue(1, 0) == 4);
    CHECK(result.getValue(1, 1) == 5);
    CHECK(result.getValue(1, 2) == 6);
    CHECK(result.getValue(2, 0) == 7);
    CHECK(result.getValue(2, 1) == 8);
    CHECK(result.getValue(2, 2) == 9);

    // Check the original matrix has been decremented:
    CHECK(mat.getSize() == 3); // Test size is correct
    CHECK(mat.getValue(0, 0) == 0);
    CHECK(mat.getValue(0, 1) == 1);
    CHECK(mat.getValue(0, 2) == 2);
    CHECK(mat.getValue(1, 0) == 3);
    CHECK(mat.getValue(1, 1) == 4);
    CHECK(mat.getValue(1, 2) == 5);
    CHECK(mat.getValue(2, 0) == 6);
    CHECK(mat.getValue(2, 1) == 7);
    CHECK(mat.getValue(2, 2) == 8);
}

// Check the transpose operator:
TEST_CASE("Transpose operator")
{
    SquareMat mat(3);
    mat.setValue(0, 0, 1);
    mat.setValue(0, 1, 2);
    mat.setValue(0, 2, 3);
    mat.setValue(1, 0, 4);
    mat.setValue(1, 1, 5);
    mat.setValue(1, 2, 6);
    mat.setValue(2, 0, 7);
    mat.setValue(2, 1, 8);
    mat.setValue(2, 2, 9);

    SquareMat result = ~mat;

    CHECK(result.getValue(0, 0) == 1);
    CHECK(result.getValue(0, 1) == 4);
    CHECK(result.getValue(0, 2) == 7);
    CHECK(result.getValue(1, 0) == 2);
    CHECK(result.getValue(1, 1) == 5);
    CHECK(result.getValue(1, 2) == 8);
    CHECK(result.getValue(2, 0) == 3);
    CHECK(result.getValue(2, 1) == 6);
    CHECK(result.getValue(2, 2) == 9);
}

// Check the equality and inequality operators:
TEST_CASE("Equality and inequality operator")
{
    SquareMat mat1(3);
    mat1.setValue(0, 0, 1);
    mat1.setValue(0, 1, 2);
    mat1.setValue(0, 2, 3);
    mat1.setValue(1, 0, 4);
    mat1.setValue(1, 1, 5);
    mat1.setValue(1, 2, 6);
    mat1.setValue(2, 0, 7);
    mat1.setValue(2, 1, 8);
    mat1.setValue(2, 2, 9);

    SquareMat mat2(3);
    mat2.setValue(0, 0, 1);
    mat2.setValue(0, 1, 2);
    mat2.setValue(0, 2, 3);
    mat2.setValue(1, 0, 4);
    mat2.setValue(1, 1, -5); // Different value
    mat2.setValue(1, 2, -6); // Different value
    mat2.setValue(2, 0, -7); // Different value
    mat2.setValue(2, 1, -8); // Different value
    mat2.setValue(2, 2, -9); // Different value

    CHECK(mat1 == mat1); // Same matrix should be equal
    CHECK(mat1 != mat2); // Different matrices should not be equal
}

// Check the greater than, less than, greater equal and less equal operators:
TEST_CASE("Greater than, less than, greater equal and less equal operators")
{
    SquareMat mat1(3);
    mat1.setValue(0, 0, 1);
    mat1.setValue(0, 1, 2);
    mat1.setValue(0, 2, 3);
    mat1.setValue(1, 0, 4);
    mat1.setValue(1, 1, 5);
    mat1.setValue(1, 2, 6);
    mat1.setValue(2, 0, 7);
    mat1.setValue(2, 1, 8);
    mat1.setValue(2, 2, 9);

    SquareMat mat2(3);
    mat2.setValue(0, 0, -1);
    mat2.setValue(0, 1, -2);
    mat2.setValue(0, 2, -3);
    mat2.setValue(1, 0, -4);
    mat2.setValue(1, 1, -5);
    mat2.setValue(1, 2, -6);
    mat2.setValue(2, 0, -7);
    mat2.setValue(2, 1, -8);
    mat2.setValue(2, 2, -9);

    SquareMat mat3(3);
    mat3.setValue(0, 0, 1);
    mat3.setValue(0, 1, 2);
    mat3.setValue(0, 2, 3);
    mat3.setValue(1, 0, 4);
    mat3.setValue(1, 1, 5);
    mat3.setValue(1, 2, 6);
    mat3.setValue(2, 0, 7);
    mat3.setValue(2, 1, 8);
    mat3.setValue(2, 2, 9);

    SquareMat mat4(3);
    mat4.setValue(0, 0, 1);
    mat4.setValue(0, 1, 2);
    mat4.setValue(0, 2, 3);
    mat4.setValue(1, 0, 4);
    mat4.setValue(1, 1, 5);
    mat4.setValue(1, 2, 6);
    mat4.setValue(2, 0, 7);
    mat4.setValue(2, 1, 7);
    mat4.setValue(2, 2, 7);

    CHECK(mat1 > mat2); // Check greater than

    // Check greater than or equal to with equal matrices on both sides
    CHECK(mat1 >= mat3);
    CHECK(mat3 >= mat1);

    CHECK(mat1 >= mat4); // Check greater than or equal to

    CHECK(mat3 >= mat3); // Check greater than or equal to with the same matrix

    ////////////////////////////////////////////////////////////////////////////

    CHECK(mat2 < mat1);  // Check less than
    CHECK(mat4 <= mat1); // Check less than or equal to

    // Check less than or equal to with equal matrices on both sides
    CHECK(mat3 <= mat1);
    CHECK(mat1 <= mat3);

    CHECK(mat3 <= mat3); // Check less than or equal to with the same matrix
}

// Check the determinant operator:
TEST_CASE("Determinant operator")
{
    SquareMat mat(3);
    mat.setValue(0, 0, 1);
    mat.setValue(0, 1, 2);
    mat.setValue(0, 2, 3);
    mat.setValue(1, 0, 4);
    mat.setValue(1, 1, 5);
    mat.setValue(1, 2, 6);
    mat.setValue(2, 0, 7);
    mat.setValue(2, 1, 8);
    mat.setValue(2, 2, 9);
    int det_res = !mat;  // Call the determinant operator
    CHECK(det_res == 0); // Check determinate is the correct value

    SquareMat mat2(3);
    mat2.setValue(0, 0, 6);
    mat2.setValue(0, 1, 7);
    mat2.setValue(0, 2, 4);
    mat2.setValue(1, 0, 8);
    mat2.setValue(1, 1, 9);
    mat2.setValue(1, 2, 6);
    mat2.setValue(2, 0, 7);
    mat2.setValue(2, 1, 7);
    mat2.setValue(2, 2, 4);
    int det_res2 = !mat2; // Call the determinant operator
    CHECK(det_res2 == 6); // Check determinate is the correct value
}

// Check the printing operator:
TEST_CASE("Printing operator")
{
    SquareMat mat(3);
    mat.setValue(0, 0, 1);
    mat.setValue(0, 1, 2);
    mat.setValue(0, 2, 3);
    mat.setValue(1, 0, 4);
    mat.setValue(1, 1, 5);
    mat.setValue(1, 2, 6);
    mat.setValue(2, 0, 7);
    mat.setValue(2, 1, 8);
    mat.setValue(2, 2, 9);

    ostringstream oss; // An output string stream (ostringstream) is created.
    // (This is a special kind of stream that writes output to a string instead of the console.)
    oss << mat; // Use the printing operator

    // The \t represents a tab character (used to separate the values in a row), and \n represents a newline (to move to the next row after each line).
    string expected_output = "1\t2\t3\n4\t5\t6\n7\t8\t9\n";

    CHECK(oss.str() == expected_output); // Check the output is correct
}

// Check the += operator(adds another matrix to this matrix):
TEST_CASE("Addition assignment operator")
{
    SquareMat mat1(3);
    mat1.setValue(0, 0, 1);
    mat1.setValue(0, 1, 2);
    mat1.setValue(0, 2, 3);
    mat1.setValue(1, 0, 4);
    mat1.setValue(1, 1, 5);
    mat1.setValue(1, 2, 6);
    mat1.setValue(2, 0, 7);
    mat1.setValue(2, 1, 8);
    mat1.setValue(2, 2, 9);

    SquareMat mat2(3);
    mat2.setValue(0, 0, -1);
    mat2.setValue(0, 1, -3);
    mat2.setValue(0, 2, -5);
    mat2.setValue(1, 0, -7);
    mat2.setValue(1, 1, -1);
    mat2.setValue(1, 2, -1);
    mat2.setValue(2, 0, -2);
    mat2.setValue(2, 1, 4);
    mat2.setValue(2, 2, 16);

    SquareMat result = mat1;
    result += mat2; // Use the addition assignment operator

    CHECK(result.getValue(0, 0) == 0);
    CHECK(result.getValue(0, 1) == -1);
    CHECK(result.getValue(0, 2) == -2);
    CHECK(result.getValue(1, 0) == -3);
    CHECK(result.getValue(1, 1) == 4);
    CHECK(result.getValue(1, 2) == 5);
    CHECK(result.getValue(2, 0) == 5);
    CHECK(result.getValue(2, 1) == 12);
    CHECK(result.getValue(2, 2) == 25);
}

// Check the -= operator(substracuts another matrix from this matrix):
TEST_CASE("Addition assignment operator")
{
    SquareMat mat1(3);
    mat1.setValue(0, 0, 1);
    mat1.setValue(0, 1, 2);
    mat1.setValue(0, 2, 3);
    mat1.setValue(1, 0, 4);
    mat1.setValue(1, 1, 5);
    mat1.setValue(1, 2, 6);
    mat1.setValue(2, 0, 7);
    mat1.setValue(2, 1, 8);
    mat1.setValue(2, 2, 9);

    SquareMat mat2(3);
    mat2.setValue(0, 0, -1);
    mat2.setValue(0, 1, -3);
    mat2.setValue(0, 2, -5);
    mat2.setValue(1, 0, -7);
    mat2.setValue(1, 1, -1);
    mat2.setValue(1, 2, -1);
    mat2.setValue(2, 0, -2);
    mat2.setValue(2, 1, 4);
    mat2.setValue(2, 2, 16);

    SquareMat result = mat1;
    result -= mat2; // Use the addition assignment operator

    CHECK(result.getValue(0, 0) == 2);
    CHECK(result.getValue(0, 1) == 5);
    CHECK(result.getValue(0, 2) == 8);
    CHECK(result.getValue(1, 0) == 11);
    CHECK(result.getValue(1, 1) == 6);
    CHECK(result.getValue(1, 2) == 7);
    CHECK(result.getValue(2, 0) == 9);
    CHECK(result.getValue(2, 1) == 4);
    CHECK(result.getValue(2, 2) == -7);
}

// Check the *= operator(Multiplies this matrix by another matrix):
TEST_CASE("Multiplication assignment operator")
{
    SquareMat mat1(3);
    mat1.setValue(0, 0, 1);
    mat1.setValue(0, 1, 2);
    mat1.setValue(0, 2, 3);
    mat1.setValue(1, 0, 4);
    mat1.setValue(1, 1, 5);
    mat1.setValue(1, 2, 6);
    mat1.setValue(2, 0, 7);
    mat1.setValue(2, 1, 8);
    mat1.setValue(2, 2, 9);

    SquareMat mat2(3);
    mat2.setValue(0, 0, -1);
    mat2.setValue(0, 1, -3);
    mat2.setValue(0, 2, -5);
    mat2.setValue(1, 0, -7);
    mat2.setValue(1, 1, -1);
    mat2.setValue(1, 2, -1);
    mat2.setValue(2, 0, -2);
    mat2.setValue(2, 1, -4);
    mat2.setValue(2, 2, -16);

    SquareMat result = mat1;
    result *= mat2; // Use the addition assignment operator

    CHECK(result.getValue(0, 0) == -21);
    CHECK(result.getValue(0, 1) == -17);
    CHECK(result.getValue(0, 2) == -55);
    CHECK(result.getValue(1, 0) == -51);
    CHECK(result.getValue(1, 1) == -41);
    CHECK(result.getValue(1, 2) == -121);
    CHECK(result.getValue(2, 0) == -81);
    CHECK(result.getValue(2, 1) == -65);
    CHECK(result.getValue(2, 2) == -187);
}

// Check the /= operator(Divides this matrix by another matrix):
TEST_CASE("Division assignment operator")
{
    SquareMat mat1(3);
    mat1.setValue(0, 0, 1);
    mat1.setValue(0, 1, 2);
    mat1.setValue(0, 2, 15);
    mat1.setValue(1, 0, 14);
    mat1.setValue(1, 1, 5);
    mat1.setValue(1, 2, 6);
    mat1.setValue(2, 0, 8);
    mat1.setValue(2, 1, 8);
    mat1.setValue(2, 2, 80);

    SquareMat mat2(3);
    mat2.setValue(0, 0, -1);
    mat2.setValue(0, 1, -2);
    mat2.setValue(0, 2, -5);
    mat2.setValue(1, 0, -7);
    mat2.setValue(1, 1, -1);
    mat2.setValue(1, 2, -1);
    mat2.setValue(2, 0, -2);
    mat2.setValue(2, 1, -4);
    mat2.setValue(2, 2, 16);

    SquareMat result = mat1;
    result /= mat2; // Use the addition assignment operator

    CHECK(result.getValue(0, 0) == -1);
    CHECK(result.getValue(0, 1) == -1);
    CHECK(result.getValue(0, 2) == -3);
    CHECK(result.getValue(1, 0) == -2);
    CHECK(result.getValue(1, 1) == -5);
    CHECK(result.getValue(1, 2) == -6);
    CHECK(result.getValue(2, 0) == -4);
    CHECK(result.getValue(2, 1) == -2);
    CHECK(result.getValue(2, 2) == 5);
}

// Check the %= operator(Performs element-wise modulo operation between this matrix and another matrix):
TEST_CASE("Modulo assignment operator")
{
    SquareMat mat1(3);
    mat1.setValue(0, 0, 1);
    mat1.setValue(0, 1, 2);
    mat1.setValue(0, 2, 15);
    mat1.setValue(1, 0, 14);
    mat1.setValue(1, 1, 5);
    mat1.setValue(1, 2, 6);
    mat1.setValue(2, 0, 8);
    mat1.setValue(2, 1, 8);
    mat1.setValue(2, 2, 80);

    SquareMat mat2(3);
    mat2.setValue(0, 0, 1);
    mat2.setValue(0, 1, 2);
    mat2.setValue(0, 2, 2);
    mat2.setValue(1, 0, 3);
    mat2.setValue(1, 1, 1);
    mat2.setValue(1, 2, 1);
    mat2.setValue(2, 0, 7);
    mat2.setValue(2, 1, 10);
    mat2.setValue(2, 2, 162);

    SquareMat result = mat1;
    result %= mat2; 

    CHECK(result.getValue(0, 0) == 0);
    CHECK(result.getValue(0, 1) == 0);
    CHECK(result.getValue(0, 2) == 1);
    CHECK(result.getValue(1, 0) == 2);
    CHECK(result.getValue(1, 1) == 0);
    CHECK(result.getValue(1, 2) == 0);
    CHECK(result.getValue(2, 0) == 1);
    CHECK(result.getValue(2, 1) == 8);
    CHECK(result.getValue(2, 2) == 80);
}