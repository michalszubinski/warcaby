#include <iostream>
#include <cstdio>

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

void ruch::show()
{
    printf("ID: %d, OLD = (%d,%d), NEW = (%d,%d), BICIE = %d, BICIEID = %d, TEAM = %d, WARTOSC = %d\n",id,x,y,x,y,bicie,bicieid,team,wartoscruchu);
}
