#ifndef OS_HPP
#define OS_HPP

#include <string>
#include "dirent.h"

class OS
{
    public:
        static void ListDir(std::string dirPath);
};

#endif