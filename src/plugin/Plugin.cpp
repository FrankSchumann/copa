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
    typedef const char* ( *getNameType )();
    void* getNameSymbol = dlsym( handle, "getName" );

    if ( nullptr != getNameSymbol )
    {
        getNameType getNameFunction = ( getNameType )getNameSymbol;

        const char* nameTmp = getNameFunction();
        name.assign( nameTmp );
    }
}

void Plugin::receiveVersion()
{
    typedef const char* ( *getVersionType )();
    void* getVersionSymbol = dlsym( handle, "getVersion" );

    if ( nullptr != getVersionSymbol )
    {
        getVersionType getVersionFunction = ( getVersionType )getVersionSymbol;

        const char* versionTmp = getVersionFunction();
        version.assign( versionTmp );
    }
}
