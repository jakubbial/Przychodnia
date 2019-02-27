#include "stdafx.h"
#include <iostream>
#include <string>
#include "recepcjonistka.h"
#include "przychodnia.h"


int _tmain(int argc, _TCHAR* argv[])
{
	przychodnia p;				//tworzony obiekt klasy przychodnia
	p.wczytaj_obsade();			//wczytuje obsade przychodni
	p.laduj_obsade();			//tworzy obiekty pracownikow
	p.rozpocznij_dzialanie();	//uruchomienie algorytmu

	return 0;
}

