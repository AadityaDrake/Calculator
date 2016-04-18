#include <stdio.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "../calc.h"
#include "test.h"

/* Test Suite setup and cleanup functions: */

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

/* Tests */

/*
 * Testing cunit
 * Failure expected on last test.
 */
void test_cunit(void) {
  CU_ASSERT(1 == 1);
  CU_ASSERT_TRUE(1 == 1);
  CU_ASSERT_FALSE(1 != 1);
  CU_ASSERT_EQUAL(1, 1);
  CU_ASSERT_NOT_EQUAL(1, 2);
  CU_PASS("CU_PASS");
  CU_FAIL("CU_FAIL");
}

/*
 * Story 2: As a user, I want to be able to enter a command, so my calculator can do multiple things.
 */
void test_get_operator(void) {
  char op = ' ';

  printf("\n******* Testing get_operator ********\n");
  op = get_operator();
  printf("Command entered \'%c\'\n", op);
  printf("*******\n");
}

/*
 * Story 4: As a user, I want to be able to exit the program, so I can
 * tell it I am finished.
 */

void test_get_float(void) {
  float f = 0.0;

  printf("\n******* Testing get_float ********\n");
  f = get_float();
  printf("Command entered \'%f\'\n", f);
  printf("*******\n");
}

/* add the tests to the suite */
int add_tests_to_suit(CU_pSuite pSuite) {
  return
    (
     NULL != CU_add_test(pSuite, "CUnit Test", test_cunit) &&
     NULL != CU_add_test(pSuite, "Testing: get_operator()",
			 test_get_operator) &&
     NULL != CU_add_test(pSuite, "Testing: get_float()",
			 test_get_float)
     );
}
