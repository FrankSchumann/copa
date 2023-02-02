#pragma once

#include <map>
#include <memory>

#include "ComponentControllerIf.h"
#include "ComponentIf.h"
#include "factory/FactoryControllerIf.h"

namespace COPA
{
class ComponentController : public ComponentControllerIf
{
   public:
    ComponentController();
    ComponentController( std::shared_ptr< FactoryControllerIf > const &_factoryController );

    virtual void create( std::string const &type, std::string const &name ) override;
    virtual std::shared_ptr< ComponentIf > get( std::string const &type, std::string const &name ) const override;
    virtual void erase( std::string const &type, std::string const &name ) override;
    virtual void erase( std::string const &type ) override;

    void list() const;

   private:
    static std::map< std::string, std::map< std::string, std::shared_ptr< ComponentIf > > > components;

    std::shared_ptr< FactoryControllerIf > factoryController;
};

}
