#pragma once

/// Funkcja pobiera kolumne bez obostrzen
int pobierz_kolumne_clean();

/// Funkcja pobiera wiersz bez obostrzen
int pobierz_wiersz_clean();

/// Funkcja pobiera wiersz i sprawdza czy dane miejsce jest wolne
/// @param plansza plansza ze statkami danego gracza
/// @param kolumna kolumna w ktorej bedzie dodany statek
int pobierz_wiersz_check(struct statek plansza[10][10], int kolumna);

/// Funkcja pobiera kolumne i sprawdza czy dane miejsce jest wolne
/// @param plansza plansza ze statkami danego gracza
/// @param wiersz wiersz w ktorym bedzie dodany statek
int pobierz_kolumne_check(struct statek plansza[10][10], int wiersz);

/// Funkcja pobiera wiersz podczas dalszej czesci dodawania pionowego statku
/// @param plansza plansza ze statkami danego gracza
/// @param kolumna kolumna w ktorej bedzie dodany statek
/// @param min wartosc najmniejsza potrzebna pozniej do wyznaczenia martwego pola
/// @param max wartosc najwieksza potrzebna pozniej do wyznaczenia martwego pola
int pobierz_wiersz_pionowy(struct statek plansza[10][10], int kolumna, int min, int max);

/// Funkcja pobiera kolumne podczas dalszej czesci dodawania poziomego statku
/// @param plansza plansza ze statkami danego gracza
/// @param wiersz wiersz w ktorym bedzie dodany statek
/// @param min wartosc najmniejsza potrzebna pozniej do wyznaczenia martwego pola
/// @param max wartosc najwieksza potrzebna pozniej do wyznaczenia martwego pola
int pobierz_kolumne_poziomy(struct statek plansza[10][10], int wiersz, int min, int max);

