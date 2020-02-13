//
// Created by thahnen on 13.02.20.
//

#ifndef SET_TYPE_H
#define SET_TYPE_H


typedef float float32;
typedef double float64;


enum TYPE {
    VOID = 0,   // set type not set yet (set_empty function)
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

#define getType(X) _Generic((X), \
                int8_t : INT8, uint8_t : UINT8, \
                int16_t : INT16, uint16_t : UINT16, \
                int32_t : INT32, uint32_t : UINT32, \
                int64_t : INT64, uint64_t : UINT64, \
                float32 : FLOAT32, float64: FLOAT64, \
                default : VOID \
)


#endif //SET_TYPE_H
