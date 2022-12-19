#pragma once

#include<vector>
#include<string>
#include <memory>

#include "Plugin.h"

namespace COPA
{

class PluginController
{
public:
	PluginController( std::string const &_folder);
	virtual ~PluginController();

	void loadPlugins();
	void loadPlugin( std::string const &plugin );

	void closePlugins();
	void closePlugin( std::string const &plugin );

	void list();

private:
	static std::vector<std::shared_ptr<Plugin>> plugins;

	std::string folder;

	void scanFolder();
};

}
