#include <stdio.h>
#include <stdlib.h>
//concatenar
char *Func_strchr(char *palavra, int n)
{
    while (palavra != (char)n)
    {
        if (!*palavra++)
        {
            return NULL;
        }
    }
    return (char *)palavra;
}
int main()
{
    char *palavra, letra;
    palavra = (char *)(malloc(1000 * sizeof(char)));
    scanf(" %[^\n]s\n", palavra);
    fflush(stdin);
    printf("Escreva a letra procurada\n");
    scanf("%c", &letra);
    char *aux = Func_strchr(palavra, letra);
    printf("s = %s \n", aux);
    free(palavra);

    return 0;
}
//matriz sem index
// *(*(matriz+i)+j)=aux;
