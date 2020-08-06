//
// Created by thahnen on 13.02.20.
//

#ifndef SET_TYPE_H
#define SET_TYPE_H


/// Unified data type names
typedef float float32;
typedef double float64;


/// includes every supported set data type
typedef enum __attribute__ ((packed)) {
    NONE = 0,   // set type not set yet (set_empty function)
    PAIR,       // pair of values, result of cross product
    INT8,       // 8-Bit integer (signed)
    UINT8,      // 8-Bit integer (unsigned)
    INT16,      // 16-Bit integer (signed)
    UINT16,     // 16-Bit integer (unsigned)
    INT32,      // 32-Bit integer (signed)
    UINT32,     // 32-Bit integer (unsigned)
    INT64,      // 64-Bit integer (signed)
    UINT64,     // 64-Bit integer (unsigned)
    FLOAT32,    // 32-Bit floating point
    FLOAT64     // 64-Bit floating point
} TYPE;


/// pair structure
typedef struct {
    struct {
        TYPE type;
        void* value;
    } elem1;

    struct {
        TYPE type;
        void* value;
    } elem2;
} Pair;


/**
 *  Returns the type of given data type
 *  Excludes every pointer and some other
 *
 *  @param X        the data to get the type from
 *  @return         the corresponding enum item (eg. int8_t => INT8)
 */
#define getEnumType(X) _Generic((X), \
        int8_t : INT8, uint8_t : UINT8, \
        int16_t : INT16, uint16_t : UINT16, \
        int32_t : INT32, uint32_t : UINT32, \
        int64_t : INT64, uint64_t : UINT64, \
        float32 : FLOAT32, float64: FLOAT64, \
        Pair: PAIR, \
        default : NONE \
)


/**
 *  Returns the size of the data type corresponding to the given enum item in bytes
 *  Excludes NONE and PAIR
 *
 *  @param type     the enum item to get the data type size of
 *  @return         returns the data type size or 0
 *
 *  TODO: maybe change to macro using typeof(?)
 */
size_t getSize(TYPE type) {
    switch (type) {
        case INT8:      return sizeof(int8_t);
        case UINT8:     return sizeof(uint8_t);
        case INT16:     return sizeof(int16_t);
        case UINT16:    return sizeof(uint16_t);
        case INT32:     return sizeof(int32_t);
        case UINT32:    return sizeof(uint32_t);
        case FLOAT32:   return sizeof(float32);
        case FLOAT64:   return sizeof(float64);
        case PAIR:      return sizeof(Pair);
        default:        return 0;
    }
}


/**
 *  Returns the "maximum" possible data type of two given (for EVERY value)
 *  Meaning: Some values of INT8 fit into UINT8, but not all! So max{INT8, UINT8} -> NONE!
 *
 *  @param a        first type
 *  @param b        second type
 *  @return         "maximum" of both or, if not possible, NONE
 *
 *  TODO: maybe change rules converting integers to floating point variables
 */
TYPE max(TYPE a, TYPE b) {
    bool a_case = a == NONE;
    bool b_case = b == NONE;
    if (a_case || b_case) {
        // max{NONE, X}         := X
        return a_case ? b : a;
    }

    a_case = a == PAIR;
    b_case = b == PAIR;
    if (a_case || b_case) {
        // max{PAIR, PAIR}      := PAIR
        // max{PAIR, Y}         := NONE
        return (a_case && b_case) ? a : NONE;
    }

    a_case = a == INT8;
    b_case = b == INT8;
    if (a_case || b_case) {
        // max{INT8, INT8}       := INT8
        // max{INT8, INT16}      := INT16
        // max{INT8, INT32}      := INT32
        // max{INT8, INT64}      := INT64
        // max{INT8, Y}          := NONE
        return (a_case && b_case) ? a :
            ((a_case && b == INT16) || (b_case && a == INT16)) ? INT16 :
            ((a_case && b == INT32) || (b_case && a == INT32)) ? INT32 :
            ((a_case && b == INT64) || (b_case && a == INT64)) ? INT64 : NONE;
    }

    a_case = a == INT16;
    b_case = b == INT16;
    if (a_case || b_case) {
        // max{INT16, INT16}     := INT16
        // max{INT16, INT32}     := INT32
        // max{INT16, INT64}     := INT64
        // max{INT16, Y}         := NONE
        return (a_case && b_case) ? a :
            ((a_case && b == INT32) || (b_case && a == INT32)) ? INT32 :
            ((a_case && b == INT64) || (b_case && a == INT64)) ? INT64 : NONE;
    }

    a_case = a == INT32;
    b_case = b == INT32;
    if (a_case || b_case) {
        // max{INT32, INT32}     := INT32
        // max{INT32, INT64}     := INT64
        // max{INT32, Y}         := NONE
        return (a_case && b_case) ? a :
            ((a_case && b == INT64) || (b_case && a == INT64)) ? INT64 : NONE;
    }

    a_case = a == INT64;
    b_case = b == INT64;
    if (a_case || b_case) {
        // max{INT64, INT64}     := INT64
        // max{INT64, Y}         := NONE
        return (a_case && b_case) ? a : NONE;
    }

    a_case = a == UINT8;
    b_case = b == UINT8;
    if (a_case || b_case) {
        // max{UINT8, UINT8}     := UINT8
        // max{UINT8, UINT16}    := UINT16
        // max{UINT8, UINT32}    := UINT32
        // max{UINT8, UINT64}    := UINT64
        // max{UINT8, Y}         := NONE
        return (a_case && b_case) ? a :
               ((a_case && b == UINT16) || (b_case && a == UINT16)) ? UINT16 :
               ((a_case && b == UINT32) || (b_case && a == UINT32)) ? UINT32 :
               ((a_case && b == UINT64) || (b_case && a == UINT64)) ? UINT64 : NONE;
    }

    a_case = a == UINT16;
    b_case = b == UINT16;
    if (a_case || b_case) {
        // max{UINT16, UINT16}   := UINT16
        // max{UINT16, UINT32}   := UINT32
        // max{UINT16, UINT64}   := UINT64
        // max{UINT16, Y}        := NONE
        return (a_case && b_case) ? a :
               ((a_case && b == UINT32) || (b_case && a == UINT32)) ? UINT32 :
               ((a_case && b == UINT64) || (b_case && a == UINT64)) ? UINT64 : NONE;
    }

    a_case = a == UINT32;
    b_case = b == UINT32;
    if (a_case || b_case) {
        // max{UINT32, UINT32}   := UINT32
        // max{UINT32, UINT64}   := UINT64
        // max{UINT32, Y}        := NONE
        return (a_case && b_case) ? a :
               ((a_case && b == UINT64) || (b_case && a == UINT64)) ? UINT64 : NONE;
    }

    a_case = a == UINT64;
    b_case = b == UINT64;
    if (a_case || b_case) {
        // max{UINT64, UINT64}   := UINT64
        // max{UINT64, Y}        := NONE
        return (a_case && b_case) ? a : NONE;
    }

    a_case = a == FLOAT32;
    b_case = b == FLOAT32;
    if (a_case || b_case) {
        // max{FLOAT32, FLOAT32} := FLOAT32
        // max{FLOAT32, FLOAT64} := FLOAT64
        // max{FLOAT32, Y}       := NONE
        return (a_case && b_case) ? a :
               ((a_case && b == FLOAT64) || (b_case && a == FLOAT64)) ? FLOAT64 : NONE;
    }

    a_case = a == FLOAT64;
    b_case = b == FLOAT64;
    if (a_case || b_case) {
        // max{FLOAT64, FLOAT64} := FLOAT64
        // max{FLOAT64, Y}       := NONE
        return (a_case && b_case) ? a : NONE;
    }

    // Everything unimplemented!
    return NONE;
}


#endif //SET_TYPE_H
