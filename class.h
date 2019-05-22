#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED

/*UWAGA! ARGUMENTY WYSYLANE DO FUNCKJI KTORYCH NIE MA CZASAMI NIE ZOSTALY OKRESLONE!!!*/

using namespace std;

struct c // KORDYNATY
{
    int x;
    int y;

    bool operator==(c other);
    bool operator!=(c other);

    bool good(); // sprawdza czy kordynaty znajduja sie na planszy
};

struct ruch // KORDYNATY RUCHU
{
    int wartoscruchu; // dla minimax
    int id; //id pionka
    c o; // stara pozycja
    c n; // nowa pozycja
    c p; // pozycja wroga

    bool bicie; // czy bylo bicie
    int bicieid; // id zbitego pionka przy tym ruchu
    bool team; // druzyna z ktorej pochodzi pionek

    bool operator==(ruch other);
    bool operator!=(ruch other);

    void show(); // pokazuje detale
};


class _ob // PIONEK
{
    bool team; // druzyna pionka
    bool alive; // czy nie jest zbity
    c pos; // pozycja pionka
    bool damka; // czy jest damka
    int id; //id
public:
    _ob(); // konstrktor
    void setteam(bool t); // ustawia druzyne
    void setpos(c P); // ustawia pozycje
    void DAMKA(); // pionek staje sie damka
    void show(); // pokazuje informacje
    void setid(int ID); // ustawia id
    bool a(); // sprawdza czy pionek nie jest zbity
    void kill(); // zabija pionek
    bool czydamka(); // sprawdza czy pionek jest damka
    int dorendera_x(); //c pos jest private a musiałem się dostać do x i y
    int dorendera_y();
    c pozycja(); // zwraca pozycje pionka
    int getid(); // zwraca id
    void setalive(bool A);
    void setdamka(bool d);
};

class team // DRUZYNA
{
    unsigned int w; // wygrane
    unsigned int l; // przegrane
    unsigned int d; // remisy
    string name; // nazwa
    bool t; // czarne czy biale
    char playertype; // typ poruszania sie (czy gracz czy ai)
public:
    team(bool tea=0, char playertype=0, string name=""); // konstuktor wczytuje statystyki z pliku
    ~team(); // dekonstruktor zapisuje statystyki
    void setplayertype(char T); // ustawia typ gracza
    string getplayertype(); // string = TYP GRACZA | JEGO DRUZYNA
    bool gett(); //zwraca druzyne
    char getpt(); // zwraca typ gracza
    void StatsFromFile(); // Wczytywanie statystyk z pliku
    void StatsToFile(); // Zapisywanie statystyk do pliku
    void setteam(bool TTT); // ustawia druzyne
    void setteamname(string X); // ustawia nazwe druzyny
    void EndV(int X); //0 DODAJE WYGRANA , 1 DODAJE PRZEGRANA , 2 DODAJE REMIS
};

class MAP
{
    bool act; // jaka druzyna ma ruch
    _ob T0[12]; // pionki druzyny bialych
    _ob T1[12]; // czarnych
    team T[2]; // 2 druzyny
    char board[8][8]; //w tej tablicy przechowuję się pozycję
    bool ActBicie; // czy teraz na mapie ktos zaczal bicie
    int idBijacego; // id pionka ktory rozpoczal bicie na mapie [TO ID KTORE PRZYJMUJE WARTOSCI OD 0 DO 23]
    bool terazbicie; // przechowuje czy jakis pionek ma dostepne bicie
    bool Druzyna_P2;  // Zmienna Druzyny player 2
public:
    MAP(); //inicjalizuje gre //  MAP_StartEnd.cpp
    ~MAP();// konczy gre// MAP_StartEnd.cpp // KIEDY ZOSTANIE ZROBIONA FUNKCJA g00d NALEZY USUNAC KOMENTARZE W TEJ FUNCKJI!!!!
    void render(); // rysuje mape DO POPRAWY
    void wyswietlanie_planszy();
    void czyszczenie_planszy();
    void wczytywanie_planszy();

    void GAME(); // funkcja gry
    void TURN2(); // funckaj zmiany tury
    void TURN();
    ruch decide(bool Tt); // decyduje ktory typ gracza wybrac

    ruch player0(); //te cyferki oznaczaja typy gracza
    int scanid(c pole); // skanuje id na danym polu
    ruch player1();   //0-czlowiek 1-random 2-minimax
    ruch player2(int KROK, ruch Wczesniejszy);
    void changer(ruch abc,int czy_aktualizowac=1); // zastosowuje ruch

    // DOMYSLNIE ID WYSYLAC Z TX[realid(czyli wartosc od 0 do 11)].getid() [Czyli wysylac to id ktore ma wartosci od 0 do 23]
    bool prepos(ruch *R); // podstawowe warunki mozliwosc ruchu
    bool possible(ruch *R);// czy ruch jest mozliwy
    char polehelp(c pole); // sprawdza co jest na danym polu (POMOCNIK FUNKCJI possible)

    bool czybicieNORM(ruch *R); // czy bicie dla normalnego pionka
    bool czybicieDAMKA(ruch *R); // czy bicie dla damki
    bool mozliwoscbicia(int id, bool Tt, int* ile,bool X=1, bool czyliczyc=0);
    ruch ruchydlaplayer2(int i, int j,int id, bool Tt, bool X, bool *fbicie, bool *nadsf, bool *czyda);
    int ocen(ruch R);
    bool czyjakiesbicie(bool Tt); // sprawdza bicie dla wszystkich pionkow danej druzyny
    int Realid(int id); // zmienia id pionka na miejsce w tablicy pionkow odpowiednie dla jego druzyny - na podstawie ruchu
    bool Teamprzeciwny(bool t); //patrzy jaka druzyna jest przeciwna - na podstawie ruchu
    bool czydamkaPOS(int id,bool Tt); // sprawdza czy dany pionek z danej druzyny jest damka [TUTAJ WYSYLAC ID OD 0 DO 12]
    void ladujbicie(ruch *R, c polewroga); // laduje bicie do obiektu klasy ruch
    bool czyonjestbijacym(int id); // sprawdza czy pionek jest pionkiem bijacym !!! JESLI NIE MA BICIA LUB PIONEK JEST PIONKIEM BIJACYM ZWRACA 1 !!!
    bool possibledamkaruch(ruch *R); // bada czy cos nie stoi na drodze damki, zeby isc na wskazane pole (warunek przemieszczania sie)
    void checkmen(int i, int id, bool Tt, int o, ruch *R, bool *fbicie, bool *nadsf, bool *czyda); // i = 0 lub 1 ; JESLI nadsf = true TO ZNACZY ZE RUCH JEST MOZLIWY
    void checkking(int j, int i, int id, bool Tt, int o,int xchanger, int ychanger, ruch *R, bool *fbicie, bool *nadsf, bool *czyda); // j = {0,1,2,3}, i = 0..11; ^ to samo
    void chansetter(int j, int *xchanger, int *ychanger); // j = {0,1,2,3}
    bool OLDmozliwoscbicia(int id, bool Tt, bool X=1); // tworzy obiekty klasy ruch i wysyla do possible [TUTAJ WYSYLAC ID OD 0 DO 12]

    bool kruch(); // okresla ktora druzyna ma ruch  zwraca 0 jesli przeciwnik lub 1 jesli jesli znowu my
    void showALL();
    void update(int id, c S); // akutalizuje polozenie pionka na mapie char
    int g00d(bool czy_wyswietlac=0); // warunek trwania gry, jesli nie jest spelniony co sie stalo // ZWRACA 1 - WYGRALI BIALI // ZWRACA 2 - WYGRALI CZARNI // ZWRACA 3 - REMIS //ZWRACA 0 -  GRA TOCZY SIE DALEJ
    int czy_wygrana();
    int czyremis(bool t);//spr. czy biale niemoga wykonac zadnego ruchu
};




#endif // CLASS_H_INCLUDED
