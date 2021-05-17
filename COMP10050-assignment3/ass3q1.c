//
// Created by agbod on 5/15/2021.
//

#include "ass3q1.h"
#define GRANULARITY 0.000001

double arr1[] = {-1.3, -1.45, -220, -100, -0.1, -0.1234, -200};
double arr2[] = {-1.3, 1.45, 220, 100, 0, 200, 0.1234};
double expected_return1 = -74.7104857142857;
double expected_return2 = 74.3247714285714;

/*int main(void) {
    q1();
    return 0;
}*/

void test_average(void) {
    CU_ASSERT_DOUBLE_EQUAL(average(arr1, sizeof(arr1) / sizeof(double)), expected_return1, GRANULARITY);
    CU_ASSERT_DOUBLE_EQUAL(average(arr2, sizeof(arr2) / sizeof(double)), expected_return2, GRANULARITY);
}

void q1(void) {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("average_test", 0, 0);
    CU_add_test(suite, "average_fun", test_average);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
}