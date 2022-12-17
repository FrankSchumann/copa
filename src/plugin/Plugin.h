#pragma once

#include<string>

class Plugin
{
public:
	Plugin( std::string const &_file );
	virtual ~Plugin();

	void load();
	void close();

private:
	std::string file;
};
