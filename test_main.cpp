#include "lib.h"

#define BOOST_TEST_MODULE test_main

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite_main)

BOOST_AUTO_TEST_CASE(test_version_valid)
{
    int major = 0;
    int minor = 0;
    int patch = 0;
    std::tie(major, minor, patch) = version();
    BOOST_CHECK( major >= 0 );
    BOOST_CHECK( minor >= 0 );
    BOOST_CHECK( patch > 0 );
}

BOOST_AUTO_TEST_SUITE_END()
