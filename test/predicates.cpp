#include "unittest++/UnitTest++.h"
#include "../src/cppfunc.h"

#include <list>
#include <vector>


using namespace cppfunc;


TEST(TestAll)
{

  CHECK(all([](int v) {return v>0;}, {1, 20, 1000, 70, 3, 2, 1}));
  CHECK(!all([](int v) {return v>0;}, {1, -2, 7}));
  CHECK(all([](int v) {return v>0;}, std::vector<int>{}));
  CHECK(!all([](int v) {return v>0;}, {-1, -2, -3}));

  std::list<double> l{20, 17.3, 45, 13};
  CHECK(all([](double v) {return v>0;}, l));

  std::vector<int> v{20, 16, 42};
  CHECK(all([](int v) {return v%2==0;}, v));
}

TEST(TestAny)
{
  CHECK(any([](int v) {return v>0;}, {1, 20, 1000, 70, 3, 2, 1}));
  CHECK(any([](int v) {return v>0;}, {1, -2, 7}));
  CHECK(any([](int v) {return v>0;}, {-1, -2, 7}));
  CHECK(!any([](int v) {return v>0;}, std::vector<int>{}));
  CHECK(!any([](int v) {return v>0;}, {-1, -2, -3}));

  std::list<double> l{20, 17.3, 45, 13};
  CHECK(any([](double v) {return v>0;}, l));

  std::vector<int> v{23, 17, 42};
  CHECK(any([](int v) {return v%2==0;}, v));
}

TEST(TestNone)
{
  CHECK(!none([](int v) {return v>0;}, {1, 20, 1000, 70, 3, 2, 1}));
  CHECK(!none([](int v) {return v>0;}, {1, -2, 7}));
  CHECK(!none([](int v) {return v>0;}, {-1, -2, 7}));
  CHECK(none([](int v) {return v>0;}, std::vector<int>{}));
  CHECK(none([](int v) {return v>0;}, {-1, -2, -3}));

  std::list<double> l{-20, -17.3, -45, -13};
  CHECK(none([](double v) {return v>0;}, l));

  std::vector<int> v{23, 17, 42};
  CHECK(!none([](int v) {return v%2==0;}, v));
}