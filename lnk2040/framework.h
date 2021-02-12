#pragma once
#include <string>

class dynamic
{
   template <class T>
   struct TypeInfo;

public:
   template <class T>
   bool get()
   {
      return TypeInfo<T>::name[0];
   }
};

template<>
struct dynamic::TypeInfo<std::string> {
   static const char* const name;
};

