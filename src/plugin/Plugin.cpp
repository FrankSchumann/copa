#include "Plugin.h"

#include<iostream>

Plugin::Plugin( std::string const &_file ) : file(_file)
{
}

Plugin::~Plugin()
{
}

void Plugin::load()
{
	std::cout << "load plugin from file " << file <<std::endl;
}
