#pragma once

#include <filesystem>
#include <string>

class Plugin
{
   public:
    Plugin( std::filesystem::path const &_file );
    virtual ~Plugin();

    void load();
    void close();

   private:
    std::filesystem::path file;
    void* handle = nullptr;
};
