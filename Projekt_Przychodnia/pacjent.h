#pragma once
#include "osoba.h"

class pacjent
	:public osoba
{
	public:
		pacjent(std::string imi, std::string nazwis, std::string skier);
		~pacjent();
		std::string skierowanie;
	
};

