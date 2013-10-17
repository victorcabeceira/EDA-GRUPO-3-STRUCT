#include<stdio.h>
#include<stdlib.h>
#include <windows.h> 
#include "Console.h"
   
//Fun��o Main
int main()
{
	// Redimensionando a Janela
	SetWindow(800,600); // Console.h

	// Declara��o de Variaveis
    int opcao=0;
	char grid[40][40];
	struct TVPontos pontos;
	struct TVLinhas linhas;
	struct TVTriangulos triangulos;
	struct TVRetangulos retangulos;
	
    // While para o menu
    while (opcao!=9)
	{
        system("cls");
        AtualizaGrafico(grid,pontos,linhas,triangulos,retangulos); // GeoLib.h
        printf("\n\n\n");
        opcao=Menu(); // Console.h
        system ("cls");
        switch (opcao)
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
            case 5:
				{
					iTriangulo(triangulos);
                    break;
                }
            case 6:
				{
					eTriangulo(triangulos);
                    break;
                }
            case 7:
				{
					iRetangulo(retangulos);
                    break;
                }
            case 8:
				{	
					eRetangulo(retangulos);
                    break;
                }				
        }//Fim do Switch
    }//Fim do While
	if(opcao==9)
		printf("\nFim do Programa!\n\n");
	return 0;
}