//---------------------------------------------------------------------------------------
// Disciplina  : ALGORITMOS E LÓGICA DE PROGRAMAÇÃO II - 52/2023
// Autor(a)    : Leonardo Patrício da Luz
// Data atual  : 04/07/2023
//---------------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>


typedef struct
    {
        char nome[50];
        char cpf[15];
        int ano_nascimento;
    }ingresso_struct;


ingresso_struct guarda_ingressos[1000];
int contador_ingressos = 0;


void vender_ingresso(){

    ingresso_struct venda_ingresso;

    printf("\n");

    printf("Informe o nome: ");
    gets(venda_ingresso.nome);
    fflush(stdin);

    printf("Informe o cpf: ");
    gets(venda_ingresso.cpf);
    fflush(stdin);
    
    printf("Informe o ano de nascimento: ");
    scanf("%d", &venda_ingresso.ano_nascimento);
    fflush(stdin);

    guarda_ingressos[contador_ingressos] = venda_ingresso;
    contador_ingressos ++;
}


void listar_ingresso(){

    int i;
    
    printf("============Lista de Ingressos============\n");
    for (i = 0; i < contador_ingressos; i++){
        printf("Nome: %s\n", guarda_ingressos[i].nome);
        printf("CPF: %s\n", guarda_ingressos[i].cpf);
        printf("Ano de Nascimento: %d\n", guarda_ingressos[i].ano_nascimento);
        printf("==========================================\n");
    }
}


void validar_ingresso(){
    
    int i;
    char cpf_validacao[15];
    int validou = 0;

    printf("Informe o CPF a ser validado: ");
    gets(cpf_validacao);
    fflush(stdin);
    printf("\n");

    for (i = 0; i < contador_ingressos; i++){
        if(strcmp(guarda_ingressos[i].cpf, cpf_validacao) == 0){
            printf("==========Validação de Ingressos==========\n");
            printf("Ingresso Validado com Sucesso!\n\n");
            printf("Nome: %s\n", guarda_ingressos[i].nome);
            printf("CPF: %s\n", guarda_ingressos[i].cpf);
            printf("Ano de Nascimento: %d\n", guarda_ingressos[i].ano_nascimento);
            printf("==========================================\n");
            validou = 1;
        }

    }
    if (!validou){
        printf("Não foi encontrado nenhum ingresso vinculado a esse cpf!\n");
    }
}

void menu_interface(){

    printf("\n---------INGRESSOS LTDA---------\n");
    printf("\n1 - Vender Ingresso.\n2 - Listar Ingressos Vendidos.\n3 - Validar Ingresso.\n4 - Sair.\n\n");
    printf("--------------------------------\n\n");
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    int menu_opc;

do
{
    menu_interface();

    printf("ESCOLHA UMA OPÇÃO: ");
    scanf("%d", &menu_opc);
    printf("\n");
    fflush(stdin);
    system("cls");

    switch (menu_opc)
    {
    case 1:
        vender_ingresso();
        system("cls");
        continue;
    case 2:
        listar_ingresso();
        system("pause");
        system("cls");
        continue;
    case 3:
        validar_ingresso();
        system("pause");
        system("cls");
        continue;
    case 4:
        printf("Finalizando o Programa...\n");
        break; 
    default:
        printf("Caractere Inválido! Tente Novamente!\n");
        //system("pause");
        //system("cls");
        continue;
    }

} while (menu_opc != 4);

    return 0;
}
