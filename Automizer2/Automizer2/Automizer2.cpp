#ifndef AUTO
#define	AUTO

#include "algo_funkcje.h"

#endif

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
#include "Randomizer.h"


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

algo_funkcje *alg_funkcje;

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



int main()
{
	srand((unsigned int)time(NULL));

	ilInit();
	printf("DevIL has been initialized\n");

	algo_funkcje *alg_funkcje;
	alg_funkcje = new algo_funkcje();

	//wcztujemy zakresy
	readRanges();

	//-------------------------------------------------------CALA REKA Z KLASY HAND
	Place places[6];

	//place 0
	places[0].setPosition(0);
	places[0].setStack(300);
	places[0].setRange(range18);
	places[0].setActive(1);//-----------------------------------ACTIVE

	//place 1
	places[1].setPosition(1);
	places[1].setStack(500);
	places[1].setRange(range26);
	places[1].setActive(0);

	//place 2
	places[2].setPosition(2);
	places[2].setStack(222);
	places[2].setRange(range34);
	places[2].setActive(1);//-----------------------------------ACTIVE

	//place 3
	places[3].setPosition(3);
	places[3].setStack(111);
	places[3].setRange(range6);
	places[3].setActive(0);

	//place 4
	places[4].setPosition(4);
	places[4].setStack(345);
	places[4].setRange(range6);
	places[4].setActive(0);

	//place 5
	places[5].setPosition(5);
	places[5].setStack(321);
	places[5].setRange(range74);
	places[5].setActive(1);//-----------------------------------ACTIVE

	int BB = 20;
	int SB = 10;
	int pot = 100;
	int ante = 10;

	vector<int> board;

	Hand *hand = new Hand(places, BB, SB, pot, ante, board);

	Place *pl = new Place();
	pl = hand->getPlaces();




	/*
	NIEAKTYWNI GRACZE MAJA RANGE OD 60 - 100%!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! STRATEGIA ZALEZY OD M
	*/

	//karta 2 do 53


	//uzywane rece
	vector<int> used;

	//wszyscy przy stole
	for (int i = 0; i < 6; i++){

		int k1;
		int k2;
		vector<int> h;

		do{
			//pobieramy dla zakresu
			h = randomHandFromRange(pl[i].getRange());

			//obie kartyz reki
			k1 = h[0];
			k2 = h[1];
			bool test = isInVector(used, h[0]) || isInVector(used, h[1]);
			//cout << "Test;" << convert(k1)  << convert(k2) << "--->" << test<< endl;

			
		} while (isInVector(used, h[0]) || isInVector(used, h[1]));

		//ustalamy rece graczom
		vector<int> temp;
		temp.push_back(k1);
		temp.push_back(k2);

		cout << convert(k1) << convert(k2) << endl;

		places[i].setHand(temp);

		//dodajemy obie karty reki do USED
		used.push_back(k1);
		used.push_back(k2);

	}

	
	//5 kart z boardu
	for (int i = 0; i < 5; i++){

		int k;
		//losowanie boardu
		do{

			//pobieramy dla zakresu
			k = rand() % 52 + 2;

			//bool test = isInVector(used, h[0]) || isInVector(used, h[1]);
			//cout << "Test;" << convert(k1)  << convert(k2) << "--->" << test<< endl;


		} while (isInVector(used, k));

		//dodajemy do boardu
		board.push_back(k);
	}
	//ustalamy board
	hand->setBoard(board);

	vector<int> b = hand->getBoard();
	cout << "BOARD" << endl;
	for (std::vector<int>::size_type i = 0; i != b.size(); i++) {
		cout << convert(b[i]) << endl;

	}


	getchar();
}
