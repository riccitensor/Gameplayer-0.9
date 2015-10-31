#include "stdafx.h"

#include <iostream>
#include <list>
#include "Hand.h"

using namespace std;

Hand::Hand(Place places[numOfPlaces], int BB, int SB, int pot, int ante, vector<int> b){
	
	for (int i = 0; i < numOfPlaces; i++){
		this->places[i] = places[i];
	}


	this->board = b;

	
	this->ante = ante;
	this->BB = BB;
	this->SB = SB;
	this->pot = pot;
	//this->myHand[0][0] = myhand[0][0];
	//this->myHand[0][1] = myhand[0][1];
	//this->myHand[1][0] = myhand[1][0];
	//this->myHand[1][1] = myhand[1][1];

	for (int i = 0; i < 6; i++){
		places[i].setM(places[i].getStack() / this->BB);
	}

}

double Hand::getM(int pos){
	return this->places[pos].getM();
}




vector< pair<double, double> > MTABLE = {
	{ 0, 7 },
	{ 7.1, 50 }
};




int Hand::whoStartsPre(){
	if (this->places[5].posBB == 1)
		return 0;

	for (int i = 0; i < 5; i++){

		if (this->places[i].posBB == 1)
			return (i + 1);

	}

	return -1;
}

int Hand::whoStartsPost(){
	if (this->places[5].posSB == 1)
		return 0;

	for (int i = 0; i < 5; i++){

		if (this->places[i].posSB == 1)
			return (i + 1);

	}
	return -1;
}


void Hand::handInfo(){

	cout << "Stakes: " << this->SB << "/" << this->BB << "$ Ante: " << this->ante << endl;
	cout << " ADD HANDS AND BOARD INFO!!" << endl;
	cout << "POT: " << this->pot << endl;

	for (int i = 0; i < 6; i++){

		if (this->places[i].isActive()){
			this->places[i].show();
			//cout << "M: " << this->getM(i) << endl;
			cout << "M: " << this->places[i].getStack() / this->BB << endl;
		}

	}

	cout << "WHO STARTS PRE: " << whoStartsPre() << endl;
	cout << "WHO STARTS POST: " << whoStartsPost() << endl;
	

}

Place* Hand::getPlaces(){

	return this->places;

}

void Hand::setBoard(vector<int> board){

	this->board = board;

}
vector<int> Hand::getBoard(){
	return this->board;
}

void Hand::clearBoard(){
	this->board.clear();
}
