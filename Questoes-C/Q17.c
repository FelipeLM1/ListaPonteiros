#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MENOR -1
#define IGUAL  0
#define MAIOR  1

int Compara16(float a, float b){
	
	if (a>b)
		{ return MAIOR;}
	else if(a<b) 
		{return MENOR;}
	else 
		{return IGUAL;}	

}
int Compara15(const void* a, const void* b){
    return ( *(float*)a - *(float*)b);               
} 
void Ordena16(float *p, int n, int (*comp)(float,float)){
	
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
	int n,i;
	printf("Digite o tamanho do vetor: ");
	scanf("%i", &n);   
	float *vetor=(float*)malloc(sizeof(float)*n);	  
	float *vetor2=(float*)malloc(sizeof(float)*n);
	for(i=0;i<n;i++){ 
		vetor[i]=rand()%100; 	
		vetor2[i]=rand()%100; 		 
	}
	printf("Vetor 1 antes: ");	
	imprimirVetor(vetor,n);
	printf("\n\n");
	printf("Vetor 2 antes: ");	
	imprimirVetor(vetor2,n);
	printf("\n\n");
	double t1,t2,t3,t4,tmpQsort,Meutmp;
	t1=clock();					// pegar tempo inicial do qsort
	qsort(vetor,n,sizeof(float),Compara15);
	t2=clock();					// pegar tempo final
	tmpQsort=((t2-t1)/(CLOCKS_PER_SEC / 1000));					// Subtrair os dois tempos para ver o tempo de execucao do qsort
	t3=clock();					// pegar tempo inicial da minha funcao
	Ordena16(vetor2,n,&Compara16);
	t4=clock();					// pegar tempo final da minha funcao e subtrair
	Meutmp=((t4-t3)/ (CLOCKS_PER_SEC / 1000));
	printf("Vetor ordenado 1: ");
	imprimirVetor(vetor,n);	
	printf("\n\n");
	printf("Vetor ordenado 2: ");
	imprimirVetor(vetor2,n);	
	printf("\nTempo Qsort: %.5f ms", tmpQsort );
	printf("\nTempo Funçao implementada : %.5f ms", Meutmp);
	printf("\n\n\n\n\n");
return 0;
}








