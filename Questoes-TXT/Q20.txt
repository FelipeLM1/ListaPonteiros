#include "gc.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

	int i;
	int *a;
	double t1,t2,TMPgc,TMPmall;
	t1=clock();
	GC_INIT();
	for (i=0; i< 1<<10; i++){
		int *p = (int *) GC_MALLOC(1000*sizeof(int));
	}
	t2=clock();
	TMPgc=(t2-t1)/(CLOCKS_PER_SEC / 1000);
	t1=clock();
	for(i=0; i< 1<<10; i++){
		int *p = (int *) malloc(1000*sizeof(int));
		free(p);
	}
	t2=clock();
	TMPmall=(t2-t1)/(CLOCKS_PER_SEC / 1000);

	printf("\n\nTempo gasto com GC_MALLOC: %.3f", TMPgc);
	printf("\n\nTempo gasto com malloc: %.3f", TMPmall);
	
	return 0;
}
