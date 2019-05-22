#include <iostream>
#include <cmath>

#include "class.h"

using namespace std;

bool MAP::prepos(ruch *R)
{
    if(R->n.good())
    {
        int realid = Realid(R->id);

        /*int bicierealid;

        if(R->team==1) bicierealid =R->bicieid-12;
        else bicierealid = R->bicieid;*/

        bool teamprzeciwny = Teamprzeciwny(R->team);

        if((R->team==0)&&(!T0[realid].a())) return 0; // czy zyje

        if((R->team==1)&&(!T1[realid].a())) return 0;

        if((R->n.x%2==0)&&(R->n.y%2==0)) {} // czy na czarnym polu
        else if((R->n.x%2==1)&&(R->n.y%2==1)) {}
        else return 0;

        if(polehelp(R->n)!=2) return 0; //czy pole jest zajete

        if(!czyonjestbijacym(R->id)) return 0; // czy jest pionkiem bijacym jesli jest bicie na mapie

        return 1;
    }
    else return 0;

}

bool MAP::possible(ruch *R)
{
    R->bicie=0;
    if(prepos(R)) // czy nowy ruch znajduje sie na planszy
    {
        /*int realid = Realid(R->id);

        //int bicierealid;

        //if(R->team==1) bicierealid =R->bicieid-12;
        //else bicierealid = R->bicieid;

        bool teamprzeciwny = Teamprzeciwny(R->team);

        if((R->team==0)&&(!T0[realid].a())) return 0; // czy zyje

        if((R->team==1)&&(!T1[realid].a())) return 0;

        if((R->n.x%2==0)&&(R->n.y%2==0)) {} // czy na czarnym polu
        else if((R->n.x%2==1)&&(R->n.y%2==1)) {}
        else return 0;

        //bool damka;
        //if(R->team==0) damka = T0[realid].czydamka();
        //else damka = T1[realid].czydamka();
        if(polehelp(R->n)!=2) return 0; //czy pole jest zajete */

        int realid = Realid(R->id);
        bool teamprzeciwny = Teamprzeciwny(R->team);
        bool damka = czydamkaPOS(R->id,R->team);

        if(!damka) // jesli jest normalnym pionkiem
        {
            if((R->team==0)&&(R->n.y<R->o.y)) return 0; // czy ruszyl sie do przodu

            if((R->team==1)&&(R->n.y>R->o.y)) return 0;

            if(ActBicie==0 && terazbicie==0)
            {
                if((abs(R->o.x - R->n.x)== 1)&&(abs(R->o.y - R->n.y)== 1)) return 1;//pole oddalone o 1;
            }

            if(czybicieNORM(R)) return 1;
            else return 0;
        }
        else // jesli jest damka
        {
            if(ActBicie==0 && terazbicie==0)
            {
                if(possibledamkaruch(R)) return 1;
            }

            if(czybicieDAMKA(R)) return 1;
            else return 0;
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

bool MAP::czybicieNORM(ruch *R)
{
    //R->show();
    bool teamprzeciwny = Teamprzeciwny(R->team);

    if((abs(R->o.x - R->n.x)== 2)&&(abs(R->o.y - R->n.y)== 2)) // sprawdzanie bicia
    {
        c polewroga;
        int mnoznik=-1;
        if(R->team==1) mnoznik = 1;

        int dx;
        if(R->n.x - R->o.x>0) dx=-1;
        else dx=1;

        polewroga.x = R->n.x + dx;
        polewroga.y = R->n.y + mnoznik;

        //cout<<"x: "<<polewroga.x<<"     y: "<<polewroga.y<<endl;

        if(polehelp(polewroga)==teamprzeciwny)
        {
            ladujbicie(R,polewroga);
            return 1;
        }
    }
    else return 0;
}

bool MAP::czybicieDAMKA(ruch *R)
{
    bool teamprzeciwny = Teamprzeciwny(R->team);
    c apole;
    c polewrogareal;

    int delta = abs(R->n.x - R->o.x);

    int deltax = R->n.x - R->o.x;
    int deltay = R->n.y - R->o.y;

    int dx;
    if(deltax>0) dx=1;
    else dx=-1;

    int dy;
    if(deltay>0) dy=1;
    else dy=-1;

    bool lastobj=0;
    bool firstobj=0;
    char pole;

    for(int i=1; i<=delta; i++)
    {
        apole.x=R->o.x + i*dx;
        apole.y=R->o.y + i*dy;

        pole = polehelp(apole);

        if(pole==R->team) return 0; // jesli po drodze stoi pionek tej samej druzyny

        if((pole==teamprzeciwny)&&(firstobj==1)) return 0; // jesli napotka drugi pionek druzyny przeciwnej

        if(pole==teamprzeciwny)
        {
            //cout<<"detected ";
            firstobj=1;
            polewrogareal=apole;
        }

        //cout<<(int)pole<<endl;

        if(pole==2&&firstobj==1) ladujbicie(R,polewrogareal);


    }

    return 1;
}



bool MAP::mozliwoscbicia(int id, bool Tt,int* ile, bool X,  bool czyliczyc)
{

    if(!czyonjestbijacym(id)) return 0;

    int sztuczneid;

    if(Tt==1) sztuczneid = id +12;
    else sztuczneid = id;

    bool fbicie=0;
    bool nadsf=0;
    bool czyda=0;

    int o = X + 1;

    bool damka = czydamkaPOS(id,Tt);


    if(!damka) // zwykly
    {
        for(int i=0; i<2; i++) // sprawdza strony ruchu
        {
            ruch *R = new ruch;
            checkmen(i,id,Tt,o,R, &fbicie, &nadsf, &czyda);

            if(!X&&nadsf&&czyliczyc) (*ile)++;
            if(X&&nadsf&&czyliczyc) (*ile)++;

            delete R;
        }
    }
    else // damka
    {
        for(int j=0; j<4; j++)
        {
            int xchanger;
            int ychanger;

            chansetter(j,&xchanger,&ychanger);

            for(int i=1; i<12;i++)
            {
                ruch *R = new ruch;
                checkking(j,i, id, Tt, o,xchanger, ychanger, R,  &fbicie, &nadsf, &czyda);

                if(!X&&!R->bicie&&czyliczyc&&nadsf) (*ile)++;
                if(X&&R->bicie&&czyliczyc&&nadsf) (*ile)++;

                delete R;
            }
        }
    }


    if(X==1) return fbicie;
    else czyda;
}

ruch MAP::ruchydlaplayer2(int i, int j,int id, bool Tt, bool X, bool *fbicie, bool *nadsf, bool *czyda)
{
    *nadsf = 1;
    if(!czyonjestbijacym(id)) nadsf = 0;

    int sztuczneid;

    if(Tt==1) sztuczneid = id +12;
    else sztuczneid = id;

    int o = X + 1;

    bool damka = czydamkaPOS(id,Tt);

    if(nadsf)
    {
        if(!damka) // zwykly
        {
            if(i==0||i==1) // sprawdza strony ruchu
            {
                ruch R;
                checkmen(i,id,Tt,o,&R, fbicie, nadsf, czyda);
                return R;
            }
        }
        else // damka
        {
            if(j>=0&&j<=4)
            {
                int xchanger;
                int ychanger;

                chansetter(j,&xchanger,&ychanger);

                if(i>=1&&i<=11)
                {
                    ruch R;
                    checkking(j,i, id, Tt, o,xchanger, ychanger, &R, fbicie, nadsf, czyda);
                    return R;
                }
            }
        }
    }
    ruch R;
    R.id=99;
    return R;
}

bool MAP::czyjakiesbicie(bool Tt)
{
    for(int i = 0; i<12; i++)
    {
        if(OLDmozliwoscbicia(i,Tt)) return 1;
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
    else damka = T1[Realid(id)].czydamka();

    return damka;
}

void MAP::ladujbicie(ruch *R, c polewroga)
{
    R->bicie=1;

    R->p = polewroga;

    for(int i=0; i<12; i++)
    {
        if(T0[i].a()&&T0[i].pozycja() == polewroga) R->bicieid = T0[i].getid();
        if(T1[i].a()&&T1[i].pozycja() == polewroga) R->bicieid = T1[i].getid();
    }
}

bool MAP::czyonjestbijacym(int id)
{
    int realid = Realid(id);

    bool team = 0;
    if(id>=12) team = 1;

    if(ActBicie==1&&team==0&&T0[realid].getid()!=id) return 0;
    else if(ActBicie==1&&team==1&&T1[realid].getid()!=id) return 0;

    return 1;
}

bool MAP::possibledamkaruch(ruch *R)
{
    if(((abs(R->o.x -  R->n.x))!=(abs(R->o.y -  R->n.y)))) return 0; // jesli jest po linii

    c polewroga;

    int delta = abs(R->n.x - R->o.x);

    int deltax = R->n.x - R->o.x;
    int deltay = R->n.y - R->o.y;

    int dx;
    if(deltax>0) dx=1;
    else dx=-1;

    int dy;
    if(deltay>0) dy=1;
    else dy=-1;

    char pole;

    for(int i=1; i<=delta; i++)
    {
        polewroga.x=R->o.x + i*dx;
        polewroga.y=R->o.y + i*dy;

        pole = polehelp(polewroga);
        if(pole!=2) return 0; // czy nic nie stoi na drodze
    }

    return 1;
}

void MAP::checkmen(int i, int id, bool Tt, int o, ruch *R, bool *fbicie, bool *nadsf, bool *czyda)
{
    int sztuczneid;

    if(Tt==1) sztuczneid = id +12;
    else sztuczneid = id;

    /*bool fbicie=0;
    bool nadsf=0;
    bool czyda=0;*/

    //int o = X + 1;

    //ruch *R = new ruch;
    if(Tt==0) R->o = T0[id].pozycja();
    else R->o = T1[id].pozycja();

    R->n = R->o;

    int mn; // dla dwoch pol ktore sa do bicia
    if(i==0) mn=-1;
    else mn=1;

    int ymn; // dla druzyny
    if(Tt==0) ymn=1;
    else ymn= -1;

    R->n.x += mn*o;
    R->n.y += ymn*o;

    R->team = Tt;
    R->id = sztuczneid;

    if((*fbicie==0)&&(R->n.good()==1))
    {
        *nadsf = possible(R);
        if(R->bicie&&*nadsf) *fbicie = 1;

        if(*nadsf) *czyda =1;
    }

    delete R;
}

void MAP::checkking(int j, int i, int id, bool Tt, int o,int xchanger, int ychanger, ruch *R, bool *fbicie, bool *nadsf, bool *czyda)
{

    int sztuczneid;

    if(Tt==1) sztuczneid = id +12;
    else sztuczneid = id;

    if(Tt==0) R->o = T0[id].pozycja();
    else R->o = T1[id].pozycja();
    R->n = R->o;

    R->n.x = R->o.x + xchanger*i;
    R->n.y = R->o.y + ychanger*i;

    R->team = Tt;
    R->id = sztuczneid;

    if((*fbicie==0)&&(R->n.good()))
    {
        *nadsf = possible(R);
        if(R->bicie&&*nadsf) {*fbicie = 1; /*cout<<"v possible";*/}

        if(*nadsf) *czyda =1;
    }
}

void MAP::chansetter(int j, int *xchanger, int *ychanger)
{
    if(j==0){*xchanger=-1; *ychanger=1;}
    else if(j==1) {*xchanger=-1; *ychanger=-1;}
    else if(j==2) {*xchanger=1; *ychanger=-1;}
    else if(j==3) {*xchanger=1; *ychanger=1;}
}

bool MAP::OLDmozliwoscbicia(int id, bool Tt, bool X)
{
    if(!czyonjestbijacym(id)) return 0;

    int sztuczneid;

    if(Tt==1) sztuczneid = id +12;
    else sztuczneid = id;

    bool fbicie=0;
    bool nadsf=0;
    bool czyda=0;

    int o = X + 1;

    bool damka = czydamkaPOS(id,Tt);

    if(!damka) // zwykly
    {
        for(int i=0; i<2; i++) // sprawdza strony ruchu
        {
            ruch *R = new ruch;
            if(Tt==0) R->o = T0[id].pozycja();
            else R->o = T1[id].pozycja();

            R->n = R->o;

            int mn; // dla dwoch pol ktore sa do bicia
            if(i==0) mn=-1;
            else mn=1;

            int ymn; // dla druzyny
            if(Tt==0) ymn=1;
            else ymn= -1;

            R->n.x += mn*o;
            R->n.y += ymn*o;

            R->team = Tt;
            R->id = sztuczneid;

            if((fbicie==0)&&(R->n.good()==1))
            {
                nadsf = possible(R);
                if(R->bicie&&nadsf) fbicie = 1;

                if(nadsf) czyda =1;
            }

            delete R;
        }
    }
    else // damka
    {
        for(int j=0; j<4; j++)
        {
            int xchanger;
            int ychanger;

            if(j==0){xchanger=-1; ychanger=1;}
            else if(j==1) {xchanger=-1; ychanger=-1;}
            else if(j==2) {xchanger=1; ychanger=-1;}
            else if(j==3) {xchanger=1; ychanger=1;}


            for(int i=1; i<12;i++)
            {
                ruch *R = new ruch;

                if(Tt==0) R->o = T0[id].pozycja();
                else R->o = T1[id].pozycja();
                R->n = R->o;

                R->n.x = R->o.x + xchanger*i;
                R->n.y = R->o.y + ychanger*i;

                R->team = Tt;
                R->id = sztuczneid;

                if((fbicie==0)&&(R->n.good()))
                {
                    nadsf = possible(R);
                    if(R->bicie&&nadsf) {fbicie = 1; /*cout<<"v possible";*/}

                    if(nadsf) czyda =1;
                }
                //R->show();

                delete R;
            }
        }
    }


    if(X==1) return fbicie;
    else czyda;
}

