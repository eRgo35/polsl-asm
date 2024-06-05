// JALab3.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "JALab3.h"

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

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_JALAB3, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    TCHAR szMessage[1000];

    /************************************************************************************************/
    // Call the MyProc1 assembler procedure from the JALib1.dll library in static mode
    int  a1 = 3, b1 = 4, z1 = 0;

    z1 = MyProc1(a1, b1);   // Call MyProc1 from the JALib1.dll library in static mode

    wsprintf(szMessage, L"MyProc1: %d", z1, MB_OK);
    MessageBox(NULL, szMessage, L"MyProc1", MB_OK);

    /************************************************************************************************/

    int a2 = 1;
    int b2 = 2;
    int c2 = 3;
    int d2 = 4;
    int e2 = 5;
    int f2 = 6;
    int z2 = 0;
    z2 = MyProc2(a2, b2, c2, d2, e2, f2);

    wsprintf(szMessage, L"MyProc2: %d", z2, MB_OK);
    MessageBox(NULL, szMessage, L"MyProc2", MB_OK);

    float a3 = 0.1;
    double b3 = 0.0001;
    float c3 = 0.2;
    double d3 = 3.1415;
    float e3 = 6.3;
    float f3 = 6.1;
    int z3 = 100;
    z3 = MyProc3(a3, b3, c3, d3, e3, f3);

    wsprintf(szMessage, L"MyProc3: %d", z3, MB_OK);
    MessageBox(NULL, szMessage, L"MyProc3", MB_OK);

    int a4 = 2;
    double b4 = 0.1;
    int c4 = 3;
    float d4 = 0.2;
    int e4 = 4;
    float f4 = 0.3;
    int z4 = 0;
    z4 = MyProc4(a4, b4, c4, d4, e4, f4);

    wsprintf(szMessage, L"MyProc4: %d", z4, MB_OK);
    MessageBox(NULL, szMessage, L"MyProc4", MB_OK);

    int z5    = 0;
    __m64 a5  = _mm_set_pi64x(0x123456LL);
    __m128 b5 = _mm_set_ps(4.0f, 3.0f, 2.0f, 1.0f);

    z5 = MyProc5(a5, b5);

    wsprintf(szMessage, L"MyProc5: %d", z5, MB_OK);
    MessageBox(NULL, szMessage, L"MyProc5", MB_OK);

    BYTE buffer[256];
    memset(buffer, 'A', sizeof(buffer));
    buffer[sizeof(buffer) - 1] = '\0';

    ModifyBuffer(buffer);

    wsprintf(szMessage, L"Bufor: %S", buffer, MB_OK);
    MessageBox(NULL, szMessage, L"Bufor", MB_OK);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_JALAB3));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_JALAB3));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_JALAB3);
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
