#include <iostream>
#include <cmath>

#include "class.h"

using namespace std;

bool MAP::possible(ruch* R)
{
    R.bicie=0;
    if(R.n.good()) // czy nowy ruch znajduje sie na planszy
    {
        int realid; //id podstawialne do tablicy

        if(R.team==0) realid =R.id;
        else realid = R.id-12;

        /*int bicierealid;

        if(R.team==1) bicierealid =R.bicieid-12;
        else bicierealid = R.bicieid;*/

        bool teamprzeciwny;
        if(R.team==0) teamprzeciwny=1;
        else teamprzeciwny=0;

        if((R.team==0)&&(!T0[realid].a())) return 0; // czy zyje

        if((R.team==1)&&(!T1[realid].a())) return 0;

        if((R.n.x%2==0)&&(R.n.y%2==0)) {} // czy na czarnym polu
        else if((R.n.x%2==1)&&(R.n.y%2==1)) {}
        else return 0;

        bool damka;
        if(R.team==0) damka = T0[realid].czydamka();
        else damka = T1[realid].czydamka();

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
                        if(T0[i].a()&&T0[0].pozycja() == polewroga) bicieid = T0[i].getid();
                        if(T1[i].a()&&T1[0].pozycja() == polewroga) bicieid = T1[i].getid();
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

            */for(int i=0; i<delta;i++)
            {
                c polewroga;
                int mnoznik=-1;
                if(R.team==1) mnoznik = 1;

                polewroga.x = R.n.x + mnoznik;
                polewroga.y = R.n.y + mnoznik;
            }dokonczyc*/

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
