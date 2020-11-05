//matriz sem index
// *(*(matriz+i)+j)=aux;
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define linha 3
#define coluna 3
/*Construa um programa que aloque em tempo de execução (dinamicamente)
uma matriz de ordem m x n (linha por coluna). Preencha a matriz com elementos 
aleatórios e em seguida exiba o menor número e a sua posição na matriz, o maior 
número e a sua posição na matriz.*/

/*
funcao para somar todos os numeros da matriz
entrada:ponteiro de ponteiro apontada para uma matriz
saida: retorna a soma de todos os numeros(aleatorios) da matriz
*/
int soma_matriz(int **matriz)
{
    int soma = 0;
    //linha e coluna são variaveis globais
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            soma += *(*(matriz + i) + j);
        }
    }

    return soma;
}

int main()
{
    int **matriz = (int *)malloc(linha * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < coluna; i++)
    {
        *(matriz + i) = (int *)malloc(coluna * sizeof(int));
    }

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            *(*(matriz + i) + j) = rand() % 100 + 1;
        }
    }
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            printf("%d ", *(*(matriz + i) + j));
        }
        printf("\n");
    }
    int maior = **matriz;
    int menor = **matriz;
    //for para pegar o menor e o maior valor dentro de uma matriz de ponteiro
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            if (menor > *(*(matriz + i) + j))
            {
                menor = *(*(matriz + i) + j);
            }
            if (maior < *(*(matriz + i) + j))
            {
                maior = *(*(matriz + i) + j);
            }
        }
    }
    printf("\nmenor:%i", menor);
    printf("\nmaior:%i", maior);
    //for para pegar a posicao do menor e do maior de acordo com a aparicao
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            if (menor == *(*(matriz + i) + j))
            {
                printf("\no menor estar na posicao [%i][%i]", i + 1, j + 1);
            }
            if (maior == *(*(matriz + i) + j))
            {
                printf("\no maior estar na posicao [%i][%i]", i + 1, j + 1);
            }
        }
    }
    free(matriz);
    return 0;
}
