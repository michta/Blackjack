#pragma once
#ifndef TALIA_H
#define TALIA_H
#include "karta.h"

class Talia
{
	Karta *talia;//tablica kart

	int ilosc;   //iloœæ kart w talii
	int licznik; //zmienna s³u¿¹ca do oznaczenia kart wydanych
public:
	Talia(int ilosc = 52);
	~Talia();
	void wyswietl();
	void tasuj();
	Karta *dajKarte();
public: //akcesory:
	inline int dajIlosc(){ return ilosc; }
	inline int ileZostalo(){ return ilosc - licznik; }
};

#endif // TALIA_H
