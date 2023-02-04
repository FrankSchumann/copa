#include <gmock/gmock.h>

#include "../../component/ComponentControllerIf.h"

namespace mock::core
{
	class ComponentController : public COPA::ComponentControllerIf
	{
	public:
		virtual ~ComponentController(){}

	    MOCK_METHOD ( void, create, ( std::string const &type, std::string const &name ), (override));
	    MOCK_METHOD (std::shared_ptr< COPA::ComponentIf >, get, ( std::string const &type, std::string const &name ), (const, override));
	    MOCK_METHOD (void, erase, ( std::string const &type, std::string const &name ), (override));
	    MOCK_METHOD (void, erase, ( std::string const &type ), (override));

	};
}
