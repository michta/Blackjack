#include "stdafx.h"
#include "Oczko.h"
#include "Czlowiek.h"
#include "talia.h"
#include <iomanip>
#include <iostream>
using namespace std;

Oczko::Oczko()
{
}
void Oczko::utworzGraczy()
{

	int iloscLudzi = 0;
	int iloscKomputerow = 0;
	string imie;
	int i = 0;
	cout << "Witaj w grze oczko. Zanim rozpoczniesz wybierz graczy" << endl;
	cout << "Ilu graczy (steruje czlowiek) chcesz dodac (maksymalnie 8)? ";
	cin >> iloscLudzi;
	while (!cin.good())
	{
		cout << "Podano nieprawidlowa wartosc. Wprowadz dane jeszcze raz: ";
		cin.clear();
		cin.sync();

		cin >> iloscLudzi;
	}

	if (iloscLudzi > 8)
		iloscLudzi = 8;
	for (; i < iloscLudzi; i++)
	{
		tablicaGraczy[i] = new Czlowiek;
		cout << "Podaj imie gracza numer " << i + 1 << ": ";
		cin >> imie;
		tablicaGraczy[i]->ustawImie(imie);
	}

	if (iloscLudzi < 8)
	{
		cout << "Ile komputerow (steruje S.I.) chcesz dodac (maksymalnie " << 8 - iloscLudzi << ")? ";
		cin >> iloscKomputerow;
		while (!cin.good())
		{
			cout << "Podano nieprawidlowa wartosc. Wprowadz dane jeszcze raz: ";
			cin.clear();
			cin.sync();

			cin >> iloscKomputerow;
		}

		if (iloscKomputerow + iloscLudzi>8)
			iloscKomputerow = 8 - iloscLudzi;
		for (; i < iloscKomputerow + iloscLudzi; i++)
		{
			tablicaGraczy[i] = new Komputer;
			imie = "S.I. #";
			imie.append(1, i - iloscLudzi + '1');
			tablicaGraczy[i]->ustawImie(imie);
		}
		iloscGraczy = iloscKomputerow + iloscLudzi;
	}
	system("cls");
}

void Oczko::graj()
{
	string decyzja;
	int wybor = 1, zwyciezca = 0;
	do
	{
		for (int i = 0; i < iloscGraczy; i++)
		{
			tablicaGraczy[i]->nowaGra();
		}

		talia = new Talia;
		talia->tasuj();
		for (int j = 0; j < iloscGraczy; j++)
		{
			tablicaGraczy[j]->dodajKarte(talia->dajKarte());

			cout << endl << "daj imie: " << tablicaGraczy[j]->dajImie() << endl;
			cout << "wyswietl karty: "; tablicaGraczy[j]->wyswietlKarty();
			cout << endl << "liczba punktow: " << tablicaGraczy[j]->policzPukty() << endl;

			while (tablicaGraczy[j]->czyNastepna() == true)
			{
				system("cls");
				cout << endl << "DAJ IMIE: " << tablicaGraczy[j]->dajImie() << endl;
				tablicaGraczy[j]->dodajKarte(talia->dajKarte());
				cout << "WYSWIETL KARTY: "; tablicaGraczy[j]->wyswietlKarty();
				cout << endl << "LICZBA PUNKTOW: " << tablicaGraczy[j]->policzPukty() << endl;
			}
			system("cls");
		}
		for (int k = 0; k < iloscGraczy; k++)
		{
			cout << endl << tablicaGraczy[k]->dajImie() << "  ";
			tablicaGraczy[k]->wyswietlKarty();
			cout << "  " << tablicaGraczy[k]->policzPukty() << endl;
		}
		system("cls");

		int *tab = new int[iloscGraczy];
		for (int i = 0; i < iloscGraczy; i++)
		{
			for (int j = 1; j <iloscGraczy - i; j++)
			{
				if (tablicaGraczy[j]->policzPukty() > tablicaGraczy[j - 1]->policzPukty())
				{
					swap(tablicaGraczy[j - 1], tablicaGraczy[j]);
				}
			}
			}
		cout << endl << "   TABELA WYNIKOW" << endl << endl;
		cout << "------------------------------------- " << endl;
		for (int i = 0; i < iloscGraczy; i++)
		{
			if (tablicaGraczy[i]->policzPukty() <= 21)
			{

				cout << tablicaGraczy[i]->dajImie() << endl;
				cout << "LICZBA PUNKTOW: " << tablicaGraczy[i]->policzPukty() << "   "; tablicaGraczy[i]->wyswietlKarty();
				cout << endl;
			}
		}
		cout << endl << endl << "         PRZEGRANCE!" << endl;
		cout << "------------------------------------- " << endl;
		for (int i = 0; i < iloscGraczy; i++)
		{
			if (tablicaGraczy[i]->policzPukty() >= 22)
			{
				cout << tablicaGraczy[i]->dajImie() << endl;
				cout << "LICZBA PUNKTOW: " << tablicaGraczy[i]->policzPukty() << "   "; tablicaGraczy[i]->wyswietlKarty();
				cout << endl;
			}
		}
			cout << "czy chcesz zagrac jeszcze raz? tak/nie " << endl;
			//cin >> wybor;
			cin >> decyzja;
			while (decyzja != "tak" && decyzja != "nie")
			{
				cout << "Podano nieprawidlowa wartosc. Wprowadz dane jeszcze raz: ";
				cin.clear();
				cin.sync();

				//cin >> wybor;
				cin >> decyzja;
			}
			system("cls");
		} while (decyzja == "tak");
	}



Oczko::~Oczko()
{
	delete talia;
}