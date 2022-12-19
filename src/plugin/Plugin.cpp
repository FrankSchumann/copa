#include "Plugin.h"

#include <dlfcn.h>

#include <iostream>

Plugin::Plugin( std::filesystem::path const& _file ) : file( _file )
{
}

Plugin::~Plugin()
{
}

void Plugin::load()
{
    std::cout << "load plugin from file " << file.string() << std::endl;

    typedef void ( *subscribeFunctionType )();

    //   handle = dlopen( file.string().c_str(), RTLD_GLOBAL );
    handle = dlopen( file.string().c_str(), RTLD_LAZY );

    if ( nullptr != handle )
    {
        void* subscribeFunctionSymbol = dlsym( handle, "subscribePlugin" );

        subscribeFunctionType subscribeFunction = ( subscribeFunctionType )subscribeFunctionSymbol;

        subscribeFunction();

        setName("Test");

        setVersion("0.0.0.0");
    }
    else
    {
        std::cout << "handle " << handle << std::endl;

        char* errormessage = dlerror();

        std::cout << "errormessage: " << errormessage << std::endl;
    }
}

void Plugin::close()
{
    std::cout << "close plugin from file " << file.string() << std::endl;
}

std::string Plugin::getName() const
{
	return name;
}

std::string Plugin::getVersion() const
{
    return version;
}

void Plugin::setName( std::string const& _name )
{
	name = _name;
}

void Plugin::setVersion( std::string const& _version )
{
	version = _version;
}
