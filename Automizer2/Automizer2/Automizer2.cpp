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

#include "ocr.h"
#include "Winner.h"


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

#include "algo_funkcje.h"
algo_funkcje *alg_funkcje;

#include "algo_porownanie.h"
algo_porownanie *alg_porownanie;




#include "Equity.h"

#include <string>

#undef _UNICODE
#include "il.h"

#pragma comment( lib, "DevIL.lib" )
#pragma comment( lib, "gdiplus.lib")

using namespace std;
using namespace Gdiplus;


/*
KODY KART - MICHAL

2 = 2h			15 = 2d			28 = 2c			41 = 2s
..				..				..				..

13 = Kh			26 = Kd			39 = Kc			52 = Ks
14 = Ah			27 = Ad			40 = Ac			53 = As

*/



//select gfx file encoder
int GetEncoderClsid(const WCHAR* format, CLSID* pClsid)
{
	UINT  num = 0;          // number of image encoders
	UINT  size = 0;         // size of the image encoder array in bytes

	ImageCodecInfo* pImageCodecInfo = NULL;

	GetImageEncodersSize(&num, &size);
	if (size == 0)
		return -1;  // Failure

	pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	if (pImageCodecInfo == NULL)
		return -1;  // Failure

	GetImageEncoders(num, size, pImageCodecInfo);

	for (UINT j = 0; j < num; ++j)
	{
		if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0)
		{
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;  // Success
		}
	}
	free(pImageCodecInfo);
	return -1;  // Failure
}

//saving screenshots
void saveScreenshotToFile(const WCHAR *fName, HBITMAP hBitmap) {

	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	Bitmap *image = new Bitmap(hBitmap, NULL);

	CLSID myClsId;
	int retVal = GetEncoderClsid(L"image/png", &myClsId);

	image->Save(fName, &myClsId, NULL);
	delete image;

	GdiplusShutdown(gdiplusToken);

}

//unit testing
void testMzJpgFiile(ILubyte * bytes) {

	printf("%d\n", bytes[636085]);
	printf("%d\n", bytes[636086]);
	printf("%d\n", bytes[636087]);
	printf("%d\n", bytes[636088]);

	//4*(w*myH+myW)
	printf("%d\n", bytes[642637]);
	printf("%d\n", bytes[642638]);
	printf("%d\n", bytes[642639]);
	printf("%d\n", bytes[642640]);
	printf("%d\n", bytes[642641]);
	printf("%d\n", bytes[642642]);
	printf("%d\n", bytes[642643]);

}

//create screenshots
HBITMAP GetScreenShot(void)
{
	int x1, y1, x2, y2, w, h;

	// get screen dimensions
	x1 = GetSystemMetrics(SM_XVIRTUALSCREEN);
	y1 = GetSystemMetrics(SM_YVIRTUALSCREEN);
	x2 = GetSystemMetrics(SM_CXVIRTUALSCREEN);
	y2 = GetSystemMetrics(SM_CYVIRTUALSCREEN);
	w = x2 - x1;
	h = y2 - y1;

	// copy screen to bitmap
	HDC     hScreen = GetDC(NULL);
	HDC     hDC = CreateCompatibleDC(hScreen);
	HBITMAP hBitmap = CreateCompatibleBitmap(hScreen, w, h);
	HGDIOBJ old_obj = SelectObject(hDC, hBitmap);
	BOOL    bRet = BitBlt(hDC, 0, 0, w, h, hScreen, x1, y1, SRCCOPY);

	return hBitmap;
}




vector <vector<int>> getPixelVector(vector<pair<int, int>> pixels) {

	int nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	int nScreenHeight = GetSystemMetrics(SM_CYSCREEN);
	HWND hDesktopWnd = GetDesktopWindow();
	HDC hDesktopDC = GetDC(hDesktopWnd);
	HDC hCaptureDC = CreateCompatibleDC(hDesktopDC);
	HBITMAP hCaptureBitmap = CreateCompatibleBitmap(hDesktopDC, nScreenWidth, nScreenHeight);
	SelectObject(hCaptureDC, hCaptureBitmap);

	BitBlt(hCaptureDC, 0, 0, nScreenWidth, nScreenHeight, hDesktopDC, 0, 0, SRCCOPY | CAPTUREBLT);

	BITMAPINFO bmi = { 0 };
	bmi.bmiHeader.biSize = sizeof(bmi.bmiHeader);
	bmi.bmiHeader.biWidth = nScreenWidth;
	bmi.bmiHeader.biHeight = nScreenHeight;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 32;
	bmi.bmiHeader.biCompression = BI_RGB;

	RGBQUAD *pPixels = new RGBQUAD[nScreenWidth * nScreenHeight];



	GetDIBits(
		hCaptureDC,
		hCaptureBitmap,
		0,
		nScreenHeight,
		pPixels,
		&bmi,
		DIB_RGB_COLORS
		);



	int p;

	vector <vector<int>> ret;

	for (int y = 0; y < nScreenHeight; y++){
		for (int x = 0; x < nScreenWidth; x++){
			p = (nScreenHeight - y - 1)*nScreenWidth + x; // upside down
			//unsigned char r = pPixels[p].rgbRed;
			//unsigned char g = pPixels[p].rgbGreen;
			//unsigned char b = pPixels[p].rgbBlue;

			int r = pPixels[p].rgbRed;
			int g = pPixels[p].rgbGreen;
			int b = pPixels[p].rgbBlue;
			vector<int> temp;
			temp.push_back(r);
			temp.push_back(g);
			temp.push_back(b);

			ret.push_back(temp);
		}
	}
	cout << "Ret getPPixel" << endl;

	return ret;

}

void pixelListTest(){


	vector<pair<int, int>> pixelList;

	pair<int, int> a1;
	a1.first = 442;
	a1.second = 221;

	pair<int, int> a2;
	a2.first = 442;
	a2.second = 221;

	pair<int, int> a3;
	a3.first = 331;
	a3.second = 663;


	pixelList.push_back(a1);
	pixelList.push_back(a2);
	pixelList.push_back(a3);

	//show pixel list
	for (vector<pair<int, int>>::iterator it = pixelList.begin(); it != pixelList.end(); ++it) {
		cout << "Vec: " << it->first << "," << it->second << endl;
	}


	vector <vector<int>> pixels = getPixelVector(pixelList);
	for (std::vector <vector<int>>::size_type i = 0; i != pixels.size(); i++){
		for (std::vector<int>::size_type j = 0; j != pixels.size(); j++){

			cout << i << " -- " << pixels[i][j] << endl;
		}
	}


}


void testFileRGBs(){

	vector<char*> files;
	files.push_back("../img/0-test.png");
	files.push_back("../img/1-test.png");
	files.push_back("../img/2-test.png");
	files.push_back("../img/3-test.png");
	files.push_back("../img/4-test.png");
	files.push_back("../img/5-test.png");
	files.push_back("../img/6-test.png");
	files.push_back("../img/7-test.png");
	files.push_back("../img/8-test.png");
	files.push_back("../img/9-test.png");

	compareFileRGBArrayForCoordinatesTEST(171, 175, 204, 210, files);
}


//------------------------------------------------------TU ZAPISANE SA RECE Z DANYCH RANGOW
std::map <int, int> int_ranges;



int main()
{
	ilInit();
	printf("DevIL has been initialized\n");

	//check pixel
	//vector <int> a = checkPixel("test.png", 136, 196);
	//cout << "RGB:" << a[0] << "," << a[1] << "," << a[2] << endl;

	//save screenshot
	//HBITMAP hBitmap = GetScreenShot();
	//saveScreenshotToFile(L"output.png", hBitmap);


	algo_funkcje *alg_funkcje;
	alg_funkcje = new algo_funkcje();


	
	
	std::vector <std::vector<std::string> >	 ranges = alg_funkcje->readRangesFromFile();

	//----------------------------------------------CALA LISTA RAK
	for (std::vector<int>::size_type i = 0; i != ranges.size(); i++){

		int_ranges[alg_funkcje->handToNum(ranges[i][0])] = std::stoi(ranges[i][1]);

	}

	//-----------------------------------------------KONKRETNE ZAKRESY
	vector <int> range27 = alg_funkcje->handsForRange(int_ranges, 5);

	
	for (std::vector<int>::size_type i = 0; i != range27.size(); i++){
		//cout << range27[i] << "(" << alg_funkcje->NumToHand(range27[i]) << ")" << ",";
	}
	

	


	//check pixelList function -- pixelListTest is TOO SLOW (uses another func), 
	//pixelListTest2();

	//test file RGBs
	//testFileRGBs();

	/*
	vector < tuple <int, int, int, int, int> > indicator_table;
	indicator_table = readIndicatorsFromFile("coords.txt");

	for (std::vector<int>::size_type i = 0; i != indicator_table.size(); i++) {
	std::cout <<
	std::get<0>(indicator_table[i]) << "," <<
	std::get<1>(indicator_table[i]) << "," <<
	std::get<2>(indicator_table[i]) << "," <<
	std::get<3>(indicator_table[i]) << "," <<
	std::get<4>(indicator_table[i]) << endl;

	}
	*/

	//-------------------------------------------------------CALA REKA Z KLASY HAND
	Place places[6];

	//place 0
	places[0].setPosition(0);
	places[0].setStack(300);
	places[0].setRange(20);
	places[0].setActive(1);//-----------------------------------ACTIVE

	//place 1
	places[1].setPosition(1);
	places[1].setStack(500);
	places[1].setRange(34);
	places[1].setActive(0);

	//place 2
	places[2].setPosition(2);
	places[2].setStack(222);
	places[2].setRange(66);
	places[2].setActive(1);//-----------------------------------ACTIVE

	//place 3
	places[3].setPosition(3);
	places[3].setStack(111);
	places[3].setRange(22);
	places[3].setActive(0);

	//place 4
	places[4].setPosition(4);
	places[4].setStack(345);
	places[4].setRange(45);
	places[4].setActive(0);

	//place 5
	places[5].setPosition(5);
	places[5].setStack(321);
	places[5].setRange(10);
	places[5].setActive(1);//-----------------------------------ACTIVE

	int BB = 20;
	int SB = 10;
	int pot = 100;
	int ante = 10;


	vector<int> board;

	Hand *hand = new Hand(places, BB, SB, pot, ante, board);

	bool player[13][4];
	srand((unsigned int) time(NULL));


	/*
	KODY KART - MICHAL

	2 = 2h			15 = 2d			28 = 2c			41 = 2s
	..				..				..				..

	13 = Kh			26 = Kd			39 = Kc			52 = Ks
	14 = Ah			27 = Ad			40 = Ac			53 = As

	*/
	
	/*
	9 - high card
	8 - 1 pair
	7 - 2 pairs
	6 - set
	5 - straight
	4 - flush
	3 - FH
	2 - quads
	1 - straight flush
	
	*/


	vector<int> cards = drawAllCards(53, 52);

	/*for (std::vector<int>::size_type j = 0; j != cards.size(); j++) {
		cout << cards[j] << " - ";
	}
	cout << endl;*/


	vector<int>::const_iterator first = cards.begin() + 0;
	vector<int>::const_iterator last = cards.begin() + 5;
	vector<int> commoncards(first, last);

	board = commoncards;

	/*for (std::vector<int>::size_type j = 0; j != board.size(); j++) {
		cout << board[j] << " - ";
	}
	cout << endl;*/

	vector<int> player1 = board;
	vector<int> player2 = board;
	vector<int> player3 = board;

	vector<int> player4 = board;
	vector<int> player5 = board;
	vector<int> player6 = board;


//---------------------------------------------player1
	vector<int>::const_iterator first1 = cards.begin() + 5;
	vector<int>::const_iterator last1 = cards.begin() + 7;
	vector<int> p1(first1, last1);

	vector<int>::const_iterator first2 = cards.begin() + 7;
	vector<int>::const_iterator last2 = cards.begin() + 9;
	vector<int> p2(first2, last2);

	vector<int>::const_iterator first3 = cards.begin() + 9;
	vector<int>::const_iterator last3 = cards.begin() + 11;
	vector<int> p3(first3, last3);

	vector<int>::const_iterator first4 = cards.begin() + 11;
	vector<int>::const_iterator last4 = cards.begin() + 13;
	vector<int> p4(first4, last4);

	vector<int>::const_iterator first5 = cards.begin() + 13;
	vector<int>::const_iterator last5 = cards.begin() + 15;
	vector<int> p5(first5, last5);

	vector<int>::const_iterator first6 = cards.begin() + 15;
	vector<int>::const_iterator last6 = cards.begin() + 17;
	vector<int> p6(first6, last6);


	player1.insert(player1.end(), p1.begin(), p1.end());
	player2.insert(player2.end(), p2.begin(), p2.end());
	player3.insert(player3.end(), p3.begin(), p3.end());
	player4.insert(player4.end(), p4.begin(), p4.end());
	player5.insert(player5.end(), p5.begin(), p5.end());
	player6.insert(player6.end(), p6.begin(), p6.end());

	int hand1[7];
	int hand2[7];
	int hand3[7];
	int hand4[7];
	int hand5[7];
	int hand6[7];

	for (int i = 0; i < 7; i++) {
		hand1[i] = player1[i];
		hand2[i] = player2[i];
		hand3[i] = player3[i];

		hand4[i] = player4[i];
		hand5[i] = player5[i];
		hand6[i] = player6[i];

	}

	vector<int> whathand1 = whatHand(hand1);
	vector<int> whathand2 = whatHand(hand2);
	vector<int> whathand3 = whatHand(hand3);
	vector<int> whathand4 = whatHand(hand4);
	vector<int> whathand5 = whatHand(hand5);
	vector<int> whathand6 = whatHand(hand6);
	cout << endl;
	cout << "Player1: "  ;
	for (std::vector<int>::size_type i = 0; i != whathand1.size(); i++) {
		if (i == 0) cout << ranka(whathand1[i]) << " ";
		if (i>0) cout << fig(whathand1[i]) << " ";
	}
	cout << endl;

	cout << "Player2: ";
	for (std::vector<int>::size_type i = 0; i != whathand2.size(); i++) {
		if (i == 0) cout << ranka(whathand2[i]) << " ";
		if (i>0) cout << fig(whathand2[i]) << " ";
	}
	cout << endl;

	cout << "Player3: ";
	for (std::vector<int>::size_type i = 0; i != whathand3.size(); i++) {
		if (i == 0) cout << ranka(whathand3[i]) << " ";
		if (i>0) cout << fig(whathand3[i]) << " ";
	}
	cout << endl;

	cout << "Player4: ";
	for (std::vector<int>::size_type i = 0; i != whathand4.size(); i++) {
		if (i == 0) cout << ranka(whathand4[i]) << " ";
		if (i>0) cout << fig(whathand4[i]) << " ";
	}
	cout << endl;

	cout << "Player5: ";
	for (std::vector<int>::size_type i = 0; i != whathand5.size(); i++) {
		if (i == 0) cout << ranka(whathand5[i]) << " ";
		if (i>0) cout << fig(whathand5[i]) << " ";
	}
	cout << endl;

	cout << "Player6: ";
	for (std::vector<int>::size_type i = 0; i != whathand6.size(); i++) {
		
		if (i==0) cout << ranka(whathand6[i]) << " ";
		if (i>0) cout << fig(whathand6[i]) << " ";
	}
	cout << endl;

	int ww = whoWins(
		whathand1,
		whathand2,
		whathand3,
		whathand4,
		whathand5,
		whathand6
		);

	cout << "Wygral gracz: " << ww << endl;


	getchar();
}
