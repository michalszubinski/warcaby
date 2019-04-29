#include <iostream>

#include "class.h"

using namespace std;

//c
bool c::operator==(c other)
{
    if((((this -> x)==(other.x))&&((this -> y)==(other.y)))) return 1;
    else return 0;
}

bool c::operator!=(c other)
{
    if((((this -> x)==(other.x))&&((this -> y)==(other.y)))) return 0;
    else return 1;
}
