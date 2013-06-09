#include "HResources.h"
#include <fstream>
#include <string>

HResources* HResources::instance;

//sprites
sf::Image* HResources::SPR_CHAR;
sf::Image* HResources::SPR_SOLID;
//bkg

//rooms
Room* HResources::ROOM_SEWER;

HResources::HResources(void)
{
	instance = this;

	SPR_CHAR = new sf::Image();
	SPR_CHAR->loadFromFile("assets/gfx/objChar.png");

	SPR_SOLID = new sf::Image();
	SPR_SOLID->loadFromFile("assets/gfx/objSolid.png");

	ROOM_SEWER = Room_Load("assets/rooms/roomSewer.txt");
}

HResources::~HResources(void)
{
	delete SPR_CHAR;
	delete SPR_SOLID;
}

HResources* HResources::getInstance()
{
	return instance;
}

Room* HResources::Room_Load(const char* url)
{
	Room* room = new Room();
	std::ifstream file;
	file.open(url);

	std::string line;

	while(file.good())
	{
		std::getline(file, line);
		std::string* parseLine = new std::string[3];
		int ac = 0;

		std::string tempStr = "";
		for(unsigned int i=0;i<line.size();i++)
		{
			char c = line.at(i);
			if(c == ' ')
			{
				parseLine[ac] = tempStr;
				tempStr = "";
				ac++;
			}
			else
			{
				tempStr += c;
			}
		}

		room->addObject(atoi(parseLine[0].c_str()), atof(parseLine[1].c_str()), atof(parseLine[2].c_str()));
	}
	file.close();
	return room;
}
