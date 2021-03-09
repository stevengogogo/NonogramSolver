/**
 * @file runtest.c
 * @brief Unit Testing with acutest
 */

#include <stdio.h>

#include "acutest.h"
#include "test_utils.h"
#include "test_Nonogram.h"

// Run TESTs 
TEST_LIST = {
    {"Nonogram constructors", test_nonogram_struct},
    {"Nonogram printer", test_hint_printout},
    {"Nonogram validation", test_validity},
    {"Utility: Flipflop",test_utils_flipflop},
    {"Utility: Find IDs", test_utils_find_ID},
    {"Utility:Dynamical array", test_dymarr},
    {NULL, NULL} // Terminate the test
};