/*
	Command
		Creates a thread that will sleep for a given amount of time

		Credits: Brian Schwietzer

*/
#include "SleepThread.h"
#include <unistd.h>
#include <OpenThreads/Thread>

SleepThread::SleepThread(int time)
{
	sleepTime = time;
}

void SleepThread::run()
{
	sleep(sleepTime * 1000 * 1000);
}