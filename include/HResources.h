#pragma once

#include "Room.h"

class HResources
{
private:
	static HResources* instance;

public:
	//sprites
	static sf::Image* SPR_CHAR;
	static sf::Image* SPR_SOLID;

	static Room* ROOM_SEWER;

	HResources(void);
	~HResources(void);

	static HResources* getInstance();

	static Room* Room_Load(const char* url);
};

