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

public:
	void show();
	bool isActive();

};