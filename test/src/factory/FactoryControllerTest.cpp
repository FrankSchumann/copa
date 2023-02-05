#include <gtest/gtest.h>

#include "factory/FactoryController.h"
#include "mock/factory/Factory.h"

TEST( FactoryControllerTest, Failed )
{
	GTEST_FAIL();
}

TEST( FactoryControllerTest, subscribe )
{
	auto factory = std::make_shared< mock::core::Factory >();

    COPA::FactoryController factoryController;

    factoryController.subscribe(factory);

    GTEST_SUCCEED();
}
