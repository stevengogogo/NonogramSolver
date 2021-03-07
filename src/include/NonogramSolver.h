#ifndef NONOGRAMSOLVER_H
#define NONOGRAMSOLVER_H

/*Nonogram solver */
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
#define MAX_LINES 10
#define MAX_HINT_NUM 20

typedef struct {
    int nPoint;
    int pLens[MAX_LINES];
} hint;

/*Array of Hints*/
typedef struct {
    hint h[MAX_HINT_NUM];
    int len; 
} hints;

typedef struct {
    int N; //rows
    int M; //cols
} size2D;

typedef struct {
    int map[MAX_LINES][MAX_LINES]; //[row][col]
    size2D size;
    hints Nhs;
    hints Mhs;
} nogram;


/* Initiate nonogram problem */
nogram init_nogram(nogram,size2D,hints);
/*Initiate an undefine nonogram*/
nogram init_nogram_undef(nogram);
hint create_hint(int pLens[],int nPoint);
hints create_hints(hint[],int number_of_hints);

//compare identical:1, 0 otherwise
int comp_array2D(int a[MAX_LINES][MAX_LINES], int b[MAX_LINES][MAX_LINES],int R_length, int C_length);
int comp_nogram(nogram, nogram);
int comp_hints(hints, hints);
int comp_hint(hint, hint);
int comp_size2D(size2D, size2D);

//verification: 1 (valid); 0 otherwise
int is_nogram_valid(nogram nm);
int is_line_valid(int line[], int len_line, hint);
//Return 1 if there is no undefine region
int is_line_set(int line[], int len_line);

//Display
char bool2sym(int);
void print_nogram_str(nogram);
char* create_nogram_str(nogram);
void close_nogram_str(char*);
void print_hint_str(hint);
char* create_hint_str(hint);
void close_hint_str(char*);


#endif