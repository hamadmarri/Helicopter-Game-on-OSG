//	See main.cpp file header for credits
// RotorNaeutral class inherites from Command class. The main purpose of this class is to set the natural variable of
// a rotor. It has tow main functions, a constructor and a boolean function to set the natural of a rotor and return
// true or false.
//
//	created by Hamad Almarri
//	modified by Fares Alotaibi
//


#ifndef __HelicopterProject__RotorNeutral_h__
#define __HelicopterProject__RotorNeutral_h__

#include "Command.h"
#include "Rotor.h"

// inhertance from Command class
class RotorNeutral : public Command {
public:
	RotorNeutral(Rotor *rotor);         // a constructor passing an instance of a rotor
	bool execute();                     // execute boolean function to make sure if natural variable set or not
	
private:            // one private member rotor 
	Rotor *rotor;
};

#endif 
