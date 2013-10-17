/* Console.h é uma biblioteca que compõe todas as funções e procedimentos para a execução de tarefas
 * não triviais que não fazem parte da GeoLib.h, desenvolvido para a o Trabalho 01 de EDA 2/2013.
 */

// Sumário
/* int Menu()
 * void *ExcluiCalda(*TPonto)
 * void validaPonto(int,int)
 * void validaAltLarg(int,int,bool,bool)
 * void iPonto(TVPontos)
 * void ePonto(TVPontos)
 * void iLinha(TVLinhas)
 * void eLinha(TVLinhas)
 * void iTriangulo(TVTriangulos)
 * void eTriangulos(TVTriangulos)
 * void iRetangulo(TVRetangulos)
 * void eRetangulo(TVRetangulos)
 * void SetWindow(int,int)
 */
 
// Bibliotecas
#include "GeoLib.h" 

// Função que define a opção escolhida no menu
int Menu()
{
    
	int op;
	
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
	
    return (op); // Retorna a Opção
}

// Função de Tratamento de Listas -> Exclusão
TPonto *ExcluiCalda(TPonto *pLista)
{
	TPonto *pAux;
	pAux = pLista;
	while(pAux->Prox->Prox!=NULL) // Enquanto pAux->Prox não apontar para a Calda
		pAux = pAux->Prox;
	free(pAux->Prox);
	pAux->Prox = NULL;
	return pLista;
}

// Validações
void validaPonto(int &x, int &y)
{
	while((x<=0)or(y<=0)or(x>40)or(y>40)) // Alcance do Grid
	{
		printf("As coordenadas podem ter valor minimo de 1 at%c um m%cximo de 40\n", 130, 160);
		printf("Por favor, insira novamente a coordenada:\n");
		scanf("%d %d", &x, &y);
		fflush(stdin);
	}	
}

void validaAltLarg(int coord, int &plus, bool neg, bool tipo)
{
	int alcance=0, valida=0;
	while(valida==0)
	{
		if(tipo==0) // Altura
		{
			if(neg==0) // Negativa
			{
				alcance = coord-1; // Ex: y = 5, alcance = 4
				if(plus>alcance) // Caso Altura seja maior que o Alcance
				{
				printf("O alcance m%cximo da Altura %c de: %d\n", 160, 130, alcance);
				printf("Digite novamente a altura:\n");
				scanf("%d", &plus);
				fflush(stdin);
				}
				else // Caso Altura seja menor ou igual ao Alcance
					valida++; // Sai da Repetição
			}
			else if(neg==1) // Positiva
			{
				alcance = 40-coord; // Ex: y = 5, alcance = 35
				if(plus>alcance) // Caso Altura seja maior que o Alcance
				{
				printf("O alcance m%cximo da Altura %c de: %d\n", 160, 130, alcance);
				printf("Digite novamente a altura:\n");
				scanf("%d", &plus);
				fflush(stdin);
				}
				else // Caso Altura seja menor ou igual ao Alcance
					valida++; // Sai da Repetição
			}	
		}
		else if(tipo==1) // Largura
		{
			if(neg==0) // Negativa
			{
				alcance = coord-1; // Ex: x = 5, alcance = 4
				if(plus>alcance) // Caso Largura seja maior que o Alcance
				{
				printf("O alcance m%cximo da Largura %c de: %d\n", 160, 130, alcance);
				printf("Digite novamente a largura:\n");
				scanf("%d", &plus);
				fflush(stdin);
				}
				else // Caso Largura seja menor ou igual ao Alcance
					valida++; // Sai da Repetição
			}
			else if(neg==1) // Positiva
			{
				alcance = 40-coord; // Ex: x = 5, alcance = 35
				if(plus>alcance) // Caso Largura seja maior que o Alcance
				{
				printf("O alcance m%cximo da Largura %c de: %d\n", 160, 130, alcance);
				printf("Digite novamente a largura:\n");
				scanf("%d", &plus);
				fflush(stdin);
				}
				else // Caso Largura seja menor ou igual ao Alcance
					valida++; // Sai da Repetição
			}	
		}
	}
}

// Cadeias de Funções e Procedimentos que tem por objetivo a Inclusão/Exclusão de Figuras

// Inserindo um Ponto
void iPonto(struct TVPontos &pontos)
{
	if(pontos.Qtde == 5 ) // Caso tenha 5 pontos, proibe inserir um novo
	{
		printf("Nao %c possivel inserir mais pontos!\n", 130);
		printf("A quantidade m%cxima de 5 pontos foi atingida!\n", 160);
		system("pause");
	}
	else // Caso não tenha 5 pontos, permite inserir um novo
	{
		struct TPonto ponto;
		char simbolo;
		printf("Digite a coordenada do ponto em par ordenado (separados por um espa%co):\n", 135);
		printf("Exemplo: 30 14\n");
		scanf("%d %d", &ponto.x, &ponto.y);
		fflush(stdin);
		validaPonto(ponto.x,ponto.y);
		printf("Digite o s%cmbolo do ponto:\n", 161);
		scanf("%c",&simbolo);
		fflush(stdin);
		PlotaPonto(pontos,ponto,simbolo); // GeoLib.h
	}
}

// Excluindo um Ponto
void ePonto(struct TVPontos &pontos)
{
	if(pontos.Qtde == 0) // Caso não tenha pontos, não considera a exclusão
	{
		printf("Nao h%c pontos para ser excluido!\n", 160);
		system("pause");		
	}
	else // Caso tenha algum ponto, considera a exclusão
	{
		int codigo=0, i = 0;
		system("cls");
		printf("[C%cdigo do Ponto]:(Coordenada X, Coordenada Y) = S%cmbolo do ponto\n", 162, 161);
		for (i = 0; i < pontos.Qtde; i++) // Listando os Pontos
			printf("[%d]:(%d, %d) = %c \n", i+1, pontos.Elementos[i].x, pontos.Elementos[i].y, pontos.Elementos[i].simb);
		printf("Insira o c%cdigo do ponto que deseja excluir:\n", 162);
		printf("Exemplo: 2\n");
		scanf("%d", &codigo);
		fflush(stdin);
		if((codigo>0)&&(codigo<=pontos.Qtde)) // Caso o codigo exista
		{
			// Retorna aos valores de origem
			pontos.Elementos[codigo-1].x = 0;
			pontos.Elementos[codigo-1].y = 0;
			pontos.Elementos[codigo-1].simb = ',';
			for(i = codigo-1; i < pontos.Qtde; i++) // Reordena o Vetor
				pontos.Elementos[i] = pontos.Elementos[i+1];
			pontos.Qtde--;
			printf("Ponto [%d] excluido com sucesso!\n", codigo);
			system("pause");
		}
		else // Caso o codigo nao exista
		{
			printf("C%cdigo incorreto!\n", 162);
			system("pause");
		}
	}
}

// Inserindo uma Linha
void iLinha(struct TVLinhas &linhas)
{
	if(linhas.Qtde == 5 ) // Caso tenha 5 linhas, proibe inserir um novo
	{
		printf("Nao %c possivel inserir mais linhas!\n", 130);
		printf("A quantidade m%cxima de 5 linhas foi atingida!\n", 160);
		system("pause");
	}
	else // Caso não tenha 5 linhas, permite inserir um novo
	{
		struct TLinha linha;
		char simbolo;
		printf("Digite a coordenada do primeiro ponto em par ordenado (separados por um espa%co):\n", 135);
		printf("Exemplo: 30 14\n");
		scanf("%d %d", &linha.Ponto1.x, &linha.Ponto1.y);
		fflush(stdin);
		validaPonto(linha.Ponto1.x,linha.Ponto1.y);
		printf("Digite a coordenada do segundo ponto em par ordenado (separados por um espa%co):\n", 135);
		printf("Exemplo: 6 12\n");
		scanf("%d %d", &linha.Ponto2.x, &linha.Ponto2.y);
		fflush(stdin);
		validaPonto(linha.Ponto2.x,linha.Ponto2.y);
		printf("Digite o s%cmbolo da linha:\n", 161);
		scanf("%c",&simbolo);
		fflush(stdin);
		PlotaLinha(linhas,linha,simbolo); // GeoLib.h
	}
}

// Excluindo uma Linha
void eLinha(struct TVLinhas &linhas)
{
	if(linhas.Qtde == 0) // Caso não tenha linhas, não considera a exclusão
	{
		printf("Nao h%c linhas para ser excluido!\n", 160);
		system("pause");		
	}
	else // Caso tenha alguma linha, considera a exclusão
	{
		int codigo=0, i = 0;
		system("cls");
		printf("[C%cdigo da Linha]:(Coordenada Ponto 1 X, Coordenada Ponto Y)(Coordenada Ponto 2 X, Coordenada Ponto 2 Y) = S%cmbolo da linha\n", 162, 161);
		for (i = 0; i < linhas.Qtde; i++) // Lista as Linhas
			printf("[%d]:(%d, %d)(%d, %d) = %c \n", i+1, linhas.Elementos[i].Ponto1.x, linhas.Elementos[i].Ponto1.y, linhas.Elementos[i].Ponto2.x, linhas.Elementos[i].Ponto2.y, linhas.Elementos[i].Ponto1.simb);
		printf("Insira o c%cdigo da Linha que deseja excluir:\n", 162);
		printf("Exemplo: 2\n");
		scanf("%d", &codigo);
		fflush(stdin);
		if((codigo>0)&&(codigo<=linhas.Qtde)) // Caso o codigo exista
		{
			TPonto *Aux;
			Aux = linhas.Elementos[codigo-1].Ponto1.Prox;
			while(Aux->Prox->Prox!=NULL) // Limpa a Lista, restando apenas 3 pontos
				Aux = ExcluiCalda(Aux);
			if(Aux->Prox->Prox==NULL) // Confirma se a limpeza acima saiu conforme esperado
			{
				free(Aux->Prox); // Limpa a calda restante
				free(Aux); // Limpa o Nó restante
				linhas.Elementos[codigo-1].Ponto1.Prox = NULL;
			}
			// Retorna aos valores de origem
			linhas.Elementos[codigo-1].Ponto1.x = 0;
			linhas.Elementos[codigo-1].Ponto1.y = 0;
			linhas.Elementos[codigo-1].Ponto1.simb = ',';
			linhas.Elementos[codigo-1].Ponto2.x = 0;
			linhas.Elementos[codigo-1].Ponto2.y = 0;
			linhas.Elementos[codigo-1].Ponto2.simb = ',';
			for(i = codigo-1; i < linhas.Qtde; i++) // Reordena o Vetor
				linhas.Elementos[i] = linhas.Elementos[i+1];
			linhas.Qtde--;
			printf("Linha [%d] excluida com sucesso!\n", codigo);
			system("pause");
		}
		else // Caso o codigo nao exista
		{
			printf("C%cdigo incorreto!\n", 162);
			system("pause");
		}
	}
}

// Inserindo um Triangulo
void iTriangulo(struct TVTriangulos &triangulos)
{	
	if(triangulos.Qtde == 5 ) // Caso tenha 5 triangulos, proibe inserir um novo
	{
		printf("Nao %c possivel inserir mais triangulos!\n", 130);
		printf("A quantidade m%cxima de 5 triangulos foi atingida!\n", 160);
		system("pause");
	}
	else // Caso não tenha 5 triangulos, permite inserir um novo
	{
		struct TTriangulo triangulo;
		char simbolo;
		int neg_alt=0, neg_larg=0;
		bool tipo=2;
		printf("Digite a coordenada da base do Triangulo em par ordenado (separados por um espa%co):\n", 135);
		printf("Exemplo: 30 14\n");
		scanf("%d %d", &triangulo.Linha1.Ponto1.x, &triangulo.Linha1.Ponto1.y);
		fflush(stdin);
		validaPonto(triangulo.Linha1.Ponto1.x,triangulo.Linha1.Ponto1.y);
		printf("Digite a altura do Triangulo:\n");
		printf("Exemplo: 17\n");
		scanf("%d", &triangulo.alt);
		fflush(stdin);
		printf("A altura %c positiva ou negativa?\n", 130);
		printf("(1) - Positiva, (0) - Negativa\n");
		scanf("%d", &neg_alt);
		triangulo.neg_alt = neg_alt;
		tipo=0;
		fflush(stdin);
		validaAltLarg(triangulo.Linha1.Ponto1.y, triangulo.alt, triangulo.neg_alt, tipo);
		printf("Digite a largura do Triangulo:\n");
		printf("Exemplo: 5\n");
		scanf("%d", &triangulo.larg);
		fflush(stdin);
		printf("A largura %c positiva ou negativa?\n", 130);
		printf("(1) - Positiva, (0) - Negativa\n");
		scanf("%d", &neg_larg);
		triangulo.neg_larg = neg_larg;
		tipo=1;
		fflush(stdin);
		validaAltLarg(triangulo.Linha1.Ponto1.x, triangulo.larg, triangulo.neg_larg, 1);
		tipo=2;
		printf("Digite o s%cmbolo do triangulo:\n", 161);
		scanf("%c",&simbolo);
		fflush(stdin);
		PlotaTriangulo(triangulos,triangulo,simbolo); // GeoLib.h
	}
}

// Excluindo Triangulo
void eTriangulo(struct TVTriangulos &triangulos)
{
	if(triangulos.Qtde == 0) // Caso não tenha triangulos, não considera a exclusão
	{
		printf("Nao h%c triangulos para ser excluido!\n", 160);
		system("pause");		
	}
	else // Caso tenha algum triangulo, considera a exclusão
	{
		int codigo=0, i = 0;
		system("cls");
		printf("[C%cdigo do Triangulo]:(Coordenada Base X, Coordenada Base Y)(Altura(Positivo ou Negativo))(Largura(Positivo ou Negativo)) = S%cmbolo do Triangulo\n", 162, 161);
		for (i = 0; i < triangulos.Qtde; i++) // Lista os Triangulos
			printf("[%d]:(%d, %d)(%d(%d))(%d(%d)) = %c \n", i+1, triangulos.Elementos[i].Linha1.Ponto1.x, triangulos.Elementos[i].Linha1.Ponto1.y, triangulos.Elementos[i].alt, triangulos.Elementos[i].neg_alt, triangulos.Elementos[i].larg, triangulos.Elementos[i].neg_larg, triangulos.Elementos[i].Linha1.Ponto1.simb);
		printf("Insira o c%cdigo do Triangulo que deseja excluir:\n", 162);
		printf("Exemplo: 2\n");
		scanf("%d", &codigo);
		fflush(stdin);
		if((codigo>0)&&(codigo<=triangulos.Qtde)) // Caso o codigo exista
		{
			TPonto *Aux;
			Aux = triangulos.Elementos[codigo-1].Linha1.Ponto1.Prox;
			while(Aux->Prox->Prox!=NULL)
				Aux = ExcluiCalda(Aux);
			if(Aux->Prox->Prox==NULL)
			{
				free(Aux->Prox);
				free(Aux);
				triangulos.Elementos[codigo-1].Linha1.Ponto1.Prox = NULL;
			}
			// Retorna aos valores de origem
			triangulos.Elementos[codigo-1].Linha1.Ponto1.x = 0;
			triangulos.Elementos[codigo-1].Linha1.Ponto1.y = 0;
			triangulos.Elementos[codigo-1].Linha1.Ponto1.simb = ',';
			triangulos.Elementos[codigo-1].Linha2.Ponto1.x = 0;
			triangulos.Elementos[codigo-1].Linha2.Ponto1.y = 0;
			triangulos.Elementos[codigo-1].Linha2.Ponto1.simb = ',';
			triangulos.Elementos[codigo-1].Linha3.Ponto1.x = 0;
			triangulos.Elementos[codigo-1].Linha3.Ponto1.y = 0;
			triangulos.Elementos[codigo-1].Linha3.Ponto1.simb = ',';
			triangulos.Elementos[codigo-1].Linha1.Ponto2.x = 0;
			triangulos.Elementos[codigo-1].Linha1.Ponto2.y = 0;
			triangulos.Elementos[codigo-1].Linha1.Ponto2.simb = ',';
			triangulos.Elementos[codigo-1].Linha2.Ponto2.x = 0;
			triangulos.Elementos[codigo-1].Linha2.Ponto2.y = 0;
			triangulos.Elementos[codigo-1].Linha2.Ponto2.simb = ',';
			triangulos.Elementos[codigo-1].Linha3.Ponto2.x = 0;
			triangulos.Elementos[codigo-1].Linha3.Ponto2.y = 0;
			triangulos.Elementos[codigo-1].Linha3.Ponto2.simb = ',';			
			triangulos.Elementos[codigo-1].alt = 0;
			triangulos.Elementos[codigo-1].neg_alt = 0;
			triangulos.Elementos[codigo-1].larg = 0;
			triangulos.Elementos[codigo-1].neg_larg = 0;
			for(i = codigo-1; i < triangulos.Qtde; i++) // Reordena o vetor
				triangulos.Elementos[i] = triangulos.Elementos[i+1];
			triangulos.Qtde--;
			printf("Triangulo [%d] excluido com sucesso!\n", codigo);
			system("pause");
		}
		else // Caso o codigo nao exista
		{
			printf("C%cdigo incorreto!\n", 162);
			system("pause");
		}
	}
}

// Inserindo um Retangulo
void iRetangulo(struct TVRetangulos &retangulos)
{
	if(retangulos.Qtde == 5 ) // Caso tenha 5 retangulos, proibe inserir um novo
	{
		printf("Nao %c possivel inserir mais retangulos!\n", 130);
		printf("A quantidade m%cxima de 5 retangulos foi atingida!\n", 160);
		system("pause");
	}
	else // Caso não tenha 5 retangulos, permite inserir um novo
	{
		struct TRetangulo retangulo;
		char simbolo;
		printf("Digite a coordenada do primeiro ponto em par ordenado (separados por um espa%co):\n", 135);
		printf("Exemplo: 30 14\n");
		scanf("%d %d", &retangulo.Linha1.Ponto1.x, &retangulo.Linha1.Ponto1.y);
		fflush(stdin);
		validaPonto(retangulo.Linha1.Ponto1.x,retangulo.Linha1.Ponto1.y);
		printf("Digite a coordenada do segundo ponto em par ordenado (separados por um espa%co):\n", 135);
		printf("Exemplo: 6 12\n");
		scanf("%d %d", &retangulo.Linha2.Ponto1.x, &retangulo.Linha2.Ponto1.y);
		fflush(stdin);
		validaPonto(retangulo.Linha2.Ponto1.x,retangulo.Linha2.Ponto1.y);
		if((retangulo.Linha1.Ponto1.x == retangulo.Linha2.Ponto1.x)||(retangulo.Linha1.Ponto1.y == retangulo.Linha2.Ponto1.y))
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

// Excluindo um Retangulo
void eRetangulo(struct TVRetangulos &retangulos)
{
	if(retangulos.Qtde == 0) // Caso não tenha retangulos, não considera a exclusão
	{
		printf("Nao h%c retangulos para ser excluido!\n", 160);
		system("pause");		
	}
	else // Caso tenha algum retangulo, considera a exclusão
	{
		int codigo=0, i = 0;
		system("cls");
		printf("[C%cdigo do Retangulo]:(Coordenada Ponto 1 X, Coordenada Ponto Y)(Coordenada Ponto 2 X, Coordenada Ponto 2 Y) = S%cmbolo do Retangulo\n", 162, 161);
		for (i = 0; i < retangulos.Qtde; i++) // Lista os Retangulos
			printf("[%d]:(%d, %d)(%d, %d) = %c \n", i+1, retangulos.Elementos[i].Linha1.Ponto1.x, retangulos.Elementos[i].Linha1.Ponto1.y, retangulos.Elementos[i].Linha2.Ponto1.x, retangulos.Elementos[i].Linha2.Ponto1.y, retangulos.Elementos[i].Linha1.Ponto1.simb);
		printf("Insira o c%cdigo do Retangulo que deseja excluir:\n", 162);
		printf("Exemplo: 2\n");
		scanf("%d", &codigo);
		fflush(stdin);
		if((codigo>0)&&(codigo<=retangulos.Qtde)) // Caso o codigo exista
		{
			TPonto *Aux;
			Aux = retangulos.Elementos[codigo-1].Linha1.Ponto1.Prox;
			while(Aux->Prox->Prox!=NULL)
				Aux = ExcluiCalda(Aux);
			if(Aux->Prox->Prox==NULL)
			{
				free(Aux->Prox);
				free(Aux);
				retangulos.Elementos[codigo-1].Linha1.Ponto1.Prox = NULL;
			}
			// Retorna aos valores de origem
			retangulos.Elementos[codigo-1].Linha1.Ponto1.x = 0;
			retangulos.Elementos[codigo-1].Linha1.Ponto1.y = 0;
			retangulos.Elementos[codigo-1].Linha1.Ponto1.simb = ',';
			retangulos.Elementos[codigo-1].Linha1.Ponto2.x = 0;
			retangulos.Elementos[codigo-1].Linha1.Ponto2.y = 0;
			retangulos.Elementos[codigo-1].Linha1.Ponto2.simb = ',';
			retangulos.Elementos[codigo-1].Linha2.Ponto1.x = 0;
			retangulos.Elementos[codigo-1].Linha2.Ponto1.y = 0;
			retangulos.Elementos[codigo-1].Linha2.Ponto1.simb = ',';
			retangulos.Elementos[codigo-1].Linha2.Ponto2.x = 0;
			retangulos.Elementos[codigo-1].Linha2.Ponto2.y = 0;
			retangulos.Elementos[codigo-1].Linha2.Ponto2.simb = ',';			
			for(i = codigo-1; i < retangulos.Qtde; i++) // Reordena o vetor
				retangulos.Elementos[i] = retangulos.Elementos[i+1];
			retangulos.Qtde--;
			printf("Retangulo [%d] excluido com sucesso!\n", codigo);
			system("pause");
		}
		else // Caso o codigo nao exista
		{
			printf("C%cdigo incorreto!\n", 162);
			system("pause");
		}
	}
}

// Procedimento de Redimensionamento de Janela
// -> Origem: http://stackoverflow.com/a/12901833
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