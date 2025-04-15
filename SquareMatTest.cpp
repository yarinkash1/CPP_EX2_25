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

    // Make sure other values are still 0
    CHECK(mat.getValue(0, 0) == 0);
    CHECK(mat.getValue(2, 2) == 0);
}