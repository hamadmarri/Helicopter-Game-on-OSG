//	See main.cpp file header for credits
//
//	created by Fares Alotaibi
//	modified by Hamad Almarri
//

#ifndef __HelicopterProject__DelayCommand_h__
#define __HelicopterProject__DelayCommand_h__

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

#endif
