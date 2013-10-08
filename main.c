#include<stdio.h>
#include<stdlib.h>
#include "GeoLib.c"

#define tamanhoGride 20//tamanho teste

void imprimeGride (){//lembrando que esta função somente irá imprimir!
     int i,j;
     char gride[tamanhoGride][tamanhoGride];//gride teste
     
          for(i=0;i<tamanhoGride;i++){
          
            for(j=0;j<tamanhoGride;j++){
            if(i==0 && j==0){printf("0  ");}                            
            else if(i==0){
              if(j>9){printf("%d ",j);}       
              else{printf(" %d ",j);}
            }
            else if(j==0){
             if(i>9){printf("%d",i);}       
              else{printf("%d ",i);}
            }
            else{
            gride[i][j] =' ';//atribuição teste
            printf("|%c ",gride[i][j]);
            }
            }
          printf("\n");                     
          }

}

main(){
imprimeGride();

system("pause");
}
