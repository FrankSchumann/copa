#include "Banner.h"

#include "config.h"

#include <iostream>

#include <core/Info.h>
#include <osal/Info.h>

namespace copa
{

Banner::Banner()
{

}

void Banner::show()
{
    std::cout << std::endl;
    std::cout << "\t\t   ______ ____   ____   ___   "  << std::endl;
    std::cout << "\t\t  / ____// __ \\ / __ \\ /   |"  << std::endl;
    std::cout << "\t\t / /    / / / // /_/ // /| | "   << std::endl;
    std::cout << "\t\t/ /___ / /_/ // ____// ___ | "   << std::endl;
    std::cout << "\t\t\\____/ \\____//_/    /_/  |_| " << std::endl;
    std::cout << "\t\t                              "  << std::endl;
    std::cout << "\t   C o n t r o l l e r  P l a t f o r m" << std::endl;
    std::cout << std::endl;
    std::cout << "\t              Version: " << COPA_VERSION << std::endl;
    std::cout << std::endl;
    std::cout << "\t   CORE: " << core::Info::getVersion() << std::endl;
    std::cout << "\t   OSAL: " << osal::Info::getVersion() << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

}
