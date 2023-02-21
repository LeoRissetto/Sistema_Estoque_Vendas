#include <stdlib.h>
#include <stdio.h>

#include "vendas.h"

//funcoes destinadas a facilitar a elaboracao do codigo

void clean() //limpar o terminal
{
    system("clear");
}

void time() //faz com que os textos permanecam na tela por um tempo determinado
{
    char *temp;
    printf("\n\nPressione 'Enter' Para Retornar ao Menu: ");
    getchar();
    readline(&temp);
}

void readline(char **f) //ler strings de tamanho variavel
{
    int i;
    for(i =0;1;i++)
    {    
        if(i)
            *f = (char*)realloc((*f),i+1);
        else
            *f = (char*)malloc(i+1);
        (*f)[i]=getchar();
        if((*f)[i]=='\n' )
        {
            (*f)[i]= '\0';
            break;
        }
    }   
    return;
}

int isIn(int cod) //verificar se o produto existe no estoque
{
    FILE *f ; 
    f = fopen("estoque.txt", "a+");

    int cod1;

    while(fscanf(f, "%d;%*d;%*f;%*s\n", &cod1)!=EOF)
    {
        if(cod1==cod)
        {
            return 1;
        }
    }

    fclose(f);

    return 0;
}

int quantProd(int cod)
{
    int codtemp,qnt;
    
    FILE *f ; 
    f = fopen("estoque.txt", "a+");

    while(fscanf(f, "%d;%d;%*f;%*s\n", &codtemp,&qnt)!=EOF)
    {
        if(codtemp==cod)
        {
            return qnt;
        }
    }
    
    fclose(f);
}
