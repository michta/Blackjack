#include "stdafx.h"
#include "Czlowiek.h"
#include <iostream>
#include <string>
using namespace std;

Czlowiek::Czlowiek()
{
}
void Czlowiek::nowaGra()
{
	for (int i = 0; i < 10; i++)
	{
		reka[i] = 0;
	}
	ileKart = 0;
}
bool Czlowiek::czyNastepna()
{
	string decyzja;
	cout << "czy chcesz nastepna karte? (t/n)" << endl;
	cin >> decyzja;
	while (decyzja != "t" && decyzja != "n")
	{
		cout << "Niewlasciwa komenda. Wprowadz ponownie: t/n ";
		cin.clear();
		cin.sync();
		cin >> decyzja;
	}
	if (decyzja == "t") return true;
	else return false;
}
Czlowiek::~Czlowiek()
{
}
