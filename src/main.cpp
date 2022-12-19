#include <iostream>
#include <memory>

#include "config.h"
#include "factory/FactoryController.h"

#include "plugin/PluginPluginController.h"

int main( int argc, char *argv[] )
{
    std::cout << "COPA - " << APPLICATION_DESCRIPTION  << std::endl;
    std::cout << "Version: " << APPLICATION_VERSION << std::endl;
    std::cout << std::endl;

    std::string const pluginsFolder( "plugins" );

    plugin::PluginController pluginController( pluginsFolder );

    pluginController.loadPlugins();

    std::shared_ptr<COPA::FactoryController> const factoryController = std::make_shared<COPA::FactoryController>();

    factoryController->list();

    return 0;
}
