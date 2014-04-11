//
// Collision is responsible of adding/removing collidable objects
// and it checks if an intersect happend between them.
// if intersect happend, it will call collide function for both objects
// that collided with each other
// 
//
//	created by Fares Alotaibi
//	modified by Hamad Almarri
//


#ifndef __HelicopterProject__Collision_h__
#define __HelicopterProject__Collision_h__


#include <vector>
#include "Collidable.h"


class Collision {
public:
	void addCollidable(Collidable *collidable);
	void removeCollidable(Collidable *collidable);
	void checkCollision();
	
private:
	std::vector<Collidable*> collidables;
};



#endif
