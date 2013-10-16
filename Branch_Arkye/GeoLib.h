/* GeoLib.h é uma biblioteca que compõe todas as funções e procedimentos para a execução de tarefas
 * requisitadas na prática de Structs, desenvolvido para a o Trabalho 01 de EDA 2/2013.
 */

// Sumário
/* Structs
 * -> TPonto
 * -> TVPontos
 * Funções/Procedimentos
 * -> void AtualizaGrafico(TVPontos)
 * -> void PlotaPonto(TVPontos, TPonto, char)
 */
 
// Structs das Figuras Geométricas
// Ponto
struct TPonto{
	int x;
	int y;
	char simb;
	struct TPonto *Prox;
	TPonto(){x=40, y=40, simb=',', Prox=NULL;}
};

// Structs dos Conjuntos de Figuras Geométricas
// Pontos
struct TVPontos{
	struct TPonto Elementos[5];
	int Qtde;
	TVPontos(){Qtde = 0;}
};
	

// Função para Atualizar o Grid
void AtualizaGrafico(char grid[40][40], TVPontos ppontos)
{
	int imp=0;
	for(int j=0; j<41; j++) // Cadeia de Linhas
	{
		for(int i=0; i<42; i++) // Cadeia de Colunas
		{
			// Imprindo as Coordenadas
			// Colunas
			if(j==0)
			{
				if (i==0)
					printf("   ");
				else if((i>0)&&(i<11))
					printf("0%d ", i-1);
				else if ((i>10)&&(i<41))
					printf("%d ", i-1);
				else if(i==41)
					printf("\n\n");
			}
			// Linhas
			if(i==0)
			{
				if((j>0)&&(j<11))
					printf("0%d ", j-1);
				else if ((j>10)&&(j<41))
					printf("%d ", j-1);
			}
			// Imprimindo o Grid
			if((i>=1)&&(j>=1))
			{
				if(i==41) // Caso para pular linha
					printf("\n\n");
				else
				{
					// Sequencia de Hierarquia 01: Plotando Pontos
					if(ppontos.Qtde!=0)
					{
						for(int k=0; k<=ppontos.Qtde; k++)
						{
							if(ppontos.Elementos[k].x == i-1)
							{
								if(ppontos.Elementos[k].y == j-1)
								{
									grid[i][j] = ppontos.Elementos[k].simb;
									imp++;
								}
							}
						}
						if (imp==0)
							grid[i][j] = '.';
						else
							imp=0;
					}
					else if(ppontos.Qtde==0)
						grid[i][j] = '.';
					printf(" %c ", grid[i][j]);
				}
			}
		}	
	}
}

// Função para adicionar o Ponto no Conjunto de Pontos
void PlotaPonto(struct TVPontos &pontos, const struct TPonto &ptr, char psimbolo)
{
	pontos.Elementos[pontos.Qtde].x = ptr.x;
	pontos.Elementos[pontos.Qtde].y = ptr.y;
	pontos.Elementos[pontos.Qtde].simb = psimbolo;
	pontos.Qtde++;
}
