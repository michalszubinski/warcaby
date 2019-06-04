#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include "class.h"

using namespace std;

//MAP() i ~MAP()

MAP::MAP()  // MAP_StartEnd.cpp
{
    cout<<"GRA WARCABY"<<endl;
    cout<<"Wykonali:\nMichal Szubinski\nKamil Stepien\nKrzysztof Kruszynski";
    bool czypusty=T[0].czyplikjestpusty();
    int cowybrac=menu(czypusty);
    if(!czypusty)
    {
        if(cowybrac==1)gra();
        if(cowybrac==2)wczytujestatystyki();
        if(cowybrac==3)exit(0);
    }
    else
    {
        if(cowybrac==1)gra();
        if(cowybrac==2)exit(0);
    }





}

void MAP::statystykidopliku() // MAP_StartEnd.cpp
{
    if(gfx) gfxclose();

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
    if(gfx) {gfxclose(); mapsend(0,0,1);}
}
int MAP::menu(bool cowyswietlac)
{
    int wybor;
    if(!cowyswietlac)
    {
       cout<<"\n\nMENU:\n1.NOWA GRA\n2.WCZYTAJ STATYSTYKI\n3.WYJDZ Z PROGRAMU\n";
  cin>>wybor;
  return wybor;
    }
    else
    {
       cout<<"\n\nMENU:\n1.NOWA GRA\n2.WYJDZ Z PROGRAMU\n";
       cin>>wybor;
       return wybor;
    }

}
void MAP::gra()
{
    system("cls");

    fstream plik1;

    plik1.open("c.txt", ios::out | ios::trunc);
    plik1.close();

    ActBicie=0;
    terazbicie=0;
    act=0;

    T[0].setteam(0);
    T[1].setteam(1);

    {
        string x="";

        cout<<"Nazwa druzyny bialej\n"; cin>>x;
        T[0].setteamname(x);

        cout<<"\nNazwa druzyny czarnej\n"; cin>>x;
        T[1].setteamname(x);

        int wybor;

        cout<<"\nKto ma grac bialymi?\n0 - gracz \n1 - random\n2 - minimax\n";
        cin >>wybor;
        T[0].setplayertype(wybor);

        cout<<"\nKto ma grac czarnymi?\n0 - gracz \n1 - random\n2 - minimax\n";
        cin >>wybor;

        T[1].setplayertype(wybor);

        cout<<"\nTryb graficzny? wpisz 0 lub 1 \n";
        cin>>gfx;

        system("CLS"); //jesli nic wczesniej ma nie wyskakiwac
    }

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
    system("cls");

    //GAME(); // DLA WERSJI NR 2
   if(gfx)
    {
        mapsend();
        gfxini();
    }

    TURN();
}
void MAP::wczytujestatystyki()
{
    while(1)
{


    T[0].StatsFromFile();
    T[1].StatsFromFile();
    _getch();
    system("CLS");
    MAP();
}
}
void MAP::render()
{
czyszczenie_planszy();
wczytywanie_planszy();
if(!gfx) wyswietlanie_planszy();
if(gfx) mapsend();
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
  cout<<"Y\n";
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

    cout<<endl;
}
ruch MAP::decide(bool Tt)
{
    terazbicie = czyjakiesbicie(act);

    ruch abc;

    if(T[act].getpt()!=2)
    {
        //cout<<"\nterazbicie = "<<terazbicie<<endl;
        //cout<<"ActBicie = "<<ActBicie<<endl;
        /*cout<<"Ruch druzyny ";
        if(act==0) cout<<"bialych!"<<endl;
        else cout<<"czarnych!"<<endl;*/
    }


    if(T[Tt].getpt()==0) {
    if(!gfx) abc=player0();      if(gfx) abc=player0gfx();
    }//sprawdza ktory gracz gra bialymi czyli minimax,czlowiek,random
    else if(T[Tt].getpt()==1) abc=player1();
    else if(T[Tt].getpt()==2) {ruch Pusty; abc=player2(0,Pusty);}

    if(T[act].getpt()!=2)
    {
        abc.show();
        if(act==0) T0[abc.id].show();
        else T1[Realid(abc.id)].show();
    }

    if(T[0].getpt()&&T[1].getpt()) Sleep(200);

    system("cls");

    return abc;
}
// player0 jest w MAP_player0.cpp
// player1 jest w MAP_player1.cpp
// player2 tez
void MAP::changer(ruch abc,int czy_aktualizowac)
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

    if(ActBicie==1) ActBicie = OLDmozliwoscbicia(Realid(abc.id),act);

  if(czy_aktualizowac)
  {
    czyszczenie_planszy();
    wczytywanie_planszy();
    wyswietlanie_planszy();
    if(gfx) mapsend();
  }



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

 int wygrana=czy_wygrana();
 int remis;
 //cout<<"zmienna wygrana"<<wygrana;

 if(wygrana==1) //mozna jeszce wykorzystac act
  {
   if(czy_wyswietlac)
   {
       cout<<"\nKoniec gry - Wygrala druzyna bialych";
       _getch();
       system("CLS");
   }
         return 1;
  }
   if(wygrana==2)
  {
     if(czy_wyswietlac)
     {
         cout<<"\nKoniec gry - Wygrala druzyna czarnych!";
         _getch();
         system("CLS");
     }
      return 2;
  }

remis = czyremis(act);//sprawdzam czy czarne beda mogly sie ruszyc

if(remis==3)
 {
 if(czy_wyswietlac)
 {
     cout<<"\nKoniec gry - Remis";
     _getch();
     system("CLS");

 }
 return 3; //jest remis
 }
return 0;
}

int MAP::czyremis(bool t)
{
    for(int i=0;i<12;i++)
    {
        if(OLDmozliwoscbicia(i,t,0)==1) {/*cout<<"zwracam 0\n";*/ return 0;}
        if(OLDmozliwoscbicia(i,t,1)==1) {/*cout<<"zwracam 0\n";*/ return 0;}
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
while(1)
{
render();

   while(1)
   {
if(act==0)
{
    string x = T[0].returnteamname();
    x.erase(0,2);
    cout<<"\nDRUZYNA BIALYCH:\n"<<x<<"\nNA POSUNIECIU\n============\n";
}
else
{
    string x = T[1].returnteamname();
    x.erase(0,2);
    cout<<"\nDRUZYNA CZARNYCH:\n"<<x<<"\nNA POSUNIECIU\n============\n";
}
    //act=0;
    abc = decide(act);
    //if(g00d(1)) break;
    system("CLS");
    changer(abc);
    kruch();
    if(g00d(1))
    {exit=0;
        break;}
        if(exit==0)break;

     }
     statystykidopliku();
     MAP();
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
