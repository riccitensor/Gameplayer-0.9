// screenshoter2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#define _WIN32_WINNT    0x0501        //xp
#include <windows.h>

using namespace std;

//https://msdn.microsoft.com/en-us/library/windows/desktop/ms633522%28v=vs.85%29.aspx


struct handle_data {
	unsigned long process_id;
	HWND best_handle;
};


BOOL is_main_window(HWND handle)
{
	return GetWindow(handle, GW_OWNER) == (HWND)0 && IsWindowVisible(handle);
}

BOOL CALLBACK enum_windows_callback(HWND handle, LPARAM lParam)
{
	handle_data& data = *(handle_data*)lParam;
	unsigned long process_id = 0;
	GetWindowThreadProcessId(handle, &process_id);
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



	RECT rc;
	HWND hwnd = FindWindow(TEXT("notepad"), NULL);    //the window can't be min
	hwnd = handle;

	if (hwnd == NULL)
	{
		cout << "it can't find any 'note' window" << endl;
		return 0;
	}
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

	cout << "success copy to clipboard, please paste it to the 'mspaint'" << endl;

	return 0;
}