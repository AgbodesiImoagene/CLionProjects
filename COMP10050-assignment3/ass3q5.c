//
// Created by agbod on 5/15/2021.
//

#include "ass3q5.h"

/*int main(void) {
    q5();
    return 0;
}*/

void test_fact(void) {
    CU_ASSERT(factorial(0) == 1);
    CU_ASSERT(factorial(1) == 1);
    CU_ASSERT(factorial(4) == 24);
    CU_ASSERT(factorial(6) == 720);
}

void q5(void) {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("fact_test", 0, 0);
    CU_add_test(suite, "fact_fun", test_fact);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
}