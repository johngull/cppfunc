#include "unittest++/UnitTest++.h"
#include "../src/cppfunc.h"

#include <list>
#include <vector>
#include <string>


using namespace cppfunc;

TEST(TestFoldL)
{
  std::vector<int> in{1,2,3,4};
  int res = foldl([](int v1, int v2)->int{return v1+v2;}, 0, in);
  CHECK_EQUAL(10, res);
  
  
  std::list<double> inl{-1.5, 2, 3.7, -4};
  auto resl = foldl([](double v1, double v2){return v1 + v2;}, 0, inl);
  CHECK_CLOSE(0.2, resl, 1e-6);
  
  std::vector<std::string> vs{"a", "b", "c", "d"};
  auto resvs = foldl([](std::string s, std::string s2) {return s+s2;}, "", vs);
  CHECK_EQUAL("abcd", resvs);
}

TEST(TestFoldR)
{
  std::vector<int> in{1,2,3,4};
  int res = foldr([](int v1, int v2)->int{return v1+v2;}, 0, in);
  CHECK_EQUAL(10, res);
  
  
  std::list<double> inl{-1.5, 2, 3.7, -4};
  auto resl = foldr([](double v1, double v2){return v1 + v2;}, 0, inl);
  CHECK_CLOSE(0.2, resl, 1e-6);
  
  std::vector<std::string> vs{"a", "b", "c", "d"};
  auto resvs = foldr([](std::string s, std::string s2) {return s+s2;}, "", vs);
  CHECK_EQUAL("dcba", resvs);
}

TEST(TestSum)
{
  CHECK_EQUAL(26, sum({12,5,-1,7,3}));
  CHECK_EQUAL(0, sum(std::vector<int>{}));

  CHECK_CLOSE(5.1, sum({0.1, -2., 7.0}), 1e-12);
}

TEST(TestProduct)
{
  CHECK_EQUAL(1, product(std::vector<int>{}));
  CHECK_EQUAL(0, product({12, 3, 0, 20, 17}));
  CHECK_EQUAL(1, product({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}));
  CHECK_EQUAL(-1, product(std::list<int>{1, -1}));
  CHECK_EQUAL(120, product({1, 2, 3, 4, 5}));

  CHECK_CLOSE(-3., product(std::vector<double>{0.1, -10., 3.0}), 1e-12);
}