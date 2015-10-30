#ifndef PLACE
#define	PLACE
#endif

#include <iostream>
#include <stdlib.h>
#include <windows.h>

#include <string>
#include <vector>

using namespace std;

class Place{

public:
	/*
	Id Miejsca: 0 do 5, nasze miejsce = 0 ZAWSZE
	*/
	int placeId;

	/*
	Stack
	*/
	int stack;

	/*
	Range
	*/
	vector<int> range;

	/*
	Typ miejsca
	*/
	bool posBB;
	bool posSB;
	bool posBTN;

	/*
	M
	*/
	double M;

	/*
	Czy bierze udzial w rozdaniu 
	*/
	int active;

	/*
	Moja reka
	*/
	vector<int> hand;

	double getM();
	void setM(double newm);

	int getStack();
	void setStack(int stack);

	vector<int> getRange();
	void setRange(vector<int> range);

	void setPosition(int pos);

	int getActive();
	void setActive(int a);

	vector<int> getHand();
	void setHand(vector<int>);

public:
	Place();
	Place(int id, int stack, vector<int> range);
		
	void show();
	bool isActive();

};