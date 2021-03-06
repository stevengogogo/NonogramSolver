#ifndef TEST_NONOGRAM_H
#define TEST_NONOGRAM_H

#include "include/NonogramSolver.h"

void test_nonogram_struct(void){
    int pLen[] = {1,1};
    int map[2][2] = {{1,1}, {1,1}};
    size2D s = {
        .nrow = 2,
        .ncol = 2
    };

    hint h = {
        .nPoint=2,
        .pLen = pLen
    };



}



#endif