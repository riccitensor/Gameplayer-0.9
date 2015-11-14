// screenshoter2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#define _WIN32_WINNT    0x0501        //xp
#include <windows.h>

#include <gdiplus.h>
#include <thread>
#include "il.h"

#pragma comment( lib, "DevIL.lib" )
#pragma comment( lib, "gdiplus.lib")

using namespace std;
using namespace Gdiplus;
using namespace std;

//https://msdn.microsoft.com/en-us/library/windows/desktop/ms633522%28v=vs.85%29.aspx




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

	cout << "Zapis do pliku " << fName << endl;
	image->Save(fName, &myClsId, NULL);


	delete image;

	GdiplusShutdown(gdiplusToken);

}

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


	void printScreen(HWND hwnd){

		RECT rc;
		GetClientRect(hwnd, &rc);

		//create
		HDC hdcScreen = GetDC(NULL);
		HDC hdc = CreateCompatibleDC(hdcScreen);
		HBITMAP hbmp = CreateCompatibleBitmap(hdcScreen,
			rc.right - rc.left, rc.bottom - rc.top);
		SelectObject(hdc, hbmp);

		//Print to memory hdc
		PrintWindow(hwnd, hdc, PW_CLIENTONLY);

		//copy to clipboard
		OpenClipboard(NULL);
		EmptyClipboard();
		SetClipboardData(CF_BITMAP, hbmp);
		CloseClipboard();

		//release
		DeleteDC(hdc);
		DeleteObject(hbmp);
		ReleaseDC(NULL, hdcScreen);

	}

struct handle_data {
	unsigned long process_id;
	HWND best_handle;
};


BOOL is_main_window(HWND handle)
{
	return GetWindow(handle, GW_OWNER) == (HWND)0 && IsWindowVisible(handle);
}

int i = 1;

BOOL CALLBACK enum_windows_callback(HWND handle, LPARAM lParam)
{
	handle_data& data = *(handle_data*)lParam;
	unsigned long process_id = 0;
	GetWindowThreadProcessId(handle, &process_id);




	cout << " HWND: " << handle << " --- " << i << endl;
	i++;

	printScreen(handle);

	/*
	std::wstring s(fName);
	wchar_t val[256];

	swprintf_s(val, L"%d", i);
	wchar_t val1[256];

	s += std::wstring(val);

	swprintf_s(val1, L".png");

	s += std::wstring(val1);

	cout << "fname" << fName << endl;
	*/

	HBITMAP hBitmap = (HBITMAP)GetClipboardData(CF_BITMAP);

	

	//const wchar_t *a = s.c_str();
	//cout << "A========" << a << endl;
	saveScreenshotToDirPeriodically(L"cipa", 1,1,hBitmap);

	if (data.process_id != process_id || !is_main_window(handle)) {
		return TRUE;
	}
	data.best_handle = handle;
	return FALSE;
}

HWND find_main_window(unsigned long process_id)
{
	handle_data data;
	data.process_id = process_id;
	data.best_handle = 0;
	EnumWindows(enum_windows_callback, (LPARAM)&data);
	return data.best_handle;
}





int main()
{

	HWND handle = find_main_window(1324);
	cout << "HANDLE " << handle << endl;
	getchar();
	/*
	int out = GetClassName(
	_In_  HWND   hWnd,
	_Out_ LPTSTR lpClassName,
	_In_  int    nMaxCount
	);
	*/



	//HWND hwnd = FindWindow(TEXT("notepad"), NULL);    //the window can't be min
	HWND hwnd = handle;



	return 0;
}