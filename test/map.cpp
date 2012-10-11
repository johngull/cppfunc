#include "unittest++/UnitTest++.h"
#include "../src/cppfunc.h"

#include <list>
#include <vector>


using namespace cppfunc;

TEST(TestMap)
{
  std::vector<int> in{1,2,3,4};
  auto res = map([](int v)->int{return v+1;}, in);
  CHECK_EQUAL(res.size(), in.size());
  
  CHECK(equal(res, std::vector<int>{2,3,4,5}));
  
  std::list<int> inl{-1,2,3,-4};
  auto resl = map([](int v)->int{return v*2;}, inl);
  CHECK_EQUAL(resl.size(), inl.size());
  
  CHECK(equal(resl, std::list<int>{-2,4,6,-8}));
}

TEST(TestMapInPlace)
{
  std::vector<int> in{1,2,3,4};
  std::vector<int> res = in;
  mapInPlace([](int v)->int{return v+1;}, res);
  CHECK_EQUAL(res.size(), in.size());
  
  CHECK(equal(res, std::vector<int>{2,3,4,5}));
  
  std::list<int> inl{-1,2,3,-4};
  auto resl = inl;
  mapInPlace([](int v)->int{return v*2;}, resl);
  CHECK_EQUAL(resl.size(), inl.size());
  
  CHECK(equal(resl, std::list<int>{-2,4,6,-8}));
}