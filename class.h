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
    c o; // stara pozycja
    c n; // nowa pozycja
    bool bicie; // czy bylo bicie
    int bicieid; // id zbitego pionka przy tym ruchu

    //bool operator==(ruch other); // ######
    //bool operator!=(ruch other); // ######
};

class _ob // PIONEK
{
    bool team; // druzyna pionka
    bool alive; // czy nie jest zbity
    c pos; // pozycja pionka
    bool damka; // czy jest damka
public:
    //_ob(); // konstrktor - NIE MAM POMYSLU CO MOZE ROBIC ALE NIECH BEDZIE JAK MACIE POMYSL [NAJLEPIEJ ZEBY NIE PRZYJMOWAL WARTOSCI!!!] ######
    void setteam(bool t); // ustawia druzyne
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
    team(bool tea, char playertype=0, string name=""); // konstuktor wczytuje statystyki z pliku
    ~team(); // dekonstruktor zapisuje statystyki
    void setplayertype(char T); // ustawia typ gracza
    string getplayertype(); // string = TYP GRACZA | JEGO DRUZYNA
    bool gett(); //zwraca druzyne
    char getpt(); // zwraca typ gracza
    void StatsFromFile(); // Wczytywanie statystyk z pliku ######
    void StatsToFile(); // Zapisywanie statystyk do pliku ######
};

class MAP
{
    bool act; // jaka druzyna ma ruch
    _ob T0[12]; // pionki druzyny bialych
    _ob T1[12]; // czarnych
    team T[2]; // 2 druzyny

public:
    //MAP(); inicjalizuje gre ######
    //~MAP(); inicjalizuje gre ######
    //void render(); // rysuje mape ######

    //void TURN(); // poczatkuje zmiane pozycji ######
    //ruch decide(); // decyduje ktory typ gracza wybrac ######

    //ruch player0(); te cyferki oznaczaja typy gracza ######
    //ruch player1();
    //ruch player2();

    //void changer(); // zastosowuje ruch ######
    //bool possible();// czy ruch jest mozliwy ######



    //int g00d(); // warunek trwania gry, jesli nie jest spelniony co sie stalo ######
};




#endif // CLASS_H_INCLUDED
