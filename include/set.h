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


// TODO: Add preprocessor symbol (packed on memory efficiency, not packed on speed efficiency)
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
DLL set* set_empty() NONNULLRETURN;


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

DLL set* set_create_i8(int8_t value) NONNULLRETURN;
DLL set* set_create_u8(uint8_t value) NONNULLRETURN;

DLL set* set_create_i16(int16_t value) NONNULLRETURN;
DLL set* set_create_u16(uint16_t value) NONNULLRETURN;

DLL set* set_create_i32(int32_t value) NONNULLRETURN;
DLL set* set_create_u32(uint32_t value) NONNULLRETURN;

DLL set* set_create_i64(int64_t value) NONNULLRETURN;
DLL set* set_create_u64(uint64_t value) NONNULLRETURN;

DLL set* set_create_f32(float32 value) NONNULLRETURN;
DLL set* set_create_f64(float64 value) NONNULLRETURN;


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

DLL bool set_add_i8(set* cur, int8_t value) NONNULL((1));
DLL bool set_add_u8(set* cur, uint8_t value) NONNULL((1));

DLL bool set_add_i16(set* cur, int16_t value) NONNULL((1));
DLL bool set_add_u16(set* cur, uint16_t value) NONNULL((1));

DLL bool set_add_i32(set* cur, int32_t value) NONNULL((1));
DLL bool set_add_u32(set* cur, uint32_t value) NONNULL((1));

DLL bool set_add_i64(set* cur, int64_t value) NONNULL((1));
DLL bool set_add_u64(set* cur, uint64_t value) NONNULL((1));

DLL bool set_add_f32(set* cur, float32 value) NONNULL((1));
DLL bool set_add_f64(set* cur, float64 value) NONNULL((1));


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

DLL bool set_min_i8(set* restrict cur, int8_t* restrict result) NONNULL((1, 2));
DLL bool set_min_u8(set* restrict cur, uint8_t* restrict result) NONNULL((1, 2));

DLL bool set_min_i16(set* restrict cur, int16_t* restrict result) NONNULL((1, 2));
DLL bool set_min_u16(set* restrict cur, uint16_t* restrict result) NONNULL((1, 2));

DLL bool set_min_i32(set* restrict cur, int32_t* restrict result) NONNULL((1, 2));
DLL bool set_min_u32(set* restrict cur, uint32_t* restrict result) NONNULL((1, 2));

DLL bool set_min_i64(set* restrict cur, int64_t* restrict result) NONNULL((1, 2));
DLL bool set_min_u64(set* restrict cur, uint64_t* restrict result) NONNULL((1, 2));

DLL bool set_min_f32(set* restrict cur, float32* restrict result) NONNULL((1, 2));
DLL bool set_min_f64(set* restrict cur, float64* restrict result) NONNULL((1, 2));


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

DLL bool set_max_i8(set* restrict cur, int8_t* restrict result) NONNULL((1, 2));
DLL bool set_max_u8(set* restrict cur, uint8_t* restrict result) NONNULL((1, 2));

DLL bool set_max_i16(set* restrict cur, int16_t* restrict result) NONNULL((1, 2));
DLL bool set_max_u16(set* restrict cur, uint16_t* restrict result) NONNULL((1, 2));

DLL bool set_max_i32(set* restrict cur, int32_t* restrict result) NONNULL((1, 2));
DLL bool set_max_u32(set* restrict cur, uint32_t* restrict result) NONNULL((1, 2));

DLL bool set_max_i64(set* restrict cur, int64_t* restrict result) NONNULL((1, 2));
DLL bool set_max_u64(set* restrict cur, uint64_t* restrict result) NONNULL((1, 2));

DLL bool set_max_f32(set* restrict cur, float32* restrict result) NONNULL((1, 2));
DLL bool set_max_f64(set* restrict cur, float64* restrict result) NONNULL((1, 2));


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
DLL bool set_union(set* A, set* B, set* out) NONNULL((1, 2, 3));


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
DLL bool set_intersect(set* A, set* B, set* out) NONNULL((1, 2, 3));


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
DLL bool set_difference(set* A, set* B, set* out) NONNULL((1, 2, 3));


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
DLL bool set_symdifference(set* A, set* B, set* out) NONNULL((1, 2, 3));


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
DLL bool set_cartesian(set* A, set* B, set* out) NONNULL((1, 2, 3));


/**
 *  Returns every subset of given input set A
 *
 *  @param A input set
 *  @param out output power set
 *  @return true if power set created, false otherwise
 */
DLL bool set_powerset(set* A, set* * out) NONNULL((1, 2));


/**
 *  Checks if A is a subset of given subset B
 *
 *  @param A maybe subset
 *  @param B maybe superset
 *  @return true if A is subset, false otherwise
 */
DLL bool set_subsetof(set* A, set* B) NONNULL((1, 2));


#endif //LIBSET_LIBRARY_H
