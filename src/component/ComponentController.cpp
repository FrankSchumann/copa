#include "copa-pdk/component/ComponentController.h"
#include "copa-pdk/factory/FactoryController.h"

namespace COPA
{
std::map< std::string, std::shared_ptr< ComponentIf > > ComponentController::components;

ComponentController::ComponentController(): ComponentController(std::make_shared<FactoryController>())
{
}

ComponentController::ComponentController(std::shared_ptr<FactoryControllerIf> const &_factoryController) : factoryController(_factoryController)
{
}

ComponentController::~ComponentController()
{
}

void ComponentController::create( std::string const &name, std::string const &type )
{
	std::shared_ptr<FactoryIf> factory = factoryController->get(type);

	std::shared_ptr<ComponentIf> component;

	factory->create();
}

std::shared_ptr< ComponentIf > ComponentController::get( std::string const &name )
{
	return nullptr;
}

}
