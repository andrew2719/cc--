#include<stdio.h>
#include<stdlib.h>

int main(){
    int a[100]; // {0,0,0,.....0}
    // 0...50
    
    int *p = calloc(100, sizeof(int)); 

    p[90] = 100;
    p[40] = 100;
    // reallocs
    p = realloc(p, 50*sizeof(int)); // [1,2,3,4] // [0,0,0]
    printf("%d", p[90]); 
    printf("%d", p[40]);
    // malloc has garbage values,// [$,$,$....$]
    // calloc has 0 values
    free(p);


}