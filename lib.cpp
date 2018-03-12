#include "lib.h"
#include "version.h"

std::tuple<int, int, int> version()
{
    return std::make_tuple(PROJECT_VERSION_MAJOR, PROJECT_VERSION_MINOR, PROJECT_VERSION_PATCH);
}
