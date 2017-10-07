#pragma once
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <string.h>
#include <string>








#define CODES \
__asm _emit 0xff \
__asm _emit 0xd4 \
__asm _emit 0xaa \
__asm _emit 0xac \
__asm _emit 0xcb \
__asm _emit 0x83 \




#define _CODE_junk(p) __asm jmp p CODES __asm p:



class Junk {
	public:
		void BestCode();
};

