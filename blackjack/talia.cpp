#include "stdafx.h"
#include "talia.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

Talia::Talia(int ilosc) :talia(NULL), ilosc(ilosc), licznik(0)
{
	talia = new Karta[ilosc];
	int p = ilosc / 4;
	int k = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < p; j++)
		{
			talia[k].ustawWartosc(j);
			talia[k].ustawKolor(i);
			k++;
			//  talia[i*p + j].ustawWartosc(12 - j);
			//	talia[i*p + j].ustawKolor(i);
		}
}

Talia::~Talia()
{
	if (talia) // if(talia!=NULL)
		delete[]talia;
}

void Talia::wyswietl()
{
	for (int i = 0; i<ilosc; i++)
		cout << talia[i].dajAwers() << endl;
}

void Talia::tasuj()
{
	srand(time(NULL));
	for (int i = 0; i<ilosc; i++)
	{
		int x = rand() % ilosc, y = rand() % ilosc;
		Karta k = talia[x];
		talia[x] = talia[y];
		talia[y] = k;
	}
}
Karta *Talia::dajKarte()
{
	Karta *k; 
	k=&talia[licznik];
	licznik++;
	return k;
//	return &talia[licznik++];
}

