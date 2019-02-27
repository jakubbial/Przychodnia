#include "przychodnia.h"
#include <iostream>
#include <string>


przychodnia::przychodnia(){
	licznik_kolejki = 0; // zmienna, ktora inkrementuje numerek kolejnego pacjenta
}

void przychodnia::rozpocznij_dzialanie(){
	int wskaznik_stanu = 0;
	char odpowiedz;
	int wybrany_lekarz;
	bool run = true;
	
	std::cout << "\n#######################################################\n\nWitamy w przychodni.";
	
	//maszyna stanow ktora odpowiada za cale menu i sekwencje wykonywania dzialan

	while(run){
			switch(wskaznik_stanu){
				case 0:
					std::cout << "\nProsze przejsc do odpowiedniego menu:\nP - Pacjent\nR - Recepconistka\nL - Lekarz\nX - Wyjscie\n";
					std::cin >> odpowiedz;
					if(odpowiedz == 'P'){
						wskaznik_stanu = 1;				//stan 1 otwiera menu pacjenta
						break;
					}else if(odpowiedz == 'R'){
						wskaznik_stanu = 2;				//stan 2 otwiera menu recepcjonistki
						break;
					}else if(odpowiedz == 'L'){
						wskaznik_stanu = 6;				//stan 6 to stan z menu lekarzy
						break;
					}else if(odpowiedz == 'X'){
						wskaznik_stanu = 99;			//stan 99 to stan zakonczenia dzialania programu
						break;
					}else{
						wskaznik_stanu = 0;				//stan 0 to stan menu glownego
						std::cout << "\nBlad wprowadzonej litery!\n";
						break;
					}
				case 1:
					std::cout << "\nMenu Pacjent.\nWybierz:\nP - Pobierz numer\nW - Wstecz\n";
					std::cin >> odpowiedz;
					if(odpowiedz == 'P'){
						wskaznik_stanu = 3;				//stan 3 pobieranie numerka pacjenta
						break;
					}else if( odpowiedz == 'W'){
						wskaznik_stanu = 0;
						break;
					}
				case 3:
					pobierz_numerek();
					wskaznik_stanu = 1; 
					break;
				case 2:
					std::cout << "\nMenu Recepcja.\nWybierz nastepujace opcje:\nK - Wyswietl kolejke pacjentow\nP - Przyjmij Kolejnego pacjenta z kolejki. (Bedzie wstepny wywiad)\nW - Wstecz\n";
					std::cin >> odpowiedz;
					if(odpowiedz == 'K'){
						wskaznik_stanu = 4;				//stan 4 to wyswietlanie kolejki pacjentow
						break;
					}else if( odpowiedz == 'P'){
						wskaznik_stanu = 5;				// stan 5 to stan ktory przyjmuje kolejnego pacjenta z kolejki i przesyla go lekarzowi
						break;
					}else if(odpowiedz == 'W'){
						wskaznik_stanu = 0;
						break;
					}
				case 4:
					recepcja.at(0).wyswietl_kolejke();
					wskaznik_stanu = 2;
					break;
				case 5:
					if(recepcja.at(0).kolejka.size() == 0){
						std::cout << "\nKolejka Pusta!\n";
					}else{
						recepcja.at(0).przyjmij_pacjenta();
						recepcja.at(0).wywiad_wstepny();
						recepcja.at(0).przydziel_pacjenta();
						przydziel_do_lekarza();
					}

					wskaznik_stanu = 2;
					break;
				case 6:
					std::cout << "\nDostepni lekarze:\n";
					wyswietl_lekarzy();
					std::cout << "\nW - Wstecz\n";
					std::cin >> odpowiedz;
					if(odpowiedz == 'W'){
						wskaznik_stanu = 0;
						break;
					} else{
						wybrany_lekarz = odpowiedz - '0';
						if(wybrany_lekarz > lekarze.size()){ 
							std::cout << "\nWybrano zle!\n";
							wskaznik_stanu = 6;
						}else{
							wskaznik_stanu = 7;
						}
						break;
					}
				case 7:
					std::cout << "\nMenu lekarza " << lekarze.at(wybrany_lekarz).imie << "a " << lekarze.at(wybrany_lekarz).nazwisko << "\nWybierz dostepne opcje:\nK - wyswietl kolejke do lekarza\nP - Przyjmij pierwszego pacjenta\nW - Wstecz\n";
					std::cin >> odpowiedz;
					if(odpowiedz == 'W'){
						wskaznik_stanu = 6;
						break;
					}else if(odpowiedz == 'K'){
						lekarze.at(wybrany_lekarz).wyswietl_kolejke();
						wskaznik_stanu = 7;
						break;
					}else if(odpowiedz == 'P'){
						if(lekarze.at(wybrany_lekarz).pacjenci.size() <= 0){
							std::cout << "Kolejka pusta!\n";
						}else{
							std::cout << "\nPrzyjeto " << lekarze.at(wybrany_lekarz).pacjenci.at(0)->imie << " " << lekarze.at(wybrany_lekarz).pacjenci.at(0)->nazwisko << "\n";
							lekarze.at(wybrany_lekarz).wywiad_szczegolowy();
							std::cout << lekarze.at(wybrany_lekarz).diagnoza;							
							lekarze.at(wybrany_lekarz).pacjenci.erase(lekarze.at(wybrany_lekarz).pacjenci.begin());
							//delete[] lekarze.at(wybrany_lekarz).pacjenci.front();
						}
						
						wskaznik_stanu = 7;
						break;
					}
					
				case 99:
					std::cout << "\nDo widzenia";
					run = false;
					//throw exception
					break;
			}

	}
	 
}




void przychodnia::wczytaj_obsade(){
	std::string andrzej[] = {"Andrzej", "Kowalski", "Lekarz", "Psychiatra", "112"};
	std::vector<std::string> andrzejek(andrzej, andrzej + sizeof(andrzej) / sizeof(andrzej[0]));
	
	std::string grazka[] = {"Grazyna", "Nowal", "Recepcjonistka", "Recepcja", "998"};
	std::vector<std::string> grazyna(grazka, grazka + sizeof(grazka) / sizeof(grazka[0]));

	std::string lucyn[] = {"Lucyna", "Kruk", "Lekarz", "Ortopeda", "1283"};
	std::vector<std::string> lucyna(lucyn, lucyn + sizeof(lucyn) / sizeof(lucyn[0]));
		
	std::string adi[] = {"Filip", "Krasny", "Lekarz", "Kardiolog", "1488"};
	std::vector<std::string> adolf(adi, adi + sizeof(adi) / sizeof(adi[0]));	
	
	obsada.push_back(andrzejek);
	obsada.push_back(grazyna);
	obsada.push_back(lucyna);
	obsada.push_back(adolf);
}

void przychodnia::laduj_obsade(){
	int ilosc_obsady = obsada.size();
	
	for(int i=0;i<ilosc_obsady;i++){
		
		std::vector<std::string> temp = obsada.at(i);
		
		if(temp.at(2) == "Lekarz"){
 			std::cout << "Zaladowalem lekarza: " << temp.at(0) << " " << temp.at(1) << "\n";
 			lekarz lek = lekarz(temp.at(0), temp.at(1),temp.at(2),temp.at(3),temp.at(4));
 			lekarze.push_back(lek);
		}else if(temp.at(2) == "Recepcjonistka"){
 			std::cout << "Zaladowalem recepcjonistke: " << temp.at(0) << " " << temp.at(1) << "\n";
 			recepcjonistka rec = recepcjonistka(temp.at(0), temp.at(1),temp.at(2),temp.at(3),temp.at(4));
 			recepcja.push_back(rec);
 		}
	}
}

void przychodnia::pobierz_numerek(){
	recepcja.at(0).kolejka.push_back(licznik_kolejki);					//odwolanie do pierwszego elementu wektora z recepcjonistkami o nazwie "recepcja" .Recepcjonistka ma kolejke i wrzucamy jeje na koniec tej kolejki nowego pacjenta
	std::cout << "\nTwoj numerek to: " << licznik_kolejki << "\n";
	licznik_kolejki++;
}

void przychodnia::przydziel_do_lekarza(){
	for(unsigned int i=0; i<lekarze.size(); i++){
		if(recepcja.at(0).przyjety_pacjent->skierowanie == lekarze.at(i).specjalnosc){
			lekarze.at(i).pacjenci.push_back(recepcja.at(0).przyjety_pacjent);  //lekarz i-ty ma wektor ze wskaznikami na pacjentow. recepcjonistka po utworzeniu nowego pacjenta przchowuje u siebie wskaznik na niego. ta linijka przepisuje wskaznik od recepcjonistki do wektora lekarza
			std::cout << "Przydzielono do lekarza!\n"; 
		}
	}
}

void przychodnia::wyswietl_lekarzy(){
	for(unsigned int i = 0; i < lekarze.size(); i++) { std::cout<< "\n" << i << " - " << lekarze.at(i).imie << " " << lekarze.at(i).nazwisko << " " << lekarze.at(i).specjalnosc;}
	}