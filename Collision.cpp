

#include "Collision.h"


void Collision::addCollidable(Collidable *collidable) {
	this->collidables.push_back(collidable);
}



void Collision::removeCollidable(Collidable *collidable) {
	this->collidables.erase(std::remove(this->collidables.begin(),
										this->collidables.end(),
										collidable
										)
							, this->collidables.end()
							);
}



void Collision::checkCollision() {
	// this function runs in O( (N * (N - 1)) / 2 )
	
	for (std::vector<Collidable*>::iterator it1 = this->collidables.begin(); it1 != this->collidables.end(); it1++) {
		for (std::vector<Collidable*>::iterator it2 = it1 + 1; it2 != this->collidables.end(); it2++) {
			if ((*it1)->getBound().intersects((*it2)->getBound())) {
				(*it1)->collide();
				(*it2)->collide();
			}
		}
	}
}



