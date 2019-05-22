#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib>
#include <ctime>

#include "class.h"

using namespace std;

ruch MAP::player1()
{
    // W TYM MIEJSCU DLA player2 POWINNO BYC KOPIOWANY AKTUALNY STAN GRY

    ruch R; // tworzy ruch
    R.team = act; // ustawia druzyne wykonujaca ruch w ruchu R
    int realid=99;

    cout<<"act:"<<act<<endl;

    // POCZATEK LICZENIA RUCHOW

    int ile=0;
    for(int i=0; i<12; i++) // jesli ruch jest mozliwy ile jest zwiekszane, wysylany jest adres inta ile do metody
    {
        mozliwoscbicia(i,act,&ile,0,1); // sprawdza ruchy nie bijace
        mozliwoscbicia(i,act,&ile,1,1); // sprawdza ruchy bijace
    }

    // KONIEC LICZENIA RUCHOW

    // POCZATEK POZYSKIWANIA RUCHOW

    cout<<"ile: "<<ile<<endl;
    ruch *TAB = new ruch[ile]; // tworzona jest tablica ruchow

    bool CzyRuchBezBicia = 0; // potrzebne boole
    bool CzyRuchMaBicie = 0;
    bool Possible = 0;
    bool damka = 0;
    int actruch = 0; // aktualnie wykorzystywane miejsce w tablicy


    for(int id=0; id<12; id++) // sprawdza cala druzyne - laduje tablice z ruchami
    {
        damka = czydamkaPOS(id,act); // sprawdza czy jest damka


        if(!damka) // nie jest damka
        {
            for(int i=0; i<2; i++)
            {
                if(actruch<ile)
                {
                    TAB[actruch] = ruchydlaplayer2(i,-1,id,act,0,&CzyRuchMaBicie,&Possible,&CzyRuchBezBicia);

                    if(act==0) TAB[actruch].id = id;
                    else TAB[actruch].id = id +12;

                    if(CzyRuchBezBicia) actruch++;
                    //cout<<"actruch = "<<actruch<<endl;
                    if(actruch<ile)
                    {
                        TAB[actruch] = ruchydlaplayer2(i,-1,id,act,1,&CzyRuchMaBicie,&Possible,&CzyRuchBezBicia);

                        if(act==0) TAB[actruch].id = id;
                        else TAB[actruch].id = id +12;
                    }

                    //cout<<"actruch = "<<actruch<<endl;
                }

            }
        }
        else // jest damka
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
    } // KONIEC POZYSKIWANIA RUCHOW // do tego momentu niech bedzie w player2 to samo

    // POCZATEK DO PISANIA player2


    srand( time( NULL ) );

    int KtoryRuchWybrac = rand() % ile;
    //cout<<"ktorywybrac = "<<KtoryRuchWybrac<<endl;


    R.wartoscruchu = TAB[KtoryRuchWybrac].wartoscruchu ; // dla minimax
    R.id = TAB[KtoryRuchWybrac].id ; //id pionka
    R.o = TAB[KtoryRuchWybrac].o ;  // stara pozycja
    R.n = TAB[KtoryRuchWybrac].n ; // nowa pozycja
    R.p = TAB[KtoryRuchWybrac].p;
    R.bicie = TAB[KtoryRuchWybrac].bicie ;
    R.bicieid = TAB[KtoryRuchWybrac].bicieid ;
    R.team = TAB[KtoryRuchWybrac].team ;

    // KONIEC DO PISANIA player2


    realid = Realid(R.id); // do konca niech bedzie to samo
    //cout<<"realid = "<<realid<<endl;

    T0[realid].show();

    if(act==0) R.o = T0[realid].pozycja();
    else R.o = T1[realid].pozycja();

    // pokazuje pionek i ruch
    R.show();
    if(act==0) T0[realid].show();
    else T1[realid].show();
    //

    if(possible(&R)) return R;
    else
    {
        cout<<"Ruch niemozliwy!\n";
    }


    return R;
}

