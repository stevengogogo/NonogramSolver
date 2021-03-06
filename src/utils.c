#include "include/utils.h"

/*Compare two string. if identical returns 0. otherwise, return 0*/
int striden(char* a, char* b){
    int diff;
    int len_sh = strcmp(a,b);

    if  (len_sh == 0) {
        diff = strncmp(a,b, strlen(a));
        return diff;
    }
    else{
        return len_sh;
    }
}


//Convert 1 char to int.
int str2int(char numstr)
{
    // ASCII starts at 48
    int out = numstr - '0';
    return out;
}

void int2str(char* s,int num){
    sprintf(s, "%d", num);
}



/*Free Str object*/
void killstr(char* str){
    free(str);
    str = NULL;
}
