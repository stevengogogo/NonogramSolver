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
    // Input 2
    nog = create_nogram_fscantf("test/data/input_2.txt");

    int a0[] = {0,1,1,1,1};
    int a1[] = {1,1,0,0,0};
    int a2[] = {0,1,1,1,0};
    int a3[] = {0,0,0,1,1};
    int a4[] = {1,1,1,1,0};
    
    for(int i=0;i<5;i++)
        nog.map[0][i] = a0[i];
    for(int i=0;i<5;i++)
        nog.map[1][i] = a1[i];
    for(int i=0;i<5;i++)
        nog.map[2][i] = a2[i];
    for(int i=0;i<5;i++)
        nog.map[3][i] = a3[i];
    for(int i=0;i<5;i++)
        nog.map[4][i] = a4[i];

    assert(is_nogram_valid(nog) == 1);
}