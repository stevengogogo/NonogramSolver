/**
 * @file test_utils.h
 */

#ifndef TEST_UTILS_H
#define TEST_UTILS_H

#include "acutest.h"
#include "include/utils.h"

void test_utils(void)
{
   
}

void test_dymarr(void){
    dymarr a;
    int init_size = 10;
    int arr[] = {2,3,4,5,6,7,8,9,10,11,12};
    int arr_len = 11; 
    int init_val=1;
    
    //Initiation with length =0; maxsize=10
    init_dymarr(&a, init_size);
    TEST_ASSERT(a.maxlen==init_size);
    TEST_ASSERT(a.len==0);
    
    //Insert a value
    insert_dymarr(&a, init_val);
    TEST_ASSERT(a.len==1);
    TEST_ASSERT(a.array[0]==init_val);

    //Insert an array
    insert_arr_dymarr(&a, arr, arr_len);
    TEST_ASSERT(a.len= (1+arr_len));
    TEST_ASSERT(a.maxlen > init_size);

    //Pop and remove
    TEST_ASSERT(pop_dymarr(&a) == arr[arr_len-1]);
    TEST_ASSERT(a.len == arr_len);

    close_dymarr(&a);
}


#endif