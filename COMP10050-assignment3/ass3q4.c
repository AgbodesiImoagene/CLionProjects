//
// Created by agbod on 5/15/2021.
//

#include "ass3q4.h"
#define GRANULARITY 0.000001

double new_max_arr1[] = {-1.3, -1.45, -220, -100, -0.1, -0.1234, -200};
double new_max_arr2[] = {-1.3, 1.45, 220, 100, 0, 200, 0.1234};
double new_max_expected_return1 = -0.1;
double new_max_expected_return2 = 220;

/*int main(void) {
    q4();
    return 0;
}*/

void new_test_max(void) {
    CU_ASSERT_DOUBLE_EQUAL(adj_max(new_max_arr1, sizeof(new_max_arr1) / sizeof(double)), new_max_expected_return1, GRANULARITY);
    CU_ASSERT_DOUBLE_EQUAL(adj_max(new_max_arr2, sizeof(new_max_arr2) / sizeof(double)), new_max_expected_return2, GRANULARITY);
}

void q4(void) {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("new_max_test", 0, 0);
    CU_add_test(suite, "new_max_fun", new_test_max);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
}