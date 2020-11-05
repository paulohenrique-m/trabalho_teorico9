//matriz sem index
// *(*(matriz+i)+j)=aux;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//concatenar
/*Faça um programa que leia um valor n e crie dinamicamente um vetor 
de n elementos. Preencha o vetor com n elementos aleatório e em seguida
apresente a soma dos elementos do vetor.*/
int main()
{
    int n;
    int aux = 0;
    srand(time(NULL));
    printf("\ntamanho do vetor:");
    scanf("%i", &n);
    int *vetor = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        *(vetor + i) = rand() % 100 + 1;
        aux += *(vetor + i);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", *(vetor + i));
    // }
    printf("\nsoma=%d", aux);

    free(vetor);
    return 0;
}
