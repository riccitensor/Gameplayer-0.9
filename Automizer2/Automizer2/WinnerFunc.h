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
	if (i == 0) karta = "AS.";
	if (i == 1) karta = "KROL.";
	if (i == 2) karta = "DAMA.";
	if (i == 3) karta = "WALET.";
	if (i == 4) karta = "DZIESIEC.";
	if (i == 5) karta = "DZIEWIEC.";
	if (i == 6) karta = "OSIEM.";
	if (i == 7) karta = "SIEDEM.";
	if (i == 8) karta = "SZESC.";
	if (i == 9) karta = "PIEC.";
	if (i == 10) karta = "CZTERY.";
	if (i == 11) karta = "TRZY.";
	if (i == 12) karta = "DWA.";
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
	if (i == 0) col = "HEARTS.";
	if (i == 1) col = "DIAMOND.";
	if (i == 2) col = "CLUBS.";
	if (i == 3) col = "SPADES.";

	return col;

}
string show(bool a[13][4])
{
	string hand;
	string karta;
	string kolor;
	for (int i = 0; i < 13; i++)
		for (int j = 0; j < 4;j++)
			if (a[i][j] == true)
			{
				if (i == 0) karta = "AS.";
				if (i == 1) karta = "KROL.";
				if (i == 2) karta = "DAMA.";
				if (i == 3) karta = "WALET.";
				if (i == 4) karta = "DZIESIEC.";
				if (i == 5) karta = "DZIEWIEC.";
				if (i == 6) karta = "OSIEM.";
				if (i == 7) karta = "SIEDEM.";
				if (i == 8) karta = "SZESC.";
				if (i == 9) karta = "PIEC.";
				if (i == 10) karta = "CZTERY.";
				if (i == 11) karta = "TRZY.";
				if (i == 12) karta = "DWA.";
				if (j == 0) kolor = "HEARTS.";
				if (j== 1) kolor = "DIAMOND.";
				if (j == 2) kolor = "CLUBS.";
				if (j == 3) kolor = "SPADES.";
			}
	hand = karta + kolor;
	return hand;
}