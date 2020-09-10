#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "dodawanie-statku.h"
#include "struktura-statek.h"

struct statek* dodaj_statek(int N, struct statek plansza[10][10], char* gracz)
{
	int wybor;
	struct statek* pHead;
	wyswietl_plansze_make(plansza, gracz);
	do
	{
		printf("Jaki statek dodajesz?\n Poziomy[1] / Pionowy[2]: ");
		scanf_s("%d", &wybor);
		if (wybor == 1)
			return dodaj_statek_poziomy(N, plansza, gracz);
		else if (wybor == 2)
			return dodaj_statek_pionowy(N, plansza, gracz);
		else
			printf("Nieprawidlowy wybor!\n\n");
	} while (1);
}

struct statek* dodaj_statek_pionowy(int N, struct statek plansza[10][10], char* gracz)
{
	int kolumna = 0, wiersz, i, min = 0, max = 0;
	struct statek* pHead, * p;
	pHead = p = NULL;
	for (i = 0; i < N; i++)
	{
		if (i == 0)
		{
			wyswietl_plansze_make(plansza, gracz);
			kolumna = pobierz_kolumne_clean();
			wiersz = pobierz_wiersz_check(plansza, kolumna);
			max = min = wiersz;
			pHead = p = alokacja_masztu(wiersz, kolumna, i, p);
		}
		else
		{
			wyswietl_plansze_make(plansza, gracz);
			wiersz = pobierz_wiersz_pionowy(plansza, kolumna, min, max);
			if (wiersz < min)
				if (wiersz <= 0)
					min = 0;
				else
					min = wiersz;
			if (wiersz > max)
				if (wiersz >= 9)
					max = 9;
				else
					max = wiersz;
			while (p->pNext)
				p = p->pNext;
			p->pNext = alokacja_masztu(wiersz, kolumna, i, p);
		}
	}
	umiesc_martwe_pole_pionowe(plansza, min, max, kolumna);
	return pHead;
}

struct statek* dodaj_statek_poziomy(int N, struct statek plansza[10][10], char* gracz)
{
	int kolumna, wiersz = 0, i, min = 0, max = 0;
	struct statek* pHead, * p;
	pHead = p = NULL;
	for (i = 0; i < N; i++)
	{
		if (i == 0)
		{
			wyswietl_plansze_make(plansza, gracz);
			wiersz = pobierz_wiersz_clean();
			kolumna = pobierz_kolumne_check(plansza, wiersz);
			max = min = kolumna;
			pHead = p = alokacja_masztu(wiersz, kolumna, i, p);
		}
		else
		{
			wyswietl_plansze_make(plansza, gracz);
			kolumna = pobierz_kolumne_poziomy(plansza, wiersz, min, max);
			if (kolumna < min)
				if (kolumna <= 0)
					min = 0;
				else
					min = kolumna;
			if (kolumna > max)
				if (kolumna >= 9)
					max = 9;
				else
					max = kolumna;
			while (p->pNext)
				p = p->pNext;
			p->pNext = alokacja_masztu(wiersz, kolumna, i, p);
		}
	}
	umiesc_martwe_pole_poziome(plansza, min, max, wiersz);
	return pHead;
}

struct statek* alokacja_masztu(int wiersz, int kolumna, int i, struct statek* poprzedni)
{
	struct statek* tmp;
	tmp = malloc(sizeof(struct statek));
	tmp->life = 1;
	tmp->blind = 1;
	tmp->wiersz = wiersz;
	tmp->kolumna = kolumna;
	tmp->pNext = NULL;
	if (i == 0)
		tmp->pPrev = NULL;
	else
		tmp->pPrev = poprzedni;
	return tmp;
}

void skoryguj(struct statek* statki_przeciwnika[5], int wiersz, int kolumna)
{
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		struct statek* p = statki_przeciwnika[i];
		while (p)
		{
			if (p->wiersz == wiersz && p->kolumna == kolumna)
				p->life = 0;
			p = p->pNext;
		}
	}
}