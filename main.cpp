#include <iostream>

#include "ggen.h"
#include "stlObject.h"

int main()
{
    StlObject cube;
    cube.readFromFile("./beczka.stl");

    return 0;
}