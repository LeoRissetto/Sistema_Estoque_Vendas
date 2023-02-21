#include <stdio.h>
#include <stdlib.h>


#include "vendas.h"

//funcoes destinadas a adicao, remocao e display de estoque 

void adicionaProduto() //adiciona um produto ao estoque
{
    clean();

    int cod,qnt;
    float price;
    char *nome;
    
    printf("Digite o codigo do produto: ");
    scanf("%d", &cod);

    if(isIn(cod)==1)
    {
        printf("\n\nEste codigo ja existe, favor escolher um diferente.\n\n");
    }

    else
    {
        printf("Digite o nome do produto: ");
        getchar();
        readline(&nome);

        printf("Digite o quantidade do produto: ");
        scanf("%d", &qnt);

        printf("Digite o preco do produto: ");
        scanf("%f", &price);

        clean();

        FILE *f ; 
        f = fopen("estoque.txt", "a");

        fprintf(f, "%d;%d;%.2f;%s\n", cod,qnt,price,nome);
        printf("Produto Adicionado com sucesso !!\n\n\n");

        fclose(f);
    }
    
    time();
    return;
}

void deleteProduto()    //remove por completo um produto do estoque
{
    clean();

    int cod;

    printf("Digite o Codigo do prduto: ");
    scanf("%d", &cod);
    clean();

    if(isIn(cod)==1)
    {
        int cod1;
        float price;
        char *nome1;
        int qnt;
        char nome[50];

        FILE *f;
        FILE *f1;
        f=fopen("estoque.txt","r");
        f1=fopen("temp.txt","w");

        while(fscanf(f, "%d;%d;%f;%s\n", &cod1,&qnt,&price,nome)!=EOF)
        {
            if(cod != cod1)
            {
                fprintf(f1, "%d;%d;%.2f;%s\n",cod,qnt,price,nome);
            }
        }
        rename("estoque.txt", "trash.txt");
        rename("temp.txt","estoque.txt");

        remove("trash.txt");
        fclose(f1);
            
        printf("Produto Deletado com Sucesso!!!\n\n\n");
    }

    else if(isIn(cod)==0)
    {
        printf("\n\nEste produto Nao Existe No Estoque !!\n\n");
    }

    time();
    return;
}

void mostraEstoque()    //mostra todo o estoque
{
    clean();

    FILE *f ; 
    f = fopen("estoque.txt", "r");

    int cod,qnt;
    float price;
    char nome[50];

    printf("Codigo\t\t\tQuantidade\t\t\tPreco\t\t\tNome\n\n");

    while(fscanf(f, "%d;%d;%f;%s\n", &cod,&qnt,&price,nome)!=EOF)
    {
        printf("%d\t\t\t%d\t\t\t\t%.2f\t\t\t\t%s\n",cod,qnt,price,nome);
    }

    fclose(f);
    time();

    return;
}

void removeProduto(int cod, int qnt)    //remove uma certa quantidade de um produto do estoque
{
    int cod1,qnt1;
    float price;
    char nome[50];
    FILE *f;
    FILE *f1;

    f=fopen("estoque.txt","r");
    f1=fopen("temp.txt","w");

    while(fscanf(f, "%d;%d;%f;%s\n", &cod1, &qnt1, &price, nome)!=EOF)
    {
        if(cod1 != cod)
        {
            fprintf(f1, "%d;%d;%.2f;%s\n",cod1,qnt1,price,nome);
        }

        else
        {
            fprintf(f1, "%d;%d;%.2f;%s\n",cod1,qnt1-qnt,price,nome);
        }
    }

    rename("estoque.txt", "trash.txt");
    rename("temp.txt","estoque.txt");
    remove("trash.txt");\
    fclose(f1);

    return;
}

void mostrarProduto()   //mostra as propriedades de um determinado produto do estoque
{
    clean();

    int cod;

    printf("Digite o Codigo do Produto: ");
    scanf("%d", &cod);
    clean();

    FILE *f ; 
    f = fopen("estoque.txt", "r");

    int cod1,qnt;
    float price;
    char nome[50];

    while(fscanf(f, "%d;%d;%f;%s\n", &cod1,&qnt,&price,nome)!=EOF)
    {
        if(cod1==cod)
        {
            printf("Codigo\t\t\tQuantidade\t\t\tPreco\t\t\tNome");
            printf("\n\n");
            printf("%d\t\t\t%d\t\t\t%.2f\t\t\t%s",cod,qnt,price,nome);
            time();
            return;
        }
    }

    fclose(f);
    printf("Produto Nao Existe No Estoque !!!");
    time();

    return;
}
