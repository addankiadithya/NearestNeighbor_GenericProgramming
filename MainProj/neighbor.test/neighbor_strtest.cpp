//Addanki Adithya
#include "neighbor.hpp"
#include "test.hpp"
#include "strcls.hpp"
#include <vector>

using namespace std;

void test_strcls_test_1() {
StrCls<const char*> p1("karolin");
StrCls<const char*> p2("kathrin");
StrCls<const char*> p3("katrine");
StrCls<const char*> p4("concept");
StrCls<const char*> p5("program");
StrCls<const char*> origin("concept");
std::vector<StrCls<const char*>> first;
first.push_back(p1);
first.push_back(p2);
first.push_back(p3);
first.push_back(p4);
first.push_back(p5);
std::vector<StrCls<const char*>>::iterator it=first.begin();
try{
  StrCls<const char*> result= nearestpoint(it,first.end()-first.begin(), origin,&distanceHamming<const char*>);
  std::cout<<"Nearest Neighbor-->>  "<< result.x <<std::endl;
}
catch(std::exception& err)
{
throw failed;
}
}

void test_strcls_test_2() {
StrCls<const char*> p1("abcdef");
StrCls<const char*> p2("bcdefg");
StrCls<const char*> p3("njiklo");
StrCls<const char*> p4("abcded");
StrCls<const char*> p5("zxcvbnm");
StrCls<const char*> origin("abcdjksd");
std::vector<StrCls<const char*>> first;
first.push_back(p1);
first.push_back(p2);
first.push_back(p3);
first.push_back(p4);
first.push_back(p5);
std::vector<StrCls<const char*>>::iterator it=first.begin();
try{
  StrCls<const char*> result= nearestpoint(it,first.end()-first.begin(), origin,&distanceLevenshtein<const char*>);
  std::cout<<"Nearest Neighbor-->> "<< result.x <<std::endl;
}
catch(std::exception& err)
{
throw failed;
}
}

void test_strcls_test_3() {
StrCls<const char*> p1("abcdef");
StrCls<const char*> p2("bcdefg");
StrCls<const char*> p3("abgdef");
StrCls<const char*> p4("abcaef");
StrCls<const char*> p5("ghyuab");
StrCls<const char*> origin("abcdjh");
std::vector<StrCls<const char*>> first;
first.push_back(p1);
first.push_back(p2);
first.push_back(p3);
first.push_back(p4);
first.push_back(p5);
std::vector<StrCls<const char*>>::iterator it=first.begin();
try{
  StrCls<const char*> result= nearestpoint(it,first.end()-first.begin(), origin,&distanceHamming<const char*>);
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
  err += test(test_strcls_test_1);
  err += test(test_strcls_test_2);
  err += test(test_strcls_test_3);
  std::cout<<"The Number of errors in strcls test for Neighbor: "<<err<<std::endl;
  return err;
}
