#include <stdlib.h>
#include <stdio.h>

#include "vendas.h"

//funcoes destinadas para o Menu do Projeto

void introducao()   //Apresenta o realizador do Projeto (*Eu*kkkkkkk)
{
    printf("\t\t\tSISTEMA DE ESOQUE E VENDAS\n\n");
    printf("\t\t\tBy LEONARDO\n\n");
}

void opcoes()   //Mostra as Diversas Opcoes do Programa
{
    printf("0. Sair\n");
    printf("1. Vender\n");
    printf("2. Adicionar ao Estoque\n");
    printf("3. Deletar do Estoque\n");
    printf("4. Mostrar Estoque\n");
    printf("5. Mostrar Produto Especifico\n");
    printf("6. Modificar Produto\n\n");
    printf("Opcao: ");
}

void menu() //Menu Principal Do Programa
{
    clean();
    introducao();
    printf("Digite a Operacao Desejada: \n\n");
    opcoes();
}

void casos(int num)    //Funcao que leva para a opcao escolhida
{
    switch(num)
    {
        case 1 :
            vender();
            break;

        case 2 :
            adicionaProduto();
            break;

        case 3 :
            deleteProduto();
            break;

        case 4 :
            mostraEstoque();
            break;

        case 5 :
            mostrarProduto();
            break; 

        case 6 :
            modificar();
            break;
            
        case 0:
            clean();
            exit(0);
    }

    return;
}