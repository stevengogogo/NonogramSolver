#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Compare two string. if identical returns 0. otherwise, return 0*/
int striden(char* a, char* b);

//Convert 1 char to int.
int str2int(char numstr);
void int2str(char* s,int num);

//Cleaner
void killstr(char*);

#endif