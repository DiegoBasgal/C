#include <stdio.h>

int main () {
	float b, h, p, a;
	printf("Informe base e altura do retangulo: ");
	scanf("%f %f", &b, &h);
	p=2*b+2*h;
	a=b*h;
	printf("Area = %.2f Perimetro = %.2f\n", a, p);
	return 0;
}
