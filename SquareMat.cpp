// yarinkash1@gmail.com
#include "SquareMat.hpp"

using namespace mat_ns;

SquareMat::SquareMat(int dimension) : n(dimension) // Initializer list constructor
{
    if (dimension <= 0)
    {
        throw "Dimension must be greater than 0.";
    }

    data = new double *[n]; // Allocate an array the size of the input dimension

    // Allocate each row with n columns(n x n size matrix):
    for (int i = 0; i < n; i++)
    {
        data[i] = new double[n];

        // Initialize all matrix values to be zero at first:
        for (int j = 0; j < n; j++)
        {
            data[i][j] = 0;
        }
    }
}

// Rule of 3:
SquareMat::~SquareMat() // Destructor
{
    // Free each row (array of int)
    for (int i = 0; i < n; i++)
    {
        delete[] data[i];
    }
    // Free the array of pointers (int*)
    delete[] data;
}

SquareMat::SquareMat(const SquareMat &other_sm) : n(other_sm.n) // Initializer list copy constructor
{
    data = new double *[n]; // Allocate an array the size of the input dimension

    // Allocate each row with n columns(n x n size matrix):
    for (int i = 0; i < n; i++)
    {
        data[i] = new double[n];

        // Initialize all matrix values to be the values of the other square matrix passed as an input:
        for (int j = 0; j < n; j++)
        {
            data[i][j] = other_sm.data[i][j];
        }
    }
}

SquareMat &SquareMat::operator=(const SquareMat &other_sm) // Copy assignment operator
{
    if (this == &other_sm)
    {
        return *this; // the actual object that this points to
    }

    // Free existing memory:
    for (int i = 0; i < n; i++)
    {
        delete[] data[i];
    }
    delete[] data;

    // Copy new size of matrix:
    n = other_sm.n;

    // Reallocating data
    data = new double *[n];

    // Allocate and copy:
    for (int i = 0; i < n; i++)
    {
        data[i] = new double[n];

        // Initialize all matrix values to be the values of the other square matrix passed as an input:
        for (int j = 0; j < n; j++)
        {
            data[i][j] = other_sm.data[i][j];
        }
    }

    return *this;
}

// Getters and setters:
int SquareMat::getSize() const
{
    return this->n;
}

void SquareMat::setValue(int i, int j, double value)
{
    if (areOutOfBounds(i, j) == false)
    {
        this->data[i][j] = value;
        return;
    }
    throw "Indexes are out of bounds.";
}

// Function overload to accept int, and implicitly convert to double
void SquareMat::setValue(int i, int j, int value)
{
    setValue(i, j, static_cast<double>(value)); // Cast the int to double and call the main function
}

double SquareMat::getValue(int i, int j)
{
    if (areOutOfBounds(i, j) == false)
    {
        return this->data[i][j];
    }
    throw "Indexes are out of bounds.";
}

// Helper function to determine if the input indexes are out of bounds
bool SquareMat::areOutOfBounds(int i, int j)
{

    if ((i < this->n && i >= 0) && (j < this->n && j >= 0))
    {
        return false;
    }
    return true;
}
// Helper function to print matrix:
void SquareMat::printMatrix(ostream &os) const
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            os << data[i][j]; // Print the value directly
            if (j < n - 1)    // Don't add a tab after the last element in each row
                os << "\t";
        }
        os << "\n"; // Newline after each row
    }
}

// Helper function to check for double equality:
bool SquareMat::isEqual(double a, double b) 
{
    return myAbs(a - b) < TOLERANCE;
}
// Helper function to calculate absolute value:
double SquareMat::myAbs(double value) 
{
    return (value < 0) ? -value : value;
}

// Function to add two matrices:
SquareMat SquareMat::operator+(const SquareMat &other_sm) const
{
    if (this->n != other_sm.n)
    {
        throw "Matrices are not the same size.";
    }

    SquareMat result(this->n); // Create a new matrix to store the result

    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            result.data[i][j] = this->data[i][j] + other_sm.data[i][j];
        }
    }
    return result;
}

// Function to subtract two matrices:
SquareMat SquareMat::operator-(const SquareMat &other_sm) const
{
    if (this->n != other_sm.n)
    {
        throw "Matrices are not the same size.";
    }

    SquareMat result(this->n); // Create a new matrix to store the result

    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            result.data[i][j] = this->data[i][j] - other_sm.data[i][j];
        }
    }
    return result;
}

// Function to negate a matrix:
SquareMat SquareMat::operator-() const
{
    SquareMat result(this->n); // Create a new matrix to store the result

    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            result.data[i][j] = -this->data[i][j];
        }
    }
    return result;
}

// Function to multiply two matrices(O(n^3)):
SquareMat SquareMat::operator*(const SquareMat &other_sm) const
{
    if (this->n != other_sm.n)
    {
        throw "Matrices are not the same size.";
    }

    SquareMat result(this->n); // Create a new matrix to store the result

    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            result.data[i][j] = 0;
            for (int k = 0; k < this->n; k++)
            {
                result.data[i][j] = result.data[i][j] + (this->data[i][k] * other_sm.data[k][j]);
            }
        }
    }
    return result;
}

// Member function to multiply a matrix by a scalar (matrix * scalar):
SquareMat SquareMat::operator*(double scalar) const
{
    SquareMat result(this->n); // Create a new matrix to store the result

    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            result.data[i][j] = this->data[i][j] * scalar;
        }
    }
    return result;
}

// Non-member function to multiply by a scalar (scalar * matrix):
namespace mat_ns
{
    SquareMat operator*(double scalar, const SquareMat &matrix)
    {
        return matrix * scalar; // Reuse the member function (:
    }
}

// Function to multiply two matrices element-wise:
SquareMat SquareMat::operator%(const SquareMat &other_sm) const
{
    if (this->n != other_sm.n)
    {
        throw "Matrices are not the same size.";
    }

    SquareMat result(this->n); // Create a new matrix to store the result

    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            result.data[i][j] = this->data[i][j] * other_sm.data[i][j];
        }
    }
    return result;
}

// Function to apply modulo to each element in the matrix (element % scalar):
SquareMat SquareMat::operator%(double scalar) const
{
    SquareMat result(this->n); // Create a new matrix to store the result

    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            result.data[i][j] = fmod(this->data[i][j], scalar); // Use fmod for floating-point modulo
        }
    }
    return result;
}

// Function to apply division to each element in the matrix (element / scalar):
SquareMat SquareMat::operator/(double scalar) const
{
    if (scalar == 0)
    {
        throw "Division by zero.";
    }

    SquareMat result(this->n); // Create a new matrix to store the result

    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            result.data[i][j] = this->data[i][j] / scalar;
        }
    }
    return result;
}

// Function to multiply the matrix by itself 'scalar' times:
SquareMat SquareMat::operator^(double scalar) const
{
    if (scalar < 0)
    {
        throw "Negative exponent not supported.";
    }
    else if (scalar == 0)
    {
        return identity(this->n); // return the identity matrix
    }
    else
    {
        SquareMat result(this->n); // Create a new matrix to store the result
        result = *this;            // Initialize result with the current matrix

        // Multiply the matrix by itself 'scalar' times:
        for (int k = 1; k < scalar; k++)
        {
            result = result * (*this);
        }

        return result;
    }
}

// Helper function to create identity matrix:
SquareMat SquareMat::identity(int dimension)
{
    SquareMat identity_mat(dimension);
    for (int i = 0; i < dimension; i++)
    {
        identity_mat.data[i][i] = 1;
    }
    return identity_mat;
}

// Pre-increment operator: increment each element in the matrix by 1
SquareMat &SquareMat::operator++()
{
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            this->data[i][j]++;
        }
    }
    return *this;
}

// Post-increment operator: increment each element in the matrix by 1
SquareMat SquareMat::operator++(int)
{
    SquareMat temp = *this; // Create a copy of the current matrix
    ++(*this);              // Call the pre-increment operator
    return temp;            // Return the copy
}

// Pre-decrement operator: decrement each element in the matrix by 1
SquareMat &SquareMat::operator--()
{
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            this->data[i][j]--;
        }
    }
    return *this;
}

// Post-decrement operator: decrement each element in the matrix by 1
SquareMat SquareMat::operator--(int)
{
    SquareMat temp = *this; // Create a copy of the current matrix
    --(*this);              // Call the pre-decrement operator
    return temp;            // Return the copy
}

// Transpose operator: transpose the matrix
SquareMat SquareMat::operator~() const
{
    SquareMat result(this->n); // Create a new matrix to store the result

    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            result.data[j][i] = this->data[i][j];
        }
    }

    return result;
}

// Non-const version: allows modification:
double *SquareMat::operator[](int i)
{
    // Check if the index is within bounds:
    if (i < 0 || i >= n)
    {
        throw "Index out of bounds.";
    }
    return data[i]; // returns a pointer to the i-th row
}

// Const version: only allows reading:
const double *SquareMat::operator[](int i) const
{
    // Check if the index is within bounds:
    if (i < 0 || i >= n)
    {
        throw "Index out of bounds.";
    }
    return data[i]; // returns a const pointer for const objects
}

// Function to check if two matrices are equal:
bool SquareMat::operator==(const SquareMat &other_sm) const
{
    bool equal = true;
    if (this->n != other_sm.n)
    {
        throw "Matrices are not the same size.";
    }
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            if (this->data[i][j] != other_sm.data[i][j])
            {
                equal = false;
                break;
            }
        }
    }
    return equal;
}

// Function to check if two matrices are not equal:
bool SquareMat::operator!=(const SquareMat &other_sm) const
{
    return !(*this == other_sm); // Reuse the equality operator
}

// Helper function to calculate the sum of all elements in the matrix:
double SquareMat::matrixSum() const
{
    int sum = 0;
    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            sum += this->data[i][j];
        }
    }
    return sum;
}

// Function to check if the sum of elements in this matrix is greater than the other matrix:
bool SquareMat::operator>(const SquareMat &other_sm) const
{
    return this->matrixSum() > other_sm.matrixSum();
}

// Function to check if the sum of elements in this matrix is less than the other matrix:
bool SquareMat::operator<(const SquareMat &other_sm) const
{
    return this->matrixSum() < other_sm.matrixSum();
}

// Function to check if the sum of elements in this matrix is greater than or equal to the other matrix:
bool SquareMat::operator>=(const SquareMat &other_sm) const
{
    return this->matrixSum() >= other_sm.matrixSum();
}

// Function to check if the sum of elements in this matrix is less than or equal to the other matrix:
bool SquareMat::operator<=(const SquareMat &other_sm) const
{
    return this->matrixSum() <= other_sm.matrixSum();
}

// Function to calculate the determinant of the matrix:
double SquareMat::operator!() const
{
    if (this->n == 1)
    {
        return this->data[0][0]; // Determinant of a 1x1 matrix is the value itself
    }
    else if (this->n == 2)
    {
        return (this->data[0][0] * this->data[1][1]) - (this->data[0][1] * this->data[1][0]); // Determinant of a 2x2 matrix is ad - bc
    }
    else // For larger matrices, use the Laplace expansion(O(n!)):
    {
        int det = 0;
        for (int i = 0; i < this->n; i++)
        {
            SquareMat subMatrix(this->n - 1); // Create a submatrix of size n-1 for the determinant calculation

            // Fill the submatrix(subMatrix) with the values of the original matrix(this->data):
            // Exclude the first row and the i-th column:
            for (int j = 1; j < this->n; j++) // Start from the second row
            {
                for (int k = 0; k < this->n; k++)
                {
                    // Exclude the i-th column(no condition for k==i):
                    if (k < i)
                    {
                        subMatrix.data[j - 1][k] = this->data[j][k];
                    }
                    else if (k > i)
                    {
                        subMatrix.data[j - 1][k - 1] = this->data[j][k];
                    }
                }
            }
            // Determinant of the minor matrix created by removing row 0 and column i
            int minor_det = !subMatrix;                                         // Call the operator!() on the submatrix to get its determinant
            det = det + ((i % 2 == 0) ? 1 : -1) * this->data[0][i] * minor_det; // Add or subtract the determinant of the minor matrix(recursive call)
        }
        return det;
    }
}

// Non member function - output operator: prints the matrix to the console
namespace mat_ns
{
    ostream &operator<<(ostream &os, const SquareMat &matrix)
    {
        matrix.printMatrix(os);
        return os;
    }
}
// Adds another matrix to this matrix
// This function modifies the current matrix (this) by adding another matrix (other_sm) to it
SquareMat &SquareMat::operator+=(const SquareMat &other_sm)
{
    if (this->n != other_sm.n)
    {
        throw "Matrices are not the same size.";
    }

    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            this->data[i][j] += other_sm.data[i][j];
        }
    }
    return *this;
}

// Subtracts another matrix from this matrix:
// This function modifies the current matrix (this) by subtracting another matrix (other_sm) from it
SquareMat &SquareMat::operator-=(const SquareMat &other_sm)
{
    if (this->n != other_sm.n)
    {
        throw "Matrices are not the same size.";
    }

    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            this->data[i][j] -= other_sm.data[i][j];
        }
    }
    return *this;
}

// Multiplies this matrix by another matrix:
// This function modifies the current matrix (this) by multiplying it with another matrix (other)
SquareMat &SquareMat::operator*=(const SquareMat &other_sm)
{
    if (this->n != other_sm.n)
    {
        throw "Matrices are not the same size.";
    }

    SquareMat result(this->n); // Create a new matrix to store the result

    for (int i = 0; i < this->n; i++) // for each row in A
    {
        for (int j = 0; j < this->n; j++) // for each column in B
        {
            result.data[i][j] = 0;
            for (int k = 0; k < this->n; k++) // For the dot product
            {
                result.data[i][j] = result.data[i][j] + (this->data[i][k] * other_sm.data[k][j]);
            }
        }
    }
    *this = result; // Update the current matrix with the result
    return *this;
}

// Divides this matrix by another matrix:
// This function modifies the current matrix (this) by dividing it with another matrix (other)
SquareMat &SquareMat::operator/=(const SquareMat &other_sm)
{
    if (this->n != other_sm.n)
    {
        throw "Matrices are not the same size.";
    }

    SquareMat result(this->n); // Create a new matrix to store the result

    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            if (other_sm.data[i][j] == 0)
            {
                throw "Division by zero.";
            }
            result.data[i][j] = this->data[i][j] / other_sm.data[i][j];
        }
    }
    *this = result; // Update the current matrix with the result
    return *this;
}

// Applies element-wise modulo operation between this matrix and another matrix:
// This function modifies the current matrix (this) by applying modulo operation with another matrix (other)
SquareMat &SquareMat::operator%=(const SquareMat &other_sm)
{
    if (this->n != other_sm.n)
    {
        throw "Matrices are not the same size.";
    }

    // Perform element-wise modulo operation
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            this->data[i][j] = fmod(this->data[i][j], other_sm.data[i][j]);
        }
    }

    return *this;
}
