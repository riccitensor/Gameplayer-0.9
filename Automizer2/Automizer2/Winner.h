#ifndef WIN
#define	WIN
#endif

#include <iostream>
#include <ctime>
#include "WinnerFunc.h"
#include <string>
#include <cmath>
#include <vector>

using namespace std;





vector<int> whatHand(vector<int> seven_cards)  //do funkcji podajemy 2 karty gracza i board
{

	short kicker[5] = { -1, -1, -1, -1, -1 };
	bool player[13][4];
	
	bool stop;
	int konwersja = 0;
	bool rank[10];  //ranking ukladow, dla true oznacza ze w rozdaniu pojawil sie ten uklad, mozna dodac drugi wymiar ktory bedzie okreslal dla ktorego gracza padl ten uklad
	int blok[10][4];  //do dla straight flusha, sprawdzam czy karty sa po kolei, jest 10 takich blokow, np od As do T, od K do 9, ... od 8 do 4 etc
	int blok_s[10];  // to przygotowalem dla strita, ale okazalo sie ze troche trudniej


	short suma_figura[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0 }; //ogolnie mamy macierz, karty od A do 2 uszeregowane kolorami, tu sprawdzam ilo zosta³o wylosowanych tych samych figur, czyli sumuje 1 z danego wiersza
	short sprawdz[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	short suma_kolor[4] = { 0, 0, 0, 0 }; //sumuje 1 z danej kolumny, jesli karta zosta³a wylosowana do w macierzy pojawia siê true, jesli nie pozostaje false

	//G£OWNY PROGRAM !!!


	//ponizej zerowanie zmiennych, to potem mozna wywalic, ale ze sa iteracje to musze zerowac zmienne
	for (int i = 0; i < 13; i++)
			for (int j = 0; j < 4; j++)
					player[i][j] = false;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			blok[i][j] = 0;
			blok_s[i] = 0;
		}
		rank[i] = false;
	}

	stop = false;
	
	// koniec zerowania zmiennych

	for (int i = 0; i < 7; i++)
	{
		konwersja = seven_cards[i];
		for (int j = 2; j<54; j++)
			if (konwersja == (13 * (2 * (int)floor((j - 2) / 13) + 1) + 3 - j)) player[(j - 2) % 13][(int)floor((j - 2) / 13)] = true;
	}


	//sumowanie dla straifght flush
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
			if (player[j][i] == true)
			{
				suma_kolor[i]++;//sumuje ile kart jest w danych kolorze
				suma_figura[j]++;//sumuje jaka jest liczba danej figury
				for (int k = 0; k < 9; k++) if ((j >= k) && (j < 5 + k)) blok[k][i]++;//tworze bloki dla STRAIGHT FLUSHA, jesli wartosc bloku rowna siê 5 tzn ze jest zapelniony caly blok, czyli karty sa po kolei
				if ((j >= 9 && j < 13) || (j == 0)) blok[9][i]++;
			}

	//sumowanie dla strita
	for (int j = 0; j < 13; j++)
		for (int i = 0; i < 4; i++)
		{

			if ((player[j][i] == true) && (sprawdz[j] == 0))
			{
				if (j == 0) { blok_s[0]++; blok_s[9]++; sprawdz[j]++; }
				if (j == 1) { blok_s[0]++; blok_s[1]++; sprawdz[j]++; }
				if (j == 2) { blok_s[0]++; blok_s[1]++; blok_s[2]++; sprawdz[j]++; }
				if (j == 3) { blok_s[0]++; blok_s[1]++; blok_s[2]++; blok_s[3]++; sprawdz[j]++; }
				if (j == 4) { blok_s[0]++; blok_s[1]++; blok_s[2]++; blok_s[3]++; blok_s[4]++; sprawdz[j]++; }
				if (j == 5) { blok_s[1]++; blok_s[2]++; blok_s[3]++; blok_s[4]++; blok_s[5]++; sprawdz[j]++; }
				if (j == 6) { blok_s[2]++; blok_s[3]++; blok_s[4]++; blok_s[5]++; blok_s[6]++; sprawdz[j]++; }
				if (j == 7) { blok_s[3]++; blok_s[4]++; blok_s[5]++; blok_s[6]++; blok_s[7]++; sprawdz[j]++; }
				if (j == 8) { blok_s[4]++; blok_s[5]++; blok_s[6]++; blok_s[7]++; blok_s[8]++; sprawdz[j]++; }
				if (j == 9) { blok_s[5]++; blok_s[6]++; blok_s[7]++; blok_s[8]++; blok_s[9]++; sprawdz[j]++; }
				if (j == 10) { blok_s[6]++; blok_s[7]++; blok_s[8]++; blok_s[9]++; sprawdz[j]++; }
				if (j == 11) { blok_s[7]++; blok_s[8]++; blok_s[9]++; sprawdz[j]++; }
				if (j == 12) { blok_s[8]++; blok_s[9]++; sprawdz[j]++; }
			}
		}

		//STRAIGHT FLUSH---------------------------------------------------
		for (int i = 0; i < 40; i++)
		{
			if (blok[(int)floor(i / 4)][i % 4] == 5)
			{
				rank[1] = true;
				kicker[0] = (int)floor(i / 4);
				break;
			}
		}

		//KARETA---------------------------------------------------
		for (int i = 0; i < 13; i++)
			if (suma_figura[i] == 4)
			{
				rank[2] = true;
				kicker[0] = i;//jaka kareta

				for (int a = 0; a < 52; a++)
					if ((player[(int)floor(a / 4)][a % 4] == true) && (a != kicker[0]))
					{
						kicker[1] = (int)floor(a / 4);
						break;
					}
				break;
			}

		//STRAIGHT---------------------------------------------------
		if ((suma_kolor[0] < 5) && (suma_kolor[1] < 5) && (suma_kolor[2] < 5) && (suma_kolor[3] < 5))
		{
			for (int i = 0; i < 10; i++)

				if (blok_s[i] == 5)
				{
					kicker[0] = i;
					rank[5] = true;
					break;
				}
		}

		//FLUSH---------------------------------------------------
		if (rank[1] == false)
		{
			for (int i = 0; i < 4; i++)
				if (suma_kolor[i] >= 5)
				{
					rank[4] = true;
					int zlicz = 0;

					for (int a = 0; a < 13; a++)
					{

						if (player[a][i] == true)
						{
							kicker[zlicz] = a;
							zlicz++;
							if (zlicz == 5) break;
						}
					}
				}
		}

		//FULL HOUSE---------------------------------------------------
		if ((rank[2] == false) && (rank[1] == false))
		{
			for (int i = 0; i < 13; i++)
			{
				if (suma_figura[i] == 3)
				{

					for (int j = 0; j < 13; j++)
						if ((j != i) && (suma_figura[j] >= 2))
						{
							rank[3] = true;
							kicker[0] = i;
							kicker[1] = j;
							break;
						}
					break;
				}
				
			}
		}

		//SET---------------------------------------------------
		if ((rank[5] == false) && (rank[4] == false) && (rank[3] == false) && (rank[2] == false) && (rank[1] == false))
		{
			int zlicz = 1;
			for (int i = 0; i < 13; i++)
			{
				if (suma_figura[i] == 3)
				{

					kicker[0] = i;
					for (int a = 0; a < 52; a++)
					{
						if ((player[(int)floor(a / 4)][a % 4] == true) && (i != (int)floor(a / 4)))
						{
							kicker[zlicz] = (int)floor(a / 4);
							zlicz++;
						}
						if (zlicz == 3) break;
					}
					rank[6] = true;
					break;
				}
			}
		}


		//2 PAIRS---------------------------------------------------
		if ((rank[6] == false) && (rank[5] == false) && (rank[4] == false) && (rank[3] == false) && (rank[2] == false) && (rank[1] == false) && (rank[2] == false))
		{
			for (int i = 0; i < 13; i++)
				if (suma_figura[i] == 2)
				{
					for (int j = 0; j < 13; j++)
						if ((j != i) && (suma_figura[j] == 2))
						{
							rank[7] = true;
							kicker[0] = i;
							kicker[1] = j;
							for (int a = 0; a < 52; a++)
							{
								if ((player[(int)floor(a / 4)][a % 4] == true) && ((int)floor(a / 4) != i) && ((int)floor(a / 4) != j))
								{
									kicker[2] = (int)floor(a / 4);
									break;
								}
							}
							break;
						}
					break;
				}

		}//end 2 pairs

		//1 PAIR---------------------------------------------------
		if ((rank[7] == false) && (rank[6] == false) && (rank[5] == false) && (rank[4] == false) && (rank[3] == false) && (rank[2] == false) && (rank[1] == false))
		{

			int zlicz = 1;
			for (int i = 0; i < 13; i++)
				if (suma_figura[i] == 2)
				{

					kicker[0] = i;
					for (int a = 0; a < 52; a++)
					{
						if ((player[(int)floor(a / 4)][a % 4] == true) && (i != (int)floor(a / 4)))
						{
							kicker[zlicz] = (int)floor(a / 4);
							zlicz++;
						}

						if (zlicz == 4) break;
					}
					rank[8] = true;
					break;
				}
		}

		//HIGH CARD---------------------------------------------------
		if ((rank[1] == false) && (rank[2] == false) && (rank[3] == false) && (rank[4] == false) && (rank[5] == false) && (rank[6] == false) && (rank[7] == false) && (rank[8] == false))
		{
			int zlicz = 0;
			for (int a = 0; a < 52; a++)
			{

				if (player[(int)floor(a / 4)][a % 4] == true)
				{
					kicker[zlicz] = (int)floor(a / 4);
					zlicz++;
				}
				if (zlicz == 5) break;
			}
			rank[9] = true;
		}

			//	zapisanie rankingow i kickerow do wektora
			int r = 0;

			for (int i = 1; i < 10; i++)
				{
					if (rank[i] == true) 
					{

						r = i;
					}
				}

	

			vector<int> ret;
			ret.push_back(r);
			for (int i = 0; i < 6; i++){
				ret.push_back(kicker[i]);
			}

			//cout << "Player:\t";
			//wyswietl(player); //wyswietla rece gracza w postaci np "Ad"
			//for (int i = 1; i < 10; i++) if (rank[i] == true) cout << ranka(i) << " ";
			//for (int i = 0; i < 5; i++) if (kicker[i] >-1) cout << fig(kicker[i]) << " ";
			//cout << endl;

	return ret;
}

int whoWins(vector<int> p1, vector<int> p2, vector<int> p3, vector<int> p4, vector<int> p5, vector<int> p6)
{
	int min = 0;
	int value_hand[6] = { 0, 0, 0, 0, 0, 0 };

	for (int i = 0; i < 6; i++)
		if (p1[i] >= 0) {value_hand[0] = value_hand[0]+ p1[i] * (int)pow(10, 5 - i);}
	for (int i = 0; i < 6; i++)
		if (p2[i] >= 0) value_hand[1] = value_hand[1]+p2[i] * (int)pow(10, 5 - i);
	for (int i = 0; i < 6; i++)
		if (p3[i] >= 0) value_hand[2] = value_hand[2]+p3[i] * (int)pow(10, 5 - i);
	for (int i = 0; i < 6; i++)
		if (p4[i] >= 0) value_hand[3] = value_hand[3]+ p4[i] * (int)pow(10, 5 - i);
	for (int i = 0; i < 6; i++)
		if (p5[i] >= 0) value_hand[4] = value_hand[4]+ p5[i] * (int)pow(10, 5 - i);
	for (int i = 0; i < 6; i++)
		if (p6[i] >= 0) value_hand[5] = value_hand[5] +p6[i] * (int)pow(10, 5 - i);

	int win = 0;
	min = value_hand[0];
	for (int i = 1; i<6; i++) //
		if (min >= value_hand[i])
		{
			min = value_hand[i];
			win = i;
		}
	//podaje numer gracza przy stole ktory wygral rozdanie
	return win;
}