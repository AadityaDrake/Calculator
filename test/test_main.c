#include <stdio.h>
#include "CUnit/CUnit.h"
#include "CUnit/Basic.h"
#include "../calc.h"
#include "test.h"

/************* Test Runner Code **************/

int main ( void )
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if ( CUE_SUCCESS != CU_initialize_registry() ) {
     fprintf(stderr, "Failed to initialize the CUnit test registry\n");
     return CU_get_error();
   }

   /* add a suite to the registry */
   pSuite = CU_add_suite( "calc test suite", init_suite, clean_suite );
   if ( NULL == pSuite ) {
     fprintf(stderr, "Failed to add suite to registry\n");
     CU_cleanup_registry();
     return CU_get_error();
   }

   /* add the tests to the suite */
   if ( !add_tests_to_suit(pSuite) ) {
     fprintf(stderr, "Failed to add tests to suite\n");
     fprintf(stderr, "\t%s\n", CU_get_error_msg());
     CU_cleanup_registry();
     return CU_get_error();
   }

   // Run all tests using the basic interface
   printf("\n\n********** Running Tests ***************\n");
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   printf("\n********** Tests Run  ***************\n");
   printf("\n********** Failed Tests  ***************\n");
   CU_basic_show_failures(CU_get_failure_list());
   printf("\n********** Failed Tests  ***************\n\n");

   /* Clean up registry and return */
   CU_cleanup_registry();
   return CU_get_error();
}
