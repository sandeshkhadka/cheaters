#include <stdio.h>

long long fact(int x) {
    if (x==1 || x==0){
        return 1;
    }
else{
        return (x * fact(x - 1));
    }
}


int main() {
    int x;
    printf("enter any number 3");
    scanf("%d",&x);
    printf("Factorial of %d is %d.\n",x, fact(x));
    printf("by Sijan Panta");
    return 0;
}
