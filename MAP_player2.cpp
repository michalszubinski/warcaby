#include <iostream>
#include <string>

#include "class.h"

using namespace std;

ruch MAP::ocen(ruch R)
{
    int suma=0;
    ruch R;
    c p;



    if (p.x==0&&(p.y==1||p.y==2||p.y==3||p.y==4||p.y==5||p.y==6||p.y==7))
        {
            suma=suma+1;
        }
     if(p.y==0&&(p.x==0||p.x==1||p.x==2||p.x==3||p.x==4||p.x==5||p.x==6||p.x==7))
     {
         suma=suma+1;
     }
     if(p.x=7&&(p.y==0||p.y==1||p.y==2||p.y==3||p.y==4||p.y==5||p.y==6||p.y==7))
     {
         suma=suma+1;
     }
     if(p.y==7&&(p.x==1||p.x==2||p.x==3||p.x==4||p.x==5||p.x==6))
     {
         suma=suma+1;
     }
     if(p.x==1&&(p.y==1||p.y==2||p.y==3||p.y==4||p.y==5||p.y==6||))
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

    if(czyjakiesbicie()==true)
        suma=suma+10;
        R.wartoscruchu=suma;
        if(act==false)
            R.wartoscruchu=R.wartoscruchu*(-1);
        return R;
}




ruch MAP::player2(int KROK, ruch Wczesniejszy)
{
    bool act;
    _ob T0[12];
          for(int i=0;i<12;i++)
          {
           _ob T0[i].alive = bool alive;
            _ob T0[i].pos=c pos;
            _ob T0[i].damka= bool damka;
          }
    _ob T1[12];
       for(int i=0;i<12;i++)
       {
        _ob T1[i].alive=bool alive;
        _ob T1[i].pos=c pos;
        _ob T1[1].damka=bool damka;
       }



    char boardd[8][8];
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        boardd[i][j]=board[i][j];
    }
    bool terazbiciee=terazbicie;
    int idBijacegoo=idBijacego;
    bool ActBiciee=ActBicie;
 /*
    if(KROK) // JESLI KROK JEST WIEKSZY OD 0
    {
        W TYM MOMENCIE NALEZY WYKONAC RUCH WCZESNIEJSZY CZYLI
        changer dla player2
        kruch dla player 2
    }*/


    ruch R;
    R.team=act;
    int realid=99;

    cout<<"act:"<<act<<end;

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

    if(actruch>0&&KROK<MAXKROK)
    {
        for(int i=0;o<actruch;i++)
        {
            TAB[i].wartoscruchu=0;
            TAB[i]=ocen(&TAB[i]);
            Pomocniczy=player2(++KROK,TAB[i]);
            TAB[i].wartoscruchu+= Pomocniczy.wartoscruchu;

        }
    }
        else
        {
            // TU TRZEBA WYMYSLIC CO BEDZIE JESLI NIE BEDZIE ZADNEGO RUCHU - PRAWDOPODBNIE ZMODYFIKOWANA METODA g00d
        // TRZEBA TUTAJ TEZ WYMYSLIC CO BEDZIE JESLI KROK ZOSTANIE PRZEKROCZONY

        // MAXKROK - JAK GLEBOKO ALGORYTM MA ANALIZOWAC RUCHY

        // JESLI AI WYGRYWA TO WARTOSC RUCHU TO 9999999
        // JESLI PRZEGRYWA TO WARTOSC RUCHU TO -9999999

        }



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
             bool alive=_ob T0[i].alive;
             c pos=_ob T0[i].pos;
             bool damka=_ob T0[i].damka;
          }
       for(int i=0;i<12;i++)
       {
           bool alive=_ob T1[i].alive;
           c pos=_ob T1[i].pos;
           bool damka= _ob T1[i].damka;
       }
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
            board[i][j]=boardd[i][j];
    }
    terazbicie=terazbiciee;
    idBijacego=idBijacegoo;
    ActBicie=ActBiciee;


    return R;



}


























