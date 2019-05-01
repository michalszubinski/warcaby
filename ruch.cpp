#include <iostream>

#include "class.h"

using namespace std;

//ruch
bool ruch::operator==(ruch other)
{
    if((((this -> o)==(other.o))&&((this -> n)==(other.n))&&((this -> wartoscruchu)==(other.wartoscruchu))&&((this -> id)==(other.id))&&((this -> bicie)==(other.bicie))&&((this -> bicieid)==(other.bicieid)))) return 1;
    else return 0;
}

bool ruch::operator!=(ruch other)
{
    if((((this -> o)==(other.o))&&((this -> n)==(other.n))&&((this -> wartoscruchu)==(other.wartoscruchu))&&((this -> id)==(other.id))&&((this -> bicie)==(other.bicie))&&((this -> bicieid)==(other.bicieid)))) return 0;
    else return 1;
}
