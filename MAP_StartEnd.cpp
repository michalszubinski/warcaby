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

        int wybor;
        cout<<"Kto ma grac bialymi?\n0-gracz \n1-random\n2-minimax\n";
        cin >>wybor;
        T[0].setplayertype(wybor);
        cout<<"Kto ma grac czarnymi?\n0-gracz \n1-random\n2-minimax\n";
        cin >>wybor;
        T[1].setplayertype(wybor);
        system("CLS"); //jesli nic wczesniej ma nie wyskakiwac
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

    //GAME(); // DLA WERSJI NR 2
}

MAP::~MAP() // MAP_StartEnd.cpp
{
    if(g00d()==1)
    {
        T[0].EndV(0);
        T[1].EndV(1);
    }

    else if(g00d()==2)
    {
        T[0].EndV(1);
        T[1].EndV(0);
    }

    else if(g00d()==3)
    {
        T[0].EndV(2);
        T[1].EndV(2);
    }


    T[0].StatsToFile();
    T[1].StatsToFile();
}
void MAP::render()
{


    for(int i=0;i<12;i++)
    {
        if((T0[i].a())==1)
        {
            if(T0[i].czydamka()==0)
        {
           board[T0[i].dorendera_x()][T0[i].dorendera_y()]='b';
        }
        else
        {
          board[T0[i].dorendera_x()][T0[i].dorendera_y()]='B';
        }
        }

         if((T1[i].a())==1)
         {
             if((T1[i].czydamka())==0)
         {
             board[T1[i].dorendera_x()][T1[i].dorendera_y()]='c';
         }
           else
           {
            board[T1[i].dorendera_x()][T1[i].dorendera_y()]='C';
           }
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
cout<<"Y\n\n";
   for(int a=0;a<8;a++)

   {cout<<a<<" ";
       for(int i=1;i<9;i++)
   {
     cout<<board[a][i-1]<<"_|";
   }
    cout<<"\n";
   }
   cout<<"\nX";
for(int i=0;i<=7;i++)
{
  cout<<"  "<<i;
}

}
ruch MAP::decide(bool Tt)
{
    ruch abc;

    if(T[Tt].getpt()==0) abc=player0(); //sprawdza ktory gracz gra bialymi czyli minimax,czlowiek,random
    else if(T[Tt].getpt()==1) abc=player1();
    else if(T[Tt].getpt()==2) abc=player2();

    return abc;
}

ruch MAP::player0()
{

}
ruch MAP::player1()
{

}
ruch MAP::player2()
{

}
void MAP::changer(struct ruch abc)
{

}
int MAP::kruch()
{

}
int MAP::g00d()
{


}
void MAP::TURN()
{
    ruch abc;
    int exit=1; //zmienna potrzebna do wyjscia z glownej petli jesli funckja g00d() zwraca wartosc 0
     //stary decide przeniesiony do konstruktora
   while(1)
   {


    abc = decide(0);
    changer(abc);
    if(g00d()) break;
    while(kruch()==1)
    {
    abc = decide(0);
    changer(abc);
        if(g00d())
        {
          exit =0;
          break;
        }
    }
    if(exit==0)break;

      abc = decide(1);
       changer(abc);
        if(g00d()) break;
       while(kruch()==1)
    {
    abc = decide(1);
      changer(abc);
       if(g00d())
       {
           exit=0;
           break;
       }
       if(exit==0)break;
    }
    }
   }

*/void MAP::GAME() // DLA WERSJI 2
{

    //T0[2].DAMKA();
    //T0[1].kill();
    //T0[2].show();
    //T0[1].show();

    //T1[2].DAMKA();
    //T1[1].kill();
    //T1[2].show();
    //T1[1].show();


    render();

    while(!g00d())
    {
        TURN();
        system("cls");
        render();
        act = kruch();
    }

    system("cls");
    render();
}

void MAP::TURN()
{
    ruch abc;

    abc = decide(act);
    changer(abc);
    kruch();
} WERSJA NR2 GRY */



