#include "Controller.h"

#include <iostream>
#include <filesystem>

namespace plugin
{

std::vector<std::shared_ptr<Plugin>> Controller::plugins;

Controller::Controller( std::string const &_folder ) : folder(_folder)
{

}

Controller::~Controller()
{

}

void Controller::loadPlugins()
{
	std::cout << "loadPlugins from folder " << folder << std::endl;

	scanFolder();

	for( auto &plugin : plugins )
	{
		plugin->load();
	}
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

void Controller::scanFolder()
{
	for( auto &file : std::filesystem::recursive_directory_iterator( folder ) )
	{
		std::cout << file.path().string() << std::endl;

		std::shared_ptr<Plugin> plugin = std::make_shared<Plugin>( file.path().string() );

		plugins.push_back( plugin );
	}
}

}

