/**
 * @file main.c
 * @brief Interface of the nonogram solver
 */
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "NonogramSolver.h"


/* * @brief Interface */
int main()
{
    nogram nog;
    
    nog = create_nogram_scantf();
    solve_nonogram_greedy(&nog);
    return 0;
}