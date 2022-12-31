#include <iostream>
#include <memory>

#include "config.h"
#include "copa-pdk/component/ComponentController.h"
#include "copa-pdk/factory/FactoryController.h"
#include "copa-pdk/osal/osalinfo/OsalInfoFactory.h"
#include "plugin/PluginController.h"
#include "runtime-sdk/RuntimeAdapterIf.h"

int main( int argc, char *argv[] )
{
    std::cout << "COPA - " << APPLICATION_DESCRIPTION << std::endl;
    std::cout << "Version: " << APPLICATION_VERSION << std::endl;
    std::cout << std::endl;

    std::shared_ptr< COPA::OsalInfoFactoryIf > osalInfoFactory = std::make_shared< COPA::OsalInfoFactory >();
    std::shared_ptr< COPA::OsalInfoIf > osalInfo = osalInfoFactory->create();

    std::cout << "OSAL - " << osalInfo->getDescription() << std::endl;
    std::cout << "Version: " << osalInfo->getVersion() << std::endl;
    std::cout << std::endl;

    std::string const pluginFolder( "plugin" );

    COPA::PluginController pluginController( pluginFolder );

    pluginController.loadPlugins();

    pluginController.list();

    std::shared_ptr< COPA::FactoryController > const factoryController = std::make_shared< COPA::FactoryController >();

    factoryController->list();

    COPA::ComponentController componentController;

    componentController.create( "RuntimeController", "Mickey Mouse" );
    componentController.create( "RuntimeAdapter", "Donald Duck" );

    componentController.create( "CodesysAdapter", "Goofy" );
    componentController.create( "CodesysAdapter", "Daisy" );
    componentController.create( "EcoStruxureAdapter", "Pluto" );
    componentController.create( "EcoStruxureAdapter", "Ellroy" );

    componentController.list();
    std::cout << std::endl;

    std::shared_ptr< COPA::ComponentIf > cmpDonaldDuck = componentController.get( "RuntimeAdapter", "Donald Duck" );

    std::cout << "cmpDonaldDuck getName: " << cmpDonaldDuck->getName() << std::endl;

    std::shared_ptr< RuntimeAdapterIf > runtimeAdpaterDonaldDuck = std::reinterpret_pointer_cast< RuntimeAdapterIf >( cmpDonaldDuck );

    std::cout << "startApplicatons" << std::endl;
    runtimeAdpaterDonaldDuck->startApplications();
    std::cout << std::endl;

    std::cout << "erase Component" << std::endl;
    componentController.erase( "EcoStruxureAdapter", "Pluto" );

    std::cout << "erase Components" << std::endl;
    componentController.erase( "CodesysAdapter" );

    std::cout << "finish erase" << std::endl << std::endl;

    componentController.list();
    std::cout << std::endl;

    std::cout << "unsubscribe Factory" << std::endl;

    factoryController->list();

    std::cout << "unsubscribe RuntimeAdapter" << std::endl;
    factoryController->unsubscribe( "RuntimeAdapter" );

    factoryController->list();

    return 0;
}
