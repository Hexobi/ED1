#include <stdio.h>
#include <string.h>

typedef struct{
  char placa[7];
  int codigo;
  char modelo[30];
  int ano;
}EstruturaCarro;

typedef struct{
 char nome[50];
 int codigo;
 char dataNasc[10];
 char contrato;
 int qtdePlacas;
 EstruturaCarro dadosDosCarros;
}EstruturaPessoa;



void menu();

int main(void) {
  menu();
  return 0;
}

void menu(){
  char menu;
  int submenu;
  do{
  printf("\nDigite qual a opção desejada");
  printf("\nA-Inserir cliente");
  printf("\nB-Excluir cliente");
  printf("\nC-Relatorios");
  printf("\nD-Finalizar");
  scanf("%c", &menu);
  fflush(stdin);
  switch(menu){
    case 'A':
    break;
    case 'B':
    printf("\nQual Deseja Excluir?");
    printf("\n1- Exclusao de cliente");
    printf("\n2- Exclusao de placa");
    scanf("%d", &submenu);
    fflush(stdin);
    switch(submenu){
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
    printf("\nQual Deseja Excluir?");
    printf("\n1- Listar todos os clientes");
    printf("\n2- Listar dados do cliente");
    printf("\n3- Listar clientes por contrato");
    scanf("%d", &submenu);
    fflush(stdin);
    switch(submenu){
      case 1:
      break;
      case 2:
      break;
      case 3:
      break;
      default:
      printf("\nInvalido");
      break;
    }
    break;
    case 'D':
    break;
    default:
    printf("\nInvalido");
    break;
  }
}while(menu != 'D');
}

void cadastro(){
  int idade;
  int qtdplaca;//mudar para uma constante depois
  do{
  printf("\nDigite seu nome");
  gets(EstruturaPessoa->nome);
  if(strlen(EstruturaPessoa->nome)=="\0"){
    printf("\nNome invalido");
  }
  }while(strlen(EstruturaPessoa->nome)=="\0");
  do{
  printf("\nDigite sua data de nascimento DD/MM/AAAA");
  gets(EstruturaPessoa->dataNasc);
//garrei nisso n sei como comparar e a net do trabalho n deixa acessar stackoverflow pra ver como testar oq eu quero mas era fazer o calculo e jogar na variavel idade
if(idade >=18 && idade <=100){
printf("\nidade invalida");
}
  }while(idade >=18 && idade <=100);
do{
  printf("\nQual o tipo do contrato?");
  printf("\nD- Diaria");
  printf("\nP- Parcial");
  printf("\nM- Mensal");
  scanf("%c", EstruturaPessoa->contrato);
if(EstruturaPessoa->contrato != D &&EstruturaPessoa->contrato != PEstruturaPessoa->contrato != M){
printf("\nTipo de contrato invalido");
}
}while(EstruturaPessoa->contrato != D &&EstruturaPessoa->contrato != PEstruturaPessoa->contrato != M)
do{
printf("Quantidade de placas?");
scanf("%d", &qtdplaca);
if(qtdplaca > 5){
printf("não deve ter mais do que 5 placas"); 
}while(qtdplaca >5);


}
