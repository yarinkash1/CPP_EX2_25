//yarinkash1@gmail.com
#include <iostream>
#include "SquareMat.hpp"
using namespace mat_ns;

int main()
{
    std::cout << "-- Demo start --" << std::endl;
    
    // show simple matrix creation and printing:
    SquareMat mat1(3);
    mat1.setValue(0, 0, 1.0);
    mat1.setValue(0, 1, 2.0);
    mat1.setValue(0, 2, 3.0);
    mat1.setValue(1, 0, 4.0);
    mat1.setValue(1, 1, 5);
    mat1.setValue(1, 2, 6.66);
    mat1.setValue(2, 0, 7.0);
    mat1.setValue(2, 1, 8.0);
    mat1.setValue(2, 2, 9.0);

    //print matrix:
    cout << "Matrix 1(using the regular print function):" << endl;
    mat1.printMatrix(cout); // Print using the regular member function printMatrix
    cout << "-----------------------------------------------------------:" << endl;
    cout << "Matrix 1(using the overloaded operator <<):" << endl;
    cout << mat1; // Print using overloaded operator <<
    cout << "-----------------------------------------------------------:" << endl;

    // Overloaded operator [] for read only and write only:
    // Read-only access:
    // Print the vector of a row:
    cout << "Row 1 of Matrix 1(using the overloaded operator []):" << endl;
    SquareMat::RowProxy row1 = mat1[1]; // Get the RowProxy for row 1
    for (int j = 0; j < mat1.getSize(); j++)
    {
        cout << row1[j] << "\t"; // Print the values of the row
    }
    cout << endl;
    cout << "-----------------------------------------------------------:" << endl;

    // Print an element using the overloaded operator []:
    cout << "Element at (1, 2) of Matrix 1(using the overloaded operator []):" << endl;
    cout << mat1[1][2] << endl; // Print the element at (1, 2)
    cout << "-----------------------------------------------------------:" << endl;

    // Write access:
    cout << "Row 1 of Matrix 1(using the overloaded operator []):" << endl;
    SquareMat::RowProxy row2 = mat1[1]; // Get the RowProxy for row 1
    row2[2] = 10.0; // Modify the value at (1, 2)
    cout << "Modified Row 1 of Matrix 1(using the overloaded operator []):" << endl;
    for (int j = 0; j < mat1.getSize(); j++)
    {
        cout << row2[j] << "\t"; // Print the modified values of the row
    }
    cout << endl;
    cout << "-----------------------------------------------------------:" << endl;
    mat1[1][2] = 6.66; // Reset the value at (1, 2)

    // Adding two matrices:
    SquareMat mat2(3); // mat 2 is a 3x3 matrix with all values initialized to 0
    SquareMat res = mat1 + mat2; // Add mat1 and mat2
    cout << "Result of adding Matrix 1 and Matrix 2(using the overloaded operator +):" << endl;
    cout << res; // Print the result using the overloaded operator << (should give a matrix the same as mat1)
    cout << "-----------------------------------------------------------:" << endl;

    // Subtracting two matrices:
    mat2[0][0] = 1;
    mat2[0][1] = 5.3;
    mat2[0][2] = 3.33;
    mat2[1][0] = 22;
    mat2[1][1] = 54.2;
    mat2[1][2] = 6.66;
    mat2[2][0] = 6.1;
    mat2[2][1] = 8.312;
    mat2[2][2] = 19.99;
    SquareMat res2 = mat1 - mat2; // Subtract mat2 from mat1
    cout << "Result of subtracting Matrix 2 from Matrix 1(using the overloaded operator -):" << endl;
    cout << res2; // Print the result using the overloaded operator << (should give a matrix the same as mat1)
    cout << "-----------------------------------------------------------:" << endl;

    // Negating a matrix:
    SquareMat res3 = -mat1; // Negate mat1
    cout << "Result of negating Matrix 1(using the overloaded operator -):" << endl;
    cout << res3; // Print the result using the overloaded operator << (should give a matrix with all values negated)
    cout << "-----------------------------------------------------------:" << endl;

    // Multiplying a matrix by a scalar(matrix * scalar):
    SquareMat res4 = mat1 * 1.5; // Multiply mat1 by 1.5
    cout << "Result of multiplying Matrix 1 by 1.5(using the overloaded operator *):" << endl;
    cout << res4; // Print the result using the overloaded operator << (should give a matrix with all values multiplied by 1.5)
    cout << "-----------------------------------------------------------:" << endl;
    // Multiplying a matrix by a scalar (scalar * matrix):
    SquareMat res5 = 1.5 * mat1; // Multiply mat1 by 1.5
    cout << "Result of multiplying 1.5 by Matrix 1(using the overloaded operator *):" << endl;
    cout << res5; // Print the result using the overloaded operator << (should give a matrix with all values multiplied by 1.5 the same as res4)
    cout << "-----------------------------------------------------------:" << endl;

    // Multiplying two matrices:
    SquareMat res6 = mat1 * mat2; // Multiply mat1 and mat2
    cout << "Result of multiplying Matrix 1 and Matrix 2(using the overloaded operator *):" << endl;
    cout << res6; // Print the result using the overloaded operator << (should give a matrix with the product of mat1 and mat2)
    cout << "-----------------------------------------------------------:" << endl;
    // Element-wise multiplication of two matrices:
    SquareMat res7 = mat1 % mat2; // Element-wise multiply mat1 and mat2
    cout << "Result of element-wise multiplying Matrix 1 and Matrix 2(using the overloaded operator %):" << endl;
    cout << res7; // Print the result using the overloaded operator % (should give a matrix with the product of mat1 and mat2)
    cout << "-----------------------------------------------------------:" << endl;

    // Modulo operator with scalar:
    SquareMat res8 = mat1 % 2; // Element-wise modulo of mat1 with 2
    cout << "Result of element-wise modulo of Matrix 1 with 2(using the overloaded operator %):" << endl;
    cout << res8; // Print the result using the overloaded operator % (should give a matrix with the modulo of mat1 with 2)
    cout << "-----------------------------------------------------------:" << endl;
    // Division operator with scalar:
    SquareMat result = mat1 / 2;
    cout << "Result of dividing Matrix 1 by 2(using the overloaded operator /):" << endl;
    cout << result; // Print the result using the overloaded operator / (should give a matrix with all values divided by 2)
    cout << "-----------------------------------------------------------:" << endl;
    // Unary power operator:
    SquareMat res9 = mat1 ^ 3; // Square mat1
    cout << "Result of raising Matrix 1 to the power of 3(using the overloaded operator ^):" << endl;
    cout << res9; // Print the result using the overloaded operator ^ (should give a matrix with all values raised to the power of 3)
    cout << "-----------------------------------------------------------:" << endl;
    // Pre-increment operator:
    SquareMat res10 = ++mat1; // Increment mat1 by 1
    cout << "Result of incrementing Matrix 1 by 1(using the overloaded operator ++):" << endl;
    cout << res10; // Print the result using the overloaded operator ++ (should give a matrix with all values incremented by 1)
    cout << "-----------------------------------------------------------:" << endl;
    // Post-increment operator:
    SquareMat res11 = mat2++; // Increment mat1 by 1
    cout << "Result of incrementing Matrix 1 by 1(using the overloaded operator ++):" << endl;
    cout << res11; // Print the result using the overloaded operator ++ (should give a matrix with all values incremented by 1)
    cout << "-----------------------------------------------------------:" << endl;
    // Pre-decrement operator:
    SquareMat res12 = --mat1; // Decrement mat1 by 1
    cout << "Result of decrementing Matrix 1 by 1(using the overloaded operator --):" << endl;
    cout << res12; // Print the result using the overloaded operator -- (should give a matrix with all values decremented by 1)
    cout << "-----------------------------------------------------------:" << endl;
    // Post-decrement operator:
    SquareMat res13 = mat2--; // Decrement mat1 by 1
    cout << "Result of decrementing Matrix 1 by 1(using the overloaded operator --):" << endl;
    cout << res13; // Print the result using the overloaded operator -- (should give a matrix with all values decremented by 1)
    cout << "-----------------------------------------------------------:" << endl;
    // Transpose operator:
    SquareMat res14 = ~mat1; // Transpose mat1
    cout << "Result of transposing Matrix 1(using the overloaded operator ~):" << endl;
    cout << res14; // Print the result using the overloaded operator ~ (should give a matrix with all values transposed)
    cout << "-----------------------------------------------------------:" << endl;
    // Equality and inequality operators:
    bool isEqual = (mat1 == mat2); // Check if mat1 and mat2 are equal
    cout << "Matrix 1 and Matrix 2 are equal: " << (isEqual ? "true" : "false") << endl; // Print the result
    cout << "-----------------------------------------------------------:" << endl;
    bool isNotEqual = (mat1 != mat2); // Check if mat1 and mat2 are not equal
    cout << "Matrix 1 and Matrix 2 are not equal: " << (isNotEqual ? "true" : "false") << endl; // Print the result
    cout << "-----------------------------------------------------------:" << endl;
    // Ineqations:
    bool isLess = (mat1 < mat2); // Check if mat1 is less than mat2
    cout << "Matrix 1 is less than Matrix 2: " << (isLess ? "true" : "false") << endl; // Print the result
    cout << "-----------------------------------------------------------:" << endl;
    bool isGreater = (mat1 > mat2); // Check if mat1 is greater than mat2
    cout << "Matrix 1 is greater than Matrix 2: " << (isGreater ? "true" : "false") << endl; // Print the result
    cout << "-----------------------------------------------------------:" << endl;
    bool isLessEqual = (mat1 <= mat2); // Check if mat1 is less than or equal to mat2
    cout << "Matrix 1 is less than or equal to Matrix 2: " << (isLessEqual ? "true" : "false") << endl; // Print the result
    cout << "-----------------------------------------------------------:" << endl;
    bool isGreaterEqual = (mat1 >= mat2); // Check if mat1 is greater than or equal to mat2
    cout << "Matrix 1 is greater than or equal to Matrix 2: " << (isGreaterEqual ? "true" : "false") << endl; // Print the result
    cout << "-----------------------------------------------------------:" << endl;
    // Determinant operator:
    double det = !mat1; // Calculate the determinant of mat1
    cout << "Determinant of Matrix 1(using the overloaded operator !): " << det << endl; // Print the determinant
    cout << "-----------------------------------------------------------:" << endl;
    // Addition assignment operator:
    SquareMat res15 = mat1; // Copy mat1 to res15
    res15 += mat2; // Add mat2 to res15
    cout << "Result of adding Matrix 2 to Matrix 1(using the overloaded operator +=):" << endl;
    cout << res15; // Print the result using the overloaded operator += (should give a matrix with the sum of mat1 and mat2)
    cout << "-----------------------------------------------------------:" << endl;
    // Subtraction assignment operator:
    SquareMat res16 = mat1; // Copy mat1 to res16
    res16 -= mat2; // Subtract mat2 from res16
    cout << "Result of subtracting Matrix 2 from Matrix 1(using the overloaded operator -=):" << endl;
    cout << res16; // Print the result using the overloaded operator -= (should give a matrix with the difference of mat1 and mat2)
    cout << "-----------------------------------------------------------:" << endl;
    // Multiplication assignment operator:
    SquareMat res17 = mat1; // Copy mat1 to res17
    res17 *= mat2; // Multiply res17 by mat2
    cout << "Result of multiplying Matrix 1 by Matrix 2(using the overloaded operator *=):" << endl;
    cout << res17; // Print the result using the overloaded operator *= (should give a matrix with the product of mat1 and mat2)
    cout << "-----------------------------------------------------------:" << endl;
    // Division assignment operator:
    SquareMat res18 = mat1; // Copy mat1 to res18
    res18 /= mat2; // Divide res18 by mat2
    cout << "Result of dividing Matrix 1 by Matrix 2(using the overloaded operator /=):" << endl;
    cout << res18; // Print the result using the overloaded operator /= (should give a matrix with the quotient of mat1 and mat2)
    cout << "-----------------------------------------------------------:" << endl;
    // Modulo assignment operator(matrix version):
    SquareMat res20 = mat1; // Copy mat1 to res20
    res20 %= 2; // Element-wise modulo of res20 with 2
    cout << "Result of element-wise modulo of Matrix 1 with 2(using the overloaded operator %=):" << endl;
    cout << res20; // Print the result using the overloaded operator %= (should give a matrix with the modulo of mat1 with 2)
    cout << "-----------------------------------------------------------:" << endl;
    // Modulo assignment operator(scalar version):
    SquareMat res21 = mat1; // Copy mat1 to res21
    res21 %= 3; // Element-wise modulo of res21 with scalar 3
    cout << "Result of element-wise modulo of Matrix 1 with scalar 3(using the overloaded operator %=):" << endl;
    cout << res21; // Print the result using the overloaded operator %= (should give a matrix with the modulo of mat1 with 3)
    cout << "-----------------------------------------------------------:" << endl;
    // Division assignment operator(scalar version):
    SquareMat res22 = mat1; // Copy mat1 to res22
    res22 /= 2; // Element-wise division of res22 with scalar 2
    cout << "Result of element-wise division of Matrix 1 with scalar 2(using the overloaded operator /=):" << endl;
    cout << res22; // Print the result using the overloaded operator /= (should give a matrix with the division of mat1 with 2)
    cout << "-----------------------------------------------------------:" << endl;
    cout << "-- Demo end --" << endl;

    return 0;
}
