#include <stdio.h>  // for printf, scanf, fprintf
#include <math.h> // for CU_DOUBLE_EQUAL
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
  printf("Double entered \'%f\'\n", f);
  printf("*******\n");
}

/* Story 6: As a user, I want to be able to add two numbers using the
 * program, so I can use it for addition
 */
void test_add(void) {
  CU_ASSERT_DOUBLE_EQUAL(add(1, 2), 3, .001);
  CU_ASSERT_DOUBLE_EQUAL(add(-1, 2), 1, .001);
  CU_ASSERT_DOUBLE_EQUAL(add(1, -2), -1, .001);
  CU_ASSERT_DOUBLE_EQUAL(add(-1, -2), -3, .001);
  CU_ASSERT_DOUBLE_EQUAL(add(1.1, 2.1), 3.2, .001);
  CU_ASSERT_DOUBLE_EQUAL(add(-1.1, 2.2), 1.1, .001);
  CU_ASSERT_DOUBLE_EQUAL(add(-1.1, 2.2), 1.1, .001);
}

/* Story 7: As a user, I want to be able to subtract two numbers using
 * the program, so I can use it for subtraction
 */
void test_subtract(void) {
  CU_ASSERT_DOUBLE_EQUAL(subtract(1, 2), -1, .001);
  CU_ASSERT_DOUBLE_EQUAL(subtract(-1, 2), -3, .001);
  CU_ASSERT_DOUBLE_EQUAL(subtract(1, -2), 3, .001);
  CU_ASSERT_DOUBLE_EQUAL(subtract(-1, -2), 1, .001);
  CU_ASSERT_DOUBLE_EQUAL(subtract(1.1, 2.1), -1.0, .001);
  CU_ASSERT_DOUBLE_EQUAL(subtract(-1.1, 2.2), -3.3, .001);
  CU_ASSERT_DOUBLE_EQUAL(subtract(1.1, -2.2), 3.3, .001);
  CU_ASSERT_DOUBLE_EQUAL(subtract(-1.1, -2.2), 1.1, .001);
}

/* Story 8: As a user, I want to be able to multiply two numbers using
 * the program, so I can use it for multiplciation
 */
void test_multiply(void) {
  CU_ASSERT_DOUBLE_EQUAL(multiply(1, 2), 2, .001);
  CU_ASSERT_DOUBLE_EQUAL(multiply(-1, 2), -2, .001);
  CU_ASSERT_DOUBLE_EQUAL(multiply(1, -2), -2, .001);
  CU_ASSERT_DOUBLE_EQUAL(multiply(-1, -2), 2, .001);
  CU_ASSERT_DOUBLE_EQUAL(multiply(1.1, 2.1), 2.31, .001);
  CU_ASSERT_DOUBLE_EQUAL(multiply(-1.1, 2.2), -2.42, .001);
  CU_ASSERT_DOUBLE_EQUAL(multiply(1.1, -2.2), -2.42, .001);
  CU_ASSERT_DOUBLE_EQUAL(multiply(-1.1, -2.2), 2.42, .001);
}

/* Story 9: As a user, I want to be able to divide two numbers using
 * the program, so I can use it for division
 */
void test_divide(void) {
  CU_ASSERT_DOUBLE_EQUAL(divide(1, 2), 0.5, .001);
  CU_ASSERT_DOUBLE_EQUAL(divide(-1, 2), -0.5, .001);
  CU_ASSERT_DOUBLE_EQUAL(divide(1, -2), -0.5, .001);
  CU_ASSERT_DOUBLE_EQUAL(divide(-1, -2), 0.5, .001);
  CU_ASSERT_DOUBLE_EQUAL(divide(1.1, 2.1), 0.5238, .001);
  CU_ASSERT_DOUBLE_EQUAL(divide(-1.1, 2.2), (-1.1/2.2), .001);
  CU_ASSERT_DOUBLE_EQUAL(divide(1.1, -2.2), (1.1/-2.2), .001);
  CU_ASSERT_DOUBLE_EQUAL(divide(-1.1, -2.2), (-1.1/-2.2), .001);
}

/* Story 17: As a user, I want to be able to add two numbers using the
 * program, so I can use it for addition
 */
void test_valid_operator(void) {
  for (char op = ' '; op <= '~'; op++) {
    if ('x' == op
	|| '+' == op
	|| '-' == op
	|| '*' == op
	|| '/' == op
	) {
      CU_ASSERT_TRUE(valid_operator(op));
    } else {
      CU_ASSERT_FALSE(valid_operator(op));
    }
  }
}

/********************************************************
 * This function is used by test_main to add the test functions to the
 * suite before the tests are run. When a new test (e.g.  voide
 * new_test(void) is added to this file, a new line needs to be added
 * to this function of the form: && NULL != CUaddtest(pSuite,"New test
 * description", new_test) 
 ********************************************************/
/* add the tests to the suite */
int add_tests_to_suit(CU_pSuite pSuite) {
  return
    (
     //     NULL != CU_add_test(pSuite, "Testing: get_operator()",
     //			 test_get_operator)
     //&& NULL != CU_add_test(pSuite, "Testing: get_float()",
     //			 test_get_float)
     NULL != CU_add_test(pSuite, "Testing: add(double, double)",
			    test_add)
     && NULL != CU_add_test(pSuite, "Testing: subtract(double, double)",
			    test_subtract)
     && NULL != CU_add_test(pSuite, "Testing: multiply(double, double)",
			    test_multiply)
     && NULL != CU_add_test(pSuite, "Testing: divide(double, double)",
			    test_divide)
     && NULL != CU_add_test(pSuite, "Testing: valid_operator(char)",
			    test_valid_operator)
     //     && NULL != CU_add_test(pSuite, "CUnit Test", test_cunit)
     );
}
