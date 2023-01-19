#include <gtest/gtest.h>

#include "copa-pdk/factory/FactoryController.h"
#include "copa-pdk/mock/factory/Factory.h"

TEST( FactoryControllerTest, Failed )
{
	GTEST_FAIL();
}

TEST( FactoryControllerTest, subscribe )
{
	auto factory = std::make_shared< Mock::Factory >();

    COPA::FactoryController factoryController;

    factoryController.subscribe(factory);

    GTEST_SUCCEED();
}
