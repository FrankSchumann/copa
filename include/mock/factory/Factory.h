#include <gmock/gmock.h>

#include "../../factory/FactoryIf.h"

namespace mock::core
{
class Factory : public COPA::FactoryIf
{
   public:
    virtual ~Factory()
    {
    }

    MOCK_METHOD( std::shared_ptr< COPA::ComponentIf >, create, ( std::string const &name ), ( const, override ) );
    MOCK_METHOD( std::string, getType, (), ( const, override ) );
    MOCK_METHOD( std::vector<std::string>, getDependencies, (), ( const, override ) );
};
}
