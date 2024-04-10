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

    uint64_t dwBegin  = 0;
    uint64_t dwEnd    = 0;
    uint64_t dwTics   = 0;
    int      nRet     = 0;

    LONGLONG start    = 0;
    LONGLONG finish   = 0;
    LONGLONG Duration = 0;

    TCHAR szMessage[100];

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_JALAB2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
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

    dwBegin = GetNowTickCount();
    nRet = FindChar_1();
    dwEnd = GetNowTickCount();
    dwTics = dwEnd - dwBegin;
    wsprintf(szMessage, L"Char J found in string: %d Tics number: %lu", nRet, (LONG)dwTics);
    MessageBox(NULL,szMessage, L"FindChar_1", MB_OK);

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

    if (FindChar_3(szString))                                   // wywo³anie procedury FindChar_3() z biblioteki JAAsm.lib
      MessageBox(NULL, L"Found J", L"FindChar_3", MB_OK);
    else
      MessageBox(NULL, L"Not Found J", L"FindChar_3", MB_OK);

    if (FindChar_4())                                           // wywo³anie procedury FindChar_4() z biblioteki JAAsm.lib
      MessageBox(NULL, L"Found J", L"FindChar_4", MB_OK);
    else
      MessageBox(NULL, L"Not Found J", L"FindChar_4", MB_OK);

    if (FindChar_5())                                           // wywo³anie procedury FindChar_5() z biblioteki JAAsm.lib
      MessageBox(NULL, L"Found J", L"FindChar_5", MB_OK);
    else
      MessageBox(NULL, L"Not Found J", L"FindChar_5", MB_OK);

    if (FindChar_6())                                           // wywo³anie procedury FindChar_6() z biblioteki JAAsm.lib
      MessageBox(NULL, L"Found J", L"FindChar_6", MB_OK);
    else
      MessageBox(NULL, L"Not Found J", L"FindChar_6", MB_OK);

    if (FindChar_7())                                           // wywo³anie procedury FindChar_7() z biblioteki JAAsm.lib
      MessageBox(NULL, L"Found J", L"FindChar_7", MB_OK);
    else
      MessageBox(NULL, L"Not Found J", L"FindChar_7", MB_OK);

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

    return (int) msg.wParam;
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

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_JALAB2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_JALAB2);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
