/* GeoLib.h é uma biblioteca que compõe todas as funções e procedimentos para a execução de tarefas
 * requisitadas na prática de Structs, desenvolvido para a o Trabalho 01 de EDA 2/2013.
 */

// Sumário
/* Structs
 * -> TPonto
 * -> TLinha
 * -> TVPontos
 * -> TVLinhas
 * Tratamentos de Listas
 * -> *IncluiCalda(TPonto,int,int,char)
 * Funções/Procedimentos
 * -> void AtualizaGrafico(TVPontos)
 * -> void PlotaPonto(TVPontos, TPonto, char)
 * -> void PlotaLinha(TVLinhas, TLinha, char)
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

// Linha
struct TLinha{
	struct TLinha *Ant;	
	struct TPonto Ponto1;
	struct TPonto Ponto2;
	struct TLinha *Prox;
	TLinha(){Ant=NULL, Ponto1=TPonto(), Ponto2=TPonto(), Prox=NULL;}
};

// Structs dos Conjuntos de Figuras Geométricas
// Pontos
struct TVPontos{
	struct TPonto Elementos[5];
	int Qtde;
	TVPontos(){Qtde = 0;}
};

// Linhas
struct TVLinhas{
	struct TLinha Elementos[5];
	int Qtde;
	TVLinhas(){Qtde = 0;}
};

// Funções de Tratamento de Listas
TPonto *IncluiCalda(TPonto *pLista, int x, int y, char psimbolo)
{
	TPonto *pNovoNo, *pAux;
	pNovoNo = (TPonto*) malloc(sizeof(TPonto));
	pNovoNo->x = x;
	pNovoNo->y = y;
	pNovoNo->simb = psimbolo;
	pNovoNo->Prox = NULL;
	pAux = pLista;
	while(pAux->Prox!=NULL)
		pAux = pAux->Prox;
	pAux->Prox = pNovoNo;
	return pLista;
}

// Função para Atualizar o Grid
void AtualizaGrafico(char grid[40][40], struct TVPontos &ppontos, struct TVLinhas &plinhas)
{
	int imp=0, k=0;
	TPonto *Aux;
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
					// Sequencia de Hierarquia 02: Plotando Linhas
					if(plinhas.Qtde!=0)
					{
						for(k=0; k<plinhas.Qtde; k++)
						{
							// Ponto 1
							if(plinhas.Elementos[k].Ponto1.x == i-1)
							{
								if(plinhas.Elementos[k].Ponto1.y == j-1)
								{
									grid[i][j] = plinhas.Elementos[k].Ponto1.simb;
									imp++;
									break;
								}
							}
							// Nós
							else
							{
								Aux = plinhas.Elementos[k].Ponto1.Prox;
								while(Aux != NULL)
								{
									if(Aux->x == i-1)
									{
										if(Aux->y == j-1)
										{
											grid[i][j] = Aux->simb;
											imp++;
											break;
										}
									}
									Aux = Aux->Prox;
								}
							}
							// Ponto2
							if(plinhas.Elementos[k].Ponto2.x == i-1)
							{
								if(plinhas.Elementos[k].Ponto2.y == j-1)
								{
									grid[i][j] = plinhas.Elementos[k].Ponto2.simb;
									imp++;
									break;
								}
							}
						}
						if(imp==0)
							grid[i][j] = '.';
						else
							imp=0;
					}
						
					// Sequencia de Hierarquia 01: Plotando Pontos
					if(ppontos.Qtde!=0)
					{
						for(k=0; k<ppontos.Qtde; k++)
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
					else if((ppontos.Qtde==0)&&(plinhas.Qtde==0))
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

void PlotaLinha(struct TVLinhas &linhas, struct TLinha &ptr, char psimbolo)
{
	// Variaveis Locais
	float a = 0, b = 0, sX=0, sX2=0, sY=0, sXY=0, tX=0;
	int maxY = 0, y=0, t=0, x=0, minY =0, i=0, antX=0;
	TPonto *pPonto;
	pPonto = (TPonto *) malloc(sizeof(TPonto));
	pPonto = &ptr.Ponto1;
	// Calculo da Reta
	sX = ptr.Ponto1.x + ptr.Ponto2.x;
	sX2 = (ptr.Ponto1.x*ptr.Ponto1.x) + (ptr.Ponto2.x*ptr.Ponto2.x);
	sY = ptr.Ponto1.y + ptr.Ponto2.y;
	sXY = (ptr.Ponto1.x*ptr.Ponto1.y) + (ptr.Ponto2.x*ptr.Ponto2.y);
	a = ((sX2*sY) - (sX*sXY))/((2*sX2) - (sX*sX));
	b = ((2*sXY) - (sX*sY))/((2*sX2) - (sX*sX));
	
	// Calculo de ajuste de float para inteiro
	if (ptr.Ponto1.y > ptr.Ponto2.y)
	{
		maxY = ptr.Ponto1.y;
		minY = ptr.Ponto2.y;
	}
	else
	{
		maxY = ptr.Ponto2.y;
		minY = ptr.Ponto1.y;
	}
	for(y=minY+1;y<maxY;y++)
	{
		antX = x;
		tX = (y - a)/b;
		for(t=0;t<40;t++)
		{
			if(t==tX)
				break;
			if(t>tX)
			{
				if(tX-t-1 > t-tX)
				{
					tX=t;
					break;
				}
				else
				{
					tX=t-1;
					break;
				}
			}
		}
		x = int(tX);
			pPonto = IncluiCalda(pPonto,x,y,psimbolo);
		if(antX!=0)
		{
			if(antX!=x)
			{
				if(antX>x+1)
				{
					for(i=antX;i>x;i--)
						pPonto = IncluiCalda(pPonto,i,y,psimbolo);
				}
				else if(antX+1<x)
				{
					for(i=antX;i<x;i++)
						pPonto = IncluiCalda(pPonto,i,y,psimbolo);
				}
			}
		}	
	}
	linhas.Elementos[linhas.Qtde].Ponto1.x = pPonto->x;
	linhas.Elementos[linhas.Qtde].Ponto1.y = pPonto->y;
	linhas.Elementos[linhas.Qtde].Ponto2.x = ptr.Ponto2.x;
	linhas.Elementos[linhas.Qtde].Ponto2.y = ptr.Ponto2.y;	
	linhas.Elementos[linhas.Qtde].Ponto1.Prox = pPonto->Prox;
	linhas.Elementos[linhas.Qtde].Ponto1.simb = psimbolo;
	linhas.Elementos[linhas.Qtde].Ponto2.simb = psimbolo;
	linhas.Qtde++;
}