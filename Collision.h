
#ifndef __HelicopterProject__Collision__
#define __HelicopterProject__Collision__


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
