#pragma once
#include "Gracz.h"
#include <iostream>
class Czlowiek:public Gracz
{
private:
	bool koniec;

public:
	Czlowiek();
	bool czyNastepna();
	void nowaGra();
	~Czlowiek();
};

