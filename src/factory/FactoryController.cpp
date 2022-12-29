#include "copa-pdk/factory/FactoryController.h"

#include <iostream>

namespace COPA
{
std::map< std::string, std::shared_ptr< FactoryIf > > FactoryController::factories;

FactoryController::FactoryController()
{
}

void FactoryController::subscribe( std::shared_ptr< FactoryIf > const factory )
{
    std::cout << "FactoryController::subscribe " << factory->getType() << std::endl;

    std::string const type = factory->getType();

    factories[ type ] = factory;
}

std::shared_ptr< FactoryIf > FactoryController::get( std::string const &type ) const
{
    std::shared_ptr< FactoryIf > result( nullptr );

    auto it = factories.find( type );
    if ( it != factories.end() )
    {
        result = it->second;
    }

    return result;
}

void FactoryController::list() const
{
    std::cout << "FactoryController::list " << std::endl;

    for ( auto const &factory : factories )
    {
        std::cout << "Factory first: " << factory.first << " second " << factory.second->getType() << std::endl;
    }

    std::cout << std::endl;
}

}
