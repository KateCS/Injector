#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <string.h>
#include <string>
#include "JunkDefination.h"



/*
	Credits :
		http://www.youtube.com/KateCSGO
		https://www.unknowncheats.me/forum/cs-go-releases/227007-random-injector.html

*/


/* 
	Paste This
	_CODE_junk(jmp_label1)
*/


/////////////////////////////////////////////////////////////////////////////////////
//                                Kate's Injector                                  //
/////////////////////////////////////////////////////////////////////////////////////

using namespace std; //dont forget this

DWORD Process(char* ProcessName)
{
	Junk Junky;        //New Object Defined
	Junky.BestCode();  //Object Usage

	_CODE_junk(jmp_label1)//junk1
		Junky.BestCode();
		HANDLE hPID = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);

	_CODE_junk(jmp_label2)//junk2

	PROCESSENTRY32 ProcEntry;
	_CODE_junk(jmp_label3)
	ProcEntry.dwSize = sizeof(ProcEntry);
	do
	{
		if (!strcmp(ProcEntry.szExeFile, ProcessName))
		{
			DWORD dwPID = ProcEntry.th32ProcessID;
			CloseHandle(hPID);
			return dwPID;
		}
	}
	while (Process32Next(hPID, &ProcEntry));
		
}



int main()
{
	char dllname[20];
	char processname[20];
	string lastcheck;
	cout << "//////////////////////////////////////////////////////////////////////////" << endl;
	cout << "///                                                                    ///" << endl;
	cout << "///                            KATE'S INJECTOR                         ///" << endl;
	cout << "///                                                                    ///" << endl;
	cout << "//////////////////////////////////////////////////////////////////////////" << endl;
	cout << endl;
	cout << "Enter the dll name" << endl;
	cin >> dllname;
	cout << "Enter the process name" << endl;
	cin >> processname;
	cout << endl << "dllname        ->    " << dllname;
	cout << endl << "processname    ->    " << processname;
	cout << endl;
	cout << endl << "Inject? (Y/N) "<< endl;
	cin >> lastcheck;
	
	if (lastcheck == "y"
		|| lastcheck == "Y"
		) {
		DWORD dwProcess;
		char myDLL[MAX_PATH];
		GetFullPathName(dllname, MAX_PATH, myDLL, 0);
		dwProcess = Process(processname);
		HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, dwProcess);
		LPVOID allocatedMem = VirtualAllocEx(hProcess, NULL, sizeof(myDLL), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
		WriteProcessMemory(hProcess, allocatedMem, myDLL, sizeof(myDLL), NULL);
		CreateRemoteThread(hProcess, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibrary, allocatedMem, 0, 0);
		CloseHandle(hProcess);
		cout << "DONE" << endl;
		return 0;
	}
	else {
		string whatnow;
		cout << endl;
		cout << "Rage Quited !!" << endl;
		cin >> whatnow;
		return 0;
	}
}