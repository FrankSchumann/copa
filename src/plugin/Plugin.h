#pragma once

#include<string>

class Plugin
{
public:
	Plugin( std::string const &_file );
	virtual ~Plugin();

	void load();

private:
	std::string file;
};
