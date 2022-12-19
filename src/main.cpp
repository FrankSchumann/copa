#include <iostream>
#include <memory>

#include "config.h"
#include "copa-pdk/factory/FactoryController.h"
#include "copa-pdk/component/ComponentController.h"

#include "plugin/PluginController.h"
int main( int argc, char *argv[] )
{
    std::cout << "COPA - " << APPLICATION_DESCRIPTION  << std::endl;
    std::cout << "Version: " << APPLICATION_VERSION << std::endl;
    std::cout << std::endl;

    std::string const pluginsFolder( "plugins" );

    COPA::PluginController pluginController( pluginsFolder );

    pluginController.loadPlugins();

    pluginController.list();

    std::shared_ptr<COPA::FactoryController> const factoryController = std::make_shared<COPA::FactoryController>();

    factoryController->list();

    COPA::ComponentController componentController;

    componentController.list();

    return 0;
}
