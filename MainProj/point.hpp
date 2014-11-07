//Addanki Adithya
#ifndef POINT_HPP
#define POINT_HPP

#include "concepts.hpp"

template<typename T1, typename T2>
requires Regular<T1>() and Regular<T2>()
  class point {
  public:
    point() = default;
    
    point(T1 x, T2 y)
      : x(x), y(y) { }

    T1 x;
    T2 y;
  };

template<typename T1, typename T2, typename T3>
  requires Regular<T1>() and Regular<T2>() and Regular<T3>()  
  class point_3d {
  public:
    point_3d() = default;

    point_3d(T1 x, T2 y, T3 z)
      : x(x), y(y), z(z) { }

    T1 x; 
    T2 y;
    T3 z;
  };

#endif