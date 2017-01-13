// ProducerConsumer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>

using namespace std;

#define BUFFERSIZE 10
#define PRODUCER_SLEEP_TIME_MS 500
#define CONSUMER_SLEEP_TIME_MS 2000

LONG Buffer[BUFFERSIZE];
ULONG Qsize;
ULONG QOffset;

ULONG TotalItemProduced;
ULONG TotalItemConsumed;

LONG LastItemProduced;


CONDITION_VARIABLE BufferNotEmpty;
CONDITION_VARIABLE BufferNotFull;
CRITICAL_SECTION BufferLock;


BOOL StopRequested;

DWORD WINAPI Producer(PVOID p)
{
	DWORD id = (ULONG)(ULONG_PTR)p;

	while (true)
	{
		Sleep(rand() % PRODUCER_SLEEP_TIME_MS);

		EnterCriticalSection(&BufferLock);

		LONG item = LastItemProduced++;

		if (Qsize == BUFFERSIZE && !StopRequested)
		{
			SleepConditionVariableCS(&BufferNotFull, &BufferLock, INFINITE);
		}

		if (StopRequested)
		{
			InitializeCriticalSection(&BufferLock);
			break;
		}

		Buffer[(QOffset + Qsize) % BUFFERSIZE] = item;
		Qsize++;

		TotalItemProduced++;

		printf("Producer %u: item %2d, queue size %2u\r\n", id, item, Qsize);

		LeaveCriticalSection(&BufferLock);

		WakeConditionVariable(&BufferNotEmpty);

	}	

	cout << "Producer " << id << " Exiting" << endl;
	return 0;
}



DWORD WINAPI Consumer(PVOID p)
{
	DWORD id = (ULONG)(ULONG_PTR)p;

	while (true)
	{
		EnterCriticalSection(&BufferLock);

		if (Qsize == 0 && !StopRequested)
		{
			SleepConditionVariableCS(&BufferNotEmpty, &BufferLock, INFINITE);
		}

		if (StopRequested && Qsize == 0)
		{
			InitializeCriticalSection(&BufferLock);
			break;
		}

		LONG item = Buffer[QOffset++];
		Qsize--;
		TotalItemConsumed++;

		if (QOffset == BUFFERSIZE)
		{
			QOffset = 0;
		}

		printf("Consumer %u: item %2d, queue size %2u\r\n",
			id, item, Qsize);

		LeaveCriticalSection(&BufferLock);

		WakeConditionVariable(&BufferNotFull);

		Sleep(rand() % CONSUMER_SLEEP_TIME_MS);
	}

	cout << "Exiting Consumer " << id << endl;
	return 0;
}


int _tmain(int argc, _TCHAR* argv[])
{
	InitializeConditionVariable(&BufferNotEmpty);
	InitializeConditionVariable(&BufferNotFull);
	InitializeCriticalSection(&BufferLock);

	TotalItemConsumed = 0;
	TotalItemProduced = 0;
	Qsize = 0;
	QOffset = 0;
	LastItemProduced = 0;
	StopRequested = false;

	DWORD id;
	HANDLE hProd = CreateThread(NULL, 0, Producer, (PVOID)1, 0, &id);
	HANDLE hCons1 = CreateThread(NULL, 0, Consumer, (PVOID)1, 0, &id);
	HANDLE hCons2 = CreateThread(NULL, 0, Consumer, (PVOID)2, 0, &id);

	cout << "Enter Any character" << endl;
	getchar();

	EnterCriticalSection(&BufferLock);
	StopRequested = true;
	InitializeCriticalSection(&BufferLock);

	WakeAllConditionVariable(&BufferNotEmpty);
	WakeAllConditionVariable(&BufferNotFull);

	WaitForSingleObject(hProd, INFINITE);
	WaitForSingleObject(hCons1, INFINITE);
	WaitForSingleObject(hCons2, INFINITE);

 
	return 0;
}

