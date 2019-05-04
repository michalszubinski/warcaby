#include <iostream>
#include <cmath>

#include "class.h"

using namespace std;

bool MAP::prepos(ruch &R)
{
    if(R.n.good())
    {
        int realid = Realid(R.id);

        /*int bicierealid;

        if(R.team==1) bicierealid =R.bicieid-12;
        else bicierealid = R.bicieid;*/

        bool teamprzeciwny = Teamprzeciwny(R.team);

        if((R.team==0)&&(!T0[realid].a())) return 0; // czy zyje

        if((R.team==1)&&(!T1[realid].a())) return 0;

        if((R.n.x%2==0)&&(R.n.y%2==0)) {} // czy na czarnym polu
        else if((R.n.x%2==1)&&(R.n.y%2==1)) {}
        else return 0;

        if(polehelp(R.n)!=2) return 0; //czy pole jest zajete

        return 1;
    }
    else return 0;

}

bool MAP::possible(ruch &R)
{
    R.bicie=0;
    if(R.n.good()) // czy nowy ruch znajduje sie na planszy
    {
        int realid = Realid(R.id);

        /*int bicierealid;

        if(R.team==1) bicierealid =R.bicieid-12;
        else bicierealid = R.bicieid;*/

        bool teamprzeciwny = Teamprzeciwny(R.team);

        if((R.team==0)&&(!T0[realid].a())) return 0; // czy zyje

        if((R.team==1)&&(!T1[realid].a())) return 0;

        if((R.n.x%2==0)&&(R.n.y%2==0)) {} // czy na czarnym polu
        else if((R.n.x%2==1)&&(R.n.y%2==1)) {}
        else return 0;

        /*bool damka;
        if(R.team==0) damka = T0[realid].czydamka();
        else damka = T1[realid].czydamka();*/

        bool damka = czydamkaPOS(R.id,R.team);

        if(polehelp(R.n)!=2) return 0; //czy pole jest zajete

        if(!damka) // jesli jest normalnym pionkiem
        {
            if((R.team==0)&&(R.n.y>R.o.y)) return 0; // czy ruszyl sie do przodu

            if((R.team==1)&&(R.n.y<R.o.y)) return 0;

            if((abs(R.o.x - R.n.x)== 1)&&(abs(R.o.y - R.n.y)== 1)) return 1;//pole oddalone o 1;

            if((abs(R.o.x - R.n.x)== 2)&&(abs(R.o.y - R.n.y)== 2)) // sprawdzanie bicia
            {
                c polewroga;
                int mnoznik=-1;
                if(R.team==1) mnoznik = 1;

                polewroga.x = R.n.x + mnoznik;
                polewroga.y = R.n.y + mnoznik;

                if(polehelp(polewroga)==teamprzeciwny)
                {
                    R.bicie=1;

                    for(int i=0; i<12; i++)
                    {
                        if(T0[i].a()&&T0[0].pozycja() == polewroga) R.bicieid = T0[i].getid();
                        if(T1[i].a()&&T1[0].pozycja() == polewroga) R.bicieid = T1[i].getid();
                    }

                    return 1;
                }
                else return 0;
            }
        }
        else // jesli jest damka
        {
            if(((abs(R.o.x - R.n.x))!=(abs(R.o.y - R.n.y)))) return 0; // jesli jest po linii

            int delta = abs(R.o.x - R.n.x);

             for(int i=0; i<delta;i++)
            {
                c polewroga;
                int mnoznik=-1;
                if(R.team==1) mnoznik = 1;

                polewroga.x = R.n.x + mnoznik;
                polewroga.y = R.n.y + mnoznik;
            }

        }

    }
    else return 0;

    cout<<"POPRAWIC METODE POSSIBLE W KLASIE MAP!\n\n";
    return 0;
}

char MAP::polehelp(c pole)
{
    for(int i=0; i<12; i++)
    {
        if(T0[i].a()&&T0[i].pozycja() == pole) return 0;
        if(T1[i].a()&&T1[i].pozycja() == pole) return 1;
    }

    return 2;
}

bool MAP::czybicieNORM(ruch &R)
{
    bool teamprzeciwny = Teamprzeciwny(R.team);

    if((abs(R.o.x - R.n.x)== 2)&&(abs(R.o.y - R.n.y)== 2)) // sprawdzanie bicia
    {
        c polewroga;
        int mnoznik=-1;
        if(R.team==1) mnoznik = 1;

        polewroga.x = R.n.x + mnoznik;
        polewroga.y = R.n.y + mnoznik;

        if(polehelp(polewroga)==teamprzeciwny)
        {
            R.bicie=1;

            for(int i=0; i<12; i++)
            {
                if(T0[i].a()&&T0[0].pozycja() == polewroga) R.bicieid = T0[i].getid();
                if(T1[i].a()&&T1[0].pozycja() == polewroga) R.bicieid = T1[i].getid();
            }

            return 1;
        }
    }
    else return 0;
}

bool MAP::czybicieDAMKA(ruch &R)
{

}

bool MAP::czybicie(ruch &R)
{
    int realid = Realid(R.id);
    bool teamprzeciwny = Teamprzeciwny(R.team);


}

bool MAP::mozliwoscbicia(int id, bool Tt)
{
    int sztuczneid;
    if(Tt==1) sztuczneid = id +12;
    bool bicie=0;

    bool damka = czydamkaPOS(id,Tt);

    if(!damka) // zwykly
    {
        for(int i=0; i<2; i++) // sprawdza strony ruchu
        {
            ruch R;
            if(Tt==0) R.o = T0[id].pozycja();
            else R.o = T1[id].pozycja();
            R.n = R.o;

            int mn; // dla dwoch pol ktore sa do bicia
            if(i==0) mn=-1;
            else mn=1;

            int ymn; // dla druzyny
            if(Tt==0) ymn=1;
            else ymn= -1;

            R.n.x += mn*2;
            R.n.y += ymn*2;

            R.team = Tt;
            R.id = sztuczneid;

            if((bicie==0)&&(R.n.good())) bicie = czybicie(R);
        }
    }
    else // damka
    {

    }

    return bicie;
}

bool MAP::czyjakiesbicie(bool Tt)
{
    for(int i = 0; i<12; i++)
    {
        if(mozliwoscbicia(i,Tt)) return 1;
    }
}

int MAP::Realid(int id)
{
    if(id<12) return id;
    else return id-12;
}

bool MAP::Teamprzeciwny(bool t)
{
    if(t==0) return 1;
    else return 0;
}

bool MAP::czydamkaPOS(int id,bool Tt)
{
    bool damka;
    if(Tt==0) damka = T0[id].czydamka();
    else damka = T1[id].czydamka();

    return damka;
}


