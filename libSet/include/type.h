//
// Created by thahnen on 13.02.20.
//

#ifndef SET_TYPE_H
#define SET_TYPE_H


/// Unified data type names
typedef float float32;
typedef double float64;


/// Includes every supported set data type
enum TYPE {
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
};


/**
 *  Returns the type of given data
 *  Excludes every pointer and some other
 *
 *  @param X        the data to get the type from
 *  @return         the corresponding enum item (eg. int8_t => INT8)
 */
#define getType(X) _Generic((X), \
                int8_t : INT8, uint8_t : UINT8, \
                int16_t : INT16, uint16_t : UINT16, \
                int32_t : INT32, uint32_t : UINT32, \
                int64_t : INT64, uint64_t : UINT64, \
                float32 : FLOAT32, float64: FLOAT64, \
                default : NONE \
)


#endif //SET_TYPE_H
