#ifndef test_h
#define test_h

int init_suite(void);
int clean_suite(void);

/*
 * Tests
 */
void test_cunit(void);
void test_get_operator(void);

/*
 * Called from main to add tests
 */
int add_tests_to_suit(CU_pSuite pSuite);
#endif
