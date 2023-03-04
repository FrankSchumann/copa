#include <iostream>
#include <memory>

#include "config.h"
#include "Banner.h"

#include <core/plugin/PluginController.h>
#include <core/component/ComponentController.h>
#include <core/factory/FactoryController.h>
#include <core/Info.h>
#include <osal/Info.h>
#include <runtime/RuntimeAdapterIf.h>



int main( int argc, char *argv[] )
{
    copa::Banner::show();

    std::string const pluginFolder( "plugin" );

    std::shared_ptr<core::PluginControllerIf> pluginController = std::make_shared<core::PluginController>( pluginFolder );

    pluginController->loadPlugins();

    pluginController->list();

    std::shared_ptr< core::FactoryController > const factoryController = std::make_shared< core::FactoryController >();

    factoryController->list();

    core::ComponentController componentController;

    componentController.create( "RuntimeController", "Mickey Mouse" );
    
    componentController.create( "RuntimeAdapter", "Donald Duck" );

    componentController.create( "CodesysAdapter", "Goofy" );
    componentController.create( "CodesysAdapter", "Daisy" );
    
    componentController.create( "EcoStruxureAdapter", "Pluto" );
    componentController.create( "EcoStruxureAdapter", "Ellroy" );

    componentController.list();
    std::cout << std::endl;

    auto const cmpDonaldDuck = componentController.get( "RuntimeAdapter", "Donald Duck" );

    std::cout << "cmpDonaldDuck getName: " << cmpDonaldDuck->getName() << std::endl << std::endl;

    std::shared_ptr< RuntimeAdapterIf > runtimeAdpaterDonaldDuck = std::reinterpret_pointer_cast< RuntimeAdapterIf >( cmpDonaldDuck );

    std::cout << "startApplicatons" << std::endl;
    runtimeAdpaterDonaldDuck->startApplications();
    std::cout << std::endl;

    std::cout << "erase Component" << std::endl;
    componentController.erase( "EcoStruxureAdapter", "Pluto" );

    std::cout << "components after erase" << std::endl << std::endl;
    componentController.list();
    std::cout << std::endl;

    std::cout << "before shutdown" << std::endl;
    factoryController->list();

    componentController.list();
    std::cout << std::endl;

    std::cout << "shutdown" << std::endl;

    // pluginController->closePlugins();
    // std::cout << std::endl;

    pluginController->list();
    std::cout << std::endl;

    pluginController->closePlugin("codesys");
    std::cout << std::endl;

    pluginController->closePlugin("ecostruxure");
    std::cout << std::endl;

    pluginController->list();
    std::cout << std::endl;

    pluginController->closePlugin("runtime");
    std::cout << std::endl;

    std::cout << "after shutdown" << std::endl;
    factoryController->list();

    componentController.list();

    return 0;
}
