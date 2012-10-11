#include "unittest++/UnitTest++.h"
#include "../src/cppfunc.h"

#include <list>
#include <vector>


using namespace cppfunc;

TEST(TestEqualSize)
{
  CHECK(equal(std::vector<double>{}, std::vector<double>{}));
  CHECK(!equal(std::vector<double>{1}, std::vector<double>{}));
  CHECK(!equal(std::vector<double>{}, std::vector<double>{1}));

  CHECK(equal(std::vector<double>{1, 2, 3}, std::vector<double>{1, 2, 3}));
  CHECK(!equal(std::vector<double>{1, 2, 3}, std::vector<double>{1, 2, 3, 4}));
  CHECK(!equal(std::vector<double>{1, 2, 3, 4}, std::vector<double>{1, 2, 3}));
}

TEST(TestEqualUsual)
{
    CHECK(equal(std::vector<int>{1,-1,20}, std::vector<int>{1,-1,20}));
    CHECK(!equal(std::vector<int>{1,-1,20}, std::vector<int>{1,-2,20}));
    
    CHECK(equal(std::vector<double>{1.1,7,3}, std::vector<double>{1.1,7,3}));
    CHECK(!equal(std::vector<double>{1.1,7,3}, std::vector<double>{1.1,7,3.0000000001}));
}

TEST(TestEqualDifferentContainers)
{
    CHECK(equal(std::vector<int>{1,-1,20}, std::list<int>{1,-1,20}));
    CHECK(!equal(std::vector<int>{1,-1,20}, std::list<int>{1,-2,20}));
}