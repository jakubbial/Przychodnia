#pragma once
#include <vector>
#include <string>
#include "recepcjonistka.h"
#include "lekarz.h"

class przychodnia
{
	public:
	std::vector<std::vector<std::string> > obsada;	//wektor na dane obsady
	std::vector<recepcjonistka> recepcja;			//wektor na obiekty recepcjonistka
	std::vector<lekarz> lekarze;					//wektor na lekarzy
	int licznik_kolejki; 					    	//numerki kolejnych pacjentów
	
	przychodnia();									//konstruktor inicjalizuje jedna zmienna
	void wczytaj_obsade();	 						//wpisuje dane kolejnych osob do wektora
	void laduj_obsade(); 							//bierze dane z wektora i tworzy obiekty. Obiekty danej profesji przechowywane sa w wektorach
	void pobierz_numerek();							//przydziela nowemu pacjentowi numerek. Tworzona jest kolejka pacjentow przed recepcja
	void przydziel_do_lekarza();					//na podstawie wstepnego wywiadu pacjent kierownay jest do odpowiednego lekarza
	void rozpocznij_dzialanie();					//Algorytm dzialania programu
	void wyswietl_lekarzy();						//Wyswietla jacy lekarze parcuja w przychodni
};

