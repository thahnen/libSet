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

#include <ll.h>


enum type {
    VOID = 0,   // set type not set yet (set_empty function)
    INT8,       // 8-Bit integer
    INT16,      // 16-Bit integer
    INT32,      // 32-Bit integer
    INT64,      // 64-Bit integer
    FLOAT32,    // 32-Bit floating point
    FLOAT64     // 64-Bit floating point
};


typedef struct {
    unsigned long size;
    struct node_t* root;
    struct node_t* end;
} set;

// Creates new empty set
set* set_empty();

// Create new set from data


#endif //LIBSET_LIBRARY_H
