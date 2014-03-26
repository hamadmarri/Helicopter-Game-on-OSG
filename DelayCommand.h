//	See main.cpp file header for credits

#ifndef __HelicopterProject__DelayCommand__
#define __HelicopterProject__DelayCommand__

#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "Command.h"


class DelayCommand : public Command {
public:
	DelayCommand(float seconds);
	bool execute();
	
private:
	float seconds;
};

#endif /* defined(__HelicopterProject__DelayCommand__) */
