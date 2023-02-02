#pragma once

#include <memory>
#include <string>

#include "ComponentIf.h"

namespace COPA
{
class ComponentControllerIf
{
   public:
    virtual void create( std::string const &type, std::string const &name ) = 0;
    virtual std::shared_ptr< ComponentIf > get( std::string const &type, std::string const &name ) const = 0;
    virtual void erase( std::string const &type, std::string const &name ) = 0;
    virtual void erase( std::string const &type ) = 0;
};

}
