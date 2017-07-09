#include "stdafx.h"
#include <iostream>
#include "karta.h"
#include "talia.h"
#include "Gracz.h"
#include "Oczko.h"a
#include "Komputer.h"
using namespace std;

int main()
{
	Oczko o;
	o.utworzGraczy();
	o.graj();

	system("pause");
	return 0;
}
