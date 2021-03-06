#include <stdio.h>

#include "acutest.h"
#include "test_utils.h"
#include "test_Nonogram.h"

// Run TESTs 
TEST_LIST = {
    {"Nonogram printer", test_nonogram_struct},
    {"Utility", test_utils},
    {NULL, NULL} // Terminate the test
};