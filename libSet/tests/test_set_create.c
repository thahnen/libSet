//
// Created by thahnen on 04.10.21.
//

#include "Unittests.h"


/// test cases on set_create* function
START_TEST(test_set_create_i8) {
    int8_t value = INT8_MAX;
    set* t1 = set_create_i8(value);
    
    ck_assert_int_eq(t1->size, 1);
    ck_assert_int_eq(t1->type, INT8);
    ck_assert_ptr_ne(t1->root, NULL);
    
    node_t* elem1 = t1->root;
    
    ck_assert_int_eq(*((int8_t*)elem1->data), value);
    ck_assert_ptr_eq(elem1->next, NULL);
} END_TEST

START_TEST(test_set_create_u8) {
    uint8_t value = UINT8_MAX;
    set* t1 = set_create_u8(value);
    
    ck_assert_int_eq(t1->size, 1);
    ck_assert_int_eq(t1->type, UINT8);
    ck_assert_ptr_ne(t1->root, NULL);
    
    node_t* elem1 = t1->root;
    
    ck_assert_int_eq(*((uint8_t*)elem1->data), value);
    ck_assert_ptr_eq(elem1->next, NULL);
} END_TEST


START_TEST(test_set_create_i16) {
    int16_t value = INT16_MAX;
    set* t1 = set_create_i16(value);
    
    ck_assert_int_eq(t1->size, 1);
    ck_assert_int_eq(t1->type, INT16);
    ck_assert_ptr_ne(t1->root, NULL);
    
    node_t* elem1 = t1->root;
    
    ck_assert_int_eq(*((int16_t*)elem1->data), value);
    ck_assert_ptr_eq(elem1->next, NULL);
} END_TEST

START_TEST(test_set_create_u16) {
    uint16_t value = UINT16_MAX;
    set* t1 = set_create_u16(value);
    
    ck_assert_int_eq(t1->size, 1);
    ck_assert_int_eq(t1->type, UINT16);
    ck_assert_ptr_ne(t1->root, NULL);
    
    node_t* elem1 = t1->root;
    
    ck_assert_int_eq(*((uint16_t*)elem1->data), value);
    ck_assert_ptr_eq(elem1->next, NULL);
} END_TEST


START_TEST(test_set_create_i32) {
    int32_t value = INT32_MAX;
    set* t1 = set_create_i32(value);
    
    ck_assert_int_eq(t1->size, 1);
    ck_assert_int_eq(t1->type, INT32);
    ck_assert_ptr_ne(t1->root, NULL);
    
    node_t* elem1 = t1->root;
    
    ck_assert_int_eq(*((int32_t*)elem1->data), value);
    ck_assert_ptr_eq(elem1->next, NULL);
} END_TEST

START_TEST(test_set_create_u32) {
    uint32_t value = UINT32_MAX;
    set* t1 = set_create_u32(value);
    
    ck_assert_int_eq(t1->size, 1);
    ck_assert_int_eq(t1->type, UINT32);
    ck_assert_ptr_ne(t1->root, NULL);
    
    node_t* elem1 = t1->root;
    
    ck_assert_int_eq(*((uint32_t*)elem1->data), value);
    ck_assert_ptr_eq(elem1->next, NULL);
} END_TEST


START_TEST(test_set_create_i64) {
    int64_t value = INT64_MAX;
    set* t1 = set_create_i64(value);
    
    ck_assert_int_eq(t1->size, 1);
    ck_assert_int_eq(t1->type, INT64);
    ck_assert_ptr_ne(t1->root, NULL);
    
    node_t* elem1 = t1->root;
    
    ck_assert_int_eq(*((int64_t*)elem1->data), value);
    ck_assert_ptr_eq(elem1->next, NULL);
} END_TEST

START_TEST(test_set_create_u64) {
    uint64_t value = UINT64_MAX;
    set* t1 = set_create_u64(value);
    
    ck_assert_int_eq(t1->size, 1);
    ck_assert_int_eq(t1->type, UINT64);
    ck_assert_ptr_ne(t1->root, NULL);
    
    node_t* elem1 = t1->root;
    
    ck_assert_int_eq(*((uint64_t*)elem1->data), value);
    ck_assert_ptr_eq(elem1->next, NULL);
} END_TEST


START_TEST(test_set_create_f32) {
    float32 value = FLT_MAX;
    set* t1 = set_create_f32(value);
    
    ck_assert_int_eq(t1->size, 1);
    ck_assert_int_eq(t1->type, FLOAT32);
    ck_assert_ptr_ne(t1->root, NULL);
    
    node_t* elem1 = t1->root;
    
    ck_assert_float_eq(*((float32*)elem1->data), value);
    ck_assert_ptr_eq(elem1->next, NULL);
} END_TEST

START_TEST(test_set_create_f64) {
    float64 value = DBL_MAX;
    set* t1 = set_create_f64(value);
    
    ck_assert_int_eq(t1->size, 1);
    ck_assert_int_eq(t1->type, FLOAT64);
    ck_assert_ptr_ne(t1->root, NULL);
    
    node_t* elem1 = t1->root;
    
    ck_assert_double_eq(*((float64*)elem1->data), value);
    ck_assert_ptr_eq(elem1->next, NULL);
} END_TEST


// create & add tests
void create_testcases(void) {
    create_i8 = tcase_create("set_create_i8");
    tcase_add_test(create_i8, test_set_create_i8);
    suite_add_tcase(test_suite, create_i8);

    create_u8 = tcase_create("set_create_u8");
    tcase_add_test(create_u8, test_set_create_u8);
    suite_add_tcase(test_suite, create_u8);
    
    create_i16 = tcase_create("set_create_i16");
    tcase_add_test(create_i16, test_set_create_i16);
    suite_add_tcase(test_suite, create_i16);

    create_u16 = tcase_create("set_create_u16");
    tcase_add_test(create_u16, test_set_create_u16);
    suite_add_tcase(test_suite, create_u16);
    
    create_i32 = tcase_create("set_create_i32");
    tcase_add_test(create_i32, test_set_create_i32);
    suite_add_tcase(test_suite, create_i32);

    create_u32 = tcase_create("set_create_u32");
    tcase_add_test(create_u32, test_set_create_u32);
    suite_add_tcase(test_suite, create_u32);
    
    create_i64 = tcase_create("set_create_i64");
    tcase_add_test(create_i64, test_set_create_i64);
    suite_add_tcase(test_suite, create_i64);
    
    create_u64 = tcase_create("set_create_u64");
    tcase_add_test(create_u64, test_set_create_u64);
    suite_add_tcase(test_suite, create_u64);
    
    create_f32 = tcase_create("set_create_f32");
    tcase_add_test(create_f32, test_set_create_f32);
    suite_add_tcase(test_suite, create_f32);
    
    create_f64 = tcase_create("set_create_f64");
    tcase_add_test(create_f64, test_set_create_f64);
    suite_add_tcase(test_suite, create_f64);
}
