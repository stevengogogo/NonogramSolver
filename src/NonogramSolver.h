/**
 * @file NonogramSolver.h
 * @brief A Nonogram Solver with brutal-force algorithm
 */
#ifndef NONOGRAMSOLVER_H
#define NONOGRAMSOLVER_H

/** * Nonogram solver */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "utils.h"

#define hole '_'
#define fill 'o'
#define hole_val 0
#define fill_val 1
#define Undef_Site_Val 3
#define Default_Site_Val 2
#define MAX_LINES 25
#define MAX_CELLS 25
#define MAX_HINT_NUM 25

/**
 * @brief A hint element
 * @param nPoint Number of fragments
 * @param pLens lengths of fragments
 */
typedef struct {
    int nPoint;
    int pLens[MAX_LINES];
} hint;

/** * Array of Hints*/
typedef struct {
    hint h[MAX_HINT_NUM];
    int len; 
} hints;

typedef struct {
    int N; //rows
    int M; //cols
} size2D;

typedef struct {
    int id[MAX_CELLS];
    int len;
} arrL;

typedef struct {
    dymarr* map; //[row][col] in one line
    size2D size;
    hints Nhs;
    hints Mhs;
    int total_cells;
} nogram;

arrL init_arrL(void);
void insert_arrL(arrL*, int);
int pop_arrL(arrL*);

hint init_hint();

/** @brief Initiate nonogram problem */
void init_nogram(nogram*,size2D,hints);
void close_nogram(nogram*);
int get_map(nogram*, int N, int M);
void change_map(nogram*, int N, int M, int val);
void get_row(dymarr*, nogram*, int row_i);
void get_col(dymarr*, nogram*, int col_i);
int NM2loc(size2D, int N, int M);

/** @brief Initiate an undefine nonogram */
nogram init_nogram_undef(nogram);
hint create_hint(int pLens[],int nPoint);
hints create_hints(hint[],int number_of_hints);

/**
 * @brief Compare two 2D arrays
 * 
 * @param a 2D array with known size
 * @param b another array for comparison
 * @param R_length length of rows of `a`
 * @param C_length length of columns of `a`
 * @return int 1: Identical; 0 otherwise
 */
int comp_array(dymarr* mapa, dymarr* mapb);
int comp_nogram(nogram, nogram);
int comp_hints(hints, hints);
int comp_hint(hint, hint);
int comp_size2D(size2D, size2D);

/** Verification: 1 (valid); 0 otherwise */
int is_nogram_valid(nogram* nm);
/** Check the validity of a line with the hint. 1:Valid, 0:Invalid*/
int is_line_valid(dymarr* line, int len_line, hint);
/** Return 1 if there is no undefine region */
int is_line_set(dymarr* line, int len_line);

/** Count the number of segments in a array */
int segment_number(dymarr* line, int len_line, int key);

/** Convert a number line into a hint */
hint get_segments(dymarr* line, int len_line);

//Display
/** Print out the map with O and _*/
void printf_map(nogram);
/** * Convert integer to symbol in nonogram*/
char convert_num2fill(int);
/** * Convert symbol to integer*/
int convert_fill2num(char);
void print_nogram_str(nogram);
char* create_nogram_str(nogram);
void close_nogram_str(char*);
void print_hint_str(hint);
char* create_hint_str(hint);
void close_hint_str(char*);

//Create Problem 
/** Nonogram creator with key in*/
nogram create_nogram_scantf(void);
/** Nonogram creator with txt file*/
nogram create_nogram_fscantf(char* filename);
/** Nonogram creator with input and output file. The created nonogram is assert valid*/
nogram create_nogram_with_answer(char* input_fn, char* output_fn);
/** Use output file to set the map of nogram*/
void set_nonogram_answer(nogram*, char* output_fn);


//Create Problem 
/** Nonogram creator with key in*/
nogram create_nogram_scantf(void);
/** NOnogram creator with txt file*/
nogram create_nogram_fscantf(char* filename);

//Solve Nonogram
/** Wrapper of nonogram solver*/
int solve_nonogram(nogram* nog);
/** Nonogram solver with greedy algorithm*/
int solve_nonogram_greedy(nogram* nog, arrL empts);

//Status checking


/** Return location with index*/
void find_nogram_empty(size2D* locE, nogram* nog);
void num2loc(size2D* loc,int* i, size2D* map_size);



#endif