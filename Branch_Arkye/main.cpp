#include<stdio.h>
#include<stdlib.h>
#include <windows.h> 
#include "Console.h"
   
//Função Main
int main()
{
	// Redimensionando a Janela
	SetWindow(800,600); // Console.h

	// Declaração de Variaveis
    int opcao=0;
	char grid[40][40];
	struct TVPontos pontos;
	struct TVLinhas linhas;
	
    // While para o menu
    while (opcao!=9)
	{
        system("cls");
        AtualizaGrafico(grid,pontos,linhas); // GeoLib.h
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
            case 4:
				{
                    break;
                }
            case 5:
				{
                    break;
                }
            case 6:
				{
                    break;
                }
            case 7:
				{
                    break;
                }
            case 8:
				{
                    break;
                }				
        }//Fim do Switch
    }//Fim do While

    printf("\nFim do Programa!\n\n");
    system("pause");
	return 0;
}