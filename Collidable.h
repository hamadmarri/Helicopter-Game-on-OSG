/*
 Collidable is an interface for objects that need to be
 considered as collidables. Tow important functions
 1- get bound of the object
 2- collide which is the action that is called when intersect happened
 */


#ifndef __HelicopterProject__Collidable_h__
#define __HelicopterProject__Collidable_h__

#include <osg/BoundingSphere>

class Collidable {
public:
	virtual osg::BoundingSphere getBound() = 0;
	virtual void collide() = 0;
};

#endif 
