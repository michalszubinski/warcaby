#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>

#include "class.h"

using namespace std;

void MAP::mapsend( bool zaz, bool ziel,int g00d)
{
    fstream plik1;
    stringstream ss;
    string linia;


    plik1.open("mapa.txt", ios::out | ios::trunc);

    for(int x=0; x<8;x++)
    {
        for(int y=0;y<8;y++)
        {

            plik1<<board[x][y]<<endl;
        }
    }

    plik1<<g00d<<endl;
    plik1<<zaz<<endl;
    plik1<<ziel;

    plik1.close();
}

void MAP::gfxini()
{
    bSuccess = CreateProcess(TEXT("cabyshow.exe"),NULL,NULL,NULL,FALSE,NULL,NULL,NULL,&startInfo,&processInfo);

    if(bSuccess)
    {
        cout<<"Proces grafiki utworzono z sukcesem!\n";
    }
}

void MAP::gfxclose()
{
    CloseHandle( processInfo.hProcess );
    CloseHandle( processInfo.hThread );
}
