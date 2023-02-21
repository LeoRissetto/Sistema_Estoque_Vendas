#ifndef INCLUDE_VENDAS_H
#define INCLUDE_VENDAS_H

//funcoes destinadas a facilitar a elaboracao do codigo

void clean();

void time();

void readline(char **f);

int isIn(int cod);

int quantProd(int cod);

//funcoes destinadas para as operacoes de estoque e venda

    //funcoes destinadas a modificacao de produtos ja existentes

void modificaCod(int cod);

void modificaQnt(int cod);

void modificaPreco(int cod);

void modificaNome(int cod);

void modificar();

    //funcoes destinadas a adicao, remocao e display de estoque 

void adicionaProduto();

void deleteProduto();

void mostraEstoque();

void removeProduto(int cod, int qnt);

void mostrarProduto();

    //funcoes destinadas a area de vendas

void vender();



void notaFiscal(int cod,int qnt);

//funcoes destinadas para o Menu do Projeto

void introducao();

void opcoes();

void menu();

void casos(int num);

#endif