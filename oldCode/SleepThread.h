/*
	Command
		Creates a thread that will sleep for a given amount of time

		Credits: Brian Schwietzer

*/

#ifndef SLEEPTHREAD_H
#define SLEEPTHREAD_H

#include <OpenThreads/Thread>

class SleepThread : public OpenThreads::Thread
{
public:
	SleepThread(int);
protected:
	virtual void run();
private:
	int sleepTime;
};

#endif