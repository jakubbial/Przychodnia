#include "pacjent.h"
#include <string>
#include <iostream>

pacjent::pacjent(std::string imi, std::string nazwis, std::string skier){
		imie = imi;
		nazwisko = nazwis;
		posada = "pacjent";
		specjalnosc = "pacjent";
		skierowanie = skier;
}

pacjent::~pacjent(){
	std::cout << "Pacjent zniszczony!\n";
}