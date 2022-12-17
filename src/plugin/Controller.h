#pragma once

#include<vector>
#include<string>

#include "Plugin.h"

namespace plugin
{

class Controller
{
public:
	Controller( std::string const &_folder);
	virtual ~Controller();

	void loadPlugins();
	void loadPlugin( std::string const &plugin );

	void closePlugins();
	void closePlugin( std::string const &plugin );

private:
	static std::vector<Plugin> plugins;

	std::string folder;
};

}
