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

    int a0[4] = {1,0,1,0};
    int a1[4] = {0,1,0,1};
    int a2[4] = {1,0,1,0};
    int a3[4] = {1,1,1,1};

    for(int i=0;i<4;i++)
        nog.map[0][i] = a0[i];
    for(int i=0;i<4;i++)
        nog.map[1][i] = a1[i];
    for(int i=0;i<4;i++)
        nog.map[2][i] = a2[i];
    for(int i=0;i<4;i++)
        nog.map[3][i] = a3[i];

    assert(is_nogram_valid(nog) == 1);
}