#include <iostream>
#include <stdlib.h>
#include <windows.h>

#include <string>
#include <vector>
#include <map>


#include "Hand.h"

using namespace std;
	


/*
1.Stan (na F, czy po F)
2. Klastrzy M
2.1. m < 7 ICMizer
2.2 m > 7 88-JJ, QQ-AA przypadki
*/



void gameTest(){

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

	/*
	MY ZAWSZE SIEDZIMY PRZZY STOLIKU 
	*/

	vector<int> board;
	board.push_back(12);
	board.push_back(13);
	board.push_back(14);
	board.push_back(15);
	board.push_back(16);



	int myhand[2][2] = { { 12, 2 }, { 3, 1 } };

	Place places[numOfPlaces];

	places[0].placeId = 0; //HERO
	places[0].stack = 995;
	places[0].posBB = 0;
	places[0].posSB = 1;
	places[0].posBTN = 0;
	places[0].active = 1; //czy bierze udzial w rozdaniu

	places[1].placeId = 1;
	places[1].stack = 855;
	places[1].posBB = 1;
	places[1].posSB = 0;
	places[1].posBTN = 0;
	places[1].active = 1;

	places[2].placeId = 2;
	places[2].stack = 845;
	places[2].posBB = 0;
	places[2].posSB = 0;
	places[2].posBTN = 0;
	places[2].active = 1;

	places[3].placeId = 3;
	places[3].stack = 0;
	places[3].posBB = 0;
	places[3].posSB = 0;
	places[3].posBTN = 0;
	places[3].active = 0;

	places[4].placeId = 4;
	places[4].stack = 0;
	places[4].posBB = 0;
	places[4].posSB = 0;
	places[4].posBTN = 0;
	places[4].active = 0;

	places[5].placeId = 5;
	places[5].stack = 135;
	places[5].posBB = 0;
	places[5].posSB = 0;
	places[5].posBTN = 1;
	places[5].active = 0;





	Hand *myHand = new Hand(places, 60, 30, 170, 5, board);

	myHand->handInfo();
	




}

/*
icmize

arguments
- the pot
- stacks
- call ranges
- fold ranges
output
- push/fold

*/
bool icmize(int pot,  int myhand[2][2], int stacks[6], int callrange[6], int foldrange[6]){

	
	return true;
}