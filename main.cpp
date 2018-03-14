#include <iostream>
#include <tuple>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/variables_map.hpp>

#include "lib.h"

int main(int argc, char *argv[])
{
    boost::program_options::options_description general("General options");

    try
    {
        general.add_options()
                ("help,h", "produce help message")
                ("version,v", "output the version number");
        boost::program_options::variables_map vm;
        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, general), vm);

        std::cout << "Hello World!" << std::endl;


        if (vm.count("help"))
        {
            std::cout << general;
        }
        else if (vm.count("version"))
        {
            auto major = 0;
            auto minor = 0;
            auto patch = 0;
            std::tie(major, minor, patch) = version();
            std::cout << "version " << major << "." << minor << "." << patch << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cout << general;
    }

    return 0;
}
