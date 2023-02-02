#include<stdio.h>
#include<stdlib.h>

int main(){
    int a[] = {1,2,3,4,5}; // 123, 127, 131, 135, *139

    int *p = malloc(sizeof(int)*5);// 20 bytes [$(0), $(1), $(2), $, $]
    p = a;
    p[4] = 100;
    printf("%d\n", a[4]);
    printf("%d", *(a+1));
}
    // output: 5 2