#ifndef FOLLOW_UPDATER_H
#define FOLLOW_UPDATER_H
#include <osg/Camera>
#include <osg/MatrixTransform>
#include <osgGA/OrbitManipulator>
#include <osgViewer/Viewer>



class FollowUpdater : public osgGA::GUIEventHandler
{
public:
	FollowUpdater( osg::Node * node) : _target(node){}


	virtual bool handle( const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa);

	osg::Matrix computeTargetToWorldMatrix( osg::Node * node ) const;

protected:
	osg::observer_ptr<osg::Node> _target;



};

#endif