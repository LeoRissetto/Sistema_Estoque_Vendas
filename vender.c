#include <stdlib.h>
#include <stdio.h>

#include "vendas.h"
    
//funcoes destinadas a area de vendas

void vender()
{
    int num1=1;
    int times=0;
    int cod,codtemp,qnt;
    float price;
    float valor=0;

    remove("notaFiscal.txt");

    while(num1==1)
    {
        clean();

        printf("Digite o Codigo do Produto: ");
        scanf("%d",&cod);

        if(isIn(cod)==0)
        {
            clean();
            printf("Produto Nao Existe no Estoque!!\n\n");
            time();
        }

        else
        {
            printf("\n\nDigite a Quantidade de Itens do Produto: ");
            scanf("%d",&qnt);
            
            if(qnt>quantProd(cod))
            {
                clean();
                printf("Estoque Insuficiente para a Venda!!\n\n");
                time();
            }
            else
            {
                removeProduto(cod,qnt);

                FILE *f;
                f=fopen("estoque.txt","r");

                while(fscanf(f,"%d;%*d;%f;%*s\n",&codtemp,&price)!=EOF)
                {
                    if(codtemp==cod)
                    {
                        valor+=qnt*price;
                    }
                }
                fclose(f);
                times++;
            
                if(times==1)
                {
                    criaNota();
                }   
                notaFiscal(cod,qnt);
            }
        }
        
        clean();
        printf("Para Continuar Digite 1, Ou Pressione Outro Numero Para Finalizar: ");
        scanf("%d",&num1);
    }

    FILE *f1;
    f1=fopen("notaFiscal.txt","a");
    fprintf(f1,"\n\nO Valor Total Da Compra Foi De %.2f", valor);
    fclose(f1);
    
    clean();
    printf("O Valor Total Da Compra Foi De %.2f", valor);

    time();
    return;
}

void criaNota()
{
    FILE *f1;
    f1=fopen("notaFiscal.txt","w");

    fprintf(f1,"Codigo\t\t\tQuantidade\t\t\tPreco\t\t\tNome\t\t\tValor Multiplicado\n\n");

    fclose(f1);
    
    return;
}

void notaFiscal(int cod, int qnt)
{
    int codtemp;
    char nome[50];
    float price;
    float valorItem;

    FILE *f;
    FILE *f1;
    f=fopen("estoque.txt","r");
    f1=fopen("notaFiscal.txt","a");

    while(fscanf(f, "%d;%*d;%f;%s\n",&codtemp,&price,nome)!=EOF)
    {
        if(codtemp==cod)
        {
            valorItem=qnt*price;
            break;
        }
    }

    fprintf(f1,"%d\t\t\t\t%d\t\t\t\t%.2f\t\t\t\t%s\t\t\t\t%.2f\n",cod,qnt,price,nome,valorItem);

    fclose(f);
    fclose(f1);
    return;
}