#include "unittest++/UnitTest++.h"
#include "../src/cppfunc.h"

#include <list>
#include <vector>
#include <string>


using namespace cppfunc;

TEST(TestZipWith)
{
    std::vector<int> in1{0,1,2,3}, in2{5,6,7,8}, in3{2,2};
    
    CHECK(equal({5,7,9,11},
          zipWith([](int v1, int v2){return v1+v2;}, in1, in2)));
          
    CHECK(equal({5,5,5,5},
          zipWith([](int v1, int v2){return v2-v1;}, in1, in2)));
          
    CHECK(equal({2,3},
          zipWith([](int v1, int v2){return v1+v2;}, in1, in3)));
}