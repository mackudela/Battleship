#pragma once

/// Funkcja umozliwia ruch, przez co gracz moze oddac strzal, po czym sprawdza czy byl trafiony, oraz czy gra moze zostac zakonczona
/// @param plansza plansza ze statkami danego gracza
/// @param plansza_przeciwnika plansza ze statkami przeciwnika
/// @param strzaly plansza z poprzednimi strzalami danego gracza
/// @param statki_przeciwnika plansza ze statkami przeciwnika
bool ruch_gracza(struct statek plansza[10][10], struct statek plansza_przeciwnika[10][10], int strzaly[10][10], struct statek* statki_przeciwnika[5]);

/// Funkcja sprawdza czy dany statek zostal w calosci zniszczony
/// @param plansza_przeciwnika plansza ze statkami przeciwnika
/// @param wiersz wiersz w ktorym znajduje sie zestrzelony statek
/// @param kolumna kolumna w ktorej znajduje sie zestrzelony statek
bool sprawdz_statek(struct statek plansza_przeciwnika[10][10], int wiersz, int kolumna);

/// Funkcja sprawdza czy graczowi zostaly jeszcze jakies statki
/// @param statki tablica ze wskaznikami na wszystkie statki danego gracza
bool sprawdz_wszystkie_statki(struct statek* statki[5]);

/// Funkcja rozpoczyna faktyczna czesc gry
/// @param plansza_gracz1 plansza ze statkami pierwszego gracza
/// @param plansza_gracz2 plansza ze statkami drugiego gracza
/// @param statki_gracz1 tablica ze wskaznikami na statki pierwszego gracza
/// @param statki_gracz2 tablica ze wskaznikami na statki drugiego gracza
/// @param strzalyg1 plansza z poprzednimi strzalami pierwszego gracza
/// @param strzalyg2 plansza z poprzednimi strzalami drugiego gracza
/// @param gracz1 przechowuje nazwe gracza 1
/// @param gracz2 przechowuje nazwe gracza 2
void gra(struct statek plansza_gracz1[10][10], struct statek plansza_gracz2[10][10], struct statek* statki_gracz1[5], struct statek* statki_gracz2[5], int strzalyg1[10][10], int strzalyg2[10][10], char* gracz1, char* gracz2);

/// Funkcja usuwa zalegle statki w pamieci
/// @param statki tablica ze wskaznikami na wszystkie statki danego gracza
void kasowanie_statkow(struct statek* statki[5]);