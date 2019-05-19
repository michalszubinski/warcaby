#include <iostream>
#include <string>

#include "class.h"

using namespace std;

int MAP::ocen(ruch R) // NIECH OCEN BEDZIE INTEM, ZWROCI WARTOSC RUCHU
{
     int suma=0;
    c p;

    for(int i=0;i<12;i++)
    {
       p=R.n;
    if (p.x==0&&(p.y==1||p.y==2||p.y==3||p.y==4||p.y==5||p.y==6||p.y==7))
        {
            suma=suma++;
        }
     if(p.y==0&&(p.x==0||p.x==1||p.x==2||p.x==3||p.x==4||p.x==5||p.x==6||p.x==7))
     {
         suma=suma++;
     }
     if(p.x=7&&(p.y==0||p.y==1||p.y==2||p.y==3||p.y==4||p.y==5||p.y==6||p.y==7))
     {
         suma=suma++;
     }
     if(p.y==7&&(p.x==1||p.x==2||p.x==3||p.x==4||p.x==5||p.x==6))
     {
         suma=suma++;
     }
     if(p.x==1&&(p.y==1||p.y==2||p.y==3||p.y==4||p.y==5||p.y==6))
     {
         suma=suma+2;
     }
     if(p.x==6&&(p.y==1||p.y==2||p.y==3||p.y==4||p.y==5||p.y==6))
     {
         suma=suma+2;
     }
     if(p.y=1&&(p.x==2||p.x==3||p.x==4||p.x==5))
     {

         suma=suma+2;
     }
      if(p.y=6&&(p.x==2||p.x==3||p.x==4||p.x==5))
     {
         suma=suma+2;
     }
     if(p.x==2&&(p.y==2||p.y==3||p.y==4||p.y==5))
     {
        suma=suma+3;
     }
      if(p.x==3&&(p.y==2||p.y==3||p.y==4||p.y==5))
     {
        suma=suma+3;
     }
      if(p.x==4&&(p.y==2||p.y==3||p.y==4||p.y==5))
     {
        suma=suma+3;
     }
      if(p.x==5&&(p.y==2||p.y==3||p.y==4||p.y==5))
     {
        suma=suma+3;
     }

    if(czyjakiesbicie(act)==true)
    {
        suma=suma+10;
    }

    }


    if(Druzyna_P2==Teamprzeciwny(Druzyna_P2))


     {
         R.wartoscruchu=R.wartoscruchu*(-1);
     }
        return suma;

}


ruch MAP::player2(int KROK, ruch Wczesniejszy)
{
    int MAXKROK = 8;


    _ob T00[12]; _ob T11[12];
    team TT[2];

    TT[0].setplayertype(T[0].getpt()); TT[1].setplayertype(T[1].getpt());
    T[0].setplayertype(2); T[1].setplayertype(2);

    for(int i=0;i<12;i++)
    {
        T00[i].setalive(T0[i].a()); // ta metode musisz stworzyc, powinno wygladac tak: void _ob::setalive(bool A) {this -> alive = a}
        T00[i].setpos(T0[i].pozycja());
        if(T0[i].czydamka()) T00[i].DAMKA();
    }
    for(int i=0;i<12;i++)
    {
        T11[i].setalive(T1[i].a()); // ta metode musisz stworzyc, powinno wygladac tak: void _ob::setalive(bool A) {this -> alive = a}
        T11[i].setpos(T1[i].pozycja());
        if(T1[i].czydamka()) T11[i].DAMKA();
    }

    char boardd[8][8];
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        boardd[i][j]=board[i][j];
    }

    bool actt = act;
    bool terazbiciee=terazbicie;
    int idBijacegoo=idBijacego;
    bool ActBiciee=ActBicie;

    if(KROK) // JESLI KROK JEST WIEKSZY OD 0
    {
          changer(decide(act),0); //
          act = kruch();
    }
    else
    {
        Druzyna_P2 = act;
    }


    ruch R;
    R.team=act;
    int realid=99;

    cout<<"act:"<<act<<endl;

    int ile=0;
    for(int i=0; i<12; i++)
    {
        mozliwoscbicia(i,act,&ile,0,1);
        mozliwoscbicia(i,act,&ile,1,1);
    }

    cout<<"ile: "<<ile<<endl;
    ruch *TAB = new ruch[ile];

    bool CzyRuchBezBicia = 0;
    bool CzyRuchMaBicie = 0;
    bool Possible = 0;
    bool damka = 0;
    int actruch = 0;

     for(int id=0; id<12; id++)
    {
        damka = czydamkaPOS(id,act);


        if(!damka)
        {
            for(int i=0; i<2; i++)
            {
                if(actruch<ile)
                {
                    TAB[actruch] = ruchydlaplayer2(i,-1,id,act,0,&CzyRuchMaBicie,&Possible,&CzyRuchBezBicia);

                    if(act==0) TAB[actruch].id = id;
                    else TAB[actruch].id = id +12;

                    if(CzyRuchBezBicia) actruch++;

                    if(actruch<ile)
                    {
                        TAB[actruch] = ruchydlaplayer2(i,-1,id,act,1,&CzyRuchMaBicie,&Possible,&CzyRuchBezBicia);

                        if(act==0) TAB[actruch].id = id;
                        else TAB[actruch].id = id +12;
                    }


                }

            }
        }
        else
        {
            for(int j=0; j<4; j++)
            {
                int xchanger;
                int ychanger;

                chansetter(j,&xchanger,&ychanger);

                for(int i=1; i<12;i++)
                {
                    if(actruch<ile)
                    {
                        TAB[actruch] = ruchydlaplayer2(i,j,id,act,0,&CzyRuchMaBicie,&Possible,&CzyRuchBezBicia);

                        if(act==0) TAB[actruch].id = id;
                        else TAB[actruch].id = id +12;

                        if(CzyRuchBezBicia) actruch++;
                        if(actruch<ile)
                        {
                            TAB[actruch] = ruchydlaplayer2(i,j,id,act,1,&CzyRuchMaBicie,&Possible,&CzyRuchBezBicia);

                            if(act==0) TAB[actruch].id = i;
                            else TAB[actruch].id = id +12;

                            if(CzyRuchMaBicie) actruch++;
                        }
                    }
                }
            }
        }
    }

    ruch Pomocniczy;
    Pomocniczy.wartoscruchu=0;
    int zmienna_pomocnicza,kto_wygrywa=0;
    if(actruch>0&&KROK<MAXKROK)
    {
        for(int i=0;i<actruch;i++)
        {
            TAB[i].wartoscruchu=0;
            TAB[i].wartoscruchu=ocen(TAB[i]);
            Pomocniczy=player2(++KROK,TAB[i]);
            TAB[i].wartoscruchu+= Pomocniczy.wartoscruchu;

        }
    }
        else
        { 
             if(actruch==0)
           {

       zmienna_pomocnicza=1;
    for(int i=0;i<12;i++) //wygrali czarni
    {
       if(T00[i].a()==1)
       {
           zmienna_pomocnicza=0;
           break;
        }

    }
    if(zmienna_pomocnicza) kto_wygrywa=2;
     zmienna_pomocnicza=1;
    for(int i=0;i<12;i++) //wygrali biali
    {
       if(T11[i].a()==1)
       {
           zmienna_pomocnicza=0;
           break;
        }

    }
      if(zmienna_pomocnicza) kto_wygrywa=1;
      if(kto_wygrywa==0)Wczesniejszy.wartoscruchu+=7; //jest remis
      if(kto_wygrywa==2) //wygrali czarni
      {
       if(Druzyna_P2==1) Wczesniejszy.wartoscruchu=9999999;
       else Wczesniejszy.wartoscruchu=-9999999;
     }
      if(kto_wygrywa==1)
      {
      if(Druzyna_P2==0) Wczesniejszy.wartoscruchu=9999999;
      else Wczesniejszy.wartoscruchu=-9999999;
       }

           //}
            // TU TRZEBA WYMYSLIC CO BEDZIE JESLI NIE BEDZIE ZADNEGO RUCHU - PRAWDOPODBNIE ZMODYFIKOWANA METODA g00d
        // TRZEBA TUTAJ TEZ WYMYSLIC CO BEDZIE JESLI KROK ZOSTANIE PRZEKROCZONY

        // MAXKROK - JAK GLEBOKO ALGORYTM MA ANALIZOWAC RUCHY

        // JESLI AI WYGRYWA TO WARTOSC RUCHU TO 9999999
        // JESLI PRZEGRYWA TO WARTOSC RUCHU TO -9999999

       // }



    realid = Realid(R.id);

    T0[realid].show();

    if(act==0) R.o = T0[realid].pozycja();
    else R.o = T1[realid].pozycja();


    R.show();
    if(act==0) T0[realid].show();
    else T1[realid].show();


    if(possible(&R)) return R;
    else
    {
        cout<<"Ruch niemozliwy!\n";
    }
for(int i=0;i<12;i++)
{
    T0[i].setalive(T00[i].a());
    T0[i].setpos(T00[i].pozycja());
    if(T00[i].czydamka()) T0[i].DAMKA();
}

for(int i=0;i<12;i++)
{
    T1[i].setalive(T11[i].a());
    T1[i].setpos(T11[i].pozycja());
    if(T11[i].czydamka()) T1[i].DAMKA();
}


    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
            board[i][j]=boardd[i][j];
    }

    T[0].setplayertype(TT[0].getpt()); T[1].setplayertype(TT[1].getpt());

    act=actt;
    terazbicie=terazbiciee;
    idBijacego=idBijacegoo;
    ActBicie=ActBiciee;


    return R;
}


























