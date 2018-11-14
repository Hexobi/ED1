/*
 * biblioteca.c
 *
 *  Created on: 13 de nov de 2018
 *      Author: n226903452
 */
const int MAX_PLACA = 5;
#include "biblioteca.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

void menu() {
	EstruturaPessoa *lista = NULL;
	char menu;
	int submenu;
	do {
		printf("\nDigite qual a opcao desejada");
		printf("\nA-Inserir cliente");
		printf("\nB-Excluir cliente");
		printf("\nC-Relatorios");
		printf("\nD-Finalizar\n");
		scanf("%c", &menu);
		fflush(stdin);
		switch (menu) {
		case 'A':
			cadastroPessoa(&lista);
			break;
		case 'B':
			puts("\nQual Deseja Excluir?");
			puts("\n1- Exclusao de cliente");
			puts("\n2- Exclusao de placa\n");
			scanf("%d", &submenu);
			fflush(stdin);
			switch (submenu) {
			case 1:
				break;
			case 2:
				break;
			default:
				printf("\nInvalido");
				break;
			}
			break;
		case 'C':
			puts("\nQual Deseja Exibir?");
			puts("\n1- Listar todos os clientes");
			puts("\n2- Listar dados do cliente");
			puts("\n3- Listar clientes por contrato\n");
			scanf("%d", &submenu);
			fflush(stdin);
			switch (submenu) {
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			default:
				puts("digite somete uma das opcoes");
				break;
			}
			break;
		case 'D':
			break;
		default:
			printf("\nInvalido");
			break;
		}
	} while (menu != 'D');
}
int verificarData(char data[]) {
	int idade, dia, mes, ano;
	time_t now;
	time(&now);
	struct tm *tm = localtime(&now);
// 01/34/6789
	if (data[2] == '/' && data[5] == '/') {
		//char* tmp = (char*) malloc(4 * sizeof(char));

		dia = concatINT(data, 0, 1); //(char[], INICIO,FIM)

		mes = concatINT(data, 3, 4);

		ano = concatINT(data, 6, 9);

		idade = (tm->tm_year+ 1900) - (ano );

		if (tm->tm_mon < mes) {
			idade--;
		} else if (mes == tm->tm_mon && tm->tm_mday < dia) {
			idade--;
		}
		printf("idade atual %d",idade);
	}
	return idade;
}
int concatINT(char s[], int inicio, int fim) {
	int r = 0;
	int cont = 1;
	int i;
	int total = fim-inicio;
	cont = pow(10,total);
	for (i = inicio; i <= fim; i++) {
		int c = (s[i] - '0'); //converte o char em numero inteiro
		c *= cont;
		r += c;
		cont /= 10;
	}
	return r;
}

void cadastroCarro(EstruturaPessoa **lista) {
	EstruturaCarro *novo = (EstruturaCarro*) malloc(sizeof(EstruturaCarro));
	int x = 0;
	puts("Digite a Placa do carro: ");
	fflush(stdin);
	gets(novo->placa);

	puts("Digite o ano do carro");
	scanf("%d", &novo->ano);
	fflush(stdin);
	puts("Digite o modelo do carro");
	gets(novo->modelo);
	fflush(stdin);

	if ((*lista)->dadosDosCarros == NULL) {
		puts("Lista vazia");
		novo->anterior = NULL;

		x = concatINT(novo->placa, 3, 6);
		x = CODIGO(x)
		;
		novo->codigo = CODIGO(x)
		;

		(*lista)->dadosDosCarros = novo;
		(*lista)->codigo = x;

	} else {

		novo->anterior = (*lista)->dadosDosCarros;
		int tmp = (*lista)->dadosDosCarros->codigo;
		novo->codigo = tmp++;
		(*lista)->dadosDosCarros = novo;
	}

	puts("Carro cadastrado com sucesso");
}

void cadastroPessoa(EstruturaPessoa** lista) {
	EstruturaPessoa *novo = (EstruturaPessoa*) malloc(sizeof(EstruturaPessoa));
	novo->dadosDosCarros = NULL;
	int qtdplaca;
	int idade=0;
	do {
		printf("\nDigite seu nome\n");
		gets(novo->nome);
		if (strcmp(novo->nome, "\0") == 0) {
			puts("\nNome invalido");
		}
	} while (strcmp(novo->nome, "\0") == 0);
	do {
		puts("\nDigite sua data de nascimento DD/MM/AAAA\n");
		gets(novo->dataNasc);
		idade = verificarData(novo->dataNasc);

		if (idade < 18 || idade >= 100) {
			puts("\nidade invalida");
		}
	} while (idade < 18 || idade >= 100);
	do {
		printf("\nQual o tipo do contrato?");
		printf("\nD- Diaria");
		printf("\nP- Parcial");
		printf("\nM- Mensal\n");
		scanf("%c", &novo->contrato);
		if (novo->contrato != 'D' && novo->contrato != 'P'
				&& novo->contrato != 'M') {
			printf("\nTipo de contrato invalido\n");
		}
	} while (novo->contrato != 'D' && novo->contrato != 'P'
			&& novo->contrato != 'M');

	do {
		puts("\nQuantidade de placas?\n");
		scanf("%d", &qtdplaca);
		if (qtdplaca > MAX_PLACA) {
			printf("nao deve ter mais do que %d placas\n", MAX_PLACA);
		}
	} while (qtdplaca > MAX_PLACA);
	int i;
	for (i = 0; i < qtdplaca; i++) {
		cadastroCarro(&novo);
	}
if((*lista)==NULL){
(lista)= &novo;
}else{
novo->proximo = (*lista);
novo->anterior = NULL;

if((*lista)->proximo != NULL){
	(*lista)->proximo->anterior = novo;
}}

puts("Cliente Cadastrado com Sucesso!");
}
EstruturaPessoa* procurarPessoa(EstruturaPessoa* lista,int codigo){
if((lista)== NULL){
	puts("Lista Vazia");
}
	while((lista)->anterior!=NULL){
		if((lista)->codigo == codigo){
			puts("\nNOME: ");puts(lista->nome);
			puts("\nData Nascimento: "); puts(lista->dataNasc);

			return lista;
		}else{
			lista =lista->anterior;
		}
}
return NULL;
}
