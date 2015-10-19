// ConsoleApplication1.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <gdiplus.h>
#include <algorithm>
#include <cmath>
#include <vector>   
#include <map>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <iterator>
#include <sys/stat.h>
#include <math.h>
#include <time.h>



#undef _UNICODE
#include "il.h"

#pragma comment( lib, "DevIL.lib" )
#pragma comment( lib, "gdiplus.lib")

using namespace std;
using namespace Gdiplus;


using namespace std;

const int MAX_RANGE = 5; //value - pobrana wartosc, mark - ustalona wartosc w excel


bool inRange(int value, int mark){
	return value >= (mark - MAX_RANGE) && value <= (mark + MAX_RANGE);
}


vector<int> checkPixel(const char *fName, int x, int y) {

	// Loading an image
	ILboolean result = ilLoadImage(fName);
	//ILboolean result = ilLoadImage("myjpg.jpg");


	if (result)
	{
		//printf("the image loaded successfully\n");
	}
	else
	{
		printf("The image failed to load\n");

		ILenum err = ilGetError();
		printf("the error %d\n", err);
		printf("string is %s\n", ilGetString(err));
	}

	int size = ilGetInteger(IL_IMAGE_SIZE_OF_DATA);
	//printf("Data size:  %d\n", size);
	ILubyte * bytes = ilGetData();

	int w = ilGetInteger(IL_IMAGE_WIDTH);
	//int h = ilGetInteger(IL_IMAGE_HEIGHT);

	int idx = 4 * (w*y + x);

	//printf("%d\n", bytes[idx]);
	//printf("%d\n", bytes[idx + 1]);
	//printf("%d\n", bytes[idx + 2]);

	vector <int> ret;

	ret.push_back(bytes[idx]);
	ret.push_back(bytes[idx + 1]);
	ret.push_back(bytes[idx + 2]);

	return ret;
}

vector <vector<int>> getPixelRGBList(const char *fName, vector<pair<int, int>> pixels) {

	vector <vector<int>> ret;

	for (vector<pair<int, int>>::iterator it = pixels.begin(); it != pixels.end(); ++it) {
		//cout << "Vec: " << it->first << "," << it->second << endl;

		vector<int> temp = checkPixel(fName, it->first, it->second);

		ret.push_back(temp);
	}
	return ret;
}

vector<int> getPixelRGBListForPixel(const char *fName, int x, int y) {

	vector<int> ret;
	ret = checkPixel(fName, x, y);

	return ret;
}

void compareFileRGBArrayForCoordinatesTEST(int x1, int x2, int y1, int y2, vector<char*> fNames){


	ofstream myfile;
	myfile.open("../Data/data.txt");

	for (int x = x1; x <= x2; x++){

		for (int y = y1; y <= y2; y++){

			for (std::vector<char*>::size_type i = 0; i != fNames.size(); i++) {

				vector<int> ret;
				ret = checkPixel(fNames[i], x, y);



				myfile << "File: " << i << ", Coords: " << x << "," << y << ", RGB: " << ret[0] << "," << ret[1] << "," << ret[2] << endl;


			}
		}

	}

	myfile.close();


}



bool reducer(int x1, int y1, int y2, const char* file){
	
	//z gory w dol, y1 > y2
		for (int y = y1; y >= y2; y--){

			vector<int> ret;
			//czyt pixel
			ret = checkPixel(file, x1, y);

			//r=g=b
			if (ret[0] == ret[1] && ret[1] == ret[2]){
				continue;
			}
			else{
				return true;
			}

		}
		//gdy ani raz tru
		return false;

}





void pixelListTest2(){

	int check = 0;  //zmienna ktora bedzie informowala czy liczba jest 1,2,3 czy 4 cyfrowa, jesli check = 2 to wtedy 2 cyfrowa etc
	int bet_pos_1 = 0; //zmienna oznacza ile podbil gracz na pozycji 1
	vector<pair<int, int>> pixelList;

	pair<int, int> acheck; //sprawdz czy liczba jest 2 czy 3 cyfrowa, zczytuje jakis pixel ktory mi powie z ilu cyfrowa liczba mam do czynienia
	acheck.first = 181;
	acheck.second = 207;

	pair<int, int> ap11z2; //ap11z2, nazwa wspolrzednej oznacza: a-nic nie oznacza, p-za literk¹ p jest cyfra ktora informuje o jak¹ pozycje mi chodzi
	ap11z2.first = 174; //a sekwencja 1z2 oznacza ze jesli to liczba 2 cyfrowa to 1 z 2 wczytuje mi RGB z wspolrzednych z dziesi¹tek, 2 z 2 wspolrzedna z jednosci
	ap11z2.second = 207;

	pair<int, int> ap12z2;
	ap12z2.first = 179;
	ap12z2.second = 207;

	//-------------------------------
	pair<int, int> ap11z3; //analogicznie pozycja 1, wpolrzedne do odczytania RGB z cyfry setek
	ap11z3.first = 171;
	ap11z3.second = 207;

	pair<int, int> ap12z3;
	ap12z3.first = 176;
	ap12z3.second = 207;


	pair<int, int> ap13z3;
	ap13z3.first = 181;
	ap13z3.second = 207;


	pixelList.push_back(acheck);
	pixelList.push_back(ap11z2);
	pixelList.push_back(ap12z2);

	pixelList.push_back(ap11z3);
	pixelList.push_back(ap12z3);
	pixelList.push_back(ap13z3);  //tu wiesz co sie dzieje

	//show pixel list
	for (vector<pair<int, int>>::iterator it = pixelList.begin(); it != pixelList.end(); ++it) {
		cout << "Vec: " << it->first << "," << it->second << endl;
	}


	vector <vector<int>> pixels = getPixelRGBList("../img/test.png", pixelList);
	/*for (std::vector <vector<int>>::size_type i = 0; i != pixels.size(); i++){
	for (std::vector<int>::size_type j = 0; j != pixels.size(); j++){

	cout << pixels[i][j] << "," << endl;
	}
	cout<<endl;
	}*/

	if ((pixels[0][0] == pixels[0][1]) && (pixels[0][1] == pixels[0][2])) //tu sprawdzam wlasnie z ilu cyfrowa liczba mam do czynienia
	{
		check = 2;
	}
	else
	{

		cout << "liczba jest 3 cyfrowa" << endl;
		check = 3;
	} //oczywiscie pozniej beda jeszcze warunki czy jest to liczba 1 cyfrowa, i warunek dla 4 cyfrowej

	if (check == 2) //jesli liczba 2 cyfrowa 
	{// to ponizej sprawdzam jaka to cyfra znajduje siê na miejscu dziesiatek naszej 2 cyfrowej liczby i odpowiednio j¹ przemnazam i przypisuje jakie to podbicie
		if (inRange(pixels[1][0], 28) && inRange(pixels[1][1], 114) && inRange(pixels[1][2], 187)) bet_pos_1 = 0 * 10;
		if (inRange(pixels[1][0], 152) && inRange(pixels[1][1], 74) && inRange(pixels[1][2], 29)) bet_pos_1 = 1 * 10;
		if (inRange(pixels[1][0], 224) && inRange(pixels[1][1], 224) && inRange(pixels[1][2], 158)) bet_pos_1 = 2 * 10;
		if (inRange(pixels[1][0], 255) && inRange(pixels[1][1], 187) && inRange(pixels[1][2], 114)) bet_pos_1 = 3 * 10;
		if (inRange(pixels[1][0], 151) && inRange(pixels[1][1], 221) && inRange(pixels[1][2], 187)) bet_pos_1 = 4 * 10;
		if (inRange(pixels[1][0], 115) && inRange(pixels[1][1], 31) && inRange(pixels[1][2], 31)) bet_pos_1 = 5 * 10;
		if (inRange(pixels[1][0], 255) && inRange(pixels[1][1], 255) && inRange(pixels[1][2], 221)) bet_pos_1 = 6 * 10;
		if (inRange(pixels[1][0], 224) && inRange(pixels[1][1], 158) && inRange(pixels[1][2], 86)) bet_pos_1 = 7 * 10;
		if (inRange(pixels[1][0], 255) && inRange(pixels[1][1], 221) && inRange(pixels[1][2], 151)) bet_pos_1 = 8 * 10;
		if (inRange(pixels[1][0], 255) && inRange(pixels[1][1], 255) && inRange(pixels[1][2], 255)) bet_pos_1 = 9 * 10;
		//tu ponizej sprawdzam jaka cyfra znajduje sie na miejscu jednosci i do podbicia dodaje jenosci
		if (inRange(pixels[2][0], 28) && inRange(pixels[2][1], 114) && inRange(pixels[2][2], 187)) bet_pos_1 = bet_pos_1 + 0;
		if (inRange(pixels[2][0], 152) && inRange(pixels[2][1], 74) && inRange(pixels[2][2], 29)) bet_pos_1 = bet_pos_1 + 1;
		if (inRange(pixels[2][0], 224) && inRange(pixels[2][1], 224) && inRange(pixels[2][2], 158)) bet_pos_1 = bet_pos_1 + 2;
		if (inRange(pixels[2][0], 255) && inRange(pixels[2][1], 187) && inRange(pixels[2][2], 114)) bet_pos_1 = bet_pos_1 + 3;
		if (inRange(pixels[2][0], 151) && inRange(pixels[2][1], 221) && inRange(pixels[2][2], 187)) bet_pos_1 = bet_pos_1 + 4;
		if (inRange(pixels[2][0], 115) && inRange(pixels[2][1], 31) && inRange(pixels[2][2], 31)) bet_pos_1 = bet_pos_1 + 5;
		if (inRange(pixels[2][0], 255) && inRange(pixels[2][1], 255) && inRange(pixels[2][2], 221)) bet_pos_1 = bet_pos_1 + 6;
		if (inRange(pixels[2][0], 224) && inRange(pixels[2][1], 158) && inRange(pixels[2][2], 86)) bet_pos_1 = bet_pos_1 + 7;
		if (inRange(pixels[2][0], 255) && inRange(pixels[2][1], 221) && inRange(pixels[2][2], 151)) bet_pos_1 = bet_pos_1 + 8;
		if (inRange(pixels[2][0], 255) && inRange(pixels[2][1], 255) && inRange(pixels[2][2], 255)) bet_pos_1 = bet_pos_1 + 9;
	}

	if (check == 3)
	{//analogicznie jak powyzej
		if (inRange(pixels[3][0], 28)  && inRange(pixels[3][1], 114) && inRange(pixels[3][2], 187)) bet_pos_1 = 0 * 100;
		if (inRange(pixels[3][0], 152) && inRange(pixels[3][1], 74)  && inRange(pixels[3][2], 29)) bet_pos_1 = 1 * 100;
		if (inRange(pixels[3][0], 224) && inRange(pixels[3][1], 224) && inRange(pixels[3][2], 158)) bet_pos_1 = 2 * 100;
		if (inRange(pixels[3][0], 255) && inRange(pixels[3][1], 187) && inRange(pixels[3][2], 114)) bet_pos_1 = 3 * 100;
		if (inRange(pixels[3][0], 151) && inRange(pixels[3][1], 221) && inRange(pixels[3][2], 187)) bet_pos_1 = 4 * 100;
		if (inRange(pixels[3][0], 115) && inRange(pixels[3][1], 31)  && inRange(pixels[3][2], 31)) bet_pos_1 = 5 * 100;
		if (inRange(pixels[3][0], 255) && inRange(pixels[3][1], 255) && inRange(pixels[3][2], 221)) bet_pos_1 = 6 * 100;
		if (inRange(pixels[3][0], 224) && inRange(pixels[3][1], 158) && inRange(pixels[3][2], 86)) bet_pos_1 = 7 * 100;
		if (inRange(pixels[3][0], 255) && inRange(pixels[3][1], 221) && inRange(pixels[3][2], 151)) bet_pos_1 = 8 * 100;
		if (inRange(pixels[3][0], 255) && inRange(pixels[3][1], 255) && inRange(pixels[3][2], 255)) bet_pos_1 = 9 * 100;

		if (inRange(pixels[4][0], 28) &&  inRange(pixels[4][1], 114) && inRange(pixels[4][2], 187)) bet_pos_1 = bet_pos_1 + 0;
		if (inRange(pixels[4][0], 152) && inRange(pixels[4][1], 74)  && inRange(pixels[4][2], 29)) bet_pos_1 = bet_pos_1 + 10;
		if (inRange(pixels[4][0], 224) && inRange(pixels[4][1], 224) && inRange(pixels[4][2], 158)) bet_pos_1 = bet_pos_1 + 20;
		if (inRange(pixels[4][0], 255) && inRange(pixels[4][1], 187) && inRange(pixels[4][2], 114)) bet_pos_1 = bet_pos_1 + 30;
		if (inRange(pixels[4][0], 151) && inRange(pixels[4][1], 221) && inRange(pixels[4][2], 187)) bet_pos_1 = bet_pos_1 + 40;
		if (inRange(pixels[4][0], 115) && inRange(pixels[4][1], 31)  && inRange(pixels[4][2], 31)) bet_pos_1 = bet_pos_1 + 50;
		if (inRange(pixels[4][0], 255) && inRange(pixels[4][1], 255) && inRange(pixels[4][2], 221)) bet_pos_1 = bet_pos_1 + 60;
		if (inRange(pixels[4][0], 224) && inRange(pixels[4][1], 158) && inRange(pixels[4][2], 86)) bet_pos_1 = bet_pos_1 + 70;
		if (inRange(pixels[4][0], 255) && inRange(pixels[4][1], 221) && inRange(pixels[4][2], 151)) bet_pos_1 = bet_pos_1 + 80;
		if (inRange(pixels[4][0], 255) && inRange(pixels[4][1], 255) && inRange(pixels[4][2], 255)) bet_pos_1 = bet_pos_1 + 90;

		if (inRange(pixels[5][0], 28)  && inRange(pixels[5][1], 114) && inRange(pixels[5][2], 187)) bet_pos_1 = bet_pos_1 + 0;
		if (inRange(pixels[5][0], 152) && inRange(pixels[5][1], 74)  && inRange(pixels[5][2], 29)) bet_pos_1 = bet_pos_1 + 1;
		if (inRange(pixels[5][0], 224) && inRange(pixels[5][1], 224) && inRange(pixels[5][2], 158)) bet_pos_1 = bet_pos_1 + 2;
		if (inRange(pixels[5][0], 255) && inRange(pixels[5][1], 187) && inRange(pixels[5][2], 114)) bet_pos_1 = bet_pos_1 + 3;
		if (inRange(pixels[5][0], 151) && inRange(pixels[5][1], 221) && inRange(pixels[5][2], 187)) bet_pos_1 = bet_pos_1 + 4;
		if (inRange(pixels[5][0], 115) && inRange(pixels[5][1], 31)  && inRange(pixels[5][2], 31)) bet_pos_1 = bet_pos_1 + 5;
		if (inRange(pixels[5][0], 255) && inRange(pixels[5][1], 255) && inRange(pixels[5][2], 221)) bet_pos_1 = bet_pos_1 + 6;
		if (inRange(pixels[5][0], 224) && inRange(pixels[5][1], 158) && inRange(pixels[5][2], 86)) bet_pos_1 = bet_pos_1 + 7;
		if (inRange(pixels[5][0], 255) && inRange(pixels[5][1], 221) && inRange(pixels[5][2], 151)) bet_pos_1 = bet_pos_1 + 8;
		if (inRange(pixels[5][0], 255) && inRange(pixels[5][1], 255) && inRange(pixels[5][2], 255)) bet_pos_1 = bet_pos_1 + 9;
	}//analogicznie bedzie trzeba jeszcze zrobic dla liczby 4 cyfrowej, czyli dojdzie extra 40 linijek kodu
	//i to wszystko co powyzej tylko dla pozycji gracza na miejscu 1, a mamy 6 pozycji, czylii 600 linijek kodu, ktore powinno daæ siê jakoœ skrocic
	//wspolrzedne beda ustalane recznie lub przez petlê for

	//a RGB jest juz ustalone na sta³e (oby)
	cout << "Gracz na pozycji 1 podbil o = " << bet_pos_1 << " zetonow" << endl;
	

}