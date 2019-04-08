#include <stdio.h>
#include <stdlib.h>


int Compara(const void* a, const void* b){
    return ( *(float*)a - *(float*)b);               // Se a > b retorna valor positivo, e o qsort faz com que o a esteja em uma posição anterior a b
}                                                    // Se a = b retorna zero e o qsort mantem as posiçoes atuais
                                                     // Se a < b retorna um valor negativo e o qsort faz com que o a venha depois do b
int main(){
    int n;
    printf("Digite a quantidade de numeros :\n");
    scanf("%d",&n);                                  // Recebe a quantidade de posições do vetor
    float *p=(float*)malloc(sizeof(float)*n);        // Aloca a memoria dependendo da quantidade de posições do vetor
    for(int i=0; i<n; i++){
        printf("Digite o valor da posicao %i: \n", i);
        scanf("%f",(p+i));                           // Recebe os valores das posições do vetor

    }
    printf("\nVetor antes de ser ordenado: ");
    for(int i=0; i<n; i++){
        printf("%.1f ", *(p+i));                     // Imprime o vetor na posição original
    }
    qsort(p,n,sizeof(float),Compara);                 // A função qsort tem como paramentros o endereço de onde começa os valores dos vetores, a quantidade
    printf("\nVetor depois de ser ordenado: ");      // de posições, o tamanho do tipo de dado, e a função de comparação criada que nesse caso é a de ordenar de forma crescente
    for(int i=0; i<n; i++){
        printf("%.1f ", *(p+i));                     // Imprime o vetor depois de ser modificado pela função qsort()
    }
    printf("\n");
    free(p);                                         // Libera o espaço de memoria alocado
    return 0;
}

