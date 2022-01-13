#include <iostream>
#include <string>
#include <bitset>
#include <fstream>

#include "Utility.h"

int main()
{
    std::fstream f(Util::fileName , std::ios_base::in);
    std::bitset <Util::maxCount> bit ;
    if (!f.is_open()) {std::cout << "ERROR" << std::endl ; return -1 ; }
    while(!f.eof())
    {
        std::string str ;
        f >> str;
        if(str == "") { continue; }
        str.erase(0,Util::unicode.size());
        size_t tmp = std::stoll(str) ;
        bit[tmp] = true ;
    }
    f.close();
    f.open(Util::fileName , std::ios_base::out);
    for(size_t i = 0 ; i < bit.size() ; ++i)
    {
        if(bit[i])
        {
            f << Util::unicode << i << "\n";
        }
    }
    return 0 ;

}