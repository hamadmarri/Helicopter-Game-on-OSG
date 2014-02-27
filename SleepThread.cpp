/*
	Command
		Creates a thread that will sleep for a given amount of time

		Credits: Brian Schwietzer

*/
#include "SleepThread.h"
#include <Windows.h>
#include <OpenThreads\Thread>

SleepThread::SleepThread(int time)
{
	sleepTime = time;
}

void SleepThread::run()
{
	Sleep(sleepTime * 1000);
}