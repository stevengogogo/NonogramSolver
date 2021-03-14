/**
 * @file main.c
 * @brief Interface of the nonogram solver
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "include/utils.h"
#include "include/NonogramSolver.h"


/* * @brief Interface */
int main()
{   
    nogram nog;
    nog = create_nogram_scantf();
    print_nogram_str(nog);
    return 0;
}