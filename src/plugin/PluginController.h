#pragma once

#include<vector>
#include<string>
#include <memory>

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
	static std::vector<std::shared_ptr<Plugin>> plugins;

	std::string folder;

	void scanFolder();
};

}
