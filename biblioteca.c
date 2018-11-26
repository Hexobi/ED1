const int MAX_PLACA = 5;
#include "biblioteca.h"
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

void interfaceUsuario() {
	EstruturaPessoa* lista = NULL;
	char menu;
	int submenu;
	do {
		printf("\nDigite a opção desejada: ");
		printf("\nA-Inserir cliente");
		printf("\nB-Excluir cliente");
		printf("\nC-Relatórios");
		printf("\nD-Finalizar\n");
		scanf("%c", &menu);
		fflush(stdin);
		menu = toupper(menu);
		switch (menu) {
		case 'A':
			lista = cadastroPessoa(&lista);
			break;
		case 'B':
			puts("\nQue exclusão deseja realizar?");
			puts("\n1- Exclusão de cliente");
			puts("\n2- Exclusão de placa\n");
			scanf("%d", &submenu);
			fflush(stdin);
			switch (submenu) {
			case 1:
				puts("Digite o código do cliente: \n");
				int codigo = 0;
				scanf("%d", &codigo);
				(lista) = procurarPessoaPorCodigo(lista, codigo);
				ExcluirPessoa(&lista);
				break;
			case 2:
				break;
			default:
				printf("\nInvalido");
				break;
			}
			break;

			case 'C':

				puts("\nQual deseja exibir?");
				puts("\n1- Listar todos os clientes");
				puts("\n2- Listar dados do cliente");
				puts("\n3- Listar clientes de acordo com seu contrato\n");
				scanf("%d", &submenu);
				fflush(stdin);

				switch (submenu) {

				case 1:
					//if(lista != NULL){
					imprimirTudo(lista);
					//	}else{
					//		puts("Vazio porra");
					//	}
					break;

				case 2:
					puts("Digite o código do cliente: \n");
					int codigo = 0;
					scanf("%d", &codigo);
					fflush(stdin);
					procurarPessoaPorCodigo(lista, codigo);
					break;

				case 3:

					puts("Digite o tipo de contrato cujos contratantes deseja saber: \n D (diário), P (parcial) ou M (mensal), apenas!");
					char contract;
					scanf("%c", &contract);
					contract = toupper(contract);
					fflush(stdin);

					imprimirPessoaPorContrato(lista, contract);

					break;

				default:
					puts("Digite apenas uma das opções");
					break;
				}
				break;
				case 'D':
					break;
				default:
					printf("\nInválido");
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

		idade = (tm->tm_year + 1900) - (ano);

		if (tm->tm_mon < mes) {
			idade--;
		} else if (mes == tm->tm_mon && tm->tm_mday < dia) {
			idade--;
		}
		printf("Idade atual: %d", idade);
	}
	return idade;
}
int concatINT(char s[], int inicio, int fim) {
	int r = 0;
	int cont = 1;
	int i;
	int total = fim - inicio;
	cont = pow(10, total);
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
	int errado = 1;
	while (errado) {
		puts("Digite a placa de seu automóvel ");
		fflush(stdin);
		gets(novo->placa);
		errado = consistePlaca(novo->placa);
		if (errado) {
			ERRO_ENTRADA;
		}
	}

	do {
		puts("Digite o ano de seu automóvel ");
		gets(novo->ano);
		fflush(stdin);

		int i;
		int year = atoi(novo->ano);


		for(i=0;i<4;i++){

			if(isdigit(novo->ano[i])==0 || year < 1950 || year > 2018){
				errado = 1;

			} else {
				errado = 0;
			}

		}

		if (errado)
			ERRO_ENTRADA;

	} while (errado == 1);

	puts("Digite o modelo de seu automóvel ");
	gets(novo->modelo);
	fflush(stdin);

	if ((*lista)->dadosDosCarros == NULL) {
		puts("Lista vazia");
		novo->anterior = NULL;

		x = concatINT(novo->placa, 3, 6);
		x = CODIGO(x);
		novo->codigo = CODIGO(x);

		(*lista)->dadosDosCarros = novo;
		(*lista)->codigo = x;

	} else {
		novo->anterior = (*lista)->dadosDosCarros;
		int tmp = (*lista)->dadosDosCarros->codigo;
		novo->codigo = ++tmp;
		(*lista)->dadosDosCarros = novo;
	}

	puts("Veículo cadastrado com sucesso");
}

EstruturaPessoa* cadastroPessoa(EstruturaPessoa** lista) {
	EstruturaPessoa *novo = (EstruturaPessoa*) malloc(sizeof(EstruturaPessoa));
	novo->dadosDosCarros = NULL;
	int idade = 0;


	do {
		printf("\nDigite seu nome\n");
		gets(novo->nome);
		if (strcmp(novo->nome, "\0") == 0) {
			puts("\nNome inválido!");
		}
	} while (strcmp(novo->nome, "\0") == 0);

	do {
		puts("\nDigite sua data de nascimento seguindo o formato DD/MM/AAAA\n");
		gets(novo->dataNasc);
		idade = verificarData(novo->dataNasc);

		if (idade < 18 || idade >= 100) {
			puts("\nIdade inálida! Digite novamente.");
		}
	} while (idade < 18 || idade >= 100);
	do {
		printf("\nQual o tipo do contrato?");
		printf("\nD- Diário");
		printf("\nP- Parcial");
		printf("\nM- Mensal\n");
		scanf("%c", &novo->contrato);
		novo->contrato = toupper(novo->contrato);
		if (novo->contrato != 'D' && novo->contrato != 'P'
				&& novo->contrato != 'M') {
			printf("\nTipo de contrato inválido\n");
		}
	} while (novo->contrato != 'D' && novo->contrato != 'P'
			&& novo->contrato != 'M');

	do {
		puts("\nQuantidade de placas?\n");
		scanf("%d", &novo->qtdPlaca);
		fflush(stdin);
		if ((novo->qtdPlaca) > MAX_PLACA || (novo->qtdPlaca) < 1) {
			printf(
					"Não deve ter mais do que %d placas\nPelo menos uma placa deve ser cadastrada!",
					MAX_PLACA);
		}
	} while ((novo->qtdPlaca) > MAX_PLACA || (novo->qtdPlaca) < 1);
	int j;
	for (j = 0; j < (novo->qtdPlaca); j++) {
		cadastroCarro(&novo);
	}
	if ((*lista) == NULL) {
		(lista) = &novo;
		(*lista)->proximo = NULL;
		(*lista)->anterior = NULL;

	} else {

		novo->anterior = (*lista);
		novo->proximo = NULL;

		(*lista)->proximo = novo;
		(*lista) = (*lista)->proximo;
	}

	puts("Cliente cadastrado com Sucesso!");
	return *lista;
}
void ExcluirPessoa(EstruturaPessoa** pessoa) {
	if ((*pessoa)->anterior != NULL) {
		(*pessoa)->anterior->proximo = (*pessoa)->proximo; // indica que o proximo do item excluido sera
	}
	//o proximo do item anterior a ele, tomando seu lugar
	if ((*pessoa)->anterior != NULL) {
		(*pessoa)->proximo		//indica que o item anterior ao excluido sera
				->anterior = (*pessoa)->anterior; // o anterior ao proximo item dele, tomando seu lugar
	}
	//ficando sem referencia, o item nao pode ser mais encontrado na lista
	if ((*pessoa)->anterior != NULL) {
		(*pessoa) = (*pessoa)->anterior;
	} else
		(*pessoa) = NULL;
}
void imprimeCarro(EstruturaCarro* carro) {
	if (carro != NULL) {
		printf("Placa: %s\n", carro->placa);
		printf("Código : %d\n", carro->codigo);
		printf("Ano: %s \n", carro->ano);
		printf("Modelo: %s\n", carro->modelo);
		imprimeCarro(carro->anterior); // volta o ponteiro para os dados do carro anterior

	}
}
void imprimirTudo(EstruturaPessoa* lista) {

	if (lista != NULL) {

		printf("\n\nNome: %s\n", lista->nome);
		printf("\nCódigo : %d", lista->codigo);
		printf("\nData de nascimento: %s", lista->dataNasc);
		printf("\nContrato: %c", lista->contrato);
		printf("\nQuantidade de placas: %d", lista->qtdPlaca);
		EstruturaCarro* tmp = lista->dadosDosCarros;
		printf("\n---------------");
		printf("\n----CARROS-----\n");
		imprimeCarro(tmp);
		free(tmp);
		printf("----------------------\n");
		printf("----FIM DOS CARROS----\n");
		if (lista->anterior != NULL) {
			imprimirTudo(lista->anterior);
		}
	} else {
		puts("Lista vazia !");
		return;
	}
}

void imprimirPessoaPorContrato (EstruturaPessoa* lista, char contract) {

	if ((lista) == NULL){
		printf("\nLista vazia.\n");
		return;

	}

	while(lista->anterior != NULL) {

		lista = lista->anterior;

	}

	while(lista != NULL) {

		if(lista->contrato == contract) {

			printf("\n\n Nome: %s\n", lista->nome);
			printf("\nCódigo : %d", lista->codigo);
			printf("\nData de Nascimento: %s", lista->dataNasc);
			printf("\nContrato: %c", lista->contrato);
			printf("\nQuantidade de placas: %d ", lista->qtdPlaca);

			lista = lista->proximo;

		} else {

			lista = lista->proximo;
		}
	}


}

EstruturaPessoa* procurarPessoaPorCodigo(EstruturaPessoa* lista, int codigo) {
	if ((lista) == NULL) {
		puts("Lista Vazia");
		return NULL;

	} else if (lista->codigo == codigo) {
		puts("\n Nome: ");
		puts(lista->nome);
		puts("\nData de nascimento: ");
		puts(lista->dataNasc);
		puts("\n Tipo de contrato: ");
		printf("%c ", lista->contrato);
		puts("\n Quantidade de placas: ");
		printf("%d ", lista->qtdPlaca);
		return lista;

	} else {
		return procurarPessoaPorCodigo(lista->anterior, codigo);
	}

}


int consistePlaca(char placa[]) {
	int i = 0;
	for (i = 0; i < 3; i++) {
		if (!isalpha(placa[i])) {
			return 1;
		}
	}
	for (i = 3; i < 7; i++) {
		if (!isdigit(placa[i])) {
			return 1;
		}
	}
	return 0;
}
//int VerificaSeEhNumero(char c) {
//	if ((c <= 57 && c >= 48)) {
//		return 1;
//	} else
//		return 0;
//}
//
//int VerificaSeEhLetra(char c) {
//	if ((c <= 90 && c >= 65) || (c >= 97 && c <= 122)) {
//		return 1;
//	} else
//		return 0;
//}
