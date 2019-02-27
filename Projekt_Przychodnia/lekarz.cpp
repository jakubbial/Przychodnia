#include "lekarz.h"
#include <iostream>

lekarz::lekarz(std::string imi, std::string nazwis, std::string pos, std::string spec, std::string num)
{
	imie = imi;
	nazwisko = nazwis;
	posada = pos;
	specjalnosc = spec;
	numer = num; 
	pacjenci.clear();
}

void lekarz::wyswietl_kolejke(){
	if(pacjenci.size() == 0){
		std::cout << "\nKolejka pusta!\n";
	}else{
		std::cout << "W kolejce " << pacjenci.size() << " pacjentow\n";
		for(unsigned int i=0; i < pacjenci.size(); i++){
			std::cout << "Pacjent " << i << " " << pacjenci.at(i)->imie << " " << pacjenci.at(i)->nazwisko << "\n";
		}
	}
}

void lekarz::wywiad_szczegolowy(){
	char wywiad[3];
	
	if (specjalnosc == "Psychiatra"){
	std::cout << "Omamy?\n";
	std::cin >> wywiad[0];
	std::cout << "Bol pulsujacy?\n";
	std::cin >> wywiad[1];
	std::cout << "Bezsennosc?\n";
	std::cin >> wywiad[2];
		if(wywiad[0] == 't'|| wywiad[0] == 'T'){
			diagnoza = "Ciezka choroba - terapia";
		}else if(wywiad[1] == 't'|| wywiad[1] == 'T'){
			diagnoza = "Uderzenie - Apap";
		}else if(wywiad[2] == 't'|| wywiad[2] == 'T'){
			diagnoza = "Stres - Melise co wieczor pic";
		}else{
			diagnoza = "Skierowanie na tomograf";
		}
	} else if(specjalnosc == "Ortopeda"){
	std::cout << "Upadek?\n";
	std::cin >> wywiad[0];
	std::cout << "Boli?\n";
	std::cin >> wywiad[1];
	std::cout << "Krwawienie?\n";
	std::cin >> wywiad[2];
		if(wywiad[0] == 't'|| wywiad[0] == 'T'){
			diagnoza = "Skrecenie - do gipsu";
		}else if(wywiad[1] == 't'|| wywiad[1] == 'T'){
			diagnoza = "Stluczenie - oklady";
		}else if(wywiad[2] == 't'|| wywiad[2] == 'T'){
			diagnoza = "Zlamanie otwarte - na SOR";
		}else{
			diagnoza = "Rentgen";
		}
	} else if( specjalnosc == "Kardiolog"){
	std::cout << "Pieczenie w klatce?\n";
	std::cin >> wywiad[0];
	std::cout << "Uklucie?\n";
	std::cin >> wywiad[1];
	std::cout << "Cisnienie?\n";
	std::cin >> wywiad[2];
		if(wywiad[0] == 't'|| wywiad[0] == 'T'){
			diagnoza = "Zawal - na oddzial";
		}else if(wywiad[1] == 't'|| wywiad[1] == 'T'){
			diagnoza = "Stres - Akard";
		}else if(wywiad[2] == 't'|| wywiad[2] == 'T'){
			diagnoza = "Za duzo kawy - nie pic";
		}else{
			diagnoza = "Badanie krwi";
		}
	}
}