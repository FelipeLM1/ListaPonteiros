#include <stdio.h>
#include <stdlib.h>

void Ordena(float *p,int n){
    for (int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if (*(p+i)< *(p+j)){
                float aux = *(p+i);
                *(p+i)=*(p+j);
                *(p+j)=aux;
            }
        }
    }
}


int main(){
    int n;
    printf("Digite a quantidade de numeros :\n");
    scanf("%d",&n);
    float *p;
    p=(float*)malloc(sizeof(float)*n);
    for(int i=0; i<n; i++){
        printf("Digite o valor da posicao %i: \n", i);
        scanf("%f",(p+i));

    }
    Ordena(p,n);
    for(int i=0; i<n; i++){
        printf("%.1f ", *(p+i));
    }
    printf("\n");
    free(p);
    return 0;
}

