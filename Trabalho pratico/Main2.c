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
#include <locale.h>
#include "Lista.h"

int main() {
	setlocale(LC_ALL, "Portuguese");

	/**
	* @brief Opera��es para criar uma nova m�quina com seus par�metros
	*/
	#pragma region CriarMaquina
	/**
	* @param [in] endere�o listaInicio		Inicio da Lista
	*/
	maquina* listaInicio;
	listaInicio = NULL;

	/**
	* @brief Criar nova m�quina para posterior inser��o em lista de opera��es
	* @param [in] c�digo da m�quina
	* @param [in] unidade de tempo
	*/
	maquina* nova;
	nova = CriarMaquina(1, 4);
	listaInicio = inserirMaqInicio2(listaInicio, nova);

	printf("Listagem teste de inser��o de m�quina\n");
	listarCrescenteMaq(listaInicio);

	#pragma endregion

	/**
	* @brief Opera��es para criar um novo Job
	*/
	#pragma region CriarJob
	/**
	* @param [in] endere�o listajInicio		Inicio da Lista
	*/
	job* listajInicio;
	listajInicio = NULL;

	/**
	* @brief Criar novo Job para posterior inser��o em lista de Jobs
	* @param [in] c�digo do Job
	*/
	job* novo;
	novo = criarJob(1);
	listajInicio = inserirJobInicio2(listajInicio, novo);
	novo = criarJob(2);
	listajInicio = inserirJobInicio2(listajInicio, novo);

	printf("\n");
	listarCrescenteJob(listajInicio); //Teste de visualiza��o da lista de Job

	#pragma endregion

	/**
	* @brief Opera��es para criar uma nova opera��o
	*/
	#pragma region CriarOperacao

	/**
	* @param [in] endere�o listaOperacao		Inicio da Lista
	*/
	operacao* listaOperacao;
	listaOperacao = NULL;

	/**
	* @brief Criar nova opera��o para posterior inser��o em lista de opera��es
	* @param [in] c�digo da opera��o
	*/
	operacao* novaOperacao;
	novaOperacao = CriarOperacao(1);
	listaOperacao = inserirOpeInicio2(listaOperacao, novaOperacao);
	novaOperacao = CriarOperacao(2);
	listaOperacao = inserirOpeInicio2(listaOperacao, novaOperacao);
	novaOperacao = CriarOperacao(3);
	listaOperacao = inserirOpeInicio2(listaOperacao, novaOperacao);
	novaOperacao = CriarOperacao(4);
	listaOperacao = inserirOpeInicio2(listaOperacao, novaOperacao);

	printf("\n");
	listarCrescenteOpe(listaOperacao); //Teste de visualiza��o da lista de Opera��es

	#pragma endregion

	/**
	* @brief Opera��es para inserir m�quinas nas opera��es
	*/
	#pragma region InserirMaquinaOperacao

	/**
	* @brief Criar e inserir m�quina em opera��o pr� definida na lista de opera��es
	* @param [in] c�digo da opera��o
	* @param [in] c�digo da m�quina
	* @param [in] quantidade de unidade de tempo para execu��o da opera��o na m�quina
	*/
	//Fun��o procura a respectiva opera��o na lista e adiciona a m�quina com seus par�metros.
	InserirMaqnaOpe(listaOperacao, 1, 1, 4);
	InserirMaqnaOpe(listaOperacao, 1, 3, 5);
	InserirMaqnaOpe(listaOperacao, 2, 2, 4);
	InserirMaqnaOpe(listaOperacao, 2, 4, 5);
	InserirMaqnaOpe(listaOperacao, 3, 3, 5);
	InserirMaqnaOpe(listaOperacao, 3, 5, 6);
	InserirMaqnaOpe(listaOperacao, 4, 4, 5);
	InserirMaqnaOpe(listaOperacao, 4, 5, 5);
	InserirMaqnaOpe(listaOperacao, 4, 6, 4);
	InserirMaqnaOpe(listaOperacao, 4, 7, 5);
	InserirMaqnaOpe(listaOperacao, 4, 8, 9);

	printf("\n");
	listarOpeComMaq(listaOperacao); //Teste de visualiza��o da lista de Opera��es

	#pragma endregion


	#pragma region ManipulacaoDados

	gravarDadosFicheiro(listaOperacao);

	#pragma endregion
}