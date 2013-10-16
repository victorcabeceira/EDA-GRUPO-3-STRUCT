/* GeoLib.h � uma biblioteca que comp�e todas as fun��es e procedimentos para a execu��o de tarefas
 * requisitadas na pr�tica de Structs, desenvolvido para a o Trabalho 01 de EDA 2/2013.
 */

// Sum�rio
/* Structs
 * -> TPonto
 * -> TLinha
 * -> TVPontos
 * -> TVLinhas
 * Tratamentos de Listas
 * -> *IncluiCalda(TPonto,int,int,char)
 * Fun��es/Procedimentos
 * -> void AtualizaGrafico(TVPontos)
 * -> void PlotaPonto(TVPontos, TPonto, char)
 * -> void PlotaLinha(TVLinhas, TLinha, char)
 */
 
// Structs das Figuras Geom�tricas
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
	struct TPonto Ponto1;
	struct TPonto Ponto2;
	TLinha(){Ponto1=TPonto(), Ponto2=TPonto();}
};

// Triangulo
struct TTriangulo{
	struct TPonto Ponto1;
	int alt;
	int larg;
	bool neg_alt;
	bool neg_larg;
	TTriangulo(){Ponto1=TPonto(), alt=0, larg=0, neg_alt=0, neg_larg=0;}
};

// Retangulo
struct TRetangulo{
	struct TPonto Ponto1;
	struct TPonto Ponto2;
	TRetangulo(){Ponto1=TPonto(),Ponto2=TPonto();}
};

// Structs dos Conjuntos de Figuras Geom�tricas
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

// Triangulos
struct TVTriangulos{
	struct TTriangulo Elementos[5];
	int Qtde;
	TVTriangulos(){Qtde = 0;}
};

// Retangulos
struct TVRetangulos{
	struct TRetangulo Elementos[5];
	int Qtde;
	TVRetangulos(){Qtde = 0;}
};

// Fun��es de Tratamento de Listas
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

// Fun��o para Atualizar o Grid
void AtualizaGrafico(char grid[40][40], struct TVPontos &ppontos, struct TVLinhas &plinhas, struct TVTriangulos &ptriangs, struct TVRetangulos &prets)
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
					// Senquencia de Hierarquia 04: Plotando Retangulos
					if(prets.Qtde!=0)
					{
						for(k=0; k<prets.Qtde; k++)
						{
							// Ponto 1
							if(prets.Elementos[k].Ponto1.x == i-1)
							{
								if(prets.Elementos[k].Ponto1.y == j-1)
								{
									grid[i][j] = prets.Elementos[k].Ponto1.simb;
									imp++;
									break;
								}
							}
							// N�s
							else
							{
								Aux = prets.Elementos[k].Ponto1.Prox;
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
							if(prets.Elementos[k].Ponto2.x == i-1)
							{
								if(prets.Elementos[k].Ponto2.y == j-1)
								{
									grid[i][j] = prets.Elementos[k].Ponto2.simb;
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
					
					// Sequencia de Hierarquia 03: Plotando Triangulos
					if(ptriangs.Qtde!=0)
					{
						for(k=0; k<ptriangs.Qtde; k++)
						{
							// Ponto 1
							if(ptriangs.Elementos[k].Ponto1.x == i-1)
							{
								if(ptriangs.Elementos[k].Ponto1.y == j-1)
								{
									grid[i][j] = ptriangs.Elementos[k].Ponto1.simb;
									imp++;
									break;
								}
							}
							// N�s
							else
							{
								Aux = ptriangs.Elementos[k].Ponto1.Prox;
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
						}
						if(imp==0)
							grid[i][j] = '.';
						else
							imp=0;
					}					
					
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
							// N�s
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
					
					if((ppontos.Qtde==0)&&(plinhas.Qtde==0)&&(ptriangs.Qtde==0)&&(prets.Qtde==0))
						grid[i][j] = '.';
						
					printf(" %c ", grid[i][j]);
				}
			}
		}	
	}
}

// Fun��o para adicionar o Ponto no Conjunto de Pontos
void PlotaPonto(struct TVPontos &pontos, const struct TPonto &ptr, char psimbolo)
{
	pontos.Elementos[pontos.Qtde].x = ptr.x;
	pontos.Elementos[pontos.Qtde].y = ptr.y;
	pontos.Elementos[pontos.Qtde].simb = psimbolo;
	pontos.Qtde++;
}

// Fun��o para adicionar a Linha no Conjunto de Linhas
void PlotaLinha(struct TVLinhas &linhas, struct TLinha &ptr, char psimbolo)
{
	// Variaveis Locais
	float a = 0, b = 0, sX=0, sX2=0, sY=0, sXY=0, tX=0;
	int maxY = 0, y=0, t=0, x=0, minY =0, i=0, antX=0;
	TPonto *pPonto;
	pPonto = (TPonto *) malloc(sizeof(TPonto));
	pPonto = &ptr.Ponto1;
	if(ptr.Ponto1.x == ptr.Ponto2.x)
	{
		if(ptr.Ponto1.y > ptr.Ponto2.y)
		{
			for(i=ptr.Ponto1.y;i<ptr.Ponto2.y;i++)
				pPonto = IncluiCalda(pPonto,ptr.Ponto1.x,i,psimbolo);
		}
		else
		{
			for(i=ptr.Ponto2.y; i<ptr.Ponto1.y;i++)
				pPonto = IncluiCalda(pPonto,ptr.Ponto1.x,i,psimbolo);
		}
	}
	else if(ptr.Ponto1.y == ptr.Ponto2.y)
	{
		if(ptr.Ponto1.x > ptr.Ponto2.x)
		{
			for(i=ptr.Ponto1.x;i<ptr.Ponto2.x;i++)
				pPonto = IncluiCalda(pPonto,i,ptr.Ponto1.y,psimbolo);
		}
		else
		{
			for(i=ptr.Ponto2.x;i<ptr.Ponto2.x;i++)
				pPonto = IncluiCalda(pPonto,i,ptr.Ponto1.y,psimbolo);
		}
	}
	else
	{
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
			if((antX!=0)&&(antX!=x))
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
// Fun��o para adicionar o Triangulo no Conjunto de Triangulos
void PlotaTriangulo(struct TVTriangulos &triangulos, struct TTriangulo &ptr, char psimbolo)
{
	float a = 0, b = 0, sX=0, sX2=0, sY=0, sXY=0, tX=0;
	int maxY = 0, y=0, t=0, x=0, minY =0, i=0, antX=0, tY=0, tX2=0;
	TPonto *pPonto;
	pPonto = (TPonto *) malloc(sizeof(TPonto));
	pPonto = &ptr.Ponto1;
	
	if(ptr.neg_alt==0)
	{
		if(ptr.neg_larg==0)
		{
			for(i=ptr.Ponto1.y;i>=(ptr.Ponto1.y-ptr.alt);i--)
			{
				pPonto = IncluiCalda(pPonto,ptr.Ponto1.x,i,psimbolo);
			}
			for(i=ptr.Ponto1.x;i>=(ptr.Ponto1.x-ptr.larg);i--)
			{
				pPonto = IncluiCalda(pPonto,i,ptr.Ponto1.y,psimbolo);
			}
			x = ptr.Ponto1.x - ptr.larg;
			y = ptr.Ponto1.y - ptr.alt;
		}
		else
		{
			for(i=ptr.Ponto1.y;i>=(ptr.Ponto1.y-ptr.alt);i--)
			{
				pPonto = IncluiCalda(pPonto,ptr.Ponto1.x,i,psimbolo);
			}
			for(i=ptr.Ponto1.x;i<=ptr.Ponto1.x+ptr.larg;i++)
			{
				pPonto = IncluiCalda(pPonto,i,ptr.Ponto1.y,psimbolo);
			}
			x = ptr.Ponto1.x + ptr.larg;
			y = ptr.Ponto1.y - ptr.alt;				
		}
	}
	else
	{
		if(ptr.neg_larg==0)
		{
			for(i=ptr.Ponto1.y;i<=ptr.Ponto1.y+ptr.alt;i++)
			{
				pPonto = IncluiCalda(pPonto,ptr.Ponto1.x,i,psimbolo);
			}
			for(i=ptr.Ponto1.x;i>=ptr.Ponto1.x-ptr.larg;i--)
			{
				pPonto = IncluiCalda(pPonto,i,ptr.Ponto1.y,psimbolo);
			}
			x = ptr.Ponto1.x - ptr.larg;
			y = ptr.Ponto1.y + ptr.alt;				
		}
		else
		{
			for(i = (ptr.Ponto1.y + 1) ; i <= (ptr.Ponto1.y + ptr.alt) ; i++)
			{
				pPonto = IncluiCalda(pPonto,ptr.Ponto1.x,i,psimbolo);
			}
			for(i = (ptr.Ponto1.x + 1) ; i <= (ptr.Ponto1.x + ptr.larg) ; i++)
			{
				pPonto = IncluiCalda(pPonto,i,ptr.Ponto1.y,psimbolo);
			}
			x = ptr.Ponto1.x + ptr.larg;
			y = ptr.Ponto1.y + ptr.alt;
		}
	}
	
	// Calculo da Reta
	sX = ptr.Ponto1.x + x;
	sX2 = (ptr.Ponto1.x*ptr.Ponto1.x) + (x*x);
	sY = ptr.Ponto1.y + y;
	sXY = (ptr.Ponto1.x*ptr.Ponto1.y) + (x*y);
	a = ((sX2*sY) - (sX*sXY))/((2*sX2) - (sX*sX));
	b = ((2*sXY) - (sX*sY))/((2*sX2) - (sX*sX));
	
	// Calculo de ajuste de float para inteiro
	if (ptr.Ponto1.y > y)
	{
		maxY = ptr.Ponto1.y;
		minY = y;
	}
	else
	{
		maxY = y;
		minY = ptr.Ponto1.y;
	}
	for(tY = (minY + 1); tY < maxY ; tY++)
	{
		antX = tX2;
		tX = (tY - a)/b;
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
		tX2 = int(tX);
		pPonto = IncluiCalda(pPonto,tX2,tY,psimbolo);
		
		if(antX!=0)
		{
			if(antX!=tX2)
			{
				if(antX>tX2+1)
				{
					for(i=antX;i>tX2;i--)
						pPonto = IncluiCalda(pPonto,i,y,psimbolo);
				}
				else if(antX+1<tX2)
				{
					for(i=antX;i<tX2;i++)
						pPonto = IncluiCalda(pPonto,i,y,psimbolo);
				}
			}
		}	
	}	
	triangulos.Elementos[triangulos.Qtde].Ponto1.x = pPonto->x;
	triangulos.Elementos[triangulos.Qtde].Ponto1.y = pPonto->y;
	triangulos.Elementos[triangulos.Qtde].Ponto1.Prox = pPonto->Prox;
	triangulos.Elementos[triangulos.Qtde].Ponto1.simb = psimbolo;
	triangulos.Qtde++;	
}

// Fun��o para adiconar o Retangulo no Conjunto de Retangulos
void PlotaRetangulo(struct TVRetangulos &retangulos, struct TRetangulo &ptr, char psimbolo)
{
	int i=0;
	TPonto *pPonto;
	pPonto = (TPonto *) malloc(sizeof(TPonto));
	pPonto = &ptr.Ponto1;
	if(ptr.Ponto1.x > ptr.Ponto2.x)
	{
		for(i=ptr.Ponto2.x;i<=ptr.Ponto1.x;i++)
		{
			pPonto = IncluiCalda(pPonto,i,ptr.Ponto1.y,psimbolo);
			pPonto = IncluiCalda(pPonto,i,ptr.Ponto2.y,psimbolo);
		}
		if(ptr.Ponto1.y > ptr.Ponto2.y)
		{	
			for(i=ptr.Ponto2.y;i<=ptr.Ponto1.y;i++)
			{
				pPonto = IncluiCalda(pPonto,ptr.Ponto1.x,i,psimbolo);
				pPonto = IncluiCalda(pPonto,ptr.Ponto2.x,i,psimbolo);
			}
		}
		else
		{	
			for(i=ptr.Ponto1.y;i<=ptr.Ponto2.y;i++)
			{
				pPonto = IncluiCalda(pPonto,ptr.Ponto1.x,i,psimbolo);
				pPonto = IncluiCalda(pPonto,ptr.Ponto2.x,i,psimbolo);
			}
		}
	}
	else
	{
		for(i=ptr.Ponto1.x;i<=ptr.Ponto2.x;i++)
		{
			pPonto = IncluiCalda(pPonto,i,ptr.Ponto1.y,psimbolo);
			pPonto = IncluiCalda(pPonto,i,ptr.Ponto2.y,psimbolo);
		}
		if(ptr.Ponto1.y > ptr.Ponto2.y)
		{	
			for(i=ptr.Ponto2.y;i<=ptr.Ponto1.y;i++)
			{
				pPonto = IncluiCalda(pPonto,ptr.Ponto1.x,i,psimbolo);
				pPonto = IncluiCalda(pPonto,ptr.Ponto2.x,i,psimbolo);
			}
		}
		else
		{	
			for(i=ptr.Ponto1.y;i<=ptr.Ponto2.y;i++)
			{
				pPonto = IncluiCalda(pPonto,ptr.Ponto1.x,i,psimbolo);
				pPonto = IncluiCalda(pPonto,ptr.Ponto2.x,i,psimbolo);
			}
		}
	}
	retangulos.Elementos[retangulos.Qtde].Ponto1.x = pPonto->x;
	retangulos.Elementos[retangulos.Qtde].Ponto1.y = pPonto->y;
	retangulos.Elementos[retangulos.Qtde].Ponto2.x = ptr.Ponto2.x;
	retangulos.Elementos[retangulos.Qtde].Ponto2.y = ptr.Ponto2.y;	
	retangulos.Elementos[retangulos.Qtde].Ponto1.Prox = pPonto->Prox;
	retangulos.Elementos[retangulos.Qtde].Ponto1.simb = psimbolo;
	retangulos.Elementos[retangulos.Qtde].Ponto2.simb = psimbolo;
	retangulos.Qtde++;
}