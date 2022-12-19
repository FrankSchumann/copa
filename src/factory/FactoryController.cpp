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

void FactoryController::doSomething()
{
    std::cout << "FactoryController::doSomething" << std::endl;
}

void FactoryController::subscribe( std::shared_ptr< FactoryIf > const factory )
{
    std::cout << "subscribe " << factory->getName() << std::endl;

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
