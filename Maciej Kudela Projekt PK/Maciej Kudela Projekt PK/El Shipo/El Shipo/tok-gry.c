#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "tok-gry.h"
#include "struktura-statek.h"
#include "operacje-na-plikach.h"

bool ruch_gracza(struct statek plansza[10][10], struct statek plansza_przeciwnika[10][10], int strzaly[10][10], struct statek* statki_przeciwnika[5])
{
	int wiersz, kolumna;
	printf("Twoja plansza: \n");
	wyswietl_plansze_game(plansza);
	printf("\n Twoja plansza strzalow: \n");
	wyswietl_plansze_strzalow(strzaly);
	wiersz = pobierz_wiersz_clean();
	kolumna = pobierz_kolumne_clean();
	if (plansza_przeciwnika[wiersz][kolumna].life == 1)
	{
		printf("Trafiony!\n");
		strzaly[wiersz][kolumna] = 1;
		plansza_przeciwnika[wiersz][kolumna].life = 0;
		skoryguj(statki_przeciwnika, wiersz, kolumna);
		if (sprawdz_statek(plansza_przeciwnika, wiersz, kolumna) == true)
			printf("Zatopiony!\n");
		Sleep(5000);
		system("cls");
		return true;
	}
	else
	{
		printf("Pudlo!\n");
		strzaly[wiersz][kolumna] = 0;
		Sleep(5000);
		system("cls");
		return false;
	}
}

bool sprawdz_statek(struct statek plansza_przeciwnika[10][10], int wiersz, int kolumna)
{
	struct statek* p;
	int licznik = 0;
	p = &plansza_przeciwnika[wiersz][kolumna];
	if (p)
	{
		while (p->pPrev)
			p = p->pPrev;
		while (p)
		{
			if (p->life == 1)
				licznik++;
			p = p->pNext;
		}
	}
	if (licznik == 0)
		return true;
	else
		return false;
}

bool sprawdz_wszystkie_statki(struct statek* statki[5])
{
	struct statek* pHead;
	int i = 0, licznik = 0;
	for (i = 0; i < 5; i++)
	{
		pHead = statki[i];
		while (pHead)
		{
			if (pHead->life == 1)
				licznik++;
			pHead = pHead->pNext;
		}
	}
	if (licznik == 0)
		return true;
	else
		return false;
}

void gra(struct statek plansza_gracz1[10][10], struct statek plansza_gracz2[10][10], struct statek* statki_gracz1[5], struct statek* statki_gracz2[5], int strzalyg1[10][10], int strzalyg2[10][10], char* gracz1, char* gracz2)
{
	system("cls");
	printf("Gra rozpoczeta!\n");
	do
	{
		do
		{
			printf("Ruch gracza %s!\n", gracz1);
		} while (ruch_gracza(plansza_gracz1, plansza_gracz2, strzalyg1, statki_gracz2) == true && sprawdz_wszystkie_statki(statki_gracz2) == false);
		if (sprawdz_wszystkie_statki(statki_gracz2) == false)
		{
			do
			{
				printf("Ruch gracza %s!\n", gracz2);
			} while (ruch_gracza(plansza_gracz2, plansza_gracz1, strzalyg2, statki_gracz1) == true && sprawdz_wszystkie_statki(statki_gracz1) == false);
		}
	} while (sprawdz_wszystkie_statki(statki_gracz1) == false && sprawdz_wszystkie_statki(statki_gracz2) == false);
	if (sprawdz_wszystkie_statki(statki_gracz2) == true)
	{
		printf("Gra zakonczona!\n\tZwycieza %s!\n\n\n", gracz1);
		zapis_wyniku(gracz1);
	}
	else
	{
		printf("Gra zakonczona!\n\tZwycieza %s!\n\n\n", gracz2);
		zapis_wyniku(gracz2);
	}
}

void kasowanie_statkow(struct statek* statki[5])
{
	int i = 0;
	struct statek* p, * tmp;
	for (i; i < 5; i++)
	{
		p = statki[i];
		while (p)
		{
			tmp = p->pNext;
			free(p);
			p = tmp;
		}
	}
}