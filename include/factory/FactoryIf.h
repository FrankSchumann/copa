#pragma once

#include <string>
#include <memory>
#include <vector>

#include "../component/ComponentIf.h"

namespace COPA
{
class FactoryIf
{
   public:
    virtual std::shared_ptr< ComponentIf > create( std::string const &name ) const = 0;
    virtual std::string getType() const = 0;
    virtual std::vector<std::string> getDependencies() const = 0;
};

}
