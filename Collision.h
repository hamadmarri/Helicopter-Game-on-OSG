
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
