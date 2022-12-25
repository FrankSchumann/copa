#pragma once

#include <memory>
#include <string>
#include <vector>

#include "Plugin.h"

namespace COPA
{
class PluginController
{
   public:
    PluginController( std::string const &_folder );
    virtual ~PluginController();

    void loadPlugins();
    void loadPlugin( std::string const &plugin ) const;

    void closePlugins() const;
    void closePlugin( std::string const &plugin ) const;

    void list() const;

   private:
    static std::vector< std::shared_ptr< Plugin > > plugins;

    std::string folder;

    void scanFolder();
};

}
