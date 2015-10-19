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

#include "Showdown.h"
#include "HandEval.h"


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

#include "function.h"
function *funkcje;


#include "baza.h"
baza *base;

#include "kolorki.h"
kolorki *kolory;

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
KODY KART

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




vector <vector<int>> getPixelVector(vector<pair<int,int>> pixels) {
	
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























//range list
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

	//test a game
	//gameTest();
	
	kolory = new kolorki();


	funkcje = new function();
	base = new baza();

	algo_funkcje *alg_funkcje;
	alg_funkcje = new algo_funkcje();

	alg_funkcje->zeruj();
	alg_funkcje->debug = 1;

	algo_porownanie *alg_porownanie;
	alg_porownanie = new algo_porownanie();

	//---------------------------------------------------------TESTY KTO WYGRAL------------------
	alg_funkcje->whoWins
		(13,5,10,24,37,
		11,42,
		12,14,
		15,16,
		17,18,
		19,20,
		21,22);

	/*
	KODY KART

	2 = 2h			15 = 2d			28 = 2c			41 = 2s
	..				..				..				..

	13 = Kh			26 = Kd			39 = Kc			52 = Ks
	14 = Ah			27 = Ad			40 = Ac			53 = As

	*/


	/*
	EXAMPLE:

	Ad 2s 3c    2d    5h
	27 41 29    15    5

	1. Ac Kd
	   40 26
	2. Kc Qc
	   39 38
	3. 2h 6h WINNER
	   2  6



	*/
	cout << "WHO WINS TEST" << endl;

	alg_funkcje->whoWins
		(27, 41, 29, 15, 5,
		40, 26,
		39, 38,
		2, 6,
		0, 0,
		0, 0,
		0, 0);


	
	std::vector <std::vector<std::string> >	 ranges = alg_funkcje->readRangesFromFile();

	//----------------------------------------------CALA LISTA RAK
	for (std::vector<int>::size_type i = 0; i != ranges.size(); i++){
		int_ranges[alg_funkcje->handToNum(ranges[i][0])] = std::stoi(ranges[i][1]);
		
	}

	//-----------------------------------------------KONKRETNE ZAKRESY
	vector <int> range27 =  alg_funkcje->handsForRange(int_ranges, 5);
	for (std::vector<int>::size_type i = 0; i != range27.size(); i++){
		//cout << range27[i] << "(" << alg_funkcje->NumToHand(range27[i]) << ")" << ",";
	}

	//-----------------------------------------------EQUITY CALC	
	//alg_funkcje->equityvsRange(23, 24, 2);

		
	//----------------------------------------TEST KONWERSJI RAK
	/*
	cout << "Reka: AhQc" 
		<< "Kod+10: " 
		<< alg_funkcje->handToNum("AhQc") 
		<< " OWROTNIE: " 
		<<alg_funkcje->NumToHand(2448)<<endl;
	*/
	
	
	//check pixelList function -- pixelListTest is TOO SLOW (uses another func), 
	pixelListTest2();
	


	getchar();
}
