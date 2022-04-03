/**
* Autor: Pedro Seixas
* E-mail: a21872@alunos.ipca.pt
* Data: 26/03/2022
*
* Colocar outros contribuintes aqui abaixo:
*
*
*/

//Biblioteca nativa de C
#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

/**
* @brief Opera��es para criar uma nova m�quina com seus par�metros, inserir em lista e listagem para teste
*/
#pragma region Maquinas

/**
*@brief aloca espa�o de mem�ria e cria uma nova m�quina
* @param [in] int cod	            c�digo do n�mero da m�quina
* @param [in] int cod	            quantidade de unidade de tempo
*/
maquina* CriarMaquina(int cod, int tempo) {
	maquina* nova = (maquina*)malloc(sizeof(maquina));
	nova->cod = cod;
	nova->und = tempo;
	nova->nextm = NULL;
	return nova;
}

/**
*@brief fun��o para inserir m�quina no inicio da lista
* @param [in] endere�o da lista de m�quinas
* @param [in] endere�o de mem�ria da nova m�quina com seus dados
*/
maquina* inserirMaqInicio2(maquina* h, maquina* nova) {

	if (h == NULL)
	{
		h = nova;
	}
	else
	{
		nova->nextm = h;
		h = nova;
	}
}

//Fun��o para remover m�quina da lista # efetuar testes #
void RemoverMaq2(maquina* lista, int valor) {
	maquina* inicio = (maquina*)malloc(sizeof(maquina));
	maquina* maquinaremover = NULL;

	inicio->nextm = lista->nextm;

	if (inicio != NULL && lista->cod == valor)
	{
		maquinaremover = lista;
		lista->nextm = maquinaremover->nextm;
	}
	else
	{
		while (inicio != NULL && inicio->nextm != NULL && inicio->nextm->cod != valor)
		{
			inicio = inicio->nextm;
		}
		if (inicio != NULL && inicio->nextm != NULL)
		{
			maquinaremover = inicio->nextm;
			inicio->nextm = maquinaremover->nextm;
		}
	};
	if (maquinaremover != NULL)
	{
		free(maquinaremover);
	}
}

/**
*@brief fun��o para lisar m�quinas cadastradas
* @param [in] endere�o da lista de m�quinas
*/
void listarCrescenteMaq(maquina* inicio)
{
	if (inicio != NULL)
	{
		listarCrescenteMaq(inicio->nextm);
		printf("Maquina %d e unidade de tempo %d\n", inicio->cod, inicio->und);
	}
}

#pragma endregion


/**
* @brief Opera��es para criar um novo Job, inserir em lista e listagem para teste
*/
#pragma region Jobs

/**
*@brief aloca espa�o de mem�ria e cria um novo Job
* @param [in] int cod	            c�digo do n�mero do Job
*/
job* criarJob(int cod) {
	job* novo = (job*)malloc(sizeof(job));
	novo->cod = cod;
	novo->nextJ = NULL;
	novo->nextO = NULL;
	return novo;
}

/**
*@brief fun��o para inserir Job no inicio da lista
* @param [in] endere�o da lista de Jobs
* @param [in] endere�o de mem�ria do novo Job com seus dados
*/
job* inserirJobInicio2(job* h, job* novo) {
	if (h == NULL)
	{
		h = novo;
	}
	else
	{
		novo->nextJ = h;
		h = novo;
	}
}

/**
*@brief fun��o para lisar JObs cadastrados
* @param [in] endere�o da lista de Jobs
*/
void listarCrescenteJob(job* listaj)
{
	if (listaj != NULL)
	{
		listarCrescenteJob(listaj->nextJ);
		printf("Job %d\n", listaj->cod);
	}
}

//
/**
*@brief Inserir lista de opera��es em um determinado Job
* @param [in] endere�o da lista de Jobs
* @param [in] endere�o da lista de Opera��es
* @param [in] int codJob, c�digo do Job para pesquisar na lista o bloco de mem�ria do Job correspondente da lista de opera��es
*/
job* inserirOpenoJob(job* listajob, operacao* listaOp, int codJob) {
	job* a = NULL;
	job* aux = NULL;
	operacao* auxOp = listaOp;

	aux = listajob;

	while (aux != NULL)
	{
		if (aux->cod == codJob)
		{
			a = aux;
		}
		aux = aux->nextJ;
	}
	a->nextO = listaOp->nextOp;

	return a;
}

#pragma endregion


/**
* @brief Opera��es para criar uma nova opera��o, inserir em lista e listagem para teste
*/
#pragma region Operacoes

/**
*@brief aloca espa�o de mem�ria e cria uma nova Opera��o
* @param [in] int cod, c�digo do n�mero da opera��o
*/
operacao* CriarOperacao(int cod) {
	operacao* nova = (operacao*)malloc(sizeof(operacao));
	nova->cod = cod;
	nova->nextM = NULL;
	nova->nextOp = NULL;
}

/**
*@brief fun��o para inserir opera��o no inicio da lista
* @param [in] endere�o da lista de opera��es
* @param [in] endere�o de mem�ria da nova opera��o
*/
operacao* inserirOpeInicio2(operacao* h, operacao* nova) {

	if (h == NULL)
	{
		h = nova;
	}
	else
	{
		nova->nextOp = h;
		h = nova;
	}
}

/**
*@brief Procurar opera��o na lista
* @param [in] endere�o da lista de opera��es
* @param [in] int cod, c�digo do n�mero da opera��o
*/
operacao* procurarOp(operacao* listaOperacao, int cod) {
	operacao* auxOp = NULL;
	operacao* auxOp2 = NULL;

	auxOp2 = listaOperacao;

	int valor = cod;            //Valor do c�digo da opera��o a procurar

	if (auxOp2->nextOp == NULL)
	{
		auxOp = auxOp2;
	}

	while (auxOp2->nextOp != NULL)
	{
		if (auxOp2->cod == valor)
		{
			auxOp = auxOp2;
		}
		auxOp2 = auxOp2->nextOp;
	}
	return auxOp;
}

/**
*@brief Inserir m�quinas em lista de opera��es
* @param [in] endere�o da lista de opera��es
* @param [in] int cadOp, c�digo da opera��o para pesquisar na lista de opera��es
* @param [in] int cadMaq, c�digo da m�quina que ser� informado para a fun��o CriarMaquina
* @param [in] int tempo, unidade de tempo da m�quina que ser� informado para a fun��o CriarMaquina
*/
void InserirMaqnaOpe(operacao* h, int codOp, int codMaq, int tempo) {
	operacao* a = NULL;
	maquina* nova = NULL;
	operacao* auxO = NULL;

	nova = CriarMaquina(codMaq, tempo);
	//printf("maquina %d e tempo%d\n", nova->cod, nova->und); //teste operacional

	auxO = h;

	while (auxO != NULL)
	{
		if (auxO->cod == codOp)
		{
			a = auxO;
		}
		auxO = auxO->nextOp;
	}

	//a = procurarOp(h, codOp);

	a->nextM = inserirMaqInicio2(a->nextM, nova);
}

/**
*@brief fun��o para lisar opera��es cadastradas
* @param [in] endere�o da lista de opera��es
*/
void listarCrescenteOpe(operacao* inicio) {

	if (inicio != NULL)
	{
		listarCrescenteOpe(inicio->nextOp);
		printf("Opera��o %d\n", inicio->cod);
	}
}


#pragma endregion


#pragma region ManipulacaoDados

//Fun��o para gravar os dados das opera��es de um Job em um ficheiro txt
void gravarDadosFicheiro(operacao* lista) {

	FILE* file;
	operacao* aux = lista;

	if (lista == NULL)
	{
		file = fopen("trabalho.txt", "w");
		fprintf(file, "Lista vazia");
	}
	while (aux != NULL)
	{
		file = fopen("trabalho.txt", "a");
		fprintf(file, "Opera��o %d, m�quina %d e tempo %d\n", aux->cod, aux->nextM->cod, aux->nextM->und);
		fclose(file);

		aux = aux->nextOp;
	}
}

#pragma endregion


#pragma region FuncoesEmDesenvolvimento

//Listar as opera��es e suas m�quinas cadastradas
//Fun��o em desenvolvimento, corrigir erro de loop
void listarOpeComMaq(operacao* inicio) {

	while (inicio != NULL)
	{
		if (inicio->cod != NULL && inicio->nextM != NULL)
		{
			printf("Opera��o %d, m�quina %d e tempo %d\n", inicio->cod, inicio->nextM->cod, inicio->nextM->und);

		}

		inicio = inicio->nextOp;
	}
}

//Listar Job com suas respectivas opera��es e Jobs
//Fun��o em desenvolvimento, corrigir pesquisa e apontador de Job para opera��es
void listarJobCompleto(job* inicio, int codJob) {
	
	operacao* a = NULL;
	
	if (inicio->cod == NULL)
	{
		printf("Lista de Jobs vazia");
	}
	else
	{
		if (inicio->cod == codJob)
		{
			a->nextOp = inicio->nextO;

			while (a->nextOp != NULL)
			{
				listarOpeComMaq(a);
				a = a->nextOp;
			}
		}
	}
}

//Fun��o para calcular menor tempo dispon�vel para efetuar um Job
//Em desenvolvimento, corrigir erro de loop na verifica��o da lista de opera��es
void ListarJobMenorTempo(operacao* lista) {
	operacao* a = NULL;
	operacao* auxNext = lista;
	int menor = 0;
	int menor2 = 0;
	int cod = 4;
	if (lista == NULL)
	{
		printf("Lista vazia");
	}
	while (lista->nextOp != NULL)
	{
		while (auxNext != NULL)
		{
			if (auxNext->cod == cod)
			{
				a = auxNext;
			}
			auxNext = auxNext->nextOp;
		}

		while (a->nextM != NULL && a->nextM->nextm != NULL)
		{
			if (a->nextM->und < a->nextM->nextm->und)
			{
				menor = a->nextM->und;
				//printf("%d %d\n", menor, a->nextM->cod);
			}
			else
			{
				menor = a->nextM->nextm->und;
				//printf("%d %d\n", menor, a->nextM->nextm->cod);
			}
			if (menor != 0 && menor2 == 0)
			{
				menor2 = menor;
			}
			if (menor < menor2)
			{
				menor2 = menor;
			}
			a = a->nextM;
		}
		printf("%d", menor2); //Apenas para teste de visualiza��o
		lista = lista->nextOp;
		cod--;
	}
	/*
	if (lista == NULL)
	{
		printf("Lista Vazia, sem opera��es para calcular tempo");
	}
	else
	{
		auxNext = lista;	
		while (lista->nextOp != NULL)
		{
			
			while (lista->nextOp->nextM != NULL)
			{


				if (lista->nextM->und < auxNext->nextM->nextm->und)
				{
					menor = lista->nextM->und;
					printf("%d\n", lista->nextM->cod);
				}
				else
				{
					menor = auxNext->nextM->nextm->und;
					printf("%d\n", auxNext->nextM->nextm->cod);
				}
				lista->nextOp->nextM = lista->nextOp->nextM->nextm;
			}
			printf("%d\n", menor);

			lista = lista->nextOp;
		}
	}*/
}

#pragma endregion

