#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <Windows.h>
#include <time.h>


void zapis_wyniku(char* gracz)
{
	FILE* plik;
    time_t curtime;
    time(&curtime);
    plik = fopen("wyniki.txt", "a");
    if (plik == NULL)
    {
        printf("Blad otwarcia pliku");
        return -1;
    }
    else
        fprintf(plik, "Czas zakonczenia gry = %szwycieza gracz: %s\n\n", ctime(&curtime), gracz);
    fclose(plik);
}