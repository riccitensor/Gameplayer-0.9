#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <vector>

using namespace std;


bool czyBylaWylosowana(int iLiczba, vector<int> tab, int ile)
{
	if (ile <= 0)
		return false;

	int i = 0;
	do
	{
		if (tab[i] == iLiczba)
			return true;

		i++;
	} while (i < ile);

	return false;
}

int wylosuj()
{
	return(rand() % 52+2);
}

void wyswietl(bool gracz[13][4])
{
	for (int i = 0; i < 13; i++)
		for (int j = 0; j < 4; j++)
		{
			if (gracz[i][j] == true)
			{
				if (i == 0) cout << "A";
				if (i == 1) cout << "K";
				if (i == 2) cout << "Q";
				if (i == 3) cout << "J";
				if (i == 4) cout << "T";
				if (i == 5) cout << "9";
				if (i == 6) cout << "8";
				if (i == 7) cout << "7";
				if (i == 8) cout << "6";
				if (i == 9) cout << "5";
				if (i == 10) cout << "4";
				if (i == 11) cout << "3";
				if (i == 12) cout << "2";

				if (j == 0) cout << "h  ";
				if (j == 1) cout << "d  ";
				if (j == 2) cout << "c  ";
				if (j == 3) cout << "s  ";

			}
		}
}

string fig(int i)
{
	string karta;
	if (i == 0) karta = "A";
	if (i == 1) karta = "K";
	if (i == 2) karta = "Q";
	if (i == 3) karta = "J";
	if (i == 4) karta = "T";
	if (i == 5) karta = "9";
	if (i == 6) karta = "8";
	if (i == 7) karta = "7";
	if (i == 8) karta = "6";
	if (i == 9) karta = "5";
	if (i == 10) karta = "4";
	if (i == 11) karta = "3";
	if (i == 12) karta = "2";
	return karta;

}
string ranka(int i)
{
	string karta;

	if (i == 1) karta = "STRAIGHT FLUSH";
	if (i == 2) karta = "4 of KIND";
	if (i == 3) karta = "FULL HOUSE";
	if (i == 4) karta = "FLUSH";
	if (i == 5) karta = "STRAIGHT";
	if (i == 6) karta = "3 of KIND";
	if (i == 7) karta = "2 PAIR";
	if (i == 8) karta = "1 PAIR";
	if (i == 9) karta = "HIGH CARD";
	return karta;

}
string kolor(int i)
{
	string col;
	if (i == 0) col = "h";
	if (i == 1) col = "d";
	if (i == 2) col = "c";
	if (i == 3) col = "s";

	return col;

}


/*
konwertuje int karty (nasz format, tj 2 do 53) na string
*/
string convert(int seven_cards)
{
	int konwersja = 0;
	bool player[13][4];
	string pocket;


	konwersja = seven_cards;
	for (int j = 2; j < 54; j++)
		if (konwersja == (13 * (2 * (int)floor((j - 2) / 13) + 1) + 3 - j))
		{
			player[(j - 2) % 13][(int)floor((j - 2) / 13)] = true;
			pocket = fig((j - 2) % 13);
			pocket = pocket + kolor((int)floor((j - 2) / 13));
		}

	return pocket;
}

//bierze inta i wektor, i sprawdza czy nie jest w wektorze
bool isInVector(vector<int> v, int val){

	for (std::vector<int>::size_type i = 0; i != v.size(); i++) {
		if (v[i] == val) return true;
	}
	return false;
}
