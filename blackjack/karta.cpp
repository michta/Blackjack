
#include "stdafx.h"
#include "karta.h"
#include <iostream>
#include <time.h>
#include <string>
using namespace std;

Karta::Karta(int value, int color) :wartosc(value), kolor(color)
{
	color = rand() % 4;

	value = rand() % 13;
	kolor = color;
	this->kolor = kolor;
	wartosc = value;
	this->wartosc = wartosc;
	aktualizuj();

}
void Karta::ustawWartosc(int wartosc)
{
	if (wartosc<13)
		this->wartosc = wartosc;
	aktualizuj();	
}
void Karta::ustawKolor(int kolor)
{
	if (kolor<4)
		this->kolor = kolor;
	aktualizuj();
}

int Karta::dajWartosc()
{
	return wartosc;
}

int Karta::dajKolor()
{
	
	return kolor;
}

int Karta::wartoscOczko()
{
	return (wartosc<12) ? wartosc % 9 + 2 : 11;
}

void Karta::aktualizuj()
{	

	string figury[13] = {
		"2", "3", "4", "5", "6", "7", "8", "9", "10",
		"J", "Q", "K", "A"
	};

	char kolory[4] = {
		3, 4, 5, 6
	};
awers = figury[wartosc] + kolory[kolor];

}
