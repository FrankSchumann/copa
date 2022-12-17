#include "Controller.h"

#include <iostream>

namespace plugin
{

Controller::Controller( std::string const &_folder ) : folder(_folder)
{

}

Controller::~Controller()
{

}

void Controller::loadPlugins()
{
	std::cout << "loadPlugins from folder " << folder << std::endl;
}

void Controller::loadPlugin( std::string const &plugin )
{

}

void Controller::closePlugins()
{

}

void Controller::closePlugin( std::string const &plugin )
{

}

}

