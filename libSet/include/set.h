//
// Created by thahnen on 12.02.20.
//

#pragma once
#ifndef LIBSET_LIBRARY_H
#define LIBSET_LIBRARY_H

#if defined (_WIN32) || defined (__CYGWIN__)
#	if defined (__GNUC__)
#		define DLL __attribute__ ((dllexport))
#	elif defined (_MSC_VER)
#		define DLL __declspec(dllexport)
#	else
#		error "No suitable Compiler (GCC / MSVC) used (Windows + WIN_EXPORT)!"
#	endif
#else
#   if defined (__GNUC__)
#       define DLL __attribute__ ((visibility("default")))
#   else
#       error "No suitable Compiler (GCC) used (non Windows)!"
#   endif
#endif

#include <stdint.h>
#include <stdbool.h>

#include "ll.h"
#include "type.h"


typedef struct {
    enum TYPE type;
    unsigned long size;
    node_t* root;
    node_t* last;
} set;

/**
 *  Creates an empty set
 *
 *  @return         a empty set containing zero items
 */
DLL set* set_empty();


// Create new set from given data
#define set_create(X) _Generic((X), \
        int8_t : set_create_i8, uint8_t : set_create_u8, \
        int16_t : set_create_i16, uint16_t : set_create_u16, \
        int32_t : set_create_i32, uint32_t : set_create_u32, \
        int64_t : set_create_i64, uint64_t : set_create_u64, \
        float32 : set_create_f32, float64 : set_create_f64, \
        default: set_create_i32 \
) (X)

DLL set* set_create_i8(int8_t value);
DLL set* set_create_u8(uint8_t value);

DLL set* set_create_i16(int16_t value);
DLL set* set_create_u16(uint16_t value);

DLL set* set_create_i32(int32_t value);
DLL set* set_create_u32(uint32_t value);

DLL set* set_create_i64(int64_t value);
DLL set* set_create_u64(uint64_t value);

DLL set* set_create_f32(float32 value);
DLL set* set_create_f64(float64 value);


// Add a value to given set
#define set_add(X, Y) _Generic((Y) \
        int8_t : set_add_i8, uint8_t : set_add_u8, \
        int16_t : set_add_i16, uint16_t : set_add_u16, \
        int32_t : set_add_i32, uint32_t : set_add_u32, \
        int64_t : set_add_i64, uint64_t : set_add_u64, \
        float32 : set_add_f32, float64 : set_add_f64 \
) (X, Y)

DLL bool set_add_i8(set* cur, int8_t value);
DLL bool set_add_u8(set* cur, uint8_t value);

DLL bool set_add_i16(set* cur, int16_t value);
DLL bool set_add_u16(set* cur, uint16_t value);

DLL bool set_add_i32(set* cur, int32_t value);
DLL bool set_add_u32(set* cur, uint32_t value);

DLL bool set_add_i64(set* cur, int64_t value);
DLL bool set_add_u64(set* cur, uint64_t value);

DLL bool set_add_f32(set* cur, float32 value);
DLL bool set_add_f64(set* cur, float64 value);


// Get the minimum value from given set
#define set_min(X, Y) _Generic((Y) \
        int8_t : set_min_i8, uint8_t : set_min_u8, \
        int16_t : set_min_i16, uint16_t : set_min_u16, \
        int32_t : set_min_i32, uint32_t : set_min_u32, \
        int64_t : set_min_i64, uint64_t : set_min_u64, \
        float32 : set_min_f32, float64 : set_min_f64 \
) (X, Y)

DLL bool set_min_i8(set* cur, int8_t* result);
DLL bool set_min_u8(set* cur, uint8_t* result);

DLL bool set_min_i16(set* cur, int16_t* result);
DLL bool set_min_u16(set* cur, uint16_t* result);

DLL bool set_min_i32(set* cur, int32_t* result);
DLL bool set_min_u32(set* cur, uint32_t* result);

DLL bool set_min_i64(set* cur, int64_t* result);
DLL bool set_min_u64(set* cur, uint64_t* result);

DLL bool set_min_f32(set* cur, float32* result);
DLL bool set_min_f64(set* cur, float64* result);


// Get the maximum value from given set
#define set_max(X, Y) _Generic((Y) \
        int8_t : set_max_i8, uint8_t : set_max_u8, \
        int16_t : set_max_i16, uint16_t : set_max_u16, \
        int32_t : set_max_i32, uint32_t : set_max_u32, \
        int64_t : set_max_i64, uint64_t : set_max_u64, \
        float32 : set_max_f32, float64 : set_max_f64 \
) (X, Y)

//DLL bool set_max_(set* cur, void* result, enum TYPE type);

DLL bool set_max_i8(set* cur, int8_t* result);
DLL bool set_max_u8(set* cur, uint8_t* result);

DLL bool set_max_i16(set* cur, int16_t* result);
DLL bool set_max_u16(set* cur, uint16_t* result);

DLL bool set_max_i32(set* cur, int32_t* result);
DLL bool set_max_u32(set* cur, uint32_t* result);

DLL bool set_max_i64(set* cur, int64_t* result);
DLL bool set_max_u64(set* cur, uint64_t* result);

DLL bool set_max_f32(set* cur, float32* result);
DLL bool set_max_f64(set* cur, float64* result);


#endif //LIBSET_LIBRARY_H
