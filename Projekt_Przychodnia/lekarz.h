#pragma once
#include "pacjent.h"
#include "osoba.h"
#include <vector>

class lekarz : public osoba
{
	public:
		std::vector<pacjent*> pacjenci;
		std::string diagnoza;
		lekarz(std::string imi, std::string nazwis, std::string pos, std::string spec, std::string num);
		void wyswietl_kolejke();
		void wywiad_szczegolowy();
};

