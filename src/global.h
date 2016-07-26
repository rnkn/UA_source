#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#ifdef GLOBAL

#define EXTR

#else

#define EXTR extern

#endif // GLOBAL

#include "glob_funcs.h"

EXTR HINSTANCE ghInstance;
EXTR int gCmdShow;
EXTR HWND ghWnd;
EXTR LPSTR gpcmdline;

EXTR char cmdline_copy[512];


EXTR g_engines engines;

EXTR nlist modes_list;
EXTR nlist graph_drivers_list;

EXTR int can_srcblend;
EXTR int can_destblend;
EXTR int can_stippling;

extern int dword_514EFC;
EXTR int dword_514F24;
EXTR HIMC dword_514F1C;

EXTR UserData userdata;
EXTR struC5 input_states;
EXTR base_64arg world_update_arg;

EXTR NC_STACK_ypaworld *ypaworld;
EXTR int dword_520400;


#endif // GLOBAL_H_INCLUDED1
