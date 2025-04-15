#include "SquareMat.hpp"

using namespace mat_ns;

SquareMat::SquareMat(int dimension) : n(dimension) // Initializer list constructor
{
    data = new int *[n]; // Allocate an array the size of the input dimension

    // Allocate each row with n columns(n x n size matrix):
    for (int i = 0; i < n; i++)
    {
        data[i] = new int[n];

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
    data = new int *[n]; // Allocate an array the size of the input dimension

    // Allocate each row with n columns(n x n size matrix):
    for (int i = 0; i < n; i++)
    {
        data[i] = new int[n];

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
    data = new int*[n];

    // Allocate and copy:
    for (int i = 0; i < n; i++)
    {
        data[i] = new int[n];

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

void SquareMat::setValue(int i, int j, int value)
{
    if (areOutOfBounds(i, j) == false)
    {
        this->data[i][j] = value;
        return;
    }
    throw "Indexes are out of bounds.";
}

int SquareMat::getValue(int i, int j)
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
void SquareMat::printMatrix() const
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

//Function to add two matrices:
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

//Function to subtract two matrices:
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

//Function to negate a matrix:
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

//Function to multiply two matrices(O(n^3)):
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

//Member function to multiply a matrix by a scalar (matrix * scalar):
SquareMat SquareMat::operator*(int scalar) const
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
SquareMat operator*(int scalar, const SquareMat &matrix)
{
    return matrix * scalar; // Reuse the member function (:
}

//Function to multiply two matrices element-wise:
SquareMat SquareMat::operator%(const SquareMat &other_sm) const
{
    if (this->n != other_sm.n)
    {
        throw "Matrices are not the same size.";
    }

    SquareMat result(this->n); // Create a new matrix to store the result

    for(int i=0; i<this->n; i++)
    {
        for(int j=0; j<this->n; j++)
        {
            result.data[i][j] = this->data[i][j] * other_sm.data[i][j];
        }
    }
    return result;
}

//Function to apply modulo to each element in the matrix (element % scalar):
SquareMat SquareMat::operator%(int scalar) const
{
    SquareMat result(this->n); // Create a new matrix to store the result

    for (int i = 0; i < this->n; i++)
    {
        for (int j = 0; j < this->n; j++)
        {
            result.data[i][j] = this->data[i][j] % scalar;
        }
    }
    return result;
}