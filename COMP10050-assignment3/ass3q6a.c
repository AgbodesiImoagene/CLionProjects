//
// Created by agbod on 5/15/2021.
//

#include "ass3q6a.h"

/*int main(void) {
    q6a();
    return 0;
}*/

void test_gcd1(void) {
    CU_ASSERT(gcd1(42, 56) == 14);
    CU_ASSERT(gcd1(48, 18) == 6);
    CU_ASSERT(gcd1(270, 192) == 6);
    CU_ASSERT(gcd1(1237, 24) == 1);
    CU_ASSERT(gcd1(4200000, 3780000) == 420000);
    CU_ASSERT(gcd1(0, 0) == 0);
}

void q6a(void) {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("gcd1_test", 0, 0);
    CU_add_test(suite, "gcd1_fun", test_gcd1);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
}