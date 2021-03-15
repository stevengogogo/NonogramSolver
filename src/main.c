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
    nog = create_nogram_with_answer("test/data/input_1.txt","test/data/output_1.txt");
    return 0;
}