// Porownywanie_ukladow.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <ctime>
#include "funkcje.h"
#include <string>

using namespace std;




int _tmain(int argc, _TCHAR* argv[])
{
	int sprawdz[13];
	bool gracz_a[13][4]; //gracz 1; 0 - AS, 1 - KROL, 2 - DAMA .... 12 - Dwójka; druga wspolrzeda to 4 kolory, hearts, clubs, spades, diamonds
	bool gracz_b[13][4]; //gracz 2
	bool gracz_c[13][4]; //gracz 3
	bool gracz_d[13][4]; //gracz 4
	bool gracz_e[13][4]; //gracz 5
	bool gracz_f[13][4]; //gracz 6
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
					if ((wylosowanych >= 0 && wylosowanych < 5) || (wylosowanych >= 7 && wylosowanych <= 8)) gracz_b[x][y] = true;
					if ((wylosowanych >= 0 && wylosowanych < 5) || (wylosowanych >= 9 && wylosowanych <= 10)) gracz_c[x][y] = true;
					if ((wylosowanych >= 0 && wylosowanych < 5) || (wylosowanych >= 11 && wylosowanych <= 12)) gracz_d[x][y] = true;
					if ((wylosowanych >= 0 && wylosowanych < 5) || (wylosowanych >= 13 && wylosowanych <= 14)) gracz_e[x][y] = true;
					if ((wylosowanych >= 0 && wylosowanych < 5) || (wylosowanych >= 15 && wylosowanych <= 16)) gracz_f[x][y] = true;

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


			// TUTAJ JUZ ROZPOZNAWANIE UKLADOW, mysle ze dosc czytelne
			//ROYAL POKER
			if ((suma_kolor[0] >= 5) && (gracz_a[0][0] == true) && (gracz_a[1][0] == true) && (gracz_a[2][0] == true) && (gracz_a[3][0] == true) && (gracz_a[4][0] == true)) {
				cout << "GRACZ A posiada=ROYAL POKER! koloru " << kolor(0) << endl;
				rank[0] = true; kicker[0] = 1;
			}
			if ((suma_kolor[1] >= 5) && (gracz_a[0][1] == true) && (gracz_a[1][1] == true) && (gracz_a[2][1] == true) && (gracz_a[3][1] == true) && (gracz_a[4][1] == true)) {
				cout << "GRACZ A posiada=ROYAL POKER! koloru " << kolor(1) << endl;
				rank[0] = true; kicker[0] = 2;
			}
			if ((suma_kolor[2] >= 5) && (gracz_a[0][2] == true) && (gracz_a[1][2] == true) && (gracz_a[2][2] == true) && (gracz_a[3][2] == true) && (gracz_a[4][2] == true)) {
				cout << "GRACZ A posiada=ROYAL POKER! koloru " << kolor(2) << endl;
				rank[0] = true; kicker[0] = 3;
			}
			if ((suma_kolor[3] >= 5) && (gracz_a[0][3] == true) && (gracz_a[1][3] == true) && (gracz_a[2][3] == true) && (gracz_a[3][3] == true) && (gracz_a[4][3] == true)) {
				cout << "GRACZ A posiada=ROYAL POKER! koloru " << kolor(3) << endl;
				rank[0] = true; kicker[0] = 4;
			}


			//STRAIGHT FLUSH
			if (rank[0] == false)
			{
				for (int i = 0; i < 10; i++)
					for (int j = 0; j < 4; j++)
					{
						if (blok[i][j] == 5)
						{
						
							cout << "GRACZ A posiada=STRAIGHT FLUSH! " << fig(i) << "Kolor to " << kolor(j) << endl;
							rank[1] = true;
							stop = 1;
							break;
						}
						if (stop == 1) break;
					}
			}

			//KARETA
			stop = 0;
			for (int i = 0; i < 13; i++)
				if (suma_figura[i] == 4)
				{

					rank[2] = true;

					//kickery dla karety
					kicker[1] = i;//jaka kareta
				

					for (int a = 0; a < 13; a++)
					{
						if (stop == 1) break;
						for (int b = 0; b < 4; b++)
						{
							if ((gracz_a[a][b] == true) && (a != kicker[1]))
							{
								stop = 1;
								kicker[2] = a;
							}
							if (stop == 1) break;
						}
						
						
					}
					cout << "GRACZ A posiada=4 of KIND! " << fig(kicker[1]) << "Kickery to: " << fig(kicker[2]) << endl;
				}
			
			//STRAIGHT
			if ((suma_kolor[0] < 5) && (suma_kolor[1] < 5) && (suma_kolor[2] < 5) && (suma_kolor[3] < 5))
			{
				for (int i = 0; i < 10; i++)

					if (blok_s[i] == 5)
					{
						cout << "GRACZ A posiada=STRAIGHT! " << fig(i) << endl;
						rank[5] = true; break;
					}
			
			}

			//FLUSH
			if (rank[0] == false && rank[1] == false)
				for (int i = 0; i < 4; i++)
					if (suma_kolor[i] >= 5)
					{
						int zlicz = 1;
						cout << "GRACZ A posiada=FLUSH! " << "Kickery to: ";
						rank[4] = true;

						for (int a = 0; a < 13; a++)
						{

							if (gracz_a[a][i] == true)
							{
								kicker[zlicz] = a;
								zlicz++;
							}
						}
						cout << fig(kicker[1]) << " " << fig(kicker[2]) << " " << fig(kicker[3]) << " " << fig(kicker[4]) << " " << fig(kicker[5]) << endl;

					}



			//FULL HOUSE
			if (rank[2] == false)
			{
				int check = 0;
				for (int i = 0; i < 13; i++)
				{
					if (suma_figura[i] == 3)
						for (int j = 0; j < 13; j++)
							if ((j != i) && (suma_figura[j] >= 2))
							{
								cout << "GRACZ A posiada=FULL HOUSE! " << fig(i) << " na " << fig(j) << endl;
								rank[3] = true;
								check = 1;
								break;
							}
					if (check == 1) break;
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

						for (int a = 0; a < 13; a++)
						{
							for (int b = 0; b < 4; b++)
							{

								if ((gracz_a[a][b] == true) && (i != a))
								{
									kicker[zlicz] = a;
									zlicz++;
								}
							}
							if (zlicz == 3) break;
						}

						rank[6] = true;
						cout << "GRACZ A posiada=3 of KIND! " << fig(i);
						cout << "Kickery to: " << fig(kicker[1]) << " " << fig(kicker[2]) << endl;
						break;
					}
				}
			}


			//2 PAIRS
			stop = 0;
			if ((rank[6] == false) && (rank[5] == false) && (rank[4] == false) && (rank[3] == false) && (rank[0] == false) && (rank[1] == false) && (rank[2] == false))
			{
				for (int i = 0; i < 13; i++)
					if (suma_figura[i] == 2)
					{
						for (int j = 0; j < 13; j++)
							if ((j != i) && (suma_figura[j] == 2))
							{
								cout << "GRACZ A posiada=2 PAIR! " << fig(i) << " i " << fig(j);
								rank[7] = true;


								for (int a = 0; a < 13; a++)
								{
									for (int b = 0; b < 4; b++)
									{
										if ((gracz_a[a][b] == true) && (a != i) && (a != j))
										{
											stop = 1;
											break;
										}
										kicker[1] = a;
									}
									if (stop == 1) break;
								}
								cout << "Kickery to: " << fig(kicker[1]) << endl;
								break;
							}

						break;
					}

			}//end 2 pairs

			//1 PAIR

			if ((rank[7] == false) && (rank[6] == false) && (rank[5] == false) && (rank[4] == false) && (rank[0] == false) && (rank[1] == false) && (rank[2] == false) && (rank[3] == false))
			{
				int zlicz = 1;
				for (int i = 0; i < 13; i++)
					if (suma_figura[i] == 2)
					{
						for (int a = 0; a < 13; a++)
						{
							for (int b = 0; b < 4; b++)
							{

								if ((gracz_a[a][b] == true) && (i != a))
								{
									kicker[zlicz] = a;
									zlicz++;
								}
							}
							if (zlicz == 4) break;
						}
						cout << "GRACZ A posiada=1 PAIR! " << fig(i) << "Kickery to: " << fig(kicker[1]) << " " << fig(kicker[2]) << " " << fig(kicker[3]) << endl;
						rank[8] = true;
					}
			}

			//HIGH CARD
			if ((rank[0] == false) && (rank[1] == false) && (rank[2] == false) && (rank[3] == false) && (rank[4] == false) && (rank[5] == false) && (rank[6] == false) && (rank[7] == false) && (rank[8] == false))
			{
				int zlicz = 1;
				for (int a = 0; a < 13; a++)
				{
					for (int b = 0; b < 4; b++)
					{

						if (gracz_a[a][b] == true)
						{
							kicker[zlicz] = a;
							zlicz++;
						}
					}
					if (zlicz == 6) break;
				}
				cout << "GRACZ A posiada=HIGH CARD! Kickery to:" << fig(kicker[1]) << " " << fig(kicker[2]) << " " << fig(kicker[3]) << " " << fig(kicker[4]) << " " << fig(kicker[5]) << endl;
				rank[9] = true;

			}


			iteracja++;
			}while (iteracja<50000);
			//}while (rank[1] == false);
	
	
	getchar();

}

