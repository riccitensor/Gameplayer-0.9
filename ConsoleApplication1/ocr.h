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
		printf("the image loaded successfully\n");
	}
	else
	{
		printf("The image failed to load\n");

		ILenum err = ilGetError();
		printf("the error %d\n", err);
		printf("string is %s\n", ilGetString(err));
	}

	int size = ilGetInteger(IL_IMAGE_SIZE_OF_DATA);
	printf("Data size:  %d\n", size);
	ILubyte * bytes = ilGetData();

	int w = ilGetInteger(IL_IMAGE_WIDTH);
	//int h = ilGetInteger(IL_IMAGE_HEIGHT);

	int idx = 4 * (w*y + x);

	printf("%d\n", bytes[idx]);
	printf("%d\n", bytes[idx + 1]);
	printf("%d\n", bytes[idx + 2]);

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


void pixelListTest2(){


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


	vector <vector<int>> pixels = getPixelRGBList("test.png", pixelList);
	/*for (std::vector <vector<int>>::size_type i = 0; i != pixels.size(); i++){
	for (std::vector<int>::size_type j = 0; j != pixels.size(); j++){

	cout << pixels[i][j] << "," << endl;
	}
	cout<<endl;
	}*/
	if (inRange(pixels[0][0], 151) && inRange(pixels[0][1], 221) && inRange(pixels[0][2], 255))  cout << "rozpoznano cyfre 0" << endl;
	//if ((pixels[0][0] == 151) && (pixels[0][1] == 221) && (pixels[0][2] == 255)) cout << "rozpoznano cyfre 0" << endl;


}