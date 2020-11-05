#include <stdio.h>
#include <stdlib.h>
//concatenar
char func_strcat(char *a, char *b)
{
    int i, j;
    for (i = 0; a[i] != '\0'; ++i)
        ;
    for (j = 0; b[j] != '\0'; ++j, ++i)
    {
        a[i] = b[j];
    }
    a[i] = '\0';
    return *a;
}
int main()
{
    char *text1 = (char *)malloc(1000 * sizeof(char));
    char *text2 = (char *)malloc(1000 * sizeof(char));
    scanf("%[^\n]s\n", text1); //scanf("%s", text1);
    fflush(stdin);
    scanf("%[^\n]s\n", text2); //scanf("%s", text2);
    func_strcat(text1, text2);
    printf("\nteste feito:%s\n", text1);
    printf("\nteste feito:%s\n", text2);
    free(text1);
    free(text2);
    return 0;
}
