#pragma once

#include <filesystem>
#include <string>

class Plugin
{
   public:
    Plugin( std::filesystem::path const &_file );

    void load();
    void close() const;
    std::string getName() const;

    void show() const;

   private:
    std::filesystem::path file;
    void *handle = nullptr;
    std::string name = std::string( "" );
    std::string version = std::string( "" );

    void receiveName();
    void receiveVersion();
    void receiveString( std::string const &functionName, std::string &destination ) const;

    void subscribe() const;
    void unsubscribe() const;
    void callPluginFunction( std::string const &function ) const;
};
