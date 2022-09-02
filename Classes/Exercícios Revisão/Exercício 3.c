#include <stdio.h>

int mdc (int x, int y){
    if (x==0 && y==0 )
        return -1;
    else if (x==0)
        return y;
    else if (y==0)
        return x;
    else{
        while (x!=y)
            if (x>y)
            x=x-y;
            else y=y-x;
                return x;
    }
}
int main (){
    int x, y, z;
    printf("Infrome dois valores inteiros: ");
    scanf("%d %d", &x, &y, &z);
    x=abs(x);
    y=abs(y);
    z=abs(z);
    z = mdc(x,y);
    if (z
         == 1){
        printf("MDC indefinido\n");
    }
    else{
        printf("mdc=%d\n", z);
    }
    return 0;
}
