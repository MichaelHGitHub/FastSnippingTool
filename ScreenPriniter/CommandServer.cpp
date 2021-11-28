

#include "stdafx.h"

#include <Windows.h>
#include "CommandServer.h"
#include "llhook.h"


namespace
{
	BOOL CALLBACK EnumWindowsProc(_In_  HWND hwnd, _In_  LPARAM lParam);

	BOOL CALLBACK EnumChildWindowProc(_In_ HWND hwnd, _In_ LPARAM lParam);

}

CommandServer::CommandServer(LPCWCHAR szWindowClass, LPCWCHAR szWindowTile):
	MessageProxy(szWindowClass, szWindowTile),
	isValid(false),
	hLastTopWindow(NULL)
{
	if(::IsWindow(GetWindowHandle()))
	{
		isValid = InstallKeyboardHook(GetWindowHandle());
	}
}


CommandServer::~CommandServer()
{
	UnisntallKeyboardHook();
}

LRESULT CommandServer::HandleMessages(UINT msg, WPARAM wParam, LPARAM lParam, bool& isHandled)
{
	LRESULT result = FALSE;
		switch(msg)
		{
		case MSG_COMMAND_1:
			printCommand.Execute();
			isHandled = true;
			break;

		default:

			break;

		}
	return result;
}
