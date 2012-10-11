#include "unittest++/UnitTest++.h"
#include "../src/cppfunc.h"

#include <list>
#include <vector>
#include <string>


using namespace cppfunc;

TEST(TestFilter)
{
    std::vector<int> in{0,3,7,-5,2,15};
    CHECK(equal(std::vector<int>{7,15}, filter([](int v){return v>5;}, in)));    
    CHECK(equal(std::vector<int>{3,7,2,15}, filter([](int v){return v>0;}, in)));
    CHECK(equal(std::vector<int>{0,-5,2}, filter([](int v){return v<3;}, in)));
    
    CHECK(equal(std::vector<int>{}, filter([](int v){return v>0;}, std::vector<int>{})));
    
    CHECK(equal(std::list<double>{2,4}, filter([](double v){return v>0;}, std::list<double>{0,-1,2,-3,4})));
    
    CHECK(equal(std::list<std::string>{"long", "very long"}, 
          filter([](std::string v){return v.length()>3;}, std::list<std::string>{"a", "v", "long", "sm", "very long"})));
}