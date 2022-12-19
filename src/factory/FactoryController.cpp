#include "copa-pdk/factory/FactoryController.h"

#include <iostream>

namespace COPA
{
std::map< std::string, std::shared_ptr< FactoryIf > > FactoryController::factories;

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
    std::cout << "FactoryController::subscribe " << factory->getType() << std::endl;

    std::string const type = factory->getType();

    factories[ type ] = factory;
}

void FactoryController::get( std::string const &type )
{
	std::shared_ptr<FactoryIf> result(nullptr);

	auto it = factories.find(type);
	if (it != factories.end())
	{
		result = it->second;
	}

}

void FactoryController::list()
{
    std::cout << "FactoryController::list " << std::endl;

    for ( auto const &factory : factories )
    {
        std::cout << "Factory first: " << factory.first << " second " << factory.second->getType() << std::endl;
    }
}

}
