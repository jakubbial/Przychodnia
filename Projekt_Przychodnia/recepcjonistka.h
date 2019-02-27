#pragma once
#include "osoba.h"
#include <vector>
#include "pacjent.h"

class recepcjonistka
	:public osoba							//dziedziczenie typu public
{
	public:
		std::string imie_pacjenta;
		std::string nazwisko_pacjenta;
		std::string skierowanie;
		std::vector<int> kolejka; 			//wpisywane numerki pacjentow. To jest vector, bo operowanie na dynamicznych tablicach jest trudne
		int aktualny_pacjent; 
		pacjent * przyjety_pacjent;			//wskaznik do ostatnio utworzonego obiektu klasy pacjent 

		recepcjonistka(std::string imi, std::string nazwis, std::string pos, std::string spec, std::string num);
		void wyswietl_kolejke();
		void przyjmij_pacjenta();			//
		void wywiad_wstepny();				//zadaje pytania i przydziela rodzaj lekarza do skierowania
		void przydziel_pacjenta();
};