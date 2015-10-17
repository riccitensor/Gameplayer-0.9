// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <gdiplus.h>

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <tuple>
#include <vector>   
#include <map>




#ifdef linux
#include <termios.h>
#include <sys/io.h>
#else
#include <io.h>
#include <windows.h>
#include <conio.h>
#endif

#include <stdlib.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <sys/stat.h>
#include <math.h>
#include <time.h>
#include <algorithm>

#include <string>

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

vector<int> getPixelRGBListForPixel(const char *fName, int x,int y) {

	vector<int> ret;
	ret = checkPixel(fName, x, y);

	return ret;
}

void compareFileRGBArrayForCoordinatesTEST(int x1, int x2, int y1, int y2, vector<char*> fNames){
	
	

		
	for (int x = x1; x <= x2; x++){

		for (int y = y1; y <= y2; y++){

			for (std::vector<char*>::size_type i = 0; i != fNames.size(); i++) {

				vector<int> ret;
				ret = checkPixel(fNames[i], x, y);

				cout << "File: " << i << ", Coords: " << x << "," << y << ", RGB: " << ret[0] << "," << ret[1] << "," << ret[2] << endl;

			}
		}

	}


}



void pixelListTest2(){

	cout << "CIPA" << endl;
	vector<pair<int, int>> pixelList;

	pair<int, int> a0;
	a0.first = 172;
	a0.second = 204;

	pair<int, int> a1;
	a1.first = 175;
	a1.second = 210;

	pair<int, int> a2;
	a2.first = 173;
	a2.second = 205;

	pair<int, int> a3;
	a3.first = 175;
	a3.second = 206;

	pair<int, int> a4;
	a4.first = 175;
	a4.second = 205;

	pair<int, int> a5;
	a5.first = 171;
	a5.second = 204;

	pair<int, int> a6;
	a6.first = 175;
	a6.second = 207;

	pair<int, int> a7;
	a7.first = 175;
	a7.second = 204;

	pair<int, int> a8;
	a8.first = 172;
	a8.second = 207;

	pair<int, int> a9;
	a9.first = 171;
	a9.second = 208;



	pixelList.push_back(a0);
	pixelList.push_back(a1);
	pixelList.push_back(a2);
	pixelList.push_back(a3);
	pixelList.push_back(a4);
	pixelList.push_back(a5);
	pixelList.push_back(a6);
	pixelList.push_back(a7);
	pixelList.push_back(a8);
	pixelList.push_back(a9);


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

	if (inRange(pixels[0][0], 151) && inRange(pixels[0][1], 221) && inRange(pixels[0][2], 255)) cout << "rozpoznano cyfre 0" << endl;
	if (inRange(pixels[1][0], 187) && inRange(pixels[1][1], 114) && inRange(pixels[1][2], 28))  cout << "rozpoznano cyfre 1" << endl;
	if (inRange(pixels[2][0], 44) && inRange(pixels[2][1], 44) && inRange(pixels[2][2], 85))  cout << "rozpoznano cyfre 2" << endl;
	if (inRange(pixels[3][0], 152) && inRange(pixels[3][1], 74) && inRange(pixels[3][2], 28))  cout << "rozpoznano cyfre 3" << endl;
	if (inRange(pixels[4][0], 113) && inRange(pixels[4][1], 27) && inRange(pixels[4][2], 27))  cout << "rozpoznano cyfre 4" << endl;
	if (inRange(pixels[5][0], 222) && inRange(pixels[5][1], 255) && inRange(pixels[5][2], 255)) cout << "rozpoznano cyfre 5" << endl;
	if (inRange(pixels[6][0], 152) && inRange(pixels[6][1], 74) && inRange(pixels[6][2], 28))  cout << "rozpoznano cyfre 6" << endl;
	if (inRange(pixels[7][0], 255) && inRange(pixels[7][1], 192) && inRange(pixels[7][2], 123)) cout << "rozpoznano cyfre 7" << endl;
	if (inRange(pixels[8][0], 187) && inRange(pixels[8][1], 255) && inRange(pixels[8][2], 255)) cout << "rozpoznano cyfre 8" << endl;
	if (inRange(pixels[9][0], 75) && inRange(pixels[9][1], 31) && inRange(pixels[9][2], 31))  cout << "rozpoznano cyfre 9" << endl;



}