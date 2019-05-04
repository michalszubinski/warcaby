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
    bool bicie; // czy bylo bicie
    int bicieid; // id zbitego pionka przy tym ruchu
    bool team; // druzyna z ktorej pochodzi pionek

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
    bool a(); // sprawdza czy pionek nie jest zbity
    void kill(); // zabija pionek
    bool czydamka(); // sprawdza czy pionek jest damka
    int dorendera_x(); //c pos jest private a musia³em siê dostaæ do x i y
    int dorendera_y();
    c pozycja(); // zwraca pozycje pionka
    int getid(); // zwraca id
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

public:
    MAP(); //inicjalizuje gre //  MAP_StartEnd.cpp
    ~MAP();// konczy gre// MAP_StartEnd.cpp // KIEDY ZOSTANIE ZROBIONA FUNKCJA g00d NALEZY USUNAC KOMENTARZE W TEJ FUNCKJI!!!!
   void render(); // rysuje mape DO POPRAWY
    
    //void GAME(); // funckja gry WRZUCAM KOD DO ZASTANOWIENIA SIE
   void TURN(); // poczatkuje zmiane pozycji ######
   ruch decide(bool Tt); // decyduje ktory typ gracza wybrac ######

    ruch player0(); //te cyferki oznaczaja typy gracza ######
    ruch player1();   //0-czlowiek 1-random 2-minimax ######
    ruch player2();
    void changer(ruch abc); // zastosowuje ruch ######
    
    bool prepos(ruch &R); // podstawowe warunki mozliwosc ruchu
    bool possible(ruch &R);// czy ruch jest mozliwy ######
    char polehelp(c pole); // sprawdza co jest na danym polu (POMOCNIK FUNKCJI possible)

    bool czybicieNORM(ruch &R); // czy bicie dla normalnego pionka
    bool czybicieDAMKA(ruch &R); // czy bicie dla damki
    bool mozliwoscbicia(int id, bool Tt); // tworzy obiekty klasy ruch i wysyla do possible
    bool czyjakiesbicie(bool Tt); // sprawdza bicie dla wszystkich pionkow danej druzyny
    int Realid(int id); // zmienia id pionka na miejsce w tablicy pionkow odpowiednie dla jego druzyny - na podstawie ruchu
    bool Teamprzeciwny(bool t); //patrzy jaka druzyna jest przeciwna - na podstawie ruchu
    bool czydamkaPOS(int id,bool Tt); // sprawdza czy dany pionek z danej druzyny jest damka
    void ladujbicie(ruch &R, c polewroga); // laduje bicie do obiektu klasy ruch

    int kruch(); // okresla ktora druzyna ma ruch ###### zwraca 0 jesli przeciwnik lub 1 jesli jesli znowu my
    int g00d(); // warunek trwania gry, jesli nie jest spelniony co sie stalo ###### // ZWRACA 1 - WYGRALI BIALI // ZWRACA 2 - WYGRALI CZARNI // ZWRACA 3 - REMIS //ZWRACA 0 -  GRA TOCZY SIE DALEJ
};




#endif // CLASS_H_INCLUDED
