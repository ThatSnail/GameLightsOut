#include "../include/H.h"

#include "SFML/Graphics.hpp"

#include "LDraw.h"
#include <algorithm>
#include <time.h>

HGame* HGame::instance;

HGame::HGame(void)
{
	instance = this;
	didRoomChange = false;

	isRunning = true;

	new HScreen();
	new HResources();
	new HRoom();

	HRoom::gotoRoom(HResources::ROOM_SEWER);

    clock_t t = clock();
	// Start the game loop
    while (HScreen::getScreen()->isOpen())
    {
        while((clock() - t)/static_cast<double>(CLOCKS_PER_SEC) < static_cast<double>(1)/FPS);
        t = clock();

        didRoomChange = false;

        hEvent();
        hStep();
        hDraw();

        while(destroyQueue.size()>0)
		{
			std::vector<Obj*>* objList = &HGame::getInstance()->objectList;
			std::vector<Obj*>::iterator it = std::find(objList->begin(), objList->end(), destroyQueue.front());
			if(it != objList->end())
			{
				objList->erase(it);
			}

			destroyQueue.pop();
		}
    }
}


HGame::~HGame(void)
{
}

void HGame::hEvent()
{
	sf::Event event;
	while(HScreen::getScreen()->pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
		{
			isRunning = false;
			break;
		}
		if(didRoomChange){break;}
		for(unsigned int i = 0; i < objectList.size(); i++)
		{
		    Obj* o = objectList.at(i);
			o->onEvent(event);
		}
	}
}

void HGame::hStep()
{
	for(unsigned int i = 0; i<objectList.size(); i++)
	{
	    Obj* o = objectList.at(i);
		if(didRoomChange){break;}
		o->onStep();
	}
}

void HGame::hDraw()
{
    if(HRoom::getCurrentRoom()->useBackgroundImage)
    {
        LDraw::DrawImage(&HRoom::getCurrentRoom()->backgroundImage, 0, 0);
    }
    else
    {
		const sf::Vector2f viewRect = HScreen::getView().getSize();
		const sf::Vector2f viewCenter = HScreen::getView().getCenter();
		LDraw::DrawRect(viewCenter.x - viewRect.x / 2, viewCenter.y - viewRect.y / 2, viewRect.x, viewRect.y, HScreen::BACKGROUND_COLOR);
    }
	for(unsigned int i = 0; i < objectList.size(); i++)
    {
        Obj* o = objectList.at(i);
		if(didRoomChange){break;}
		if(o->visible)
		{
			o->onDraw();
		}
	}

	HScreen::getScreen()->display();
}

HGame* HGame::getInstance()
{
	return instance;
}

void HGame::addObject(Obj* o)
{
	HGame::getInstance()->objectList.push_back(o);
}

void HGame::removeObject(Obj* o)
{
	HGame::getInstance()->destroyQueue.push(o);
}

std::vector<Obj*> HGame::getObjectList()
{
	return HGame::getInstance()->objectList;
}
