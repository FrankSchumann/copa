#pragma once

#include "FactoryIf.h"

namespace COPA
{
class FactoryControllerIf
{
   public:
    virtual void subscribe( std::shared_ptr< FactoryIf > const factory ) = 0;
    virtual void unsubscribe( std::string const &type ) = 0;
    virtual std::shared_ptr< FactoryIf > get( std::string const &type ) const = 0;
};
}
