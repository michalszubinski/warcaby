#include <iostream>
#include <windows.h>

#include "class.h"

using namespace std;

//MAP() i ~MAP()

MAP::MAP()  // MAP_StartEnd.cpp
{
    ActBicie=0;
    terazbicie=0;
    act=0;

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
    TURN();
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
czyszczenie_planszy();
wczytywanie_planszy();
wyswietlanie_planszy();

}
void MAP::czyszczenie_planszy()
{
   for(int i=0;i<8;i++)
   {
       for(int a=0;a<8;a++) board[i][a]=' ';
   }
}
void MAP::wczytywanie_planszy()
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
}
void MAP:: wyswietlanie_planszy()
{
  cout<<"Y\n\n";
   for(int a=0;a<8;a++)

   {cout<<7-a<<" ";
       for(int i=1;i<9;i++)
   {
     cout<<board[7-a][i-1]<<"_|";
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
    terazbicie = czyjakiesbicie(act);

    ruch abc;

    cout<<"\nterazbicie = "<<terazbicie<<endl;
    cout<<"ActBicie = "<<ActBicie<<endl;

    if(T[Tt].getpt()==0) abc=player0(); //sprawdza ktory gracz gra bialymi czyli minimax,czlowiek,random
    else if(T[Tt].getpt()==1) abc=player1();
    else if(T[Tt].getpt()==2) abc=player2();

    return abc;
}
// player0 jest w MAP_player0.cpp
ruch MAP::player1()
{

}
ruch MAP::player2()
{

}
void MAP::changer(ruch abc)
{
    if(abc.bicie==1)
    {
        if(Teamprzeciwny(act)==0) T0[abc.bicieid].kill();
        else T1[Realid(abc.bicieid)].kill();

        ActBicie = 1;
    }

    if(act==0) T0[abc.id].setpos(abc.n);
    else T1[Realid(abc.id)].setpos(abc.n);

    if((abc.team==0) && (T0[abc.id].dorendera_y()==7)) T0[abc.id].DAMKA();

    if((abc.team==1) && (T1[Realid(abc.id)].dorendera_y()==0)) T1[Realid(abc.id)].DAMKA();

    update(abc.id,abc.o);
    if(abc.bicie==1) update(abc.bicieid,abc.p);

    if(ActBicie==1) ActBicie = mozliwoscbicia(Realid(abc.id),act);

czyszczenie_planszy();
wczytywanie_planszy();
wyswietlanie_planszy();

}
bool MAP::kruch()
{
    bool zmienna;

    if(ActBicie==1) zmienna = act;
    else zmienna = Teamprzeciwny(act);

    act = zmienna;
//cout<<"zmienna"<<zmienna;
    return zmienna;
}

int MAP::g00d(bool czy_wyswietlac)
{

 int wygrana=czy_wygrana(),remis;
 //cout<<"zmienna wygrana"<<wygrana;

 if(wygrana==1) //mozna jeszce wykorzystac act
  {
   if(czy_wyswietlac) cout<<"\nKoniec gry-Wygrala druzyna bialych";
      return 1;
  }
   if(wygrana==2)
  {
     if(czy_wyswietlac) cout<<"\nKoniec gry-Wygrala druzyna czarnych!";
      return 2;
  }
if(act==1)remis=czyremis1(); //sprawdzam czy czarne beda mogly sie ruszyc
else remis=czyremis0();
if(remis==3)
 {
 if(czy_wyswietlac) cout<<"\nKoniec gry-Remis";
 return 3; //jest remis
 }
return 0;
}
int MAP::czyremis1()
{
 for(int i=0;i<12;i++)
    {
        if(mozliwoscbicia(i,1,0)==1||mozliwoscbicia(i,1,1)==1)return 0;
    }
 return 3;
  }


int MAP::czyremis0()
{
    for(int i=0;i<12;i++)
    {
        if(mozliwoscbicia(i,0,0)==1||mozliwoscbicia(i,0,1)==1)return 0;
    }
 return 3;

}
int MAP::czy_wygrana()
{
    int zmienna_pomocnicza=1;
    for(int i=0;i<12;i++) //wygrali czarni
    {
       if(T0[i].a()==1)
       {
           zmienna_pomocnicza=0;
           break;
        }

    }
    if(zmienna_pomocnicza) return 2;
    zmienna_pomocnicza=1;
    for(int i=0;i<12;i++) //wygrali biali
    {
       if(T1[i].a()==1)
       {
           zmienna_pomocnicza=0;
           break;
        }

    }
    if(zmienna_pomocnicza) return 1;
return 0;
}
/*
void MAP::TURN()
{
    ruch abc;
    int exit=1; //zmienna potrzebna do wyjscia z glownej petli jesli funckja g00d() zwraca wartosc 0
     //stary decide przeniesiony do konstruktora
render();
   while(1)
   {

    //act=0;
    abc = decide(0);
    changer(abc);
    if(g00d(1)) break;
    while(kruch()==0)
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
      //act=1;
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
*/
void MAP::TURN()
{

ruch abc;
    int exit=1; //zmienna potrzebna do wyjscia z glownej petli jesli funckja g00d() zwraca wartosc 0
     //stary decide przeniesiony do konstruktora
render();
   while(1)
   {

    //act=0;
    abc = decide(act);
    //if(g00d(1)) break;
    changer(abc);
    kruch();
    if(g00d(1))
    {exit=0;
        break;}
        if(exit==0)break;

}
}
void MAP::GAME()
{
    render();

    while(!g00d())
    {
        TURN2();
        render();
        showALL();
    }

    system("cls");
    render();
}

void MAP::TURN2()
{
    ruch abc;

    abc = decide(act);
    changer(abc);
    act = kruch();
}

void MAP::showALL()
{
    for(int i=0;i<12;i++)
    {
        T0[i].show();
        T1[i].show();
    }
}

void MAP::update(int id, c S)
{
    int realid = Realid(id);

    if(act==0)//biale
    {
        board[S.y][S.x]=' ';
    }
    else //czarne
    {
        board[S.y][S.x]=' ';
    }

    if(act==0)//biale
    {
        if(T0[realid].a())
        {
            if(T0[realid].czydamka())
            {
                board[T0[realid].dorendera_y()][T0[realid].dorendera_x()]='B';
            }
            else
            {
                board[T0[realid].dorendera_y()][T0[realid].dorendera_x()]='b';
            }
        }
    }
    else //czarne
    {
        if(T1[realid].a())
        {
            if(T1[realid].czydamka())
            {
                board[T1[realid].dorendera_y()][T1[realid].dorendera_x()]='C';
            }
            else
            {
                board[T1[realid].dorendera_y()][T1[realid].dorendera_x()]='c';
            }
        }
    }
}
