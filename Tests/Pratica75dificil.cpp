#include <stdio.h>

int main(){
	
	int c = 1, qtdeImpares = 0;
	
	while(qtdeImpares < 100){
		//Se contador atual é ÍMPAR
		if(c % 2 != 0){
			printf("%d ", c);
			qtdeImpares++;			
		}
		c++;
	}
	
	return 0;
}
