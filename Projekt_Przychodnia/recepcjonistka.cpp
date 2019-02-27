#include "recepcjonistka.h"
#include "pacjent.h"
#include <iostream>

recepcjonistka::recepcjonistka(std::string imi, std::string nazwis, std::string pos, std::string spec, std::string num){
		imie = imi;
		nazwisko = nazwis;
		posada = pos;
		specjalnosc = spec;
		numer = num;
}

void recepcjonistka::przyjmij_pacjenta(){
	int ilosc = kolejka.size();
	if(ilosc == 0){
		std::cout << "\nKolejka Pusta \n";  
	} else if( ilosc >0){
		aktualny_pacjent = kolejka.at(0);
		std::cout << "\nObslugiwany pacjent to: " << aktualny_pacjent << "\n";
		kolejka.erase(kolejka.begin());
	}
}

void recepcjonistka::wyswietl_kolejke(){
	std::cout << "\nKolejka do recepcjonistki:\n";
	if(kolejka.size() == 0){
		std::cout << "Kolejka pusta\n";
	}else{
		for(unsigned int i=0; i<kolejka.size(); i++) { std::cout << kolejka.at(i) << "\n";}
	}
	
}

void recepcjonistka::wywiad_wstepny(){

	char wywiad[3];
	std::cout << "Imie\n";
	std::cin >> imie_pacjenta;
	std::cout << "Nazwisko\n";
	std::cin >> nazwisko_pacjenta;
	std::cout << "Czy boli noga?\n";
	std::cin >> wywiad[0];
	std::cout << "Czy boli glowa?\n";
	std::cin >> wywiad[1];
	std::cout << "Czy boli serce?\n";
	std::cin >> wywiad[2];
	
	if(wywiad[0] == 't'|| wywiad[0] == 'T'){
		skierowanie = "Ortopeda";
	}else if(wywiad[1] == 't'|| wywiad[1] == 'T'){
		skierowanie = "Psychiatra";
	}else if(wywiad[2] == 't'|| wywiad[2] == 'T'){
		skierowanie = "Kardiolog";
	}else{
		skierowanie = "Brak";
	}
	std::cout << skierowanie << "\n";
}

void recepcjonistka::przydziel_pacjenta(){
	przyjety_pacjent = new pacjent(imie_pacjenta, nazwisko_pacjenta, skierowanie);
}