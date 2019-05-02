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

bool c::good()
{
    if(((this -> x)>0)&&((this -> x)<8)&&((this -> y)>0)&&((this -> y)<8)) return 1;

    return 0;
}
