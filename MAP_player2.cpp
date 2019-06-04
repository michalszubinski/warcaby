#include <iostream>
#include <string>

#include "class.h"

using namespace std;

int MAP::ocen(ruch R) // NIECH OCEN BEDZIE INTEM, ZWROCI WARTOSC RUCHU
{
    int suma=0;
    c p;
    int przel;

    for(int i=0; i<2; i++)
    {
        if(!i) {p.x = R.o.x;p.y = R.o.y; przel=-1;}
        else {p.x = R.n.x;p.y = R.n.y;przel=1;}

        if(((p.x==0)||(p.x==7))&&((p.y==0)||(p.y==7))) suma+=20*przel;
        else if(((p.x<=1)||(p.x>=6))&&((p.y<=1)||(p.x>=6))) suma+=10*przel;
    }

    if(czyjakiesbicie(act)==true)
    {
        if(act==Druzyna_P2)suma+=20;
        else suma-=45;
    }

    if(Druzyna_P2==Teamprzeciwny(Druzyna_P2))
    {
         R.wartoscruchu=R.wartoscruchu*(-1);
    }
        return suma;

}


ruch MAP::player2(int KROK, ruch Wczesniejszy)
{
    int MAXKROK = 3;


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
          changer(Wczesniejszy,0);
          act = kruch();
    }
    else
    {
        Druzyna_P2 = act;
    }


    //cpy

    ruch R; // tworzy ruch
    R.team = act; // ustawia druzyne wykonujaca ruch w ruchu R
    int realid=99;

    //cout<<"act:"<<act<<endl;

    // POCZATEK LICZENIA RUCHOW

    int ile=0;

    terazbicie = czyjakiesbicie(act);

    for(int i=0; i<12; i++) // jesli ruch jest mozliwy ile jest zwiekszane, wysylany jest adres inta ile do metody
    {
        mozliwoscbicia(i,act,&ile,0,1); // sprawdza ruchy nie bijace
        mozliwoscbicia(i,act,&ile,1,1); // sprawdza ruchy bijace
    }

    // KONIEC LICZENIA RUCHOW

    // POCZATEK POZYSKIWANIA RUCHOW

    //cout<<"ile: "<<ile<<endl;
    ruch *TAB = new ruch[ile]; // tworzona jest tablica ruchow

    bool CzyRuchBezBicia = 0; // potrzebne boole
    bool CzyRuchMaBicie = 0;
    bool Possible = 0;
    bool damka = 0;
    int actruch = 0; // aktualnie wykorzystywane miejsce w tablicy


    for(int id=0; id<12; id++) // WPISYWANIE RUCHOW DO TABLICY
    {
        damka = czydamkaPOS(id,act);
        if(!damka) // jesli pionek nie jest damka
        {
            for(int i=0; i<2; i++)
            {
                if(actruch<ile)
                {
                    TAB[actruch] = ruchydlaplayer2(i,-1,id,act,0,&CzyRuchMaBicie,&Possible,&CzyRuchBezBicia);

                    if(act==0) TAB[actruch].id = id;
                    else TAB[actruch].id = id +12;

                    if(!TAB[actruch].bicie&&Possible&&!terazbicie&&possible(&TAB[actruch])) actruch++;

                    if(actruch<ile)
                    {
                        TAB[actruch] = ruchydlaplayer2(i,-1,id,act,1,&CzyRuchMaBicie,&Possible,&CzyRuchBezBicia);

                        if(act==0) TAB[actruch].id = id;
                        else TAB[actruch].id = id +12;

                        if(TAB[actruch].bicie&&Possible&&terazbicie&&possible(&TAB[actruch])) actruch++;
                    }
                }
            }
        }
        else // jesli jest
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

                        if(!TAB[actruch].bicie&&Possible&&!terazbicie&&possible(&TAB[actruch])) actruch++;
                        if(actruch<ile)
                        {
                            TAB[actruch] = ruchydlaplayer2(i,j,id,act,1,&CzyRuchMaBicie,&Possible,&CzyRuchBezBicia);

                            if(act==0) TAB[actruch].id = i;
                            else TAB[actruch].id = id +12;

                            if(TAB[actruch].bicie&&Possible&&terazbicie&&possible(&TAB[actruch])) actruch++;
                        }
                    }
                }
            }
        }
    } // KONIEC POZYSKIWANIA RUCHOW // do tego momentu niech bedzie w player2 to samo

    // POCZATEK DO PISANIA player2


    /*for(int i=0; i<ile;i++)
    {
        cout<<"KROK: "<<KROK<<endl;
        TAB[i].show();
    }
    cout<<endl;*/

    ruch Pomocniczy;
    Pomocniczy.wartoscruchu=0;
    int zmienna_pomocnicza,kto_wygrywa=0;

    if(actruch>0&&KROK<MAXKROK)
    {
        for(int i=0;i<actruch;i++)
        {
            TAB[i].wartoscruchu=0;
            TAB[i].wartoscruchu=ocen(TAB[i]);
            //TAB[i].show();
            Pomocniczy=player2(KROK+1,TAB[i]);
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

        if(actruch==0) // jesli ich nie ma
        {

            kto_wygrywa=czy_wygrana();

            if(kto_wygrywa==0)R.wartoscruchu+=7; //jest remis

            if(kto_wygrywa==2) //wygrali czarni
            {
                if(Druzyna_P2==1) R.wartoscruchu=9999999;
                else R.wartoscruchu=-9999999;
            }

            if(kto_wygrywa==1)
            {
                if(Druzyna_P2==0) R.wartoscruchu=-9999999;
                else R.wartoscruchu=9999999;
            }

            return R;
        }
        else // jesli sa ruchy
        {
            for(int i=0;i<actruch;i++)
            {
                TAB[i].wartoscruchu=0;
                TAB[i].wartoscruchu=ocen(TAB[i]);
                TAB[i].wartoscruchu+= Pomocniczy.wartoscruchu;
            }
        }
    }

    int KtoryRuchWybrac=0;

    if(ile>0)
    {
        R.wartoscruchu = TAB[0].wartoscruchu;
        for(int i=0;i<ile;i++ )
        {
            if(Druzyna_P2==act)
            {
                if(R.wartoscruchu<TAB[i].wartoscruchu)
                {
                    R=TAB[i]; KtoryRuchWybrac=i;
                }

            }
            else
            {
                if(R.wartoscruchu>TAB[i].wartoscruchu)
                {
                    R=TAB[i]; KtoryRuchWybrac=i;
                }
            }
        }

        R.wartoscruchu = TAB[KtoryRuchWybrac].wartoscruchu ; // dla minimax
        R.id = TAB[KtoryRuchWybrac].id ; //id pionka
        R.o = TAB[KtoryRuchWybrac].o ;  // stara pozycja
        R.n = TAB[KtoryRuchWybrac].n ; // nowa pozycja
        R.p = TAB[KtoryRuchWybrac].p;
        R.bicie = TAB[KtoryRuchWybrac].bicie ;
        R.bicieid = TAB[KtoryRuchWybrac].bicieid ;
        R.team = TAB[KtoryRuchWybrac].team ;

    }



    //T0[realid].show();

    if(!R.o.good()||!R.n.good()||R.id<0||R.id>24) // system ratowania przed brakiem ruchu
    {
        c o;
        c n;
        bool found=0;

        c copy1 = R.o;
        c copy2 = R.n;

        for(int ox=0; ox<8; ox++)
        {
            for(int oy=0; oy<8; oy++)
            {
                for(int nx=0; nx<8; nx++)
                {
                    for(int ny=0; ny<8; ny++)
                    {
                        if(!found)
                        {
                            R.o.x = ox;
                            R.o.y = oy;
                            if(polehelp(R.o)==act)
                            {
                                R.id = scanid(R.o);
                                R.n.x = nx;
                                R.n.y = ny;
                                OLDmozliwoscbicia(R.id,act);
                                if(possible(&R)) found = 1;
                            }
                        }
                    }
                }
            }
        }

        if(!found)
        {
            cout<<"Ups...\n"<<endl;
            copy1 = R.o;
            copy2 = R.n;
        }
    } // koniec systemu zapobiegawczego

    realid = Realid(R.id);

    if(act==0) R.o = T0[realid].pozycja();
    else R.o = T1[realid].pozycja();

   /* cout<<"wybrany ruch:\n";
    TAB[KtoryRuchWybrac].show();*/

    /*if(act==0) T0[realid].show();
    else T1[realid].show();*/

    // powrot do starych danych

    for(int i=0;i<12;i++)
    {
        T0[i].setalive(T00[i].a());
        T0[i].setpos(T00[i].pozycja());
        T0[i].setdamka(T00[i].czydamka());
    }

    for(int i=0;i<12;i++)
    {
        T1[i].setalive(T11[i].a());
        T1[i].setpos(T11[i].pozycja());
        T1[i].setdamka(T11[i].czydamka());
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


    if(possible(&R)) return R;
    else
    {
        //cout<<"Ruch niemozliwy!\n";
        /*string x;
        cin>>x;*/
    }

    return R;
}
