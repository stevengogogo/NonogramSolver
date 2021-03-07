#include <stdio.h>

#include "acutest.h"
#include "test_utils.h"
#include "test_Nonogram.h"

// Run TESTs 
TEST_LIST = {
    {"Nonogram constructors", test_nonogram_struct},
    {"Nonogram printer", test_hint_printout},
    {"Utility", test_utils},
    {"Utility:Dynamical array", test_dymarr},
    {NULL, NULL} // Terminate the test
};