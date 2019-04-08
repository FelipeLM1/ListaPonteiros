#include "gc.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// EXEMPLO DE APLICAÇÃO DO LIBGC: Somar um vetor muito grande com ele mesmo e comparar o desempenho do GC_MALLOC com o malloc


void SomaV(int *a, int n){ 
	int i;
	for (i=0; i<n ; i++){
 		a[i]=(a[i]+a[i]);
	}
}
/*void testesoma(int *a, int n){
	int i;
	for (i=0; i<n ; i++){
 		printf(" (%d) ",a[i]);
	}
}*/

void randv(int *a, int n){ 
	int i;
	for (i=0; i<n ; i++){
 		a[i]=rand()%100;
	}
}

int main()
{
	int n=1<<10;
	int i;
	int *a;
	double t1,t2,TMPgc,TMPmall;
	
 	t1=clock();
	GC_INIT();
	int *v1 = (int *) GC_MALLOC(n*sizeof(int));
	randv(v1,n);
	SomaV(v1,n);	
	t2=clock();
	TMPgc=(t2-t1)/(CLOCKS_PER_SEC / 1000);
	
	t1=clock();
	int *v2 = (int *) malloc(n*sizeof(int));
	randv(v2,n);
	SomaV(v2,n);
	free(v2);
	t2=clock();
	TMPmall=(t2-t1)/(CLOCKS_PER_SEC / 1000);	
	
	printf("\n\nTempo gasto com GC_MALLOC: %.3f ms", TMPgc);
	printf("\n\nTempo gasto com malloc: %.3f ms", TMPmall);
	printf("\n\n");
	return 0;
}
