#include <iostream>
#include <stdio.h>

#include "class.h"

using namespace std;

//_ob

_ob::_ob()
{
    this -> alive = 1;
    this -> damka = 0;
}

void _ob::setteam(bool t)
{
    this -> team = t;
    /*if(t==0) n0++;
    else n1++; TO LICZYLO ILOSC PIONKOW, ALE RACZEJ JEST NIE POTRZEBNE*/
}

void _ob::setpos(c P)
{
    pos = P;
}

void _ob::DAMKA()
{
    this -> damka = 1;
}

void _ob::show()
{
    printf("ID = %d, TEAM = %d, ALIVE = %d, (X,Y) = (%d,%d), DAMKA = %d\n",id,team,alive,pos.x,pos.y,damka);
}

void _ob::setid(int ID)
{
    this -> id = ID;
}

bool _ob::a()
{
    if((this -> alive)==1) return 1;
    else return 0;
}

void _ob::kill()
{
    (this -> alive) = 0;
}

bool _ob::czydamka()
{
    return this -> damka;
}
int _ob::dorendera_x()
{
  return pos.x;
}
int _ob::dorendera_y()
{
  return pos.y;
}

c _ob::pozycja()
{
    return pos;
}

int _ob::getid()
{
    return this -> id;
}
