#include "factory/FactoryController.h"

#include <iostream>

namespace COPA
{
std::vector< std::shared_ptr< FactoryIf > > FactoryController::factories;

FactoryController::FactoryController()
{
}

FactoryController::~FactoryController()
{
}

void FactoryController::subscribe( std::shared_ptr< FactoryIf > const factory )
{
    factories.push_back( factory );
}

void FactoryController::list()
{
    for ( auto const factory : factories )
    {
        std::cout << "Factory: " << factory->getName() << std::endl;
    }
}

}
