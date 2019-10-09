/* DESCRI��O DO PROGRAMA: ESTE PROGRAMA REALIZA UM PROCESSO SIMPLIFICADO DE MATR�CULAS
                          EM UMA FACULDADE, N�O ARMAZENANDO OS DADOS PERMANENTEMENTE. E
                          A INSER��O DE TODOS OS DADOS E REQUISITOS � REALIZADA PELO
                          TECLADO.

            INSTITUI��O: PONTIF�CIA UNIVERSIDADE CAT�LICA DE CAMPINAS
            NOME DO ALUNO: MURILO DE PAULA ARAUJO
            RA: 17747775                       DATA DE ENTREGA: 13/03/2019
            PROFESSORA: DANIELE CRISTINA UCHOA MAIA RODRIGUES
            CURSO: ENGENHARIA DA COMPUTA��O     PER�ODO: 3� SEMESTRE
            DISCIPLINA CURRICULAR: PARADIGMAS DE PROGRAMA��O A

                    TRABALHO PR�TICO - "MATR�CULAS EM UMA FACULDADE"
*/

//################################# BIBLIOTECAS #################################
#include <stdio.h>    //"Cabe�alho Padr�o de (Entrada/Sa�da)"
#include <stdlib.h>   //"Cabe�alho da Biblioteca de Prop�sito Geral Padr�o"
#include <string.h>   //"Biblioteca com v�rias fun��es Para Manipular Strings"
#include <conio.h>    //"Utilizada a Fun��o "Getche()" da Biblioteca"
#include <windows.h>  //"Utilizada Para Usar a Fun��o "Sleep","Dormir" por Alguns Milissegundos e Muda de Cor"
#include <ctype.h>     //"Fun��es Adicionais Para Usar com Caracteres"
//###############################################################################



//################################### DEFINES ###################################
#define Maximo_Disciplinas 30
#define Maximo_Alunos 15
#define Maximo_Professores 15

#define ESC 27
#define ENTER 13

#define Cor_Das_Grades 9 //9  ou 1
#define Verde 10
#define Vermelho 12  //12 ou 4
#define Branco 15
#define Amarelo 14
//###############################################################################



//################################## STRUCT's ###################################

////####### STRUCT PARA ARMAZENAR OS RAS E NOMES DOS ALUNOS CADASTRADOS #########
typedef struct
{
    int RA;
    char Nomes[100];
} Alunos;
//###############################################################################


////### STRUCT PARA ARMAZENAR OS C�DIGOS E NOMES DAS DISCIPLINAS CADASTRADAS ####
typedef struct
{
    char Codigo[100];
    char Nome[100];
} Disciplinas;
//###############################################################################

//// STRUCT PARA ARMAZENAR OS C�DIGOS E NOMES DAS DISCIPLINAS CADASTRADAS INDEPENDENTES DAS TURMAS
typedef struct
{
    char Codigo2[100];
    char Nome2[100];
} Disciplinas_Sem_Turma;
//###############################################################################


////##### STRUCT PARA ARMAZENAR OS RPS E NOMES DOS PROFESSORES CADASTRADOS ######
typedef struct
{
    int RP;
    char Nome[100];
} Professores;
//###############################################################################


////###### STRUCT PARA REALIZAR OS PROCEDIMENTOS DE MATR�CULAS ACAD�MICAS #######
typedef struct
{
    int Alunos[100];      //Maximo de alunos 15
    int Professores;
} Matriculas;
//###############################################################################


//################## PROT�TIPO DAS FUN��ES UTILIZADAS NA MAIN ###################

// FUN��O PARA "SETAR" TODOS OS VALORES DA STRUCT MATRICULAS COMO (-1) E SETAR OS VALORES INICIAIS DAS VARI�VEIS
void Padronizacao_Inicial (Matriculas Tabela[], int *N_Alunos, int *N_Disciplinas, int *N_Professores, int *Verificar, int *Escolha, int *inicio, int *x);

// FUN��O PARA MUDAR A COR DOS CARACT�RES IMPRESSOS
void Muda_Cor (int cor);

// FUN��O PARA CADASTRAR OS ALUNOS NO SISTEMA
void Cadastrar_Alunos (Alunos Tabela[], int *N);

// FUN��O PARA CADASTRAR AS DISCIPLINAS NO SISTEMA
void Cadastrar_Disciplinas (Disciplinas *Tabela, int *N);

// FUN��O PARA CADASTRAR OS PROFESSORES NO SISTEMA
void Cadastrar_Professores (Professores Tabela[], int *N);

// FUN��O PARA IMPRIMIR A TELA INICIAL
int Imprime_Tela_Inicial ();

// FUN��O PARA IMPRIMIR A TELA DO MENU PRINCIPAL
int Imprime_MENU_Principal ();

// FUN��O PARA IMPRIMIR A LISTA DE TODOS OS ALUNOS CADASTRADOS SEM VERIFICA��O
void Imprime_Alunos_Cadastrados (Alunos Tabela[], int N);

// FUN��O PARA IMPRIMIR A LISTA DE TODOS OS ALUNOS CADASTRADOS SEM VERIFICA��O
void Imprime_Lista_Alunos (Alunos Tabela[], int N);

// FUN��O PARA IMPRIMIR A LISTA DE TODAS AS DISCIPLINAS CADASTRADAS COM VERIFICA��O
void Imprime_Disciplinas_Cadastradas (Disciplinas Tabela[], int N);

// FUN��O PARA IMPRIMIR A LISTA DE TODAS AS DISCIPLINAS CADASTRADAS SEM VERIFICA��O
void Imprime_lista_Disciplinas (Disciplinas Tabela[], int N);

// FUN��O PARA IMPRIMIR A LISTA DE TODAS AS DISCIPLINAS CADASTRADAS SEM VERIFICA��O
void Imprime_lista_Disciplinas_Independente_da_Turma (Disciplinas TAB_DIS[], Disciplinas_Sem_Turma Tabela[], int N);

// FUN��O PARA IMPRIMIR A LISTA DE TODOS OS PROFESSORES CADASTRADOS COM VERIFICA��O
void Imprime_Professores_Cadastrados (Professores Tabela[], int N);

// FUN��O PARA IMPRIMIR A LISTA DE TODOS OS PROFESSORES CADASTRADOS SEM VERIFICA��O
void Imprime_Lista_Professores (Professores Tabela[], int N);

// FUN��O PARA REALIZAR OS PROCEDIMENTOS DE MATRICULAS DOS ALUNOS NAS DEVIDAS DISCIPLINAS
void Matricular_Alunos (Alunos TAB_AL[], Disciplinas TAB_DIS[], Matriculas Tabela[], int N_AL, int N_DIS);

// FUN��O PARA REALIZAR OS PROCEDIMENTOS DE CANCELAR A MATRICULA DOS ALUNOS NAS DEVIDAS DISCIPLINAS
void Desmatricular_Alunos (Alunos TAB_AL[], Disciplinas TAB_DIS[], Matriculas Tabela[], int N_AL, int N_DIS);

// FUN��O PARA IMPRIMIR A LISTA DE DISCIPLINAS DE UM ALUNO
void Imprimir_Lista_Disciplinas_De_Aluno(Matriculas Tabela[], Alunos TAB_AL[], Disciplinas TAB_DIS[], int N_AL, int N_DIS);

// FUN��O PARA IMPRIMIR A LISTA DE ALUNOS EM UMA DISCIPLINA E TURMA
void Imprimir_Lista_Alunos_De_Disciplina_Turma(Matriculas Tabela[], Alunos TAB_AL[], Disciplinas TAB_DIS[], int N_AL, int N_DIS);

// FUN��O PARA IMPRIMIR A LISTA DE ALUNOS EM UMA DISCIPLINA INDEPENDENTE DA TURMA
void Imprimir_Lista_Alunos_De_Disciplina(Matriculas Tabela[], Alunos TAB_AL[], Disciplinas TAB_DIS[], int N_AL, int N_DIS, Disciplinas_Sem_Turma TAB_DIS_S_TURMA[]);

// FUN��O PARA REALIZAR OS PROCEDIMENTOS DE VINCULA��O DOS PROFESSORES NAS DEVIDAS DISCIPLINAS
void Vincular_Professores (Professores TAB_PROF[], Disciplinas TAB_DIS[], Matriculas Tabela[], int N_PROF, int N_DIS);

// FUN��O PARA REALIZAR OS PROCEDIMENTOS DE DESVINCULA��O DOS PROFESSORES NAS DEVIDAS DISCIPLINAS
void Desvincular_Professores (Professores TAB_PROF[], Disciplinas TAB_DIS[], Matriculas Tabela[], int N_PROF, int N_DIS);

//########### FUN��O PARA IMPRIMIR A LISTA DE DISCIPLINAS DE UM PROFESSOR ###########
void Imprimir_Lista_Disciplinas_De_Professor (Matriculas Tabela[], Professores TAB_PROF[], Disciplinas TAB_DIS[], int N_PROF, int N_DIS);

// FUN��O PARA IMPRIMIR A LISTA DE PROFESSORES EM UMA DISCIPLINA INDEPENDENTE DA TURMA
void Imprimir_Lista_Professores_De_Disciplina(Matriculas Tabela[], Professores TAB_PROF[], Disciplinas TAB_DIS[], int N_PROF, int N_DIS, Disciplinas_Sem_Turma TAB_DIS_S_TURMA[]);


// FUN��O PARA SAIR DO PROGRAMA
void Sair_Programa ();
//###############################################################################



//#################################### MAIN #####################################
int main ()
{
    Alunos Cadastramento_AL[100];
    Disciplinas Cadastramento_DIS[100];
    Disciplinas_Sem_Turma Impressao_Sem_Turmas[100];
    Professores Cadastramento_PROF[100];
    Matriculas Matriculados[100];

    int N_Alunos;
    int N_Disciplinas;
    int N_Professores;
    int Verificar;
    int Escolha;
    int inicio;
    int x;

    Padronizacao_Inicial (Matriculados, &N_Alunos, &N_Disciplinas, &N_Professores, &Verificar, &Escolha, &inicio, &x);

    while(x==0)
    {
        if(inicio == 0 || Escolha == 0)
        {
            inicio = -1;
            Verificar = Imprime_Tela_Inicial();
        }

        if(Verificar == 13)
        {
            Escolha = Imprime_MENU_Principal();

            switch(Escolha)
            {
            case 0:
                Escolha = 0;
                break;

            case 1:
                Cadastrar_Alunos(Cadastramento_AL, &N_Alunos);
                break;

            case 2:
                Cadastrar_Disciplinas(Cadastramento_DIS, &N_Disciplinas);
                break;

            case 3:
                Cadastrar_Professores(Cadastramento_PROF, &N_Professores);
                break;

            case 4:
                Matricular_Alunos (Cadastramento_AL, Cadastramento_DIS, Matriculados, N_Alunos, N_Disciplinas);
                break;

            case 5:
                Desmatricular_Alunos(Cadastramento_AL, Cadastramento_DIS, Matriculados, N_Alunos, N_Disciplinas);
                break;

            case 6:
                Vincular_Professores (Cadastramento_PROF, Cadastramento_DIS, Matriculados, N_Professores, N_Disciplinas);
                break;

            case 7:
                Desvincular_Professores (Cadastramento_PROF, Cadastramento_DIS, Matriculados, N_Professores, N_Disciplinas);
                break;

            case 8:
                Imprime_Alunos_Cadastrados(Cadastramento_AL, N_Alunos);
                break;

            case 9:
                Imprime_Disciplinas_Cadastradas(Cadastramento_DIS, N_Disciplinas);
                break;

            case 10:
                Imprime_Professores_Cadastrados(Cadastramento_PROF, N_Professores);
                break;

            case 11:
                Imprimir_Lista_Disciplinas_De_Aluno(Matriculados, Cadastramento_AL, Cadastramento_DIS, N_Alunos, N_Disciplinas);
                break;

            case 12:
                Imprimir_Lista_Alunos_De_Disciplina_Turma(Matriculados, Cadastramento_AL, Cadastramento_DIS, N_Alunos, N_Disciplinas);
                break;

            case 13:
                Imprimir_Lista_Alunos_De_Disciplina(Matriculados, Cadastramento_AL, Cadastramento_DIS, N_Alunos, N_Disciplinas, Impressao_Sem_Turmas);
                break;

            case 14:
                //########### FUN��O PARA IMPRIMIR A LISTA DE DISCIPLINAS DE UM PROFESSOR ###########
                Imprimir_Lista_Disciplinas_De_Professor (Matriculados, Cadastramento_PROF, Cadastramento_DIS, N_Professores, N_Disciplinas);
                break;

            case 15:
                Imprimir_Lista_Professores_De_Disciplina(Matriculados, Cadastramento_PROF, Cadastramento_DIS, N_Professores, N_Disciplinas, Impressao_Sem_Turmas);
                break;
            }
        }

        if(Verificar == 27)
            x=1;
    }

    Sair_Programa();
    return 0;
}
//###############################################################################

// FUN��O PARA "SETAR" TODOS OS VALORES DA STRUCT MATRICULAS COMO (-1) E SETAR OS VALORES INICIAIS DAS VARI�VEIS
void Padronizacao_Inicial (Matriculas Tabela[], int *N_Alunos, int *N_Disciplinas, int *N_Professores, int *Verificar, int *Escolha, int *inicio, int *x) // SETAR VALORES INICIAIS DA STRUCT E VARIAVEIS
{
    int i;
    int j;

    *N_Alunos=0;
    *N_Disciplinas=0;
    *N_Professores=0;
    *inicio=0;
    *x=0;
    *Verificar = -1;
    *Escolha = -1;

    for (i = 0; i < 30; i++)
    {
        for (j = 0; j < 15; j++)
        {
            Tabela[i].Alunos[j] = (-1);
        }

        Tabela[i].Professores = (-1);
    }
}
//###############################################################################

//############## FUN��O PARA MUDAR A COR DOS CAR�CTERES IMPRESSOS ###############
void Muda_Cor (int cor)
{

    /*
    0 = Preto		8 = Cinza
    1 = Azul		9 = Azul Claro
    2 = Verde		10 = Verde Claro
    3 = Verde-Agua	11= Verde-Agua Claro
    4 = Vermelho	12 = Vermelho Claro
    5 = Roxo		13 = Lilas
    6 = Amarelo		14 = Amarelo Claro
    7 = Branco		15 = Branco Brilhante
    */
    HANDLE Saida;
    Saida = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(Saida,cor);
}
//###############################################################################


//################# FUN��O PARA CADASTRAR OS ALUNOS NO SISTEMA ##################
void Cadastrar_Alunos (Alunos Tabela[], int *N) // REQUISITO 1
{
    int i;
    int j;
    int Aux;
    int Aux2;
    int mult;
    int x;
    int Analise;
    int Tamanho;
    int Verificar;
    int Saida;
    int teste;

    char Vet[100];

    Verificar = 13;
    i=*N;
    Saida=0;
    teste=0;

    while(Verificar == 13 && i < Maximo_Alunos && Saida == 0)
    {
        do
        {
            Aux = 0;
            Aux2=0;
            Tamanho=0;
            mult = 1;
            x=0;
            Analise=0;
            Saida=0;
            teste=0;

            system("cls");

            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf(" REALIZANDO O CADASTRAMENTO DE UM ALUNO NO SISTEMA....");

            Muda_Cor(Cor_Das_Grades);
            printf(" \263\n \300\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");
            printf("\n\n");

            Muda_Cor(Verde);
            printf("  Digite o RA do Aluno de no maximo 8 numeros ou digite");
            printf("\n  <S> ou <s> para retornar ao menu, e pressione ENTER: ");
            Muda_Cor(Branco);
            scanf("%[^\n]", Vet);
            fflush(stdin);

            if(Vet[0] == 'S' ||  Vet[0] == 's')
            {
                Saida=1;
                Tabela[i].RA = 0;
                Analise = 0;
            }

            if(Saida != 1)
            {

                Tamanho = strlen(Vet);
                x = (Tamanho-1);

                for(j=0; j<Tamanho; j++)
                {
                    if(Vet[j] < 48 || Vet[j] > 57)
                    {
                        Analise = 1;
                    }
                    Vet[j] = (Vet[j]-48);
                }

                if(Analise == 0)
                {
                    for(j=0; j<Tamanho; j++)
                    {
                        Aux = Vet[x]*mult;
                        Aux2 = (Aux2+Aux);
                        x=(x-1);
                        mult = mult*10;
                    }

                    Tabela[i].RA = Aux2;

                    if(i!=0)
                    {
                        for(j=0; j<i; j++)
                        {
                            if(Tabela[i].RA == Tabela[j].RA)
                            {
                                teste=1;
                            }
                        }
                    }

                    if(teste==1)
                    {
                        Muda_Cor(Cor_Das_Grades);
                        printf("\n \332\304\304");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n \263");

                        Muda_Cor(Vermelho);
                        printf(" ERRO!!! ESSE RA JA ESTA CADASTRADO NO SISTEMA ACADEMICO!");
                        Analise = 1;
                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n \300\304\304");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");
                        Sleep(3000);

                    }
                }

                if(Tabela[i].RA == 0)
                    Analise = 1;
            }

        }
        while((Tabela[i].RA) < 0 || (Tabela[i].RA) > 99999999 || Analise == 1);

        if(Saida != 1)
        {

            do
            {
                system("cls");

                Analise=0;

                Muda_Cor(Cor_Das_Grades);
                printf("\n \332\304\304\304\304\304\304\304");

                for(j=0; j<6; j++)
                    printf("\304\304\304\304\304\304\304\304");

                printf("\277\n \263");

                Muda_Cor(Vermelho);
                printf(" REALIZANDO O CADASTRAMENTO DE UM ALUNO NO SISTEMA....");
                Muda_Cor(Cor_Das_Grades);
                printf(" \263\n \300\304\304\304\304\304\304\304");

                for(j=0; j<6; j++)
                    printf("\304\304\304\304\304\304\304\304");

                printf("\331");
                printf("\n\n");

                Tamanho = 0;
                Muda_Cor(Verde);

                fflush(stdin);
                printf("  Digite o nome do Aluno <50 caracteres no maximo>: ");
                Muda_Cor(Branco);
                scanf("%[^\n]", Tabela[i].Nomes);
                fflush(stdin);

                Tamanho = strlen(Tabela[i].Nomes);

                if(Tamanho <=0 || Tamanho > 50)
                    Analise=1;

                if(Analise == 0)
                {
                    for(j=0; j<Tamanho; j++)
                    {
                        if(Tabela[i].Nomes[j] < 65 && Tabela[i].Nomes[j] > 32)
                            Analise = 1;

                        if(Tabela[i].Nomes[j] < 32)
                            Analise = 1;

                        if(Tabela[i].Nomes[j] > 90 && Tabela[i].Nomes[j] < 97)
                            Analise = 1;

                        if(Tabela[i].Nomes[j] > 122)
                            Analise = 1;
                    }
                }
            }
            while(Tamanho == 0 || Tamanho > 50 || Analise == 1);

            for(j=0; j<Tamanho; j++)
            {
                Tabela[i].Nomes[j] = toupper(Tabela[i].Nomes[j]);
            }

            i=(i+1);
            *N=i;

            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");
            Muda_Cor(Vermelho);
            printf(" REALIZANDO O CADASTRAMENTO DE UM ALUNO NO SISTEMA....");
            Muda_Cor(Cor_Das_Grades);
            printf(" \263\n \300\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331\n\n\n \332\304\304\304\304\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");
            Muda_Cor(Vermelho);
            printf("     ALUNO CADASTRADO COM SUCESSO NO SISTEMA ACADEMICO!!!!");
            Muda_Cor(Cor_Das_Grades);
            printf("\t \263\n \303\304\304\304\304\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\264 \n \263\t\t\t\t\t\t\t\t \263\n \303\304\304\304\304\304\304\304\304\304\304\302");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\304\304\304\304\264\n \263");

            Muda_Cor(Vermelho);
            printf("    RA    ");

            Muda_Cor(Cor_Das_Grades);
            printf("\263");

            Muda_Cor(Vermelho);
            printf("\t\t    NOME DO ALUNO");

            Muda_Cor(Cor_Das_Grades);
            printf("\t\t\t \263 \n \303\304\304\304\304\304\304\304\304\304\304\305");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\304\304\304\304\264\n \263");

            Muda_Cor(Branco);
            printf(" %-8d", Tabela[(i-1)].RA);

            Muda_Cor(Cor_Das_Grades);
            printf(" \263");

            Muda_Cor(Branco);
            printf(" %-50s", Tabela[(i-1)].Nomes);

            Muda_Cor(Cor_Das_Grades);
            printf(" \263\n \300\304\304\304\304\304\304\304\304\304\304\301");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\304\304\304\304\331");

            Sleep(2000);

        }
    }

    if (i>=Maximo_Alunos)
    {
        system("cls");
        Muda_Cor(Cor_Das_Grades);
        printf("\n \332\304\304\304\304\304");

        for(j=0; j<8; j++)
            printf("\304\304\304\304\304\304\304\304");

        printf("\277\n \263");

        Muda_Cor(Vermelho);
        printf("  JA FOI ATINGIDO O NUMERO MAXIMO DE ALUNO CADASTRADO NO SISTEMA!!!");
        Muda_Cor(Cor_Das_Grades);
        printf("  \263\n \300\304\304\304\304\304");

        for(j=0; j<8; j++)
            printf("\304\304\304\304\304\304\304\304");

        printf("\331");
        Sleep(4000);
    }
}
//###############################################################################

//############## FUN��O PARA CADASTRAR AS DISCIPLINAS NO SISTEMA ################
void Cadastrar_Disciplinas (Disciplinas Tabela[], int *N)  // REQUISITO 2
{
    int i;
    int j;
    int Tamanho;
    int Analise;
    int Verificar;
    int Retorno;
    int Saida;
    int x;

    char Aux_Codigo[] = {"-01"};
    char Aux_Nome[] = {" (TURMA 1)"};


    i=*N;
    j=0;
    Analise=0;
    Retorno = -1;
    Saida=0;
    x=0;

    Tamanho = 0;
    Verificar = 13;

    while(Verificar == 13 && i < Maximo_Disciplinas && Saida == 0)
    {
        do
        {
            Analise =0;
            Retorno = -1;
            Saida = 0;
            x=0;

            system("cls");

            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");
            Muda_Cor(Vermelho);
            printf(" REALIZANDO O CADASTRAMENTO DE UMA DISCIPLINA NO SISTEMA....");
            Muda_Cor(Cor_Das_Grades);
            printf(" \263\n \300\304\304\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite o codigo da Disciplina de no maximo 6 digitos ou digite: ");
            printf("\n  <S> ou <s> para retornar ao menu, e pressione ENTER: ");
            Muda_Cor(Branco);

            scanf("%[^\n]", Tabela[i].Codigo);
            fflush(stdin);

            if(Tabela[i].Codigo[0] == 'S' ||  Tabela[i].Codigo[0] == 's')
            {
                Saida=1;
                Tamanho = 1;
                Analise = 0;
            }

            if(Saida != 1)
            {

                Tamanho = strlen(Tabela[i].Codigo);

                if(Tamanho > 6 || Tamanho <=0)
                    Analise=1;

                if(Analise ==0)
                {
                    for(j=0; j<Tamanho; j++)
                    {
                        /* N�o permitir que digite Numero
                        if(Tabela[i].Nomes[j] < 65 && Tabela[i].Nomes[j] > 32)
                        Analise = 1;  */

                        if(Tabela[i].Codigo[j] < 65 && Tabela[i].Codigo[j] > 57)
                            Analise = 1;

                        if(Tabela[i].Codigo[j] < 48 && Tabela[i].Codigo[j] > 32)
                            Analise = 1;

                        if(Tabela[i].Codigo[j] < 32)
                            Analise = 1;

                        if(Tabela[i].Codigo[j] > 90 && Tabela[i].Codigo[j] < 97)
                            Analise = 1;

                        if(Tabela[i].Codigo[j] > 122)
                            Analise = 1;
                    }
                }

                x=0;

                if(Analise == 0)
                {
                    strcat(Tabela[i].Codigo, Aux_Codigo);

                    if(i!=0)
                    {
                        for(j=0; j<i; j++)
                        {
                            Retorno = strcmp(Tabela[i].Codigo, Tabela[j].Codigo);

                            if(Retorno == 0)
                            {
                                x=1;
                            }
                        }
                    }

                    if(x==1)
                    {
                        Muda_Cor(Cor_Das_Grades);
                        printf("\n \332\304\304\304\304");

                        for(j=0; j<9; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n \263");

                        Muda_Cor(Vermelho);
                        printf(" ERRO!!! O CODIGO DESSA DISCIPLINA JA ESTA CADASTRADO NO SISTEMA ACADEMICO!");
                        Analise = 1;
                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n \300\304\304\304\304");

                        for(j=0; j<9; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");
                        Sleep(2000);
                    }
                }
            }
        }
        while(Tamanho == 0 || Tamanho > 6 || Analise == 1);

        x=0;

        if(Saida != 1)
        {
            Tamanho = strlen(Tabela[i].Codigo);

            for(j=0; j<Tamanho; j++)
            {
                Tabela[(i+1)].Codigo[j] = Tabela[i].Codigo[j];
            }

            Tamanho = (Tamanho-1);
            Tabela[(i+1)].Codigo[Tamanho] = 50;

            do
            {
                system("cls");
                Analise=0;
                Retorno=-1;
                x=0;

                Muda_Cor(Cor_Das_Grades);
                printf("\n \332\304\304\304\304\304");

                for(j=0; j<7; j++)
                    printf("\304\304\304\304\304\304\304\304");

                printf("\277\n \263");

                Muda_Cor(Vermelho);
                printf(" REALIZANDO O CADASTRAMENTO DE UMA DISCIPLINA NO SISTEMA....");

                Muda_Cor(Cor_Das_Grades);
                printf(" \263\n \300\304\304\304\304\304");

                for(j=0; j<7; j++)
                    printf("\304\304\304\304\304\304\304\304");

                printf("\331");

                fflush(stdin);
                Muda_Cor(Verde);
                printf("\n\n  Digite o nome da Disciplina <40 caracteres no maximo>: ");
                Muda_Cor(Branco);
                scanf("%[^\n]", Tabela[i].Nome);
                fflush(stdin);

                Tamanho = strlen(Tabela[i].Nome);

                if(Tamanho > 40 || Tamanho <= 0)
                    Analise = 1;

                if(Analise == 0)
                {
                    for(j=0; j<Tamanho; j++)
                    {
                        /* N�o permitir que digite Numero
                        if(Tabela[i].Nomes[j] < 65 && Tabela[i].Nomes[j] > 32)
                        Analise = 1;  */

                        if(Tabela[i].Nome[j] < 65 && Tabela[i].Nome[j] > 57)
                            Analise = 1;

                        if(Tabela[i].Nome[j] < 48 && Tabela[i].Nome[j] > 32)
                            Analise = 1;

                        if(Tabela[i].Nome[j] < 32)
                            Analise = 1;

                        if(Tabela[i].Nome[j] > 90 && Tabela[i].Nome[j] < 97)
                            Analise = 1;

                        if(Tabela[i].Nome[j] > 122)
                            Analise = 1;
                    }
                }

                if(Analise == 0)
                {

                    strcat(Tabela[i].Nome, Aux_Nome);
                    x=0;

                    Tamanho = strlen(Tabela[i].Nome);

                    for(j=0; j<Tamanho; j++)
                    {
                        Tabela[i].Nome[j] = toupper(Tabela[i].Nome[j]);
                    }

                    if(i!=0)
                    {
                        for(j=0; j<i; j++)
                        {
                            Retorno = strcmp(Tabela[i].Nome, Tabela[j].Nome);

                            if(Retorno == 0)
                            {
                                x=1;
                            }
                        }

                    }

                    if(x==1)
                    {
                        Muda_Cor(Cor_Das_Grades);
                        printf("\n \332\304\304");

                        for(j=0; j<9; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n \263");

                        Muda_Cor(Vermelho);
                        printf(" ERRO!!! O NOME DESSA DISCIPLINA JA ESTA CADASTRADO NO SISTEMA ACADEMICO!");
                        Analise = 1;
                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n \300\304\304");

                        for(j=0; j<9; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");
                        Sleep(3000);
                    }
                }

            }
            while(Tamanho == 0 || Tamanho > 50 || Analise == 1);


            Tamanho = strlen(Tabela[i].Nome);

            for(j=0; j<Tamanho; j++)
            {
                Tabela[(i+1)].Nome[j] = Tabela[i].Nome[j];
            }

            Tamanho = (Tamanho-2);

            Tabela[(i+1)].Nome[Tamanho] = 50;

            i=(i+2);
            *N=i;

            system("cls");

            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");
            Muda_Cor(Vermelho);
            printf(" REALIZANDO O CADASTRAMENTO DE UMA DISCIPLINA NO SISTEMA....");
            Muda_Cor(Cor_Das_Grades);
            printf(" \263\n \300\304\304\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331\n\n\n \332\304\304\304\304\304\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");
            Muda_Cor(Vermelho);
            printf("  DISCIPLINAS CADASTRADAS COM SUCESSO NO SISTEMA ACADEMICO!!!");
            Muda_Cor(Cor_Das_Grades);
            printf("   \263\n \303\304\304\304\304\304\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\264 \n \263\t\t\t\t\t\t\t\t  \263\n \303\304\304\304\304\304\304\304\304\304\304\304\302");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\304\304\304\304\264\n \263");

            Muda_Cor(Vermelho);
            printf("  CODIGO   ");

            Muda_Cor(Cor_Das_Grades);
            printf("\263");

            Muda_Cor(Vermelho);
            printf("\t\t    NOME DA DISCIPLINAS");

            Muda_Cor(Cor_Das_Grades);
            printf("\t\t\t  \263 \n \303\304\304\304\304\304\304\304\304\304\304\304\305");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\304\304\304\304\264\n \263");

            Muda_Cor(Branco);
            printf(" %-9s", Tabela[(i-2)].Codigo);

            Muda_Cor(Cor_Das_Grades);
            printf(" \263");

            Muda_Cor(Branco);
            printf(" %-50s", Tabela[(i-2)].Nome);

            Muda_Cor(Cor_Das_Grades);
            printf(" \263\n \303\304\304\304\304\304\304\304\304\304\304\304\305");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\304\304\304\304\264 \n \263");

            Muda_Cor(Branco);
            printf(" %-9s", Tabela[(i-1)].Codigo);

            Muda_Cor(Cor_Das_Grades);
            printf(" \263");

            Muda_Cor(Branco);
            printf(" %-50s", Tabela[(i-1)].Nome);

            Muda_Cor(Cor_Das_Grades);
            printf(" \263\n \300\304\304\304\304\304\304\304\304\304\304\304\301");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\304\304\304\304\331");
            Sleep(2000);
        }
    }

    if (i>=Maximo_Disciplinas)
    {
        system("cls");
        Muda_Cor(Cor_Das_Grades);
        printf("\n \332\304\304\304\304");

        for(j=0; j<9; j++)
            printf("\304\304\304\304\304\304\304\304");

        printf("\277\n \263");

        Muda_Cor(Vermelho);
        printf("  JA FOI ATINGIDO O NUMERO MAXIMO DE DISCIPLINAS CADASTRADAS NO SISTEMA!!!");
        Muda_Cor(Cor_Das_Grades);
        printf("  \263\n \300\304\304\304\304");

        for(j=0; j<9; j++)
            printf("\304\304\304\304\304\304\304\304");

        printf("\331");
        Sleep(4000);
    }

}
//###############################################################################

//############## FUN��O PARA CADASTRAR OS PROFESSORES NO SISTEMA ################
void Cadastrar_Professores (Professores Tabela[], int *N) // REQUISITO 3
{
    int i;
    int j;
    int Tamanho;
    int Verificar;
    int Aux;
    int Aux2;
    int mult;
    int x;
    int Analise;
    int Saida;
    int teste;

    char Vet[50];

    Verificar = 13;
    i=*N;
    Saida = 0;
    teste=0;

    while(Verificar == 13 && i < Maximo_Professores && Saida == 0)
    {
        do
        {
            system("cls");

            Aux = 0;
            Aux2=0;
            Tamanho=0;
            mult = 1;
            x=0;
            Analise=0;
            Saida=0;
            teste=0;

            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\277");
            printf("\n \263");
            Muda_Cor(Vermelho);
            printf(" REALIZANDO O CADASTRAMENTO DE UM PROFESSOR NO SISTEMA....");
            Muda_Cor(Cor_Das_Grades);
            printf(" \263");
            printf("\n \300\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite o RP do Professor de no maximo 8 numeros ou digite");
            printf("\n  <S> ou <s> para retornar ao menu, e pressione ENTER: ");
            Muda_Cor(Branco);
            scanf("%[^\n]", Vet);
            fflush(stdin);

            if(Vet[0] == 'S' ||  Vet[0] == 's')
            {
                Saida=1;
                Tabela[i].RP=0;
                Analise=0;
            }

            if(Saida != 1)
            {

                Tamanho = strlen(Vet);
                x = (Tamanho-1);

                for(j=0; j<Tamanho; j++)
                {
                    if(Vet[j] < 48 || Vet[j] > 57)
                    {
                        Analise = 1;
                    }
                    Vet[j] = Vet[j]-48;
                }

                if(Analise == 0)
                {
                    for(j=0; j<Tamanho; j++)
                    {
                        Aux = Vet[x]*mult;
                        Aux2 = (Aux2+Aux);
                        x=(x-1);
                        mult = mult*10;
                    }

                    Tabela[i].RP = Aux2;
                    teste=0;

                    if(i!=0)
                    {
                        for(j=0; j<i; j++)
                        {
                            if(Tabela[i].RP == Tabela[j].RP)
                            {
                                teste=1;
                            }
                        }
                    }

                    if(teste==1)
                    {
                        Muda_Cor(Cor_Das_Grades);
                        printf("\n \332\304\304");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n \263");

                        Muda_Cor(Vermelho);
                        printf(" ERRO!!! ESSE RP JA ESTA CADASTRADO NO SISTEMA ACADEMICO!");
                        Analise = 1;

                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n \300\304\304");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");
                        Sleep(3000);
                    }
                }

                if(Tabela[i].RP == 0)
                    Analise = 1;
            }
        }
        while((Tabela[i].RP) < 0 || (Tabela[i].RP) > 99999999 || Analise == 1);

        if(Saida != 1)
        {

            do
            {
                system("cls");

                Analise=0;

                Muda_Cor(Cor_Das_Grades);
                printf("\n \332\304\304\304\304\304\304\304\304");
                printf("\304\304\304\304\304\304\304\304\304\304");
                printf("\304\304\304\304\304\304\304\304\304\304");
                printf("\304\304\304\304\304\304\304\304\304\304");
                printf("\304\304\304\304\304\304\304\304\304\304\304");
                printf("\304\304\304\304\304\304\304\304\304\304\277");
                printf("\n \263");
                Muda_Cor(Vermelho);
                printf(" REALIZANDO O CADASTRAMENTO DE UM PROFESSOR NO SISTEMA....");
                Muda_Cor(Cor_Das_Grades);
                printf(" \263");
                printf("\n \300\304\304\304\304\304\304\304\304\304");
                printf("\304\304\304\304\304\304\304\304\304\304\304");
                printf("\304\304\304\304\304\304\304\304\304\304");
                printf("\304\304\304\304\304\304\304\304\304\304");
                printf("\304\304\304\304\304\304\304\304\304\304");
                printf("\304\304\304\304\304\304\304\304\304\331");

                fflush(stdin);
                Muda_Cor(Verde);
                printf("\n\n  Digite o nome do professor <50 caracteres no maximo>: ");
                Muda_Cor(Branco);
                scanf("%[^\n]", Tabela[i].Nome);
                fflush(stdin);

                Tamanho = strlen(Tabela[i].Nome);

                if(Tamanho <=0 || Tamanho > 50)
                    Analise=1;

                if(Analise == 0)
                {
                    for(j=0; j<Tamanho; j++)
                    {
                        if(Tabela[i].Nome[j] < 65 && Tabela[i].Nome[j] > 32)
                            Analise = 1;

                        if(Tabela[i].Nome[j] < 32)
                            Analise = 1;

                        if(Tabela[i].Nome[j] > 90 && Tabela[i].Nome[j] < 97)
                            Analise = 1;

                        if(Tabela[i].Nome[j] > 122)
                            Analise = 1;
                    }
                }
            }
            while(Tamanho == 0 || Tamanho > 50 || Analise == 1);

            for(j=0; j<Tamanho; j++)
            {
                Tabela[i].Nome[j] = toupper(Tabela[i].Nome[j]);
            }

            i=(i+1);
            *N=i;

            system("cls");

            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\277");
            printf("\n \263");
            Muda_Cor(Vermelho);
            printf(" REALIZANDO O CADASTRAMENTO DE UM PROFESSOR NO SISTEMA....");
            Muda_Cor(Cor_Das_Grades);
            printf(" \263\n \300\304\304\304");


            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331\n\n\n \332\304\304\304\304\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");
            Muda_Cor(Vermelho);
            printf("   PROFESSOR CADASTRADO COM SUCESSO NO SISTEMA ACADEMICO!!!!");
            Muda_Cor(Cor_Das_Grades);
            printf("\t \263\n \303\304\304\304\304\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\264 \n \263\t\t\t\t\t\t\t\t \263\n \303\304\304\304\304\304\304\304\304\304\304\302");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\304\304\304\304\264\n \263");

            Muda_Cor(Vermelho);
            printf("    RP    ");

            Muda_Cor(Cor_Das_Grades);
            printf("\263");

            Muda_Cor(Vermelho);
            printf("\t\t      NOME DO PROFESSOR");

            Muda_Cor(Cor_Das_Grades);
            printf("\t\t\t \263 \n \303\304\304\304\304\304\304\304\304\304\304\305");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\304\304\304\304\264\n \263");

            Muda_Cor(Branco);
            printf(" %-8d", Tabela[(i-1)].RP);

            Muda_Cor(Cor_Das_Grades);
            printf(" \263");

            Muda_Cor(Branco);
            printf(" %-50s", Tabela[(i-1)].Nome);

            Muda_Cor(Cor_Das_Grades);
            printf(" \263\n \300\304\304\304\304\304\304\304\304\304\304\301");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\304\304\304\304\331");

            Sleep(2000);
        }
    }


    if (i >= Maximo_Professores)
    {
        system("cls");
        Muda_Cor(Cor_Das_Grades);
        printf("\n \332\304\304\304\304");

        for(j=0; j<9; j++)
            printf("\304\304\304\304\304\304\304\304");

        printf("\277\n \263");

        Muda_Cor(Vermelho);
        printf("  JA FOI ATINGIDO O NUMERO MAXIMO DE PROFESSORES CADASTRADOS NO SISTEMA!!!");
        Muda_Cor(Cor_Das_Grades);
        printf("  \263\n \300\304\304\304\304");

        for(j=0; j<9; j++)
            printf("\304\304\304\304\304\304\304\304");

        printf("\331");
        Sleep(4000);
    }

}
//###############################################################################

//################### FUN��O PARA IMPRIMIR A TELA INICIAL #####################
int Imprime_Tela_Inicial ()  // IMPRIME A CAPA DO PROGRAMA
{
    int i;
    int Verificar;
    Verificar = 0;

    do
    {
        system("cls");

        printf("\n\n\n");

        Muda_Cor(Cor_Das_Grades);
        printf("        \332\304\304");
        for(i=0; i<17; i++)
            printf("\304\304\304\304");

        printf("\304\277\n");

        Muda_Cor(Cor_Das_Grades);
        printf("\t\263");
        Muda_Cor(Vermelho);
        printf("\t    _____ _____  _____ _______ ______ __  __");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\t\263 \n\t\263");
        Muda_Cor(Vermelho);
        printf("\t   / ____|_   _|/ ____|__   __|  ____|  \\/  |   /\\");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\263 \n\t\263");
        Muda_Cor(Vermelho);
        printf("\t  | (___   | | | (___    | |  | |__  | \\  / |  /  \\");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\263 \n\t\263");
        Muda_Cor(Vermelho);
        printf("\t   \\___ \\  | |  \\___ \\   | |  |  __| | |\\/| | / /\\ \\");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\263 \n\t\263");
        Muda_Cor(Vermelho);
        printf("\t   ____) |_| |_ ____) |  | |  | |____| |  | |/ ____ \\");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\263 \n\t\263");
        Muda_Cor(Vermelho);
        printf("\t  |_____/|_____|_____/   |_|  |______|_|  |_/_/    \\_\\");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\263 \n\t\263\t\t\t\t\t\t\t\t\t\263 \n");

        Muda_Cor(Cor_Das_Grades);
        printf("\t\263");
        Muda_Cor(Verde);
        printf("\t\t\t    _____  ______");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\t\t\263 \n\t\263");
        Muda_Cor(Verde);
        printf("\t\t\t   |  __ \\|  ____|");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\t\t\263 \n\t\263");
        Muda_Cor(Verde);
        printf("\t\t\t   | |  | | |__");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\t\t\t\263 \n\t\263");
        Muda_Cor(Verde);
        printf("\t\t\t   | |  | |  __|");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\t\t\263 \n\t\263");
        Muda_Cor(Verde);
        printf("\t\t\t   | |__| | |____");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\t\t\263 \n\t\263");
        Muda_Cor(Verde);
        printf("\t\t\t   |_____/|______|");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\t\t\263 \n\t\263\t\t\t\t\t\t\t\t\t\263 \n");

        Muda_Cor(Cor_Das_Grades);
        printf("\t\263");
        Muda_Cor(Vermelho);
        printf("    __  __       _______ _____  _____ _____ _    _ _");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\t\263 \n\t\263");
        Muda_Cor(Vermelho);
        printf("   |  \\/  |   /\\|__   __|  __ \\|_   _/ ____| |  | | |        /\\");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\263 \n\t\263");
        Muda_Cor(Vermelho);
        printf("   | \\  / |  /  \\  | |  | |__) | | || |    | |  | | |       /  \\");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\263 \n\t\263");
        Muda_Cor(Vermelho);
        printf("   | |\\/| | / /\\ \\ | |  |  _  /  | || |    | |  | | |      / /\\ \\");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\263 \n\t\263");
        Muda_Cor(Vermelho);
        printf("   | |  | |/ ____ \\| |  | | \\ \\ _| || |____| |__| | |____ / ____ \\");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\263 \n\t\263");
        Muda_Cor(Vermelho);
        printf("   |_|  |_/_/    \\_\\_|  |_|  \\_\\_____\\_____|\\____/|______/_/    \\_\\");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\263 \n\t\263\t\t\t\t\t\t\t\t\t\263 \n");


        Muda_Cor(Cor_Das_Grades);
        printf("\t\263");
        Muda_Cor(Verde);
        printf("\t     _____          _____  ______ __  __ _____ _____");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\263 \n\t\263");
        Muda_Cor(Verde);
        printf("      /\\   / ____|   /\\   |  __ \\|  ____|  \\/  |_   _/ ____|   /\\");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\263 \n\t\263");
        Muda_Cor(Verde);
        printf("     /  \\ | |       /  \\  | |  | | |__  | \\  / | | || |       /  \\");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\263 \n\t\263");
        Muda_Cor(Verde);
        printf("    / /\\ \\| |      / /\\ \\ | |  | |  __| | |\\/| | | || |      / /\\ \\");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\263 \n        \263");
        Muda_Cor(Verde);
        printf("   / ____ \\ |____ / ____ \\| |__| | |____| |  | |_| || |____ / ____ \\");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\263 \n\t\263");
        Muda_Cor(Verde);
        printf("  /_/    \\_\\_____/_/    \\_\\_____/|______|_|  |_|_____\\_____/_/    \\_\\");
        Muda_Cor(Cor_Das_Grades);
        printf("  \263 \n\t\263\t\t\t\t\t\t\t\t\t\263\n\t\300\304\304\304");

        for(i=0; i<17; i++)
            printf("\304\304\304\304");

        printf("\331");

        fflush(stdin);
        Muda_Cor(Verde);
        printf("\n\n\t\tDIGITE ENTER PARA INICIALIZAR OU CONTINUAR O PROCEDIMENTO ");
        printf("\n\t\t    DE MATRICULA OU DIGITE ESC PARA SAIR DO SISTEMA: ");
        Muda_Cor(Branco);
        Verificar = getch();
        fflush(stdin);

    }
    while(Verificar != 27 && Verificar != 13);

    return Verificar;
}


//############### FUN��O PARA IMPRIMIR A TELA DO MENU PRINCIPAL #################
int Imprime_MENU_Principal () // IMPRIME O MENU INCIAL COM TODAS AS OPCOES
{
    int i;
    int Numero;

    Numero = (-1);

    do
    {
        system("cls");

        i=0;

        Muda_Cor(Cor_Das_Grades);
        printf("\n  \332\304\304");

        for(i=0; i<10; i++)
            printf("\304\304\304\304\304\304\304\304");

        printf("\277\n  \263");
        Muda_Cor(Vermelho);
        printf("\t\t\t\t   MENU PRINCIPAL");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\t\t     \263\n  \303\304\304");

        for(i=0; i<10; i++)
            printf("\304\304\304\304\304\304\304\304");

        printf("\264\n  \263\t\t\t\t\t\t\t\t\t\t     \263");

        printf("\n  \303\304\304\304\304\304\304\304\304\304\304\302\304\304\304");

        for(i=0; i<17; i++)
            printf("\304\304\304\304");


        printf("\264\n  \263");

        Muda_Cor(Vermelho);
        printf(" ESCOLHAS ");

        Muda_Cor(Cor_Das_Grades);
        printf("\263");

        Muda_Cor(Vermelho);
        printf("\t\t\t REQUISITOS DO SISTEMA ACADEMICO\t\t     ");

        Muda_Cor(Cor_Das_Grades);
        printf("\263\n  \303\304\304\304\304\304\304\304\304\304\304\305\304\304\304");
        for(i=0; i<17; i++)
            printf("\304\304\304\304");

        printf("\264\n  \263");

        Muda_Cor(Vermelho);
        printf("     1 ");
        Muda_Cor(Cor_Das_Grades);
        printf("   \263");
        Muda_Cor(Vermelho);
        printf(" CADASTRAR ALUNOS");

        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\t\t\t\t\t     \263\n  \303\304");
        printf("\304\304\304\304\304\304\304\304\304\305\304\304\304");

        for(i=0; i<17; i++)
            printf("\304\304\304\304");

        printf("\264\n  \263");
        Muda_Cor(Vermelho);
        printf("     2 ");
        Muda_Cor(Cor_Das_Grades);
        printf("   \263");
        Muda_Cor(Vermelho);
        printf(" CADASTRAR DISCIPLINAS");

        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\t\t\t\t     \263\n  \303\304");
        printf("\304\304\304\304\304\304\304\304\304\305\304\304\304");

        for(i=0; i<17; i++)
            printf("\304\304\304\304");

        printf("\264\n  \263");

        Muda_Cor(Vermelho);
        printf("     3 ");
        Muda_Cor(Cor_Das_Grades);
        printf("   \263");

        Muda_Cor(Vermelho);
        printf(" CADASTRAR PROFESSORES");

        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\t\t\t\t     \263\n  \303\304");
        printf("\304\304\304\304\304\304\304\304\304\305\304\304\304");

        for(i=0; i<17; i++)
            printf("\304\304\304\304");

        printf("\264\n  \263");

        Muda_Cor(Vermelho);
        printf("     4 ");
        Muda_Cor(Cor_Das_Grades);
        printf("   \263");
        Muda_Cor(Vermelho);
        printf(" REALIZACAO DA MATRICULA");

        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\t\t\t\t     \263\n  \303\304");
        printf("\304\304\304\304\304\304\304\304\304\305\304\304\304");

        for(i=0; i<17; i++)
            printf("\304\304\304\304");

        printf("\264\n  \263");

        Muda_Cor(Vermelho);
        printf("     5 ");
        Muda_Cor(Cor_Das_Grades);
        printf("   \263");

        Muda_Cor(Vermelho);
        printf(" CANCELAMENTO DA MATRICULA");

        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\t\t\t     \263\n  \303\304");
        printf("\304\304\304\304\304\304\304\304\304\305\304\304\304");

        for(i=0; i<17; i++)
            printf("\304\304\304\304");

        printf("\264\n  \263");

        Muda_Cor(Vermelho);
        printf("     6 ");
        Muda_Cor(Cor_Das_Grades);
        printf("   \263");

        Muda_Cor(Vermelho);
        printf(" VINCULAR PROFESSORES A DISCIPLINAS");

        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\t\t     \263\n  \303\304");
        printf("\304\304\304\304\304\304\304\304\304\305\304\304\304");

        for(i=0; i<17; i++)
            printf("\304\304\304\304");

        printf("\264\n  \263");

        Muda_Cor(Vermelho);
        printf("     7 ");
        Muda_Cor(Cor_Das_Grades);
        printf("   \263");
        Muda_Cor(Vermelho);

        printf(" REMOVER VINCULOS DE UM CONJUNTO DE PROFESSORES");
        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\t     \263\n  \303\304");
        printf("\304\304\304\304\304\304\304\304\304\305\304\304\304");

        for(i=0; i<17; i++)
            printf("\304\304\304\304");

        printf("\264\n  \263");

        Muda_Cor(Vermelho);
        printf("     8 ");
        Muda_Cor(Cor_Das_Grades);
        printf("   \263");

        Muda_Cor(Vermelho);
        printf(" IMPRIMIR A LISTA DE TODOS OS ALUNOS");

        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\t\t     \263\n  \303\304");
        printf("\304\304\304\304\304\304\304\304\304\305\304\304\304");

        for(i=0; i<17; i++)
            printf("\304\304\304\304");

        printf("\264\n  \263");

        Muda_Cor(Vermelho);
        printf("     9 ");
        Muda_Cor(Cor_Das_Grades);
        printf("   \263");

        Muda_Cor(Vermelho);
        printf(" IMPRIMIR A LISTA DE TODAS AS DISCIPLINAS");

        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\t\t     \263\n  \303\304");
        printf("\304\304\304\304\304\304\304\304\304\305\304\304\304");

        for(i=0; i<17; i++)
            printf("\304\304\304\304");

        printf("\264\n  \263");

        Muda_Cor(Vermelho);
        printf("    10 ");
        Muda_Cor(Cor_Das_Grades);
        printf("   \263");

        Muda_Cor(Vermelho);
        printf(" IMPRIMIR A LISTA DE TODOS OS PROFESSORES");

        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\t\t     \263\n  \303\304");
        printf("\304\304\304\304\304\304\304\304\304\305\304\304\304");

        for(i=0; i<17; i++)
            printf("\304\304\304\304");

        printf("\264\n  \263");

        Muda_Cor(Vermelho);
        printf("    11 ");
        Muda_Cor(Cor_Das_Grades);
        printf("   \263");

        Muda_Cor(Vermelho);
        printf(" IMPRIMIR A LISTA DE DISCIPLINAS DE UM ALUNO");

        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\t     \263\n  \303\304");
        printf("\304\304\304\304\304\304\304\304\304\305\304\304\304");

        for(i=0; i<17; i++)
            printf("\304\304\304\304");

        printf("\264\n  \263");

        Muda_Cor(Vermelho);
        printf("    12 ");
        Muda_Cor(Cor_Das_Grades);
        printf("   \263");

        Muda_Cor(Vermelho);
        printf(" IMPRIMIR A LISTA DE ALUNOS EM UMA DISCIPLINA E TURMA");

        Muda_Cor(Cor_Das_Grades);
        printf("\t\t     \263\n  \303\304");
        printf("\304\304\304\304\304\304\304\304\304\305\304\304\304");

        for(i=0; i<17; i++)
            printf("\304\304\304\304");

        printf("\264\n  \263");

        Muda_Cor(Vermelho);
        printf("    13 ");
        Muda_Cor(Cor_Das_Grades);
        printf("   \263");

        Muda_Cor(Vermelho);
        printf(" IMPRIMIR A LISTA DE ALUNOS EM UMA DISCIPLINA, INDEPENDENTE DA TURMA");

        Muda_Cor(Cor_Das_Grades);
        printf("   \263\n  \303\304");
        printf("\304\304\304\304\304\304\304\304\304\305\304\304\304");

        for(i=0; i<17; i++)
            printf("\304\304\304\304");

        printf("\264\n  \263");

        Muda_Cor(Vermelho);
        printf("    14 ");

        Muda_Cor(Cor_Das_Grades);
        printf("   \263");

        Muda_Cor(Vermelho);
        printf(" IMPRIMIR A LISTA DE TODAS AS DISCIPLINAS MINISTRADAS POR UM PROFESSOR");

        Muda_Cor(Cor_Das_Grades);
        printf(" \263\n  \303\304");
        printf("\304\304\304\304\304\304\304\304\304\305\304\304\304");

        for(i=0; i<17; i++)
            printf("\304\304\304\304");

        printf("\264\n  \263");

        Muda_Cor(Vermelho);
        printf("    15 ");

        Muda_Cor(Cor_Das_Grades);
        printf("   \263");

        Muda_Cor(Vermelho);
        printf(" IMPRIMIR A LISTA DE TODOS OS PROFESSORES VINCULADOS A UMA DISCIPLINAS");

        Muda_Cor(Cor_Das_Grades);
        printf(" \263\n  \303\304");
        printf("\304\304\304\304\304\304\304\304\304\305\304\304\304");

        for(i=0; i<17; i++)
            printf("\304\304\304\304");

        printf("\264\n  \263");

        Muda_Cor(Vermelho);
        printf("     0 ");

        Muda_Cor(Cor_Das_Grades);
        printf("   \263");

        Muda_Cor(Vermelho);
        printf(" SAIR DO SISTEMA DE MATRICULA ACADEMICA");

        Muda_Cor(Cor_Das_Grades);
        printf("\t\t\t\t     \263\n  \300\304");
        printf("\304\304\304\304\304\304\304\304\304\301\304\304\304");

        for(i=0; i<17; i++)
            printf("\304\304\304\304");

        printf("\331");

        fflush(stdin);
        Muda_Cor(Verde);
        printf("\n\n  ESCOLHA UM NUMERO ENTRE 0 E 15 E PRESSIONE <ENTER> EM RELACAO A OPCAO DESEJADA: ");
        Muda_Cor(Branco);
        scanf("%d", &Numero);
        fflush(stdin);
    }
    while (Numero < 0 || Numero > 15);

    return Numero;
}
//###############################################################################

//# FUN��O PARA IMPRIMIR A LISTA DE TODOS OS ALUNOS CADASTRADOS COM VERIFICA��O #
void Imprime_Alunos_Cadastrados (Alunos Tabela[], int N) // REQUISITO 8
{
    int i;
    int Verificar;

    if(N==0)
    {
        do
        {

            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304");

            for(i=0; i<6; i++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("\t    NENHUM ALUNO CADASTRADO NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf("         \263\n \300\304\304\304\304\304\304\304");

            for(i=0; i<6; i++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL e cadastrar alunos: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    else
    {
        do
        {
            system("cls");

            Muda_Cor(Cor_Das_Grades);
            printf("\n\n \332\304\304\304\304\304\304\304");

            for(i=0; i<7; i++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");
            Muda_Cor(Vermelho);
            printf("\t  LISTA DE TODOS OS ALUNOS CADASTRADOS NO SISTEMA");
            Muda_Cor(Cor_Das_Grades);
            printf("\t \263\n \303\304\304\304\304\304\304\304");

            for(i=0; i<7; i++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\264\n \263\t\t\t\t\t\t\t\t \263");

            printf("\n \303\304\304\304\304\304\304\304\304\304\304\302");

            for(i=0; i<13; i++)
                printf("\304\304\304\304");

            printf("\264\n \263");


            Muda_Cor(Vermelho);
            printf("    RA    ");

            Muda_Cor(Cor_Das_Grades);
            printf("\263");

            Muda_Cor(Vermelho);
            printf("\t\t      ALUNOS CADASTRADOS\t\t ");
            Muda_Cor(Cor_Das_Grades);
            printf("\263\n \303\304\304\304\304\304\304\304\304\304\304\305");

            for(i=0; i<13; i++)
                printf("\304\304\304\304");

            printf("\264");


            for(i=0; i<N; i++)
            {
                printf("\n \263");
                Muda_Cor(Branco);
                printf(" %-8d ", Tabela[i].RA);
                Muda_Cor(Cor_Das_Grades);
                printf("\263");
                Muda_Cor(Branco);
                printf(" %-50s", Tabela[i].Nomes);
                Muda_Cor(Cor_Das_Grades);
                printf(" \263\n");

                if(i==(N-1))
                {
                    printf(" \300\304\304\304\304\304\304\304\304\304\304");
                    printf("\301\304\304\304\304\304\304\304\304\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\331");
                }
                else
                {
                    printf(" \303\304\304\304\304\304\304\304\304\304");
                    printf("\304\305\304\304\304\304\304\304\304\304\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\264");
                }
            }

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }
}
//###############################################################################

//# FUN��O PARA IMPRIMIR A LISTA DE TODOS OS ALUNOS CADASTRADOS SEM VERIFICA��O #
void Imprime_Lista_Alunos (Alunos Tabela[], int N)   // REQUISITO AUXILIAR DO 8
{
    int i;

    Muda_Cor(Cor_Das_Grades);
    printf("\n\n \332\304\304\304\304\304\304\304");

    for(i=0; i<7; i++)
        printf("\304\304\304\304\304\304\304\304");

    printf("\277\n \263");
    Muda_Cor(Vermelho);
    printf("\t  LISTA DE TODOS OS ALUNOS CADASTRADOS NO SISTEMA");
    Muda_Cor(Cor_Das_Grades);
    printf("\t \263\n \303\304\304\304\304\304\304\304");

    for(i=0; i<7; i++)
        printf("\304\304\304\304\304\304\304\304");

    printf("\264\n \263\t\t\t\t\t\t\t\t \263");

    printf("\n \303\304\304\304\304\304\304\304\304\304\304\302");

    for(i=0; i<13; i++)
        printf("\304\304\304\304");

    printf("\264\n \263");


    Muda_Cor(Vermelho);
    printf("    RA    ");

    Muda_Cor(Cor_Das_Grades);
    printf("\263");

    Muda_Cor(Vermelho);
    printf("\t\t      ALUNOS CADASTRADOS\t\t ");
    Muda_Cor(Cor_Das_Grades);
    printf("\263\n \303\304\304\304\304\304\304\304\304\304\304\305");

    for(i=0; i<13; i++)
        printf("\304\304\304\304");

    printf("\264");


    for(i=0; i<N; i++)
    {
        printf("\n \263");
        Muda_Cor(Branco);
        printf(" %-8d ", Tabela[i].RA);
        Muda_Cor(Cor_Das_Grades);
        printf("\263");
        Muda_Cor(Branco);
        printf(" %-50s", Tabela[i].Nomes);
        Muda_Cor(Cor_Das_Grades);
        printf(" \263\n");

        if(i==(N-1))
        {
            printf(" \300\304\304\304\304\304\304\304\304\304\304");
            printf("\301\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\331");
        }
        else
        {
            printf(" \303\304\304\304\304\304\304\304\304\304");
            printf("\304\305\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\264");
        }
    }

}
//###############################################################################

// FUN��O PARA IMPRIMIR A LISTA DE TODAS AS DISCIPLINAS CADASTRADAS COM VERIFICA��O
void Imprime_Disciplinas_Cadastradas (Disciplinas Tabela[], int N) // REQUISITO 9
{
    int i;
    int Verificar;

    if(N==0)
    {
        do
        {

            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304");

            for(i=0; i<6; i++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("\t NENHUMA DISCIPLINA CADASTRADA NO MOMENTO!");

            Muda_Cor(Cor_Das_Grades);
            printf("       \263\n \300\304\304\304\304\304\304\304");

            for(i=0; i<6; i++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL e cadastrar disciplinas: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    else
    {
        Verificar = 0;

        do
        {
            system("cls");

            Muda_Cor(Cor_Das_Grades);
            printf("\n\n \332");

            for(i=0; i<16; i++)
                printf("\304\304\304\304");

            printf("\277\n \263");
            Muda_Cor(Vermelho);
            printf("      LISTA DE TODOS AS DISCIPLINAS CADASTRADAS NO SISTEMA");
            Muda_Cor(Cor_Das_Grades);

            printf("\t  \263\n \303");

            for(i=0; i<16; i++)
                printf("\304\304\304\304");

            printf("\264\n \263\t\t\t\t\t\t\t\t  \263\n \303\304");
            printf("\304\304\304\304\304\304\304\304\304\304\302");

            for(i=0; i<13; i++)
                printf("\304\304\304\304");

            printf("\264\n \263");

            Muda_Cor(Vermelho);
            printf("  CODIGO   ");

            Muda_Cor(Cor_Das_Grades);
            printf("\263");

            Muda_Cor(Vermelho);
            printf("\t\t    DISCIPLINAS CADASTRADAS\t\t");
            Muda_Cor(Cor_Das_Grades);
            printf("  \263\n \303\304\304\304\304\304\304\304\304\304\304\304\305");

            for(i=0; i<13; i++)
                printf("\304\304\304\304");

            printf("\264");

            for(i=0; i<N; i++)
            {
                printf("\n \263");
                Muda_Cor(Branco);
                printf(" %-9s ", Tabela[i].Codigo);
                Muda_Cor(Cor_Das_Grades);
                printf("\263");
                Muda_Cor(Branco);
                printf(" %-50s", Tabela[i].Nome);
                Muda_Cor(Cor_Das_Grades);
                printf(" \263\n");

                if(i==(N-1))
                {
                    printf(" \300\304\304\304\304\304\304\304\304\304\304");
                    printf("\304\301\304\304\304\304\304\304\304\304\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\331");
                }
                else
                {
                    printf(" \303\304\304\304\304\304\304\304\304\304\304");
                    printf("\304\305\304\304\304\304\304\304\304\304\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\264");
                }
            }

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

}
//###############################################################################

// FUN��O PARA IMPRIMIR A LISTA DE TODAS AS DISCIPLINAS CADASTRADAS SEM VERIFICA��O
void Imprime_lista_Disciplinas (Disciplinas Tabela[], int N) // REQUISITO AUXILIAR DO 9
{
    int i;

    Muda_Cor(Cor_Das_Grades);
    printf("\n\n \332");

    for(i=0; i<16; i++)
        printf("\304\304\304\304");

    printf("\277\n \263");
    Muda_Cor(Vermelho);
    printf("      LISTA DE TODOS AS DISCIPLINAS CADASTRADAS NO SISTEMA");
    Muda_Cor(Cor_Das_Grades);

    printf("\t  \263\n \303");

    for(i=0; i<16; i++)
        printf("\304\304\304\304");

    printf("\264\n \263\t\t\t\t\t\t\t\t  \263\n \303\304");
    printf("\304\304\304\304\304\304\304\304\304\304\302");

    for(i=0; i<13; i++)
        printf("\304\304\304\304");

    printf("\264\n \263");

    Muda_Cor(Vermelho);
    printf("  CODIGO   ");

    Muda_Cor(Cor_Das_Grades);
    printf("\263");

    Muda_Cor(Vermelho);
    printf("\t\t    DISCIPLINAS CADASTRADAS\t\t");
    Muda_Cor(Cor_Das_Grades);
    printf("  \263\n \303\304\304\304\304\304\304\304\304\304\304\304\305");

    for(i=0; i<13; i++)
        printf("\304\304\304\304");

    printf("\264");

    for(i=0; i<N; i++)
    {
        printf("\n \263");
        Muda_Cor(Branco);
        printf(" %-9s ", Tabela[i].Codigo);
        Muda_Cor(Cor_Das_Grades);
        printf("\263");
        Muda_Cor(Branco);
        printf(" %-50s", Tabela[i].Nome);
        Muda_Cor(Cor_Das_Grades);
        printf(" \263\n");

        if(i==(N-1))
        {
            printf(" \300\304\304\304\304\304\304\304\304\304\304");
            printf("\304\301\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\331");
        }
        else
        {
            printf(" \303\304\304\304\304\304\304\304\304\304\304");
            printf("\304\305\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\264");
        }
    }
}
//###############################################################################

// FUN��O PARA IMPRIMIR A LISTA DE TODAS AS DISCIPLINAS CADASTRADAS SEM VERIFICA��O
void Imprime_lista_Disciplinas_Independente_da_Turma (Disciplinas TAB_DIS[], Disciplinas_Sem_Turma Tabela[], int N) // REQUISITO AUXILIAR DO 9 SEM TURMAS
{
    int i;
    int j;
    int k;
    int Tamanho;

    k=0;

    for(i=0; i<N; i+=2)
    {
        Tamanho = strlen(TAB_DIS[i].Codigo);
        Tamanho=(Tamanho-3);
        for(j=0; j<Tamanho; j++)
        {
            Tabela[k].Codigo2[j] = TAB_DIS[i].Codigo[j];
        }
        k=(k+1);
    }

    k=0;

    for(i=0; i<N; i+=2)
    {
        Tamanho = strlen(TAB_DIS[i].Nome);
        Tamanho=(Tamanho-10);
        for(j=0; j<Tamanho; j++)
        {
            Tabela[k].Nome2[j] = TAB_DIS[i].Nome[j];
        }
        k=(k+1);
    }


    Muda_Cor(Cor_Das_Grades);
    printf("\n\n \332");

    for(i=0; i<16; i++)
        printf("\304\304\304\304");

    printf("\277\n \263");
    Muda_Cor(Vermelho);
    printf("      LISTA DE TODOS AS DISCIPLINAS CADASTRADAS NO SISTEMA");
    Muda_Cor(Cor_Das_Grades);

    printf("\t  \263\n \303");

    for(i=0; i<16; i++)
        printf("\304\304\304\304");

    printf("\264\n \263\t\t\t\t\t\t\t\t  \263\n \303\304");
    printf("\304\304\304\304\304\304\304\304\304\304\302");

    for(i=0; i<13; i++)
        printf("\304\304\304\304");

    printf("\264\n \263");

    Muda_Cor(Vermelho);
    printf("  CODIGO   ");

    Muda_Cor(Cor_Das_Grades);
    printf("\263");

    Muda_Cor(Vermelho);
    printf("\t\t    DISCIPLINAS CADASTRADAS\t\t");
    Muda_Cor(Cor_Das_Grades);
    printf("  \263\n \303\304\304\304\304\304\304\304\304\304\304\304\305");

    for(i=0; i<13; i++)
        printf("\304\304\304\304");

    printf("\264");

    k = N;
    k = (k/2);

    for(i=0; i<k; i++)
    {
        printf("\n \263");
        Muda_Cor(Branco);
        printf(" %-9s ", Tabela[i].Codigo2);
        Muda_Cor(Cor_Das_Grades);
        printf("\263");
        Muda_Cor(Branco);
        printf(" %-50s", Tabela[i].Nome2);
        Muda_Cor(Cor_Das_Grades);
        printf(" \263\n");

        if(i==(k-1))
        {
            printf(" \300\304\304\304\304\304\304\304\304\304\304");
            printf("\304\301\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\331");
        }
        else
        {
            printf(" \303\304\304\304\304\304\304\304\304\304\304");
            printf("\304\305\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\264");
        }
    }
}
//###############################################################################

// FUN��O PARA IMPRIMIR A LISTA DE TODOS OS PROFESSORES CADASTRADOS COM VERIFICA��O
void Imprime_Professores_Cadastrados (Professores Tabela[], int N) // REQUISITO 10
{
    int i;
    int Verificar;

    if(N == 0)
    {
        do
        {

            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304");

            for(i=0; i<6; i++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("\t  NENHUM PROFESSOR CADASTRADO NO MOMENTO!");

            Muda_Cor(Cor_Das_Grades);
            printf("        \263\n \300\304\304\304\304\304\304\304");

            for(i=0; i<6; i++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL e cadastrar professores: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    else
    {
        Verificar = 0;

        do
        {
            system("cls");

            Muda_Cor(Cor_Das_Grades);
            printf("\n\n \332\304\304\304");

            for(i=0; i<15; i++)
                printf("\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("     LISTA DE TODOS OS PROFESSSORES CADASTRADOS NO SISTEMA");

            Muda_Cor(Cor_Das_Grades);
            printf("\t \263\n \303\304\304\304");

            for(i=0; i<15; i++)
                printf("\304\304\304\304");

            printf("\264\n \263\t\t\t\t\t\t\t\t \263\n \303");
            printf("\304\304\304\304\304\304\304\304\304\304\302");

            for(i=0; i<13; i++)
                printf("\304\304\304\304");

            printf("\264\n \263");

            Muda_Cor(Vermelho);
            printf("    RP    ");

            Muda_Cor(Cor_Das_Grades);
            printf("\263");

            Muda_Cor(Vermelho);
            printf("\t\t   PROFESSORES CADASTRADOS\t\t ");
            Muda_Cor(Cor_Das_Grades);
            printf("\263\n \303\304\304\304\304\304\304\304\304\304\304\305");

            for(i=0; i<13; i++)
                printf("\304\304\304\304");

            printf("\264");

            for(i=0; i<N; i++)
            {
                printf("\n \263");
                Muda_Cor(Branco);
                printf(" %-8d ", Tabela[i].RP);
                Muda_Cor(Cor_Das_Grades);
                printf("\263");
                Muda_Cor(Branco);
                printf(" %-50s", Tabela[i].Nome);
                Muda_Cor(Cor_Das_Grades);
                printf(" \263\n");

                if(i==(N-1))
                {
                    printf(" \300\304\304\304\304\304\304\304\304\304\304");
                    printf("\301\304\304\304\304\304\304\304\304\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\331");
                }
                else
                {
                    printf(" \303\304\304\304\304\304\304\304\304\304");
                    printf("\304\305\304\304\304\304\304\304\304\304\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\264");
                }
            }

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");

            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");

            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL: ");

            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }
}
//###############################################################################

// FUN��O PARA IMPRIMIR A LISTA DE TODOS OS PROFESSORES CADASTRADOS SEM VERIFICA��O
void Imprime_Lista_Professores (Professores Tabela[], int N) // REQUISITO AUXILIAR DO 10
{
    int i;

    Muda_Cor(Cor_Das_Grades);
    printf("\n\n \332\304\304\304");

    for(i=0; i<15; i++)
        printf("\304\304\304\304");

    printf("\277\n \263");

    Muda_Cor(Vermelho);
    printf("     LISTA DE TODOS OS PROFESSSORES CADASTRADOS NO SISTEMA");

    Muda_Cor(Cor_Das_Grades);
    printf("\t \263\n \303\304\304\304");

    for(i=0; i<15; i++)
        printf("\304\304\304\304");

    printf("\264\n \263\t\t\t\t\t\t\t\t \263\n \303");
    printf("\304\304\304\304\304\304\304\304\304\304\302");

    for(i=0; i<13; i++)
        printf("\304\304\304\304");

    printf("\264\n \263");

    Muda_Cor(Vermelho);
    printf("    RP    ");

    Muda_Cor(Cor_Das_Grades);
    printf("\263");

    Muda_Cor(Vermelho);
    printf("\t\t   PROFESSORES CADASTRADOS\t\t ");

    Muda_Cor(Cor_Das_Grades);
    printf("\263\n \303\304\304\304\304\304\304\304\304\304\304\305");

    for(i=0; i<13; i++)
        printf("\304\304\304\304");

    printf("\264");

    for(i=0; i<N; i++)
    {
        printf("\n \263");
        Muda_Cor(Branco);
        printf(" %-8d ", Tabela[i].RP);
        Muda_Cor(Cor_Das_Grades);
        printf("\263");
        Muda_Cor(Branco);
        printf(" %-50s", Tabela[i].Nome);
        Muda_Cor(Cor_Das_Grades);
        printf(" \263\n");

        if(i==(N-1))
        {
            printf(" \300\304\304\304\304\304\304\304\304\304\304");
            printf("\301\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\331");
        }
        else
        {
            printf(" \303\304\304\304\304\304\304\304\304\304");
            printf("\304\305\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\304");
            printf("\304\304\304\304\304\304\304\304\304\304\264");
        }
    }
}
//###############################################################################

// FUN��O PARA REALIZAR OS PROCEDIMENTOS DE MATRICULAS DOS ALUNOS NAS DEVIDAS DISCIPLINAS
void Matricular_Alunos (Alunos TAB_AL[], Disciplinas TAB_DIS[], Matriculas Tabela[], int N_AL, int N_DIS) // REQUISITO 4
{
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    int x;
    int Vet_RA[40];
    int RA[40];
    int Vet_Nome[40];
    char Vet_Aux[40][10];

    int Analise;
    int Analise2;
    int Aux;
    int Aux_2;
    int Aux_3;
    int Saida;
    int Retorno;
    int Teste;

    int Verificar;

    Verificar = 13;
    i=0;
    j=0;
    k=0;
    l=0;
    Analise=0;
    Analise2=0;
    Aux = 0;
    Saida = 0;
    Retorno = -1;
    m=0;
    n=0;
    x=0;
    Teste=0;
    Aux_2=0;
    Aux_3=0;

    if(N_AL == 0 && N_DIS == 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf(" NENHUM ALUNO E NEM DISCIPLINA CADASTRADA NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf(" \263\n \300\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL");
            printf("\n  e cadastrar alunos ou disciplinas: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_AL == 0 && N_DIS > 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("\t    NENHUM ALUNO CADASTRADO NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf("         \263\n \300\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL e cadastrar alunos: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_DIS == 0 && N_AL > 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("\t  NENHUMA DISCIPLINA CADASTRADA NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf("     \263\n \300\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL e cadastrar disciplinas: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    Saida = 0;

    while(Verificar == 13)
    {
        i=0;
        j=0;
        k=0;
        l=0;
        Analise=0;
        Analise2=0;
        Aux = 0;
        Retorno = -1;
        Verificar = 13;
        Saida = 0;
        x=0;

        for(j=0; j<40; j++)
        {
            Vet_Nome[j] = (-1);
            RA[j] = (-1);
        }

        if(N_AL > 0 && N_DIS > 0)
        {
            i=0;
            while(Saida == 0 && i<Maximo_Alunos)
            {
                do
                {
                    system("cls");
                    Analise = 0;
                    Analise2=0;
                    Saida=0;

                    Muda_Cor(Cor_Das_Grades);
                    printf("\n    \332");

                    for(j=0; j<7; j++)
                        printf("\304\304\304\304\304\304\304\304");

                    printf("\277\n    \263");

                    Muda_Cor(Vermelho);
                    printf(" REALIZANDO A MATRICULA DE UM CONJUNTO DE ALUNOS, EM UM");

                    Muda_Cor(Cor_Das_Grades);
                    printf(" \263\n    \263");

                    Muda_Cor(Vermelho);
                    printf(" CONJUNTO DE DISCIPLINAS PARA UMA DETERMINADA TURMA...");
                    Muda_Cor(Cor_Das_Grades);
                    printf("  \263\n    \300");

                    for(j=0; j<7; j++)
                        printf("\304\304\304\304\304\304\304\304");

                    printf("\331");

                    Imprime_Lista_Alunos(TAB_AL, N_AL);

                    Muda_Cor(Verde);
                    printf("\n\n   Digite um ");

                    Muda_Cor(Cor_Das_Grades);
                    printf("RA");

                    Muda_Cor(Verde);
                    printf(" correspondente ao nome de um");

                    Muda_Cor(Cor_Das_Grades);
                    printf(" ALUNO CADASTRADO ");

                    Muda_Cor(Verde);
                    printf("ou\n   Digite <");

                    Muda_Cor(Cor_Das_Grades);
                    printf("-10");

                    Muda_Cor(Verde);
                    printf("> para selecionar TODOS OS ALUNOS CADASTRADOS e\n   pressione");

                    Muda_Cor(Cor_Das_Grades);
                    printf(" ENTER. ");

                    Muda_Cor(Verde);
                    printf(" Quando desejar encerrar o conjunto de\n   ALUNOS digite <");

                    Muda_Cor(Cor_Das_Grades);
                    printf("-1");

                    Muda_Cor(Verde);
                    printf("> e pressione a tecla");

                    Muda_Cor(Cor_Das_Grades);
                    printf(" ENTER: ");

                    fflush(stdin);
                    Muda_Cor(Branco);
                    scanf("%d", &Vet_RA[i]);
                    fflush(stdin);

                    Analise=0;
                    Analise2=0;
                    Saida=0;
                    Aux=0;
                    x=0;

                    if(Vet_RA[i] == (-10))
                    {
                        x=10;
                    }

                    if(Vet_RA[i]!=(-1) && x!=10)
                    {
                        for(j=0; j<N_AL; j++)
                        {
                            if(Vet_RA[i] == TAB_AL[j].RA)
                            {
                                Analise = 1;
                                Aux = j;
                            }
                        }

                        if(Analise == 0)
                        {
                            Muda_Cor(Cor_Das_Grades);
                            printf("\n \332\304");

                            for(j=0; j<5; j++)
                                printf("\304\304\304\304\304\304\304\304");

                            printf("\277\n \263");

                            Muda_Cor(Vermelho);
                            printf(" RA NAO CADASTRADO NO SISTEMA ACADEMICO!");
                            Muda_Cor(Cor_Das_Grades);
                            printf(" \263\n \300\304");

                            for(j=0; j<5; j++)
                                printf("\304\304\304\304\304\304\304\304");

                            printf("\331");
                            Sleep(3000);
                        }
                        else
                        {
                            RA[i] = Aux;

                            if(i!=0)
                            {
                                for(j=0; j<i; j++)
                                {
                                    if(RA[i] == RA[j])
                                    {
                                        Analise2=1;
                                    }
                                }
                                if(Analise2 == 1)
                                {
                                    Muda_Cor(Cor_Das_Grades);
                                    printf("\n \332\304");

                                    for(j=0; j<5; j++)
                                        printf("\304\304\304\304\304\304\304\304");

                                    printf("\277\n \263");

                                    Muda_Cor(Vermelho);
                                    printf(" VOCE JA INCLUIU ESTE ALUNO NO CONJUNTO!");
                                    Muda_Cor(Cor_Das_Grades);
                                    printf(" \263\n \300\304");

                                    for(j=0; j<5; j++)
                                        printf("\304\304\304\304\304\304\304\304");

                                    printf("\331");
                                    Sleep(3000);
                                }

                            }
                        }
                    }

                    if(Vet_RA[i]==(-1))
                    {
                        Saida=1;
                        Analise=1;
                        Analise2=0;
                    }

                    if(x==10)
                    {
                        Analise=1;
                        Analise2=0;
                    }

                }
                while(Analise==0 || Analise2==1);


                if(Saida == 0 && Analise == 1 && Analise2==0 && x!=10)
                {

                    system("cls");

                    Muda_Cor(Cor_Das_Grades);
                    printf("\n    \332");

                    for(j=0; j<7; j++)
                        printf("\304\304\304\304\304\304\304\304");

                    printf("\277\n    \263");

                    Muda_Cor(Vermelho);
                    printf(" REALIZANDO A MATRICULA DE UM CONJUNTO DE ALUNOS, EM UM");

                    Muda_Cor(Cor_Das_Grades);
                    printf(" \263\n    \263");

                    Muda_Cor(Vermelho);
                    printf(" CONJUNTO DE DISCIPLINAS PARA UMA DETERMINADA TURMA...");
                    Muda_Cor(Cor_Das_Grades);
                    printf("  \263\n    \300");

                    for(j=0; j<7; j++)
                        printf("\304\304\304\304\304\304\304\304");

                    printf("\331");


                    printf("\n\n\t       \332\304\304\304\304\304\304\304\304\304\304\304\304\302");

                    for(j=0; j<5; j++)
                        printf("\304\304\304\304");

                    printf("\304\277\n\t       \263");


                    Muda_Cor(Vermelho);
                    printf(" QUANTIDADE ");

                    Muda_Cor(Cor_Das_Grades);
                    printf("\263");

                    Muda_Cor(Vermelho);
                    printf("  RAS SELECIONADOS   ");
                    Muda_Cor(Cor_Das_Grades);
                    printf("\263\n\t       \303\304\304\304\304\304\304\304\304\304\304\304\304\305");

                    for(j=0; j<5; j++)
                        printf("\304\304\304\304");

                    printf("\304\264");

                    i=(i+1);

                    for(j=0; j<i; j++)
                    {
                        printf("\n\t       \263");
                        Muda_Cor(Branco);
                        printf("      %-2d    ", (j+1));
                        Muda_Cor(Cor_Das_Grades);
                        printf("\263");
                        Muda_Cor(Branco);
                        printf("      %-8d", Vet_RA[j]);
                        Muda_Cor(Cor_Das_Grades);
                        printf("       \263\n\t       ");

                        if(j==(i-1))
                        {
                            printf("\300\304\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\301\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\331");
                        }
                        else
                        {
                            printf("\303\304\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\305\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\264");
                        }
                    }
                    Sleep(1000*i);
                }

                if(x==10)
                {
                    i=0;

                    for(j=0; j<N_AL; j++)
                    {
                        RA[i] = j;
                        i=(i+1);
                    }

                    Muda_Cor(Cor_Das_Grades);
                    printf("\n\n \332");

                    for(j=0; j<6; j++)
                        printf("\304\304\304\304\304\304\304\304");

                    printf("\277\n \263");

                    Muda_Cor(Vermelho);
                    printf("    FOI SELECIONADA A OPCAO TODOS OS ALUNOS!");
                    Muda_Cor(Cor_Das_Grades);
                    printf("    \263\n \300");

                    for(j=0; j<6; j++)
                        printf("\304\304\304\304\304\304\304\304");

                    printf("\331");
                    Sleep(3000);

                    Saida=1;
                }
            }

            if(i>0)
            {
                Saida=0;

                k=0;
                while(Saida == 0 && i<Maximo_Disciplinas)
                {
                    do
                    {
                        system("cls");

                        Muda_Cor(Cor_Das_Grades);
                        printf("\n    \332");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n    \263");

                        Muda_Cor(Vermelho);
                        printf(" REALIZANDO A MATRICULA DE UM CONJUNTO DE ALUNOS, EM UM");

                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n    \263");

                        Muda_Cor(Vermelho);
                        printf(" CONJUNTO DE DISCIPLINAS PARA UMA DETERMINADA TURMA...");
                        Muda_Cor(Cor_Das_Grades);
                        printf("  \263\n    \300");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");

                        Imprime_lista_Disciplinas(TAB_DIS, N_DIS);

                        Muda_Cor(Verde);
                        printf("\n\n   Digite um ");

                        Muda_Cor(Cor_Das_Grades);
                        printf("CODIGO COM O TRACO");

                        Muda_Cor(Verde);
                        printf(" correspondente a uma");

                        Muda_Cor(Cor_Das_Grades);
                        printf(" DISCIPLINA\n   CADASTRADA ");

                        Muda_Cor(Verde);
                        printf("ou digite a letra <");

                        Muda_Cor(Cor_Das_Grades);
                        printf("T");

                        Muda_Cor(Verde);
                        printf("> ou <");

                        Muda_Cor(Cor_Das_Grades);
                        printf("t");

                        Muda_Cor(Verde);
                        printf("> para selecionar TODAS\n   AS DISCIPLINAS CADASTRADAS e pressione");

                        Muda_Cor(Cor_Das_Grades);
                        printf(" ENTER.");

                        Muda_Cor(Verde);
                        printf(" Quando desejar\n   encerrar o conjunto de DISCIPLINAS digite a tecla <");

                        Muda_Cor(Cor_Das_Grades);
                        printf("s");

                        Muda_Cor(Verde);
                        printf("> ou <");

                        Muda_Cor(Cor_Das_Grades);
                        printf("S");

                        Muda_Cor(Verde);
                        printf(">\n   e pressione a tecla");

                        Muda_Cor(Cor_Das_Grades);
                        printf(" ENTER: ");

                        fflush(stdin);
                        Muda_Cor(Branco);
                        scanf("%[^\n]", Vet_Aux[k]);
                        fflush(stdin);

                        Saida=0;
                        Analise=0;
                        Analise2=0;
                        Aux=0;
                        x=0;
                        Retorno=(-1);

                        if(Vet_Aux[k][0] == 'T' || Vet_Aux[k][0] == 't')
                        {
                            x=10;
                        }

                        if(Vet_Aux[k][0] == 'S' ||  Vet_Aux[k][0] == 's')
                        {
                            Saida=1;
                            Analise=1;
                            Analise2=0;
                        }

                        if(Saida!=1 && x != 10)
                        {
                            for(j=0; j<N_DIS; j++)
                            {
                                Retorno = strcmp(Vet_Aux[k], TAB_DIS[j].Codigo);
                                if(Retorno == 0)
                                {
                                    Analise=1;
                                    Aux=j;
                                }

                            }

                            if(Analise == 0)
                            {
                                Muda_Cor(Cor_Das_Grades);
                                printf("\n \332\304\304\304\304\304");

                                for(j=0; j<5; j++)
                                    printf("\304\304\304\304\304\304\304\304");

                                printf("\277\n \263");

                                Muda_Cor(Vermelho);
                                printf(" CODIGO NAO CADASTRADO NO SISTEMA ACADEMICO!");
                                Muda_Cor(Cor_Das_Grades);
                                printf(" \263\n \300\304\304\304\304\304");

                                for(j=0; j<5; j++)
                                    printf("\304\304\304\304\304\304\304\304");

                                printf("\331");
                                Sleep(3000);
                            }
                            else
                            {
                                Vet_Nome[k] = Aux;

                                if(k!=0)
                                {
                                    for(j=0; j<k; j++)
                                    {
                                        if(Vet_Nome[k] == Vet_Nome[j])
                                        {
                                            Analise2=1;
                                        }
                                    }

                                    if(Analise2 == 1)
                                    {
                                        Muda_Cor(Cor_Das_Grades);
                                        printf("\n \332\304\304\304\304\304\304");

                                        for(j=0; j<5; j++)
                                            printf("\304\304\304\304\304\304\304\304");

                                        printf("\277\n \263");

                                        Muda_Cor(Vermelho);
                                        printf(" VOCE JA INCLUIU ESTA DISCIPLINA NO CONJUNTO!");
                                        Muda_Cor(Cor_Das_Grades);
                                        printf(" \263\n \300\304\304\304\304\304\304");

                                        for(j=0; j<5; j++)
                                            printf("\304\304\304\304\304\304\304\304");

                                        printf("\331");
                                        Sleep(3000);

                                    }
                                }

                            }
                        }

                        if(x==10)
                        {
                            Analise=1;
                            Analise2=0;
                        }

                    }
                    while(Analise == 0 || Analise2==1);


                    if(Saida == 0 && Analise == 1 && Analise2==0 && x!=10)
                    {
                        system("cls");

                        Muda_Cor(Cor_Das_Grades);
                        printf("\n    \332");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n    \263");

                        Muda_Cor(Vermelho);
                        printf(" REALIZANDO A MATRICULA DE UM CONJUNTO DE ALUNOS, EM UM");

                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n    \263");

                        Muda_Cor(Vermelho);
                        printf(" CONJUNTO DE DISCIPLINAS PARA UMA DETERMINADA TURMA...");
                        Muda_Cor(Cor_Das_Grades);
                        printf("  \263\n    \300");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");


                        printf("\n\n\t       \332\304\304\304\304\304\304\304\304\304\304\304\304\302");

                        for(j=0; j<5; j++)
                            printf("\304\304\304\304");

                        printf("\304\304\277\n\t       \263");


                        Muda_Cor(Vermelho);
                        printf(" QUANTIDADE ");

                        Muda_Cor(Cor_Das_Grades);
                        printf("\263");

                        Muda_Cor(Vermelho);
                        printf(" CODIGOS SELECIONADOS ");
                        Muda_Cor(Cor_Das_Grades);
                        printf("\263\n\t       \303\304\304\304\304\304\304\304\304\304\304\304\304\305");

                        for(j=0; j<5; j++)
                            printf("\304\304\304\304");

                        printf("\304\304\264");

                        k=(k+1);

                        for(j=0; j<k; j++)
                        {
                            printf("\n\t       \263");
                            Muda_Cor(Branco);
                            printf("      %-2d    ", (j+1));
                            Muda_Cor(Cor_Das_Grades);
                            printf("\263");
                            Muda_Cor(Branco);
                            printf("      %-9s", Vet_Aux[j]);
                            Muda_Cor(Cor_Das_Grades);
                            printf("       \263\n\t       ");

                            if(j==(k-1))
                            {
                                printf("\300\304\304\304\304\304\304\304\304\304\304\304\304");
                                printf("\301\304\304\304\304\304\304\304\304\304\304\304\304");
                                printf("\304\304\304\304\304\304\304\304\304\304\331");
                            }
                            else
                            {
                                printf("\303\304\304\304\304\304\304\304\304\304\304\304\304");
                                printf("\305\304\304\304\304\304\304\304\304\304\304\304\304");
                                printf("\304\304\304\304\304\304\304\304\304\304\264");
                            }
                        }
                        Sleep(1000*k);
                    }

                    if(x==10)
                    {
                        k=0;
                        for(j=0; j<N_DIS; j++)
                        {
                            Vet_Nome[k] = j;
                            k=(k+1);
                        }

                        Muda_Cor(Cor_Das_Grades);
                        printf("\n\n \332\304");

                        for(j=0; j<6; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n \263");

                        Muda_Cor(Vermelho);
                        printf("  FOI SELECIONADA A OPCAO TODAS AS DISCIPLINAS!");
                        Muda_Cor(Cor_Das_Grades);
                        printf("  \263\n \300\304");

                        for(j=0; j<6; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");
                        Sleep(3000);

                        Saida=1;
                    }
                }

                Teste=0;
                Aux = 0;
                j=0;
                l=0;
                x=0;

                for(j=0; j<40; j++)
                {
                    Aux = (Aux + RA[j]);
                }

                if(Aux!=(-40))
                {
                    Aux=0;
                    m=0;

                    for(j=0; j<40; j++)
                    {
                        Aux = (Aux + Vet_Nome[j]);
                    }

                    if(Aux!=(-40))
                    {
                        Teste=25;
                        Aux_2 = 0;
                        Aux_3 = 0;

                        for(l=0; l<k; l++)
                        {
                            Aux=(Vet_Nome[l]);
                            j=0;
                            m=0;

                            while(j<15 && m < i)
                            {
                                Aux_2 = Aux;

                                if(Aux_2%2==0)
                                {
                                    Aux_3=2;
                                }
                                else
                                {
                                    Aux_3=1;
                                }

                                if(Aux_3 == 2)
                                {
                                    Aux_2 = Aux;
                                    Aux_2 = (Aux_2+1);
                                }

                                if(Aux_3 == 1)
                                {
                                    Aux_2 = Aux;
                                    Aux_2 = (Aux_2-1);
                                }

                                Analise=0;

                                for(n=0; n<15; n++)
                                {
                                    if(Tabela[Aux_2].Alunos[n] == RA[m])
                                    {
                                        m=(m+1);
                                        Analise=1;
                                    }
                                }
                                if(Analise!=1)
                                {
                                    while(Tabela[Aux].Alunos[j] != (-1))
                                    {
                                        j++;
                                    }
                                    x=0;

                                    for(n=0; n<15; n++)
                                    {
                                        if(Tabela[Aux].Alunos[n] == (RA[m]))
                                        {
                                            x=1;
                                        }
                                    }
                                    if(x==1)
                                    {
                                        m=(m+1);
                                    }
                                    else
                                    {
                                        Tabela[Aux].Alunos[j] = (RA[m]);
                                        m=(m+1);
                                    }
                                }
                            }
                        }
                    }
                }

                if(Teste==25)
                {
                    do
                    {
                        system("cls");
                        Muda_Cor(Cor_Das_Grades);
                        printf("\n    \332");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n    \263");

                        Muda_Cor(Vermelho);
                        printf("  CONJUNTO DE ALUNOS MATRICULADOS COM SUCESSO, EM UM");

                        Muda_Cor(Cor_Das_Grades);
                        printf("    \263\n    \263");

                        Muda_Cor(Vermelho);
                        printf(" CONJUNTO DE DISCIPLINAS PARA UMA DETERMINADA TURMA...");
                        Muda_Cor(Cor_Das_Grades);
                        printf("  \263\n    \300");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");

                        fflush(stdin);
                        Muda_Cor(Verde);
                        printf("\n\n     Digite ");
                        Muda_Cor(Cor_Das_Grades);
                        printf("ENTER ");
                        Muda_Cor(Verde);
                        printf("se deseja cadastrar mais ALUNOS\n     no sistema ou ");
                        Muda_Cor(Cor_Das_Grades);
                        printf("ESC ");
                        Muda_Cor(Verde);
                        printf("para retornar ao MENU: ");
                        Muda_Cor(Branco);

                        Verificar = getch();
                        fflush(stdin);
                    }
                    while(Verificar != 27 && Verificar != 13);
                }

                else
                {
                    do
                    {
                        system("cls");
                        Muda_Cor(Cor_Das_Grades);
                        printf("\n    \332");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n    \263");

                        Muda_Cor(Vermelho);
                        printf("  CONJUNTO DE ALUNOS MATRICULADOS SEM SUCESSO, EM UM");

                        Muda_Cor(Cor_Das_Grades);
                        printf("    \263\n    \263");

                        Muda_Cor(Vermelho);
                        printf(" CONJUNTO DE DISCIPLINAS PARA UMA DETERMINADA TURMA...");
                        Muda_Cor(Cor_Das_Grades);
                        printf("  \263\n    \300");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");

                        fflush(stdin);
                        Muda_Cor(Verde);
                        printf("\n\n     Digite ");
                        Muda_Cor(Cor_Das_Grades);
                        printf("ENTER ");
                        Muda_Cor(Verde);
                        printf("se deseja cadastrar mais ALUNOS\n     no sistema ou ");
                        Muda_Cor(Cor_Das_Grades);
                        printf("ESC ");
                        Muda_Cor(Verde);
                        printf("para retornar ao MENU: ");
                        Muda_Cor(Branco);

                        Verificar = getch();
                        fflush(stdin);
                    }
                    while(Verificar != 27 && Verificar != 13);

                }
            }

            if(Saida==1 && i==0)
            {
                Verificar=27;
            }
        }
    }
}
//###############################################################################

// FUN��O PARA REALIZAR OS PROCEDIMENTOS DE MATRICULAS DOS ALUNOS NAS DEVIDAS DISCIPLINAS
void Desmatricular_Alunos (Alunos TAB_AL[], Disciplinas TAB_DIS[], Matriculas Tabela[], int N_AL, int N_DIS) // REQUISITO 5
{
    int i;
    int j;
    int k;
    int l;
    int m;
    int x;
    int Vet_RA[40];
    int RA[40];
    int Vet_Nome[40];
    char Vet_Aux[40][10];

    int Analise;
    int Analise2;
    int Aux;
    int Saida;
    int Retorno;
    int Soma;
    int Teste;


    int Verificar;

    i=0;
    j=0;
    k=0;
    l=0;
    Analise=0;
    Analise2=0;
    Aux = 0;
    Saida = 0;
    Retorno = -1;
    m=0;
    x=0;
    Soma=0;
    Teste=0;
    Verificar = 13;

    if(N_AL == 0 && N_DIS == 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf(" NENHUM ALUNO E NEM DISCIPLINA CADASTRADA NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf(" \263\n \300\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL");
            printf("\n  e cadastrar alunos ou disciplinas: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_AL == 0 && N_DIS > 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("\t    NENHUM ALUNO CADASTRADO NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf("         \263\n \300\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL e cadastrar alunos: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_DIS == 0 && N_AL > 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("\t  NENHUMA DISCIPLINA CADASTRADA NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf("     \263\n \300\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL e cadastrar disciplinas: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_AL > 0 && N_DIS > 0)
    {
        x=0;

        for(l=0; l<30; l++)
        {
            Soma=0;
            for(j=0; j<15; j++)
            {
                Soma = (Soma+Tabela[l].Alunos[j]);
            }
            if(Soma!=(-15))
            {
                x=1;
            }

        }

        if(x==0)
        {
            do
            {
                system("cls");
                Muda_Cor(Cor_Das_Grades);
                printf("\n \332\304\304\304\304\304\304\304");

                for(j=0; j<6; j++)
                    printf("\304\304\304\304\304\304\304\304");

                printf("\277\n \263");

                Muda_Cor(Vermelho);
                printf("\t   NENHUM ALUNO MATRICULADO NO MOMENTO! ");

                Muda_Cor(Cor_Das_Grades);
                printf("         \263\n \300\304\304\304\304\304\304\304");

                for(j=0; j<6; j++)
                    printf("\304\304\304\304\304\304\304\304");

                printf("\331");

                fflush(stdin);
                Muda_Cor(Verde);
                printf("\n\n  Digite ");
                Muda_Cor(Cor_Das_Grades);
                printf("ESC ");
                Muda_Cor(Verde);
                printf("para retornar ao MENU INICIAL e cadastrar disciplinas: ");
                Muda_Cor(Branco);
                Verificar = getch();
                fflush(stdin);
            }
            while(Verificar != 27);
        }
    }

    if(x==1)
    {
        while(Verificar == 13)
        {
            Verificar = 13;
            i=0;
            j=0;
            k=0;
            l=0;
            Analise=0;
            Analise2=0;
            Aux = 0;
            Saida = 0;
            Retorno = -1;
            x=0;

            for(j=0; j<40; j++)
            {
                Vet_Nome[j] = (-1);
                RA[j] = (-1);
            }

            if(N_AL > 0 && N_DIS > 0)
            {
                i=0;
                while(Saida == 0 && i<Maximo_Alunos)
                {
                    do
                    {
                        system("cls");

                        Muda_Cor(Cor_Das_Grades);
                        printf("\n    \332\304\304\304");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n    \263");

                        Muda_Cor(Vermelho);
                        printf(" REALIZANDO O CANCELAMENTO DE UM CONJUNTO DE ALUNOS, EM UM");

                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n    \263");

                        Muda_Cor(Vermelho);
                        printf(" CONJUNTO DE DISCIPLINAS PARA UMA DETERMINADA TURMA...");
                        Muda_Cor(Cor_Das_Grades);
                        printf("     \263\n    \300\304\304\304");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");

                        Imprime_Lista_Alunos(TAB_AL, N_AL);

                        Muda_Cor(Verde);
                        printf("\n\n   Digite um ");

                        Muda_Cor(Cor_Das_Grades);
                        printf("RA");

                        Muda_Cor(Verde);
                        printf(" correspondente ao nome de um");

                        Muda_Cor(Cor_Das_Grades);
                        printf(" ALUNO CADASTRADO ");

                        Muda_Cor(Verde);
                        printf("ou\n   Digite <");

                        Muda_Cor(Cor_Das_Grades);
                        printf("-10");

                        Muda_Cor(Verde);
                        printf("> para selecionar TODOS OS ALUNOS CADASTRADOS e\n   pressione");

                        Muda_Cor(Cor_Das_Grades);
                        printf(" ENTER. ");

                        Muda_Cor(Verde);
                        printf(" Quando desejar encerrar o conjunto de\n   ALUNOS digite <");

                        Muda_Cor(Cor_Das_Grades);
                        printf("-1");

                        Muda_Cor(Verde);
                        printf("> e pressione a tecla");

                        Muda_Cor(Cor_Das_Grades);
                        printf(" ENTER: ");

                        fflush(stdin);
                        Muda_Cor(Branco);
                        scanf("%d", &Vet_RA[i]);
                        fflush(stdin);

                        Analise=0;
                        Analise2=0;
                        Saida=0;
                        Aux=0;

                        if(Vet_RA[i] == (-10))
                        {
                            x=10;
                        }

                        if(Vet_RA[i]!=(-1) && x!=10)
                        {
                            for(j=0; j<N_AL; j++)
                            {
                                if(Vet_RA[i] == TAB_AL[j].RA)
                                {
                                    Analise = 1;
                                    Aux = j;
                                }
                            }

                            if(Analise == 0)
                            {
                                Muda_Cor(Cor_Das_Grades);
                                printf("\n \332\304");

                                for(j=0; j<5; j++)
                                    printf("\304\304\304\304\304\304\304\304");

                                printf("\277\n \263");

                                Muda_Cor(Vermelho);
                                printf(" RA NAO CADASTRADO NO SISTEMA ACADEMICO!");
                                Muda_Cor(Cor_Das_Grades);
                                printf(" \263\n \300\304");

                                for(j=0; j<5; j++)
                                    printf("\304\304\304\304\304\304\304\304");

                                printf("\331");
                                Sleep(3000);

                            }
                            else
                            {
                                RA[i] = Aux;

                                if(i!=0)
                                {
                                    for(j=0; j<i; j++)
                                    {
                                        if(RA[i] == RA[j])
                                        {
                                            Analise2=1;
                                        }
                                    }
                                    if(Analise2 == 1)
                                    {
                                        Muda_Cor(Cor_Das_Grades);
                                        printf("\n \332\304");

                                        for(j=0; j<5; j++)
                                            printf("\304\304\304\304\304\304\304\304");

                                        printf("\277\n \263");

                                        Muda_Cor(Vermelho);
                                        printf(" VOCE JA INCLUIU ESTE ALUNO NO CONJUNTO!");
                                        Muda_Cor(Cor_Das_Grades);
                                        printf(" \263\n \300\304");

                                        for(j=0; j<5; j++)
                                            printf("\304\304\304\304\304\304\304\304");

                                        printf("\331");
                                        Sleep(3000);
                                    }

                                }
                            }

                        }

                        if(Vet_RA[i]==(-1))
                        {
                            Saida=1;
                            Analise=1;
                            Analise2=0;
                        }

                        if(x==10)
                        {
                            Analise=1;
                            Analise2=0;
                        }
                    }
                    while(Analise == 0 || Analise2==1);

                    if(Saida == 0 && Analise == 1 && Analise2==0 && x!=10)
                    {
                        system("cls");

                        Muda_Cor(Cor_Das_Grades);
                        printf("\n    \332\304\304\304");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n    \263");

                        Muda_Cor(Vermelho);
                        printf(" REALIZANDO O CANCELAMENTO DE UM CONJUNTO DE ALUNOS, EM UM");

                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n    \263");

                        Muda_Cor(Vermelho);
                        printf(" CONJUNTO DE DISCIPLINAS PARA UMA DETERMINADA TURMA...");
                        Muda_Cor(Cor_Das_Grades);
                        printf("     \263\n    \300\304\304\304");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");


                        printf("\n\n\t       \332\304\304\304\304\304\304\304\304\304\304\304\304\302");

                        for(j=0; j<5; j++)
                            printf("\304\304\304\304");

                        printf("\304\277\n\t       \263");


                        Muda_Cor(Vermelho);
                        printf(" QUANTIDADE ");

                        Muda_Cor(Cor_Das_Grades);
                        printf("\263");

                        Muda_Cor(Vermelho);
                        printf("  RAS SELECIONADOS   ");
                        Muda_Cor(Cor_Das_Grades);
                        printf("\263\n\t       \303\304\304\304\304\304\304\304\304\304\304\304\304\305");

                        for(j=0; j<5; j++)
                            printf("\304\304\304\304");

                        printf("\304\264");

                        i=(i+1);

                        for(j=0; j<i; j++)
                        {
                            printf("\n\t       \263");
                            Muda_Cor(Branco);
                            printf("      %-2d    ", (j+1));
                            Muda_Cor(Cor_Das_Grades);
                            printf("\263");
                            Muda_Cor(Branco);
                            printf("      %-8d", Vet_RA[j]);
                            Muda_Cor(Cor_Das_Grades);
                            printf("       \263\n\t       ");

                            if(j==(i-1))
                            {
                                printf("\300\304\304\304\304\304\304\304\304\304\304\304\304");
                                printf("\301\304\304\304\304\304\304\304\304\304\304\304");
                                printf("\304\304\304\304\304\304\304\304\304\304\331");
                            }
                            else
                            {
                                printf("\303\304\304\304\304\304\304\304\304\304\304\304\304");
                                printf("\305\304\304\304\304\304\304\304\304\304\304\304");
                                printf("\304\304\304\304\304\304\304\304\304\304\264");
                            }
                        }
                        Sleep(1000*i);
                    }
                    if(x==10)
                    {
                        i=0;
                        for(j=0; j<N_AL; j++)
                        {
                            RA[i] = j;
                            i=(i+1);
                        }
                        Muda_Cor(Cor_Das_Grades);
                        printf("\n\n \332");

                        for(j=0; j<6; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n \263");

                        Muda_Cor(Vermelho);
                        printf("    FOI SELECIONADA A OPCAO TODOS OS ALUNOS!");
                        Muda_Cor(Cor_Das_Grades);
                        printf("    \263\n \300");

                        for(j=0; j<6; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");
                        Sleep(3000);

                        Saida=1;
                    }
                }

                if(i>0)
                {
                    Saida=0;

                    k=0;
                    while(Saida == 0 && i<Maximo_Disciplinas)
                    {
                        do
                        {
                            system("cls");
                            Analise = 0;
                            Saida=0;
                            Retorno=(-1);
                            x=0;

                            Muda_Cor(Cor_Das_Grades);
                            printf("\n    \332\304\304\304");

                            for(j=0; j<7; j++)
                                printf("\304\304\304\304\304\304\304\304");

                            printf("\277\n    \263");

                            Muda_Cor(Vermelho);
                            printf(" REALIZANDO O CANCELAMENTO DE UM CONJUNTO DE ALUNOS, EM UM");

                            Muda_Cor(Cor_Das_Grades);
                            printf(" \263\n    \263");

                            Muda_Cor(Vermelho);
                            printf(" CONJUNTO DE DISCIPLINAS PARA UMA DETERMINADA TURMA...");
                            Muda_Cor(Cor_Das_Grades);
                            printf("     \263\n    \300\304\304\304");

                            for(j=0; j<7; j++)
                                printf("\304\304\304\304\304\304\304\304");

                            printf("\331");

                            Imprime_lista_Disciplinas(TAB_DIS, N_DIS);

                            Muda_Cor(Verde);
                            printf("\n\n   Digite um ");

                            Muda_Cor(Cor_Das_Grades);
                            printf("CODIGO COM O TRACO");

                            Muda_Cor(Verde);
                            printf(" correspondente a uma");

                            Muda_Cor(Cor_Das_Grades);
                            printf(" DISCIPLINA\n   CADASTRADA ");

                            Muda_Cor(Verde);
                            printf("ou digite a letra <");

                            Muda_Cor(Cor_Das_Grades);
                            printf("T");

                            Muda_Cor(Verde);
                            printf("> ou <");

                            Muda_Cor(Cor_Das_Grades);
                            printf("t");

                            Muda_Cor(Verde);
                            printf("> para selecionar TODAS\n   AS DISCIPLINAS CADASTRADAS e pressione");

                            Muda_Cor(Cor_Das_Grades);
                            printf(" ENTER.");

                            Muda_Cor(Verde);
                            printf(" Quando desejar\n   encerrar o conjunto de DISCIPLINAS digite a tecla <");

                            Muda_Cor(Cor_Das_Grades);
                            printf("s");

                            Muda_Cor(Verde);
                            printf("> ou <");

                            Muda_Cor(Cor_Das_Grades);
                            printf("S");

                            Muda_Cor(Verde);
                            printf(">\n   e pressione a tecla");

                            Muda_Cor(Cor_Das_Grades);
                            printf(" ENTER: ");

                            fflush(stdin);
                            Muda_Cor(Branco);
                            scanf("%[^\n]", Vet_Aux[k]);
                            fflush(stdin);

                            Saida=0;
                            Analise=0;
                            Analise2=0;
                            Aux=0;

                            if(Vet_Aux[k][0] == 'T' || Vet_Aux[k][0] == 't')
                            {
                                x=10;
                            }

                            if(Vet_Aux[k][0] == 'S' ||  Vet_Aux[k][0] == 's')
                            {
                                Saida=1;
                                Analise=1;
                                Analise2=0;
                            }

                            if(Saida!=1 && x != 10)
                            {
                                for(j=0; j<N_DIS; j++)
                                {
                                    Retorno = strcmp(Vet_Aux[k], TAB_DIS[j].Codigo);
                                    if(Retorno == 0)
                                    {
                                        Analise=1;
                                        Aux=j;
                                    }

                                }

                                if(Analise == 0)
                                {
                                    Muda_Cor(Cor_Das_Grades);
                                    printf("\n \332\304\304\304\304\304");

                                    for(j=0; j<5; j++)
                                        printf("\304\304\304\304\304\304\304\304");

                                    printf("\277\n \263");

                                    Muda_Cor(Vermelho);
                                    printf(" CODIGO NAO CADASTRADO NO SISTEMA ACADEMICO!");
                                    Muda_Cor(Cor_Das_Grades);
                                    printf(" \263\n \300\304\304\304\304\304");

                                    for(j=0; j<5; j++)
                                        printf("\304\304\304\304\304\304\304\304");

                                    printf("\331");
                                    Sleep(3000);
                                }
                                else
                                {
                                    Vet_Nome[k] = Aux;

                                    if(k!=0)
                                    {
                                        for(j=0; j<k; j++)
                                        {
                                            if(Vet_Nome[k] == Vet_Nome[j])
                                            {
                                                Analise2=1;
                                            }
                                        }

                                        if(Analise2 == 1)
                                        {
                                            Muda_Cor(Cor_Das_Grades);
                                            printf("\n \332\304\304\304\304\304\304");

                                            for(j=0; j<5; j++)
                                                printf("\304\304\304\304\304\304\304\304");

                                            printf("\277\n \263");

                                            Muda_Cor(Vermelho);
                                            printf(" VOCE JA INCLUIU ESTA DISCIPLINA NO CONJUNTO!");
                                            Muda_Cor(Cor_Das_Grades);
                                            printf(" \263\n \300\304\304\304\304\304\304");

                                            for(j=0; j<5; j++)
                                                printf("\304\304\304\304\304\304\304\304");

                                            printf("\331");
                                            Sleep(3000);
                                        }
                                    }

                                }
                            }
                            if(x==10)
                            {
                                Analise=1;
                                Analise2=0;
                            }


                        }
                        while(Analise == 0 || Analise2==1);


                        if(Saida == 0 && Analise == 1 && Analise2==0 && x!=10)
                        {
                            system("cls");

                            Muda_Cor(Cor_Das_Grades);
                            printf("\n    \332\304\304\304");

                            for(j=0; j<7; j++)
                                printf("\304\304\304\304\304\304\304\304");

                            printf("\277\n    \263");

                            Muda_Cor(Vermelho);
                            printf(" REALIZANDO O CANCELAMENTO DE UM CONJUNTO DE ALUNOS, EM UM");

                            Muda_Cor(Cor_Das_Grades);
                            printf(" \263\n    \263");

                            Muda_Cor(Vermelho);
                            printf(" CONJUNTO DE DISCIPLINAS PARA UMA DETERMINADA TURMA...");
                            Muda_Cor(Cor_Das_Grades);
                            printf("     \263\n    \300\304\304\304");

                            for(j=0; j<7; j++)
                                printf("\304\304\304\304\304\304\304\304");

                            printf("\331");


                            printf("\n\n\t       \332\304\304\304\304\304\304\304\304\304\304\304\304\302");

                            for(j=0; j<5; j++)
                                printf("\304\304\304\304");

                            printf("\304\304\277\n\t       \263");


                            Muda_Cor(Vermelho);
                            printf(" QUANTIDADE ");

                            Muda_Cor(Cor_Das_Grades);
                            printf("\263");

                            Muda_Cor(Vermelho);
                            printf(" CODIGOS SELECIONADOS ");
                            Muda_Cor(Cor_Das_Grades);
                            printf("\263\n\t       \303\304\304\304\304\304\304\304\304\304\304\304\304\305");

                            for(j=0; j<5; j++)
                                printf("\304\304\304\304");

                            printf("\304\304\264");

                            k=(k+1);

                            for(j=0; j<k; j++)
                            {
                                printf("\n\t       \263");
                                Muda_Cor(Branco);
                                printf("      %-2d    ", (j+1));
                                Muda_Cor(Cor_Das_Grades);
                                printf("\263");
                                Muda_Cor(Branco);
                                printf("      %-9s", Vet_Aux[j]);
                                Muda_Cor(Cor_Das_Grades);
                                printf("       \263\n\t       ");

                                if(j==(k-1))
                                {
                                    printf("\300\304\304\304\304\304\304\304\304\304\304\304\304");
                                    printf("\301\304\304\304\304\304\304\304\304\304\304\304\304");
                                    printf("\304\304\304\304\304\304\304\304\304\304\331");
                                }
                                else
                                {
                                    printf("\303\304\304\304\304\304\304\304\304\304\304\304\304");
                                    printf("\305\304\304\304\304\304\304\304\304\304\304\304\304");
                                    printf("\304\304\304\304\304\304\304\304\304\304\264");
                                }
                            }
                            Sleep(1000*k);
                        }

                        if(x==10)
                        {
                            k=0;
                            for(j=0; j<N_DIS; j++)
                            {
                                Vet_Nome[k] = j;
                                k=(k+1);
                            }
                            Muda_Cor(Cor_Das_Grades);
                            printf("\n\n \332\304");

                            for(j=0; j<6; j++)
                                printf("\304\304\304\304\304\304\304\304");

                            printf("\277\n \263");

                            Muda_Cor(Vermelho);
                            printf("  FOI SELECIONADA A OPCAO TODAS AS DISCIPLINAS!");
                            Muda_Cor(Cor_Das_Grades);
                            printf("  \263\n \300\304");

                            for(j=0; j<6; j++)
                                printf("\304\304\304\304\304\304\304\304");

                            printf("\331");
                            Sleep(3000);

                            Saida=1;
                        }
                    }
                    Teste=0;
                    Aux = 0;
                    j=0;
                    l=0;
                    x=0;

                    for(j=0; j<40; j++)
                    {
                        Aux = (Aux + RA[j]);
                    }

                    if(Aux!=(-40))
                    {
                        Aux=0;
                        m=0;

                        for(j=0; j<40; j++)
                        {
                            Aux = (Aux + Vet_Nome[j]);
                        }

                        if(Aux!=(-40))
                        {
                            Teste=25;
                            for(l=0; l<k; l++)
                            {
                                Aux=(Vet_Nome[l]);

                                m=0;

                                while(m < i)
                                {
                                    x=(-3);

                                    for(j=0; j<15; j++)
                                    {
                                        if(Tabela[Aux].Alunos[j] == RA[m])
                                        {
                                            x=j;
                                        }
                                    }
                                    if(x==(-3))
                                    {
                                        m=(m+1);
                                    }
                                    else
                                    {
                                        Tabela[Aux].Alunos[x] = (-1);
                                        m=(m+1);
                                    }

                                }

                            }
                        }
                    }


                    if(Teste==25)
                    {
                        do
                        {
                            system("cls");

                            Muda_Cor(Cor_Das_Grades);
                            printf("\n    \332");

                            for(j=0; j<7; j++)
                                printf("\304\304\304\304\304\304\304\304");

                            printf("\277\n    \263");

                            Muda_Cor(Vermelho);
                            printf("  CONJUNTO DE ALUNOS CANCELADOS COM SUCESSO, EM UM");

                            Muda_Cor(Cor_Das_Grades);
                            printf("      \263\n    \263");

                            Muda_Cor(Vermelho);
                            printf(" CONJUNTO DE DISCIPLINAS PARA UMA DETERMINADA TURMA...");
                            Muda_Cor(Cor_Das_Grades);
                            printf("  \263\n    \300");

                            for(j=0; j<7; j++)
                                printf("\304\304\304\304\304\304\304\304");

                            printf("\331");

                            fflush(stdin);
                            Muda_Cor(Verde);
                            printf("\n\n     Digite ");
                            Muda_Cor(Cor_Das_Grades);
                            printf("ENTER ");
                            Muda_Cor(Verde);
                            printf("se deseja cadastrar mais ALUNOS\n     no sistema ou ");
                            Muda_Cor(Cor_Das_Grades);
                            printf("ESC ");
                            Muda_Cor(Verde);
                            printf("para retornar ao MENU Inicial: ");
                            Muda_Cor(Branco);

                            Verificar = getch();
                            fflush(stdin);
                        }
                        while(Verificar != 27 && Verificar != 13);
                    }

                    if(Aux==(-40))
                    {
                        do
                        {
                            system("cls");
                            Muda_Cor(Cor_Das_Grades);
                            printf("\n    \332");

                            for(j=0; j<7; j++)
                                printf("\304\304\304\304\304\304\304\304");

                            printf("\277\n    \263");

                            Muda_Cor(Vermelho);
                            printf("  CONJUNTO DE ALUNOS MATRICULADOS SEM SUCESSO, EM UM");

                            Muda_Cor(Cor_Das_Grades);
                            printf("    \263\n    \263");

                            Muda_Cor(Vermelho);
                            printf(" CONJUNTO DE DISCIPLINAS PARA UMA DETERMINADA TURMA...");
                            Muda_Cor(Cor_Das_Grades);
                            printf("  \263\n    \300");

                            for(j=0; j<7; j++)
                                printf("\304\304\304\304\304\304\304\304");

                            printf("\331");

                            fflush(stdin);
                            Muda_Cor(Verde);
                            printf("\n\n     Digite ");
                            Muda_Cor(Cor_Das_Grades);
                            printf("ENTER ");
                            Muda_Cor(Verde);
                            printf("se deseja cadastrar mais ALUNOS\n     no sistema ou ");
                            Muda_Cor(Cor_Das_Grades);
                            printf("ESC ");
                            Muda_Cor(Verde);
                            printf("para retornar ao MENU: ");
                            Muda_Cor(Branco);

                            Verificar = getch();
                            fflush(stdin);
                        }
                        while(Verificar != 27 && Verificar != 13);
                    }
                }
                if(Saida==1 && i==0)
                {
                    Verificar=27;
                }
            }
        }
    }
}
//###############################################################################

//########### FUN��O PARA IMPRIMIR A LISTA DE DISCIPLINAS DE UM ALUNO ###########
void Imprimir_Lista_Disciplinas_De_Aluno(Matriculas Tabela[], Alunos TAB_AL[], Disciplinas TAB_DIS[], int N_AL, int N_DIS) // REQUISITO 11
{
    int i;
    int j;
    int k;
    int RA;
    int teste;
    int Pos;
    int Verificar;
    int Soma;
    int x;

    int Vet[40];

    Soma=0;
    Verificar=13;
    x=0;

    if(N_AL == 0 && N_DIS == 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf(" NENHUM ALUNO E NEM DISCIPLINA CADASTRADA NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf(" \263\n \300\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL");
            printf("\n  e cadastrar alunos ou disciplinas: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_AL == 0 && N_DIS > 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("\t    NENHUM ALUNO CADASTRADO NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf("         \263\n \300\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL e cadastrar alunos: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_DIS == 0 && N_AL > 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("\t  NENHUMA DISCIPLINA CADASTRADA NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf("     \263\n \300\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL e cadastrar disciplinas: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_AL > 0 && N_DIS > 0)
    {
        x=0;

        for(i=0; i<30; i++)
        {
            Soma=0;
            for(j=0; j<15; j++)
            {
                Soma = (Soma+Tabela[i].Alunos[j]);
            }
            if(Soma!=(-15))
            {
                x=1;
            }

        }

        if(x==0)
        {
            do
            {
                system("cls");
                Muda_Cor(Cor_Das_Grades);
                printf("\n \332\304\304\304\304\304\304\304");

                for(j=0; j<6; j++)
                    printf("\304\304\304\304\304\304\304\304");

                printf("\277\n \263");

                Muda_Cor(Vermelho);
                printf("\t   NENHUM ALUNO MATRICULADO NO MOMENTO! ");

                Muda_Cor(Cor_Das_Grades);
                printf("         \263\n \300\304\304\304\304\304\304\304");

                for(j=0; j<6; j++)
                    printf("\304\304\304\304\304\304\304\304");

                printf("\331");

                fflush(stdin);
                Muda_Cor(Verde);
                printf("\n\n  Digite ");
                Muda_Cor(Cor_Das_Grades);
                printf("ESC ");
                Muda_Cor(Verde);
                printf("para retornar ao MENU INICIAL e cadastrar disciplinas: ");
                Muda_Cor(Branco);
                Verificar = getch();
                fflush(stdin);
            }
            while(Verificar != 27);
        }
    }

    while(Verificar == 13)
    {
        Verificar = 13;

        for(j=0; j<40; j++)
        {
            Vet[j] = (-1);
        }


        if(N_AL > 0 && N_DIS > 0 && x==1)
        {
            do
            {
                system("cls");
                Imprime_Lista_Alunos (TAB_AL, N_AL);

                i=0;
                j=0;
                k=0;
                RA=0;


                fflush(stdin);
                Muda_Cor(Verde);
                printf("\n\n\n   Digite o");
                Muda_Cor(Cor_Das_Grades);
                printf(" RA ");
                Muda_Cor(Verde);
                printf("de um");
                Muda_Cor(Cor_Das_Grades);
                printf(" ALUNO CADASTRADO ");
                Muda_Cor(Verde);
                printf("e pressione");
                Muda_Cor(Cor_Das_Grades);
                printf(" ENTER ");
                Muda_Cor(Verde);
                printf("para\n   visualizar todas as DISCIPLINAS que esse ALUNO esta\n   matriculado ou <");
                Muda_Cor(Cor_Das_Grades);
                printf("-1");
                Muda_Cor(Verde);
                printf("> para retornar ao MENU INICIAL: ");
                Muda_Cor(Branco);
                scanf("%d", &RA);
                fflush(stdin);

                if(RA != (-1))
                {

                    teste=0;

                    if(N_AL!=0)
                    {
                        for(j=0; j<N_AL; j++)
                        {
                            if(TAB_AL[j].RA == RA)
                            {
                                teste=1;
                                Pos=j;
                            }
                        }
                    }

                    if(teste==0)
                    {
                        Muda_Cor(Cor_Das_Grades);
                        printf("\n \332\304");

                        for(j=0; j<5; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n \263");

                        Muda_Cor(Vermelho);
                        printf(" RA NAO CADASTRADO NO SISTEMA ACADEMICO!");
                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n \300\304");

                        for(j=0; j<5; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");
                        Sleep(3000);
                    }

                    k=0;

                    for(i=0; i<30; i++)
                    {
                        for(j=0; j<15; j++)
                        {
                            if(Tabela[i].Alunos[j] == Pos)
                            {
                                Vet[k]=i;
                                k=(k+1);
                                j=14;
                            }
                        }
                    }

                    if(k==0 && teste==1)
                    {
                        Muda_Cor(Cor_Das_Grades);
                        printf("\n \332\304\304\304\304");

                        for(j=0; j<9; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n \263");

                        Muda_Cor(Vermelho);
                        printf(" O ALUNO selecionado nao esta matriculado em nenhuma disicplina no momento!");
                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n \300\304\304\304\304");

                        for(j=0; j<9; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");
                        Sleep(3000);
                    }
                }
                else
                {
                    teste=1;
                    k=1;
                }
            }
            while(teste==0 || k==0);

            if(RA!=(-1))
            {
                do
                {
                    system("cls");
                    Muda_Cor(Cor_Das_Grades);
                    printf("\n\n \332");

                    for(i=0; i<4; i++)
                        printf("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304");

                    printf("\277\n \263");
                    Muda_Cor(Vermelho);
                    printf("   LISTA DE TODOS AS DISCIPLINAS CADASTRADAS DO(A) ALUNO(A):");
                    Muda_Cor(Cor_Das_Grades);

                    printf("\t  \263\n \303");

                    for(i=0; i<4; i++)
                        printf("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304");

                    printf("\264\n \263");

                    Muda_Cor(Branco);
                    printf("       %-50s", TAB_AL[Pos].Nomes);

                    Muda_Cor(Cor_Das_Grades);
                    printf("\t  \263\n \303");
                    for(i=0; i<16; i++)
                        printf("\304\304\304\304");

                    Muda_Cor(Cor_Das_Grades);
                    printf("\264\n \263\t\t\t\t\t\t\t\t  \263\n \303\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\302");

                    for(i=0; i<13; i++)
                        printf("\304\304\304\304");

                    printf("\264\n \263");

                    Muda_Cor(Vermelho);
                    printf("  CODIGO   ");

                    Muda_Cor(Cor_Das_Grades);
                    printf("\263");

                    Muda_Cor(Vermelho);
                    printf("\t\t    DISCIPLINAS CADASTRADAS\t\t");
                    Muda_Cor(Cor_Das_Grades);
                    printf("  \263\n \303\304\304\304\304\304\304\304\304\304\304\304\305");

                    for(i=0; i<13; i++)
                        printf("\304\304\304\304");

                    printf("\264");

                    for(i=0; i<k; i++)
                    {
                        printf("\n \263");
                        Muda_Cor(Branco);
                        printf(" %-9s ", TAB_DIS[Vet[i]].Codigo);
                        Muda_Cor(Cor_Das_Grades);
                        printf("\263");
                        Muda_Cor(Branco);
                        printf(" %-50s", TAB_DIS[Vet[i]].Nome);
                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n");

                        if(i==(k-1))
                        {
                            printf(" \300\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\301\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\331");
                        }
                        else
                        {
                            printf(" \303\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\305\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\264");
                        }
                    }

                    fflush(stdin);
                    Muda_Cor(Verde);
                    printf("\n\n     Digite ");
                    Muda_Cor(Cor_Das_Grades);
                    printf("ENTER ");
                    Muda_Cor(Verde);
                    printf("se deseja imprimir outra lista de disciplinas\n     de um aluno ou ");
                    Muda_Cor(Cor_Das_Grades);
                    printf("ESC ");
                    Muda_Cor(Verde);
                    printf("para retornar ao MENU: ");
                    Muda_Cor(Branco);

                    Verificar = getch();
                    fflush(stdin);
                }
                while(Verificar != 27 && Verificar != 13);
            }
            else
            {
                Verificar=27;
            }
        }
    }
}
//###############################################################################

//####### FUN��O PARA IMPRIMIR A LISTA DE ALUNOS EM UMA DISCIPLINA E TURMA #######
void Imprimir_Lista_Alunos_De_Disciplina_Turma(Matriculas Tabela[], Alunos TAB_AL[], Disciplinas TAB_DIS[], int N_AL, int N_DIS) // REQUISITO 12
{
    int i;
    int j;
    int k;
    int teste;
    int Pos;
    int Verificar;
    int Soma;
    int x;
    int Saida;
    int Retorno;

    char COD[10];

    int Vet[40];

    Soma=0;
    Verificar=13;
    x=0;
    Retorno=(-1);

    if(N_AL == 0 && N_DIS == 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf(" NENHUM ALUNO E NEM DISCIPLINA CADASTRADA NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf(" \263\n \300\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL");
            printf("\n  e cadastrar alunos ou disciplinas: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_AL == 0 && N_DIS > 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("\t    NENHUM ALUNO CADASTRADO NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf("         \263\n \300\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL e cadastrar alunos: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_DIS == 0 && N_AL > 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("\t  NENHUMA DISCIPLINA CADASTRADA NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf("     \263\n \300\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL e cadastrar disciplinas: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_AL > 0 && N_DIS > 0)
    {
        x=0;

        for(i=0; i<30; i++)
        {
            Soma=0;
            for(j=0; j<15; j++)
            {
                Soma = (Soma+Tabela[i].Alunos[j]);
            }
            if(Soma!=(-15))
            {
                x=1;
            }

        }

        if(x==0)
        {
            do
            {
                system("cls");
                Muda_Cor(Cor_Das_Grades);
                printf("\n \332\304\304\304\304\304\304\304");

                for(j=0; j<6; j++)
                    printf("\304\304\304\304\304\304\304\304");

                printf("\277\n \263");

                Muda_Cor(Vermelho);
                printf("\t   NENHUM ALUNO MATRICULADO NO MOMENTO! ");

                Muda_Cor(Cor_Das_Grades);
                printf("         \263\n \300\304\304\304\304\304\304\304");

                for(j=0; j<6; j++)
                    printf("\304\304\304\304\304\304\304\304");

                printf("\331");

                fflush(stdin);
                Muda_Cor(Verde);
                printf("\n\n  Digite ");
                Muda_Cor(Cor_Das_Grades);
                printf("ESC ");
                Muda_Cor(Verde);
                printf("para retornar ao MENU INICIAL e cadastrar disciplinas: ");
                Muda_Cor(Branco);
                Verificar = getch();
                fflush(stdin);
            }
            while(Verificar != 27);
        }
    }

    while(Verificar == 13)
    {
        Verificar = 13;
        Saida=0;

        for(j=0; j<40; j++)
        {
            Vet[j] = (-1);
        }


        if(N_AL > 0 && N_DIS > 0 && x==1)
        {
            do
            {
                system("cls");
                Imprime_lista_Disciplinas(TAB_DIS, N_DIS);

                i=0;
                j=0;
                k=0;
                Saida=0;


                fflush(stdin);
                Muda_Cor(Verde);
                printf("\n\n\n   Digite o");
                Muda_Cor(Cor_Das_Grades);
                printf(" CODIGO ");
                Muda_Cor(Verde);
                printf("de uma");
                Muda_Cor(Cor_Das_Grades);
                printf(" DISCIPLINA CADASTRADA ");
                Muda_Cor(Verde);
                printf("e pressione");
                Muda_Cor(Cor_Das_Grades);
                printf(" ENTER ");
                Muda_Cor(Verde);
                printf("\n   para visualizar todas os ALUNOS matriculados nesta DISCIPLINA\n   e TURMA ou <");
                Muda_Cor(Cor_Das_Grades);
                printf("S");
                Muda_Cor(Verde);
                printf("> ou <");
                Muda_Cor(Cor_Das_Grades);
                printf("s");
                Muda_Cor(Verde);
                printf("> para retornar ao MENU INICIAL: ");
                fflush(stdin);
                Muda_Cor(Branco);
                scanf("%[^\n]", COD);
                fflush(stdin);


                if(COD[0] == 'S' ||  COD[0] == 's')
                {
                    Saida=1;
                }

                if(Saida != 1)
                {
                    teste=0;

                    if(N_DIS!=0)
                    {
                        Retorno=-1;

                        for(j=0; j<N_DIS; j++)

                        {
                            Retorno = strcmp(TAB_DIS[j].Codigo, COD);

                            if(Retorno == 0)
                            {
                                teste=1;
                                Pos=j;
                            }
                        }
                    }

                    if(teste==0)
                    {
                        Muda_Cor(Cor_Das_Grades);
                        printf("\n \332\304\304\304\304\304");

                        for(j=0; j<5; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n \263");

                        Muda_Cor(Vermelho);
                        printf(" CODIGO NAO CADASTRADO NO SISTEMA ACADEMICO!");
                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n \300\304\304\304\304\304");

                        for(j=0; j<5; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");
                        Sleep(3000);
                    }

                    k=0;

                    for(j=0; j<15; j++)
                    {
                        if(Tabela[Pos].Alunos[j] != (-1))
                        {
                            Vet[k]=Tabela[Pos].Alunos[j];
                            k=(k+1);
                        }
                    }

                    if(k==0 && teste==1)
                    {
                        Muda_Cor(Cor_Das_Grades);
                        printf("\n \332\304\304\304\304");

                        for(j=0; j<8; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n \263");

                        Muda_Cor(Vermelho);
                        printf(" A DISCIPLINA selecionada nao contem nenhum aluno matriculado nela!");
                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n \300\304\304\304\304");

                        for(j=0; j<8; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");
                        Sleep(3000);
                    }
                }
                else
                {
                    teste=1;
                    k=1;
                }
            }
            while(teste==0 || k==0);

            if(Saida!=1)
            {
                do
                {
                    system("cls");
                    Muda_Cor(Cor_Das_Grades);
                    printf("\n\n \332\304\304\304\304\304\304\304");

                    for(i=0; i<7; i++)
                        printf("\304\304\304\304\304\304\304\304");

                    printf("\277\n \263");
                    Muda_Cor(Vermelho);
                    printf("      LISTA DE TODOS OS ALUNOS CADASTRADOS NA DISCIPLINA:");
                    Muda_Cor(Cor_Das_Grades);

                    printf("\t \263\n \303\304\304\304\304\304\304\304");

                    for(i=0; i<7; i++)
                        printf("\304\304\304\304\304\304\304\304");

                    printf("\264\n \263");

                    Muda_Cor(Branco);
                    printf("      %-50s", TAB_DIS[Pos].Nome);

                    Muda_Cor(Cor_Das_Grades);
                    printf("\t \263\n \303\304\304\304\304\304\304\304");
                    for(i=0; i<7; i++)
                        printf("\304\304\304\304\304\304\304\304");

                    Muda_Cor(Cor_Das_Grades);
                    printf("\264\n \263\t\t\t\t\t\t\t\t \263\n \303\304");
                    printf("\304\304\304\304\304\304\304\304\304\302");

                    for(i=0; i<13; i++)
                        printf("\304\304\304\304");

                    printf("\264\n \263");

                    Muda_Cor(Vermelho);
                    printf("    RA    ");

                    Muda_Cor(Cor_Das_Grades);
                    printf("\263");

                    Muda_Cor(Vermelho);
                    printf("\t\t      ALUNOS CADASTRADOS\t\t");
                    Muda_Cor(Cor_Das_Grades);
                    printf(" \263\n \303\304\304\304\304\304\304\304\304\304\304\305");

                    for(i=0; i<13; i++)
                        printf("\304\304\304\304");

                    printf("\264");

                    for(i=0; i<k; i++)
                    {
                        printf("\n \263");
                        Muda_Cor(Branco);
                        printf(" %-8d ", TAB_AL[Vet[i]].RA);
                        Muda_Cor(Cor_Das_Grades);
                        printf("\263");
                        Muda_Cor(Branco);
                        printf(" %-50s", TAB_AL[Vet[i]].Nomes);
                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n");

                        if(i==(k-1))
                        {
                            printf(" \300\304\304\304\304\304\304\304\304\304");
                            printf("\304\301\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\331");
                        }
                        else
                        {
                            printf(" \303\304\304\304\304\304\304\304\304\304");
                            printf("\304\305\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\264");
                        }
                    }

                    fflush(stdin);
                    Muda_Cor(Verde);
                    printf("\n\n     Digite ");
                    Muda_Cor(Cor_Das_Grades);
                    printf("ENTER ");
                    Muda_Cor(Verde);
                    printf("se deseja imprimir outra lista de disciplinas\n     de um aluno ou ");
                    Muda_Cor(Cor_Das_Grades);
                    printf("ESC ");
                    Muda_Cor(Verde);
                    printf("para retornar ao MENU: ");
                    Muda_Cor(Branco);

                    Verificar = getch();
                    fflush(stdin);
                }
                while(Verificar != 27 && Verificar != 13);
            }
            else
            {
                Verificar=27;
            }
        }
    }
}
//###############################################################################

// FUN��O PARA IMPRIMIR A LISTA DE ALUNOS EM UMA DISCIPLINA INDEPENDENTE DA TURMA
void Imprimir_Lista_Alunos_De_Disciplina(Matriculas Tabela[], Alunos TAB_AL[], Disciplinas TAB_DIS[], int N_AL, int N_DIS, Disciplinas_Sem_Turma TAB_DIS_S_TURMA[]) // REQUISITO 13
{
    int i;
    int j;
    int k;
    int teste;
    int Pos;
    int Verificar;
    int Soma;
    int x;
    int Saida;
    int Retorno;
    int N;

    char COD[10];

    int Vet[40];

    Soma=0;
    Verificar=13;
    x=0;
    Retorno=(-1);

    if(N_AL == 0 && N_DIS == 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf(" NENHUM ALUNO E NEM DISCIPLINA CADASTRADA NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf(" \263\n \300\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL");
            printf("\n  e cadastrar alunos ou disciplinas: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_AL == 0 && N_DIS > 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("\t    NENHUM ALUNO CADASTRADO NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf("         \263\n \300\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL e cadastrar alunos: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_DIS == 0 && N_AL > 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("\t  NENHUMA DISCIPLINA CADASTRADA NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf("     \263\n \300\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL e cadastrar disciplinas: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_AL > 0 && N_DIS > 0)
    {
        x=0;

        for(i=0; i<30; i++)
        {
            Soma=0;
            for(j=0; j<15; j++)
            {
                Soma = (Soma+Tabela[i].Alunos[j]);
            }
            if(Soma!=(-15))
            {
                x=1;
            }

        }

        if(x==0)
        {
            do
            {
                system("cls");
                Muda_Cor(Cor_Das_Grades);
                printf("\n \332\304\304\304\304\304\304\304");

                for(j=0; j<6; j++)
                    printf("\304\304\304\304\304\304\304\304");

                printf("\277\n \263");

                Muda_Cor(Vermelho);
                printf("\t   NENHUM ALUNO MATRICULADO NO MOMENTO! ");

                Muda_Cor(Cor_Das_Grades);
                printf("         \263\n \300\304\304\304\304\304\304\304");

                for(j=0; j<6; j++)
                    printf("\304\304\304\304\304\304\304\304");

                printf("\331");

                fflush(stdin);
                Muda_Cor(Verde);
                printf("\n\n  Digite ");
                Muda_Cor(Cor_Das_Grades);
                printf("ESC ");
                Muda_Cor(Verde);
                printf("para retornar ao MENU INICIAL e cadastrar disciplinas: ");
                Muda_Cor(Branco);
                Verificar = getch();
                fflush(stdin);
            }
            while(Verificar != 27);
        }
    }

    while(Verificar == 13)
    {
        Verificar = 13;
        Saida=0;

        for(j=0; j<40; j++)
        {
            Vet[j] = (-1);
        }

        if(N_AL > 0 && N_DIS > 0 && x==1)
        {
            do
            {
                system("cls");
                Imprime_lista_Disciplinas_Independente_da_Turma (TAB_DIS, TAB_DIS_S_TURMA, N_DIS);

                i=0;
                j=0;
                k=0;
                Saida=0;


                fflush(stdin);
                Muda_Cor(Verde);
                printf("\n\n\n   Digite o");
                Muda_Cor(Cor_Das_Grades);
                printf(" CODIGO ");
                Muda_Cor(Verde);
                printf("de uma");
                Muda_Cor(Cor_Das_Grades);
                printf(" DISCIPLINA CADASTRADA ");
                Muda_Cor(Verde);
                printf("e pressione");
                Muda_Cor(Cor_Das_Grades);
                printf(" ENTER ");
                Muda_Cor(Verde);
                printf("\n   para visualizar todas os ALUNOS matriculados nesta DISCIPLINA\n   ou <");
                Muda_Cor(Cor_Das_Grades);
                printf("S");
                Muda_Cor(Verde);
                printf("> ou <");
                Muda_Cor(Cor_Das_Grades);
                printf("s");
                Muda_Cor(Verde);
                printf("> para retornar ao MENU INICIAL: ");
                fflush(stdin);
                Muda_Cor(Branco);
                scanf("%[^\n]", COD);
                fflush(stdin);


                if(COD[0] == 'S' ||  COD[0] == 's')
                {
                    Saida=1;
                }

                if(Saida != 1)
                {
                    teste=0;
                    N=N_DIS;
                    N=(N/2);

                    if(N!=0)
                    {
                        Retorno=-1;

                        for(j=0; j<N; j++)

                        {
                            Retorno = strcmp(TAB_DIS_S_TURMA[j].Codigo2, COD);

                            if(Retorno == 0)
                            {
                                teste=1;
                                Pos=j;
                            }
                        }
                    }

                    if(teste==0)
                    {
                        Muda_Cor(Cor_Das_Grades);
                        printf("\n \332\304\304\304\304\304");

                        for(j=0; j<5; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n \263");

                        Muda_Cor(Vermelho);
                        printf(" CODIGO NAO CADASTRADO NO SISTEMA ACADEMICO!");
                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n \300\304\304\304\304\304");

                        for(j=0; j<5; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");
                        Sleep(3000);
                    }

                    k=0;
                    Pos=(Pos*2);

                    for(j=0; j<15; j++)
                    {
                        if(Tabela[Pos].Alunos[j] != (-1))
                        {
                            Vet[k]=Tabela[Pos].Alunos[j];
                            k=(k+1);
                        }
                    }

                    for(j=0; j<15; j++)
                    {
                        if(Tabela[(Pos+1)].Alunos[j] != (-1))
                        {
                            Vet[k]=Tabela[(Pos+1)].Alunos[j];
                            k=(k+1);
                        }
                    }

                    Pos=(Pos/2);

                    if(k==0 && teste==1)
                    {
                        Muda_Cor(Cor_Das_Grades);
                        printf("\n \332\304\304\304\304");

                        for(j=0; j<8; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n \263");

                        Muda_Cor(Vermelho);
                        printf(" A DISCIPLINA selecionada nao contem nenhum aluno matriculado nela!");
                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n \300\304\304\304\304");

                        for(j=0; j<8; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");
                        Sleep(3000);
                    }
                }
                else
                {
                    teste=1;
                    k=1;
                }
            }
            while(teste==0 || k==0);

            if(Saida!=1)
            {
                do
                {
                    system("cls");
                    Muda_Cor(Cor_Das_Grades);
                    printf("\n\n \332\304\304\304\304\304\304\304");

                    for(i=0; i<7; i++)
                        printf("\304\304\304\304\304\304\304\304");

                    printf("\277\n \263");
                    Muda_Cor(Vermelho);
                    printf("      LISTA DE TODOS OS ALUNOS CADASTRADOS NA DISCIPLINA:");
                    Muda_Cor(Cor_Das_Grades);

                    printf("\t \263\n \303\304\304\304\304\304\304\304");

                    for(i=0; i<7; i++)
                        printf("\304\304\304\304\304\304\304\304");

                    printf("\264\n \263");

                    Muda_Cor(Branco);
                    printf("      %-50s", TAB_DIS_S_TURMA[Pos].Nome2);

                    Muda_Cor(Cor_Das_Grades);
                    printf("\t \263\n \303\304\304\304\304\304\304\304");
                    for(i=0; i<7; i++)
                        printf("\304\304\304\304\304\304\304\304");

                    Muda_Cor(Cor_Das_Grades);
                    printf("\264\n \263\t\t\t\t\t\t\t\t \263\n \303\304");
                    printf("\304\304\304\304\304\304\304\304\304\302");

                    for(i=0; i<13; i++)
                        printf("\304\304\304\304");

                    printf("\264\n \263");

                    Muda_Cor(Vermelho);
                    printf("    RA    ");

                    Muda_Cor(Cor_Das_Grades);
                    printf("\263");

                    Muda_Cor(Vermelho);
                    printf("\t\t      ALUNOS CADASTRADOS\t\t");
                    Muda_Cor(Cor_Das_Grades);
                    printf(" \263\n \303\304\304\304\304\304\304\304\304\304\304\305");

                    for(i=0; i<13; i++)
                        printf("\304\304\304\304");

                    printf("\264");

                    for(i=0; i<k; i++)
                    {
                        printf("\n \263");
                        Muda_Cor(Branco);
                        printf(" %-8d ", TAB_AL[Vet[i]].RA);
                        Muda_Cor(Cor_Das_Grades);
                        printf("\263");
                        Muda_Cor(Branco);
                        printf(" %-50s", TAB_AL[Vet[i]].Nomes);
                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n");

                        if(i==(k-1))
                        {
                            printf(" \300\304\304\304\304\304\304\304\304\304");
                            printf("\304\301\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\331");
                        }
                        else
                        {
                            printf(" \303\304\304\304\304\304\304\304\304\304");
                            printf("\304\305\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\264");
                        }
                    }

                    fflush(stdin);
                    Muda_Cor(Verde);
                    printf("\n\n     Digite ");
                    Muda_Cor(Cor_Das_Grades);
                    printf("ENTER ");
                    Muda_Cor(Verde);
                    printf("se deseja imprimir outra lista de disciplinas\n     de um aluno ou ");
                    Muda_Cor(Cor_Das_Grades);
                    printf("ESC ");
                    Muda_Cor(Verde);
                    printf("para retornar ao MENU: ");
                    Muda_Cor(Branco);

                    Verificar = getch();
                    fflush(stdin);
                }
                while(Verificar != 27 && Verificar != 13);
            }
            else
            {
                Verificar=27;
            }
        }
    }
}
//###############################################################################


// FUN��O PARA REALIZAR OS PROCEDIMENTOS DE VINCULA��O DOS PROFESSORES NAS DEVIDAS DISCIPLINAS
void Vincular_Professores (Professores TAB_PROF[], Disciplinas TAB_DIS[], Matriculas Tabela[], int N_PROF, int N_DIS) // REQUISITO 6
{
    int i;
    int j;
    int k;
    int l;
    int x;
    int Vet_RP[40];
    int RP[40];
    int Vet_Nome[40];
    char Vet_Aux[40][10];

    int Analise;
    int Analise2;
    int Aux;
    int Saida;
    int Retorno;
    int Teste;

    int Verificar;

    Verificar = 13;
    i=0;
    j=0;
    k=0;
    l=0;
    Analise=0;
    Analise2=0;
    Aux = 0;
    Saida = 0;
    Retorno = -1;
    x=0;
    Teste=0;

    if(N_PROF == 0 && N_DIS == 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("  NENHUM PROFESSOR E NEM DISCIPLINA CADASTRADOS NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf(" \263\n \300\304\304\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL");
            printf("\n  e cadastrar professores ou disciplinas: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_PROF == 0 && N_DIS > 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("\t    NENHUM PROFESSOR CADASTRADO NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf("         \263\n \300\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL e cadastrar professores: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_DIS == 0 && N_PROF > 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("\t  NENHUMA DISCIPLINA CADASTRADA NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf("     \263\n \300\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL e cadastrar disciplinas: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    Saida = 0;

    while(Verificar == 13)
    {
        i=0;
        j=0;
        k=0;
        l=0;
        Analise=0;
        Analise2=0;
        Aux = 0;
        Retorno = -1;
        Verificar = 13;
        Saida = 0;
        x=0;

        for(j=0; j<40; j++)
        {
            Vet_Nome[j] = (-1);
            RP[j] = (-1);
        }

        if(N_PROF > 0 && N_DIS > 0)
        {
            i=0;
            while(Saida == 0 && i<Maximo_Professores)
            {
                do
                {
                    system("cls");
                    Analise = 0;
                    Analise2=0;
                    Saida=0;

                    Muda_Cor(Cor_Das_Grades);
                    printf("\n  \332\304\304\304\304\304");

                    for(j=0; j<7; j++)
                        printf("\304\304\304\304\304\304\304\304");

                    printf("\277\n  \263");

                    Muda_Cor(Vermelho);
                    printf(" REALIZANDO O VINCULAMENTO DE UM CONJUNTO DE PROFESSORES, EM");

                    Muda_Cor(Cor_Das_Grades);
                    printf(" \263\n  \263");

                    Muda_Cor(Vermelho);
                    printf(" UM CONJUNTO DE DISCIPLINAS PARA UMA DETERMINADA TURMA...");
                    Muda_Cor(Cor_Das_Grades);
                    printf("    \263\n  \300\304\304\304\304\304");

                    for(j=0; j<7; j++)
                        printf("\304\304\304\304\304\304\304\304");

                    printf("\331");

                    Imprime_Lista_Professores(TAB_PROF, N_PROF);

                    Muda_Cor(Verde);
                    printf("\n\n   Digite um ");

                    Muda_Cor(Cor_Das_Grades);
                    printf("RP");

                    Muda_Cor(Verde);
                    printf(" correspondente ao nome de um");

                    Muda_Cor(Cor_Das_Grades);
                    printf(" PROFESSOR CADASTRADO ");

                    Muda_Cor(Verde);
                    printf("ou\n   Digite <");

                    Muda_Cor(Cor_Das_Grades);
                    printf("-10");

                    Muda_Cor(Verde);
                    printf("> para selecionar TODOS OS PROFESSORES CADASTRADOS e\n   pressione");

                    Muda_Cor(Cor_Das_Grades);
                    printf(" ENTER. ");

                    Muda_Cor(Verde);
                    printf(" Quando desejar encerrar o conjunto de\n   PROFESSORES digite <");

                    Muda_Cor(Cor_Das_Grades);
                    printf("-1");

                    Muda_Cor(Verde);
                    printf("> e pressione a tecla");

                    Muda_Cor(Cor_Das_Grades);
                    printf(" ENTER: ");

                    fflush(stdin);
                    Muda_Cor(Branco);
                    scanf("%d", &Vet_RP[i]);
                    fflush(stdin);

                    Analise=0;
                    Analise2=0;
                    Saida=0;
                    Aux=0;
                    x=0;

                    if(Vet_RP[i] == (-10))
                    {
                        x=10;
                    }

                    if(Vet_RP[i]!=(-1) && x!=10)
                    {
                        for(j=0; j<N_PROF; j++)
                        {
                            if(Vet_RP[i] == TAB_PROF[j].RP)
                            {
                                Analise = 1;
                                Aux = j;
                            }
                        }

                        if(Analise == 0)
                        {
                            Muda_Cor(Cor_Das_Grades);
                            printf("\n \332\304");

                            for(j=0; j<5; j++)
                                printf("\304\304\304\304\304\304\304\304");

                            printf("\277\n \263");

                            Muda_Cor(Vermelho);
                            printf(" RP NAO CADASTRADO NO SISTEMA ACADEMICO!");
                            Muda_Cor(Cor_Das_Grades);
                            printf(" \263\n \300\304");

                            for(j=0; j<5; j++)
                                printf("\304\304\304\304\304\304\304\304");

                            printf("\331");
                            Sleep(3000);
                        }
                        else
                        {
                            RP[i] = Aux;

                            if(i!=0)
                            {
                                for(j=0; j<i; j++)
                                {
                                    if(RP[i] == RP[j])
                                    {
                                        Analise2=1;
                                    }
                                }
                                if(Analise2 == 1)
                                {
                                    Muda_Cor(Cor_Das_Grades);
                                    printf("\n \332\304\304\304\304\304");

                                    for(j=0; j<5; j++)
                                        printf("\304\304\304\304\304\304\304\304");

                                    printf("\277\n \263");

                                    Muda_Cor(Vermelho);
                                    printf(" VOCE JA INCLUIU ESTE PROFESSOR NO CONJUNTO!");
                                    Muda_Cor(Cor_Das_Grades);
                                    printf(" \263\n \300\304\304\304\304\304");

                                    for(j=0; j<5; j++)
                                        printf("\304\304\304\304\304\304\304\304");

                                    printf("\331");
                                    Sleep(3000);
                                }

                            }
                        }
                    }

                    if(Vet_RP[i]==(-1))
                    {
                        Saida=1;
                        Analise=1;
                        Analise2=0;
                    }

                    if(x==10)
                    {
                        Analise=1;
                        Analise2=0;
                    }

                }
                while(Analise==0 || Analise2==1);


                if(Saida == 0 && Analise == 1 && Analise2==0 && x!=10)
                {

                    system("cls");

                    Muda_Cor(Cor_Das_Grades);
                    printf("\n  \332\304\304\304\304\304");

                    for(j=0; j<7; j++)
                        printf("\304\304\304\304\304\304\304\304");

                    printf("\277\n  \263");

                    Muda_Cor(Vermelho);
                    printf(" REALIZANDO O VINCULAMENTO DE UM CONJUNTO DE PROFESSORES, EM");

                    Muda_Cor(Cor_Das_Grades);
                    printf(" \263\n  \263");

                    Muda_Cor(Vermelho);
                    printf(" UM CONJUNTO DE DISCIPLINAS PARA UMA DETERMINADA TURMA...");
                    Muda_Cor(Cor_Das_Grades);
                    printf("\t\263\n  \300\304\304\304\304\304");

                    for(j=0; j<7; j++)
                        printf("\304\304\304\304\304\304\304\304");

                    printf("\331");


                    printf("\n\n\t       \332\304\304\304\304\304\304\304\304\304\304\304\304\302");

                    for(j=0; j<5; j++)
                        printf("\304\304\304\304");

                    printf("\304\277\n\t       \263");


                    Muda_Cor(Vermelho);
                    printf(" QUANTIDADE ");

                    Muda_Cor(Cor_Das_Grades);
                    printf("\263");

                    Muda_Cor(Vermelho);
                    printf("  RPS SELECIONADOS   ");
                    Muda_Cor(Cor_Das_Grades);
                    printf("\263\n\t       \303\304\304\304\304\304\304\304\304\304\304\304\304\305");

                    for(j=0; j<5; j++)
                        printf("\304\304\304\304");

                    printf("\304\264");

                    i=(i+1);

                    for(j=0; j<i; j++)
                    {
                        printf("\n\t       \263");
                        Muda_Cor(Branco);
                        printf("      %-2d    ", (j+1));
                        Muda_Cor(Cor_Das_Grades);
                        printf("\263");
                        Muda_Cor(Branco);
                        printf("      %-8d", Vet_RP[j]);
                        Muda_Cor(Cor_Das_Grades);
                        printf("       \263\n\t       ");

                        if(j==(i-1))
                        {
                            printf("\300\304\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\301\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\331");
                        }
                        else
                        {
                            printf("\303\304\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\305\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\264");
                        }
                    }
                    Sleep(1000*i);
                }

                if(x==10)
                {
                    i=0;
                    for(j=0; j<N_PROF; j++)
                    {
                        RP[i] = j;
                        i=(i+1);
                    }

                    Muda_Cor(Cor_Das_Grades);
                    printf("\n\n \332");

                    for(j=0; j<6; j++)
                        printf("\304\304\304\304\304\304\304\304");

                    printf("\277\n \263");

                    Muda_Cor(Vermelho);
                    printf("  FOI SELECIONADA A OPCAO TODOS OS PROFESSORES!");
                    Muda_Cor(Cor_Das_Grades);
                    printf(" \263\n \300");

                    for(j=0; j<6; j++)
                        printf("\304\304\304\304\304\304\304\304");

                    printf("\331");
                    Sleep(3000);

                    Saida=1;
                }
            }

            if(i>0)
            {
                Saida=0;

                k=0;
                while(Saida == 0 && i<Maximo_Disciplinas)
                {
                    do
                    {
                        system("cls");

                        Muda_Cor(Cor_Das_Grades);
                        printf("\n  \332\304\304\304\304\304");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n  \263");

                        Muda_Cor(Vermelho);
                        printf(" REALIZANDO O VINCULAMENTO DE UM CONJUNTO DE PROFESSORES, EM");

                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n  \263");

                        Muda_Cor(Vermelho);
                        printf(" UM CONJUNTO DE DISCIPLINAS PARA UMA DETERMINADA TURMA...");
                        Muda_Cor(Cor_Das_Grades);
                        printf("\t\263\n  \300\304\304\304\304\304");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");

                        Imprime_lista_Disciplinas(TAB_DIS, N_DIS);

                        Muda_Cor(Verde);
                        printf("\n\n   Digite um ");

                        Muda_Cor(Cor_Das_Grades);
                        printf("CODIGO COM O TRACO");

                        Muda_Cor(Verde);
                        printf(" correspondente a uma");

                        Muda_Cor(Cor_Das_Grades);
                        printf(" DISCIPLINA\n   CADASTRADA ");

                        Muda_Cor(Verde);
                        printf("ou digite a letra <");

                        Muda_Cor(Cor_Das_Grades);
                        printf("T");

                        Muda_Cor(Verde);
                        printf("> ou <");

                        Muda_Cor(Cor_Das_Grades);
                        printf("t");

                        Muda_Cor(Verde);
                        printf("> para selecionar TODAS\n   AS DISCIPLINAS CADASTRADAS e pressione");

                        Muda_Cor(Cor_Das_Grades);
                        printf(" ENTER.");

                        Muda_Cor(Verde);
                        printf(" Quando desejar\n   encerrar o conjunto de DISCIPLINAS digite a tecla <");

                        Muda_Cor(Cor_Das_Grades);
                        printf("s");

                        Muda_Cor(Verde);
                        printf("> ou <");

                        Muda_Cor(Cor_Das_Grades);
                        printf("S");

                        Muda_Cor(Verde);
                        printf(">\n   e pressione a tecla");

                        Muda_Cor(Cor_Das_Grades);
                        printf(" ENTER: ");

                        fflush(stdin);
                        Muda_Cor(Branco);
                        scanf("%[^\n]", Vet_Aux[k]);
                        fflush(stdin);

                        Saida=0;
                        Analise=0;
                        Analise2=0;
                        Aux=0;
                        x=0;
                        Retorno=(-1);

                        if(Vet_Aux[k][0] == 'T' || Vet_Aux[k][0] == 't')
                        {
                            x=10;
                        }

                        if(Vet_Aux[k][0] == 'S' ||  Vet_Aux[k][0] == 's')
                        {
                            Saida=1;
                            Analise=1;
                            Analise2=0;
                        }

                        if(Saida!=1 && x != 10)
                        {
                            for(j=0; j<N_DIS; j++)
                            {
                                Retorno = strcmp(Vet_Aux[k], TAB_DIS[j].Codigo);
                                if(Retorno == 0)
                                {
                                    Analise=1;
                                    Aux=j;
                                }

                            }

                            if(Analise == 0)
                            {
                                Muda_Cor(Cor_Das_Grades);
                                printf("\n \332\304\304\304\304\304");

                                for(j=0; j<5; j++)
                                    printf("\304\304\304\304\304\304\304\304");

                                printf("\277\n \263");

                                Muda_Cor(Vermelho);
                                printf(" CODIGO NAO CADASTRADO NO SISTEMA ACADEMICO!");
                                Muda_Cor(Cor_Das_Grades);
                                printf(" \263\n \300\304\304\304\304\304");

                                for(j=0; j<5; j++)
                                    printf("\304\304\304\304\304\304\304\304");

                                printf("\331");
                                Sleep(3000);
                            }
                            else
                            {
                                Vet_Nome[k] = Aux;

                                if(k!=0)
                                {
                                    for(j=0; j<k; j++)
                                    {
                                        if(Vet_Nome[k] == Vet_Nome[j])
                                        {
                                            Analise2=1;
                                        }
                                    }

                                    if(Analise2 == 1)
                                    {
                                        Muda_Cor(Cor_Das_Grades);
                                        printf("\n \332\304\304\304\304\304\304");

                                        for(j=0; j<5; j++)
                                            printf("\304\304\304\304\304\304\304\304");

                                        printf("\277\n \263");

                                        Muda_Cor(Vermelho);
                                        printf(" VOCE JA INCLUIU ESTA DISCIPLINA NO CONJUNTO!");
                                        Muda_Cor(Cor_Das_Grades);
                                        printf(" \263\n \300\304\304\304\304\304\304");

                                        for(j=0; j<5; j++)
                                            printf("\304\304\304\304\304\304\304\304");

                                        printf("\331");
                                        Sleep(3000);

                                    }
                                }

                            }
                        }

                        if(x==10)
                        {
                            Analise=1;
                            Analise2=0;
                        }

                    }
                    while(Analise == 0 || Analise2==1);


                    if(Saida == 0 && Analise == 1 && Analise2==0 && x!=10)
                    {
                        system("cls");

                        Muda_Cor(Cor_Das_Grades);
                        printf("\n  \332\304\304\304\304\304");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n  \263");

                        Muda_Cor(Vermelho);
                        printf(" REALIZANDO O VINCULAMENTO DE UM CONJUNTO DE PROFESSORES, EM");

                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n  \263");

                        Muda_Cor(Vermelho);
                        printf(" UM CONJUNTO DE DISCIPLINAS PARA UMA DETERMINADA TURMA...");
                        Muda_Cor(Cor_Das_Grades);
                        printf("    \263\n  \300\304\304\304\304\304");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");


                        printf("\n\n\t       \332\304\304\304\304\304\304\304\304\304\304\304\304\302");

                        for(j=0; j<5; j++)
                            printf("\304\304\304\304");

                        printf("\304\304\277\n\t       \263");


                        Muda_Cor(Vermelho);
                        printf(" QUANTIDADE ");

                        Muda_Cor(Cor_Das_Grades);
                        printf("\263");

                        Muda_Cor(Vermelho);
                        printf(" CODIGOS SELECIONADOS ");
                        Muda_Cor(Cor_Das_Grades);
                        printf("\263\n\t       \303\304\304\304\304\304\304\304\304\304\304\304\304\305");

                        for(j=0; j<5; j++)
                            printf("\304\304\304\304");

                        printf("\304\304\264");

                        k=(k+1);

                        for(j=0; j<k; j++)
                        {
                            printf("\n\t       \263");
                            Muda_Cor(Branco);
                            printf("      %-2d    ", (j+1));
                            Muda_Cor(Cor_Das_Grades);
                            printf("\263");
                            Muda_Cor(Branco);
                            printf("      %-9s", Vet_Aux[j]);
                            Muda_Cor(Cor_Das_Grades);
                            printf("       \263\n\t       ");

                            if(j==(k-1))
                            {
                                printf("\300\304\304\304\304\304\304\304\304\304\304\304\304");
                                printf("\301\304\304\304\304\304\304\304\304\304\304\304\304");
                                printf("\304\304\304\304\304\304\304\304\304\304\331");
                            }
                            else
                            {
                                printf("\303\304\304\304\304\304\304\304\304\304\304\304\304");
                                printf("\305\304\304\304\304\304\304\304\304\304\304\304\304");
                                printf("\304\304\304\304\304\304\304\304\304\304\264");
                            }
                        }
                        Sleep(1000*k);
                    }

                    if(x==10)
                    {
                        k=0;
                        for(j=0; j<N_DIS; j++)
                        {
                            Vet_Nome[k] = j;
                            k=(k+1);
                        }

                        Muda_Cor(Cor_Das_Grades);
                        printf("\n\n \332\304");

                        for(j=0; j<6; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n \263");

                        Muda_Cor(Vermelho);
                        printf("  FOI SELECIONADA A OPCAO TODAS AS DISCIPLINAS!");
                        Muda_Cor(Cor_Das_Grades);
                        printf("  \263\n \300\304");

                        for(j=0; j<6; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");
                        Sleep(3000);

                        Saida=1;
                    }
                }

                Teste=0;
                Aux = 0;
                j=0;
                l=0;
                x=0;

                for(j=0; j<40; j++)
                {
                    Aux = (Aux + RP[j]);
                }

                if(Aux!=(-40))
                {
                    Aux=0;

                    for(j=0; j<40; j++)
                    {
                        Aux = (Aux + Vet_Nome[j]);
                    }

                    if(Aux!=(-40))
                    {
                        Teste=25;
                        Aux = 0;

                        for(l=0; l<k; l++)
                        {
                            Aux=(Vet_Nome[l]);

                            (Tabela[Aux].Professores = RP[(i-1)]);
                        }
                    }
                }

                if(Teste==25)
                {
                    do
                    {
                        system("cls");
                        Muda_Cor(Cor_Das_Grades);
                        printf("\n  \332\304\304");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n  \263");

                        Muda_Cor(Vermelho);
                        printf("   CONJUNTO DE PROFESSORES VINCULADOS COM SUCESSO, EM");

                        Muda_Cor(Cor_Das_Grades);
                        printf("     \263\n  \263");

                        Muda_Cor(Vermelho);
                        printf(" UM CONJUNTO DE DISCIPLINAS PARA UMA DETERMINADA TURMA...");
                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n  \300\304\304");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");

                        fflush(stdin);
                        Muda_Cor(Verde);
                        printf("\n\n     Digite ");
                        Muda_Cor(Cor_Das_Grades);
                        printf("ENTER ");
                        Muda_Cor(Verde);
                        printf("se deseja cadastrar mais PROFESSORES\n     no sistema ou ");
                        Muda_Cor(Cor_Das_Grades);
                        printf("ESC ");
                        Muda_Cor(Verde);
                        printf("para retornar ao MENU: ");
                        Muda_Cor(Branco);

                        Verificar = getch();
                        fflush(stdin);
                    }
                    while(Verificar != 27 && Verificar != 13);
                }

                else
                {
                    do
                    {
                        system("cls");
                        Muda_Cor(Cor_Das_Grades);
                        printf("\n  \332\304\304");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n  \263");

                        Muda_Cor(Vermelho);
                        printf("   CONJUNTO DE PROFESSORES VINCULADOS SEM SUCESSO, EM");

                        Muda_Cor(Cor_Das_Grades);
                        printf("     \263\n  \263");


                        Muda_Cor(Vermelho);
                        printf(" UM CONJUNTO DE DISCIPLINAS PARA UMA DETERMINADA TURMA...");
                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n  \300\304\304");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");

                        fflush(stdin);
                        Muda_Cor(Verde);
                        printf("\n\n     Digite ");
                        Muda_Cor(Cor_Das_Grades);
                        printf("ENTER ");
                        Muda_Cor(Verde);
                        printf("se deseja cadastrar mais PROFESSORES\n     no sistema ou ");
                        Muda_Cor(Cor_Das_Grades);
                        printf("ESC ");
                        Muda_Cor(Verde);
                        printf("para retornar ao MENU: ");
                        Muda_Cor(Branco);

                        Verificar = getch();
                        fflush(stdin);
                    }
                    while(Verificar != 27 && Verificar != 13);

                }
            }

            if(Saida==1 && i==0)
            {
                Verificar=27;
            }
        }
    }
}
//###############################################################################


// FUN��O PARA REALIZAR OS PROCEDIMENTOS DE VINCULA��O DOS PROFESSORES NAS DEVIDAS DISCIPLINAS
void Desvincular_Professores (Professores TAB_PROF[], Disciplinas TAB_DIS[], Matriculas Tabela[], int N_PROF, int N_DIS) // REQUISITO 7
{
    int i;
    int j;
    int k;
    int l;

    int x;
    int Vet_RP[40];
    int RP[40];
    int Vet_Nome[40];
    char Vet_Aux[40][10];

    int Analise;
    int Analise2;
    int Aux;
    int Saida;
    int Retorno;
    int Teste;
    int Soma;

    int Verificar;

    Verificar = 13;
    i=0;
    j=0;
    k=0;
    l=0;
    Analise=0;
    Analise2=0;
    Aux = 0;
    Saida = 0;
    Retorno = -1;
    x=0;
    Teste=0;
    Soma=0;

    if(N_PROF == 0 && N_DIS == 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("  NENHUM PROFESSOR E NEM DISCIPLINA CADASTRADOS NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf(" \263\n \300\304\304\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL");
            printf("\n  e cadastrar professores ou disciplinas: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_PROF == 0 && N_DIS > 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("\t    NENHUM PROFESSOR CADASTRADO NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf("         \263\n \300\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL e cadastrar professores: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_DIS == 0 && N_PROF > 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("\t  NENHUMA DISCIPLINA CADASTRADA NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf("     \263\n \300\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL e cadastrar disciplinas: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_PROF > 0 && N_DIS > 0)
    {
        x=0;

        Soma=0;
        for(j=0; j<15; j++)
        {
            Soma = (Soma+Tabela[j].Professores);
        }
        if(Soma!=(-15))
        {
            x=1;
        }

        if(x==0)
        {
            do
            {
                system("cls");
                Muda_Cor(Cor_Das_Grades);
                printf("\n \332");

                for(j=0; j<7; j++)
                    printf("\304\304\304\304\304\304\304\304");

                printf("\277\n \263");

                Muda_Cor(Vermelho);
                printf("\t NENHUM PROFESSOR VINCULADO NO MOMENTO!!! ");

                Muda_Cor(Cor_Das_Grades);
                printf("        \263\n \300");

                for(j=0; j<7; j++)
                    printf("\304\304\304\304\304\304\304\304");

                printf("\331");

                fflush(stdin);
                Muda_Cor(Verde);
                printf("\n\n  Digite ");
                Muda_Cor(Cor_Das_Grades);
                printf("ESC ");
                Muda_Cor(Verde);
                printf("para retornar ao MENU INICIAL e cadastrar disciplinas: ");
                Muda_Cor(Branco);
                Verificar = getch();
                fflush(stdin);
            }
            while(Verificar != 27);
        }
    }

    Saida = 0;

    while(Verificar == 13)
    {
        i=0;
        j=0;
        k=0;
        l=0;
        Analise=0;
        Analise2=0;
        Aux = 0;
        Retorno = -1;
        Verificar = 13;
        Saida = 0;
        x=0;

        for(j=0; j<40; j++)
        {
            Vet_Nome[j] = (-1);
            RP[j] = (-1);
        }

        if(N_PROF > 0 && N_DIS > 0)
        {
            i=0;
            while(Saida == 0 && i<Maximo_Professores)
            {
                do
                {
                    system("cls");
                    Analise = 0;
                    Analise2=0;
                    Saida=0;

                    Muda_Cor(Cor_Das_Grades);
                    printf("\n \332\304\304\304\304\304\304\304\304");

                    for(j=0; j<7; j++)
                        printf("\304\304\304\304\304\304\304\304");

                    printf("\277\n \263");

                    Muda_Cor(Vermelho);
                    printf(" REALIZANDO O DESVINCULAMENTO DE UM CONJUNTO DE PROFESSORES, EM");

                    Muda_Cor(Cor_Das_Grades);
                    printf(" \263\n \263");

                    Muda_Cor(Vermelho);
                    printf("    UM CONJUNTO DE DISCIPLINAS PARA UMA DETERMINADA TURMA...");
                    Muda_Cor(Cor_Das_Grades);
                    printf("    \263\n \300\304\304\304\304\304\304\304\304");

                    for(j=0; j<7; j++)
                        printf("\304\304\304\304\304\304\304\304");

                    printf("\331");

                    Imprime_Lista_Professores(TAB_PROF, N_PROF);

                    Muda_Cor(Verde);
                    printf("\n\n   Digite um ");

                    Muda_Cor(Cor_Das_Grades);
                    printf("RP");

                    Muda_Cor(Verde);
                    printf(" correspondente ao nome de um");

                    Muda_Cor(Cor_Das_Grades);
                    printf(" PROFESSOR CADASTRADO ");

                    Muda_Cor(Verde);
                    printf("ou\n   Digite <");

                    Muda_Cor(Cor_Das_Grades);
                    printf("-10");

                    Muda_Cor(Verde);
                    printf("> para selecionar TODOS OS PROFESSORES CADASTRADOS e\n   pressione");

                    Muda_Cor(Cor_Das_Grades);
                    printf(" ENTER. ");

                    Muda_Cor(Verde);
                    printf(" Quando desejar encerrar o conjunto de\n   PROFESSORES digite <");

                    Muda_Cor(Cor_Das_Grades);
                    printf("-1");

                    Muda_Cor(Verde);
                    printf("> e pressione a tecla");

                    Muda_Cor(Cor_Das_Grades);
                    printf(" ENTER: ");

                    fflush(stdin);
                    Muda_Cor(Branco);
                    scanf("%d", &Vet_RP[i]);
                    fflush(stdin);

                    Analise=0;
                    Analise2=0;
                    Saida=0;
                    Aux=0;
                    x=0;

                    if(Vet_RP[i] == (-10))
                    {
                        x=10;
                    }

                    if(Vet_RP[i]!=(-1) && x!=10)
                    {
                        for(j=0; j<N_PROF; j++)
                        {
                            if(Vet_RP[i] == TAB_PROF[j].RP)
                            {
                                Analise = 1;
                                Aux = j;
                            }
                        }

                        if(Analise == 0)
                        {
                            Muda_Cor(Cor_Das_Grades);
                            printf("\n \332\304");

                            for(j=0; j<5; j++)
                                printf("\304\304\304\304\304\304\304\304");

                            printf("\277\n \263");

                            Muda_Cor(Vermelho);
                            printf(" RP NAO CADASTRADO NO SISTEMA ACADEMICO!");
                            Muda_Cor(Cor_Das_Grades);
                            printf(" \263\n \300\304");

                            for(j=0; j<5; j++)
                                printf("\304\304\304\304\304\304\304\304");

                            printf("\331");
                            Sleep(3000);
                        }
                        else
                        {
                            RP[i] = Aux;

                            if(i!=0)
                            {
                                for(j=0; j<i; j++)
                                {
                                    if(RP[i] == RP[j])
                                    {
                                        Analise2=1;
                                    }
                                }
                                if(Analise2 == 1)
                                {
                                    Muda_Cor(Cor_Das_Grades);
                                    printf("\n \332\304\304\304\304\304");

                                    for(j=0; j<5; j++)
                                        printf("\304\304\304\304\304\304\304\304");

                                    printf("\277\n \263");

                                    Muda_Cor(Vermelho);
                                    printf(" VOCE JA INCLUIU ESTE PROFESSOR NO CONJUNTO!");
                                    Muda_Cor(Cor_Das_Grades);
                                    printf(" \263\n \300\304\304\304\304\304");

                                    for(j=0; j<5; j++)
                                        printf("\304\304\304\304\304\304\304\304");

                                    printf("\331");
                                    Sleep(3000);
                                }

                            }
                        }
                    }

                    if(Vet_RP[i]==(-1))
                    {
                        Saida=1;
                        Analise=1;
                        Analise2=0;
                    }

                    if(x==10)
                    {
                        Analise=1;
                        Analise2=0;
                    }

                }
                while(Analise==0 || Analise2==1);


                if(Saida == 0 && Analise == 1 && Analise2==0 && x!=10)
                {

                    system("cls");

                    Muda_Cor(Cor_Das_Grades);
                    printf("\n \332\304\304\304\304\304\304\304\304");

                    for(j=0; j<7; j++)
                        printf("\304\304\304\304\304\304\304\304");

                    printf("\277\n \263");

                    Muda_Cor(Vermelho);
                    printf(" REALIZANDO O DESVINCULAMENTO DE UM CONJUNTO DE PROFESSORES, EM");

                    Muda_Cor(Cor_Das_Grades);
                    printf(" \263\n \263");

                    Muda_Cor(Vermelho);
                    printf("    UM CONJUNTO DE DISCIPLINAS PARA UMA DETERMINADA TURMA...");
                    Muda_Cor(Cor_Das_Grades);
                    printf("    \263\n \300\304\304\304\304\304\304\304\304");

                    for(j=0; j<7; j++)
                        printf("\304\304\304\304\304\304\304\304");

                    printf("\331");


                    printf("\n\n\t       \332\304\304\304\304\304\304\304\304\304\304\304\304\302");

                    for(j=0; j<5; j++)
                        printf("\304\304\304\304");

                    printf("\304\277\n\t       \263");


                    Muda_Cor(Vermelho);
                    printf(" QUANTIDADE ");

                    Muda_Cor(Cor_Das_Grades);
                    printf("\263");

                    Muda_Cor(Vermelho);
                    printf("  RPS SELECIONADOS   ");
                    Muda_Cor(Cor_Das_Grades);
                    printf("\263\n\t       \303\304\304\304\304\304\304\304\304\304\304\304\304\305");

                    for(j=0; j<5; j++)
                        printf("\304\304\304\304");

                    printf("\304\264");

                    i=(i+1);

                    for(j=0; j<i; j++)
                    {
                        printf("\n\t       \263");
                        Muda_Cor(Branco);
                        printf("      %-2d    ", (j+1));
                        Muda_Cor(Cor_Das_Grades);
                        printf("\263");
                        Muda_Cor(Branco);
                        printf("      %-8d", Vet_RP[j]);
                        Muda_Cor(Cor_Das_Grades);
                        printf("       \263\n\t       ");

                        if(j==(i-1))
                        {
                            printf("\300\304\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\301\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\331");
                        }
                        else
                        {
                            printf("\303\304\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\305\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\264");
                        }
                    }
                    Sleep(1000*i);
                }

                if(x==10)
                {
                    i=0;
                    for(j=0; j<N_PROF; j++)
                    {
                        RP[i] = j;
                        i=(i+1);
                    }

                    Muda_Cor(Cor_Das_Grades);
                    printf("\n\n \332");

                    for(j=0; j<6; j++)
                        printf("\304\304\304\304\304\304\304\304");

                    printf("\277\n \263");

                    Muda_Cor(Vermelho);
                    printf("  FOI SELECIONADA A OPCAO TODOS OS PROFESSORES!");
                    Muda_Cor(Cor_Das_Grades);
                    printf(" \263\n \300");

                    for(j=0; j<6; j++)
                        printf("\304\304\304\304\304\304\304\304");

                    printf("\331");
                    Sleep(3000);

                    Saida=1;
                }
            }

            if(i>0)
            {
                Saida=0;

                k=0;
                while(Saida == 0 && i<Maximo_Disciplinas)
                {
                    do
                    {
                        system("cls");

                        Muda_Cor(Cor_Das_Grades);
                        printf("\n \332\304\304\304\304\304\304\304\304");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n \263");

                        Muda_Cor(Vermelho);
                        printf(" REALIZANDO O DESVINCULAMENTO DE UM CONJUNTO DE PROFESSORES, EM");

                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n \263");

                        Muda_Cor(Vermelho);
                        printf("    UM CONJUNTO DE DISCIPLINAS PARA UMA DETERMINADA TURMA...");
                        Muda_Cor(Cor_Das_Grades);
                        printf("    \263\n \300\304\304\304\304\304\304\304\304");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");

                        Imprime_lista_Disciplinas(TAB_DIS, N_DIS);

                        Muda_Cor(Verde);
                        printf("\n\n   Digite um ");

                        Muda_Cor(Cor_Das_Grades);
                        printf("CODIGO COM O TRACO");

                        Muda_Cor(Verde);
                        printf(" correspondente a uma");

                        Muda_Cor(Cor_Das_Grades);
                        printf(" DISCIPLINA\n   CADASTRADA ");

                        Muda_Cor(Verde);
                        printf("ou digite a letra <");

                        Muda_Cor(Cor_Das_Grades);
                        printf("T");

                        Muda_Cor(Verde);
                        printf("> ou <");

                        Muda_Cor(Cor_Das_Grades);
                        printf("t");

                        Muda_Cor(Verde);
                        printf("> para selecionar TODAS\n   AS DISCIPLINAS CADASTRADAS e pressione");

                        Muda_Cor(Cor_Das_Grades);
                        printf(" ENTER.");

                        Muda_Cor(Verde);
                        printf(" Quando desejar\n   encerrar o conjunto de DISCIPLINAS digite a tecla <");

                        Muda_Cor(Cor_Das_Grades);
                        printf("s");

                        Muda_Cor(Verde);
                        printf("> ou <");

                        Muda_Cor(Cor_Das_Grades);
                        printf("S");

                        Muda_Cor(Verde);
                        printf(">\n   e pressione a tecla");

                        Muda_Cor(Cor_Das_Grades);
                        printf(" ENTER: ");

                        fflush(stdin);
                        Muda_Cor(Branco);
                        scanf("%[^\n]", Vet_Aux[k]);
                        fflush(stdin);

                        Saida=0;
                        Analise=0;
                        Analise2=0;
                        Aux=0;
                        x=0;
                        Retorno=(-1);

                        if(Vet_Aux[k][0] == 'T' || Vet_Aux[k][0] == 't')
                        {
                            x=10;
                        }

                        if(Vet_Aux[k][0] == 'S' ||  Vet_Aux[k][0] == 's')
                        {
                            Saida=1;
                            Analise=1;
                            Analise2=0;
                        }

                        if(Saida!=1 && x != 10)
                        {
                            for(j=0; j<N_DIS; j++)
                            {
                                Retorno = strcmp(Vet_Aux[k], TAB_DIS[j].Codigo);
                                if(Retorno == 0)
                                {
                                    Analise=1;
                                    Aux=j;
                                }

                            }

                            if(Analise == 0)
                            {
                                Muda_Cor(Cor_Das_Grades);
                                printf("\n \332\304\304\304\304\304");

                                for(j=0; j<5; j++)
                                    printf("\304\304\304\304\304\304\304\304");

                                printf("\277\n \263");

                                Muda_Cor(Vermelho);
                                printf(" CODIGO NAO CADASTRADO NO SISTEMA ACADEMICO!");
                                Muda_Cor(Cor_Das_Grades);
                                printf(" \263\n \300\304\304\304\304\304");

                                for(j=0; j<5; j++)
                                    printf("\304\304\304\304\304\304\304\304");

                                printf("\331");
                                Sleep(3000);
                            }
                            else
                            {
                                Vet_Nome[k] = Aux;

                                if(k!=0)
                                {
                                    for(j=0; j<k; j++)
                                    {
                                        if(Vet_Nome[k] == Vet_Nome[j])
                                        {
                                            Analise2=1;
                                        }
                                    }

                                    if(Analise2 == 1)
                                    {
                                        Muda_Cor(Cor_Das_Grades);
                                        printf("\n \332\304\304\304\304\304\304");

                                        for(j=0; j<5; j++)
                                            printf("\304\304\304\304\304\304\304\304");

                                        printf("\277\n \263");

                                        Muda_Cor(Vermelho);
                                        printf(" VOCE JA INCLUIU ESTA DISCIPLINA NO CONJUNTO!");
                                        Muda_Cor(Cor_Das_Grades);
                                        printf(" \263\n \300\304\304\304\304\304\304");

                                        for(j=0; j<5; j++)
                                            printf("\304\304\304\304\304\304\304\304");

                                        printf("\331");
                                        Sleep(3000);

                                    }
                                }

                            }
                        }

                        if(x==10)
                        {
                            Analise=1;
                            Analise2=0;
                        }

                    }
                    while(Analise == 0 || Analise2==1);


                    if(Saida == 0 && Analise == 1 && Analise2==0 && x!=10)
                    {
                        system("cls");

                        Muda_Cor(Cor_Das_Grades);
                        printf("\n \332\304\304\304\304\304\304\304\304");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n \263");

                        Muda_Cor(Vermelho);
                        printf(" REALIZANDO O DESVINCULAMENTO DE UM CONJUNTO DE PROFESSORES, EM");

                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n \263");

                        Muda_Cor(Vermelho);
                        printf("    UM CONJUNTO DE DISCIPLINAS PARA UMA DETERMINADA TURMA...");
                        Muda_Cor(Cor_Das_Grades);
                        printf("    \263\n \300\304\304\304\304\304\304\304\304");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");


                        printf("\n\n\t       \332\304\304\304\304\304\304\304\304\304\304\304\304\302");

                        for(j=0; j<5; j++)
                            printf("\304\304\304\304");

                        printf("\304\304\277\n\t       \263");


                        Muda_Cor(Vermelho);
                        printf(" QUANTIDADE ");

                        Muda_Cor(Cor_Das_Grades);
                        printf("\263");

                        Muda_Cor(Vermelho);
                        printf(" CODIGOS SELECIONADOS ");
                        Muda_Cor(Cor_Das_Grades);
                        printf("\263\n\t       \303\304\304\304\304\304\304\304\304\304\304\304\304\305");

                        for(j=0; j<5; j++)
                            printf("\304\304\304\304");

                        printf("\304\304\264");

                        k=(k+1);

                        for(j=0; j<k; j++)
                        {
                            printf("\n\t       \263");
                            Muda_Cor(Branco);
                            printf("      %-2d    ", (j+1));
                            Muda_Cor(Cor_Das_Grades);
                            printf("\263");
                            Muda_Cor(Branco);
                            printf("      %-9s", Vet_Aux[j]);
                            Muda_Cor(Cor_Das_Grades);
                            printf("       \263\n\t       ");

                            if(j==(k-1))
                            {
                                printf("\300\304\304\304\304\304\304\304\304\304\304\304\304");
                                printf("\301\304\304\304\304\304\304\304\304\304\304\304\304");
                                printf("\304\304\304\304\304\304\304\304\304\304\331");
                            }
                            else
                            {
                                printf("\303\304\304\304\304\304\304\304\304\304\304\304\304");
                                printf("\305\304\304\304\304\304\304\304\304\304\304\304\304");
                                printf("\304\304\304\304\304\304\304\304\304\304\264");
                            }
                        }
                        Sleep(1000*k);
                    }

                    if(x==10)
                    {
                        k=0;
                        for(j=0; j<N_DIS; j++)
                        {
                            Vet_Nome[k] = j;
                            k=(k+1);
                        }

                        Muda_Cor(Cor_Das_Grades);
                        printf("\n\n \332\304");

                        for(j=0; j<6; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n \263");

                        Muda_Cor(Vermelho);
                        printf("  FOI SELECIONADA A OPCAO TODAS AS DISCIPLINAS!");
                        Muda_Cor(Cor_Das_Grades);
                        printf("  \263\n \300\304");

                        for(j=0; j<6; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");
                        Sleep(3000);

                        Saida=1;
                    }
                }

                Teste=0;
                Aux = 0;
                j=0;
                l=0;
                x=0;

                for(j=0; j<40; j++)
                {
                    Aux = (Aux + RP[j]);
                }

                if(Aux!=(-40))
                {
                    Aux=0;

                    for(j=0; j<40; j++)
                    {
                        Aux = (Aux + Vet_Nome[j]);
                    }

                    if(Aux!=(-40))
                    {
                        Teste=25;
                        Aux = 0;

                        for(l=0; l<k; l++)
                        {
                            Aux=(Vet_Nome[l]);

                            for(j=0; j<15; j++)
                            {
                                if(Tabela[Aux].Professores == RP[j])
                                {
                                    Tabela[Aux].Professores=(-1);
                                }
                            }

                        }
                    }
                }

                if(Teste==25)
                {
                    do
                    {
                        system("cls");
                        Muda_Cor(Cor_Das_Grades);
                        printf("\n    \332\304\304");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n    \263");

                        Muda_Cor(Vermelho);
                        printf("  CONJUNTO DE PROFESSORES DESVINCULADOS COM SUCESSO, EM");

                        Muda_Cor(Cor_Das_Grades);
                        printf("   \263\n    \263");

                        Muda_Cor(Vermelho);
                        printf(" UM CONJUNTO DE DISCIPLINAS PARA UMA DETERMINADA TURMA...");
                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n    \300\304\304");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");

                        fflush(stdin);
                        Muda_Cor(Verde);
                        printf("\n\n     Digite ");
                        Muda_Cor(Cor_Das_Grades);
                        printf("ENTER ");
                        Muda_Cor(Verde);
                        printf("se deseja cadastrar mais PROFESSORES\n     no sistema ou ");
                        Muda_Cor(Cor_Das_Grades);
                        printf("ESC ");
                        Muda_Cor(Verde);
                        printf("para retornar ao MENU: ");
                        Muda_Cor(Branco);

                        Verificar = getch();
                        fflush(stdin);
                    }
                    while(Verificar != 27 && Verificar != 13);
                }

                else
                {
                    do
                    {
                        system("cls");
                        Muda_Cor(Cor_Das_Grades);
                        printf("\n    \332\304\304");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n    \263");

                        Muda_Cor(Vermelho);
                        printf("  CONJUNTO DE PROFESSORES DESVINCULADOS SEM SUCESSO, EM");

                        Muda_Cor(Cor_Das_Grades);
                        printf("   \263\n    \263");

                        Muda_Cor(Vermelho);
                        printf(" UM CONJUNTO DE DISCIPLINAS PARA UMA DETERMINADA TURMA...");
                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n    \300\304\304");

                        for(j=0; j<7; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");

                        fflush(stdin);
                        Muda_Cor(Verde);
                        printf("\n\n     Digite ");
                        Muda_Cor(Cor_Das_Grades);
                        printf("ENTER ");
                        Muda_Cor(Verde);
                        printf("se deseja cadastrar mais PROFESSORES\n     no sistema ou ");
                        Muda_Cor(Cor_Das_Grades);
                        printf("ESC ");
                        Muda_Cor(Verde);
                        printf("para retornar ao MENU: ");
                        Muda_Cor(Branco);

                        Verificar = getch();
                        fflush(stdin);
                    }
                    while(Verificar != 27 && Verificar != 13);

                }
            }

            if(Saida==1 && i==0)
            {
                Verificar=27;
            }
        }
    }
}
//###############################################################################


//########### FUN��O PARA IMPRIMIR A LISTA DE DISCIPLINAS DE UM PROFESSOR ###########
void Imprimir_Lista_Disciplinas_De_Professor (Matriculas Tabela[], Professores TAB_PROF[], Disciplinas TAB_DIS[], int N_PROF, int N_DIS) // REQUISITO 14 - A
{
    int i;
    int j;
    int k;
    int RP;
    int teste;
    int Pos;
    int Verificar;
    int Soma;
    int x;

    int Vet[40];

    Soma=0;
    Verificar=13;
    x=0;

    if(N_PROF == 0 && N_DIS == 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("  NENHUM PROFESSOR E NEM DISCIPLINA CADASTRADOS NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf(" \263\n \300\304\304\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL");
            printf("\n  e cadastrar professores ou disciplinas: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_PROF == 0 && N_DIS > 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("\t    NENHUM PROFESSOR CADASTRADO NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf("         \263\n \300\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL e cadastrar professores: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_DIS == 0 && N_PROF > 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("\t  NENHUMA DISCIPLINA CADASTRADA NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf("     \263\n \300\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL e cadastrar disciplinas: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_PROF > 0 && N_DIS > 0)
    {
        x=0;

        Soma=0;
        for(j=0; j<15; j++)
        {
            Soma = (Soma+Tabela[j].Professores);
        }
        if(Soma!=(-15))
        {
            x=1;
        }

        if(x==0)
        {
            do
            {
                system("cls");
                Muda_Cor(Cor_Das_Grades);
                printf("\n \332");

                for(j=0; j<7; j++)
                    printf("\304\304\304\304\304\304\304\304");

                printf("\277\n \263");

                Muda_Cor(Vermelho);
                printf("\t NENHUM PROFESSOR MATRICULADO NO MOMENTO! ");

                Muda_Cor(Cor_Das_Grades);
                printf("        \263\n \300");

                for(j=0; j<7; j++)
                    printf("\304\304\304\304\304\304\304\304");

                printf("\331");

                fflush(stdin);
                Muda_Cor(Verde);
                printf("\n\n  Digite ");
                Muda_Cor(Cor_Das_Grades);
                printf("ESC ");
                Muda_Cor(Verde);
                printf("para retornar ao MENU INICIAL e cadastrar disciplinas: ");
                Muda_Cor(Branco);
                Verificar = getch();
                fflush(stdin);
            }
            while(Verificar != 27);
        }
    }

    while(Verificar == 13)
    {
        Verificar = 13;

        for(j=0; j<40; j++)
        {
            Vet[j] = (-1);
        }

        if(N_PROF > 0 && N_DIS > 0)
        {
            do
            {
                system("cls");
                Imprime_Lista_Professores (TAB_PROF, N_PROF);

                i=0;
                j=0;
                k=0;
                RP=0;


                fflush(stdin);
                Muda_Cor(Verde);
                printf("\n\n\n   Digite o");
                Muda_Cor(Cor_Das_Grades);
                printf(" RP ");
                Muda_Cor(Verde);
                printf("de um");
                Muda_Cor(Cor_Das_Grades);
                printf(" PROFESSOR CADASTRADO ");
                Muda_Cor(Verde);
                printf("e pressione");
                Muda_Cor(Cor_Das_Grades);
                printf(" ENTER ");
                Muda_Cor(Verde);
                printf("para\n   visualizar todas as DISCIPLINAS que esse PROFESSOR esta\n   vinculado ou <");
                Muda_Cor(Cor_Das_Grades);
                printf("-1");
                Muda_Cor(Verde);
                printf("> para retornar ao MENU INICIAL: ");
                Muda_Cor(Branco);
                scanf("%d", &RP);
                fflush(stdin);

                if(RP != (-1))
                {
                    teste=0;

                    if(N_PROF!=0)
                    {
                        for(j=0; j<N_PROF; j++)
                        {
                            if(TAB_PROF[j].RP == RP)
                            {
                                teste=1;
                                Pos=j;
                            }
                        }
                    }

                    if(teste==0)
                    {
                        Muda_Cor(Cor_Das_Grades);
                        printf("\n \332\304");

                        for(j=0; j<5; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n \263");

                        Muda_Cor(Vermelho);
                        printf(" RP NAO CADASTRADO NO SISTEMA ACADEMICO!");
                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n \300\304");

                        for(j=0; j<5; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");
                        Sleep(3000);
                    }

                    k=0;

                    for(j=0; j<15; j++)
                    {
                        if(Tabela[j].Professores == Pos)
                        {
                            Vet[k]=j;
                            k=(k+1);
                        }
                    }


                    if(k==0 && teste==1)
                    {
                        Muda_Cor(Cor_Das_Grades);
                        printf("\n \332\304\304\304\304\304\304");

                        for(j=0; j<9; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n \263");

                        Muda_Cor(Vermelho);
                        printf(" O PROFESSOR selecionado nao esta vinculado em nenhuma disicplina no momento!");
                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n \300\304\304\304\304\304\304");

                        for(j=0; j<9; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");
                        Sleep(3000);
                    }
                }
                else
                {
                    teste=1;
                    k=1;
                }
            }
            while(teste==0 || k==0);

            if(RP!=(-1))
            {
                do
                {
                    system("cls");
                    Muda_Cor(Cor_Das_Grades);
                    printf("\n\n \332");

                    for(i=0; i<4; i++)
                        printf("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304");

                    printf("\277\n \263");
                    Muda_Cor(Vermelho);
                    printf(" LISTA DE TODOS AS DISCIPLINAS CADASTRADAS DO(A) PROFESSOR(A):");
                    Muda_Cor(Cor_Das_Grades);

                    printf("  \263\n \303");

                    for(i=0; i<4; i++)
                        printf("\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304");

                    printf("\264\n \263");

                    Muda_Cor(Branco);
                    printf("       %-50s", TAB_PROF[Pos].Nome);

                    Muda_Cor(Cor_Das_Grades);
                    printf("\t  \263\n \303");
                    for(i=0; i<16; i++)
                        printf("\304\304\304\304");

                    Muda_Cor(Cor_Das_Grades);
                    printf("\264\n \263\t\t\t\t\t\t\t\t  \263\n \303\304");
                    printf("\304\304\304\304\304\304\304\304\304\304\302");

                    for(i=0; i<13; i++)
                        printf("\304\304\304\304");

                    printf("\264\n \263");

                    Muda_Cor(Vermelho);
                    printf("  CODIGO   ");

                    Muda_Cor(Cor_Das_Grades);
                    printf("\263");

                    Muda_Cor(Vermelho);
                    printf("\t\t    DISCIPLINAS VINCULADAS \t\t");
                    Muda_Cor(Cor_Das_Grades);
                    printf("  \263\n \303\304\304\304\304\304\304\304\304\304\304\304\305");

                    for(i=0; i<13; i++)
                        printf("\304\304\304\304");

                    printf("\264");

                    for(i=0; i<k; i++)
                    {
                        printf("\n \263");
                        Muda_Cor(Branco);
                        printf(" %-9s ", TAB_DIS[Vet[i]].Codigo);
                        Muda_Cor(Cor_Das_Grades);
                        printf("\263");
                        Muda_Cor(Branco);
                        printf(" %-50s", TAB_DIS[Vet[i]].Nome);
                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n");

                        if(i==(k-1))
                        {
                            printf(" \300\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\301\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\331");
                        }
                        else
                        {
                            printf(" \303\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\305\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\264");
                        }
                    }

                    fflush(stdin);
                    Muda_Cor(Verde);
                    printf("\n\n     Digite ");
                    Muda_Cor(Cor_Das_Grades);
                    printf("ENTER ");
                    Muda_Cor(Verde);
                    printf("se deseja imprimir outra lista de disciplinas\n     de um professor ou ");
                    Muda_Cor(Cor_Das_Grades);
                    printf("ESC ");
                    Muda_Cor(Verde);
                    printf("para retornar ao MENU: ");
                    Muda_Cor(Branco);

                    Verificar = getch();
                    fflush(stdin);
                }
                while(Verificar != 27 && Verificar != 13);
            }
            else
            {
                Verificar=27;
            }
        }
    }
}
//###############################################################################



// FUN��O PARA IMPRIMIR A LISTA DE PROFESSORES EM UMA DISCIPLINA INDEPENDENTE DA TURMA
void Imprimir_Lista_Professores_De_Disciplina(Matriculas Tabela[], Professores TAB_PROF[], Disciplinas TAB_DIS[], int N_PROF, int N_DIS, Disciplinas_Sem_Turma TAB_DIS_S_TURMA[]) // REQUISITO 15
{
    int i;
    int j;
    int k;
    int teste;
    int Pos;
    int Verificar;
    int Soma;
    int x;
    int Saida;
    int Retorno;
    int N;

    char COD[10];

    int Vet[40];

    Soma=0;
    Verificar=13;
    x=0;
    Retorno=(-1);

    if(N_PROF == 0 && N_DIS == 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("  NENHUM PROFESSOR E NEM DISCIPLINA CADASTRADOS NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf(" \263\n \300\304\304\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL");
            printf("\n  e cadastrar professores ou disciplinas: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_PROF == 0 && N_DIS > 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("\t    NENHUM PROFESSOR CADASTRADO NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf("         \263\n \300\304\304\304");

            for(j=0; j<7; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL e cadastrar professores: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_DIS == 0 && N_PROF > 0)
    {
        do
        {
            system("cls");
            Muda_Cor(Cor_Das_Grades);
            printf("\n \332\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\277\n \263");

            Muda_Cor(Vermelho);
            printf("\t  NENHUMA DISCIPLINA CADASTRADA NO MOMENTO! ");

            Muda_Cor(Cor_Das_Grades);
            printf("     \263\n \300\304\304\304\304\304\304\304");

            for(j=0; j<6; j++)
                printf("\304\304\304\304\304\304\304\304");

            printf("\331");

            fflush(stdin);
            Muda_Cor(Verde);
            printf("\n\n  Digite ");
            Muda_Cor(Cor_Das_Grades);
            printf("ESC ");
            Muda_Cor(Verde);
            printf("para retornar ao MENU INICIAL e cadastrar disciplinas: ");
            Muda_Cor(Branco);
            Verificar = getch();
            fflush(stdin);
        }
        while(Verificar != 27);
    }

    if(N_PROF > 0 && N_DIS > 0)
    {
        x=0;

        Soma=0;
        for(j=0; j<15; j++)
        {
            Soma = (Soma+Tabela[j].Professores);
        }
        if(Soma!=(-15))
        {
            x=1;
        }

        if(x==0)
        {
            do
            {
                system("cls");
                Muda_Cor(Cor_Das_Grades);
                printf("\n \332");

                for(j=0; j<7; j++)
                    printf("\304\304\304\304\304\304\304\304");

                printf("\277\n \263");

                Muda_Cor(Vermelho);
                printf("\t NENHUM PROFESSOR VINCULADO NO MOMENTO!!! ");

                Muda_Cor(Cor_Das_Grades);
                printf("        \263\n \300");

                for(j=0; j<7; j++)
                    printf("\304\304\304\304\304\304\304\304");

                printf("\331");

                fflush(stdin);
                Muda_Cor(Verde);
                printf("\n\n  Digite ");
                Muda_Cor(Cor_Das_Grades);
                printf("ESC ");
                Muda_Cor(Verde);
                printf("para retornar ao MENU INICIAL e cadastrar disciplinas: ");
                Muda_Cor(Branco);
                Verificar = getch();
                fflush(stdin);
            }
            while(Verificar != 27);
        }
    }




    while(Verificar == 13)
    {
        Verificar = 13;
        Saida=0;

        for(j=0; j<40; j++)
        {
            Vet[j] = (-1);
        }

        if(N_PROF > 0 && N_DIS > 0)
        {
            do
            {
                system("cls");
                Imprime_lista_Disciplinas_Independente_da_Turma (TAB_DIS, TAB_DIS_S_TURMA, N_DIS);

                i=0;
                j=0;
                k=0;
                Saida=0;


                fflush(stdin);
                Muda_Cor(Verde);
                printf("\n\n\n   Digite o");
                Muda_Cor(Cor_Das_Grades);
                printf(" CODIGO ");
                Muda_Cor(Verde);
                printf("de uma");
                Muda_Cor(Cor_Das_Grades);
                printf(" DISCIPLINA CADASTRADA ");
                Muda_Cor(Verde);
                printf("e pressione");
                Muda_Cor(Cor_Das_Grades);
                printf(" ENTER ");
                Muda_Cor(Verde);
                printf("\n   para visualizar todos os Professores vinculados nesta DISCIPLINA\n   ou <");
                Muda_Cor(Cor_Das_Grades);
                printf("S");
                Muda_Cor(Verde);
                printf("> ou <");
                Muda_Cor(Cor_Das_Grades);
                printf("s");
                Muda_Cor(Verde);
                printf("> para retornar ao MENU INICIAL: ");
                fflush(stdin);
                Muda_Cor(Branco);
                scanf("%[^\n]", COD);
                fflush(stdin);


                if(COD[0] == 'S' ||  COD[0] == 's')
                {
                    Saida=1;
                }

                if(Saida != 1)
                {
                    teste=0;
                    N=N_DIS;
                    N=(N/2);

                    if(N!=0)
                    {
                        Retorno=(-1);

                        for(j=0; j<N; j++)
                        {
                            Retorno = strcmp(TAB_DIS_S_TURMA[j].Codigo2, COD);

                            if(Retorno == 0)
                            {
                                teste=1;
                                Pos=j;
                            }
                        }
                    }

                    if(teste==0)
                    {
                        Muda_Cor(Cor_Das_Grades);
                        printf("\n \332\304\304\304\304\304");

                        for(j=0; j<5; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n \263");

                        Muda_Cor(Vermelho);
                        printf(" CODIGO NAO CADASTRADO NO SISTEMA ACADEMICO!");
                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n \300\304\304\304\304\304");

                        for(j=0; j<5; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");
                        Sleep(3000);
                    }

                    k=0;
                    Pos=(Pos*2);

                    if(Tabela[Pos].Professores != (-1))
                    {
                        Vet[k]=Tabela[Pos].Professores;
                        k=(k+1);
                    }

                    if(Tabela[Pos].Professores != Tabela[(Pos+1)].Professores)
                    {
                        if(Tabela[(Pos+1)].Professores != (-1))
                        {
                            Vet[k]=Tabela[(Pos+1)].Professores;
                            k=(k+1);
                        }
                    }



                    Pos=(Pos/2);

                    if(k==0 && teste==1)
                    {
                        Muda_Cor(Cor_Das_Grades);
                        printf("\n \332\304\304\304\304\304\304");

                        for(j=0; j<8; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\277\n \263");

                        Muda_Cor(Vermelho);
                        printf(" A DISCIPLINA selecionada nao contem nenhum professor vinculado nela!");
                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n \300\304\304\304\304\304\304");

                        for(j=0; j<8; j++)
                            printf("\304\304\304\304\304\304\304\304");

                        printf("\331");
                        Sleep(3000);
                    }
                }
                else
                {
                    teste=1;
                    k=1;
                }
            }
            while(teste==0 || k==0);

            if(Saida!=1)
            {
                do
                {
                    system("cls");
                    Muda_Cor(Cor_Das_Grades);
                    printf("\n\n \332\304\304\304\304\304\304\304");

                    for(i=0; i<7; i++)
                        printf("\304\304\304\304\304\304\304\304");

                    printf("\277\n \263");
                    Muda_Cor(Vermelho);
                    printf("   LISTA DE TODOS OS PROFESSORES CADASTRADOS NA DISCIPLINA:");
                    Muda_Cor(Cor_Das_Grades);

                    printf("\t \263\n \303\304\304\304\304\304\304\304");

                    for(i=0; i<7; i++)
                        printf("\304\304\304\304\304\304\304\304");

                    printf("\264\n \263");

                    Muda_Cor(Branco);
                    printf("      %-50s", TAB_DIS_S_TURMA[Pos].Nome2);

                    Muda_Cor(Cor_Das_Grades);
                    printf("\t \263\n \303\304\304\304\304\304\304\304");
                    for(i=0; i<7; i++)
                        printf("\304\304\304\304\304\304\304\304");

                    Muda_Cor(Cor_Das_Grades);
                    printf("\264\n \263\t\t\t\t\t\t\t\t \263\n \303\304");
                    printf("\304\304\304\304\304\304\304\304\304\302");

                    for(i=0; i<13; i++)
                        printf("\304\304\304\304");

                    printf("\264\n \263");

                    Muda_Cor(Vermelho);
                    printf("    RP    ");

                    Muda_Cor(Cor_Das_Grades);
                    printf("\263");

                    Muda_Cor(Vermelho);
                    printf("\t\t   PROFESSORES CADASTRADOS\t\t");
                    Muda_Cor(Cor_Das_Grades);
                    printf(" \263\n \303\304\304\304\304\304\304\304\304\304\304\305");

                    for(i=0; i<13; i++)
                        printf("\304\304\304\304");

                    printf("\264");

                    for(i=0; i<k; i++)
                    {
                        printf("\n \263");
                        Muda_Cor(Branco);
                        printf(" %-8d ", TAB_PROF[Vet[i]].RP);
                        Muda_Cor(Cor_Das_Grades);
                        printf("\263");
                        Muda_Cor(Branco);
                        printf(" %-50s", TAB_PROF[Vet[i]].Nome);
                        Muda_Cor(Cor_Das_Grades);
                        printf(" \263\n");

                        if(i==(k-1))
                        {
                            printf(" \300\304\304\304\304\304\304\304\304\304");
                            printf("\304\301\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\331");
                        }
                        else
                        {
                            printf(" \303\304\304\304\304\304\304\304\304\304");
                            printf("\304\305\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\304");
                            printf("\304\304\304\304\304\304\304\304\304\304\264");
                        }
                    }

                    fflush(stdin);
                    Muda_Cor(Verde);
                    printf("\n\n     Digite ");
                    Muda_Cor(Cor_Das_Grades);
                    printf("ENTER ");
                    Muda_Cor(Verde);
                    printf("se deseja imprimir outra lista de disciplinas\n     de um professor ou ");
                    Muda_Cor(Cor_Das_Grades);
                    printf("ESC ");
                    Muda_Cor(Verde);
                    printf("para retornar ao MENU: ");
                    Muda_Cor(Branco);

                    Verificar = getch();
                    fflush(stdin);
                }
                while(Verificar != 27 && Verificar != 13);
            }
            else
            {
                Verificar=27;
            }
        }
    }
}
//###############################################################################






//######################### FUN��O PARA SAIR DO PROGRAMA ########################
void Sair_Programa () // SAIR DO PROGRAMA
{
    int i;


    system("cls");

    Muda_Cor(Cor_Das_Grades);
    printf("\n\n\n   \332\304\304\304\304\304\304\304\304\304");

    for(i=0; i<7; i++)
        printf("\304\304\304\304\304\304\304\304");

    printf("\277\n   \263");

    Muda_Cor(Verde);
    printf("      AGRADECEMOS POR UTILIZAR O NOSSO SISTEMA ACADEMICO!!!");

    Muda_Cor(Cor_Das_Grades);
    printf("      \263\n   \263");

    Muda_Cor(Verde);
    printf(" ESPERAMOS QUE TENHA GOSTADO E SURPREENDIDO AS SUAS EXPECTATIVAS");

    Muda_Cor(Cor_Das_Grades);
    printf(" \263\n   \300\304\304\304\304\304\304\304\304\304");

    for(i=0; i<7; i++)
        printf("\304\304\304\304\304\304\304\304");

    printf("\331\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    Muda_Cor(7);
}
//###############################################################################
