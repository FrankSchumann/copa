#include "factory/FactoryController.h"

namespace COPA
{
std::vector< std::shared_ptr< FactoryIf > > FactoryController::factories;

FactoryController::FactoryController()
{
}

FactoryController::~FactoryController()
{
}

void FactoryController::subscribe()
{
}

}
