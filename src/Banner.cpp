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
    std::cout << "\n";
    std::cout << "\t\t   ______ ____   ____   ___   "  << "\n";
    std::cout << "\t\t  / ____// __ \\ / __ \\ /   |"  << "\n";
    std::cout << "\t\t / /    / / / // /_/ // /| | "   << "\n";
    std::cout << "\t\t/ /___ / /_/ // ____// ___ | "   << "\n";
    std::cout << "\t\t\\____/ \\____//_/    /_/  |_| " << "\n";
    std::cout << "\n";
    std::cout << "\t   C o n t r o l l e r  P l a t f o r m" << "\n";
    std::cout << "\n";
    std::cout << "\t              Version: " << COPA_VERSION << "\n";
    std::cout << std::endl;
    std::cout << "\t   CORE: " << core::Info::getVersion() << "\n";
    std::cout << "\t   OSAL: " << osal::Info::getVersion() << "\n";
    std::cout << "\n";
    std::cout << std::endl;
}

}
