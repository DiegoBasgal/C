#include <stdio.h>

int main() {
	float x, y, z, v;
	printf("Informe as 3 medidas do hexaedro:");
	scanf("%f %f %f", &x, &y, &z);
	v=x*y*z;
	printf("Volume = %f\n", v);
	return 0;
}
