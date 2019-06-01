#include <iostream>
#include <string>
#include <windows.h>
#include <sstream>
#include <fstream>

#include "class.h"

using namespace std;

ruch MAP::player0gfx()
{
    fstream plik1;
    string xD;
    ruch R;
    int realid=99;

    R.team = act;

    mapsend();

    R.o.x =-1;
    R.o.y =-1;

    for(;;)
    {
        while(!((realid>=0)&&(realid<=11)))
        {
            R.o = posfromfile();
            Sleep(100);

            //cout<<R.o.x<<endl;
            //cout<<R.o.y<<endl;


            if(R.o.good()&&polehelp(R.o)!=2) R.id = scanid(R.o);
            else R.id = 9999;

            if((act==0)&&(Realid(R.id)!=R.id)) R.id=9999;
            if((act==1)&&(Realid(R.id)==R.id)) R.id=9999;

            realid = Realid(R.id);
        }

        R.show();
        mapsend(1,1);
        plik1.open("c.txt", ios::out | ios::trunc);
        plik1.close();

        realid = Realid(R.id);
        R.n.x = 9;
        R.n.y = 9;

        while(!R.n.good())
        {
            R.n = posfromfile();
            Sleep(100);
        }

        mapsend(1);
        //plik1.open("c.txt", ios::out | ios::trunc);
        //plik1.close();

        if(act==0) R.o = T0[realid].pozycja();
        else R.o = T1[realid].pozycja();

        //
        //R.show();
        //if(act==0) T0[realid].show();
        //else T1[realid].show();
        //

        if(possible(&R)) return R;
        else
        {
            cout<<"Ruch niemozliwy!\n";
        }


        realid=99;
    }
}

c MAP::posfromfile()
{
    c p;
    fstream plik1;
    string linia="";

    p.x=9; p.y = 9;



    int i=0;

    plik1.open("c.txt", ios::in);
    while (getline(plik1, linia))
    {
        istringstream iss (linia);

        if(i==0) iss >> p.x;
        if(i==1) iss >> p.y;

        i++;
    }

    plik1.close();

    //plik1.open("c.txt", ios::out | ios::trunc);
    //plik1.close();

    return p;
}
