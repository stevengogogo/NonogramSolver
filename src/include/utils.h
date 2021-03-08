#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>


/*Compare two string. if identical returns 0. otherwise, return 0*/
int striden(char* a, char* b);

//Convert 1 char to int.
int str2int(char numstr);
void int2str(char* s,int num);

//Cleaner
void killstr(char*);

//find: return index of the key. return -1 if the array doesn't contain the key
int findfirst_int_arr(int arr[], int arr_size, int key);



/**
 * @brief Dynamical Array
 * @param array Interger array
 * @param len length of data
 * @param maxlen maximum storage
 */
typedef struct{
    int* array;
    int len;
    int maxlen;
}dymarr;

void init_dymarr(dymarr*,int init_size);
void close_dymarr(dymarr*);
void insert_arr_dymarr(dymarr*, int src[], int src_len);
void insert_dymarr(dymarr*, int val);
int pop_dymarr(dymarr*);

//Find all id of a key in array
dymarr* create_ids_int_arr(int arr[], int arr_size, int key);
void close_ids_int_arr(dymarr*);

//Convert 1 char to int.
int str2int(char numstr);
void int2str(char* s,int num);

//Cleaner
void killstr(char*);

#endif