#include <iostream>
#include <Windows.h>
#include <string>
#include <process.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

HANDLE SemaF;
string message;

HANDLE In = CreateEventA(NULL, TRUE, TRUE, "Ввод");
HANDLE Out = CreateEventA(NULL, TRUE, TRUE, "Вывод");
HANDLE Ex = CreateEventA(NULL, TRUE, TRUE, "Выход");

DWORD WINAPI Writer(LPVOID)
{
	CHAR a;
	do
	{
		Sleep(2000);
		cout << "______________________________________________" << endl;
		cout << "		Чат с процессами		     		   " << endl;
		cout << "______________________________________________" << endl;
		cout << "Введите Сообщение: ";
		cout.flush();
		cin >> message;
		ResetEvent(In);
		WaitForSingleObject(Out, 1000);
		cout.flush();
		Sleep(2000);
		cout << "Хотите ввести еще одно сообщение? (+(Да) / -(Нет))";
		cin >> a;
		if (a == '+') 
		{ 
			SetEvent(In); 
		}
		else if (a == '-') 
		{
			ResetEvent(In);
			SetEvent(Ex);
		}
	}
		while (WaitForSingleObject(In, 1000) == WAIT_OBJECT_0);
		SetEvent(Ex);
		ReleaseSemaphore(SemaF, 1, NULL);
		return 0;
	}

DWORD WINAPI Administrator(LPVOID)
{
	DWORD ID1;
	HANDLE Write;
	setlocale(LC_ALL, ".1251");
	int n;
	cout << "Введите кол-во процессов для write: ";
	cin >> n;
	SemaF = CreateSemaphore(NULL, 0, n, NULL);
	for (int i = 0; i < n; i++)
	{
		SetEvent(In);
		ResetEvent(Out);
		ResetEvent(Ex);
		Write = CreateThread(NULL, 0, Writer, NULL, 0, &ID1);
		if (Writer == NULL)
		{
			cout << "The new process is not created." << endl;
			cout << "Press any key to exit." << endl;
			cin.get();
			return GetLastError();
		}
		do
		{
			if (WaitForSingleObject(In, NULL) != WAIT_OBJECT_0)
			{
				cout << message << endl;
				cout.flush();
				SetEvent(Out);
				SetEvent(In);
			}
			} while (WaitForSingleObject(Ex, 2000) != WAIT_OBJECT_0);
			WaitForSingleObject(SemaF, INFINITE);
			cout << "Writer " << i + 1 << " завершил свою работу, приходим к следующему..." << endl;
		}
	return 0;
}

int main()
{
	setlocale(LC_ALL, ".1251");
	HANDLE admin;
	DWORD ID;
	admin = CreateThread(NULL, 0, Administrator, NULL, 0, &ID);
	if (admin == NULL)
	{
		Sleep(500);
		cout << "The new process is not created." << endl;
		cout << "Press any key to exit." << endl;
		Sleep(500);
		cin.get();
		Sleep(500);
		return GetLastError();
	}
	WaitForSingleObject(admin, INFINITE);
}