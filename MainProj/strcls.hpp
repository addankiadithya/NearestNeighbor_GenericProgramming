//Addanki Adithya
#ifndef STRCLS_HPP
#define STRCLS_HPP

template<typename T1>
requires Semiregular<T1>()
  class StrCls {
  public:
    StrCls() = default;
    
    StrCls(T1 x)
      : x(x){ }

    const char* x;
};

#endif