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
        receiveName();
        receiveVersion();
        subscribe();
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

void Plugin::show()
{
    std::cout << "Plugin: " << name << " File: " << file.string() << " Version: " << version << std::endl;
}

void Plugin::subscribe()
{
    typedef void ( *subscribeFunctionType )();
    void* subscribeFunctionSymbol = dlsym( handle, "subscribePlugin" );

    if ( nullptr != subscribeFunctionSymbol )
    {
        subscribeFunctionType subscribeFunction = ( subscribeFunctionType )subscribeFunctionSymbol;

        subscribeFunction();
    }
}

void Plugin::receiveName()
{
    receiveString( std::string( "getName" ), version );
}

void Plugin::receiveVersion()
{
    receiveString( std::string( "getVersion" ), version );
}

void Plugin::receiveString( std::string const& functionName, std::string& destination )
{
    typedef const char* ( *getStringFunctionType )();
    void* getStringFunctionSymbol = dlsym( handle, functionName.c_str() );

    if ( nullptr != getStringFunctionSymbol )
    {
        getStringFunctionType getStringFunction = ( getStringFunctionType )getStringFunctionSymbol;

        const char* stringTmp = getStringFunction();
        destination.assign( stringTmp );
    }
}
