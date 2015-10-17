#include "stdafx.h"

#include <iostream>

#include "Place.h"

using namespace std;

double Place::getM(){
	return M;
}

void Place::setM(double newm){
	M = newm;
}

int Place::getStack(){
	return stack;
}

void Place::show(){

	cout << "===POSID=== " << this->placeId <<endl;
	cout << "STACK: " << this->stack << endl;
	cout << "BB: " << this->posBB << endl;
	cout << "SB: " << this->posSB << endl;
	cout << "BTN: " << this->posBTN << endl;
	//cout << "M: " << this->getM() << endl;
	cout << "ACTIVE: " << this->active << endl;

}

bool Place::isActive(){
	return this->active ? true : false;
}