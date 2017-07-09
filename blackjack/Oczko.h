#pragma once
#include "Gracz.h"
#include "talia.h"
#include "Komputer.h"
#include <iostream>
using namespace std;
class Oczko
{
private:
	Gracz *tablicaGraczy[8];
	int iloscGraczy;
	Talia *talia;

public:
	Oczko(); 
	void utworzGraczy();
	void graj();
	~Oczko();
};


