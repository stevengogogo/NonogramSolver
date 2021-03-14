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
     struct array{
        int arr[4];
        int len;
        int n_seg;
    };

    struct array A[] = {
        {{0,0,0,0},4,0},
        {{1,0,0,0},4,1},
        {{0,1,0,0},4,1},
        {{1,1,0,0},4,1},
        {{0,0,1,0},4,1},
        {{1,0,1,0},4,2},
        {{0,1,1,0},4,1},
        {{1,1,1,0},4,1},
        {{0,0,0,1},4,1},
        {{1,0,0,1},4,2},
        {{0,1,0,1},4,2},
        {{1,1,0,1},4,2},
        {{0,0,1,1},4,1},
        {{1,0,1,1},4,2},
        {{0,1,1,1},4,1},
        {{1,1,1,1},4,1}
    };
    int A_len = 16;
    hint h;

    for(int i=0;i<A_len;i++){
        h = get_segments(A[i].arr, A[i].len);
        printf("\nGet %d; true %d",h.nPoint, A[i].n_seg);
        assert(A[i].n_seg == h.nPoint);
        //TEST_MSG("True seg: %d. But got %d", A[i].n_seg, h.nPoint);
    }

    return 0;
}