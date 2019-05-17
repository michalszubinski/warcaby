#include <iostream>
#include <string>

#include "class.h"

using namespace std;

ruch MAP::ocen(ruch *R)
{
    int suma=0;
    ruch R;
;
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
}




ruch MAP::player2()
{
    bool act;
    _ob T0[12]; // dla kazdego pionka z tablicy
            bool alive;
            c pos;
            bool damka;

    _ob T1[12];
        bool alive;
        c pos;
        bool damka;

    char board[8][8];
    bool ActBicie;
    int idBijacego;
    bool terazbicie;

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


    if(actruch>0)
    for(i=0;i<actruch;i++)
        tab[i]=ocen(TAB[i],bool team)
    NajlepszyRuch = player2(++actruch,TAB[i],bool Teamprzeciwny())



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


    return R;



}


























