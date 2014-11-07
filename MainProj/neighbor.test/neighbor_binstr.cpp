//Addanki Adithya
#include "neighbor.hpp"
#include "test.hpp"
#include "binstr.hpp"
#include <vector>

using namespace std;

void test_binstr_test_1() {
BinStr<const char*> p1("1001010101");
BinStr<const char*> p2("0101010101");
BinStr<const char*> p3("0101010111");
BinStr<const char*> p4("1111111000");
BinStr<const char*> p5("0111000111");
BinStr<const char*> origin("0000001000");
std::vector<BinStr<const char*>> first;
first.push_back(p1);
first.push_back(p2);
first.push_back(p3);
first.push_back(p4);
first.push_back(p5);
std::vector<BinStr<const char*>>::iterator it=first.begin();
try{
  BinStr<const char*> result=nearestpoint(it,first.end()-first.begin(), origin,&distanceJaccard<const char*>);
  std::cout<<"Nearest Neighbor-->>  "<< result.x <<std::endl;
}
catch(std::exception& err)
{
throw failed;
}
}

void test_binstr_test_2() {
BinStr<const char*> p1("1001010101");
BinStr<const char*> p2("0000001000");
BinStr<const char*> p3("0101010111");
BinStr<const char*> p4("1111111000");
BinStr<const char*> p5("0111000111");
BinStr<const char*> origin("0101010101");
std::vector<BinStr<const char*>> first;
first.push_back(p1);
first.push_back(p2);
first.push_back(p3);
first.push_back(p4);
first.push_back(p5);
std::vector<BinStr<const char*>>::iterator it=first.begin();
try{
  BinStr<const char*> result=nearestpoint(it,first.end()-first.begin(), origin,&distanceJaccard<const char*>);
  std::cout<<"Nearest Neighbor-->>  "<< result.x <<std::endl;
}
catch(std::exception& err)
{
throw failed;
}
}

int main() {
  int err = 0;
  //std::cout<<"Main"<<std::endl;
  err += test(test_binstr_test_1);
  err += test(test_binstr_test_2);
  std::cout<<"The Number of errors in binstr test for Neighbor: "<<err<<std::endl;
  return err;
}
