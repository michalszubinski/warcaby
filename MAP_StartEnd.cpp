#include <iostream>

#include "class.h"

using namespace std;

//MAP() i ~MAP()

MAP::MAP()  // MAP_StartEnd.cpp
{
    T[0].setteam(0);
    T[1].setteam(1);

    {
        string x="";

        cout<<"Nazwa druzyny bialej\n"; cin>>x;
        T[0].setteamname(x);

        cout<<"Nazwa druzyny czarnej\n"; cin>>x;
        T[1].setteamname(x);
    }


    T[0].StatsFromFile();
    T[1].StatsFromFile();
    c help0, help1;

    act = 0;

    for(int i=0; i<12; i++)
    {
        T0[i].setteam(0);
        T1[i].setteam(1);

        T0[i].setid(i);
        T1[i].setid(i+12);

        if(((i>=0)&&(i<=3))||((i>=8)&&(i<=11))) // ustawianie pozycji pomocnicznej
        {
            help0.x = (i % 4) * 2;
            if(i<4) help0.y = 0;
            else help0.y=2;

            help1.x = help0.x + 1;
            if(i<4) help1.y = 7;
            else help1.y=5;
        }

        else if((i>=4)&&(i<=7))
        {
            help1.x = (i % 4) * 2;
            help0.y=1;

            help0.x = help1.x + 1;
            help1.y=6;
        }

        T0[i].setpos(help0); // ustawianie pozycji
        T1[i].setpos(help1);

        //T0[i].show();
        //T1[i].show();
    }

}

MAP::~MAP() // MAP_StartEnd.cpp
{
    /*if(g00d==1)
    {
        T[0].w++;
        T[1].l++;
    }

    else if(g00d==2)
    {
        T[0].l++;
        T[1].w++;
    }

    else if(g00d==3)
    {
        T[0].d++;
        T[1].d++;
    } TEN KOMENTARZ NALEZY USUNAC JAK POWSTANIE FUNCKJA g00d*/


    T[0].StatsToFile();
    T[1].StatsToFile();
}
void MAP::render()
{

    for(int i=0;i<12;i++)
    {
        if((T0[i].a())==1)
        {
        board[T0[i].dorendera_x()][T0[i].dorendera_y()]='b';
        }

         if((T0[i].a())==1)
         {
            board[T1[i].dorendera_x()][T1[i].dorendera_y()]='c';
         }
    }
    for(int i=0;i<9;i++)
    {
        for(int a=0;a<9;a++)
    {
       if(board[i][a]=='c'||board[i][a]=='b');
       else
        {
        board[i][a]=' ';
       }

    }
   }
for(int a=1;a<9;a++)
{cout<<9-a<<" ";
       for(int i=1;i<9;i++)
   {
     cout<<board[a-1][i-1]<<"_|";
   }
    cout<<"\n";
}
for(char i='a';i<='h';i++)
{
  cout<<"  "<<i;
}

}
