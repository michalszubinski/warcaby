#include <iostream>

#include "class.h"

using namespace std;

//team
team::team(bool tea, char playertype, string name)
{
    setplayertype(playertype);
    StatsFromFile();
    this -> t = tea;
}

team::~team()
{
    StatsToFile();
}

void team::setplayertype(char T)
{
    switch(T)
    {
    case 0: this -> playertype = T; break; //Gracz
    case 1: this -> playertype = T; break; //Randomowe
    case 2: this -> playertype = T; break; //Minimax
    case 3: this -> playertype = T; break; // Samouk
    default: this -> playertype = 1; break;
    }
}

string team::getplayertype()
{
    string ret="";
    switch(this -> playertype)
    {
    case 0: ret = "Gracz"; break; //Gracz
    case 1: ret = "AI (RANDOM)"; break; //Randomowe
    case 2: ret = "AI (RANDOM)"; break; //Minimax
    case 3: ret = "AI (RANDOM)"; break; // Samouk
    default: ret = "wtf"; break;
    }
    ret+=" | ";
    switch(this -> t)
    {
    case 0: ret+= "Druzyna 0";break;
    case 1: ret+= "Druzyna 1";break;
    default: ret = "wtf"; break;
    }
    return ret;
}

bool team::gett()
{
    return (this -> t);
}

char team::getpt()
{
    return (this -> playertype);
}

void team::StatsFromFile()
{
    //TUTAJ BEDZIE WCZYTYWALO STATYSTYKI Z PLIKU
}

void team::StatsToFile()
{
    //TUTAJ BEDZIE ZAPISYWALO STATYSTYKI Z PLIKU
}
