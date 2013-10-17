/* O que o programa faz?
 * R: insere Figuras Geom�tricas em um campo de 40x40 pontos
 * Arquivos Anexos: Console.h, GeoLib.h
 * Disciplina: Estrutura de Dados e Algoritmos - 193704
 * Professor: Nilton Correia da Silva
 * Turma: B
 * Tarefa: Trabalho Pr�tico (Structs)
 * Data de T�rmino: 16/10/2013
 * Integrantes:
 * -> Dennis L�cio Merli Rodrigues
 * --> GitHub: https://github.com/neneds
 * -> Henrique Augusto Pereira dos Santos
 * --> GitHub: 
 * -> Iago Mendes Leite
 * --> GitHub:
 * -> Jonathan Henrique Maia de Moraes
 * --> GitHub: https://github.com/arkye
 * -> Ricardo Gon�alves Teixeira
 * --> GitHub: https://github.com/ricardogtx
 * -> Victor Fellipe Gon�alves Cabeceira
 * --> GitHub: https://github.com/victorcabeceira
 */

// Bibliotecas
#include<stdio.h>
#include<stdlib.h>
#include<windows.h> 
#include "Console.h"
   
// Fun��o Main
int main()
{
	// Redimensionando a Janela
	SetWindow(800,600); // Console.h

	// Declara��o de Variaveis
    int opcao=0;
	char grid[41][41];
	struct TVPontos pontos;
	struct TVLinhas linhas;
	struct TVTriangulos triangulos;
	struct TVRetangulos retangulos;
	
    // While para o Menu
    while (opcao!=9)
	{
        system("cls");
        AtualizaGrafico(grid,pontos,linhas,triangulos,retangulos); // GeoLib.h	
        opcao=Menu(); // Console.h	
        system ("cls");
        switch (opcao) // Tratamento da Op��o Escolhida
		{
            case 1: // Incluir Ponto
				{
					iPonto(pontos); // Console.h
					break;
                }
            case 2: // Excluir Ponto
				{
					ePonto(pontos); // Console.h
                    break;
                }
            case 3: // Incluir Linha
				{
					iLinha(linhas); // Console.h
                    break;
                }
            case 4: // Excluir Linha
				{
					eLinha(linhas); // Console.h
                    break;
                }
            case 5: // Incluir Triangulo
				{
					iTriangulo(triangulos); // Console.h
                    break;
                }
            case 6: // Excluir Triangulo
				{
					eTriangulo(triangulos); // Console.h
                    break;
                }
            case 7: // Incluir Retangulo
				{
					iRetangulo(retangulos); // Console.h
                    break;
                }
            case 8: // Excluir Retangulo
				{	
					eRetangulo(retangulos); // Console.h
                    break;
                }				
        }
    }
	// Impress�es finais
	printf("\nFim do Programa!\n\n");
	system("PAUSE");
	return 0;
}