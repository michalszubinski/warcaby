#include <iostream>
#include <string>

#include "class.h"

using namespace std;

ruch MAP::ocena_ruchu(int *WartoscRuchu1,c ruch, int *tablica)
{
   int suma=0;
    C p;

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
        WartoscRuchu1=suma;
        return WartoscRuchu1;
}




ruch MAP::player2(int *KROK, int *WartoscRuchu1,c ruch)
{
    int idd=_ob.id;
    bool teamm=_ob.team;
    bool alivee=_ob.alive;
    bool damkaa=_ob.damka;

    bool tt=team.t;

    bool actt=MAP.act;
   bool ActBiciee=MAP.ActBicie;
   int idBijacegoo=MAP.idBijacego;
   bool terazbiciee=MAP.terazbicie;

    int liczba_ruchow=0;
    if(prepos!=0) // tu ma zastosowywaæ ruch na zmienionych zasadach gry ale nie wiedzia³em co to.
    {

        liczba_ruchow++;
    }

        int *tablica=new int[liczba_ruchow];

    if(KROK<liczba_ruchow)


    for(int i=0;i<liczba_ruchow;i++)
    {
        ocena_ruchu( *WartoscRuchu1,c ruch,*tablica);
        player2(++KROK, &WartoscRuchu1, c ruch[i])
    }

    _ob.id=idd;
    _ob.team=teamm;
    _ob.alive=alivee;
    _ob.damka=damkaa;

    team.t=actt;
    MAP.act=actt;
    MAP.ActBicie=idBijacegoo;
    MAP.terazbicie=terazbiciee;

    ruch L;
    for(int i=0;i<liczba_ruchow;i++)
    {
        if(ruch[i].wartoscruchu<ruch[i+1].wartoscruchu)
           {
               if(ruch[i>ruch L])
              ruch L=ruch[i];
           }
    }
    delete [] tablica;
}


