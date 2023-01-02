#ifndef TRICYCLE_CONTROL__VISIBILITY_CONTROL_H_
#define TRICYCLE_CONTROL__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define TRICYCLE_CONTROL_EXPORT __attribute__ ((dllexport))
    #define TRICYCLE_CONTROL_IMPORT __attribute__ ((dllimport))
  #else
    #define TRICYCLE_CONTROL_EXPORT __declspec(dllexport)
    #define TRICYCLE_CONTROL_IMPORT __declspec(dllimport)
  #endif
  #ifdef TRICYCLE_CONTROL_BUILDING_LIBRARY
    #define TRICYCLE_CONTROL_PUBLIC TRICYCLE_CONTROL_EXPORT
  #else
    #define TRICYCLE_CONTROL_PUBLIC TRICYCLE_CONTROL_IMPORT
  #endif
  #define TRICYCLE_CONTROL_PUBLIC_TYPE TRICYCLE_CONTROL_PUBLIC
  #define TRICYCLE_CONTROL_LOCAL
#else
  #define TRICYCLE_CONTROL_EXPORT __attribute__ ((visibility("default")))
  #define TRICYCLE_CONTROL_IMPORT
  #if __GNUC__ >= 4
    #define TRICYCLE_CONTROL_PUBLIC __attribute__ ((visibility("default")))
    #define TRICYCLE_CONTROL_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define TRICYCLE_CONTROL_PUBLIC
    #define TRICYCLE_CONTROL_LOCAL
  #endif
  #define TRICYCLE_CONTROL_PUBLIC_TYPE
#endif

#endif  // TRICYCLE_CONTROL__VISIBILITY_CONTROL_H_
