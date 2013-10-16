#include <stdio.h>
    #include <stdlib.h>
    #include <string>
    #include <conio.h>
    #define ERRO printf("\nErro!\n")
    #define tamanhoGride 31

//Parte 1: Alocação dinamica

//Alocaremos ponteiros do tipo char, i e j são inteiros com a dimensão da matriz

char **Alocar(int i,int j){
	
    int cont;
    char **PontMat; //Ponteiro para a matriz
	
    //Alocando
    PontMat=(char**)malloc(i*sizeof(char*));    //É importante observar que temos aqui uma alocação de duas dimensões
    /*if(PontMat == NULL){
	   	ERRO;
	   	return (NULL);
	   }*/
    //Colunas
    for(cont=0;cont<j;cont++){
        PontMat[cont]=(char*)malloc(j*sizeof(char));  //Para cada linha vamos alocar colunas
        /*if(PontMat[cont] == NULL){
	     	   	ERRO;
	     	   	return (NULL);
	     	   }*/
    }
	
    //Retornando o ponteiro da matriz criada
    return(PontMat);
	
}

//Parte 2 Criação do Gride
struct Gride {
    int QX, QY; //QX: unidades do eixo X (colunas), QY: unidades do eixo Y (linhas).
    char **Grid;
    Gride(int pQX = 60, int pQY = 30){
        QX = pQX;
        QY = pQY;
        Grid = Alocar(QY, QX);
        for (int py = 0; py < QY; py++)   
            for (int px = 0; px < QX; px++)
                Grid[py][px] = '.';
    }
};

struct TPonto{
    int x,y;
};
struct TLinha{
    struct TPonto primeiroponto;
    struct TPonto segundoponto;
    
};
struct TTriangulo{
    struct TPonto ponto;
    int altura;
};
struct TRetangulo{
    struct TPonto primeiroponto;
    struct TPonto segundoponto;
};

struct TVPontos{
    struct TPonto elementos[5];         
    int Qtd;
    TVPontos(){Qtd=0;}       
};
struct TVLinhas{
    struct TLinha elementos[5];         
    int Qtd;
    TVLinhas(){Qtd=0;}       
};
struct TVTriangulo{
    struct TTriangulo elementos[5];
    int Qtd;
    TVTriangulo(){Qtd=0;}   
};
struct TVRetangulo{
    struct TLinha elementos[5];         
    int Qtd;
    TVRetangulo(){Qtd=0;}       
};

void MostraPontos(TVPontos *ppontos) {
    int pind;
    system("cls"); //Limpa a tela
    printf("Ponto: (X, Y)\n");
    for (pind = 0; pind < ppontos->Qtd; pind++) {
        printf("%d: (%d, %d)", pind+1, ppontos->elementos[pind].x, ppontos->elementos[pind].y);
        printf("\n");
    }
}
void MostraLinhas(TVLinhas *plinhas) {
    int pind;
    system("cls"); //Limpa a tela
    for (pind = 0; pind < plinhas->Qtd; pind++) {
        printf("Linha %d: Ponto(%d, %d) a ", pind+1, plinhas->elementos[pind].primeiroponto.x, plinhas->elementos[pind].primeiroponto.y);
        printf("Ponto(%d, %d)\n",plinhas->elementos[pind].segundoponto.x,plinhas->elementos[pind].segundoponto.y);
    }
    printf("\n");
}

void MostraTriangulos(TVTriangulo *ptriangulos) {
    int pind;
    system("cls"); //Limpa a tela
    for (pind = 0; pind < ptriangulos->Qtd; pind++) {
        printf("Triangulo %d: Ponto(%d, %d) Altura %d", pind, ptriangulos->elementos[pind].ponto.x, ptriangulos->elementos[pind].ponto.y, ptriangulos->elementos[pind].altura);
    }
    printf("\n");
}

void MostraRetangulos(TVRetangulo *pretangulos) {
    int pind;
    system("cls"); //Limpa a tela
    for (pind = 0; pind < pretangulos->Qtd; pind++) {
        printf("Retangulo %d: Ponto(%d, %d) a", pind, pretangulos->elementos[pind].primeiroponto.x, pretangulos->elementos[pind].primeiroponto.y);
        printf("Ponto(%d, %d)",pretangulos->elementos[pind].segundoponto.x,pretangulos->elementos[pind].segundoponto.y);   
    }
    printf("\n");
}


void PlotarPonto(struct TVPontos *ponto, struct Gride *gride,char simbolo){
                   
    gride->Grid[ponto->elementos[ponto->Qtd].y][ponto->elementos[ponto->Qtd].x]=simbolo;

}
void ExcluirPonto(struct TVPontos *pontos,int cordenadas[],Gride *gride){
    int i,j,retorno = 0;
    
    for(i=0;i<pontos->Qtd;i++){
        if(cordenadas[0]==pontos->elementos[i].x && cordenadas[1]==pontos->elementos[i].y){
            gride->Grid[pontos->elementos[i].y][pontos->elementos[i].x]='.';
            pontos->elementos[i]=pontos->elementos[i+1];
            pontos->Qtd--;  
            printf("Exclusao efetuada com sucesso!\n");
            retorno =1;
        }
     
    }
    if(retorno==0){
     
        printf("Ponto nao encontrado!\n");    
    }
 
}
void IncluirLinha(struct TVLinhas *linha,struct Gride *gride,char simbolo){
    int linhainicial=linha->elementos[linha->Qtd].primeiroponto.y,colunainicial=linha->elementos[linha->Qtd].primeiroponto.x;
    int linhafinal=linha->elementos[linha->Qtd].segundoponto.y,colunafinal=linha->elementos[linha->Qtd].segundoponto.x;
    int i,j;
    if(linhainicial<=linhafinal || colunainicial<=colunafinal){
        for(i=linhainicial;i<=linhafinal;i++){
            for(j=colunainicial;j<=colunafinal;j++){
                /*if(j==i){
       gride->Grid[i][j]=simbolo;
       retorno=1;
       } */                                       
                if(j==colunainicial){
                    gride->Grid[i][j]=simbolo;
                }
                else if(i == linhainicial){
                    gride->Grid[i][j]=simbolo;
                }
            }
        }
    }
    else if(linhainicial>linhafinal && colunainicial<colunafinal){
        system("cls");
        printf("Operacao nao permitida!\n");
    }
          
}

void ExcluirLinha(struct TVLinhas *linhas,int cordenadas[],Gride *gride){
    int k,i,j,retorno = 0;
    
    for(k=0;k< linhas->Qtd;k++){
        if((cordenadas[0]==linhas->elementos[k].primeiroponto.x && cordenadas[1]==linhas->elementos[k].primeiroponto.y)&&(cordenadas[2]==linhas->elementos[k].segundoponto.x && cordenadas[3]==linhas->elementos[k].segundoponto.y))                                          
        {  
            
            for(i=linhas->elementos[k].primeiroponto.x;i <= linhas->elementos[k].segundoponto.x;i++){
                for(j=linhas->elementos[k].primeiroponto.y;j <= linhas->elementos[k].segundoponto.y;j++){
                    if(j==linhas->elementos[k].primeiroponto.y){
                        gride->Grid[i][j]='.';
                    }
                    else if(i == linhas->elementos[k].primeiroponto.x){
                        gride->Grid[i][j]='.';
                    }
                    printf("teste");
                }
            }
             
            gride->Grid[linhas->elementos[k].primeiroponto.y][linhas->elementos[k].primeiroponto.x]='.';
            
             
            linhas->elementos[i]=linhas->elementos[i+1];
            linhas->Qtd--;  
            printf("Exclusao efetuada com sucesso!\n");
            retorno =1;
        }}
     
    
    if(retorno==0){
     
        printf("Ponto nao encontrado!\n");    
    }
 
}
void IncluirTriangulo(struct TVTriangulo *triangulo,struct Gride *gride,char simbolo){
    int k, i;
    for (k = 0; k < triangulo->elementos[triangulo->Qtd].altura; k++) {
        for (i = k * (-1); i <= k; i++)
            gride->Grid[triangulo->elementos[triangulo->Qtd].ponto.y + k][triangulo->elementos[triangulo->Qtd].ponto.x + i] = simbolo;
    }
}

void IncluirRetangulo(struct TVRetangulo *retangulo,struct Gride *gride,char simbolo){
    int linhainicial=retangulo->elementos[retangulo->Qtd].primeiroponto.y,colunainicial=retangulo->elementos[retangulo->Qtd].primeiroponto.x;
    int linhafinal=retangulo->elementos[retangulo->Qtd].segundoponto.y,colunafinal=retangulo->elementos[retangulo->Qtd].segundoponto.x;
    int i,j;
    if(linhainicial<=linhafinal && colunainicial<=colunafinal){
        for(i=linhainicial;i<=linhafinal;i++){
            for(j=colunainicial;j<=colunafinal;j++){
                if(j==colunainicial || i == linhainicial){
                    gride->Grid[i][j]=simbolo;
                }
                if(j==colunafinal || i == linhafinal){
                    gride->Grid[i][j]=simbolo;
                }
            }
        }
    }
    else if(linhainicial>linhafinal && colunainicial<colunafinal){
        for(i=linhainicial;i>linhafinal;i--){
            for(j=colunainicial;j<colunafinal;j++){
                if(j==colunainicial || i == linhainicial){
                    gride->Grid[i][j]=simbolo;
                }
                if(j==colunafinal || i == linhafinal){
                    gride->Grid[i][j]=simbolo;
                }
            }
        }
    }
}
       



void imprimeGride(struct Gride *gride){//lembrando que esta função somente irá imprimir!
    int i,j;
    
         
    for(i=0;i<tamanhoGride;i++){
        for(j=0;j<tamanhoGride;j++){
            if(i==0 && j==0){printf("0 ");}                            
            else if(i==0){
                if(j>9){printf("%d ",j);} //maior que 9 pois acima disso será 2 algorismos,quebrando a formatação      
                else{printf(" %d ",j);}
            }
            else if(j==0){
                if(i>9){printf("%d",i);} //maior que 9 pois acima disso será 2 algorismos,quebrando a formatação    
                else{printf("%d ",i);}
            }
            else{
                       
                printf(" %c ",gride->Grid[i][j]);
            }
        }
        printf("\n");                     
    }

}
