#pragma once
#include "karta.h"
#include <iostream>
class Gracz
{
protected:
	Karta *reka[10];
	int ileKart = 0;
	std::string imie;
public:
	Gracz()
	{
	}
	~Gracz();
	virtual void nowaGra() = 0;
	virtual bool czyNastepna() = 0;
	std::string dajImie();
	void dodajKarte(Karta *k);
	int policzPukty();
	void wyswietlKarty();
	void ustawImie(std::string imie = "brak");
	
};

