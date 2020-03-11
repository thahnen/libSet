//
// Created by thahnen on 13.02.20.
//

#ifndef SET_TYPE_H
#define SET_TYPE_H


/// Unified data type names
typedef float float32;
typedef double float64;


/// Includes every supported set data type
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
        default:        return 0;
    }
}


#endif //SET_TYPE_H
