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

#pragma region FuncoesMaquinas

/**
	* @brief Inserir uma nova m�quina e seus par�metros no in�cio da estrutura
	* @param [in] endere�o lista		Inicio da Lista
	* @param [in] int cod	            c�digo do n�mero da m�quina
	* @param [in] int cod	            quantidade de unidade de tempo
	* @param [in] int cod	            opera��o a que pertencem os par�metros
	* @param [in] int cod	            n�mero do Job ao qual pertencem os par�metros
	*/
void inserirMaqInicio(ListaMaquina *lista, int valor, int tempo, int operacao, int job) {
	maquina* novo = (maquina*)malloc(sizeof(maquina));
	novo->cod = valor;             //Valor do c�digo da nova m�quina
	novo->und = tempo;             //Valor de unidade de tempo
	novo->op = operacao;           //Valor da opera��o cadastrada
	novo->job = job;               //Valor do Job pertencente
	novo->nextm = lista->inicio;   //Novo bloco aponta para o valor do in�cio da lista
	lista->inicio = novo;          //In�cio da lista passa a apontar ao novo bloco
	lista->tam++;                  //incremento na quantidade de elementos na lista
}

/**
	* @brief Inserir uma nova m�quina e seus par�metros no final da estrutura
	* @param [in] endere�o lista		Inicio da Lista
	* @param [in] int cod	            c�digo do n�mero da m�quina
	* @param [in] int cod	            quantidade de unidade de tempo
	* @param [in] int cod	            opera��o a que pertencem os par�metros
	* @param [in] int cod	            n�mero do Job ao qual pertencem os par�metros
	*/
void inserirMaqFim(ListaMaquina* lista, int valor, int tempo, int operacao, int job) {
	maquina* novo = (maquina*)malloc(sizeof(maquina));
	maquina* aux = (maquina*)malloc(sizeof(maquina));
	novo->cod = valor;             //Valor do c�digo da nova m�quina
	novo->und = tempo;             //Valor de unidade de tempo
	novo->op = operacao;           //Valor da opera��o cadastrada
	novo->job = job;               //Valor do job pertencente
	novo->nextm = NULL;            //Novo bloco aponta para NULL pois encontra-se no final da lista.

	if (lista->inicio == NULL) {
		lista->inicio = novo;
	}
	else {
		aux->nextm = lista->inicio;
		while (aux->nextm != NULL)
		{
			aux = aux->nextm;
		}
			aux->nextm = novo;
	}
	lista->tam++;
}
//Op��o para retornar o in�cio da lista
maquina* inserirMaqFim2(ListaMaquina* lista, int valor, int tempo, int operacao, int job) {
	maquina* novo = (maquina*)malloc(sizeof(maquina));
	maquina* aux = (maquina*)malloc(sizeof(maquina));
	novo->cod = valor;             //Valor do c�digo da nova m�quina
	novo->und = tempo;             //Valor de unidade de tempo
	novo->op = operacao;           //Valor da opera��o cadastrada
	novo->job = job;               //Valor do job pertencente
	novo->nextm = NULL;            //Novo bloco aponta para NULL pois encontra-se no final da lista.

	if (lista->inicio == NULL) {
		lista->inicio = novo;
	}
	else {
		aux->nextm = lista->inicio;
		while (aux->nextm != NULL)
		{
			aux = aux->nextm;
		}
		aux->nextm = novo;
		lista->tam++;
	}
}

/**
	* @brief Remover uma determinada m�quina da estrutura
	* @param [in] endere�o lista		Inicio da Lista
	* @param [in] int cod	            c�digo do n�mero da m�quina a remover
	* 
	* ##Procedimento ainda em desenvolvimento##
	*/
void RemoverMaq(ListaMaquina* lista, int valor) {
	maquina* inicio = (maquina*)malloc(sizeof(maquina));
	maquina* maquinaremover = NULL;

	inicio->nextm = lista->inicio;

	if (inicio != NULL && lista->inicio->cod == valor)
	{
		maquinaremover = lista->inicio;
		lista->inicio = maquinaremover->nextm;
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
		lista->tam--;
	}
};

/**
	@brief Procedimento para imprimir e visualizar a lista cadastrada de maquinas e seus par�metros
	@param endere�o de "lista"
	*/
void imprimirMaq(ListaMaquina* lista) {
	maquina* inicio = lista->inicio;
	printf("O tamanho da lista e %d\n", lista->tam);
	while (inicio != NULL)
	{
		printf("Maquina %d\n", inicio->cod);
		printf("Unidade de tempo %d\n", inicio->und);
		printf("Opera��o a que pertence:%d\n", inicio->op);
		printf("Job a que pertence:%d\n\n", inicio->job);
		inicio = inicio->nextm;
	}
	printf("\n");
}
/**
* @brief Procedimento para imprimir e visualizar a lista cadastrada de um Job, suas opera��es
* e m�quinas dispon�veis.
* @param endere�o de "lista" e n�mero do Job, exemplo: int 1, ir� imprimir a lista com as opera��es
* cadastradas para o Job 1
*/
void imprimirListaPorJob(ListaMaquina* lista, int j) {
	maquina* inicio = lista->inicio;
	int valor = j;
	printf("A lista das opera��es dispon�veis para o job %d s�o:\n", valor);
	while (inicio != NULL)
	{
		if (inicio->job == valor)
		{
			printf("Opera��o:%d ;", inicio->op);
			printf("Maquina %d ;", inicio->cod);
			printf("Unidade de tempo %d ;\n", inicio->und);
		}
		inicio = inicio->nextm;
	}
	printf("\n");
}
	//@param endere�o de um ponteiro
void imprimirMaq2(maquina* lista) {
	maquina* inicio = lista->nextm;
		while (inicio != NULL)
		{
			printf("Maquina %d\n", inicio->cod);
			printf("Unidade de tempo %d\n", inicio->und);
			printf("Opera��o a que pertence:%d\n", inicio->op);
			printf("Job a que pertence:%d\n\n", inicio->job);
			inicio = inicio->nextm;
		}
	printf("\n");
}

#pragma endregion

#pragma region FuncoesJobs
//02abr


/**
	* @brief Inserir um novo Job no in�cio da estrutura
	* @param [in] endere�o listaj		Inicio da Lista
	* @param [in] int cod	            c�digo do n�mero do Job
	*/
void inserirJobInicio(ListaJob* listaj, int valor) {
	job* novo = (job*)malloc(sizeof(job));
	novo->cod = valor;              //Valor do c�digo de refer�ncia do job
	novo->nextJ = listaj->inicio;   //Novo bloco aponta para o valor do in�cio da lista
	listaj->inicio = novo;          //In�cio da lista passa a apontar ao novo bloco
	listaj->tam++;                  //Incremento na quantidade de elementos na lista
}


/**
	* @brief Inserir um novo Job no final da estrutura
	* @param [in] endere�o listaj		Inicio da Lista
	* @param [in] int cod	            c�digo do n�mero do Job
	*/
void inserirJobFim(ListaJob* listaj, int valor) {
	job* novo = (job*)malloc(sizeof(job));
	job* aux = (job*)malloc(sizeof(job));
	novo->cod = valor;              //Valor do c�digo de refer�ncia do job
	novo->nextJ = NULL;             //Novo bloco aponta para NULL pois ocupar� o final da lista
	novo->nextO = NULL;             //Apontador para a lista de opera��es do Job correspondente

	if (listaj->inicio == NULL)
	{
		listaj->inicio = novo;
	}
	else
	{
		aux->nextJ = listaj->inicio;
		while (aux->nextJ != NULL)
		{
			aux = aux->nextJ;
		}
		aux->nextJ = novo;
	}
	listaj->tam++;
}
job* inserirJobFim2(ListaJob* listaj, int valor) {
	job* novo = (job*)malloc(sizeof(job));
	job* aux = (job*)malloc(sizeof(job));
	novo->cod = valor;
	novo->nextJ = NULL;
	novo->nextO = NULL;

	if (listaj->inicio == NULL)
	{
		listaj->inicio = novo;
	}
	else
	{
		aux->nextJ = listaj->inicio;
		while (aux->nextJ != NULL)
		{
			aux = aux->nextJ;
		}
		aux->nextJ = novo;
		listaj->tam++;
	}
};

/**
	* @brief Remover um determinado Job da estrutura
	* @param [in] endere�o listaj		Inicio da Lista
	* @param [in] int cod	            c�digo do n�mero do Job a remover
	*/
void RemoverJob(ListaJob* listaj, int valor) {
	job* inicio = (job*)malloc(sizeof(job));
	job* jobremover = NULL;

	inicio->nextJ = listaj->inicio;

	if (inicio != NULL && listaj->inicio->cod == valor)
	{
		jobremover = listaj->inicio;
		listaj->inicio = jobremover->nextJ;
	}
	else
	{
		while (inicio != NULL && inicio->nextJ != NULL && inicio->nextJ->cod != valor)
		{
			inicio = inicio->nextJ;
		}
		if (inicio != NULL && inicio->nextJ != NULL)
		{
			jobremover = inicio->nextJ;
			inicio->nextJ = jobremover->nextJ;
		}
	};
	if (jobremover != NULL)
	{
		free(jobremover);
		listaj->tam--;
	}
};

/**
	@brief Procedimento para imprimir e visualizar a lista cadastrada de Jobs.
	@param endere�o de "listaj"
	*/
void imprimirJob(ListaJob* listaj) {
	job* inicio = listaj->inicio;
	printf("O tamanho da lista e %d\n", listaj->tam);
	while (inicio != NULL)
	{
		printf("Job %d\n", inicio->cod);
		inicio = inicio->nextJ;
		if (listaj->inicio->nextO != NULL)
		{
			printf("As opera��es desse Jobs s�o: %d", inicio->nextO);
			inicio = inicio->nextO;
		}
	}
	printf("\n");
}

#pragma endregion

#pragma region FuncoesOperacoes
//02abr




/**
	* @brief Inserir uma nova opera��o no final da estrutura
	* @param [in] endere�o listaOp		Inicio da Lista
	* @param [in] int valor	            c�digo do n�mero da opera��o
	*/
void inserirOpeFim(ListaOperacao* listaOp, int valor) {
	operacao* novo = (operacao*)malloc(sizeof(operacao));
	operacao* aux = (operacao*)malloc(sizeof(operacao));

	novo->cod = valor;              //Valor inteiro referente ao n�mero da opera��o
	novo->nextOp = NULL;            //Novo bloco aponta para NULL pois ocupar� o final da lista
	novo->nextM = NULL;            //Novo bloco aponta para NULL ou para a lista das m�quinas da sua opera��o

	if (listaOp->inicio == NULL){
		listaOp->inicio = novo;
	}
	else
	{
		aux->nextOp = listaOp->inicio;
		while (aux->nextOp != NULL)
		{
			aux = aux->nextOp;
		}
		aux->nextOp = novo;
	}
	listaOp->tam++;
}

void inserirOpeInicio(ListaOperacao* listaOp, int valor) {
	operacao* novo = (operacao*)malloc(sizeof(operacao));
	novo->cod = valor;
	novo->nextM = NULL;
	novo->nextOp = listaOp->inicio;
	listaOp->inicio = novo;
	listaOp->tam++;
}

//Remover opera��o da lista
void removerOpe(ListaOperacao* listaOp, int valor) {
	operacao* inicio = (operacao*)malloc(sizeof(operacao));
	operacao* removerOperacao = NULL;

	inicio->nextOp = listaOp->inicio;

	if (inicio != NULL && listaOp->inicio->cod == valor)
	{
		removerOperacao = listaOp->inicio;
		listaOp->inicio = removerOperacao->nextOp;
	}
	else
	{
		while (inicio != NULL && inicio->nextOp && inicio->nextOp->cod != valor)
		{
			inicio = inicio->nextOp;
		}
		if (inicio != NULL && inicio->nextOp != NULL)
		{
			removerOperacao = inicio->nextOp;
			inicio->nextOp = removerOperacao->nextOp;
		}
	}
	if (removerOperacao != NULL)
	{
		free(removerOperacao);
	}
}

void imprimirOp(ListaOperacao* listaOp) {
	operacao* inicio = listaOp->inicio;
	printf("O tamanho da lista e %d\n", listaOp->tam);
	while (inicio != NULL)
	{
		printf("Opera��o %d\n", inicio->cod);
		inicio = inicio->nextOp;
	}
	printf("\n");
}

#pragma endregion

#pragma region ProcedimentosFuncoesTestes
//Procedimentos e fun��es em testes
//Fun��o que copia um bloco de mem�ria da lista original de m�quinas.
maquina* copiarbloco(ListaMaquina* lista) {
	if (lista->inicio != NULL)
	{
		maquina* no = lista->inicio;
		lista->inicio = no->nextm;
		return no;
	}
	else return NULL;
}
//Procedimento para montar a lista com as opera��es e m�quinas de um determinado Job
void montarListaJobs(ListaMaquina* lista, ListaMaquina* listaaux, int j) {
	maquina* copiado = (maquina*)malloc(sizeof(maquina));
	maquina* aux = (maquina*)malloc(sizeof(maquina));
	maquina* aux2;
	int valor = j;
	aux = lista->inicio;

	while (aux->nextm != NULL);
	{
		if (aux->job == valor)
		{
			copiado->nextm = aux->nextm;
			copiado->nextm = listaaux->inicio;
			listaaux->inicio = copiado;
				/*copiarbloco(lista);
			inserirMaqFim(listaaux, copiado->cod, copiado->und, copiado->op, copiado->job); */
			free(copiado);
			listaaux->tam++;
		}
		aux = aux->nextm;
	}
}

void imprimirRelatorioJob(ListaJob* listaj, ListaMaquina* lista, ListaOperacao* listaOp, int valor) {
	int j = valor; //Referencia do n�mero do Job

	operacao* op1 = NULL;
	operacao* op2 = NULL;
	operacao* op3 = NULL;
	operacao* op4 = NULL;

	job* j1 = NULL;
	while (listaj->inicio->cod != NULL)
	{
		if (listaj->inicio->cod == j) {
			j1->nextO = listaOp->inicio;
		}
	}
	printf("Opera��es do Job %d\n", j);
	while (j1 != NULL)
	{
		printf("%d", j1->nextO);
		j1 = listaOp->inicio->nextOp;

	}
}



/*
void CriarListaJob(ListaMaquina* lista, int valor, int tempo, int operacao, int job) {
	maquina* inicio = lista->inicio;
	maquina* aux = NULL;
	maquina* novo = NULL;

	novo->cod = valor;
	novo->und = tempo;
	novo->op = operacao;
	novo->job = job;

	if (lista->inicio == NULL)
	{
		lista->inicio = novo;
	}
	else
	{	aux = lista->inicio;
		while (aux->nextm != NULL)
		{
			if (aux->job == valor)
			{
				aux->nextm = novo;
			}
			aux = aux->nextm;
		}
	}
}
*/

#pragma endregion

#pragma region CodigosProfessorJoao
//c�digos do professor Jo�o Carlos

//fun��o para listar as m�quinas cadastradas em ordem decrescente
void listarDecrescenteMaq(maquina* lista)
{
	maquina* aux = lista;
	while (aux != NULL)
	{
		printf("%d\n", aux->cod);
		aux = aux->nextm;
	}
}





//Inserir m�quinas na lista e criar espa�o de m�moria
maquina* inserirInicioM(maquina* inicio, int cod, int tempo, int operacao, int job) {
	maquina* novo = (maquina*)malloc(sizeof(maquina));

	if (novo != NULL)
	{
		novo->cod = cod;
		novo->und = tempo;
		novo->op = operacao;
		novo->job = job;
		novo->nextm = inicio;
		return (novo);
	}
	else return(inicio);
}

//Inserir Jobs na lista e criar espa�o de mem�ria
job* inserirInicioJ(job* head, int cod) {
	job* novo = (job*)malloc(sizeof(job));

	if (novo != NULL)
	{
		novo->cod = cod;
		novo->nextJ = head;
		novo->nextO = NULL;
		return (novo);
	}
	else return(head);
}

#pragma endregion