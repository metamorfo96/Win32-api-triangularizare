#include <windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include"resource.h"

struct point
{
	float x;
	float y;
};

WNDCLASSEX wc, wc2, wc3;
HWND hwnd, start, help, X, Y;
MSG Msg;
HINSTANCE _hIstance;
int _nCmdShow, n, x_dim = 5;
point *a;
bool visit_help_menu = false;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK WndProc2(HWND, UINT, WPARAM, LPARAM);
void verify_and_append(char *, char *);
float arie();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	_hIstance = hInstance;
	_nCmdShow = nCmdShow;

	//Window Class

	// Main Window (wc)
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszClassName = "myWindowClass";
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MYMENU);
	
	// Start Window (wc2)
	wc2.cbSize = sizeof(WNDCLASSEX);
	wc2.style = 0;
	wc2.lpfnWndProc = WndProc2;
	wc2.cbClsExtra = 0;
	wc2.cbWndExtra = 0;
	wc2.hInstance = hInstance;
	wc2.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc2.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc2.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc2.lpszClassName = "myWindowClass2";
	wc2.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
//	wc2.lpszMenuName = MAKEINTRESOURCE(IDR_MYMENU);
	
	if (!RegisterClassEx(&wc) || !RegisterClassEx(&wc2))
	{
		MessageBox(NULL, "Window Registration Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	//  Creating the Window
	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE, "myWindowClass", "Triangularizarea poligoanelor simpe", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 640, 320, NULL, NULL, hInstance, NULL);

	if (hwnd == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	a = (point*)malloc(x_dim*sizeof(point));

	// The Message Loop
	while (GetMessage(&Msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{

	switch (msg)
	{

	case WM_PAINT:
	{
					 HFONT hfont;

					 PAINTSTRUCT ps;
					 HDC hdc = BeginPaint(hwnd, &ps);

					 hfont = CreateFont(36, 22, 0, 0, FW_DONTCARE, FALSE, TRUE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
						 CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Times New Roman"));
					 SelectObject(hdc, hfont);

					 TextOut(hdc, 290, 30, launcher1, strlen(launcher1));
					 TextOut(hdc, 355, 70, launcher2, strlen(launcher2));
					 TextOut(hdc, 220, 110, launcher3, strlen(launcher3));
					 TextOut(hdc, 310, 150, launcher4, strlen(launcher4));

					 DeleteObject(hfont);
					 EndPaint(hwnd, &ps);
					 break;

	}

	case WM_CREATE:
	{
					  HWND B1 = CreateWindow("Button", "Start", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 30, 30, 150, 40, hwnd, (HMENU)BUTTON_START, NULL, NULL);
					  HWND B2 = CreateWindow("Button", "Options", WS_CHILD | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 30, 80, 150, 40, hwnd, (HMENU)BUTTON_OPTIONS, NULL, NULL);
					  HWND B3 = CreateWindow("Button", "Exit", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 30, 130, 150, 40, hwnd, (HMENU)BUTTON_EXIT, NULL, NULL);

					  break;
	}

	case WM_CLOSE:
	{
					 if (MessageBox(hwnd, "Are you sure ?", "Exit", MB_YESNO | MB_ICONQUESTION) == IDYES)
					 {
						 DestroyWindow(hwnd);
						 exit(1);
					 }
					 else
						 break;
	}

	case WM_DESTROY:
	{
					   PostQuitMessage(0);
					   break;
	}

	case WM_COMMAND:
	{
					   int wmId = LOWORD(wParam);
					   int wmEvent = HIWORD(wParam);

					   switch (wmId)
					   {

					   case ID_FILE_EXIT:
					   {
											if (MessageBox(hwnd, "Are you sure ?", "Exit", MB_YESNO | MB_ICONQUESTION) == IDYES)
												exit(1);
					   }

					   case ID_STUFF_HELP:
					   {
											 //AICI o sa pun istructiunile cand va fi sa fi facut ceva...

											 break;
					   }

					   case ID_STUFF_ABOUT:
					   {
											  MessageBox(hwnd, s, "About..", MB_OK);
											  break;
					   }

					   case BUTTON_START:
					   {
									//		MessageBox(hwnd, "Ai apasat start!", "Start", MB_OK);
											

											start = CreateWindowEx(WS_EX_CLIENTEDGE, "myWindowClass2", "Start", WS_OVERLAPPEDWINDOW,
												100, 100, 1280, 900, hwnd, NULL, _hIstance, NULL);

											ShowWindow(start, _nCmdShow);
											UpdateWindow(start);

											break;
					   }

					   case BUTTON_OPTIONS:
					   {
											  MessageBox(hwnd, "Ai apasat options!", "Options", MB_OK);
											  break;
					   }

					   case BUTTON_EXIT:
					   {
										   if (MessageBox(hwnd, "Are you sure ?", "Exit", MB_YESNO | MB_ICONQUESTION) == IDYES)
											   exit(1);
					   }


					   }

	}

	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}


LRESULT CALLBACK WndProc2(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{

	case WM_PAINT:
	{
					 PAINTSTRUCT ps;
					 HDC hdc = BeginPaint(start, &ps);
					 
					 HPEN hPenOld;
					 HPEN hLinePen;
					 COLORREF qLineColor;
					 qLineColor = RGB(255, 0, 0);
					 hLinePen = CreatePen(PS_SOLID, 7, qLineColor);
					 hPenOld = (HPEN)SelectObject(hdc, hLinePen);

					 MoveToEx(hdc, 400, 360, NULL);
					 LineTo(hdc, 1200, 360);

					 MoveToEx(hdc, 800, 60, NULL);
					 LineTo(hdc, 800, 660);

					 SelectObject(hdc, hPenOld);
					 DeleteObject(hLinePen);

					 HFONT hfont;

					 hfont = CreateFont(36, 22, 0, 0, 1000, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
						 CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Times New Roman"));
					 SelectObject(hdc, hfont);

					 SetTextColor(hdc, RGB(255, 0, 0));
					 TextOut(hdc, 1200, 342, ">", 1);
					 TextOut(hdc, 787, 55, "^", 1);
					 
					 hfont = CreateFont(72, 44, 0, 0, 1000, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
						 CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Times New Roman"));
					 SelectObject(hdc, hfont);

					 SetTextColor(hdc, RGB(0, 0, 255));
					 TextOut(hdc, 50, 750, "REZULTAT : ", 10);
					 
					 /*
					 hfont = CreateFont(2, 2, 0, 0, 0, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
						 CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Times New Roman"));
					 SelectObject(hdc, hfont);

					 SetTextColor(hdc, RGB(0, 0, 255));
					 TextOut(hdc, 800, 360, "x", 1);
					 */

					 hfont = CreateFont(26, 12, 0, 0, 1000, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
						 CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Times New Roman"));
					 SelectObject(hdc, hfont);

					 SetTextColor(hdc, RGB(0, 0, 0));
					 TextOut(hdc, 10, 10, "Coordonate : ", 13);
					 TextOut(hdc, 70, 50, "X                Y", 20);
					 
					 DeleteObject(hfont);
					
					 EndPaint(hwnd, &ps);

					 break;
	}

	case WM_CREATE:
	{

					  HWND B_CALC = CreateWindow("Button", "Calcul", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 30, 640, 100, 30, hwnd, (HMENU)BUTTON_CALC, NULL, NULL);
					  HWND B_RESET = CreateWindow("Button", "RESET", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 160, 640, 100, 30, hwnd, (HMENU)BUTTON_RESET, NULL, NULL);

					  X = CreateWindow("Edit", "", WS_BORDER | WS_CHILD | WS_VISIBLE, 55, 80, 50, 25, hwnd, (HMENU)BUTTON_X, NULL, NULL);
					  Y = CreateWindow("Edit", "", WS_BORDER | WS_CHILD | WS_VISIBLE, 188, 80, 50, 25, hwnd, (HMENU)BUTTON_Y, NULL, NULL);

					  HWND B_GET_POINT = CreateWindow("Button", "Get Point", WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 95, 120, 100, 30, hwnd, (HMENU)BUTTON_GET_POINT, NULL, NULL);


	}

	case WM_COMMAND:
	{
					   int wmId = LOWORD(wParam);
					   int wmEvent = HIWORD(wParam);

					   switch (wmId)
					   {

					   case BUTTON_GET_POINT:
					   {
												int k1 = 0, k2 = 0;
												char buff1[8], buff2[8];
												k1 = GetWindowText(X, buff1, 8);
												k2 = GetWindowText(Y, buff2, 8);

												if (k1 == 0 || k2 == 0)
												{
													MessageBox(NULL, "Eroare introducere coordonata!", "Eroare", MB_OK);
												}
									
												verify_and_append(buff1, buff2);
												
												break;
					   }

					   case BUTTON_CALC:
					   {
										   if (n <= 2)
										   {
											   MessageBox(start, "Numar insuficient de puncte", "Error", MB_OK);
											   return DefWindowProc(hwnd, msg, wParam, lParam);
										   }

										   PAINTSTRUCT ps;
										   HDC h = GetDC(start);
										   BeginPaint(start, &ps);
										   
										   HPEN hPenOld;
										   HPEN hLinePen;
										   COLORREF qLineColor;
										   qLineColor = RGB(0, 0, 0);
										   hLinePen = CreatePen(PS_SOLID, 2, qLineColor);
										   hPenOld = (HPEN)SelectObject(h, hLinePen);

										   for (int i = 0; i < n; i++)
										   {
											   MoveToEx(h, 800+a[i].x*DIM, 360-a[i].y*DIM, NULL);
											   LineTo(h, 800 + a[(i+1)%n].x * DIM, 360 - a[(i+1)%n].y * DIM);
										   }

										   SelectObject(h, hPenOld);
										   DeleteObject(hLinePen);

										   float resoult = arie();
										   char _resoult[10];
										   sprintf(_resoult, "%g", resoult);
										   HFONT hfont = CreateFont(72, 44, 0, 0, 1000, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
											   CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Times New Roman"));
										   SelectObject(h, hfont);

										   SetTextColor(h, RGB(0, 0, 255));
										   TextOut(h, 800, 750, _resoult, strlen(_resoult));
										   
										   EndPaint(start, &ps);

										   break;
					   }

					   default:break;

					   }
	}
		
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}

	return 0;
}

void verify_and_append(char *x, char *y)
{
	if (n == MAX_POINTS)
	{
		MessageBox(start, "Ai atins numarul maxim de numere in sistem", "Error", MB_OK);
		return;
	}

	int i;

	for (i = 0; i < strlen(x);i++)
	if (strchr("1234567890-", x[i]) == NULL)
	{
		MessageBox(start, "Coordonate incorecte pe X", "Error", MB_OK);
		return;
	}

	for (i = 0; i < strlen(y); i++)
	if (strchr("1234567890-", y[i]) == NULL)
	{
		MessageBox(start, "Coordonate incorecte pe Y", "Error", MB_OK);
		return;
	}

	float _x = atof(x);
	float _y = atof(y);

	if (_x>MAX_X || _x<-MAX_X )
	{
		MessageBox(start, "Ai depasit limita graficului pe X", "Error", MB_OK);
		return;
	}

	if (_y>MAX_Y || _y < -MAX_Y)
	{
		MessageBox(start, "Ai depasit limita graficului pe Y", "Error", MB_OK);
		return;
	}

	for (i = 0; i < n;i++)
	if (a[i].x == _x && a[i].y == _y)
	{
		MessageBox(start, "Punctul exista deja in sistem", "Error", MB_OK);
		return;
	}

	a[n].x = _x;
	a[n].y = _y;

	static int pas = 170;
	static int nr = 1;

	PAINTSTRUCT ps;
	HDC h = GetDC(start);
	BeginPaint(start, &ps);

	char text[50];
	sprintf(text, "Puctul %d : x=%g  y=%g ", nr++, a[n].x, a[n].y);

	TextOut(h, 30, pas, text, strlen(text));

	pas += 20;

	EndPaint(start, &ps);

	n++;

	if (n == x_dim)
	{
		x_dim++;
		a = (point*)realloc(a, x_dim*sizeof(point));
	}
	
}

float arie()
{
	int i;
	float sum = 0;

	for (i = 0; i < n; i++)
		sum += (a[i].x*a[(i + 1) % n].y - a[(i + 1) % n].x*a[i].y);


	return abs(sum / 2);

}