#pragma once

#include <string>

namespace COPA
{
class ComponentIf
{
   public:
    virtual std::string getType() const = 0;
    virtual std::string getName() const = 0;
    virtual std::string getVersion() const = 0;
};

}
