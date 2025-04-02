#include <check.h>

#define LINKED_LIST_IMPLEMENTATION
#include "include.h" 
START_TEST(test_deque_int_push_pop) {
    Deque_int* deque = deque_int_create();
    ck_assert_ptr_ne(deque, NULL);

    ck_assert(deque_int_push_back(deque, 10));
    ck_assert(deque_int_push_back(deque, 20));
    ck_assert(deque_int_push_front(deque, 5));
    ck_assert(deque_int_push_front(deque, 1));

    int value;
    ck_assert(deque_int_pop_front(deque, &value));
    ck_assert_int_eq(value, 1);

    ck_assert(deque_int_pop_back(deque, &value));
    ck_assert_int_eq(value, 20);

    ck_assert(deque_int_pop_front(deque, &value));
    ck_assert_int_eq(value, 5);

    ck_assert(deque_int_pop_back(deque, &value));
    ck_assert_int_eq(value, 10);

    ck_assert(deque_int_is_empty(deque));

    deque_int_destroy(deque);
}
END_TEST

Suite* deque_suite(void) {
    Suite* s;
    TCase* tc_core;

    s = suite_create("Deque");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_deque_int_push_pop);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite* s;
    SRunner* sr;

    s = deque_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
