//
// Created by thahnen on 04.10.21.
//

#include "Unittests.h"


/// test cases on set_add* function
START_TEST(test_set_add_i8) {
    int8_t value = INT8_MIN;
    set* t1 = set_create_i8(value);
    set_add_i8(t1, INT8_MAX);
    
    ck_assert_int_eq(t1->size, 2);
    
    node_t* elem1 = t1->root->next;
    
    ck_assert_int_eq(*((int8_t*)elem1->data), INT8_MAX);
    ck_assert_ptr_eq(elem1->next, NULL);
    
    
} END_TEST

START_TEST(test_set_add_u8) {
    uint8_t value = 0;
    set* t1 = set_create_u8(value);
    set_add_u8(t1, UINT8_MAX);
    
    ck_assert_int_eq(t1->size, 2);
    
    node_t* elem1 = t1->root->next;
    
    ck_assert_int_eq(*((uint8_t*)elem1->data), UINT8_MAX);
    ck_assert_ptr_eq(elem1->next, NULL);
} END_TEST


START_TEST(test_set_add_i16) {
    int16_t value = INT16_MIN;
    set* t1 = set_create_i16(value);
    set_add_i16(t1, INT16_MAX);
    
    ck_assert_int_eq(t1->size, 2);
    
    node_t* elem1 = t1->root->next;
    
    ck_assert_int_eq(*((int16_t*)elem1->data), INT16_MAX);
    ck_assert_ptr_eq(elem1->next, NULL);
    
    
} END_TEST

START_TEST(test_set_add_u16) {
    uint16_t value = 0;
    set* t1 = set_create_u16(value);
    set_add_u16(t1, UINT16_MAX);
    
    ck_assert_int_eq(t1->size, 2);
    
    node_t* elem1 = t1->root->next;
    
    ck_assert_int_eq(*((uint16_t*)elem1->data), UINT16_MAX);
    ck_assert_ptr_eq(elem1->next, NULL);
} END_TEST


START_TEST(test_set_add_i32) {
    int32_t value = INT32_MIN;
    set* t1 = set_create_i32(value);
    set_add_i32(t1, INT32_MAX);
    
    ck_assert_int_eq(t1->size, 2);
    
    node_t* elem1 = t1->root->next;
    
    ck_assert_int_eq(*((int32_t*)elem1->data), INT32_MAX);
    ck_assert_ptr_eq(elem1->next, NULL);
    
    
} END_TEST

START_TEST(test_set_add_u32) {
    uint32_t value = 0;
    set* t1 = set_create_u32(value);
    set_add_u32(t1, UINT32_MAX);
    
    ck_assert_int_eq(t1->size, 2);
    
    node_t* elem1 = t1->root->next;
    
    ck_assert_int_eq(*((uint32_t*)elem1->data), UINT32_MAX);
    ck_assert_ptr_eq(elem1->next, NULL);
} END_TEST


START_TEST(test_set_add_i64) {
    int64_t value = INT64_MIN;
    set* t1 = set_create_i64(value);
    set_add_i64(t1, INT64_MAX);
    
    ck_assert_int_eq(t1->size, 2);
    
    node_t* elem1 = t1->root->next;
    
    ck_assert_int_eq(*((int64_t*)elem1->data), INT64_MAX);
    ck_assert_ptr_eq(elem1->next, NULL);
    
    
} END_TEST

START_TEST(test_set_add_u64) {
    uint64_t value = 0;
    set* t1 = set_create_u64(value);
    set_add_u64(t1, UINT64_MAX);
    
    ck_assert_int_eq(t1->size, 2);
    
    node_t* elem1 = t1->root->next;
    
    ck_assert_int_eq(*((uint64_t*)elem1->data), UINT64_MAX);
    ck_assert_ptr_eq(elem1->next, NULL);
} END_TEST


START_TEST(test_set_add_f32) {
    float32 value = FLT_MIN;
    set* t1 = set_create_f32(value);
    set_add_f32(t1, FLT_MAX);
    
    ck_assert_int_eq(t1->size, 2);
    
    node_t* elem1 = t1->root->next;
    
    ck_assert_float_eq(*((float32*)elem1->data), FLT_MAX);
    ck_assert_ptr_eq(elem1->next, NULL);
    
    
} END_TEST

START_TEST(test_set_add_f64) {
    float64 value = DBL_MIN;
    set* t1 = set_create_f64(value);
    set_add_f64(t1, DBL_MAX);
    
    ck_assert_int_eq(t1->size, 2);
    
    node_t* elem1 = t1->root->next;
    
    ck_assert_double_eq(*((float64*)elem1->data), DBL_MAX);
    ck_assert_ptr_eq(elem1->next, NULL);
} END_TEST


// create & add tests
void add_testcases(void) {
    add_i8 = tcase_create("set_add_i8");
    tcase_add_test(add_i8, test_set_add_i8);
    suite_add_tcase(test_suite, add_i8);

    add_u8 = tcase_create("set_add_u8");
    tcase_add_test(add_u8, test_set_add_u8);
    suite_add_tcase(test_suite, add_u8);
    
    add_i16 = tcase_create("set_add_i16");
    tcase_add_test(add_i16, test_set_add_i16);
    suite_add_tcase(test_suite, add_i16);

    add_u16 = tcase_create("set_add_u16");
    tcase_add_test(add_u16, test_set_add_u16);
    suite_add_tcase(test_suite, add_u16);
    
    add_i32 = tcase_create("set_add_i32");
    tcase_add_test(add_i32, test_set_add_i32);
    suite_add_tcase(test_suite, add_i32);

    add_u32 = tcase_create("set_add_u32");
    tcase_add_test(add_u32, test_set_add_u32);
    suite_add_tcase(test_suite, add_u32);
    
    add_i64 = tcase_create("set_add_i64");
    tcase_add_test(add_i64, test_set_add_i64);
    suite_add_tcase(test_suite, add_i64);

    add_u64 = tcase_create("set_add_u64");
    tcase_add_test(add_u64, test_set_add_u64);
    suite_add_tcase(test_suite, add_u64);
    
    add_f32 = tcase_create("set_add_f32");
    tcase_add_test(add_f32, test_set_add_f32);
    suite_add_tcase(test_suite, add_f32);

    add_f64 = tcase_create("set_add_f64");
    tcase_add_test(add_f64, test_set_add_f64);
    suite_add_tcase(test_suite, add_f64);
}
