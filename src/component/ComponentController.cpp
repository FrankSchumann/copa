#include "copa-pdk/component/ComponentController.h"

namespace COPA
{
std::map< std::string, std::shared_ptr< ComponentIf > > ComponentController::components;

ComponentController::ComponentController()
{
}

ComponentController::~ComponentController()
{
}

void ComponentController::create( std::string const &name, std::string const &type )
{
}

std::shared_ptr< ComponentIf > ComponentController::get( std::string const &name )
{
	return nullptr;
}

}
