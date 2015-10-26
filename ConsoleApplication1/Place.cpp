#include "stdafx.h"

#include <iostream>

#include "Place.h"

using namespace std;


Place::Place(){

}

Place::Place(int id, int stack, int range){
	this->placeId = id;
	this->stack = stack;
	this->range = range;

}

double Place::getM(){
	return M;
}

void Place::setM(double newm){
	M = newm;
}

int Place::getStack(){
	return this->stack;
}

int Place::getRange(){
	return this->range;
}

void Place::setStack(int stack){
	 this->stack = stack;
}

void Place::setRange(int range){
	this->range = range;
}

void Place::setPosition(int pos){
	this->placeId = pos;
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