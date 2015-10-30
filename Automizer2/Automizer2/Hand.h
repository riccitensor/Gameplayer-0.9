#ifndef HAND
#define	HAND
#endif

#include <iostream>
#include <stdlib.h>
#include <windows.h>

#include <string>
#include <vector>

#include "Place.h"

const int numOfPlaces = 6;

using namespace std;

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

	vector<int> board;


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
	Hand(Place places[numOfPlaces], int BB, int SB, int pot, int ante, vector<int> board);

public:

	double getM(int pos); 
 

	void handInfo();
	int whoStartsPre();
	int whoStartsPost();

	Place* getPlaces();
	int setPlaces(Place place[6]);

	void setBoard(vector<int> board);
	vector<int> getBoard();


};