
#pragma once

#include<Windows.h>
#include "MessageProxy.h"
#include "PrintScreenCommand.h"

class CommandServer : public MessageProxy
{
public:
	CommandServer(LPCWCHAR szWindowClass, LPCWCHAR szWindowTile);
	~CommandServer();

	LRESULT virtual HandleMessages(UINT msg, WPARAM wParam, LPARAM lParam, bool& isHandled);
	bool IsValid() { return isValid; }
private:

	PrintScreenCommand printCommand;
	HWND hLastTopWindow;

	bool isValid;

};