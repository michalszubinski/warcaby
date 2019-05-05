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
    if(g00d(0)==1)
    {
        T[0].EndV(0);
        T[1].EndV(1);
    }

    else if(g00d(0)==2)
    {
        T[0].EndV(1);
        T[1].EndV(0);
    }

    else if(g00d(0)==3)
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
           board[T0[i].dorendera_y()][T0[i].dorendera_x()]='b';
        }
        else
        {
          board[T0[i].dorendera_y()][T0[i].dorendera_x()]='B';
        }
        }

         if((T1[i].a())==1)
         {
             if((T1[i].czydamka())==0)
         {
             board[T1[i].dorendera_y()][T1[i].dorendera_x()]='c';
         }
           else
           {
            board[T1[i].dorendera_y()][T1[i].dorendera_x()]='C';
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
cout<<"X\n\n";
   for(int a=0;a<8;a++)

   {cout<<a<<" ";
       for(int i=1;i<9;i++)
   {
     cout<<board[a][i-1]<<"_|";
   }
    cout<<"\n";
   }
   cout<<"\nY";
for(int i=0;i<=7;i++)
{
  cout<<"  "<<i;
}

}
ruch MAP::decide(bool Tt)
{
    terazbicie = czyjakiesbicie(Tt);
    
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
void MAP::changer(ruch abc)
{

}
int MAP::kruch()
{

}
int MAP::g00d(bool czy_wyswietlac)
{
    int zmienna_pomocnicza=1,exit=0;
  for(int i=0;i<8;i++)//wygrali biali-nie ma zadnego czarnego pionka lub damki na szachownicy
  {
      for (int a=0;a<8;a++)
      {
          if(board[i][a]=='c'|| board[i][a]=='C')
          {
                zmienna_pomocnicza=0;
                exit=1;
                break;
          }
          if(exit) break;
      }
  }
  if(zmienna_pomocnicza)
  {
   if(czy_wyswietlac) cout<<"\nKoniec gry-Wygrala druzyna bialych";
      return 1;
  }

 for(int i=0;i<8;i++)//wygrali czarni-nie ma zadnego czarnego pionka lub damki na szachownicy
  {
      for (int a=0;a<8;a++)
      {
          if(board[i][a]=='b'|| board[i][a]=='B')
          {
                zmienna_pomocnicza=0;
                exit=1;
                break;
          }
          if(exit) break;
      }
  }
    if(zmienna_pomocnicza)
  {
     if(czy_wyswietlac) cout<<"\nKoniec gry-Wygrala druzyna czarnych!";
      return 2;
  }

  ruch abc_pomocniczy; //do sprawdzenia czy mozna wykonac jakis ruch
 if(act==1) //sprawdzam mozliwosc ruchu dla bialych
 {
     for(int i=0;i<8;i++)
     {
         for(int a=0;a<8;a++)
         {
             if(board[a][i]=='b') //szuka dowolnego bialego pionka i spr. czy mozna wykonac nim ruch //damka jesli damka nie moze sie ruszyc o 1 lub o dwa pola to nie moze sie ruszyc wogole
              {
                abc_pomocniczy.o.x=a;
                abc_pomocniczy.o.y=i;
                 for(int q=0;q<12;q++)
                  {
                    if(T0[q].dorendera_x()==a)
                    {
                        if(T0[q].dorendera_y()==i)
                        {
                            abc_pomocniczy.id=T0[q].getid();
                            abc_pomocniczy.team=0;
                        }
                     }

                  }
                abc_pomocniczy.n.x=a+1; //czy pionek bialy moze sie ruszyc o jeden w prawo
                abc_pomocniczy.n.y=i+1;
               if(possible(abc_pomocniczy))return 0; //gra toczy sie dalej jest mozliwy ruch
                abc_pomocniczy.n.x=a+1;  //czy pionek moze sie ruszyc o 1 w lewo
                abc_pomocniczy.n.y=i-1;
                if(possible(abc_pomocniczy))return 0;
                abc_pomocniczy.n.x=a+2;  //spr. czy pionek moze zbic w prawo
                abc_pomocniczy.n.y=i+2;
               if(possible(abc_pomocniczy))return 0;
                abc_pomocniczy.n.x=a+2; //spr. czy pionek moze zbic w lewo
                abc_pomocniczy.n.y=i-2;
               if(possible(abc_pomocniczy))return 0;

             }
             if(board[a][i]=='B') //dla damki spr. mozliwosci jak dla pionka bialego i czarnego, bo damka moze sie ruszac i do przodu i do tylu
             {abc_pomocniczy.o.x=a;
                abc_pomocniczy.o.y=i;
                 for(int q=0;q<12;q++)
                  {
                    if(T0[q].dorendera_x()==a)
                    {
                        if(T0[q].dorendera_y()==i)
                        {
                            abc_pomocniczy.id=T0[q].getid();
                            abc_pomocniczy.team=0;
                        }
                     }

                  }
                abc_pomocniczy.n.x=a+1;
                abc_pomocniczy.n.y=i+1;
               if(possible(abc_pomocniczy))return 0;
                abc_pomocniczy.n.x=a+1;
                abc_pomocniczy.n.y=i-1;
                if(possible(abc_pomocniczy))return 0;
                abc_pomocniczy.n.x=a+2;
                abc_pomocniczy.n.y=i+2;
               if(possible(abc_pomocniczy))return 0;
                abc_pomocniczy.n.x=a+2;
                abc_pomocniczy.n.y=i-2;
               if(possible(abc_pomocniczy))return 0;
               abc_pomocniczy.n.x=a-1;
                abc_pomocniczy.n.y=i+1;
               if(possible(abc_pomocniczy))return 0;
                abc_pomocniczy.n.x=a-1;
                abc_pomocniczy.n.y=i-1;
                if(possible(abc_pomocniczy))return 0;
                abc_pomocniczy.n.x=a-2;
                abc_pomocniczy.n.y=i+2;
               if(possible(abc_pomocniczy))return 0;
                abc_pomocniczy.n.x=a-2;
                abc_pomocniczy.n.y=i-2;
               if(possible(abc_pomocniczy))return 0;

             }

         }
     }
 }
 else
 {
for(int i=0;i<8;i++)
   {
         for(int a=0;a<8;a++)
         {
             if(board[a][i]=='c')
              {
                abc_pomocniczy.o.x=a;
                abc_pomocniczy.o.y=i;
                for(int q=0;q<12;q++)
                  {
                    if(T0[q].dorendera_x()==a)
                    {
                        if(T0[q].dorendera_y()==i)
                        {
                            abc_pomocniczy.id=T0[q].getid();
                            abc_pomocniczy.team=1;
                        }
                     }
                  }
                abc_pomocniczy.n.x=a-1; //czy pionek  moze sie ruszyc o jeden w prawo
                abc_pomocniczy.n.y=i+1;
               if(possible(abc_pomocniczy))return 0; //gra toczy sie dalej jest mozliwy ruch
                abc_pomocniczy.n.x=a-1;  //czy pionek moze sie ruszyc o 1 w lewo
                abc_pomocniczy.n.y=i-1;
                if(possible(abc_pomocniczy))return 0;
                abc_pomocniczy.n.x=a-2;  //spr. czy pionek moze zbic w prawo
                abc_pomocniczy.n.y=i+2;
               if(possible(abc_pomocniczy))return 0;
                abc_pomocniczy.n.x=a-2; //spr. czy pionek moze zbic w lewo
                abc_pomocniczy.n.y=i-2;
               if(possible(abc_pomocniczy))return 0;

             }
             if(board[a][i]=='C')
             {
                abc_pomocniczy.n.x=a+1;
                abc_pomocniczy.n.y=i+1;
               if(possible(abc_pomocniczy))return 0;
                abc_pomocniczy.n.x=a+1;
                abc_pomocniczy.n.y=i-1;
                if(possible(abc_pomocniczy))return 0;
                abc_pomocniczy.n.x=a+2;
                abc_pomocniczy.n.y=i+2;
               if(possible(abc_pomocniczy))return 0;
                abc_pomocniczy.n.x=a+2;
                abc_pomocniczy.n.y=i-2;
               if(possible(abc_pomocniczy))return 0;
               abc_pomocniczy.n.x=a-1;
                abc_pomocniczy.n.y=i+1;
               if(possible(abc_pomocniczy))return 0;
                abc_pomocniczy.n.x=a-1;
                abc_pomocniczy.n.y=i-1;
                if(possible(abc_pomocniczy))return 0;
                abc_pomocniczy.n.x=a-2;
                abc_pomocniczy.n.y=i+2;
               if(possible(abc_pomocniczy))return 0;
                abc_pomocniczy.n.x=a-2;
                abc_pomocniczy.n.y=i-2;
               if(possible(abc_pomocniczy))return 0;
             }
          }

   }
 }
if(czy_wyswietlac) cout<<"\nKoniec gry-Remis";
 return 3; //jest remis
}
void MAP::TURN()
{
    ruch abc;
    int exit=1; //zmienna potrzebna do wyjscia z glownej petli jesli funckja g00d() zwraca wartosc 0
     //stary decide przeniesiony do konstruktora
   while(1)
   {

    act=1;
    abc = decide(0);
    changer(abc);
    if(g00d(1)) break;
    while(kruch()==1)
    {
    abc = decide(0);
    changer(abc);
        if(g00d(1))
        {
          exit =0;
          break;
        }
    }
    if(exit==0)break;
      act=0;
      abc = decide(1);
       changer(abc);
        if(g00d(1)) break;
       while(kruch()==1)
       {
    abc = decide(1);
      changer(abc);
       if(g00d(1))
       {
           exit=0;
           break;
       }
       if(exit==0)break;
       }
    }
}

/*void MAP::GAME() // DLA WERSJI 2
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



