// Porownywanie_ukladow.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <ctime>
#include "WinnerFunc.h"
#include <string>
#include <cmath>
#include <vector>

using namespace std;



/*
LOSUJE 17 ROZNYCH KART Z 50 KART, MUSI WIEDZIEC TYLKO O MOJEJ RECE
*/
vector<int> drawAllCards(
	/*
	Moja reka jako integer
	*/
	int myHand1,
	int myHand2
	
){

		
	vector<int> karta;
	int wylosowanych = 0;
	do//losowanie 17 kart sposrod 52-----------------------------------------POWINNO BYC 52 MINUS 2 KARTY NASZE!!!!!!!!!!!!
	{
		int liczba = wylosuj();
		if (czyBylaWylosowana(liczba, karta, wylosowanych) == false)
		{

			karta.push_back(liczba);
			//cout << karta[wylosowanych] << endl;

			wylosowanych++;
		} //if
	} while (wylosowanych < 17);

	
	return karta;
}

/*
Pobiera wektor 17tu kart, robi 6 wektorow po 7kart dla graczy
*/
/*
vector<vector<int>> cardBuckets(vector<int> tab){
	
	vector<int> board;

	vector<int> player1;
	vector<int> player2;
	vector<int> player3;

	vector<int> player4;
	vector<int> player5;
	vector<int> player6;

	vector<vector<int>> ret;

	for (int i = 0; i < 5; i++) {
		board[i] = tab[i];
	}


	//P1
	for (int  i = 5; i < 7; i++) {
		player1[i] = tab[i];
	}
	for (int  i = 0; i < 5; i++) {
		player1.push_back(board[i]);
	}
	
	//P2
	for (int i = 7; i < 9; i++) {
		player2[i] = tab[i];
	}
	for (int i = 0; i < 5; i++) {
		player2.push_back(board[i]);
	}

	for (int i = 5; i < 7; i++) {
		cout << player2[i];
	}

	//P3
	for (int i = 9; i < 11; i++) {
		player3[i] = tab[i];
	}
	for (int i = 0; i < 5; i++) {
		player3.push_back(board[i]);
	}

	//P4
	for (int i = 11; i < 13; i++) {
		player4[i] = tab[i];
	}
	for (int i = 0; i < 5; i++) {
		player4.push_back(board[i]);
	}

	//P5
	for (int i = 13; i < 15; i++) {
		player5[i] = tab[i];
	}
	for (int i = 0; i < 5; i++) {
		player5.push_back(board[i]);
	}

	//P6
	for (int i = 15; i < 17; i++) {
		player6[i] = tab[i];
	}
	for (int i = 0; i < 5; i++) {
		player6.push_back(board[i]);
	}

	//ret.push_back(board);

	ret.push_back(player1);
	ret.push_back(player2);
	ret.push_back(player3);

	ret.push_back(player4);
	ret.push_back(player5);
	ret.push_back(player6);

	return ret;
}
*/


vector<int> whatHand(

	int seven_cards[7]

	/*

	kazdy gracz ma reke, losowane bez powtorzen, konwertowane na matrix Slawka
	W TABLICY JEST SIEDEM KART GRACZA = 2 UNIKALNE JEGO i PIEC
	dla gracza matrixa losujemy 5 kart z boardu bo na poaczatku jego tablica bedzie miala tylko dwa TRUE!!!!!!!!!!!!!!!!!!!!!!!
	TA FUNKCJA DA SIE WYWOLAC 6 RAZY ALE TRZEBA PAMIETAC CO WYLOSOWAISMY DLA POPRZEDNIKOW RANGOW
	TRZEBA PAMIETAC ZE PRZY LOSOWANIU ZAWSZE TRZEBA MOC WYLOSOWAC RECE
	P1 10%
	P2 20%
	P3 30%
	P4 40%
	P5 50%
	P6 60%


	*/
	){




	/*cout << "WEW FUNKCJI" << endl;
	for (int i = 0; i < 13; i++){
		for (int j = 0; j < 4; j++){
			if (player[i][j] == true){
				cout << "(" << i << "," << j << ")";
			}


		}
	}*/

	//kicker[0] bedzie informowal o kolorze pokera, flusha, stright flusha, wartosc 1 to h, 2 to d, 3 to c, 4 to s
	//kicker [1]...kicker [5] to wysokosc karty pierwszej, drugiej, trzeciej o ile jest kickerem, przez wysokosc rozumiem 0 to as, 1 to krol, etc

	int kicker[6] = { 0, 0, 0, 0, 0, 0 };
	bool player[13][4];
	int sprawdz[13];
	bool stop;
	int konwersja = 0;
	bool rank[10];  //ranking ukladow, dla true oznacza ze w rozdaniu pojawil sie ten uklad, mozna dodac drugi wymiar ktory bedzie okreslal dla ktorego gracza padl ten uklad
	int blok[10][4];  //do dla straight flusha, sprawdzam czy karty sa po kolei, jest 10 takich blokow, np od As do T, od K do 9, ... od 8 do 4 etc
	int blok_s[10];  // to przygotowalem dla strita, ale okazalo sie ze troche trudniej


	int suma_figura[13]; //ogolnie mamy macierz, karty od A do 2 uszeregowane kolorami, tu sprawdzam ilo zosta³o wylosowanych tych samych figur, czyli sumuje 1 z danego wiersza
	int suma_kolor[4]; //sumuje 1 z danej kolumny, jesli karta zosta³a wylosowana do w macierzy pojawia siê true, jesli nie pozostaje false


	int test = 0;
	for (int i = 0; i < 10; i++)
	{
		rank[i] = 0; 
	}

	//G£OWNY PROGRAM !!!


	//ponizej zerowanie zmiennych, to potem mozna wywalic, ale ze sa iteracje to musze zerowac zmienne
	for (int i = 0; i < 4; i++) suma_kolor[i] = 0;
	for (int i = 0; i < 6; i++) kicker[i] = -1;
	for (int i = 0; i < 13; i++)
	{
		suma_figura[i] = 0; 
		sprawdz[i] = 0;
		for (int j = 0; j < 4; j++)
		{
			player[i][j] = false;

		}
	}


	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 4; j++)
		{
			blok[i][j] = 0;
			blok_s[i] = 0;
		}


	for (int i = 0; i < 10; i++) {
		rank[i] = 0;
	}
	stop = false;
	
	// koniec zerowania zmiennych

	for (int i = 0; i < 7; i++)
	{
		konwersja = seven_cards[i];
		for (int j = 2; j<54; j++)
			if (konwersja == (13 * (2 * (int)floor((j - 2) / 13) + 1) + 3 - j)) player[(j - 2) % 13][(int)floor((j - 2) / 13)] = true;
	}



	//sumowanie
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 13; j++)
			if (player[j][i] == true)
			{
				suma_kolor[i]++;//sumuje ile kart jest w danych kolorze
				suma_figura[j]++;//sumuje jaka jest liczba danej figury
				if (j >= 0 && j < 5) blok[0][i]++;//tworze bloki dla STRAIGHT FLUSHA, jesli wartosc bloku rowna siê 5 tzn ze jest zapelniony caly blok, czyli karty sa po kolei
				if (j >= 1 && j < 6) blok[1][i]++;
				if (j >= 2 && j < 7) blok[2][i]++;
				if (j >= 3 && j < 8) blok[3][i]++;
				if (j >= 4 && j < 9) blok[4][i]++;
				if (j >= 5 && j < 10) blok[5][i]++;
				if (j >= 6 && j < 11) blok[6][i]++;
				if (j >= 7 && j < 12) blok[7][i]++;
				if (j >= 8 && j < 13) blok[8][i]++;
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
				//kickery dla karety
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
						}
					}
				}
		}

		//FULL HOUSE---------------------------------------------------
		if (rank[2] == false)
		{
			for (int i = 0; i < 13; i++)
			{
				if (suma_figura[i] == 3)
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
				if (zlicz == 6) break;
			}
			rank[9] = true;
		}

			//	zapisanie rankingow i kickerow do wektora
			int r = 0;

			for (int i = 1; i < 10; i++){
				if (rank[i] == true) {

					r = i;
				}
			}

			for (int i = 0; i < 6; i++){

			}

			vector<int> ret;
			ret.push_back(r);
			for (int i = 0; i < 6; i++){
				ret.push_back(kicker[i]);
			}

			wyswietl(player);

	return ret;
}

int whoWins(
	vector<int> p1,
	vector<int> p2,
	vector<int> p3,
	vector<int> p4,
	vector<int> p5,
	vector<int> p6
	){
	int min = 0;
	int value_hand[6] = { 0, 0, 0, 0, 0, 0 };

	for (int i = 0; i < 6; i++)
		if (p1[i] >= 0) value_hand[0] = p1[i] * pow(10,5-i);
	for (int i = 0; i < 6; i++)
		if (p2[i] >= 0) value_hand[1] = p2[i] * pow(10, 5 - i);
	for (int i = 0; i < 6; i++)
		if (p3[i] >= 0) value_hand[2] = p3[i] * pow(10, 5 - i);
	for (int i = 0; i < 6; i++)
		if (p4[i] >= 0) value_hand[3] = p4[i] * pow(10, 5 - i);
	for (int i = 0; i < 6; i++)
		if (p5[i] >= 0) value_hand[4] = p5[i] * pow(10, 5 - i);
	for (int i = 0; i < 6; i++)
		if (p6[i] >= 0) value_hand[5] = p6[i] * pow(10, 5 - i);

	min = value_hand[0];
	for (int i = 1; i<6; i++) //
		if (min>value_hand[i])
			min = i;
	//podaje numer gracza przy stole ktory wygral rozdanie
	return min;


}