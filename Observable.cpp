//
//  Observable.cpp
//
//	See main.cpp file header for credits
//

#include "Observable.h"


void Observable::AddObserver(Observer *observer) {
	auto it = std::find(this->observers.begin(), this->observers.end(), observer);
	if (it == this->observers.end())
		this->observers.push_back(observer);
}



void Observable::RemoveObserver(Observer *observer) {
	auto it = std::find(this->observers.begin(), this->observers.end(), observer);
	if (it != this->observers.end())
		this->observers.erase(it);
}



void Observable::NotifyAll(Event event) {
	for (auto observer = this->observers.begin(); observer != this->observers.end(); observer++)
		(*observer)->Update(event);
}



