#ifndef PLAIN_VEHICLE_CONTROL__VISIBILITY_CONTROL_H_
#define PLAIN_VEHICLE_CONTROL__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define PLAIN_VEHICLE_CONTROL_EXPORT __attribute__ ((dllexport))
    #define PLAIN_VEHICLE_CONTROL_IMPORT __attribute__ ((dllimport))
  #else
    #define PLAIN_VEHICLE_CONTROL_EXPORT __declspec(dllexport)
    #define PLAIN_VEHICLE_CONTROL_IMPORT __declspec(dllimport)
  #endif
  #ifdef PLAIN_VEHICLE_CONTROL_BUILDING_LIBRARY
    #define PLAIN_VEHICLE_CONTROL_PUBLIC PLAIN_VEHICLE_CONTROL_EXPORT
  #else
    #define PLAIN_VEHICLE_CONTROL_PUBLIC PLAIN_VEHICLE_CONTROL_IMPORT
  #endif
  #define PLAIN_VEHICLE_CONTROL_PUBLIC_TYPE PLAIN_VEHICLE_CONTROL_PUBLIC
  #define PLAIN_VEHICLE_CONTROL_LOCAL
#else
  #define PLAIN_VEHICLE_CONTROL_EXPORT __attribute__ ((visibility("default")))
  #define PLAIN_VEHICLE_CONTROL_IMPORT
  #if __GNUC__ >= 4
    #define PLAIN_VEHICLE_CONTROL_PUBLIC __attribute__ ((visibility("default")))
    #define PLAIN_VEHICLE_CONTROL_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define PLAIN_VEHICLE_CONTROL_PUBLIC
    #define PLAIN_VEHICLE_CONTROL_LOCAL
  #endif
  #define PLAIN_VEHICLE_CONTROL_PUBLIC_TYPE
#endif

#endif  // PLAIN_VEHICLE_CONTROL__VISIBILITY_CONTROL_H_
