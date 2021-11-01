#include "pch.h"
#pragma comment(lib, "netapi32.lib")
#ifndef UNICODE
#define UNICODE
#endif
#include <stdio.h>
#include <windows.h> 
#include <lm.h>
BOOL CreateUser(PWSTR pszName, PWSTR pszPassword) {
	USER_INFO_1 ui = { 0 };
	NET_API_STATUS nStatus;
	ui.usri1_name = pszName; // имя пользователя
	ui.usri1_password = pszPassword; // пароль пользователя
	ui.usri1_priv = USER_PRIV_USER; // обычный пользователь
	nStatus = NetUserAdd(NULL, 1, (LPBYTE)&ui, NULL);
	return (nStatus == NERR_Success);
}
void main() {
	if (!CreateUser(L"ExpUser", L"123"))
		printf("A system error has occurred");
}