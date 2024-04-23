/**********************************************************************************************
 *                              JA Æwiczenie laboratoryjne 2                                  *
 *                                                                                            *
 *   Temat: Sposoby adresacji procesora x86 w trybie x86                                      *
 *                                                                                            *
 *   Zadanie:                                                                                 *
 *   1. Porówaæ ró¿ne metody adresacji stringu szString[] w celu wyznaczenia najszybszego     *
 *      dostêpu do elementu bufora pamiêci                                                    *
 *   2. Zaproponowaæ w³asne rozwi¹zanie wyszukania znaku 'J' w stringu tak aby liczba taktów  *
 *      procesora by³a najmniejsza. Kod ASM wpisaæ do procedury FindChar7 w pliku JAAsm.asm   *
 *                                                                                            *
 **********************************************************************************************/


#include "framework.h"
#include "JALab2.h"

#pragma intrinsic(__rdtsc)

#define MAX_LOADSTRING 100

 // Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.

	uint64_t dwBegin = 0;
	uint64_t dwEnd = 0;
	uint64_t dwTics = 0;
	int      nRet = 0;

	LONGLONG start = 0;
	LONGLONG finish = 0;
	LONGLONG Duration = 0;

	TCHAR szMessage[1000];

	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_JALAB2, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_JALAB2));


	/*************************************** JALab2 ***********************************************/

	BYTE szString[] = { '0','1','2','3','4','5','6','7','8','9','0','0','1','2','3','4','5','6','7','8','9','A','J','B','C', 0xFF };

	/**********************************************************************************************
	 *
	 *   Metody pomiaru czasu wykonania kodu maszynowego dla procesorów x86:
	 *   1. Funkcja GetNowTickCount ()
	 *   2. Funkcja PeroformanceCounter ()
	 *   3. rozkaz RDTSC wynik pomiaru dla x86 w rejestrach EDX:EAX wykorzystywany w
	 *      programach typu CPUID do wyliczania benchmarków procesorów
	 *
	 *   Funkcje daj¹ ró¿ne wyniki zale¿ne od wyliczania czasu procesora w œrodowisku
	 *   wielozadaniowego systemu operacyjnego np. Windows
	 *
	 *********************************************************************************************/

	//start = __rdtsc();
	//int nRet1 = FindChar_1();
	//LONGLONG finish1 = __rdtsc();
	//int nRet2 = FindChar_2();
	//LONGLONG finish2 = __rdtsc();
	//int nRet3 = FindChar_3(szString);
	//LONGLONG finish3 = __rdtsc();
	//int nRet4 = FindChar_4();
	//LONGLONG finish4 = __rdtsc();
	//int nRet5 = FindChar_5();
	//LONGLONG finish5 = __rdtsc();
	//int nRet6 = FindChar_6();
	//LONGLONG finish6 = __rdtsc();
	//int nRet7 = FindChar_7();
	//LONGLONG finish7 = __rdtsc();

	//uint64_t dwBegin1 = GetNowTickCount();
	//int nRet11 = FindChar_1(); 
	//uint64_t dwEnd1 = GetNowTickCount();
	//int nRet12 = FindChar_2();
	//uint64_t dwEnd2 = GetNowTickCount();
	//int nRet13 = FindChar_3(szString);
	//uint64_t dwEnd3 = GetNowTickCount();
	//int nRet14 = FindChar_4();
	//uint64_t dwEnd4 = GetNowTickCount();
	//int nRet15 = FindChar_5();
	//uint64_t dwEnd5 = GetNowTickCount();
	//int nRet16 = FindChar_6();
	//uint64_t dwEnd6 = GetNowTickCount();
	//int nRet17 = FindChar_7();
	//uint64_t dwEnd7 = GetNowTickCount();

	//uint64_t dwTics1 = dwEnd1 - dwBegin1;
	//uint64_t dwTics2 = dwEnd2 - dwEnd1;
	//uint64_t dwTics3 = dwEnd3 - dwEnd2;
	//uint64_t dwTics4 = dwEnd4 - dwEnd3;
	//uint64_t dwTics5 = dwEnd5 - dwEnd4;
	//uint64_t dwTics6 = dwEnd6 - dwEnd5;
	//uint64_t dwTics7 = dwEnd7 - dwEnd6;

	//LONGLONG Duration1 = finish1 - start;
	//LONGLONG Duration2 = finish2 - finish1;
	//LONGLONG Duration3 = finish3 - finish2;
	//LONGLONG Duration4 = finish4 - finish3;
	//LONGLONG Duration5 = finish5 - finish4;
	//LONGLONG Duration6 = finish6 - finish5;
	//LONGLONG Duration7 = finish7 - finish6;

	//LONGLONG start01 = PerformanceCounter();
	//int nRet01 = FindChar_1();
	//LONGLONG finish01 = PerformanceCounter();
	//int nRet02 = FindChar_2();
	//LONGLONG finish02 = PerformanceCounter();
	//int nRet03 = FindChar_3(szString);
	//LONGLONG finish03 = PerformanceCounter();
	//int nRet04 = FindChar_4();
	//LONGLONG finish04 = PerformanceCounter();
	//int nRet05 = FindChar_5();
	//LONGLONG finish05 = PerformanceCounter();
	//int nRet06 = FindChar_6();
	//LONGLONG finish06 = PerformanceCounter();
	//int nRet07 = FindChar_7();
	//LONGLONG finish07 = PerformanceCounter();
	//
	//LONGLONG Duration11 = finish01 - start01;
	//LONGLONG Duration12 = finish02 - finish01;
	//LONGLONG Duration13 = finish03 - finish02;
	//LONGLONG Duration14 = finish04 - finish03;
	//LONGLONG Duration15 = finish05 - finish04;
	//LONGLONG Duration16 = finish06 - finish05;
	//LONGLONG Duration17 = finish07 - finish06;

	//TCHAR szMessage1[100];
	//TCHAR szMessage2[100];
	//TCHAR szMessage3[100];
	//TCHAR szMessage4[100];
	//TCHAR szMessage5[100];
	//TCHAR szMessage6[100];
	//TCHAR szMessage7[100];

	//wsprintf(szMessage1, L"J: %d; GetNowTickCount(): %lu; PerformanceCounter(): %lu; __rdtsc: %lu", nRet1, (LONG)dwTics1, (ULONG)Duration11, (ULONG)Duration1);
	//wsprintf(szMessage2, L"J: %d; GetNowTickCount(): %lu; PerformanceCounter(): %lu; __rdtsc: %lu", nRet2, (LONG)dwTics2, (ULONG)Duration12, (ULONG)Duration2);
	//wsprintf(szMessage3, L"J: %d; GetNowTickCount(): %lu; PerformanceCounter(): %lu; __rdtsc: %lu", nRet3, (LONG)dwTics3, (ULONG)Duration13, (ULONG)Duration3);
	//wsprintf(szMessage4, L"J: %d; GetNowTickCount(): %lu; PerformanceCounter(): %lu; __rdtsc: %lu", nRet4, (LONG)dwTics4, (ULONG)Duration14, (ULONG)Duration4);
	//wsprintf(szMessage5, L"J: %d; GetNowTickCount(): %lu; PerformanceCounter(): %lu; __rdtsc: %lu", nRet5, (LONG)dwTics5, (ULONG)Duration15, (ULONG)Duration5);
	//wsprintf(szMessage6, L"J: %d; GetNowTickCount(): %lu; PerformanceCounter(): %lu; __rdtsc: %lu", nRet6, (LONG)dwTics6, (ULONG)Duration16, (ULONG)Duration6);
	//wsprintf(szMessage7, L"J: %d; GetNowTickCount(): %lu; PerformanceCounter(): %lu; __rdtsc: %lu", nRet7, (LONG)dwTics7, (ULONG)Duration17, (ULONG)Duration7);

	//wsprintf(szMessage, L"%s\n%s\n%s\n%s\n%s\n%s\n%s",
	//	szMessage1, szMessage2, szMessage3, szMessage4, szMessage5, szMessage6, szMessage7);

	//MessageBox(NULL, szMessage, L"All", MB_OK);
	
	
	/*if (FindChar_1())                                           // wywo³anie procedury FindChar_1() z biblioteki JAAsm.lib
		MessageBox(NULL, L"Found J", L"FindChar_2", MB_OK);
	else
		MessageBox(NULL, L"Not Found J", L"FindChar_2", MB_OK);

	dwBegin = GetNowTickCount();
	nRet = FindChar_1();
	dwEnd = GetNowTickCount();
	dwTics = dwEnd - dwBegin;
	wsprintf(szMessage, L"Char J found in string: %d Tics number: %lu", nRet, (LONG)dwTics);
	MessageBox(NULL, szMessage, L"FindChar_1", MB_OK);

	start = PerformanceCounter();                               // Record start time
	nRet = FindChar_1();
	finish = PerformanceCounter();                              // Record end time
	Duration = finish - start;                                  // liczba tików zegarowych x86
	wsprintf(szMessage, L"Char J found in string: %d Tics number: %lu", nRet, (ULONG)Duration);
	MessageBox(NULL, szMessage, L"FindChar_1", MB_OK);

	start = __rdtsc();
	nRet = FindChar_1();
	finish = __rdtsc();
	Duration = finish - start;                                  // liczba tików zegarowych x86
	wsprintf(szMessage, L"Char J found in string: %d Tics number: %lu", nRet, (ULONG)Duration);
	MessageBox(NULL, szMessage, L"FindChar_1", MB_OK);

	if (FindChar_2())                                           // wywo³anie procedury FindChar_2() z biblioteki JAAsm.lib
		MessageBox(NULL, L"Found J", L"FindChar_2", MB_OK);
	else
		MessageBox(NULL, L"Not Found J", L"FindChar_2", MB_OK);

	dwBegin = GetNowTickCount();
	nRet = FindChar_2();
	dwEnd = GetNowTickCount();
	dwTics = dwEnd - dwBegin;
	wsprintf(szMessage, L"Char J found in string: %d Tics number: %lu", nRet, (LONG)dwTics);
	MessageBox(NULL, szMessage, L"FindChar_2", MB_OK);

	start = PerformanceCounter();                               // Record start time
	nRet = FindChar_2();
	finish = PerformanceCounter();                              // Record end time
	Duration = finish - start;                                  // liczba tików zegarowych x86
	wsprintf(szMessage, L"Char J found in string: %d Tics number: %lu", nRet, (ULONG)Duration);
	MessageBox(NULL, szMessage, L"FindChar_2", MB_OK);

	start = __rdtsc();
	nRet = FindChar_2();
	finish = __rdtsc();
	Duration = finish - start;                                  // liczba tików zegarowych x86
	wsprintf(szMessage, L"Char J found in string: %d Tics number: %lu", nRet, (ULONG)Duration);
	MessageBox(NULL, szMessage, L"FindChar_2", MB_OK);

	if (FindChar_3(szString))                                   // wywo³anie procedury FindChar_3() z biblioteki JAAsm.lib
		MessageBox(NULL, L"Found J", L"FindChar_3", MB_OK);
	else
		MessageBox(NULL, L"Not Found J", L"FindChar_3", MB_OK);

	dwBegin = GetNowTickCount();
	nRet = FindChar_3(szString);
	dwEnd = GetNowTickCount();
	dwTics = dwEnd - dwBegin;
	wsprintf(szMessage, L"Char J found in string: %d Tics number: %lu", nRet, (LONG)dwTics);
	MessageBox(NULL, szMessage, L"FindChar_3", MB_OK);

	start = PerformanceCounter();                               // Record start time
	nRet = FindChar_3(szString);
	finish = PerformanceCounter();                              // Record end time
	Duration = finish - start;                                  // liczba tików zegarowych x86
	wsprintf(szMessage, L"Char J found in string: %d Tics number: %lu", nRet, (ULONG)Duration);
	MessageBox(NULL, szMessage, L"FindChar_3", MB_OK);

	start = __rdtsc();
	nRet = FindChar_3(szString);
	finish = __rdtsc();
	Duration = finish - start;                                  // liczba tików zegarowych x86
	wsprintf(szMessage, L"Char J found in string: %d Tics number: %lu", nRet, (ULONG)Duration);
	MessageBox(NULL, szMessage, L"FindChar_3", MB_OK);
	
	if (FindChar_4())                                           // wywo³anie procedury FindChar_4() z biblioteki JAAsm.lib
		MessageBox(NULL, L"Found J", L"FindChar_4", MB_OK);
	else
		MessageBox(NULL, L"Not Found J", L"FindChar_4", MB_OK);

	dwBegin = GetNowTickCount();
	nRet = FindChar_4();
	dwEnd = GetNowTickCount();
	dwTics = dwEnd - dwBegin;
	wsprintf(szMessage, L"Char J found in string: %d Tics number: %lu", nRet, (LONG)dwTics);
	MessageBox(NULL, szMessage, L"FindChar_4", MB_OK);

	start = PerformanceCounter();                               // Record start time
	nRet = FindChar_4();
	finish = PerformanceCounter();                              // Record end time
	Duration = finish - start;                                  // liczba tików zegarowych x86
	wsprintf(szMessage, L"Char J found in string: %d Tics number: %lu", nRet, (ULONG)Duration);
	MessageBox(NULL, szMessage, L"FindChar_4", MB_OK);

	start = __rdtsc();
	nRet = FindChar_4();
	finish = __rdtsc();
	Duration = finish - start;                                  // liczba tików zegarowych x86
	wsprintf(szMessage, L"Char J found in string: %d Tics number: %lu", nRet, (ULONG)Duration);
	MessageBox(NULL, szMessage, L"FindChar_4", MB_OK);
	
	if (FindChar_5())                                           // wywo³anie procedury FindChar_5() z biblioteki JAAsm.lib
		MessageBox(NULL, L"Found J", L"FindChar_5", MB_OK);
	else
		MessageBox(NULL, L"Not Found J", L"FindChar_5", MB_OK);

	dwBegin = GetNowTickCount();
	nRet = FindChar_5();
	dwEnd = GetNowTickCount();
	dwTics = dwEnd - dwBegin;
	wsprintf(szMessage, L"Char J found in string: %d Tics number: %lu", nRet, (LONG)dwTics);
	MessageBox(NULL, szMessage, L"FindChar_5", MB_OK);

	start = PerformanceCounter();                               // Record start time
	nRet = FindChar_5();
	finish = PerformanceCounter();                              // Record end time
	Duration = finish - start;                                  // liczba tików zegarowych x86
	wsprintf(szMessage, L"Char J found in string: %d Tics number: %lu", nRet, (ULONG)Duration);
	MessageBox(NULL, szMessage, L"FindChar_5", MB_OK);

	start = __rdtsc();
	nRet = FindChar_5();
	finish = __rdtsc();
	Duration = finish - start;                                  // liczba tików zegarowych x86
	wsprintf(szMessage, L"Char J found in string: %d Tics number: %lu", nRet, (ULONG)Duration);
	MessageBox(NULL, szMessage, L"FindChar_5", MB_OK);
	
	if (FindChar_6())                                           // wywo³anie procedury FindChar_6() z biblioteki JAAsm.lib
		MessageBox(NULL, L"Found J", L"FindChar_6", MB_OK);
	else
		MessageBox(NULL, L"Not Found J", L"FindChar_6", MB_OK);

	dwBegin = GetNowTickCount();
	nRet = FindChar_6();
	dwEnd = GetNowTickCount();
	dwTics = dwEnd - dwBegin;
	wsprintf(szMessage, L"Char J found in string: %d Tics number: %lu", nRet, (LONG)dwTics);
	MessageBox(NULL, szMessage, L"FindChar_6", MB_OK);

	start = PerformanceCounter();                               // Record start time
	nRet = FindChar_6();
	finish = PerformanceCounter();                              // Record end time
	Duration = finish - start;                                  // liczba tików zegarowych x86
	wsprintf(szMessage, L"Char J found in string: %d Tics number: %lu", nRet, (ULONG)Duration);
	MessageBox(NULL, szMessage, L"FindChar_6", MB_OK);

	start = __rdtsc();
	nRet = FindChar_6();
	finish = __rdtsc();
	Duration = finish - start;                                  // liczba tików zegarowych x86
	wsprintf(szMessage, L"Char J found in string: %d Tics number: %lu", nRet, (ULONG)Duration);
	MessageBox(NULL, szMessage, L"FindChar_6", MB_OK);*/
	
	if (FindChar_7())                                           // wywo³anie procedury FindChar_7() z biblioteki JAAsm.lib
		MessageBox(NULL, L"Found J", L"FindChar_7", MB_OK);
	else
		MessageBox(NULL, L"Not Found J", L"FindChar_7", MB_OK);

	dwBegin = GetNowTickCount();
	nRet = FindChar_7();
	dwEnd = GetNowTickCount();
	dwTics = dwEnd - dwBegin;
	wsprintf(szMessage, L"Char J found in string: %d Tics number: %lu", nRet, (LONG)dwTics);
	MessageBox(NULL, szMessage, L"FindChar_7", MB_OK);

	start = PerformanceCounter();                               // Record start time
	nRet = FindChar_7();
	finish = PerformanceCounter();                              // Record end time
	Duration = finish - start;                                  // liczba tików zegarowych x86
	wsprintf(szMessage, L"Char J found in string: %d Tics number: %lu", nRet, (ULONG)Duration);
	MessageBox(NULL, szMessage, L"FindChar_7", MB_OK);

	start = __rdtsc();
	nRet = FindChar_7();
	finish = __rdtsc();
	Duration = finish - start;                                  // liczba tików zegarowych x86
	wsprintf(szMessage, L"Char J found in string: %d Tics number: %lu", nRet, (ULONG)Duration);
	MessageBox(NULL, szMessage, L"FindChar_7", MB_OK);

	/*************************************** JALab2 ***********************************************/


	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_JALAB2));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_JALAB2);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code that uses hdc here...
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

LONGLONG PerformanceCounter()
{
	LARGE_INTEGER li;
	::QueryPerformanceCounter(&li);
	return li.QuadPart;
	}


#ifdef _WIN32
// get frequency of the performance counter
uint64_t GetPCFrequency()
{
	uint64_t freq = 0;
	if (!QueryPerformanceFrequency((LARGE_INTEGER*)&freq))
	{
		DWORD dwRet = GetLastError();
	}
	return freq;
}
#endif

uint64_t GetNowTickCount()
{
#ifdef _WIN32
	static uint64_t freq = GetPCFrequency();
	uint64_t now = 0;
	if (!QueryPerformanceCounter((LARGE_INTEGER*)&now))
	{
		DWORD dwRet = GetLastError();
	}
	return (now * 1000000000UL) / freq;

#else
	timespec ts;
	if (clock_gettime(CLOCK_MONOTONIC, &ts) < 0)
	{
		LOG(FATAL) << errno;
	}
	return (ts.tv_sec * 1000000000UL) + ts.tv_nsec;
#endif
}

uint64_t elapsed(uint32_t start_hi, uint32_t start_lo, uint32_t end_hi, uint32_t end_lo)
{
	uint64_t start = (((uint64_t)start_hi) << 32) | start_lo;
	uint64_t end = (((uint64_t)end_hi) << 32) | end_lo;
	return end - start;
}
