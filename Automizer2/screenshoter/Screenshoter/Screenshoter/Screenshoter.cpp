#ifndef AUTO
#define	AUTO


#endif

#include "stdafx.h"

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <WinUser.h>
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
#include <chrono>
#include <thread>

#include <wchar.h>



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
void saveScreenshotToFile(const wchar_t *fName, HBITMAP hBitmap) {

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


/*saving screenshots
fName - file name
amount - how many times
interval - amount of secs
hBitmap - bitmap handle
*/
void saveScreenshotToDirPeriodically(const wchar_t *fName, int amount, unsigned int interval, HBITMAP hBitmap) {


	for (int i = 0; i < amount; i++){

		std::wstring s(fName);
		wchar_t val[256];

		swprintf_s(val, L"%d", i);
		wchar_t val1[256];

		s += std::wstring(val);

		swprintf_s(val1, L".png");

		s += std::wstring(val1);
		const wchar_t *a = s.c_str();

		saveScreenshotToFile(a, hBitmap);



		//saveScreenshotToFile(szName, hBitmap);
		std::this_thread::sleep_for(std::chrono::milliseconds(interval));


	}




}

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{

	LPWSTR class_name = NULL, title = NULL;

	GetClassName(hwnd, class_name, sizeof(class_name));
	GetWindowText(hwnd, title, sizeof(title));
	cout << "Window title: " << title << endl;
	cout << "Class name: " << class_name << endl << endl;


	return TRUE;
}


HBITMAP GetScreenShot(LPCTSTR wind=NULL)
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
	HDC     hScreen;
	HDC     hDC;

	if (wind != NULL){
		// Get the window handle of calculator application.
		//HWND hWnd = ::FindWindow(0, _T("Calculator"));
		HWND hWnd = ::FindWindow(0, wind);

		// copy screen to bitmap
		hScreen = GetDC(hWnd);
		hDC = CreateCompatibleDC(hScreen);
	}
	else{

		// copy screen to bitmap
		//hScreen = GetDC(NULL);
		hScreen = GetDC(GetActiveWindow());

		hDC = CreateCompatibleDC(hScreen);

	}


	HBITMAP hBitmap = CreateCompatibleBitmap(hScreen, w, h);
	HGDIOBJ old_obj = SelectObject(hDC, hBitmap);
	BOOL    bRet = BitBlt(hDC, 0, 0, w, h, hScreen, x1, y1, SRCCOPY);


	return hBitmap;
}


int main(){

	//EnumWindows(EnumWindowsProc, NULL);

	//save screenshot
	HBITMAP hBitmap = GetScreenShot();
	//saveScreenshotToFile(L"dupaxxx.png", hBitmap);
	saveScreenshotToDirPeriodically(L"C:\\Users\\Public\\Documents\\Dokumenty\\dupa", 10, 500, hBitmap);

}