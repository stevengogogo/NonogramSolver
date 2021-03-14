/**
 * @file test_Nonogram.h
 */

#ifndef TEST_NONOGRAM_H
#define TEST_NONOGRAM_H

#include <string.h>
#include "acutest.h"
#include "include/NonogramSolver.h"

/*Create a nonogram problem*/
void test_nonogram_struct(void){

    /*Create a nonogram problem*/
    int pLen[] = {1,1}; //Point lengths
    hint h = create_hint(pLen, 2);//Single hint
    hint hs[] = {h,h,h,h};
    hints H = create_hints(hs, 4);//all hints

    nogram nm; //nonogram probel
    size2D s = {
        .N=2,
        .M=2
    };//map size

    nm = init_nogram(nm, s, H);//init: map object, size and hints

    /*Verify information*/
    nm.map[0][0] = hole_val; //create psudo solution
    nm.map[0][1] = fill_val;
    char* hint_str;
    char* hint_str_real;
    char* nogram_str = create_nogram_str(nm);
    char* nogram_str_real = "\n_o\n22";

    // Compare Hints
    for(int i=0;i<nm.Nhs.len;i++){
        TEST_ASSERT(comp_hint(nm.Nhs.h[i], H.h[i]) == 1);
    }
    for(int i=nm.Nhs.len;i<nm.Mhs.len;i++){
        TEST_ASSERT(comp_hint(nm.Mhs.h[i-nm.Nhs.len], H.h[i]) == 1);
    }

    //Test nogram map
    TEST_ASSERT(striden(nogram_str_real, nogram_str) == 0);
    TEST_MSG("Real map: %s. \nBut got %s", nogram_str_real, nogram_str); 
    //print_nogram_str(nm);
    close_nogram_str(nogram_str);
}

void test_hint_printout(void){
    int pLens[] = {1,1,5,2};
    hint h= create_hint(pLens, 4);
    char *hstr = create_hint_str(h);
    printf("hint: %s ", hstr);
    print_hint_str(h);
    //Cleanup
    close_hint_str(hstr);
}

void test_validity(void){
    int line1[]={1,1,1,1};
    int line2[]={1,1,0,1};
    int line3[]={0,1,0,0};
    int line4[]={1,1,1,0};
    int line5[]={0,0,0,0};

    TEST_ASSERT(segment_number(line1, 4, 1) == 1);
    TEST_ASSERT(segment_number(line2, 4, 1) == 2);
    TEST_ASSERT(segment_number(line3, 4, 1) == 1);
    TEST_ASSERT(segment_number(line4, 4, 1) == 1);
    TEST_ASSERT(segment_number(line5, 4, 1) == 0);
}

void test_create_nonogram(void){
    nogram nog;
    //nog = create_nogram_scantf();
    nog = create_nogram_fscantf("test/data/input_1.txt");

    // validate the content
    TEST_ASSERT(nog.size.N == 4);
    TEST_ASSERT(nog.size.M == 4);
    TEST_ASSERT(nog.Nhs.h[0].nPoint == 2);
}

#endif