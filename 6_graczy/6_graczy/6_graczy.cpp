// Porownywanie_ukladow.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <ctime>
#include "funkcje.h"
#include <string>
#include <vector>
#include <cmath>

using namespace std;




int _tmain(int argc, _TCHAR* argv[])
{
	int sprawdz[13];
	bool gracz_a[13][4]; //gracz 2

	bool stop = 0;
	int hej = 0;
	int kicker[6] = { 0, 0, 0, 0, 0, 0 }; //kicker[0] bedzie informowal o kolorze pokera, flusha, stright flusha, wartosc 1 to h, 2 to d, 3 to c, 4 to s
											//kicker [1]...kicker [5] to wysokosc karty pierwszej, drugiej, trzeciej o ile jest kickerem, przez wysokosc rozumiem 0 to as, 1 to krol, etc

	bool rank[10];  //ranking ukladow, dla true oznacza ze w rozdaniu pojawil sie ten uklad, mozna dodac drugi wymiar ktory bedzie okreslal dla ktorego gracza padl ten uklad
	int blok[10][4];  //do dla straight flusha, sprawdzam czy karty sa po kolei, jest 10 takich blokow, np od As do T, od K do 9, ... od 8 do 4 etc
	int blok_s[10];  // to przygotowalem dla strita, ale okazalo sie ze troche trudniej
	int ranking[10]; //to licznik, ile padlo ukladow w zadanej liczbie iteracji
	int figura_a = 0;
	int figura_b = 0;
	

	int karta[17]; //losujemy karty bez powtorzen, 5 wspolnych i po 2 dla 2 graczy, lacznie 9
	int wylosowanych = 0;//sprawdzanie ile juz zostalo wylosowanych roznych kart
	int iteracja = 0;

	int suma_figura[13]; //ogolnie mamy macierz, karty od A do 2 uszeregowane kolorami, tu sprawdzam ilo zosta³o wylosowanych tych samych figur, czyli sumuje 1 z danego wiersza
	int suma_kolor[4]; //sumuje 1 z danej kolumny, jesli karta zosta³a wylosowana do w macierzy pojawia siê true, jesli nie pozostaje false

	//ponizej zerowanie zmiennych, nie pamietam czy jest lepszy sposob
	int test = 0;
	for (int i = 0; i < 10; i++) 
		{
			rank[i] = 0; ranking[i] = 0;
		}

	//G£OWNY PROGRAM !!!

		srand(time(NULL));
		do
		{
			wylosowanych = 0;
			//ponizej zerowanie zmiennych, to potem mozna wywalic, ale ze sa iteracje to musze zerowac zmienne
			for (int i = 0; i < 4; i++) suma_kolor[i] = 0;
			for (int i = 0; i < 6; i++) kicker[i] = -1;
			for (int j = 0; j < 13; j++) {
				suma_figura[j] = 0; sprawdz[j] = 0;
				
			}
			for (int i = 0; i < 10; i++)
				for (int j = 0; j < 4; j++)
				{
					blok[i][j] = 0;
					blok_s[i] = 0;
				}

			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 13; j++) gracz_a[j][i] = false;
			for (int i = 0; i < 10; i++) {
				rank[i] = 0;
			}
			stop = 0;
			// koniec zerowania zmiennych


			do//losowanie 17 kart sposrod 52
			{
				int liczba = wylosuj();
				if (czyBylaWylosowana(liczba, karta, wylosowanych) == false)
				{
					int x, y;
					karta[wylosowanych] = liczba;
					x = liczba % 13;
					y = liczba / 13;

					if (wylosowanych >= 0 && wylosowanych < 7) gracz_a[x][y] = true;


					wylosowanych++;
				} //if
			} while (wylosowanych < 17);
			// koniec losowania



			//sumowanie
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 13; j++)
					if (gracz_a[j][i] == true)
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

					if ((gracz_a[j][i] == true) && (sprawdz[j] == 0))
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
			
			
			wyswietl(gracz_a);  //WYSWIETLANIE kart gracza
			cout << "  -  ";


			//STRAIGHT FLUSH

			for (int i = 0; i < 40; i++)
			{
				if (blok[(int)floor(i / 4)][i % 4] == 5)
				{
					rank[1] = true;
					kicker[0] = (int)floor(i / 4);
					break;
				}
			}



			//KARETA
			for (int i = 0; i < 13; i++)
				if (suma_figura[i] == 4)
				{
					rank[2] = true;
					//kickery dla karety
					kicker[0] = i;//jaka kareta

					for (int a = 0; a < 52; a++)
						if ((gracz_a[(int)floor(a / 4)][a % 4] == true) && (a != kicker[0]))
						{
							kicker[1] = (int)floor(a / 4);
							break;
						}
					break;
				}

			//STRAIGHT
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

			//FLUSH
			if (rank[1] == false)
			{
				for (int i = 0; i < 4; i++)
					if (suma_kolor[i] >= 5)
					{
						rank[4] = true;
						int zlicz = 0;

						for (int a = 0; a < 13; a++)
						{

							if (gracz_a[a][i] == true)
							{
								kicker[zlicz] = a;
								zlicz++;
							}
						}
					}
			}

			//FULL HOUSE
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
			//SET

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
							if ((gracz_a[(int)floor(a / 4)][a % 4] == true) && (i != (int)floor(a / 4)))
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


			//2 PAIRS

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
									if ((gracz_a[(int)floor(a / 4)][a % 4] == true) && ((int)floor(a / 4) != i) && ((int)floor(a / 4) != j))
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

			//1 PAIR

			if ((rank[7] == false) && (rank[6] == false) && (rank[5] == false) && (rank[4] == false) && (rank[3] == false) && (rank[2] == false) && (rank[1] == false))
			{

				int zlicz = 1;
				for (int i = 0; i < 13; i++)
					if (suma_figura[i] == 2)
					{

						kicker[0] = i;
						for (int a = 0; a < 52; a++)
						{
							if ((gracz_a[(int)floor(a / 4)][a % 4] == true) && (i != (int)floor(a / 4)))
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

			//HIGH CARD
			if ((rank[1] == false) && (rank[2] == false) && (rank[3] == false) && (rank[4] == false) && (rank[5] == false) && (rank[6] == false) && (rank[7] == false) && (rank[8] == false))
			{
				int zlicz = 0;
				for (int a = 0; a < 52; a++)
				{

					if (gracz_a[(int)floor(a / 4)][a % 4] == true)
					{
						kicker[zlicz] = (int)floor(a / 4);
						zlicz++;
					}
					if (zlicz == 6) break;
				}
				rank[9] = true;
			}


			iteracja++;

			if (rank[1] == true) cout << "Straight Flush";
			if (rank[2] == true) cout << "4 of Kind";
			if (rank[3] == true) cout << "Full House";
			if (rank[4] == true) cout << "Flush";
			if (rank[5] == true) cout << "Straight";
			if (rank[6] == true) cout << "3 of Kind";
			if (rank[7] == true) cout << "2 Pair";
			if (rank[8] == true) cout << "1 Pair";
			if (rank[9] == true) cout << "High Card";
		
			cout << "  Kicker: ";
			for (int i = 0; i < 6; i++)
			{
				
				if (kicker[i] == -1);else cout << fig(kicker[i]) << "  ";
			}
			cout << endl;

			}while (iteracja<50);
			//}while (rank[1] == false);
	
	
	getchar();

}

