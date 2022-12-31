#include "PluginController.h"

#include <filesystem>
#include <iostream>

namespace COPA
{
std::vector< std::shared_ptr< Plugin > > PluginController::plugins;

PluginController::PluginController( std::string const &_folder ) : folder( _folder )
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

    std::cout << std::endl;
}

void PluginController::loadPlugin( std::string const &plugin ) const
{
}

void PluginController::closePlugins() const
{
    for ( auto &plugin : plugins )
    {
        plugin->close();
    }
}

void PluginController::closePlugin( std::string const &plugin ) const
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

    std::cout << std::endl;
}

void PluginController::list() const
{
    std::cout << "PluginController::list " << std::endl;

    for ( auto const plugin : plugins )
    {
        plugin->show();
    }

    std::cout << std::endl;
}

}
