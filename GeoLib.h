/* GeoLib.h é uma biblioteca que compõe todas as funções e procedimentos para a execução de tarefas
 * requisitadas na prática de Structs, desenvolvido para a o Trabalho 01 de EDA 2/2013.
 */

// Sumário
/* Structs
 * -> TPonto
 * -> TLinha
 * -> TTriangulo
 * -> TRetangulo
 * -> TVPontos
 * -> TVLinhas
 * -> TVTriangulos
 * -> TVRetangulos
 * Tratamentos de Listas
 * -> *IncluiCalda(TPonto,int,int,char)
 * Tratamentos de Linhas
 * -> *GeraLinha(*TPonto, TLinha, char)
 * Funções/Procedimentos
 * -> void AtualizaGrafico(TVPontos)
 * -> void PlotaPonto(TVPontos, TPonto, char)
 * -> void PlotaLinha(TVLinhas, TLinha, char)
 * -> void PlotaTriangulo(TVTriangulos, TTriangulo, char)
 * -> void PlotaRetangulo(TVRetangulos, TRetangulo, char)
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
	struct TPonto Ponto1;
	struct TPonto Ponto2;
	TLinha(){Ponto1=TPonto(), Ponto2=TPonto();}
};

// Triangulo
struct TTriangulo{
	struct TLinha Linha1;
	struct TLinha Linha2;
	struct TLinha Linha3;
	int alt;
	int larg;
	bool neg_alt;
	bool neg_larg;
	TTriangulo(){Linha1=TLinha(), Linha2=TLinha(), Linha3=TLinha(), alt=0, larg=0, neg_alt=0, neg_larg=0;}
};

// Retangulo
struct TRetangulo{
	struct TLinha Linha1;
	struct TLinha Linha2;
	struct TLinha Linha3;
	struct TLinha Linha4;
	TRetangulo(){Linha1=TLinha(),Linha2=TLinha(), Linha3=TLinha(), Linha4=TLinha();}
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

// Funções de Tratamento de Listas -> Inclusão
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

// Funções de Tratamento de Linhas -> Gerar Linhas
TPonto *GeraLinha(TPonto *pPonto, TLinha &ptr, char psimbolo)
{
	// Variaveis Locais
	float a = 0, b = 0, sX=0, sX2=0, sY=0, sXY=0, tX=0, tY=0;
	int maxX = 0, maxY = 0, y=0, t=0, x=0, minX = 0, minY =0, i=0, mTermo=0;
	
	// Casos de Linhas Horizontais ou Verticais
	if(ptr.Ponto1.x == ptr.Ponto2.x)
	{
		if(ptr.Ponto1.y > ptr.Ponto2.y)
		{
			for(i=ptr.Ponto2.y;i<=ptr.Ponto1.y;i++)
				pPonto = IncluiCalda(pPonto,ptr.Ponto1.x,i,psimbolo);
		}
		else
		{
			for(i=ptr.Ponto1.y; i<=ptr.Ponto2.y;i++)
				pPonto = IncluiCalda(pPonto, ptr.Ponto1.x, i , psimbolo);
		}
	}
	else if(ptr.Ponto1.y == ptr.Ponto2.y)
	{
		if(ptr.Ponto1.x > ptr.Ponto2.x)
		{
			for(i=ptr.Ponto2.x;i<=ptr.Ponto1.x;i++)
				pPonto = IncluiCalda(pPonto,i,ptr.Ponto1.y,psimbolo);
		}
		else
		{
			for(i=ptr.Ponto1.x;i<=ptr.Ponto2.x;i++)
				pPonto = IncluiCalda(pPonto,i,ptr.Ponto1.y,psimbolo);
		}
	}
	
	// Casos de Linhas em Geral
	if((ptr.Ponto1.x != ptr.Ponto2.x)&&(ptr.Ponto1.y != ptr.Ponto2.y))
	{
		// Calculo da Reta
		sX = ptr.Ponto1.x + ptr.Ponto2.x;
		sX2 = (ptr.Ponto1.x*ptr.Ponto1.x) + (ptr.Ponto2.x*ptr.Ponto2.x);
		sY = ptr.Ponto1.y + ptr.Ponto2.y;
		sXY = (ptr.Ponto1.x*ptr.Ponto1.y) + (ptr.Ponto2.x*ptr.Ponto2.y);
		a = ((sX2*sY) - (sX*sXY))/((2*sX2) - (sX*sX));
		b = ((2*sXY) - (sX*sY))/((2*sX2) - (sX*sX));
	
		// Calculo de ajuste de float para inteiro e criação da Lista
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
		
		if (ptr.Ponto1.x > ptr.Ponto2.x)
		{
			maxX = ptr.Ponto1.x;
			minX = ptr.Ponto2.x;
		}
		else
		{
			maxX = ptr.Ponto2.x;
			minX = ptr.Ponto1.x;
		}
		for(y=minY;y<=maxY;y++)
		{
			tX = (y - a)/b;
			for(t=0;t<=40;t++)
			{
				if(t==tX)
					break;
				if(t>tX)
				{
					if(tX-(t-1) > t-tX)
					{
						tX=t;
						break;
					}
					else if(tX-(t-1) < t-tX)
					{
						tX=t-1;
						break;
					}
					else if(tX-(t-1) == t-tX)
					{
						tX=t-1;
						mTermo++;
						break;
					}
				}
			}
			x = int(tX);
			if(mTermo==1)
			{
				pPonto = IncluiCalda(pPonto,x,y,psimbolo);
				x++;
				pPonto = IncluiCalda(pPonto,x,y,psimbolo);
				mTermo = 0;
			}
			else
				pPonto = IncluiCalda(pPonto,x,y,psimbolo);
		}
		
		for(x=minX;x<=maxX;x++)
		{
			tY = a+(b*x);
			for(t=0;t<=40;t++)
			{
				if(t==tY)
					break;
				if(t>tY)
				{
					if(tY-(t-1) > t-tY)
					{
						tY=t;
						break;
					}
					else if(tY-(t-1) < t-tY)
					{
						tY=t-1;
						break;
					}
					else if(tY-(t-1) == t-tY)
					{
						tY=t-1;
						mTermo++;
						break;
					}
				}
			}
		y = int(tY);
			if(mTermo==1)
			{
				pPonto = IncluiCalda(pPonto,x,y,psimbolo);
				y++;
				pPonto = IncluiCalda(pPonto,x,y,psimbolo);
				mTermo = 0;
			}
			else
				pPonto = IncluiCalda(pPonto,x,y,psimbolo);
		}
	}
	return pPonto;	
}

// Função para Atualizar o Grid
void AtualizaGrafico(char grid[41][41], struct TVPontos &ppontos, struct TVLinhas &plinhas, struct TVTriangulos &ptriangs, struct TVRetangulos &prets)
{
	// Variaveis Locais
	int k=0, i=0, j=0;
	TPonto *Aux;

	// Gerando o Grid Cru
	for(j=1; j<41; j++) // Cadeia de Linhas
	{
		for(i=1; i<41; i++) // Cadeia de Colunas
			grid[i][j] = '.';
	}
	
	// Replicando dados em Coordenadas
	
	// Hierarquia 04: Retangulos
	if(prets.Qtde!=0)
	{
		for(k=0; k<prets.Qtde; k++)
		{
			Aux = prets.Elementos[k].Linha1.Ponto1.Prox;
			while(Aux!=NULL)
			{
				grid[Aux->x][Aux->y] = Aux->simb;
				Aux = Aux->Prox;
			}
		}
	}		

	// Hierarquia 03: Triangulos
	if(ptriangs.Qtde!=0)
	{
		for(k=0; k<ptriangs.Qtde; k++)
		{
			Aux = ptriangs.Elementos[k].Linha1.Ponto1.Prox;
			while(Aux!=NULL)
			{
				grid[Aux->x][Aux->y] = Aux->simb;
				Aux = Aux->Prox;
			}
		}
	}	
	
	// Hierarquia 02: Linhas
	if(plinhas.Qtde!=0)
	{
		for(k=0; k<plinhas.Qtde; k++)
		{
			Aux = plinhas.Elementos[k].Ponto1.Prox;
			while(Aux != NULL)
			{
				grid[Aux->x][Aux->y] = Aux->simb;
				Aux = Aux->Prox;
			}
		}
	}

	// Hierarquia 01: Pontos
	if(ppontos.Qtde!=0)
	{
		for(k=0; k<ppontos.Qtde; k++)
			grid[ppontos.Elementos[k].x][ppontos.Elementos[k].y] = ppontos.Elementos[k].simb;
	}
	
	// Imprimindo o Grid Atualizado
	for(j=0; j<41; j++) // Cadeia de Linhas
	{
		for(i=0; i<42; i++) // Cadeia de Colunas
		{
			// Imprindo as Coordenadas
			// Colunas
			if(j==0)
			{
				if (i==0)
					printf("   ");
				else if((i>0)&&(i<10))
					printf("0%d ", i);
				else if ((i>9)&&(i<41))
					printf("%d ", i);
				else if(i==41)
					printf("\n\n");
			}
			// Linhas
			if(i==0)
			{
				if((j>0)&&(j<10))
					printf("0%d ", j);
				else if ((j>9)&&(j<41))
					printf("%d ", j);
			}
			if((i>0)&&(j>0))
			{
				if(i==41) // Caso para pular linha
					printf("\n\n");
				else
				{
				printf(" %c ", grid[i][j]); // Impressão da coordenada
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

// Função para adicionar a Linha no Conjunto de Linhas
void PlotaLinha(struct TVLinhas &linhas, struct TLinha &ptr, char psimbolo)
{
	TPonto *pPonto;
	pPonto = (TPonto *) malloc(sizeof(TPonto));
	pPonto = &ptr.Ponto1;
	pPonto = GeraLinha(pPonto,ptr,psimbolo);
	system("PAUSE");
	linhas.Elementos[linhas.Qtde].Ponto1.x = pPonto->x;
	linhas.Elementos[linhas.Qtde].Ponto1.y = pPonto->y;
	linhas.Elementos[linhas.Qtde].Ponto2.x = ptr.Ponto2.x;
	linhas.Elementos[linhas.Qtde].Ponto2.y = ptr.Ponto2.y;	
	linhas.Elementos[linhas.Qtde].Ponto1.Prox = pPonto->Prox;
	linhas.Elementos[linhas.Qtde].Ponto1.simb = psimbolo;
	linhas.Elementos[linhas.Qtde].Ponto2.simb = psimbolo;
	linhas.Qtde++;
}

// Função para adicionar o Triangulo no Conjunto de Triangulos
void PlotaTriangulo(struct TVTriangulos &triangulos, struct TTriangulo &ptr, char psimbolo)
{
	TPonto *pPonto;
	pPonto = (TPonto *) malloc(sizeof(TPonto));
	pPonto = &ptr.Linha1.Ponto1;
 	
	if(ptr.neg_alt==0)
	{
		if(ptr.neg_larg==0)
		{
			ptr.Linha1.Ponto2.x = ptr.Linha1.Ponto1.x - ptr.larg;
			ptr.Linha1.Ponto2.y = ptr.Linha1.Ponto1.y;
			ptr.Linha2.Ponto1.x = ptr.Linha1.Ponto1.x;
			ptr.Linha2.Ponto1.y = ptr.Linha1.Ponto1.y;
			ptr.Linha2.Ponto2.x = ptr.Linha1.Ponto1.x;
			ptr.Linha2.Ponto2.y = ptr.Linha1.Ponto1.y - ptr.alt;
			ptr.Linha3.Ponto1.x = ptr.Linha2.Ponto2.x;
			ptr.Linha3.Ponto1.y = ptr.Linha2.Ponto2.y;
			ptr.Linha3.Ponto2.x = ptr.Linha1.Ponto2.x;
			ptr.Linha3.Ponto2.y = ptr.Linha1.Ponto2.y;
		}
		else
		{
			ptr.Linha1.Ponto2.x = ptr.Linha1.Ponto1.x + ptr.larg;
			ptr.Linha1.Ponto2.y = ptr.Linha1.Ponto1.y;
			ptr.Linha2.Ponto1.x = ptr.Linha1.Ponto1.x;
			ptr.Linha2.Ponto1.y = ptr.Linha1.Ponto1.y;
			ptr.Linha2.Ponto2.x = ptr.Linha1.Ponto1.x;
			ptr.Linha2.Ponto2.y = ptr.Linha1.Ponto1.y - ptr.alt;
			ptr.Linha3.Ponto1.x = ptr.Linha2.Ponto2.x;
			ptr.Linha3.Ponto1.y = ptr.Linha2.Ponto2.y;
			ptr.Linha3.Ponto2.x = ptr.Linha1.Ponto2.x;
			ptr.Linha3.Ponto2.y = ptr.Linha1.Ponto2.y;		
		}
	}
	else
	{
		if(ptr.neg_larg==0)
		{
			ptr.Linha1.Ponto2.x = ptr.Linha1.Ponto1.x - ptr.larg;
			ptr.Linha1.Ponto2.y = ptr.Linha1.Ponto1.y;
			ptr.Linha2.Ponto1.x = ptr.Linha1.Ponto1.x;
			ptr.Linha2.Ponto1.y = ptr.Linha1.Ponto1.y;
			ptr.Linha2.Ponto2.x = ptr.Linha1.Ponto1.x;
			ptr.Linha2.Ponto2.y = ptr.Linha1.Ponto1.y + ptr.alt;
			ptr.Linha3.Ponto1.x = ptr.Linha2.Ponto2.x;
			ptr.Linha3.Ponto1.y = ptr.Linha2.Ponto2.y;
			ptr.Linha3.Ponto2.x = ptr.Linha1.Ponto2.x;
			ptr.Linha3.Ponto2.y = ptr.Linha1.Ponto2.y;			
		}
		else
		{
			ptr.Linha1.Ponto2.x = ptr.Linha1.Ponto1.x + ptr.larg;
			ptr.Linha1.Ponto2.y = ptr.Linha1.Ponto1.y;
			ptr.Linha2.Ponto1.x = ptr.Linha1.Ponto1.x;
			ptr.Linha2.Ponto1.y = ptr.Linha1.Ponto1.y;
			ptr.Linha2.Ponto2.x = ptr.Linha1.Ponto1.x;
			ptr.Linha2.Ponto2.y = ptr.Linha1.Ponto1.y + ptr.alt;
			ptr.Linha3.Ponto1.x = ptr.Linha2.Ponto2.x;
			ptr.Linha3.Ponto1.y = ptr.Linha2.Ponto2.y;
			ptr.Linha3.Ponto2.x = ptr.Linha1.Ponto2.x;
			ptr.Linha3.Ponto2.y = ptr.Linha1.Ponto2.y;			
		}
	}
	pPonto = GeraLinha(pPonto,ptr.Linha1,psimbolo);
	pPonto = GeraLinha(pPonto,ptr.Linha2,psimbolo);
	pPonto = GeraLinha(pPonto,ptr.Linha3,psimbolo);
	triangulos.Elementos[triangulos.Qtde].Linha1.Ponto1.x = pPonto->x;
	triangulos.Elementos[triangulos.Qtde].Linha1.Ponto1.y = pPonto->y;
	triangulos.Elementos[triangulos.Qtde].Linha1.Ponto1.Prox = pPonto->Prox;
	triangulos.Elementos[triangulos.Qtde].Linha1.Ponto1.simb = psimbolo;
	triangulos.Qtde++;	
}

// Função para adicionar o Retangulo no Conjunto de Retangulos
void PlotaRetangulo(struct TVRetangulos &retangulos, struct TRetangulo &ptr, char psimbolo)
{
	TPonto *pPonto;
	pPonto = (TPonto *) malloc(sizeof(TPonto));
	pPonto = &ptr.Linha1.Ponto1;
	
	ptr.Linha1.Ponto2.x = ptr.Linha2.Ponto1.x;
	ptr.Linha1.Ponto2.y = ptr.Linha1.Ponto1.y;
	ptr.Linha2.Ponto2.x = ptr.Linha1.Ponto1.x;
	ptr.Linha2.Ponto2.y = ptr.Linha2.Ponto1.y;
	ptr.Linha3.Ponto1.x = ptr.Linha2.Ponto1.x;
	ptr.Linha3.Ponto1.y = ptr.Linha2.Ponto1.y;
	ptr.Linha3.Ponto2.x = ptr.Linha1.Ponto2.x;
	ptr.Linha3.Ponto2.y = ptr.Linha1.Ponto2.y;
	ptr.Linha4.Ponto1.x = ptr.Linha1.Ponto1.x;
	ptr.Linha4.Ponto1.y = ptr.Linha1.Ponto1.y;
	ptr.Linha4.Ponto2.x = ptr.Linha2.Ponto2.x;
	ptr.Linha4.Ponto2.y = ptr.Linha2.Ponto2.y;
	pPonto = GeraLinha(pPonto,ptr.Linha1,psimbolo);
	pPonto = GeraLinha(pPonto,ptr.Linha2,psimbolo);
	pPonto = GeraLinha(pPonto,ptr.Linha3,psimbolo);
	pPonto = GeraLinha(pPonto,ptr.Linha4,psimbolo);
	retangulos.Elementos[retangulos.Qtde].Linha1.Ponto1.x = pPonto->x;
	retangulos.Elementos[retangulos.Qtde].Linha1.Ponto1.y = pPonto->y;
	retangulos.Elementos[retangulos.Qtde].Linha2.Ponto1.x = ptr.Linha2.Ponto1.x;
	retangulos.Elementos[retangulos.Qtde].Linha2.Ponto1.y = ptr.Linha2.Ponto1.y;	
	retangulos.Elementos[retangulos.Qtde].Linha1.Ponto1.Prox = pPonto->Prox;
	retangulos.Elementos[retangulos.Qtde].Linha1.Ponto1.simb = psimbolo;
	retangulos.Elementos[retangulos.Qtde].Linha2.Ponto1.simb = psimbolo;
	retangulos.Qtde++;
}