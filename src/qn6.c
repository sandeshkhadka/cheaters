#include <stdio.h>

int fab(int x){
    if (x==1|| x==0){
        return 1;
    }else{
        return fab(x-1)+fab(x-2);
    }

}


int main() {
    int n;
    printf("enter the number of terms");
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        printf("%d  ",fab(i));
    }

    printf("By Sijan Panta");
}
