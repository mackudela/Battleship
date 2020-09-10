#pragma once

/// Funkcja dodaje nowy statek
/// @param N wskazuje ilosc masztow, jaka posiada dodawany statek
/// @param plansza plansza ze statkami danego gracza
/// @param gracz wskazuje ktory gracz aktualnie dodaje statki
struct statek* dodaj_statek(int N, struct statek plansza[10][10], char* gracz);

/// Funkcja dodaje statek pionowy 
/// @param N ilosc masztow w danym statku
/// @param plansza plansza ze statkami danego gracza
/// @param gracz wskazuje ktory gracz aktualnie dodaje statki
struct statek* dodaj_statek_pionowy(int N, struct statek plansza[10][10], char* gracz);

/// Funkcja dodaje statek poziomy 
/// @param N ilosc masztow w danym statku
/// @param plansza plansza ze statkami danego gracza
/// @param gracz wskazuje ktory gracz aktualnie dodaje statki
struct statek* dodaj_statek_poziomy(int N, struct statek plansza[10][10], char* gracz);

/// Funkcja alokuje pamiec oraz tworzy liste dwukierunkowa
/// @param wiersz wiersz, w ktorym alokowany jest maszt
/// @param kolumna kolumna, w ktorej alokowany jest maszt
/// @param i licznik potrzebny do odroznienia pierwszego masztu od reszty
/// @param poprzedni wskaznik na poprzedni maszt w danym statku
struct statek* alokacja_masztu(int wiersz, int kolumna, int i, struct statek* poprzedni);

/// Funkcja koryguje dane miedzy plansza gracza oraz tablica jego statkow
/// @param statki_przeciwnika plansza ze statkami przeciwnika
/// @param wiersz wiersz masztu do korekty
/// @param kolumna kolumna masztu do korekty
void skoryguj(struct statek* statki_przeciwnika[5], int wiersz, int kolumna);

