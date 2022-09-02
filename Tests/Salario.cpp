#include <stdio.h>

int main() {
	float sal, vp, v25, valemp;
	int qp;
	printf("Informe salario: ");
	scanf("%f", &sal);
	printf("Informe valor do emprestimo: ");
	scanf("%f", &valemp);
	printf("Entre com quantidade de parcelas: ");
	scanf("%d", &qp);
	vp=valemp/qp;
	v25=sal*0.25;
	if (vp<=v25) {
	   printf("Emprestimo concedido\n");
	   printf("Valor parcela = %.2f\n", vp);
    } else printf("Emprestimo negado\n");
    
    return 0;
}
