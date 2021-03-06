# CProjectTemplate




![](https://user-images.githubusercontent.com/29009898/110197098-19e2aa00-7e84-11eb-8e0c-396e6a0056a3.png)


## Create 2D array with double pointer and one malloc call

```c
#include<stdio.h> 
#include<stdlib.h> 
  
int main() 
{ 
    int r=3, c=4, len=0; 
    int *ptr, **arr; 
    int count = 0,i,j; 
  
    len = sizeof(int *) * r + sizeof(int) * c * r; 
    arr = (int **)malloc(len); 
  
    // ptr is now pointing to the first element in of 2D array 
    ptr = (int *)(arr + r); 
  
    // for loop to point rows pointer to appropriate location in 2D array 
    for(i = 0; i < r; i++) 
        arr[i] = (ptr + c * i); 
  
    for (i = 0; i < r; i++) 
        for (j = 0; j < c; j++) 
            arr[i][j] = ++count; // OR *(*(arr+i)+j) = ++count 
  
    for (i = 0; i < r; i++) 
        for (j = 0; j < c; j++) 
            printf("%d ", arr[i][j]); 
  
    return 0; 
} 
```

## Git tag

```sh
git tag -a v1.4 -m "my version 1.4"
```

## Reference
1. 2D array construction. [[GreekforGeek](https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/)]
2. Git tag. [[Blog](https://git-scm.com/book/zh-tw/v2/Git-%E5%9F%BA%E7%A4%8E-%E6%A8%99%E7%B1%A4)]
3. Integer to string: `itoa`. [[Blog](https://www.cnblogs.com/oomusou/archive/2007/01/06/613413.html)]
4. Compare with `memcpy` [[Tutorial](http://tw.gitbook.net/c_standard_library/c_function_memcmp.html)]
    - 不能用於 struct [[reason](https://stackoverflow.com/questions/141720/how-do-you-compare-structs-for-equality-in-c)]