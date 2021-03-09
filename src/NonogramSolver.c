/**
 * @file NonogramSolver.c
 */

#include "include/NonogramSolver.h"

nogram init_nogram(nogram nm_, size2D size, hints H){
    //number of hint is N+M
    assert(  H.len == (size.N + size.M) );
    nogram nm;
    hints HN, HM;
    nm = init_nogram_undef(nm);
    nm.size = size;

    for(int i=0;i<size.N;i++){
        for(int j=0;j<size.M;j++){
           nm.map[i][j] = Default_Site_Val;
        }
    }

    HN.len = size.N; //Hint of N
    HM.len = size.M; //Hint of M
    //Dispatch to N x M Hints
    for(int n=0;n<size.N;n++){
         HN.h[n] = H.h[n];
    }
    for(int m=size.N;m<size.M;m++){
        HM.h[m-size.N] = H.h[m];
    }

    nm.Nhs = HN;
    nm.Mhs = HM;

    return nm;
}

nogram init_nogram_undef(nogram nm){
    nogram NM;
    for(int i=0;i<MAX_LINES; i++){
        for(int j=0;j<MAX_LINES; j++){
            NM.map[i][j]=Undef_Site_Val;
        }
    }
    return NM;
}

hint create_hint(int sizes[],int nPoint){
    assert(nPoint<MAX_LINES);
    hint h;
    h.nPoint =  nPoint;
    for(int i=0;i<nPoint;i++){
        h.pLens[i] = sizes[i];
    }
    return h;
}

hints create_hints(hint harr[],int number_of_hints){
    hints H;
    H.len=number_of_hints;
    
    for(int i=0;i<number_of_hints;i++){
        H.h[i] = harr[i]; 
    }
    return H;
}

//Compare 

/*Compare 2 2D array. Identical 1; 0 otherwise*/
int comp_array2D(int a[MAX_LINES][MAX_LINES], int b[MAX_LINES][MAX_LINES],int R_length, int C_length){
    for(int i=0;i<R_length;i++){
        for(int j=0;j<C_length;j++){
            if(a[i][j] != b[i][j]){
                return 0;
            }
        }
    }
    return 1;
}


int comp_nogram(nogram a, nogram b){
    if (comp_size2D(a.size,b.size)==0){
        return 0;
    }
    else if (comp_hints(a.Nhs, b.Nhs) == 0){
        return 0;
    }
    else if (comp_hints(a.Mhs,b.Mhs) == 0){
        return 0;
    }
    else if (comp_array2D(a.map, b.map, a.size.N, a.size.M) == 0){
        return 0;
    }
    return 1;
}

int comp_hints(hints a, hints b){
    if (a.len != b.len){
        return 0;
    }
    for(int i=0;i<a.len;i++){
        if(comp_hint(a.h[i], b.h[i]) == 0){
            return 0;
        }
    }
    return 1;
}

int comp_hint(hint a, hint b){
    if (a.nPoint != b.nPoint){
        return 0;
    }
    for(int i=0;i<a.nPoint;i++){
        if(a.pLens[i] != b.pLens[i]){
            return 0;
        }
    }
    return 1;
}

int comp_size2D(size2D a, size2D b){
    if (a.M!=b.M){
        return 0;
    }
    else if(a.N != b.N){
        return 0;
    }
    else{
        return 1;
    }
}

//verification
int is_nogram_valid(nogram nm){
    
}

int is_line_valid(int line[], int len_line, hint h){
    // Check the line is well-defined
    if (is_line_set(line, len_line) == 0)
        return 0;
    
}

int is_line_set(int line[], int len_line){
    int undef_i, def_i ;
    undef_i = findfirst_int_arr(line,len_line, Undef_Site_Val);
    def_i = findfirst_int_arr(line,len_line, Default_Site_Val);

    if(undef_i != -1)
        printf("Warning: the input array containing Undefine region at %d", undef_i);

    if(def_i!=-1)
        printf("Warning: the input array containing default region at %d", def_i);

    if ( (undef_i!=-1) | (def_i!=-1))
        return 0;

    return 1;
}


//Display
char bool2sym(int a){
    char as;
    if (a == fill_val){
        return fill;
    }
    else if(a==hole_val){
        return hole;
    }
    else if (a==Default_Site_Val | a==Undef_Site_Val){
        int2str(&as, a);
        return as;
    }
    else {
        printf("Map value undefine");
        exit(-1);
    }
}
void print_nogram_str(nogram nm){
    char* nogram_str;
    nogram_str = create_nogram_str(nm);
    printf("%s\t", nogram_str);
    close_nogram_str(nogram_str);
}
char* create_nogram_str(nogram nm){
    size_t mapsize = ((nm.size.N+1) * (nm.size.M+1)+ 1) * sizeof(char) ;
    char val;
    char* mapstr = (char*)malloc(mapsize);
    assert(mapstr!=NULL);


    //Save values
    for(int n=0;n<nm.size.N;n++){
        strncat(mapstr, "\n", sizeof("\n"));
        for(int m=0;m<nm.size.M;m++){
            val = bool2sym(nm.map[n][m]);
            strncat(mapstr, &val, sizeof(char));
        }
    }

    return mapstr;
}

void close_nogram_str(char* nm_str){
    killstr(nm_str);
}

void print_hint_str(hint h){
    char* s  = create_hint_str(h);
    printf("%s", s);
    close_hint_str(s);
}

char* create_hint_str(hint h){
    int max_len = 2*MAX_LINES;
    char s[MAX_LINES];

    //Allocate memory
    char* hstr = (char*)malloc(max_len*sizeof(char));
    assert(hstr != NULL);

    //Paste info to string
    int2str(s,h.nPoint);
    strncat(hstr, s, sizeof(h.nPoint));
    for(int i=0;i<h.nPoint;i++){
        strncat(hstr, " ", sizeof(" "));
        int2str(s, h.pLens[i]);
        strncat(hstr, s, sizeof(h.pLens[i]));
    }

    return hstr;
}

void close_hint_str(char* hstr){
    killstr(hstr);
}