
#ifndef __HelicopterProject__Collidable__
#define __HelicopterProject__Collidable__

#include <osg/BoundingSphere>

class Collidable {
public:
	virtual osg::BoundingSphere getBound() = 0;
	virtual void collide() = 0;
};

#endif /* defined(__HelicopterProject__Collidable__) */
