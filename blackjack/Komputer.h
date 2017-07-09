#pragma once
#include "Gracz.h"
#include "talia.h"
class Komputer: public Gracz
{
public:
	Komputer();
	int liczba;
	 bool czyNastepna();
	 void nowaGra();
	~Komputer();
};

