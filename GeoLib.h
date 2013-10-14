#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <conio.h>
#define ERRO printf("\nErro!\n")

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
       struct TPonto ponto;
       int tamanho;
};
struct TTriangulo{
       struct TLinha linha;
       int altura;
};
struct TRetangulo{
       struct TLinha linha;
       int x,y;
};

struct TVPontos{
       struct TPonto elementos[5];         
       int Qtd;
TVPontos(){Qtd=0;}       
};

void PlotarPonto(struct TPonto *ponto, struct Gride *gride,char simbolo){
                   
       gride->Grid[ponto->y][ponto->x]=simbolo;

}
void imprimeGride(struct Gride *gride){//lembrando que esta função somente irá imprimir!
         int i,j;
         int tamanhoGride =20;
         
         for(i=0;i<tamanhoGride;i++){
          for(j=0;j<tamanhoGride;j++){
            if(i==0 && j==0){printf("0  ");}                            
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
