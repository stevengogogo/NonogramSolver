/**
 * @file main.c
 * @brief Interface of the nonogram solver
 */
#include <stdio.h>
#include <stdlib.h>
#include "include/utils.h"
#include "include/NonogramSolver.h"


/* * @brief Interface */
int main()
{   
    nogram nog;
    //nog = create_nogram_scantf();
    nog = create_nogram_fscantf("test/data/input_1.txt");
    print_nogram_str(nog);
    return 0;
}