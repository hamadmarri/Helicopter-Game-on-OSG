
#include "HudsManager.h"
#include "Game.h"


HudsManager::HudsManager(Game *game, unsigned int initial_Y_Position) {
	this->game = game;
	this->initial_Y_Position = initial_Y_Position;
}



HudsManager::~HudsManager() {
	for (Hud* h : this->leftHuds)
		game->root->removeChild(h->getHudCamera());
	
	for (Hud* h : this->rightHuds)
		game->root->removeChild(h->getHudCamera());
}



Hud* HudsManager::createHud(HudAlignment hudAlignment) {
	Hud *hud = new Hud();
	unsigned long hudPosition;
	
	hud->initializeHudText();
	
	if (hudAlignment == HudAlignment::LEFT) {
		this->leftHuds.push_back(hud);
		hud->setPosition(osg::Vec3(10, this->initial_Y_Position, 0));
	} else {
		this->rightHuds.push_back(hud);
		hud->setPosition(osg::Vec3(900, this->initial_Y_Position, 0));
	}
	
	hud->setText("");
	osg::Camera *hudCamera = hud->getHudCamera();
	game->root->addChild(hudCamera);
	
	
	// update huds positions
	hudPosition = this->leftHuds.size();
	for (Hud* h : this->leftHuds)
		h->setPosition(osg::Vec3(h->getPosition().x(), ((hudPosition--) * 25) + this->initial_Y_Position + 10, 0));

	hudPosition = this->rightHuds.size();
	for (Hud* h : this->rightHuds)
		h->setPosition(osg::Vec3(h->getPosition().x(), ((hudPosition--) * 25) + this->initial_Y_Position + 10, 0));
	
	return hud;
}



void HudsManager::removeHud(Hud* hud) {
	for (Hud* h : this->leftHuds)
		if (h == hud)
			this->leftHuds.erase(std::remove(this->leftHuds.begin(), this->leftHuds.end(), hud), this->leftHuds.end());
	
	for (Hud* h : this->rightHuds)
		if (h == hud)
			this->rightHuds.erase(std::remove(this->rightHuds.begin(), this->rightHuds.end(), hud), this->rightHuds.end());
	
	game->root->removeChild(hud->getHudCamera());
}



void HudsManager::hide() {
	for (auto it = this->leftHuds.begin(); it != this->leftHuds.end(); it++)
		(*it)->hide();
	
	for (auto it = this->rightHuds.begin(); it != this->rightHuds.end(); it++)
		(*it)->hide();
}



void HudsManager::show() {
	for (auto it = this->leftHuds.begin(); it != this->leftHuds.end(); it++)
		(*it)->show();
	
	for (auto it = this->rightHuds.begin(); it != this->rightHuds.end(); it++)
		(*it)->show();
}


