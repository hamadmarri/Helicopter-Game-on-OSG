//
//  Game.cpp
//
//	See main.cpp file header for credits
//
//	Here is the main function call in our UI. It will set the scence,
//	helicopters, and other models in some specific locaitons we had decided on.
//	Setting up all things so that the player can play the game.
//

#include "Game.h"



Game::Game() {

}


void Game::initialize() {
    
    osg::ref_ptr<osg::Group> root = new osg::Group();
	osg::ref_ptr<Helicopter> helicopter = static_cast<Helicopter*>(ModelFactory::getInstance()->create(ModelsTypes::HELICOPTER));
	osg::ref_ptr<Model> terrain = ModelFactory::getInstance()->create(ModelsTypes::TERRAIN);
	osg::ref_ptr<Model> sky = ModelFactory::getInstance()->create(ModelsTypes::SKY);
	osg::ref_ptr<Model> eiffelTour = ModelFactory::getInstance()->create(ModelsTypes::EIFFEL_TOUR);
    osg::ref_ptr<Model> building1 = ModelFactory::getInstance()->create(ModelsTypes::LARGE_RESIDENTIAL_HIGHRISE);
    osg::ref_ptr<Model> building2 = ModelFactory::getInstance()->create(ModelsTypes::LARGE_RESIDENTIAL_HIGHRISE_ORANGE);
    HelicopterController *helicopterController = new HelicopterController(helicopter.get());
    TimeHandler *timhandler = new  TimeHandler();
	osg::ref_ptr<osgGA::NodeTrackerManipulator> nodeTracker = new osgGA::NodeTrackerManipulator;
    
	
	// add models to models vector
	this->models.push_back(helicopter.get());
	this->models.push_back(terrain.get());
	this->models.push_back(sky.get());
	this->models.push_back(eiffelTour.get());
	this->models.push_back(building1.get());
	this->models.push_back(building2.get());
	
	
    // add obeservers
    timhandler->AddObserver(helicopter.get());
    
	
	// set node tracker
	nodeTracker->setHomePosition(osg::Vec3f(0.0f, 7.0f, -35.0f),	//homeEye
								 osg::Vec3f(),						//homeCenter
								 osg::Y_AXIS);						//homeUp
	nodeTracker->setTrackerMode(osgGA::NodeTrackerManipulator::NODE_CENTER_AND_ROTATION);
    nodeTracker->setRotationMode(osgGA::NodeTrackerManipulator::TRACKBALL);
	nodeTracker->setTrackNode(helicopter.get()->getNode());
	
	
	

	// add children nodes to root
	root->addChild(helicopter.get());
	root->addChild(terrain.get());
	root->addChild(sky.get());
    root->addChild(eiffelTour.get());
	root->addChild(building1.get());
	root->addChild(building2.get());
	
	
	// setup viewer
	viewer.addEventHandler(helicopterController);
	viewer.addEventHandler(timhandler);
	viewer.setSceneData(root.get());
    viewer.setCameraManipulator(nodeTracker.get());
	
}



void Game::run() {
	this->viewer.run();
}



void Game::run(const char *fileName) {

	std::thread startReadScript(Game::runScript, fileName, getHelicopter());
	
	run();
	startReadScript.join();

}



void Game::runScript(const char *fileName, osg::ref_ptr<Helicopter> helicopter) {
	ScriptRunner sr(fileName, helicopter.get());
	sr.Run();
}



Helicopter* Game::getHelicopter() {
	return static_cast<Helicopter*>(this->models.at(0));
}



Configuration* Game::getConfiguration() {
	return Configuration::getInstance();
}


