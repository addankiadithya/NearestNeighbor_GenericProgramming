//Addanki Adithya
#include "neighbor.hpp"
#include "test.hpp"
#include "point.hpp"
#include <vector>

using namespace std;

void test_point_3dtest_1() {
point_3d<int, int, int> p1(2,3,3);
point_3d<int, int, int> p2(4,3,5);
point_3d<int, int, int> p3(5,3,4);
point_3d<int, int, int> p4(6,3,1);
point_3d<int, int, int> p5(1,3,6);
point_3d<int, int, int> origin(0,0,0);

std::vector<point_3d<int, int, int>> first;
first.push_back(p1);
first.push_back(p2);
first.push_back(p3);
first.push_back(p4);
first.push_back(p5);
std::vector<point_3d<int, int,int>>::iterator it=first.begin();
try{
  point_3d<int,int,int> result= nearestpoint(it,first.end()-first.begin(), origin,&distanceEucl3<int, int,int>);
  std::cout<<"Nearest Neighbor-->>  x: "<< result.x <<"  y: "<< result.y  <<"  z: "<< result.z <<std::endl;
}
catch(std::exception& err)
{
throw failed;
}
}

void test_point_3dtest_2() {
point_3d<float,float,float> p1(2.5,3.4,4.5);
point_3d<float,float,float> p2(4.2,3.2,4.5);
point_3d<float,float,float> p3(5.2,3.0,8.0);
point_3d<float,float,float> p4(6.4,3.6,1.2);
point_3d<float,float,float> p5(1.1,3.0,2.2);
point_3d<float,float,float> origin(0.9,0.1,0.0);
std::vector<point_3d<float,float,float>> first;
first.push_back(p1);
first.push_back(p2);
first.push_back(p3);
first.push_back(p4);
first.push_back(p5);
std::vector<point_3d<float,float,float>>::iterator it=first.begin();
try{
  point_3d<float,float,float> result= nearestpoint(it,first.end()-first.begin(), origin,&distanceEucl3<float,float, float>);
  std::cout<<"Nearest Neighbor-->>  x: "<< result.x <<"  y: "<< result.y  <<"  z: "<< result.z <<std::endl;
}
catch(std::exception& err)
{
throw failed;
}
}


int main() {
  int err = 0;
  err += test(test_point_3dtest_1);
  err += test(test_point_3dtest_2);
  std::cout<<"The Number of errors in point_3d test for Neighbor: "<<err<<std::endl;
  return err;
}
