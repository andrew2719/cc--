#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
    int num;
    int age;
    char name[20];
};


int main(){

    int n = 100;
    struct student a[n];
    struct student *pointer;
    a[1].num = 10; // A  =10, A = &A[1].NUM ,= 123
    a[1].age = 15;
    char name_2[20];
    scanf("%s",a[1].name);
    strcpy(a[1].name, name_2);

    printf("%d %d %s", a[1].num, a[1].age, a[1].name);


    
    // x = address of something
}