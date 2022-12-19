#include "copa-pdk/component/ComponentController.h"

#include "copa-pdk/factory/FactoryController.h"

namespace COPA
{
std::map< std::string, std::map< std::string, std::shared_ptr< ComponentIf > > > ComponentController::components;

ComponentController::ComponentController() : ComponentController( std::make_shared< FactoryController >() )
{
}

ComponentController::ComponentController( std::shared_ptr< FactoryControllerIf > const &_factoryController ) : factoryController( _factoryController )
{
}

ComponentController::~ComponentController()
{
}

void ComponentController::create( std::string const &type, std::string const &name )
{
    std::shared_ptr< FactoryIf > factory = factoryController->get( type );

    std::shared_ptr< ComponentIf > component = factory->create( name );

    components.insert( std::make_pair( type, std::map< std::string, std::shared_ptr< ComponentIf > >() ) );
    components[ type ].insert( std::make_pair( name, component ) );
}

std::shared_ptr< ComponentIf > ComponentController::get( std::string const &type, std::string const &name )
{
    std::shared_ptr< ComponentIf > result( nullptr );

    auto const componentsSameType = getComponentsSameType( type );

    if ( false == componentsSameType.empty() )
    {
    	result = getComponent(name, componentsSameType);
    }

    return result;
}

std::map< std::string, std::shared_ptr< ComponentIf > > ComponentController::getComponentsSameType( std::string const &type )
{
    std::map< std::string, std::shared_ptr< ComponentIf > > result;

    auto it = components.find( type );
    if ( it != components.end() )
    {
        result = it->second;
    }

    return result;
}

std::shared_ptr< ComponentIf > ComponentController::getComponent( std::string const &name,
                                                                  std::map< std::string, std::shared_ptr< ComponentIf > > const &componentsSameType )
{
    std::shared_ptr< ComponentIf > result;

    auto it = componentsSameType.find( name );
    if ( it != componentsSameType.end() )
    {
        result = it->second;
    }

    return result;
}

}
