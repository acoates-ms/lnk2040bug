#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>

#include <string>

class dynamic
{
   enum Type
   {
      NULLT,
      ARRAY,
      BOOL,
      DOUBLE,
      INT64,
      OBJECT,
      STRING,
   };

   template <class T>
   struct TypeInfo;

public:

   template <class T>
   T& get()
   {
      throw std::exception(TypeInfo<T>::name);
   }
};

#define FOLLY_DYNAMIC_DEC_TYPEINFO(T, val)     \
  template <>                                  \
  struct dynamic::TypeInfo<T> {                \
    static const char *const name;             \
    static constexpr dynamic::Type type = val; \
  };                                           \
  //
FOLLY_DYNAMIC_DEC_TYPEINFO(std::nullptr_t, dynamic::NULLT)
FOLLY_DYNAMIC_DEC_TYPEINFO(bool, dynamic::BOOL)
FOLLY_DYNAMIC_DEC_TYPEINFO(std::string, dynamic::STRING)
FOLLY_DYNAMIC_DEC_TYPEINFO(double, dynamic::DOUBLE)
FOLLY_DYNAMIC_DEC_TYPEINFO(int64_t, dynamic::INT64)
#undef FOLLY_DYNAMIC_DEC_TYPEINFO