
#include "FollowUpdater.h"



bool FollowUpdater::handle( const osgGA::GUIEventAdapter& ea, osgGA::GUIActionAdapter& aa)
{

	osgViewer::View * view = static_cast<osgViewer::View*>(&aa);
	
	if ( !view || !_target || ea.getEventType()!=osgGA::GUIEventAdapter::FRAME)
		return false;

	osgGA::OrbitManipulator* orbit = dynamic_cast<osgGA::OrbitManipulator*>( view->getCameraManipulator() );

	if (orbit)
	{
		osg::Matrix matrix = computeTargetToWorldMatrix(_target.get());

		osg::Vec3d targetCenter = _target->getBound().center() * matrix;
		orbit->setCenter( targetCenter);
	}
	
	
	return true;




}


osg::Matrix FollowUpdater::computeTargetToWorldMatrix( osg::Node * node ) const
{

	osg::Matrix t2w;

	if (node && node->getNumParents()>0)
	{
		osg::Group* parent = node->getParent(0);
		t2w = osg::computeLocalToWorld( parent->getParentalNodePaths()[0] );
	}



	return t2w;


}