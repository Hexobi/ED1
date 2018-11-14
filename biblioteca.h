/*
 * biblioteca.h
 *
 *  Created on: 13 de nov de 2018
 *      Author: Junior
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

#define CODIGO(x) (x*100+1)
typedef struct CARRO EstruturaCarro;
typedef struct PESSOA EstruturaPessoa;
int verificarData(char data[]);
struct CARRO {
	char placa[7];
	int codigo;
	char modelo[50];
	int ano;
	EstruturaCarro *anterior;
};

struct PESSOA {
	char nome[50];
	int codigo;
	char dataNasc[10];
	char contrato;
	int qtdPlaca;
	EstruturaCarro *dadosDosCarros;

	EstruturaPessoa *proximo;
	EstruturaPessoa *anterior;
};

typedef struct INFO_LISTA {
	EstruturaPessoa *primeiro;
	EstruturaPessoa *ultimo;
	int tamanho;
}EstruturaLista;


void menu();
int concatINT(char s[], int inicio, int fim);
void cadastroPessoa(EstruturaPessoa* *lista);
void cadastroCarro(EstruturaPessoa** lista);
EstruturaPessoa* procurarPessoa(EstruturaPessoa* lista,int codigo);

#endif /* BIBLIOTECA_H_ */
