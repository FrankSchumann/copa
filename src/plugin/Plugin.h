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

    std::string getName() const;
    std::string getVersion() const;

   private:
    std::filesystem::path file;
    void *handle = nullptr;
    std::string name = std::string("");
    std::string version = std::string("");;

    void setName( std::string const &_name );
    void setVersion( std::string const &_version );
};
