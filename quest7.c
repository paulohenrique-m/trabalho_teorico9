#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n1, n2;
    int *aux = (int *)malloc(1000 * sizeof(int));
    scanf("%i", &n1);
    scanf("%i", &n2);
    int opc = -1;
    while (opc != 0)
    {
        printf("\n-----calculadora-----\n");
        printf("1-soma\n");
        printf("2-subtracao\n");
        printf("3-multiplicacao\n");
        printf("4-divisao\n");
        printf("5-trocar os numeros\n");
        printf("0-SAIR\n");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
            *aux = n1 + n2;
            printf("\n%i", *aux);
            break;

        case 2:
            *aux = n1 - n2;
            printf("\n%i", *aux);
            break;

        case 3:
            *aux = n1 * n2;
            printf("\n%i", *aux);
            break;

        case 4:
            *aux = n1 / n2;
            printf("\n%i", *aux);
            break;
        case 5:
            scanf("%i", &n1);
            scanf("%i", &n2);
            break;

        default:
            printf("\nN/A");
            break;
        }
    }
    free(aux);
    return 0;
}
