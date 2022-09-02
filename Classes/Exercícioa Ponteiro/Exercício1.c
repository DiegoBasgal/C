#include <stdio.h>

int main () {
    int a = 1;
    int *p = &a;
    int b = (*p)++;
    printf("%d %d %d %d %d %d\n", a, p, b, &a, *p, &b);
    return 0;
}
