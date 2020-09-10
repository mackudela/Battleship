#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <time.h>
#include "Operacje-na-planszach.h"
#include "struktura-statek.h"
#include "dodawanie-statku.h"
#include "manipulacja-wierszami.h"
#include "tok-gry.h"
#include "operacje-na-plikach.h"

int main()
{
	char gracz1[15];
	printf("Gracz 1, podaj swoja nazwe: ");
	scanf("%s", &gracz1);
	char gracz2[15];
	printf("Gracz 2, podaj swoja nazwe: ");
	do
	{
		scanf("%s", &gracz2);
		if (strcmp(gracz1, gracz2) == 0)
			printf("Nazwy graczy nie moga byc identyczne!\n Podaj nowa nazwe: ");
	} while(strcmp(gracz1, gracz2) == 0);
	struct statek plansza_gracz1[10][10];
	wypelnij_plansze(plansza_gracz1);
	struct statek plansza_gracz2[10][10];
	wypelnij_plansze(plansza_gracz2);
	struct statek* statki_gracz1[5];
	struct statek* statki_gracz2[5];
	int strzalyg1[10][10];
	int strzalyg2[10][10];
	int i;
	printf("\n");
	for (i = 0; i < 5; i++)
	{
		statki_gracz1[i] = dodaj_statek(2, plansza_gracz1, gracz1);
		system("cls");
	}
	dodaj_na_plansze(statki_gracz1, plansza_gracz1);
	wyswietl_plansze_game(plansza_gracz1);
	Sleep(5000);
	system("cls");
	for (i = 0; i < 5; i++)
	{
		statki_gracz2[i] = dodaj_statek(2, plansza_gracz2, gracz2);
		system("cls");
	}
	dodaj_na_plansze(statki_gracz2, plansza_gracz2);
	system("cls");
	gra(plansza_gracz1, plansza_gracz2, statki_gracz1, statki_gracz2, strzalyg1, strzalyg2, gracz1, gracz2);
	kasowanie_statkow(statki_gracz1);
	kasowanie_statkow(statki_gracz2);
}