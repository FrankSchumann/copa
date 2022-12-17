#include "plugin/Controller.h"

#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "COPA - Controller Platform" << std::endl;

    std::string pluginsFolder( "plugins" );

    plugin::Controller pluginController( pluginsFolder );

    pluginController.loadPlugins();

    return 0;
}
