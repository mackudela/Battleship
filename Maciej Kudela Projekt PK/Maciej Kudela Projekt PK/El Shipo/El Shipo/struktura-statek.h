/*! podstawowa struktura przedstawiajaca statek, posiada wskaznik zycia, wiersz i kolumne w ktorej sie znajduje oraz wskazniki na poprzedni i nastepny maszt */
struct statek
{
	int life;  /*!< wskaznik zycia, jesli wynosi 0 oznacza to ze maszt zostal zestrzelony */
	int blind;  /*!< wartosc blindspota, wynosi 1 jesli statek zajmuje pole na planszy */
	int wiersz;  /*!< przechowuje wiersz w ktorym znajduje sie statek */
	int kolumna;  /*!< przechowuje kolumne w ktorej znajduje sie statek */
	struct statek* pPrev;  /*!< wskaznik na poprzedni maszt w statku */
	struct statek* pNext;  /*!< wskaznik na nastepny maszt w statku */
};