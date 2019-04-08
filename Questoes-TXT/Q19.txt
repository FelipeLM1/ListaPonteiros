#include <stdio.h>
#include <stdlib.h>

int Limpa() // funçao criada apenas para pular linhas,funcionando como a função clear,mas sem precisar usar o system que varia para cada SO
{
    puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    return 0;
}
void multiplica(int **a,int **b,int **c,int nla,int nca,int ncb){ // funçao que faz a multiplicação das matrizes
    for(int i=0; i<nla; i++){
        for (int j=0; j<ncb;j++){
            c[i][j]=0;
            for (int k=0; k<nca;k++){
                c[i][j]=(a[i][k]*b[k][j])+c[i][j];
            }
        }
    }
}
int main()
{
    int **a,**b,**c;                                         // ponteiros que apontam para outro ponteiro int
    int nla,nca,nlb,ncb;                                     // numeros de linhas a / numeros colunas a / n. linhas b / n. colunas b
    printf("\nDigite o numero de linhas da matriz 1: ");      // recebe as informaçoes de dimensao das matrizes
    scanf("%d", &nla);
    printf("\nDigite o numero de colunas da matriz 1: ");
    scanf("%d",&nca);
    nlb=nca;                                                // supoe-se que o numero de linhas da matriz b seja igual ao numero de coluna da matriz a
    printf("\nDigite o numero de colunas da matriz 2: ");
    scanf("%d",&ncb);
    int nlc=nla,ncc=ncb;                                    // uma multiplicação de duas matrizes Lxp * pxC resulta em uma matriz LxC por isso a matriz C sera nlaXncb
    a=(int**)malloc(sizeof(int*)*nla);                        // alocamento para cada linha das matrizes
    b=(int**)malloc(sizeof(int*)*nlb);
    c=(int**)malloc(sizeof(int*)*nlc);
    for (int i=0; i<nla; i++){
        a[i]=(int*)malloc(sizeof(int)*nca);               // Alocamento para as colunas das matrizes.Cada linha alocada anteriormente agora tem alocamento para cada coluna
    }                                                     // EX: uma matriz 2x3 anteriormente teria alocado somente as linhas --> |l1|l2|
    for (int i=0;i<nlb;i++) {                             // Agora cada linha tem mais 3 alocamentos para as colunas --> |l1c1|l1c2|l1c3|l2c1|l2c2|l3c3| formando um vetor de vetores ou matriz bidimensional
        b[i]=(int*)malloc(sizeof(int)*ncb);
    }
    for (int i=0;i<nlc;i++) {
        c[i]=(int*)malloc(sizeof(int)*ncc);
    }
    for (int i=0; i<nla;i++){                               // recebe os valores da matriz a
        for (int j=0; j<nca; j++){
            printf("\nDigite o valor da posicao [%d][%d] da matriz 1 :", i,j);
            scanf("%d",&a[i][j]);
        }
    }
    for (int i=0; i<nlb;i++){                               // recebe os valores da matriz b
        for (int j=0; j<ncb; j++){
            printf("\nDigite o valor da posicao [%d][%d] da matriz 2 :", i,j);
            scanf("%d",&b[i][j]);
        }
    }
    multiplica(a,b,c,nla,nca,ncb);                  // chamada da funçao que multiplica as matrizes
    Limpa();                                        // chamada da função que pula varias linha para melhor vizualização
    printf("Matriz 1: \n");
    for (int i=0; i<nla;i++){                       // mostra a matriz a
        for (int j=0; j<nca; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\nMatriz 2: \n");                         // mostra a matriz b
    for (int i=0; i<nlb;i++){
        for (int j=0; j<ncb; j++){
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    printf("\nMatriz 1 * 2: \n");                       // mostra a matriz a*b
    for (int i=0; i<nlc;i++){
        for (int j=0; j<ncc; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}

