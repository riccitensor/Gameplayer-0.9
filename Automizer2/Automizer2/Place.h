#include <iostream>
#include <stdlib.h>
#include <windows.h>

#include <string>


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
	int range;

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

	double getM();
	void setM(double newm);
	int getStack();
	void setStack(int stack);
	int getRange();
	void setRange(int stack);
	void setPosition(int pos);
	int getActive();
	void setActive(int a);

public:
	Place();
	Place(int id, int stack, int range);
		
	void show();
	bool isActive();

};