#include <stdlib.h>
#include <stdio.h>

#include "vendas.h"

//funcoes destinadas para as operacoes de estoque e venda

    //funcoes destinadas a modificacao de produtos ja existentes

void modificaCod(int cod)  //altera o codigo de um produto ja existente
{
    clean();

    int cod1;

    printf("Digite o Novo Codigo: ");
    scanf("%d", &cod1);

    if(isIn(cod1)==1)
    {
        printf("\n\nEste Codigo Ja Esta Sendo Utilizado, Favor Escolher Um Diferente!!!\n\n");
    }

    else if(isIn(cod1)==0)
    {

        int codtemp;
        int qnt;
        float price;
        char nome[50];

        FILE *f;
        FILE *f1;

        f=fopen("estoque.txt", "r");
        f1=fopen("temp.txt", "w");

        while(fscanf(f, "%d;%d;%f;%s\n", &codtemp,&qnt,&price,nome)!=EOF)
        {
            if(codtemp==cod)
            {
                fprintf(f1, "%d;%d;%.2f;%s\n",cod1,qnt,price,nome);
            }
            else
            {
                fprintf(f1, "%d;%d;%.2f;%s\n",codtemp,qnt,price,nome);
            }
        }

        rename("estoque.txt", "trash.txt");
        rename("temp.txt","estoque.txt");

        remove("trash.txt");
        fclose(f1);

        clean();
        printf("Codigo Modificado com Sucesso!!!\n\n");
    }

    time();
    return;
}

void modificaQnt(int cod)   //modifica a quantidade de um produto ja existente
{
    clean();

    int qnt1;

    printf("Digite a Nova Quantidade: ");
    scanf("%d",&qnt1);

    int codtemp;
    int qnt;
    float price;
    char nome[50];

    FILE *f;
    FILE *f1;

    f=fopen("estoque.txt", "r");
    f1=fopen("temp.txt", "w");

    while(fscanf(f, "%d;%d;%f;%s\n", &codtemp,&qnt,&price,nome)!=EOF)
    {
        if(codtemp==cod)
        {
            fprintf(f1, "%d;%d;%.2f;%s\n",codtemp,qnt1,price,nome);
        }
        else
        {
            fprintf(f1, "%d;%d;%.2f;%s\n",codtemp,qnt,price,nome);
        }
    }

    rename("estoque.txt", "trash.txt");
    rename("temp.txt","estoque.txt");

    remove("trash.txt");
    fclose(f1);

    clean();
    printf("Quantidade Modificada com Sucesso!!!\n\n");

    time();
    return;
}

void modificaPreco(int cod)   //modifica o preco de um produto ja existente
{
   clean();

    float price1;

    printf("Digite o Novo Preco: ");
    scanf("%f",&price1);

    int codtemp;
    int qnt;
    float price;
    char nome[50];

    FILE *f;
    FILE *f1;

    f=fopen("estoque.txt", "r");
    f1=fopen("temp.txt", "w");

    while(fscanf(f, "%d;%d;%f;%s\n", &codtemp,&qnt,&price,nome)!=EOF)
    {
        if(codtemp==cod)
        {
            fprintf(f1, "%d;%d;%.2f;%s\n",codtemp,qnt,price1,nome);
        }
        else
        {
            fprintf(f1, "%d;%d;%.2f;%s\n",codtemp,qnt,price,nome);
        }
    }

    rename("estoque.txt", "trash.txt");
    rename("temp.txt","estoque.txt");

    remove("trash.txt");
    fclose(f1);

    clean();
    printf("Preco Modificado com Sucesso!!!\n\n");

    time();
    return;
}

void modificaNome(int cod)    //altera o nome de um produto ja existente
{
    clean();

    char *nome1;

    printf("Digite o Novo Nome do produto: ");
    getchar();
    readline(&nome1);

    int codtemp;
    int qnt;
    float price;
    char nome[50];

    FILE *f;
    FILE *f1;

    f=fopen("estoque.txt", "r");
    f1=fopen("temp.txt", "w");

    while(fscanf(f, "%d;%d;%f;%s\n", &codtemp,&qnt,&price,nome)!=EOF)
    {
        if(codtemp==cod)
        {
            fprintf(f1, "%d;%d;%.2f;%s\n",codtemp,qnt,price,nome1);
        }
        else
        {
            fprintf(f1, "%d;%d;%.2f;%s\n",codtemp,qnt,price,nome);
        }
    }

    rename("estoque.txt", "trash.txt");
    rename("temp.txt","estoque.txt");

    remove("trash.txt");
    fclose(f1);

    clean();
    printf("Nome Modificado com Sucesso!!!\n\n");

    time();
    return;
}

void modificar()    //area de modificar as propriedades de um produto
{
    clean();

    int cod;

    printf("Digite o codigo do produto: ");
    scanf("%d", &cod);

    if(isIn(cod)==0)
    {
        clean();
        printf("Produto Nao Existe no Estoque!!\n\n");
        time();
    }

    else if(isIn(cod)==1)
    {
        int num1;

        clean();

        printf("Selecione o Que Deve Ser Alterado:\n\n\n");
        printf("1- Codigo\n\n2- Quantidade\n\n3-Preco\n\n4-Nome\n\n");
        scanf("%d",&num1);

        switch(num1)
        { 
            case 1:
                modificaCod(cod);
                break;

            case 2:
                modificaQnt(cod);
                break;

            case 3:
                modificaPreco(cod);
                break;

            case 4:
                modificaNome(cod);
                break;
        }
    }
    
    return;
}