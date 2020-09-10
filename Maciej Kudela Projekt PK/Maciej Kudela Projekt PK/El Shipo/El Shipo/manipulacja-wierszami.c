#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "manipulacja-wierszami.h"
#include "struktura-statek.h"

int pobierz_kolumne_clean()
{
	int kolumna;
	do
	{
		printf("Podaj kolumne(1-10): ");
		scanf_s("%d", &kolumna);
		if (kolumna < 1 || kolumna > 10)
			printf("Niepoprawna kolumna!\n");
	} while (kolumna < 1 || kolumna > 10);
	return kolumna - 1;
}

int pobierz_wiersz_clean()
{
	int wiersz;
	do
	{
		printf("Podaj wiersz(1-10): ");
		scanf_s("%d", &wiersz);
		if (wiersz < 1 || wiersz > 10)
			printf("Niepoprawny wiersz!\n");
	} while (wiersz < 1 || wiersz > 10);
	return wiersz - 1;
}

int pobierz_wiersz_check(struct statek plansza[10][10], int kolumna)
{
	int wiersz;
	do
	{
		printf("Podaj wiersz(1-10): ");
		scanf_s("%d", &wiersz);
		if (wiersz < 1 || wiersz > 10 || plansza[wiersz - 1][kolumna].blind == 1)
			printf("Niepoprawny wiersz!\n");
	} while (wiersz < 1 || wiersz > 10 || plansza[wiersz - 1][kolumna].blind == 1);
	return wiersz - 1;
}

int pobierz_kolumne_check(struct statek plansza[10][10], int wiersz)
{
	int kolumna;
	do
	{
		printf("Podaj kolumne(1-10): ");
		scanf_s("%d", &kolumna);
		if (kolumna < 1 || kolumna > 10 || plansza[wiersz][kolumna - 1].blind == 1)
			printf("Niepoprawny wiersz!\n");
	} while (kolumna < 1 || kolumna > 10 || plansza[wiersz][kolumna - 1].blind == 1);
	return kolumna - 1;
}

int pobierz_wiersz_pionowy(struct statek plansza[10][10], int kolumna, int min, int max)
{
	int wiersz;
	do
	{
		if (min < 1)
		{
			printf("Podaj wiersz(%d)", max + 2);
			scanf_s("%d", &wiersz);
			if (wiersz == max + 2 && plansza[wiersz - 1][kolumna].blind != 1)
			{
				wiersz = wiersz - 1;
				return wiersz;
			}
			else
				printf("Nieprawidlowy wiersz!\n");
		}
		else if (max + 2 > 10)
		{
			printf("Podaj wiersz(%d)", min);
			scanf_s("%d", &wiersz);
			if (wiersz == min && plansza[wiersz - 1][kolumna].blind != 1)
			{
				wiersz = wiersz - 1;
				return wiersz;
			}
			else
				printf("Nieprawidlowy wiersz!\n");
		}
		else
		{
			printf("Podaj wiersz(%d lub %d): ", min, max + 2);
			scanf_s("%d", &wiersz);
			if (wiersz == min && plansza[wiersz - 1][kolumna].blind != 1)
			{
				wiersz = wiersz - 1;
				return wiersz;
			}
			else if (wiersz == max + 2 && plansza[wiersz - 1][kolumna].blind != 1)
			{
				wiersz = wiersz - 1;
				return wiersz;
			}
			else
				printf("Nieprawidlowy wiersz!\n");
		}
	} while (1);
}

int pobierz_kolumne_poziomy(struct statek plansza[10][10], int wiersz, int min, int max)
{
	int kolumna;
	do
	{
		if (min < 1)
		{
			printf("Podaj kolumne(%d)", max + 2);
			scanf_s("%d", &kolumna);
			if (kolumna == max + 2 && plansza[wiersz][kolumna - 1].blind != 1)
				return kolumna - 1;
			else
				printf("Nieprawidlowa kolumna!\n");
		}
		else if (max + 2 > 10)
		{
			printf("Podaj kolumne(%d)", min);
			scanf_s("%d", &kolumna);
			if (kolumna == min && plansza[wiersz][kolumna - 1].blind != 1)
				return kolumna - 1;
			else
				printf("Nieprawidlowa kolumna!\n");
		}
		else
		{
			printf("Podaj kolumne(%d lub %d): ", min, max + 2);
			scanf_s("%d", &kolumna);
			if (kolumna == min && plansza[wiersz][kolumna - 1].blind != 1)
				return kolumna - 1;
			else if (kolumna == max + 2 && plansza[wiersz][kolumna - 1].blind != 1)
				return kolumna - 1;
			else
				printf("Nieprawidlowa kolumna!\n");
		}
	} while (1);
}