#include <stdio.h>
#include <stdlib.h>

void Somav(float *a,float *b,float *c,int n){       // função soma de vetores
    for (int i=0; i<n ; i++){
        *(c+i)=*(a+i)+*(b+i);           // soma dos vetores
    }
}
int main()
{
    int n;
    printf("Digite a quantidade de posicoes para o vetor: \n"); // receber o tamanho dos vetores
    scanf("%i", &n);
    float *v1 = (float*)malloc(sizeof(float)*n);                // alocar a memoria para os vetores
    float *v2 = (float*)malloc(sizeof(float)*n);
    float *v3 = (float*)malloc(sizeof(float)*n);
    if (n<=0){                                                  // Fazer com que o programa encerre se o n for menor ou igual a 0
        printf("\nValor invalido, programa encerrado.\n");
    }
    else{
        float *v1 = (float*)malloc(sizeof(float)*n);                // alocar a memoria para os vetores
        float *v2 = (float*)malloc(sizeof(float)*n);
        float *v3 = (float*)malloc(sizeof(float)*n);
        for (int i=0;i<n;i++) 
	{
            printf("Digite o valor da posicao %d do vetor 1: ", i);
            scanf("%f",(v1+i));                                     // receber os valores na posição de memoria indicada
       	}
        printf("\n");
        for (int i=0;i<n;i++)
	 {
            printf("Digite o valor da posicao %d do vetor 2: ", i);
            scanf("%f",(v2+i));                                     // receber os valores na posição de memoria indicada
         }
        for (int i=0;i<n;i++) 
	{
            *(v3+i)=0;                                              // zerar o conteudo do vetor
        }
   }
        Somav(v1,v2,v3,n);                                         // chamada da função
        printf("\nVetor soma: ");
        for (int i=0; i<n; i++) {
            printf("%.1f ",*(v3+i));                              // impressao do vetor soma
        }
        printf("\n\n");
        free(v1);                                                 // liberação do espaço de memoria alocado
        free(v2);
        free(v3);

    return 0;
}

