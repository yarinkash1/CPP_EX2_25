//yarinkash1@gmail.com
#include <iostream>
#include "SquareMat.hpp"
using namespace mat_ns;

int main()
{
    std::cout << "Program started!" << std::endl;
    
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

    // Print the vector of a row:
    cout << "Row 1 of Matrix 1(using the overloaded operator []):" << endl;
    SquareMat::RowProxy row1 = mat1[1]; // Get the RowProxy for row 1
    for (int j = 0; j < mat1.getSize(); j++)
    {
        cout << row1[j] << "\t"; // Print the values of the row
    }
    cout << endl;
    cout << "-----------------------------------------------------------:" << endl;



    return 0;
}
