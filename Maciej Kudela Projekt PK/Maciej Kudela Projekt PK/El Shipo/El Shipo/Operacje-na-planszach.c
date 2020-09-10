#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "Operacje-na-planszach.h"
#include "struktura-statek.h"

void wyswietl_plansze_make(struct statek plansza[10][10], char* gracz)
{
	system("cls");
	printf("Dodawanie statkow gracz %s:\n\n", gracz);
	int i = 0, k = 0;
	for (i = 0; i < 10; i++)
	{
		if (i == 0)
			printf("    %d ", i + 1);
		else
			printf(" %d ", i + 1);
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		if (i + 1 == 10)
			printf("%d ", i + 1);
		else
			printf("%d  ", i + 1);
		for (k = 0; k < 10; k++)
		{
			printf("[");
			if (plansza[i][k].life == 1)
				printf("+");
			else if (plansza[i][k].blind == 1)
				printf("0");
			else
				printf(" ");
			printf("]");
		}
		printf("\n");
	}
}

void wyswietl_plansze_game(struct statek plansza[10][10])
{
	int i = 0, k = 0;
	for (i = 0; i < 10; i++)
	{
		if (i == 0)
			printf("    %d ", i + 1);
		else
			printf(" %d ", i + 1);
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		if (i + 1 == 10)
			printf("%d ", i + 1);
		else
			printf("%d  ", i + 1);
		for (k = 0; k < 10; k++)
		{
			printf("[");
			if (plansza[i][k].life == 1)
				printf("+");
			else if (plansza[i][k].life == 0)
				printf("0");
			else
				printf(" ");
			printf("]");
		}
		printf("\n");
	}
}

void wyswietl_plansze_strzalow(int tab[10][10])
{
	int i = 0, k = 0;
	for (i = 0; i < 10; i++)
	{
		if (i == 0)
			printf("    %d ", i + 1);
		else
			printf(" %d ", i + 1);
	}
	printf("\n");
	for (i = 0; i < 10; i++)
	{
		if (i + 1 == 10)
			printf("%d ", i + 1);
		else
			printf("%d  ", i + 1);
		for (k = 0; k < 10; k++)
		{
			printf("[");
			if (tab[i][k] == 1)
				printf("x");
			else if (tab[i][k] == 0)
				printf("o");
			else
				printf(" ");
			printf("]");
		}
		printf("\n");
	}
}

void dodaj_na_plansze(struct statek* statki[5], struct statek plansza[10][10])
{
	int i = 0;
	for (i; i < 5; i++)
	{
		if (statki[i])
		{
			struct statek* tmp = statki[i];
			while (tmp)
			{
				plansza[tmp->wiersz][tmp->kolumna] = *tmp;
				tmp = &plansza[tmp->wiersz][tmp->kolumna];
				tmp = tmp->pNext;
			}
		}
	}
}

void wypelnij_plansze(struct statek plansza[10][10])
{
	int i, k;
	struct statek pusty;
	pusty.blind = 0;
	for (i = 0; i < 10; i++)
	{
		for (k = 0; k < 10; k++)
			plansza[i][k] = pusty;
	}
}

void umiesc_martwe_pole_pionowe(struct statek plansza[10][10], int min, int max, int kolumna)
{
	int powrot = kolumna - 1;
	int min_kolumny = kolumna - 1, max_kolumny = kolumna + 1;
	struct statek test;
	test.blind = 1;
	for (min - 1; min - 1 <= max + 1; min++)
	{
		for (min_kolumny = powrot; min_kolumny <= max_kolumny; min_kolumny++)
		{
			if (min - 1 >= 0 && min - 1 <= 9 && min_kolumny >= 0 && min_kolumny <= 9)
				if (plansza[min - 1][min_kolumny].blind == 0)
					plansza[min - 1][min_kolumny] = test;
		}
	}
}

void umiesc_martwe_pole_poziome(struct statek plansza[10][10], int min, int max, int wiersz)
{
	int powrot = wiersz - 1;
	int min_wiersz = wiersz - 1, max_wiersz = wiersz + 1;
	struct statek test;
	test.blind = 1;
	for (min - 1; min - 1 <= max + 1; min++)
	{
		for (min_wiersz = powrot; min_wiersz <= max_wiersz; min_wiersz++)
		{
			if (min - 1 >= 0 && min - 1 <= 9 && min_wiersz >= 0 && min_wiersz <= 9)
				if (plansza[min_wiersz][min - 1].blind == 0)
					plansza[min_wiersz][min - 1] = test;
		}
	}
}