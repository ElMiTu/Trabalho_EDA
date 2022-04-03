/**
* Autor: Pedro Seixas
* E-mail: a21872@alunos.ipca.pt
* Data: 26/03/2022
*
* Colocar outros contribuintes aqui abaixo:
*
*
*/
/*
//Biblioteca nativa de C
#include <stdio.h>
#include <locale.h>
#include "Lista.h"
*/
/*
int main() {
	setlocale(LC_ALL, "Portuguese");

// @brief Opera��es para inserir um novo Job na lista
#pragma region InserirJobs
	//Inicializa��o da lista de Jobs "listaj"
	ListaJob listaj;
	listaj.inicio = NULL;
	listaj.tam = 0;

	/**
	* @brief Opera��es para inserir um novo Job na lista
	* @param [in] endere�o listaj		Inicio da Lista
	* @param [in] int cod	            c�digo do n�mero do Job
	
	inserirJobFim(&listaj, 1);
	inserirJobFim(&listaj, 2);
	inserirJobFim(&listaj, 3);
	inserirJobFim(&listaj, 4);
	inserirJobFim(&listaj, 5);
	inserirJobFim(&listaj, 6);
	inserirJobFim(&listaj, 7);
	inserirJobFim(&listaj, 8);

	/**
	@brief Procedimento para imprimir e visualizar a lista cadastrada de Jobs
	@param endere�o de "listaj"
	
	imprimirJob(&listaj);

#pragma endregion


// @brief Opera��es para inserir um nova m�quina e seus par�metros conforme tabela
#pragma region InserirMaquinas
	//Inicializa��o da lista de m�quinas
	ListaMaquina lista, listaaux;
	lista.inicio = NULL;
	lista.tam = 0;
	listaaux.inicio = NULL;
	listaaux.tam = 0;

	/**
	* @brief Opera��es para inserir uma nova m�quina e seus par�metros
	* @param [in] endere�o lista		Inicio da Lista
	* @param [in] int cod	            c�digo do n�mero da m�quina
	* @param [in] int cod	            quantidade de unidade de tempo
	* @param [in] int cod	            opera��o a que pertencem os par�metros
	* @param [in] int cod	            n�mero do Job ao qual pertencem os par�metros
	
	//Lista com as m�quinas e opera��es do Job 1
	inserirMaqFim(&lista, 1, 4, 1, 1);
	inserirMaqFim(&lista, 3, 5, 1, 1);
	inserirMaqFim(&lista, 2, 4, 2, 1);
	inserirMaqFim(&lista, 4, 5, 2, 1);
	inserirMaqFim(&lista, 3, 5, 3, 1);
	inserirMaqFim(&lista, 5, 6, 3, 1);
	inserirMaqFim(&lista, 4, 5, 4, 1);
	inserirMaqFim(&lista, 5, 5, 4, 1);
	inserirMaqFim(&lista, 6, 4, 4, 1);
	inserirMaqFim(&lista, 7, 5, 4, 1);
	inserirMaqFim(&lista, 8, 9, 4, 1);

	//Lista com as m�quinas e opera��es do Job 2
	inserirMaqFim(&lista, 1, 1, 1, 2);
	inserirMaqFim(&lista, 3, 5, 1, 2);
	inserirMaqFim(&lista, 5, 7, 1, 2);
	inserirMaqFim(&lista, 4, 5, 2, 2);
	inserirMaqFim(&lista, 8, 4, 2, 2);
	inserirMaqFim(&lista, 4, 1, 3, 2);
	inserirMaqFim(&lista, 6, 6, 3, 2);
	inserirMaqFim(&lista, 4, 4, 4, 2);
	inserirMaqFim(&lista, 7, 4, 4, 2);
	inserirMaqFim(&lista, 8, 7, 4, 2);
	inserirMaqFim(&lista, 4, 1, 5, 2);
	inserirMaqFim(&lista, 6, 2, 5, 2);
	inserirMaqFim(&lista, 1, 5, 6, 2);
	inserirMaqFim(&lista, 6, 6, 6, 2);
	inserirMaqFim(&lista, 8, 4, 6, 2);
	inserirMaqFim(&lista, 4, 4, 7, 2);

	/**
	@brief Procedimento para imprimir e visualizar a lista cadastrada de maquinas e seus par�metros
	@param endere�o de "lista"
	
	imprimirMaq(&lista);

#pragma endregion


// @brief Opera��es para inserir um nova m�quina e seus par�metros conforme tabela
#pragma region InserirOperacoes
	//Inicializa��o da lista de opera��es
	ListaOperacao listaOp;
	listaOp.inicio = NULL;
	listaOp.tam = 0;

	/**
	* @brief Opera��es para inserir uma nova opera��o
	* @param [in] endere�o listaOp		Inicio da Lista
	* @param [in] int cod	            c�digo do n�mero da opera��o
	
	inserirOpeFim(&listaOp, 1);
	inserirOpeFim(&listaOp, 2);
	inserirOpeFim(&listaOp, 3);
	inserirOpeFim(&listaOp, 4);

	/**
	@brief Procedimento para imprimir e visualizar a lista cadastrada de opera��es
	@param endere�o de "lista"
	
	imprimirOp(&listaOp);

#pragma endregion


// @brief Opera��es para imprimir e gravar lista por Job
#pragma region ImpressaoPorJob

	imprimirListaPorJob(&lista, 1);
	imprimirListaPorJob(&lista, 2);

#pragma endregion

	
	montarListaJobs(&lista, &listaaux, 1);
	imprimirMaq(&listaaux);
	
	
} */