#include "GeoLib.h"
/* Console.h é uma biblioteca que compõe todas as funções e procedimentos para a execução de tarefas
 * não triviais que não fazem parte da GeoLib.h, desenvolvido para a o Trabalho 01 de EDA 2/2013.
 */

// Sumário
/* int Menu()
 * void *ExcluiCalda(*TPonto)
 * void iPonto(TVPontos)
 * void ePonto(TVPontos)
 * void iLinha(TVLinhas)
 * void eLinha(TVLinhas)
 * void SetWindow(int,int)
 */
 
// Função que define a opção escolhida no menu
int Menu()
{
    
	int op;  // Variavel da opção
	
	do{
	    printf("\nMenu de Op%coes\n\n", 135);
		printf("\n1 - Incluir Ponto\n");
		printf("\n2 - Excluir Ponto\n");
		printf("\n3 - Incluir Linha\n");
		printf("\n4 - Excluir Linha\n");
		printf("\n5 - Incluir Triangulo\n");
		printf("\n6 - Excluir Triangulo\n");
		printf("\n7 - Incluir Retangulo\n");
		printf("\n8 - Excluir Retangulo\n");
		printf("\n9 - Sair\n\n");
		printf("\nDigite a sua escolha: ");
		scanf("%d",&op);
		if((op<1)||(op>9))
			printf("\n\nOp%cao nao existente!\n\n", 135);
	}while((op<1)||(op>9));
	
    return (op); // Retorna a opção
}


// Funções de Tratamento de Listas
TPonto *ExcluiCalda(TPonto *pLista)
{
	TPonto *pAux;
	pAux = pLista;
	while(pAux->Prox->Prox!=NULL)
		pAux = pAux->Prox;
	free(pAux->Prox);
	pAux->Prox = NULL;
	return pLista;
}

// Cadeias de Funções e Procedimentos que tem por objetivo a Inclusão de Figuras

// Inserindo um Ponto
void iPonto(struct TVPontos &pontos)
{
	if(pontos.Qtde == 5 )
	{
		printf("Nao %c possivel inserir mais pontos!\n", 130);
		printf("A quantidade m%cxima de 5 pontos foi atingida!\n", 160);
		system("pause");
	}
	else
	{
		struct TPonto ponto;
		char simbolo;
		printf("Digite a coordenada do ponto em par ordenado (separados por um espa%co):\n", 135);
		printf("Exemplo: 30 14\n");
		scanf("%d %d", &ponto.x, &ponto.y);
		fflush(stdin);
		printf("Digite o s%cmbolo do ponto:\n", 161);
		scanf("%c",&simbolo);
		fflush(stdin);
		PlotaPonto(pontos,ponto,simbolo);
	}
}

// Excluindo um Ponto
void ePonto(struct TVPontos &pontos)
{
	if(pontos.Qtde == 0)
	{
		printf("Nao h%c pontos para ser excluido!\n", 160);
		system("pause");		
	}
	else
	{
		int codigo=0, i = 0;
		system("cls");
		printf("[C%cdigo do Ponto]:(Coordenada X, Coordenada Y) = S%cmbolo do ponto\n", 162, 161);
		for (i = 0; i < pontos.Qtde; i++)
			printf("[%d]:(%d, %d) = %c \n", i+1, pontos.Elementos[i].x, pontos.Elementos[i].y, pontos.Elementos[i].simb);
		printf("Insira o c%cdigo do ponto que deseja excluir:\n", 162);
		printf("Exemplo: 2\n");
		scanf("%d", &codigo);
		if((codigo>0)&&(codigo<=pontos.Qtde))
		{
			pontos.Elementos[codigo-1].x = 40;
			pontos.Elementos[codigo-1].y = 40;
			pontos.Elementos[codigo-1].simb = ',';
			for(i = codigo-1; i < pontos.Qtde; i++)
				pontos.Elementos[i] = pontos.Elementos[i+1];
			pontos.Qtde--;
			printf("Ponto [%d] excluido com sucesso!\n", codigo);
		}
		else
		{
			printf("C%cdigo incorreto!\n", 162);
			system("pause");
		}
	}
}

// Inserindo uma Linha
void iLinha(struct TVLinhas &linhas)
{
	if(linhas.Qtde == 5 )
	{
		printf("Nao %c possivel inserir mais linhas!\n", 130);
		printf("A quantidade m%cxima de 5 linhas foi atingida!\n", 160);
		system("pause");
	}
	else
	{
		struct TLinha linha;
		char simbolo;
		printf("Digite a coordenada do primeiro ponto em par ordenado (separados por um espa%co):\n", 135);
		printf("Exemplo: 30 14\n");
		scanf("%d %d", &linha.Ponto1.x, &linha.Ponto1.y);
		fflush(stdin);
		printf("Digite a coordenada do segundo ponto em par ordenado (separados por um espa%co):\n", 135);
		printf("Exemplo: 6 12\n");
		scanf("%d %d", &linha.Ponto2.x, &linha.Ponto2.y);
		fflush(stdin);
		printf("Digite o s%cmbolo da linha:\n", 161);
		scanf("%c",&simbolo);
		fflush(stdin);
		PlotaLinha(linhas,linha,simbolo); // GeoLib.h
	}
}

// Excluindo uma Linha
void eLinha(struct TVLinhas &linhas)
{
	if(linhas.Qtde == 0)
	{
		printf("Nao h%c linhas para ser excluido!\n", 160);
		system("pause");		
	}
	else
	{
		int codigo=0, i = 0;
		system("cls");
		printf("[C%cdigo da Linha]:(Coordenada Ponto 1 X, Coordenada Ponto Y)(Coordenada Ponto 2 X, Coordenada Ponto 2 Y) = S%cmbolo do linha\n", 162, 161);
		for (i = 0; i < linhas.Qtde; i++)
			printf("[%d]:(%d, %d)(%d, %d) = %c \n", i+1, linhas.Elementos[i].Ponto1.x, linhas.Elementos[i].Ponto1.y, linhas.Elementos[i].Ponto2.x, linhas.Elementos[i].Ponto2.y, linhas.Elementos[i].Ponto1.simb);
		printf("Insira o c%cdigo do ponto que deseja excluir:\n", 162);
		printf("Exemplo: 2\n");
		scanf("%d", &codigo);
		fflush(stdin);
		if((codigo>0)&&(codigo<=linhas.Qtde))
		{
			TPonto *Aux;
			Aux = linhas.Elementos[codigo-1].Ponto1.Prox;
			while(Aux->Prox->Prox!=NULL)
				Aux = ExcluiCalda(Aux);
			if(Aux->Prox->Prox==NULL)
			{
				free(Aux->Prox);
				free(Aux);
				linhas.Elementos[codigo-1].Ponto1.Prox = NULL;
			}
			linhas.Elementos[codigo-1].Ponto1.x = 40;
			linhas.Elementos[codigo-1].Ponto1.y = 40;
			linhas.Elementos[codigo-1].Ponto1.simb = ',';
			linhas.Elementos[codigo-1].Ponto2.x = 40;
			linhas.Elementos[codigo-1].Ponto2.y = 40;
			linhas.Elementos[codigo-1].Ponto2.simb = ',';
			for(i = codigo-1; i < linhas.Qtde; i++)
				linhas.Elementos[i] = linhas.Elementos[i+1];
			linhas.Qtde--;
			printf("Linha [%d] excluida com sucesso!\n", codigo);
		}
		else
		{
			printf("C%cdigo incorreto!\n", 162);
			system("pause");
		}
	}
}

// Incluindo Triangulo
// Excluindo Triangulo

// Inserindo um Retangulo
void iRetangulo(struct TVRetangulos &retangulos)
{
	if(retangulos.Qtde == 5 )
	{
		printf("Nao %c possivel inserir mais retangulos!\n", 130);
		printf("A quantidade m%cxima de 5 retangulos foi atingida!\n", 160);
		system("pause");
	}
	else
	{
		struct TRetangulo retangulo;
		char simbolo;
		printf("Digite a coordenada do primeiro ponto em par ordenado (separados por um espa%co):\n", 135);
		printf("Exemplo: 30 14\n");
		scanf("%d %d", &retangulo.Ponto1.x, &retangulo.Ponto1.y);
		fflush(stdin);
		printf("Digite a coordenada do segundo ponto em par ordenado (separados por um espa%co):\n", 135);
		printf("Exemplo: 6 12\n");
		scanf("%d %d", &retangulo.Ponto2.x, &retangulo.Ponto2.y);
		fflush(stdin);
		if((retangulo.Ponto1.x == retangulo.Ponto2.x)or(retangulo.Ponto1.y == retangulo.Ponto2.y))
		{
			printf("\nNao %c possivel gerar retangulos com pontos na mesma linha/coluna!\n", 130);
			system("PAUSE");
		}
		else
		{
			printf("Digite o s%cmbolo do retangulo:\n", 161);
			scanf("%c",&simbolo);
			fflush(stdin);
			PlotaRetangulo(retangulos,retangulo,simbolo); // GeoLib.h
		}
	}
}

// Procedimento de Redimensionamento de Janela
void SetWindow(int Width, int Height) 
{
    _COORD coord; 
    coord.X = Width; 
    coord.Y = Height; 

    _SMALL_RECT Rect; 
    Rect.Top = 0; 
    Rect.Left = 0; 
    Rect.Bottom = Height - 1; 
    Rect.Right = Width - 1; 

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle 
    SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size 
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size 
} 