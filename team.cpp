#include <iostream>
#include <fstream>
#include<string>
#include <cstdlib>
#include <sstream>

#include "class.h"

using namespace std;

//team
team::team(bool tea, char playertype, string name)
{
    setplayertype(playertype);
    this -> t = tea;
    this -> w = 0;
    this -> l = 0;
    this -> d = 0;
}

team::~team()
{

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
	string linia;
	fstream plik;
	plik.open("nowy.txt", ios::in);

	while (getline(plik, linia))
	{

		if (linia == name)
		{
			getline(plik, linia);
			w = w + atoi(linia.c_str());
			getline(plik, linia);
			l = l + atoi(linia.c_str());
			getline(plik, linia);
			d = d + atoi(linia.c_str());
		}
	}
	cout << "Nazwa druzyny" << name << endl;
	cout << "Wygrane: " << w << endl;
	cout << "Przegrane: " << l << endl;
	cout << "Remisy: " << d << endl;
	plik.close();
}

void team::StatsToFile()
{
    bool jest=0;
    fstream plik1;
    string linia;
    stringstream ss1,ss2,ss3;

    plik1.open("nowy.txt", ios::in);

    while (getline(plik1, linia))
	{
		if (linia == name)
        {
            jest = 1;
            break;
        }
	}

	plik1.close();

    if(!jest)
    {
        //cout<<"!JEST"<<endl;
        plik1.open("nowy.txt", ios::out | ios::app);
        plik1 << name << endl;
        plik1 << w << endl;
        plik1 << l << endl;
        plik1 << d << endl;

        plik1.close();
    }
    else
    {
        //cout<<"JEST"<<endl;
        string* nowy;
        int ile=0;

        plik1.open("nowy.txt", ios::in);

        while (getline(plik1, linia))
            ile++;

        plik1.close();

        if(ile>0)
        {
            nowy = new string[ile];

            int i=0;

            plik1.open("nowy.txt", ios::in);
            //cout<<"T PRE" <<endl;

            while (getline(plik1, linia))
            {
                nowy[i] = linia;
                //cout<<linia<<endl;
                i++;
            }

            plik1.close();

            for(int j=0; j<ile; j++)
            {
                if(nowy[j] == this->name)
                {
                    ss1 << w;
                    ss2 << d;
                    ss3 << l;
                    nowy[j+1] =  ss1.str();
                    nowy[j+2] =  ss2.str();
                    nowy[j+3] =  ss3.str();
                }
            }

            plik1.open("nowy.txt", ios::out | ios::trunc);

            //cout<<"T START"<<endl;

            for(int j=0; j<ile; j++)
                {plik1<<nowy[j]<<endl; /*cout<<nowy[j]<<endl;*/}

            plik1.close();

            delete [] nowy;
        }
    }
}

void team::setteam(bool TTT)
{
    this -> t = TTT;
}

void team::setteamname(string X) // ustawia nazwe druzyny
{
    X = ": " + X;
    this -> name = X;
}

void team::EndV(int X)
{
    switch(X)
    {
    case 0: w++; break;
    case 1: l++; break;
    case 2: d++; break;
    }
}
