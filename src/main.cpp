#include <iostream>

#include "config.h"
#include "plugin/Controller.h"

int main( int argc, char *argv[] )
{
    std::cout << "COPA - " << APPLICATION_DESCRIPTION  << std::endl;
    std::cout << "Version: " << APPLICATION_VERSION << std::endl;
    std::cout << std::endl;

    std::string pluginsFolder( "plugins" );

    plugin::Controller pluginController( pluginsFolder );

    pluginController.loadPlugins();

    return 0;
}
