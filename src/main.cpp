#include <iostream>
#include <memory>

#include "config.h"
#include "copa-pdk/component/ComponentController.h"
#include "copa-pdk/factory/FactoryController.h"
#include "plugin/PluginController.h"
#include "runtime-sdk/RuntimeAdapterIf.h"
int main( int argc, char *argv[] )
{
    std::cout << "COPA - " << APPLICATION_DESCRIPTION << std::endl;
    std::cout << "Version: " << APPLICATION_VERSION << std::endl;
    std::cout << std::endl;

    std::string const pluginsFolder( "plugins" );

    COPA::PluginController pluginController( pluginsFolder );

    pluginController.loadPlugins();

    pluginController.list();

    std::shared_ptr< COPA::FactoryController > const factoryController = std::make_shared< COPA::FactoryController >();

    factoryController->list();

    COPA::ComponentController componentController;

    componentController.create( "RuntimeAdapter", "Mickey Mouse" );
    componentController.create( "RuntimeAdapter", "Donald Duck" );

    componentController.create( "CodesysAdapter", "Goofy" );
    componentController.create( "CodesysAdapter", "Pluto" );

    componentController.list();
    std::cout << std::endl;

    std::shared_ptr< COPA::ComponentIf > cmpMickeyMouse = componentController.get( "RuntimeAdapter", "Mickey Mouse" );

    std::cout << "cmpMickeyMouse getName: " << cmpMickeyMouse->getName() << std::endl;

    std::shared_ptr< RuntimeAdapterIf > runtimeAdpaterMickeyMouse = std::reinterpret_pointer_cast< RuntimeAdapterIf >( cmpMickeyMouse );

    std::cout << "startApplicatons" << std::endl;
    runtimeAdpaterMickeyMouse->startApplications();

    return 0;
}
