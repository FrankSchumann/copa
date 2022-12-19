#include "PluginController.h"

#include <filesystem>
#include <iostream>

namespace COPA
{
std::vector< std::shared_ptr< Plugin > > PluginController::plugins;

PluginController::PluginController( std::string const &_folder ) : folder( _folder )
{
}

PluginController::~PluginController()
{
}

void PluginController::loadPlugins()
{
    std::cout << "loadPlugins from folder " << folder << std::endl;

    scanFolder();

    for ( auto &plugin : plugins )
    {
        plugin->load();
    }
}

void PluginController::loadPlugin( std::string const &plugin )
{
}

void PluginController::closePlugins()
{
    for ( auto &plugin : plugins )
    {
        plugin->close();
    }
}

void PluginController::closePlugin( std::string const &plugin )
{
}

void PluginController::scanFolder()
{
    for ( auto &file : std::filesystem::recursive_directory_iterator( folder ) )
    {
        std::cout << file.path().string() << std::endl;

        std::shared_ptr< Plugin > plugin = std::make_shared< Plugin >( file.path() );

        plugins.push_back( plugin );
    }
}

void PluginController::list()
{
    std::cout << "PluginController::list " << std::endl;

    for ( auto const plugin : plugins )
    {
        plugin->show();
    }

    std::cout << std::endl;
}

}
