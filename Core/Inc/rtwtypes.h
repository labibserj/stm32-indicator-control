/*
 * rtwtypes.h
 * Standard Simulink Coder type definitions for ARM Cortex-M
 * Compatible with R2025a generated code
 */

#ifndef RTWTYPES_H
#define RTWTYPES_H

#include <stdint.h>
#include <stdbool.h>

/* Logical type definitions */
typedef bool boolean_T;

/* Integer type definitions */
typedef int8_t   int8_T;
typedef uint8_t  uint8_T;
typedef int16_t  int16_T;
typedef uint16_t uint16_T;
typedef int32_t  int32_T;
typedef uint32_t uint32_T;
typedef int64_t  int64_T;
typedef uint64_t uint64_T;

/* Floating point type definitions */
typedef float    real32_T;
typedef double   real_T;

/* Character type */
typedef char     char_T;

/* Pointer to void */
typedef void *   pointer_T;

/* Generic integer */
typedef int      int_T;
typedef unsigned uint_T;

/* Byte type */
typedef unsigned char byte_T;

/* Unused parameter macro */
#ifndef UNUSED_PARAMETER
#define UNUSED_PARAMETER(x)   (void)(x)
#endif

/* NULL definition */
#ifndef NULL
#define NULL   (0)
#endif

#endif /* RTWTYPES_H */
