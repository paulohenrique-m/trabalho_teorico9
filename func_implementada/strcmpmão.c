#include <stdio.h>
#include <stdlib.h>

int func_strlen(char *a)
{
    int aux = 0;
    for (; *a != '\0'; a++)
    {
        aux++;
    }
    return aux;
}
int func_strcmp(char *a, char *b)
{
    int aux1 = func_strlen(a);
    int aux2 = func_strlen(b);
    if (aux1 < aux2)
    {
        return -1;
    }
    else if (aux1 > aux2)
    {
        return 1;
    }
    else if (aux1 == aux2)
    {
        return 0;
    }
}
int main()
{
    char *text1 = (char *)malloc(1000 * sizeof(char));
    char *text2 = (char *)malloc(1000 * sizeof(char));
    scanf("%[^\n]s\n", text1);
    fflush(stdin);
    scanf("%[^\n]s\n", text2);
    printf("\nteste feito:%s\n", text1);
    printf("\nteste feito:%s\n", text2);
    int resp = func_strcmp(text1, text2);
    printf("%i", resp);
    free(text1);
    free(text2);
    return 0;
}