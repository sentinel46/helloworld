#include <iostream>
#include <tuple>

#include "lib.h"

int main()
{
    std::cout << "Hello World!" << std::endl;
    int major = 0;
    int minor = 0;
    int patch = 0;
    std::tie(major, minor, patch) = version();
    std::cout << "Version " << major << "." << minor << "." << patch << std::endl;
    return 0;
}
