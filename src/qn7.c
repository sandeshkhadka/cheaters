#include<stdio.h>

int gcd(int a, int b) {
    if(b==0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}

int main(){
    int num1,num2;
    printf("enter two number non negative number ");
    scanf("%d %d",&num1,&num2);
    int g=gcd(num1,num2);
    printf("%d",g);
    return 0;
    printf("By Sijan Panta");
}