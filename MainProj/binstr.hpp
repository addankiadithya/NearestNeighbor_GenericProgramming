//Addanki Adithya
#ifndef BINSTR_HPP
#define BINSTR_HPP

template<typename T1>
requires Semiregular<T1>()
  class BinStr {
  public:
    BinStr() = default;
    
    BinStr(T1 x)
      : x(x){ }

    const char* x;
};

#endif