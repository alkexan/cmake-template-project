#define BOOST_TEST_MAIN
#define BOOST_TEST_DYN_LINK

#include "Singleton.hpp"
#include <boost/assign.hpp>
#include <boost/test/tools/old/interface.hpp>
#include <boost/test/unit_test.hpp>

#define BOOST_TEST_MODULE MyClass

BOOST_AUTO_TEST_SUITE(tests)

BOOST_AUTO_TEST_CASE(SingletonTest) {
  Singleton *singleton = Singleton::GetInstance("BAR");
  BOOST_CHECK_EQUAL(singleton->value(), "BAR");
}

BOOST_AUTO_TEST_SUITE_END()
