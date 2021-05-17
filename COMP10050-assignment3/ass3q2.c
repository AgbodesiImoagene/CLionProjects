//
// Created by agbod on 5/15/2021.
//

#include "ass3q2.h"
#define GRANULARITY 0.000001

double new_arr1[] = {-1.3, -1.45, -220, -100, -0.1, -0.1234, -200};
double new_arr2[] = {-1.3, 1.45, 220, 100, 0, 200, 0.1234};
double new_expected_return1 = -74.7104857142857;
double new_expected_return2 = 74.3247714285714;

/*int main(void) {
    q2();
    return 0;
}*/

void new_test_average(void) {
    CU_ASSERT_DOUBLE_EQUAL(adj_average(new_arr1, sizeof(new_arr1) / sizeof(double)), new_expected_return1, GRANULARITY);
    CU_ASSERT_DOUBLE_EQUAL(adj_average(new_arr2, sizeof(new_arr2) / sizeof(double)), new_expected_return2, GRANULARITY);
}

void q2(void) {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("new_average_test", 0, 0);
    CU_add_test(suite, "new_average_fun", new_test_average);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
}