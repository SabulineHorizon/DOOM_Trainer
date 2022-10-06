#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <TlHelp32.h>
#include <math.h>
#include <sys/stat.h>
#include <Dbghelp.h>
#include <Commctrl.h>
#include <string>
#include <fstream>
#include <vector>

#include "resource.h"
#include "memory.h"

#pragma comment(lib, "Winmm.lib")
#pragma comment(lib, "Dbghelp.lib")
#pragma comment(lib, "Comctl32.lib")

#define WIDTH 185
#define HEIGHT 300
#define PI 3.141592653589793f

#define ClearKeybind(k, i) Keybind((short *)&k, 0, 0, 0); SetTextFromKeybind(hDlg, i, k); active_id = 0; memset(&keybind, 0, sizeof(keybind)); SetKeybinds(&keybinds);

using std::string;

typedef struct {
	short forward[4], backward[4], left[4], right[4], up[4], down[4], increase[4], decrease[4], god[4], ammo[4], fly[4], timer[4], time_increase[4], time_decrease[4], time_reset[4], rewind[4], kill[4], doublejump[4];
	short save[5][4];
	short load[5][4];
	short test_save[1][4];
	short test_load[1][4];
} KEYBINDS;

typedef struct {
	char player[24];
	float fz;
	char camera[8];
} SAVE;

typedef struct {
	char player[24];
	float fz;
	char camera[8];
} REWIND;

void Update();
void Listener();
void SetKeybinds(KEYBINDS* k);
string SetConfigPath(char* path, string directory = "", string filename = "");
HWND MakeWindowFromCenter(HWND hWndtemp, int offsetx = 0, int offsety = 0);
KEYBINDS GetKeybinds();
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK KeyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam);