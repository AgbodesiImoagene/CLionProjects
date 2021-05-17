//
// Created by agbod on 5/15/2021.
//

#include "ass3q6c.h"

/*int main(void) {
    q6c();
    return 0;
}*/

void test_gcd3(void) {
    CU_ASSERT(gcd3(42, 56) == 14);
    CU_ASSERT(gcd3(48, 18) == 6);
    CU_ASSERT(gcd3(270, 192) == 6);
    CU_ASSERT(gcd3(1237, 24) == 1);
    CU_ASSERT(gcd3(4200000, 3780000) == 420000);
    CU_ASSERT(gcd3(0, 0) == 0);
}

void q6c(void) {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("gcd3_test", 0, 0);
    CU_add_test(suite, "gcd3_fun", test_gcd3);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
}