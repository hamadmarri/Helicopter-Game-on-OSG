//
//  Observable.cpp
//
//	See main.cpp file header for credits
//  This is the implementation of Obserable class, it has three mian function, add observer, delete observer , and
// a functioin to notifyall.
//
//	created by Fares Alotaibi
//	modified by Hamad Almarri
//

#include "Observable.h"

// adding an observer by looping into the observers vector and push it or add it to our vector class.
void Observable::AddObserver(Observer *observer) {
	// due to some problems with compiling find, we rathar decided to omit it out
//	auto it = std::find(this->observers.begin(), this->observers.end(), observer);
//	if (it == this->observers.end())
	this->observers.push_back(observer);
}


// removing observers by looping to our  observers vector and find it to delete it
void Observable::RemoveObserver(Observer *observer) {
	// due to some problems with compiling find, we rathar decided to omit it out
//	auto it = std::find(this->observers.begin(), this->observers.end(), observer);
//	if (it != this->observers.end())
//		this->observers.erase(it);
	
	this->observers.erase(std::remove(this->observers.begin(),
									  this->observers.end(),
									  observer
									  )
							, this->observers.end()
							);
}


// notifyAll function to loop through the observers vector and call the update function that was implemented in
// obbserver class and pass the event to it.
void Observable::NotifyAll(Event event) {
	for (auto observer = this->observers.begin(); observer != this->observers.end(); observer++)
		(*observer)->Update(event);
}



