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



    return 0;
}
