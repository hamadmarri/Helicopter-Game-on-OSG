
#ifndef __HelicopterProject__Collidable_h__
#define __HelicopterProject__Collidable_h__

#include <osg/BoundingSphere>

class Collidable {
public:
	virtual osg::BoundingSphere getBound() = 0;
	virtual void collide() = 0;
};

#endif 
