#include "stdafx.h"
#include "Komputer.h"
#include "Oczko.h"
#include <iostream>
#include <string>
using namespace std;

Komputer::Komputer()
{
}
void Komputer::nowaGra()
{
	for (int i = 0; i < 10; i++)
	{
		reka[i] = 0;
	}
	ileKart = 0;
}
bool Komputer::czyNastepna()
{
	if (policzPukty() < 16)
		return true;
	else return false;
}
Komputer::~Komputer()
{
}
