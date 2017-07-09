#pragma once
#ifndef KARTA_H
#define KARTA_H
#include <string>


class Karta
{
private:
	int wartosc, kolor;
	std::string awers;
public:
	Karta(int wartosc  = 0, int kolor = 0 );
	void ustawWartosc(int wartosc);
	void ustawKolor(int kolor);
	int dajWartosc();
	int dajKolor();
	inline std::string dajAwers(){ return awers;}

	int wartoscOczko();

private:
	void aktualizuj();
};

#endif // KARTA_H