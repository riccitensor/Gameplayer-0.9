#include <iostream>
#include <stdlib.h>
#include <windows.h>

#include <string>
#include <vector>

#include "Place.h"

const int numOfPlaces = 6;



class Hand{

public:
	/*
	miejsca przy stole
	*/
	Place places[numOfPlaces];
	
	/*
	miejsca przy stole
	*/
	int myHand[2][2];

	/*
	pierwsza klamra to karta, druga klamra to kolor karty
	od lewej pierwsza karta to osemka dzwonek, druga to dama dzwonek, 3 to krol czerwien,
	pierwsza klamra:
	0-brak karty
	1-as
	2-dwojka
	3-trojka
	4-
	5-
	6-
	7-
	8-
	9-
	10-dziesiatka
	11-walet
	12-dama
	13-krol

	druga klamra:
	0-brak karty
	1-pik //na skojarzenie pik pierwszy bo krolewski
	2-trefl
	3-czerwien //na skojarzenia bo przypomina serduszko<3
	4-dzwonek // bo przypomina romb
	*/

	/*
	BB,SB 
	*/
	int BB;
	int SB;

	/*
	pot
	*/

	int pot;

	/*
	ante
	*/

	int ante;

	/*
	pot
	*/

	int board[5][2];


public:

	/*
	Indeks places - POZYCJA
	0 - SB
	1 - BB
	2 - UTG
	3 - HJ
	4 - LJ
	5 - BTN
	*/
	Hand(Place places[numOfPlaces], int BB, int SB, int pot, int ante, int board[5][2], int myhand[2][2]);

public:

	double getM(int pos);

	void handInfo();
	int whoStartsPre();
	int whoStartsPost();


};