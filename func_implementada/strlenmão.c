#include <stdio.h>
#include <stdlib.h>

/*
int main()
{
    //USANDO STRLEN POREM COM PONTEIRO
    char *teste[] = {"programa do paulo"};
    int *ptr = strlen(*teste);
    printf("%s", *teste);
    printf("\n");
    printf("numero de palavras:%d", ptr);
    return 0;
}
*/
int tamanho_string(char *a)
{
    int aux = 0;
    for (; *a != '\0'; a++)
    {
        aux++;
    }
    return aux;
}
int main()
{
    //USANDO STRLEN FEITO A MÃO
    char *teste = (char *)malloc(1000 * sizeof(char));
    scanf(" %[^\n]s\n", teste);
    printf("\nteste feito:%s\n", teste);
    int aux = tamanho_string(teste);
    printf("numero de palavras:%d", aux);
    free(teste);
    return 0;
}