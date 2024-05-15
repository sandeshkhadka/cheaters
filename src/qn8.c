#include<stdio.h>
#include<conio.h>

int toh(int,char,char,char);

void main(){
    int n;
    printf("enter the number of n ");
    scanf("%d" ,&n);
    toh(n,'O','D','I');
    getch();
}

int toh(int n,char a,char b,char c){
    if(n>0){
        toh(n-1,a,c,b);
        printf("move %d disk from %c to %c\n",n,a,b);
        toh(n-1,c,b,a);
    }
    printf("By Sijan Panta");
}