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


// TODO: add preprocessor attribute (packed on memory efficiency, not packed on speed efficiency)
typedef struct __attribute__ ((packed)) {
    unsigned long size;
    TYPE type;
    node_t* root;
} set;


/**
 *  Creates an empty set
 *  Result assertion:      |R| = 0
 *
 *  @return a empty set containing zero items
 */
DLL set* set_empty();


/**
 *  Creates a new set with a single item, which is given
 *  Equals the operation:   R := { Y }
 *  Resulut assertion:     |R| = 1
 *
 *  @param X the item to start the set with
 *  @return a new set containg one item
 */
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


/**
 *  Adds a single item to an existing set
 *  Equals the operation:   R := X ∪ { Y }
 *  Result assertion:      |R| ≥ |X|
 *
 *  @param X the existing set to add to
 *  @param Y the item to add to the set
 *  @return true if operation successful, false otherwise
 *
 *  TODO: add operation X ∪ V, where X is set and V is vector, and X ∪ Z, where X,Z are sets
 */
#define set_add(X, Y) _Generic((Y) \
        int8_t : set_add_i8, uint8_t : set_add_u8, \
        int16_t : set_add_i16, uint16_t : set_add_u16, \
        int32_t : set_add_i32, uint32_t : set_add_u32, \
        int64_t : set_add_i64, uint64_t : set_add_u64, \
        float32 : set_add_f32, float64 : set_add_f64 \
) (X, Y)

DLL bool set_add_i8(NOT$NULL set* cur, int8_t value);
DLL bool set_add_u8(NOT$NULL set* cur, uint8_t value);

DLL bool set_add_i16(NOT$NULL set* cur, int16_t value);
DLL bool set_add_u16(NOT$NULL set* cur, uint16_t value);

DLL bool set_add_i32(NOT$NULL set* cur, int32_t value);
DLL bool set_add_u32(NOT$NULL set* cur, uint32_t value);

DLL bool set_add_i64(NOT$NULL set* cur, int64_t value);
DLL bool set_add_u64(NOT$NULL set* cur, uint64_t value);

DLL bool set_add_f32(NOT$NULL set* cur, float32 value);
DLL bool set_add_f64(NOT$NULL set* cur, float64 value);


/**
 *  Gets the minimum value from given set
 *  Equals the operation:   R := min X
 *
 *  @param X the existing set to get the minimum from
 *  @param Y pointer to variable to store the value to
 *  @return true if there is a minimum, false otherwise
 *
 *  TODO: Add support for pair!
 */
#define set_min(X, Y) _Generic((Y) \
        int8_t* : set_min_i8, uint8_t* : set_min_u8, \
        int16_t* : set_min_i16, uint16_t* : set_min_u16, \
        int32_t* : set_min_i32, uint32_t* : set_min_u32, \
        int64_t* : set_min_i64, uint64_t* : set_min_u64, \
        float32* : set_min_f32, float64* : set_min_f64 \
) (X, Y)

DLL inline bool set_min_i8(NOT$NULL set* cur, NOT$NULL int8_t* result);
DLL inline bool set_min_u8(NOT$NULL set* cur, NOT$NULL uint8_t* result);

DLL inline bool set_min_i16(NOT$NULL set* cur, NOT$NULL int16_t* result);
DLL inline bool set_min_u16(NOT$NULL set* cur, NOT$NULL uint16_t* result);

DLL inline bool set_min_i32(NOT$NULL set* cur, NOT$NULL int32_t* result);
DLL inline bool set_min_u32(NOT$NULL set* cur, NOT$NULL uint32_t* result);

DLL inline bool set_min_i64(NOT$NULL set* cur, NOT$NULL int64_t* result);
DLL inline bool set_min_u64(NOT$NULL set* cur, NOT$NULL uint64_t* result);

DLL inline bool set_min_f32(NOT$NULL set* cur, NOT$NULL float32* result);
DLL inline bool set_min_f64(NOT$NULL set* cur, NOT$NULL float64* result);


/**
 *  Gets the maximum value from given set
 *  Equals the operation:   R := max X
 *
 *  @param X the existing set to get the maximum from
 *  @param Y pointer to variable to store the value to
 *  @return true if there is a maximum, false otherwise
 *
 *  TODO: Add support for pair!
 */
#define set_max(X, Y) _Generic((Y) \
        int8_t* : set_max_i8, uint8_t* : set_max_u8, \
        int16_t* : set_max_i16, uint16_t* : set_max_u16, \
        int32_t* : set_max_i32, uint32_t* : set_max_u32, \
        int64_t* : set_max_i64, uint64_t* : set_max_u64, \
        float32* : set_max_f32, float64* : set_max_f64 \
) (X, Y)

DLL bool set_max_i8(NOT$NULL set* cur, NOT$NULL int8_t* result);
DLL bool set_max_u8(NOT$NULL set* cur, NOT$NULL uint8_t* result);

DLL bool set_max_i16(NOT$NULL set* cur, NOT$NULL int16_t* result);
DLL bool set_max_u16(NOT$NULL set* cur, NOT$NULL uint16_t* result);

DLL bool set_max_i32(NOT$NULL set* cur, NOT$NULL int32_t* result);
DLL bool set_max_u32(NOT$NULL set* cur, NOT$NULL uint32_t* result);

DLL bool set_max_i64(NOT$NULL set* cur, NOT$NULL int64_t* result);
DLL bool set_max_u64(NOT$NULL set* cur, NOT$NULL uint64_t* result);

DLL bool set_max_f32(NOT$NULL set* cur, NOT$NULL float32* result);
DLL bool set_max_f64(NOT$NULL set* cur, NOT$NULL float64* result);


/**
 *  Adds two sets together
 *  Equals the operation:   R := A ∪ B
 *  Result assertion:      |R| <= |A| + |B|
 *
 *  @param A first input set
 *  @param B second input set
 *  @param out resulting set
 *  @return true if union created, false otherwise
 */
DLL bool set_union(NOT$NULL set* A, NOT$NULL set* B, NOT$NULL set* out);


/**
 *  Intersects two sets
 *  Equals the operation:   R := A ∩ B
 *  Result assertion:      |R| ...
 *
 *  @param A first input set
 *  @param B second input set
 *  @param out resulting set
 *  @return true if intersection created, false otherwise
 */
DLL bool set_intersect(NOT$NULL set* A, NOT$NULL set* B, NOT$NULL set* out);


/**
 *  Returns every item in A but not in B
 *  Equals the operation:   R := A \ B
 *  Result assertion:      |R| ...
 *
 *  @param A first input set
 *  @param B second input set
 *  @param out resulting set
 *  @return true if difference created, false otherwise
 */
DLL bool set_difference(NOT$NULL set* A, NOT$NULL set* B, NOT$NULL set* out);


/**
 *  Returns every item in A, B but not in both
 *  Equals the operation:   R := A Δ B
 *  Result assertion:      |R| ...
 *
 *  @param A first input set
 *  @param B second input set
 *  @param out resulting set
 *  @return true if symmetric difference created, false otherwise
 */
DLL bool set_symdifference(NOT$NULL set* A, NOT$NULL set* B, NOT$NULL set* out);


/**
 *  Returns every pair from the cartesian product from items in A, B
 *  Equals the operation:   R := A x B
 *  Result assertion:       ...
 *
 *  @param A first input set
 *  @param B second input set
 *  @param out resulting set
 *  @return true if cartesian products created, false otherwise
 */
DLL bool set_cartesian(NOT$NULL set* A, NOT$NULL set* B, NOT$NULL set* out);


/**
 *  Returns every subset of given input set A
 *
 *  @param A input set
 *  @param out output power set
 *  @return true if power set created, false otherwise
 */
DLL bool set_powerset(NOT$NULL set* A, NOT$NULL set** out);


/**
 *  Checks if A is a subset of given subset B
 *
 *  @param A maybe subset
 *  @param B maybe superset
 *  @return true if A is subset, false otherwise
 */
DLL bool set_subsetof(NOT$NULL set* A, NOT$NULL set* B);


#endif //LIBSET_LIBRARY_H
