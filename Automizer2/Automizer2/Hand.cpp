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


/*
"0" - BRAK KARTY
"1" - 2ka
KOLORY:
1 - spades
2 - clubs
3 - diamond
4 - hearts

KARTE  LICZYMY OD 1!!!
*/
vector< pair<int, string> > HANDS = {

	{ 1, "2s" },
	{ 2, "3s" },
	{ 3, "4s" },
	{ 4, "5s" },
	{ 5, "6s" },
	{ 6, "7s" },
	{ 7, "8s" },
	{ 8, "9s" },
	{ 9, "Ts" },
	{ 10, "Js" },
	{ 11, "Qs" },
	{ 12, "Ks" },
	{ 13, "As" },

	{ 14, "2c" },
	{ 15, "3c" },
	{ 16, "4c" },
	{ 17, "5c" },
	{ 18, "6c" },
	{ 19, "7c" },
	{ 20, "8c" },
	{ 21, "9c" },
	{ 22, "Tc" },
	{ 23, "Jc" },
	{ 24, "Qc" },
	{ 25, "Kc" },
	{ 26, "Ac" },

	{ 27, "2d" },
	{ 28, "3d" },
	{ 29, "4d" },
	{ 30, "5d" },
	{ 31, "6d" },
	{ 32, "7d" },
	{ 33, "8d" },
	{ 34, "9d" },
	{ 35, "Td" },
	{ 36, "Jd" },
	{ 37, "Qd" },
	{ 38, "Kd" },
	{ 39, "Ad" },

	{ 40, "2h" },
	{ 41, "3h" },
	{ 42, "4h" },
	{ 43, "5h" },
	{ 44, "6h" },
	{ 45, "7h" },
	{ 46, "8h" },
	{ 47, "9h" },
	{ 48, "Th" },
	{ 49, "Jh" },
	{ 50, "Qh" },
	{ 51, "Kh" },
	{ 52, "Ah" }


};


/*
"0" - BRAK KARTY
"1" - 2ka
KOLORY:
1 - spades
2 - clubs
3 - diamond
4 - hearts
*/

string getHandSignature(int h, int color){
	return HANDS.at((color - 1) * 13 + h - 1).second;
}

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

//vector<int,vector<int,int> > range2hands(int range){

	//vector<int, vector<int, int> >temp;
//		temp[1]


//}


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