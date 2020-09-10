#pragma once

/// Funkcja wyswietla plansze podczas dodawania statkow
/// @param plansza plansza ze statkami danego gracza
/// @param gracz wskazuje ktory gracz aktualnie dodaje statki
void wyswietl_plansze_make(struct statek plansza[10][10], char* gracz);

/// Funkcja wyswietla plansze podczas gry
/// @param plansza plansza ze statkami danego gracza
void wyswietl_plansze_game(struct statek plansza[10][10]);

/// Funkcja wyswietla plansze poprzednich strzalow podczas gry
/// @param tab plansza z poprzednimi strzalami 
void wyswietl_plansze_strzalow(int tab[10][10]);

/// Funkcja umieszcza statki na planszy
/// @param statki tablica zawierajaca wskazniki na wszystkie statki danego gracza
/// @param plansza plansza ze statkami danego gracza
void dodaj_na_plansze(struct statek* statki[5], struct statek plansza[10][10]);

/// Funkcja wypelnia pusta plansze "blindspotami"
/// @param plansza plansza ze statkami danego gracza
void wypelnij_plansze(struct statek plansza[10][10]);

/// Funkcja umieszcza pole, przez ktore na danym miejscu nie mozna postawic nowego statku
/// @param plansza plansza ze statkami danego gracza
/// @param min wartosc najmniejsza podczas dodawania martwego pola
/// @param max wartosc najwieksza podczas dodawania martwego pola
/// @param kolumna wskazuje kolumne, w ktorej bedzie dodawane martwe pole
void umiesc_martwe_pole_pionowe(struct statek plansza[10][10], int min, int max, int kolumna);

/// Funkcja umieszcza pole, przez ktore na danym miejscu nie mozna postawic nowego statku
/// @param plansza plansza ze statkami danego gracza
/// @param min wartosc najmniejsza podczas dodawania martwego pola
/// @param max wartosc najwieksza podczas dodawania martwego pola
/// @param wiersz wskazuje wiersz w ktorym bedzie dodawane martwe pole
void umiesc_martwe_pole_poziome(struct statek plansza[10][10], int min, int max, int wiersz);



