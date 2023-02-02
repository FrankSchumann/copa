#include "copa/component/ComponentController.h"

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <utility>

#include "copa/factory/FactoryController.h"

namespace COPA
{
std::map< std::string, std::map< std::string, std::shared_ptr< ComponentIf > > > ComponentController::components;

ComponentController::ComponentController() : ComponentController( std::make_shared< FactoryController >() )
{
}

ComponentController::ComponentController( std::shared_ptr< FactoryControllerIf > const &_factoryController ) : factoryController( _factoryController )
{
}

void ComponentController::create( std::string const &type, std::string const &name )
{
    std::shared_ptr< FactoryIf > factory = factoryController->get( type );

    std::shared_ptr< ComponentIf > component = factory->create( name );

    components.insert( std::make_pair( type, std::map< std::string, std::shared_ptr< ComponentIf > >() ) );
    components[ type ].insert( std::make_pair( name, component ) );
}

std::shared_ptr< ComponentIf > ComponentController::get( std::string const &type, std::string const &name ) const
{
    std::shared_ptr< ComponentIf > result( nullptr );

    try
    {
        result = components.at( type ).at( name );
    }
    catch ( const std::out_of_range &oor )
    {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }

    return result;
}

void ComponentController::erase( std::string const &type, std::string const &name )
{
    try
    {
        components.at( type ).at( name ).reset();
        components.at( type ).erase( name );

        if ( true == components.at( type ).empty() )
        {
            components.erase( type );
        }
    }
    catch ( const std::out_of_range &oor )
    {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
    }
}

void ComponentController::erase( std::string const &type )
{
    auto first = components.at( type ).begin();
    auto last = components.at( type ).end();

    auto destroy = []( auto &componentPair ) { componentPair.second.reset(); };

    std::for_each( first, last, destroy );

    components.erase( type );
}

void ComponentController::list() const
{
    std::cout << "ComponentController::list" << std::endl;

    for ( auto const &[ type, componentsSameType ] : components )
    {
        std::cout << std::endl << "Type: " << type << std::endl;

        for ( auto const &[ name, component ] : componentsSameType )
        {
            std::cout << "Name: " << name << std::endl;
        }
    }
}
}
