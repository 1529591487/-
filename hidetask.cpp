#include <stdio.h>  
#include <iostream>
#include <windows.h>  
#include <atlstr.h>
using namespace std;
int main(int argc, char* argv[])
{
	HWND button, task,startmenu;
	
	//desktop = FindWindow(L"ProgMan", NULL);
	task = FindWindow(L"Shell_TrayWnd", NULL);  //���������ں�
	//startmenu = FindWindow(L"TrayNotifyWnd", NULL);  //��ʼ�˵����ں�
	button = FindWindow(L"button", NULL);          
	//for (int i = 0; i < 20; i+=2)
	//{
	//	startmenu = (HWND)((int)task + i);
	//	LPWSTR PerfData = (LPWSTR)malloc(255);
	//	GetClassName(startmenu, PerfData, 255);
	//	printf(CW2A(PerfData));
	//	printf("\n");
	//	system("pause");
	//	ShowWindow(startmenu, SW_SHOW);//��ʾ
	//}

	APPBARDATA apBar;
	memset(&apBar, 0, sizeof(apBar));
	apBar.cbSize = sizeof(apBar);
	apBar.hWnd = task;
	LPARAM lParam = SHAppBarMessage(ABM_GETSTATE, &apBar);
	//if (lParam == ABS_AUTOHIDE)
	//{
	//	apBar.lParam = ABS_ALWAYSONTOP;
	//	SHAppBarMessage(ABM_SETSTATE, &apBar);
	//}
	//else
	//{
	//	apBar.lParam = ABS_AUTOHIDE | ABS_ALWAYSONTOP;
	//	SHAppBarMessage(ABM_SETSTATE, &apBar);
	//}




	if (IsWindowVisible(task) || IsWindowVisible(button))
	{
		apBar.lParam = ABS_AUTOHIDE | ABS_ALWAYSONTOP;
		SHAppBarMessage(ABM_SETSTATE, &apBar);
		ShowWindow(task, SW_HIDE);//���������� 
		ShowWindow(button, SW_HIDE);//���������� 
	}
	else
	{
		ShowWindow(task, SW_SHOW);//��ʾ������ 
		ShowWindow(button, SW_SHOW);//��ʾ������ 
		Sleep(500);
		apBar.lParam = ABS_ALWAYSONTOP;
		SHAppBarMessage(ABM_SETSTATE, &apBar);
	}


	//LPRECT rect=(LPRECT)malloc(10);
	//GetWindowRect(task, rect);
	//MoveWindow(task, 0, 0, 0, 0, 0);
	//ShowWindow(desktop, SW_HIDE);//��������  
	//Sleep(3000);
	//ShowWindow(task, SW_SHOW);//��ʾ  
	//ShowWindow(desktop, SW_SHOW);//��ʾ  
	//system("pause");
	return 0;
}