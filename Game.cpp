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
	this->configuration = new Configuration();
	this->hudsManager = new HudsManager(this, 0);
	this->popupHelpScreen = nullptr;
}



Game::~Game() {
	
}



void Game::initialize() {
    
	ModelFactory mf(this);
	timeHandler = new  TimeHandler(this);
    root = new osg::Group();
	osg::ref_ptr<Helicopter> helicopter = static_cast<Helicopter*>(mf.create(ModelsTypes::HELICOPTER));
	osg::ref_ptr<Model> terrain = mf.create(ModelsTypes::TERRAIN);
	osg::ref_ptr<Model> sky = mf.create(ModelsTypes::SKY);
	osg::ref_ptr<Model> eiffelTour = mf.create(ModelsTypes::EIFFEL_TOUR);
    osg::ref_ptr<Model> building1 = mf.create(ModelsTypes::LARGE_RESIDENTIAL_HIGHRISE);
    osg::ref_ptr<Model> building2 = mf.create(ModelsTypes::LARGE_RESIDENTIAL_HIGHRISE_ORANGE);
	
	osg::ref_ptr<Model> target = mf.create(ModelsTypes::TARGET);
	
    GameController *helicopterController = new GameController(this, helicopter.get());
	this->nodeTracker = new osgGA::NodeTrackerManipulator;

	
	
	// add models to models vector
	this->models.push_back(helicopter.get());
	this->models.push_back(terrain.get());
	this->models.push_back(sky.get());
	this->models.push_back(eiffelTour.get());
	this->models.push_back(building1.get());
	this->models.push_back(building2.get());
	this->models.push_back(target.get());
	
	
    // add obeservers
    timeHandler->AddObserver(helicopter.get());
	
	
	// add collidables
	this->collision.addCollidable(static_cast<Obstacle*>(eiffelTour.get()));
	this->collision.addCollidable(static_cast<Obstacle*>(building1.get()));
	this->collision.addCollidable(static_cast<Obstacle*>(building2.get()));
	this->collision.addCollidable(static_cast<Obstacle*>(target.get()));
    
	
	// add loggables
	this->logger.addLoggable(helicopter.get());
	
	
	// initialize popup help screen
	initializePopupHelpScreen();
	
	
	// set node tracker
	initializeCamera();
	

	// add children nodes to root
	root->addChild(helicopter.get());
	root->addChild(terrain.get());
	root->addChild(sky.get());
    root->addChild(eiffelTour.get());
	root->addChild(building1.get());
	root->addChild(building2.get());
	root->addChild(target.get());
	
	
	// setup viewer
	viewer.addEventHandler(helicopterController);
	viewer.addEventHandler(timeHandler);
	viewer.setSceneData(root.get());
    viewer.setCameraManipulator(nodeTracker.get());
	
}



void Game::initializeCamera() {
	nodeTracker->setHomePosition(osg::Vec3f(0.0f, 7.0f, -35.0f),	//homeEye
								 osg::Vec3f(),						//homeCenter
								 osg::Y_AXIS);						//homeUp
	
	if (this->configuration->isAutoCamera())
		nodeTracker->setTrackerMode(osgGA::NodeTrackerManipulator::NODE_CENTER_AND_ROTATION);
	else
		nodeTracker->setTrackerMode(osgGA::NodeTrackerManipulator::NODE_CENTER);
	
    nodeTracker->setRotationMode(osgGA::NodeTrackerManipulator::TRACKBALL);
	nodeTracker->setTrackNode(getHelicopter()->getNode());
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



void Game::initializePopupHelpScreen() {
	
	if (popupHelpScreen)
		delete popupHelpScreen;
		
	this->popupHelpScreen = new HudsManager(this, this->configuration->getScreenHeight() / 2);
	
	Hud *titleHud = popupHelpScreen->createHud(HudAlignment::LEFT);
	Hud *mouseHud;
	Hud *movementHud;
	
	if (this->configuration->isMouseControl())
		mouseHud = popupHelpScreen->createHud(HudAlignment::LEFT);
	else
		movementHud = popupHelpScreen->createHud(HudAlignment::LEFT);
	
	Hud *resetJoystickHud = popupHelpScreen->createHud(HudAlignment::LEFT);
	Hud *zeroRotorSpeedHud = popupHelpScreen->createHud(HudAlignment::LEFT);
	Hud *increase_decreaseRotorSpeedHud = popupHelpScreen->createHud(HudAlignment::LEFT);
	Hud *neutralRotorModeHud = popupHelpScreen->createHud(HudAlignment::LEFT);
	Hud *rotationHud = popupHelpScreen->createHud(HudAlignment::LEFT);
	Hud *fireHud = popupHelpScreen->createHud(HudAlignment::LEFT);
	Hud *increment_decrementInclinationAngleHud = popupHelpScreen->createHud(HudAlignment::LEFT);
	Hud *increment_decrementMissileInitialSpeedHud = popupHelpScreen->createHud(HudAlignment::LEFT);
	Hud *frictionEnable_DisableHud = popupHelpScreen->createHud(HudAlignment::LEFT);
	Hud *updateHud = popupHelpScreen->createHud(HudAlignment::LEFT);
	Hud *showHelpHud = popupHelpScreen->createHud(HudAlignment::LEFT);
	Hud *hideHelpHud = popupHelpScreen->createHud(HudAlignment::LEFT);
	
	titleHud->setText("Settings");
	
	if (this->configuration->isMouseControl())
		mouseHud->setText("Mouse contorl the joystick");
	else {
		movementHud->setText(
							 std::string(1, this->configuration->getKeySettings().movingForward) + ", " +
							 std::string(1, this->configuration->getKeySettings().movingRight) + ", " +
							 std::string(1, this->configuration->getKeySettings().movingLeft) + ", " +
							 std::string(1, this->configuration->getKeySettings().movingBackward) +
							 ": moving forward, left, right, backward"
							 );
	}
		
	
	resetJoystickHud->setText(
			std::string(1, this->configuration->getKeySettings().resetJoystick) + ": reset joystick");
	
	zeroRotorSpeedHud->setText(
			std::string(1, this->configuration->getKeySettings().zeroRotorSpeed) + ": zero rotor speed");
	
	increase_decreaseRotorSpeedHud->setText(
			std::string(1, this->configuration->getKeySettings().increaseRotorSpeed) + "/" +
			std::string(1, this->configuration->getKeySettings().decreaseRotorSpeed) + ": +/- rotor speed");
	
	neutralRotorModeHud->setText(
			std::string(1, this->configuration->getKeySettings().neutralRotorMode) + ": neutral rotor mode");
	
	rotationHud->setText(
			std::string(1, this->configuration->getKeySettings().rotateLeft) + "/" +
			std::string(1, this->configuration->getKeySettings().rotateRight) + ": rotate left/right");
	
	fireHud->setText(
			std::string(1, this->configuration->getKeySettings().fire) + ": fire");
	
	increment_decrementInclinationAngleHud->setText(
			std::string(1, this->configuration->getKeySettings().incrementInclinationAngle) + "/" +
			std::string(1, this->configuration->getKeySettings().decrementInclinationAngle) +
													": +/- inclination angle");
	
	increment_decrementMissileInitialSpeedHud->setText(
			std::string(1, this->configuration->getKeySettings().incrementMissileInitialSpeed) + "/" +
			std::string(1, this->configuration->getKeySettings().decrementMissileInitialSpeed) +
													   + ": +/- increment missile initial speed");
	
	frictionEnable_DisableHud->setText(
			std::string(1, this->configuration->getKeySettings().frictionEnable) + "/" +
			std::string(1, this->configuration->getKeySettings().frictionDisable) +
									   + ": enable/disable friction");
	
	updateHud->setText(
			std::string(1, this->configuration->getKeySettings().updateKeySettings) + ": updste key settings");
	
	showHelpHud->setText(
			std::string(1, this->configuration->getKeySettings().showPopupHelpScreen) + ": show help screen");
	
	hideHelpHud->setText(
			std::string(1, this->configuration->getKeySettings().hidePopupHelpScreen) + ": hide help screen");
}



std::vector<Model*> Game::getModels() {
	return this->models;
}



Helicopter* Game::getHelicopter() {
	return static_cast<Helicopter*>(this->models.at(0));
}



Configuration* Game::getConfiguration() {
	return this->configuration;
}


