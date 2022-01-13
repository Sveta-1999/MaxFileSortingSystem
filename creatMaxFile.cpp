#include <iostream>
#include <fstream>
#include <string>

#include "Utility.h"

int main()
{
    std::fstream f (Util::fileName , std::ios_base::out);
    if (! f.is_open() ) { std::cout << "ERROR" << std::endl; return -1 ; }
    for(size_t i = 0 ; i < Util::maxCount ; ++i)
    {
        f << Util::unicode << std::rand() % Util::maxCount << "  " ;
    }
    return 0 ;
}