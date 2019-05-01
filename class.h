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
};

struct ruch // KORDYNATY RUCHU
{
    int wartoscruchu; // dla minimax
    int id; //id pionka
    c o; // stara pozycja
    c n; // nowa pozycja
    bool bicie; // czy bylo bicie
    int bicieid; // id zbitego pionka przy tym ruchu

    bool operator==(ruch other); 
    bool operator!=(ruch other); 
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
    void StatsToFile(); // Zapisywanie statystyk do pliku ######
    void setteam(bool TTT); // ustawia druzyne
    void setteamname(string X); // ustawia nazwe druzyny
};

class MAP
{
    bool act; // jaka druzyna ma ruch
    _ob T0[12]; // pionki druzyny bialych
    _ob T1[12]; // czarnych
    team T[2]; // 2 druzyny

public:
    MAP(); //inicjalizuje gre //  MAP_StartEnd.cpp
    ~MAP();// konczy gre// MAP_StartEnd.cpp // KIEDY ZOSTANIE ZROBIONA FUNKCJA g00d NALEZY USUNAC KOMENTARZE W TEJ FUNCKJI!!!!
    //void render(); // rysuje mape ######

    //void TURN(); // poczatkuje zmiane pozycji ######
    //ruch decide(); // decyduje ktory typ gracza wybrac ######

    //ruch player0(); te cyferki oznaczaja typy gracza ######
    //ruch player1();
    //ruch player2();

    //void changer(); // zastosowuje ruch ######
    //bool possible();// czy ruch jest mozliwy ######

    //void kruch(); // okresla ktora druzyna ma ruch ######



    //int g00d(); // warunek trwania gry, jesli nie jest spelniony co sie stalo ###### // ZWRACA 1 - WYGRALI BIALI // ZWRACA 2 - WYGRALI CZARNI // ZWRACA 3 - REMIS
};




#endif // CLASS_H_INCLUDED
