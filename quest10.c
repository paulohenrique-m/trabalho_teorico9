//matriz sem index
// *(*(matriz+i)+j)=aux;
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
    Crie um programa para gerenciar o cadastro de produtos. Cada produto 
    deve ser armazenado em uma estrutura com as informações de código, 
    descrição e valor. Seu programa deve ser capaz de armazenar n produtos, 
    sendo que o valor n deve ser informado pelo usuário. Seu programa deve usar 
    funções e ponteiros para executar as seguintes operações:
        -Cadastrar um novo produto
        -Editar os dados de um produto
        -Excluir um produto
        -Exibir todos os produtos cadastrados
        -Exibir a quantidade total de produtos
*/
//tipificando o produto
typedef struct
{
    int codigo;
    char descricao[100];
    float valor;
} Produto;
/*
funcao para cadastrar um produto na posição qtd+1(e se não tiver cadastrado, na posicao 0)
entrada:produto a ser cadastrado com seus dados e quantidade de itens cadastrados
saída:não tem!
*/
void cadastra_produtos(Produto *produto, int qtd_cadastrados)
{
    produto += qtd_cadastrados;
    printf("\n------cadastro------\n");
    printf("\ncodigo do produto[%i]:", qtd_cadastrados + 1);
    scanf("%i", &produto->codigo);
    printf("\ndescricao do produto[%i]:", qtd_cadastrados + 1);
    //scanf("%[^\n]s\n", &produto->descricao);
    scanf("%s", produto->descricao);
    printf("\nvalor do produto[%i]:", qtd_cadastrados + 1);
    scanf("%f", &produto->valor);
    printf("\n------produto[%i] cadastrado com sucesso!!------\n", qtd_cadastrados + 1);
    //*qtd_cadastrados = *qtd_cadastrados + 1; usar quando n for ponteiro!!
}

void editar_produto(Produto *produto, int qtd_cadastrados)
{
    int aux;
    printf("qual codigo do produto que sera modificado: ");
    scanf("%i", &aux);
    produto += aux;
    printf("digite descricao nova: ");
    scanf("%s", (produto)->codigo);
    printf("digite um novo valor: ");
    scanf("%f", &(produto)->valor);
}

/*
funcao para exibir produtos cadastrados 
entrada:produto a ser cadastrado com seus dados e quantidade de itens cadastrados
saída:não tem!
*/
void exibir_produtos(Produto *produto, int qtd_cadastrados)
{
    for (int i = 0; i < qtd_cadastrados; i++)
    {
        printf("\n-----produto[%i]-----\n", i + 1);
        printf("\ncodigo: %i", produto->codigo);
        printf("\ndescricao: %s", produto->descricao);
        printf("\nvalor: %0.2f", produto->valor);
        produto++;
    }
}
//fazer if para nao rodar as outras funcoes se nao tiver nenhum produto cadastrado
int main()
{
    Produto *produto = malloc(1000 * sizeof(Produto));
    int qtd_cadastro; //valor n informado pelo usuario para cadastrar
    int n = 0;        //itens ja cadastrados(so o contador)
    int opc = -1;
    //variaveis para questão
    char pergunta[10];
    printf("quantos produtos deseja cadastrar: ");
    scanf("%i", &qtd_cadastro);
    while (opc != 0)
    {
        printf("\n-------------SISTEMA-------------\n");
        printf("1-cadastra produtos\n");
        printf("2-editar produtos\n");
        printf("3-excluir produtos\n");
        printf("4-exibir produtos\n");
        printf("5-exibir quantos produtos\n");
        printf("0-SAIR\n");
        scanf("%i", &opc);
        if (n < 1 && opc != 1 && opc != 0)
        {
            printf("cadastre no minimo 1 produto!");
        }
        else
        {
            if (qtd_cadastro > n)
            {

                switch (opc)
                {
                case 1:
                    //cadastro
                    cadastra_produtos(produto, n);
                    printf("\n\nproduto[%i] cadastrado", n + 1);
                    n++;
                    break;

                case 2:
                    //editar
                    editar_produto(produto, n);
                    printf("produto editado");
                    break;

                case 3:
                    //excluir
                    //excluir_produtos(&produto, qtd_cadastro);
                    break;

                case 4:
                    //exibir todos os produtos
                    exibir_produtos(produto, n);
                    break;

                case 5:
                    //exibir qtd(n) cadastrados
                    break;
                case 0:
                    printf("\nSAINDO!");
                default:
                    printf("menu-error!");
                    break;
                }
            }
            else
            {
                printf("maximo de produtos!!\n");
                break;
            }
        }
    }
    return 0;
}
