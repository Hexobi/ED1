/*
 * biblioteca.h
 *
 *  Created on: 13 de nov de 2018
 *      Author: Junior
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

#define ERRO_ENTRADA puts("Entrada de dados invalida!\n Digite Novamente\n")
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
	char dataNasc[11];
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


void InterfaceUsuario();
int concatINT(char s[], int inicio, int fim);
EstruturaPessoa* cadastroPessoa(EstruturaPessoa* *lista);
void cadastroCarro(EstruturaPessoa** lista);
EstruturaPessoa* procurarPessoaPorCodigo(EstruturaPessoa* lista,int codigo);
int VerificaSeEhLetra(char c);
int VerificaSeEhNumero(char c);
int consistePlaca(char c[]);
#endif /* BIBLIOTECA_H_ */
