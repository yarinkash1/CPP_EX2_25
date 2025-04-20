#include <iostream>
#include "SquareMat.hpp"
using namespace mat_ns;

int main()
{
    std::cout << "Program started!" << std::endl;
    
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

    //print matrix:
    cout << "Matrix 1:" << endl;
    mat1.printMatrix(cout); // Print using the regular member function printMatrix
    cout << "-----------------------------------------------------------:" << endl;
    cout << mat1; // Print using overloaded operator<<
    cout << "-----------------------------------------------------------:" << endl;



    return 0;
}
