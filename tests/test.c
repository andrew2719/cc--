#include<stdio.h>
#define S(n) scanf("%d",&n)
#define P(n) printf("%d",n)


int main(){
    int n;
    S(n);
    // print frequency of each digit
    int freq[10]={0};
    int temp=n;
    while(n){
        freq[n%10]++;
        n/=10;
    }
    // numbers in the order of the original number
    int i=0;
    for(int i=0;i<10;i++){
        if(freq[i]){
            P(i);
            printf("-");
            P(freq[i]);
            printf("\n");
        }
    }
    


}
