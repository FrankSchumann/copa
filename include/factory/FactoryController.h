#pragma once

#include <map>
#include <memory>

#include "FactoryControllerIf.h"
#include "FactoryIf.h"

namespace COPA
{
class FactoryController : public FactoryControllerIf
{
   public:
    FactoryController();

    void subscribe( std::shared_ptr< FactoryIf > const factory ) override;
    void unsubscribe( std::string const &type ) override;
    std::shared_ptr< FactoryIf > get( std::string const &type ) const override;

    void list() const;

   private:
    static std::map< std::string, std::shared_ptr< FactoryIf > > factories;
};

}
