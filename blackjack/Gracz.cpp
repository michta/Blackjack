#include "stdafx.h"
#include "Gracz.h"
#include "karta.h"
#include "talia.h"
#include <string>
#include <string.h>
#include <iostream>
using namespace std;

void Gracz::ustawImie(string name)
{
	imie = name;
}
std::string Gracz::dajImie()
{
	return imie;
}
int Gracz::policzPukty()
{
	
	int suma = 0;
	for (int i = 0; i < ileKart; i++)
	{
		suma += reka[i]->wartoscOczko();
	}
	return suma;
}

void Gracz::wyswietlKarty()
{
	for (int i = 0; i < ileKart; i++)
	{
		cout << reka[i]->dajAwers() << " ";
	}
}

void Gracz::dodajKarte(Karta* k)
{
	reka[ileKart] = k;
	this->reka[ileKart] = reka[ileKart];
	ileKart++;
}
Gracz::~Gracz()
{
	delete[]reka;
}

