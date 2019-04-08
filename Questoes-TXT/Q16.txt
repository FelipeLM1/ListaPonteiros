#include <stdio.h>
#include <stdlib.h>
#define MENOR -1
#define IGUAL 0
#define MAIOR 1

int compara(float a, float b){
	
	if (a>b)
		{ return MAIOR;}
	else if(a<b) 
		{return MENOR;}
	else 
		{return IGUAL;}	

}

void Ordena(float *p, int n, int (*comp)(float,float)){
	
    for(int i = 0; i < n - 1; i++) {
      int menor = i;
      	for(int j = i + 1; j < n; j++) {
         	if (comp(p[j], p[menor]) == MENOR) menor = j;
      	}
      float aux = p[i];
      p[i] = p[menor];
      p[menor] = aux;
   }
}

void imprimirVetor(float *p, int n) {
   printf("[");
   for(int i = 0; i < n - 1; i++) {
      printf("%.2f ", p[i]);
   }
   printf("%.2f]\n", p[n - 1]);
}



int main() {
	int n;
	printf("Digite o tamanho do vetor: ");
	scanf("%i", &n);   
	float *vetor=(float*)malloc(sizeof(float)*n);	  
	
	for(int i=0; i<n; i++){
 	       printf("Digite o valor da posicao %i: \n", i);
 	       scanf("%f",(vetor+i));                          
    	}

	printf("Vetor antes: ");
	imprimirVetor(vetor,n);
	Ordena(vetor,n,&compara);
	printf("Vetor ordenado: ");
	imprimirVetor(vetor,n);	
	free(vetor);

   return 0;
}
