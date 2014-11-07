//Addanki Adithya
#include "neighbor.hpp"
#include "test.hpp"
#include "point.hpp"
#include <vector>

using namespace std;

void test_pointtest_1() {
point<int, int> p1(2,3);
point<int, int> p2(4,3);
point<int, int> p3(5,3);
point<int, int> p4(6,3);
point<int, int> p5(1,3);
point<int, int> origin(0,0);
std::vector<point<int, int>> first;
first.push_back(p1);
first.push_back(p2);
first.push_back(p3);
first.push_back(p4);
first.push_back(p5);
std::vector<point<int, int>>::iterator it=first.begin();
try{
  point<int,int> result= nearestpoint(it,first.end()-first.begin(), origin,&distanceEucl<int, int>);
  std::cout<<"Nearest Neighbor-->>  x: "<< result.x <<"  y: "<< result.y <<std::endl;
}
catch(std::exception& err)
{
throw failed;
}
}

void test_pointtest_2() {
point<float,float> p1(2.5,3.4);
point<float,float> p2(4.2,3.2);
point<float,float> p3(5.2,3.0);
point<float,float> p4(6.4,3.6);
point<float,float> p5(1.1,3.0);
point<float,float> origin(0.9,0.1);
std::vector<point<float,float>> first;
first.push_back(p1);
first.push_back(p2);
first.push_back(p3);
first.push_back(p4);
first.push_back(p5);
std::vector<point<float,float>>::iterator it=first.begin();
try{
  point<float,float> result= nearestpoint(it,first.end()-first.begin(), origin,&distanceEucl<float, float>);
  std::cout<<"Nearest Neighbor-->>  x: "<< result.x <<"  y: "<< result.y <<std::endl;
}
catch(std::exception& err)
{
throw failed;
}
}

void test_pointtest_3() {
point<char,char> p1('a','a');
point<char,char> p2('b','b');
point<char,char> p3('c','b');
point<char,char> p4('d','a');
point<char,char> p5('g','e');
point<char,char> origin('b','b');
std::vector<point<char,char>> first;
first.push_back(p1);
first.push_back(p2);
first.push_back(p3);
first.push_back(p4);
first.push_back(p5);
std::vector<point<char,char>>::iterator it=first.begin();
try{
  point<char,char> result= nearestpoint(it,first.end()-first.begin(), origin,&distanceEucl<char,char>);
  std::cout<<"Nearest Neighbor-->>  x: "<< result.x <<"  y: "<< result.y <<std::endl;
}
catch(std::exception& err)
{
throw failed;
}
}

int main() {
  int err = 0;
  err += test(test_pointtest_1);
  err += test(test_pointtest_2);
  err += test(test_pointtest_3);
  std::cout<<"The Number of errors in point test for Neighbor: "<<err<<std::endl;
  return err;
}
