//
// Created by agbod on 5/15/2021.
//

#include "ass3q6b.h"

/*int main(void) {
    q6b();
    return 0;
}*/

void test_gcd2(void) {
    CU_ASSERT(gcd2(42, 56) == 14);
    CU_ASSERT(gcd2(48, 18) == 6);
    CU_ASSERT(gcd2(270, 192) == 6);
    CU_ASSERT(gcd2(1237, 24) == 1);
    CU_ASSERT(gcd2(4200000, 3780000) == 420000);
    CU_ASSERT(gcd2(0, 0) == 0);
}

void q6b(void) {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("gcd2_test", 0, 0);
    CU_add_test(suite, "gcd2_fun", test_gcd2);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
}